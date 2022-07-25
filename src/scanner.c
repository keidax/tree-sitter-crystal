#include <tree_sitter/parser.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wctype.h>

enum LiteralTypeEnum {
    STRING,
    STRING_NO_ESCAPE,
    COMMAND,
    STRING_ARRAY,
    SYMBOL_ARRAY,
    REGEX,
};
typedef uint8_t LiteralType;

struct PercentLiteral {
    // We compare these chars with int32_t codepoints, but all valid delimiters
    // in Crystal are in the ASCII range, so we won't overflow.
    uint8_t opening_char;
    uint8_t closing_char;
    uint8_t nesting_level;
    LiteralType type;
};
typedef struct PercentLiteral PercentLiteral;

#define MAX_LITERAL_COUNT 16

struct State {
    bool has_leading_whitespace;

    // It's possible to have nested delimited literals, like
    //   %(#{%(foo)})
    // We can handle up to MAX_LITERAL_COUNT levels of nesting.
    uint8_t literal_count;
    PercentLiteral literal_stack[MAX_LITERAL_COUNT];
};
typedef struct State State;

#define HAS_ACTIVE_LITERAL(state) \
    (state->literal_count > 0)

#define ACTIVE_LITERAL(state) \
    (state->literal_stack[state->literal_count - 1])

#define PUSH_LITERAL(state, literal) \
    (state->literal_stack[state->literal_count++] = literal)

#define POP_LITERAL(state) \
    (state->literal_stack[--state->literal_count] = (PercentLiteral){0, 0, 0, 0})

#ifdef TREE_SITTER_INTERNAL_BUILD
#define DEBUG(...)                                                                          \
    if (getenv("TREE_SITTER_DEBUG") && strncmp(getenv("TREE_SITTER_DEBUG"), "1", 1) == 0) { \
        fprintf(stderr, __VA_ARGS__);                                                       \
    }

#define ASSERT(expr)                                                          \
    if (expr) {                                                               \
        ;                                                                     \
    } else {                                                                  \
        fprintf(stderr, "tree-sitter-crystal: src/scanner.c:%d: ", __LINE__); \
        fprintf(stderr, "Assertion `%s` failed\n", #expr);                    \
        abort();                                                              \
    }
#else
#define DEBUG(...)
#define ASSERT(expr)                                                          \
    if (expr) {                                                               \
        ;                                                                     \
    } else {                                                                  \
        fprintf(stderr, "tree-sitter-crystal: src/scanner.c:%d: ", __LINE__); \
        fprintf(stderr, "Assertion `%s` failed\n", #expr);                    \
    }
#endif

enum Token {
    LINE_BREAK,

    START_OF_BRACE_BLOCK,
    START_OF_HASH_OR_TUPLE,
    START_OF_TUPLE_TYPE,

    START_OF_INDEX_OPERATOR,

    END_OF_WITH_EXPRESSSION,

    UNARY_PLUS,
    UNARY_MINUS,
    BINARY_PLUS,
    BINARY_MINUS,

    UNARY_WRAPPING_PLUS,
    UNARY_WRAPPING_MINUS,
    BINARY_WRAPPING_PLUS,
    BINARY_WRAPPING_MINUS,

    UNARY_STAR,
    BINARY_STAR,

    UNARY_DOUBLE_STAR,
    BINARY_DOUBLE_STAR,

    BEGINLESS_RANGE_OPERATOR,

    REGEX_START,
    BINARY_SLASH,
    BINARY_DOUBLE_SLASH,

    REGULAR_IF_KEYWORD,
    MODIFIER_IF_KEYWORD,

    REGULAR_UNLESS_KEYWORD,
    MODIFIER_UNLESS_KEYWORD,

    MODULO_OPERATOR,

    STRING_PERCENT_LITERAL_START,
    COMMAND_PERCENT_LITERAL_START,
    STRING_ARRAY_PERCENT_LITERAL_START,
    SYMBOL_ARRAY_PERCENT_LITERAL_START,
    REGEX_PERCENT_LITERAL_START,
    PERCENT_LITERAL_END,
    DELIMITED_STRING_CONTENTS,

    DELIMITED_ARRAY_ELEMENT_START,
    DELIMITED_ARRAY_ELEMENT_END,

    REGEX_MODIFIER,

    // Never returned
    START_OF_PARENLESS_ARGS,
    END_OF_RANGE,

    // Only used when error recovery mode is active
    ERROR_RECOVERY,

    NONE,
};
typedef enum Token Token;

void *tree_sitter_crystal_external_scanner_create() {
    State *state;

    state = malloc(sizeof(State));
    memset(state, 0, sizeof(State));
    state->has_leading_whitespace = false;

    return state;
}

void lex_skip(State *state, TSLexer *lexer) {
    state->has_leading_whitespace = true;
    lexer->advance(lexer, true);
}

// NOTE: apparently this can't be called `advance` because it conflicts with a
// symbol in glibc
void lex_advance(TSLexer *lexer) {
    lexer->advance(lexer, false);
}

bool next_char_is_identifier(TSLexer *lexer) {
    int32_t lookahead = lexer->lookahead;

    return iswalnum(lookahead)
        || lookahead == '_'
        || lookahead == '?'
        || lookahead == '!'
        || lookahead >= 0xa0;
}

bool scan_whitespace(State *state, TSLexer *lexer, const bool *valid_symbols) {
    bool crossed_newline = false;

    for (;;) {
        switch (lexer->lookahead) {
            case ' ':
            case '\t':
            case '\r':
                lex_skip(state, lexer);
                break;

            case '\n':
                if (valid_symbols[LINE_BREAK] && !crossed_newline) {
                    lex_advance(lexer);
                    lexer->mark_end(lexer);
                    crossed_newline = true;
                } else {
                    lex_skip(state, lexer);
                }
                break;

            case '\v':
            case '\f':
                // In regular code, these characters are not allowed. But they
                // may be used in between strings in a %w array.
                if (HAS_ACTIVE_LITERAL(state)) {
                    lex_skip(state, lexer);
                    break;
                }

            default:
                if (crossed_newline) {
                    if (lexer->lookahead == '.') {
                        // Check if this is the continuation of a method call,
                        // or the start of a beginless range literal.
                        lex_advance(lexer);
                        if (lexer->lookahead == '.') {
                            DEBUG(" ==> returning LINE_BREAK\n");
                            lexer->result_symbol = LINE_BREAK;
                        }
                    } else if (lexer->lookahead == '#') {
                        // Comments don't interrupt line continuations
                    } else {
                        DEBUG(" ==> returning LINE_BREAK\n");
                        lexer->result_symbol = LINE_BREAK;
                    }
                }
                return true;
        }
    }
}

// Returns true if a string content token is found
bool scan_string_contents(State *state, TSLexer *lexer, const bool *valid_symbols) {
    bool found_content = false;
    LiteralType active_type;

    // This may be overridden later.
    lexer->result_symbol = DELIMITED_STRING_CONTENTS;

    for (;;) {
        if (lexer->eof(lexer)) {
            DEBUG("reached EOF\n");
            return found_content;
        }

        active_type = ACTIVE_LITERAL(state).type;

        switch (lexer->lookahead) {
            case '\\':
                switch (active_type) {
                    case STRING:
                    case COMMAND:
                    case REGEX:
                        return found_content;
                    case STRING_NO_ESCAPE:
                        break;
                    case STRING_ARRAY:
                    case SYMBOL_ARRAY:
                        // %w and %i allow only '\<whitespace>' or the closing
                        // delimiter as an escape sequence, so we have to look
                        // ahead one character.
                        lexer->mark_end(lexer);
                        lex_advance(lexer);
                        if (iswspace(lexer->lookahead) || ACTIVE_LITERAL(state).closing_char == lexer->lookahead) {
                            return found_content;
                        }

                        // The backslash must be part of the word contents.
                        found_content = true;
                        lexer->mark_end(lexer);
                        continue;
                }
                break;
            case '#':
                if (active_type == STRING_NO_ESCAPE || active_type == STRING_ARRAY || active_type == SYMBOL_ARRAY) {
                    // These types don't allow interpolation
                    break;
                }

                lexer->mark_end(lexer);
                lex_advance(lexer);
                if (lexer->lookahead == '{') {
                    return found_content;
                }

                found_content = true;
                lexer->mark_end(lexer);
                continue;
            case ' ':
            case '\t':
            case '\n':
            case '\r':
            case '\v':
            case '\f':
                if (active_type == STRING_ARRAY || active_type == SYMBOL_ARRAY) {
                    ASSERT(found_content || valid_symbols[DELIMITED_ARRAY_ELEMENT_END]);

                    if (found_content) {
                        // We've already found string contents, return that.
                        return true;
                    } else if (valid_symbols[DELIMITED_ARRAY_ELEMENT_END]) {
                        // We've reached the end of an array word.
                        lexer->result_symbol = DELIMITED_ARRAY_ELEMENT_END;
                        return true;
                    }
                }
                break;
            case '"':
            case '|':
                // These delimiters can't nest
                if (ACTIVE_LITERAL(state).closing_char == lexer->lookahead) {
                    if (found_content) {
                        // We've already found string contents, return that.
                        return true;
                    } else if (valid_symbols[DELIMITED_ARRAY_ELEMENT_END]) {
                        // We've reached the end of an array word.
                        lexer->result_symbol = DELIMITED_ARRAY_ELEMENT_END;
                        return true;
                    } else {
                        return false;
                    }
                }
                break;
            case '(':
            case '[':
            case '{':
            case '<':
                if (ACTIVE_LITERAL(state).opening_char == lexer->lookahead) {
                    ACTIVE_LITERAL(state).nesting_level++;
                }
                break;
            case ')':
            case ']':
            case '}':
            case '>':
                if (ACTIVE_LITERAL(state).closing_char == lexer->lookahead) {
                    if (ACTIVE_LITERAL(state).nesting_level == 0) {
                        if (found_content) {
                            // We've already found string contents, return that.
                            return true;
                        } else if (valid_symbols[DELIMITED_ARRAY_ELEMENT_END]) {
                            // We've reached the end of an array word.
                            lexer->result_symbol = DELIMITED_ARRAY_ELEMENT_END;
                            return true;
                        } else {
                            return false;
                        }
                    }

                    ACTIVE_LITERAL(state).nesting_level--;
                }
                break;
        }

        lex_advance(lexer);
        lexer->mark_end(lexer);
        found_content = true;
    }
}

bool scan_regex_modifier(State *state, TSLexer *lexer, const bool *valid_symbols) {
    if (!state->has_leading_whitespace) {
        bool found_modifier = false;

        for (;;) {
            switch (lexer->lookahead) {
                case 'i':
                case 'm':
                case 'x':
                    found_modifier = true;
                    lex_advance(lexer);
                    continue;
            }

            if (found_modifier) {
                lexer->result_symbol = REGEX_MODIFIER;
                return true;
            } else {
                break;
            }
        }
    }

    return false;
}

void skip_space(State *state, TSLexer *lexer) {
    while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
        lex_skip(state, lexer);
    }
}

void skip_space_and_newline(State *state, TSLexer *lexer) {
    while (lexer->lookahead == ' '
        || lexer->lookahead == '\t'
        || lexer->lookahead == '\r'
        || lexer->lookahead == '\n') {
        lex_skip(state, lexer);
    }
}

bool is_const_part(int32_t codepoint) {
    // constant tokens are in the range [0-9A-Za-z_\u{00a0}-\u{10ffff}]
    return ('0' <= codepoint && codepoint <= '9')
        || ('A' <= codepoint && codepoint <= 'Z')
        || ('a' <= codepoint && codepoint <= 'z')
        || (codepoint == '_')
        || (0x00a0 <= codepoint && codepoint <= 0x10ffffff);
}

void consume_const(State *state, TSLexer *lexer) {
    if ('A' <= lexer->lookahead && lexer->lookahead <= 'Z') {
        lex_advance(lexer);

        while (is_const_part(lexer->lookahead)) {
            lex_advance(lexer);
        }
    }
}

bool lookahead_delimiter_or_type_suffix(State *state, TSLexer *lexer, const bool *valid_symbols) {
    if (lexer->eof(lexer)) { return true; }

    switch (lexer->lookahead) {
        case '.':
            lex_advance(lexer);
            skip_space_and_newline(state, lexer);
            if (lexer->lookahead != 'c') { return false; }
            lex_advance(lexer);
            if (lexer->lookahead != 'l') { return false; }
            lex_advance(lexer);
            if (lexer->lookahead != 'a') { return false; }
            lex_advance(lexer);
            if (lexer->lookahead != 's') { return false; }
            lex_advance(lexer);
            if (lexer->lookahead != 's') { return false; }
            lex_advance(lexer);
            if (is_const_part(lexer->lookahead)) {
                // the keyword doesn't end after `class`
                return false;
            } else {
                // .class type
                return true;
            }

        case '?':
        case '*':
            lex_advance(lexer);
            return lookahead_delimiter_or_type_suffix(state, lexer, valid_symbols);

        case '-':
            lex_advance(lexer);
            if (lexer->lookahead == '>') {
                // Const -> is considered a type suffix
                return true;
            }
            return false;

        case '=':
            lex_advance(lexer);
            switch (lexer->lookahead) {
                case '>':
                    // Const => is considered a type suffix
                    return true;
                case '=':
                case '~':
                    // other operators
                    return false;
                default:
                    // Const = is considered a type suffix
                    return true;
            }

        case '|':
        case ',':
        case ';':
        case '\n':
        case '(':
        case ')':
        case '[':
        case ']':
            // other type delimiters
            return true;

        default:
            return false;
    }
}

// Check to see if the next token is part of the type grammar or not. Based on
// https://github.com/crystal-lang/crystal/blob/cd2b7d6490301e092cecc22dfbc91d0f9553ba20/src/compiler/crystal/syntax/parser.cr#L5195
// As the compiler code notes, these conditions are not completely accurate in determining what
// could or could not be a type.
bool lookahead_start_of_type(State *state, TSLexer *lexer, const bool *valid_symbols) {

    skip_space(state, lexer);

    if (lexer->eof(lexer)) {
        DEBUG("reached EOF\n");
        return false;
    }

    while (lexer->lookahead == '{' || lexer->lookahead == '(') {
        lex_advance(lexer);
        skip_space_and_newline(state, lexer);
    }

    while ('A' <= lexer->lookahead && lexer->lookahead <= 'Z') {
        consume_const(state, lexer);

        if (lexer->lookahead == ':') {
            lex_advance(lexer);

            if (lexer->lookahead == ':') {
                lex_advance(lexer);
                skip_space_and_newline(state, lexer);
                // continue consuming const segments
            } else {
                // named tuple start
                return false;
            }
        } else {
            skip_space(state, lexer);
            return lookahead_delimiter_or_type_suffix(state, lexer, valid_symbols);
        }
    }

    switch (lexer->lookahead) {
        // TODO: handle ident
        case '_':
            lex_advance(lexer);
            if (!iswalnum(lexer->lookahead)) {
                // This is just a plain underscore
                return true;
            }
            break;
        case '-':
            lex_advance(lexer);
            if (lexer->lookahead == '>') {
                // proc type
                return true;
            }
            break;
        case '*':
            lex_advance(lexer);
            skip_space_and_newline(state, lexer);
            if (lexer->lookahead == '*') {
                // double splat is not a valid type operator
                return false;
            } else {
                return lookahead_start_of_type(state, lexer, valid_symbols);
            }
            break;
    }

    DEBUG("Not the start of a type\n");
    return false;
}

bool tree_sitter_crystal_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    DEBUG("\n ==> starting external scan\n");
    DEBUG(" ==> char is '%c'\n", lexer->lookahead);
    DEBUG(" ==> valid symbols are:\n");

#define LOG_SYMBOL(sym) \
    if (valid_symbols[sym]) DEBUG("\t" #sym "\n");

    LOG_SYMBOL(LINE_BREAK);
    LOG_SYMBOL(START_OF_BRACE_BLOCK);
    LOG_SYMBOL(START_OF_HASH_OR_TUPLE);
    LOG_SYMBOL(START_OF_TUPLE_TYPE);
    LOG_SYMBOL(START_OF_INDEX_OPERATOR);
    LOG_SYMBOL(END_OF_WITH_EXPRESSSION);
    LOG_SYMBOL(UNARY_PLUS);
    LOG_SYMBOL(UNARY_MINUS);
    LOG_SYMBOL(BINARY_PLUS);
    LOG_SYMBOL(BINARY_MINUS);
    LOG_SYMBOL(UNARY_WRAPPING_PLUS);
    LOG_SYMBOL(UNARY_WRAPPING_MINUS);
    LOG_SYMBOL(BINARY_WRAPPING_PLUS);
    LOG_SYMBOL(BINARY_WRAPPING_MINUS);
    LOG_SYMBOL(UNARY_STAR);
    LOG_SYMBOL(BINARY_STAR);
    LOG_SYMBOL(UNARY_DOUBLE_STAR);
    LOG_SYMBOL(BINARY_DOUBLE_STAR);
    LOG_SYMBOL(BEGINLESS_RANGE_OPERATOR);
    LOG_SYMBOL(REGEX_START);
    LOG_SYMBOL(BINARY_SLASH);
    LOG_SYMBOL(BINARY_DOUBLE_SLASH);
    LOG_SYMBOL(REGULAR_IF_KEYWORD);
    LOG_SYMBOL(MODIFIER_IF_KEYWORD);
    LOG_SYMBOL(REGULAR_UNLESS_KEYWORD);
    LOG_SYMBOL(MODIFIER_UNLESS_KEYWORD);
    LOG_SYMBOL(MODULO_OPERATOR);
    LOG_SYMBOL(STRING_PERCENT_LITERAL_START);
    LOG_SYMBOL(COMMAND_PERCENT_LITERAL_START);
    LOG_SYMBOL(STRING_ARRAY_PERCENT_LITERAL_START);
    LOG_SYMBOL(SYMBOL_ARRAY_PERCENT_LITERAL_START);
    LOG_SYMBOL(REGEX_PERCENT_LITERAL_START);
    LOG_SYMBOL(PERCENT_LITERAL_END);
    LOG_SYMBOL(DELIMITED_STRING_CONTENTS);
    LOG_SYMBOL(DELIMITED_ARRAY_ELEMENT_START);
    LOG_SYMBOL(DELIMITED_ARRAY_ELEMENT_END);
    LOG_SYMBOL(REGEX_MODIFIER);
    LOG_SYMBOL(START_OF_PARENLESS_ARGS);
    LOG_SYMBOL(END_OF_RANGE);
    LOG_SYMBOL(ERROR_RECOVERY);

    State *state = (State *)payload;
    state->has_leading_whitespace = false;

    if (valid_symbols[DELIMITED_STRING_CONTENTS] && HAS_ACTIVE_LITERAL(state) && scan_string_contents(state, lexer, valid_symbols)) {
        return true;
    }

    lexer->result_symbol = NONE;

    if (!scan_whitespace(state, lexer, valid_symbols)) {
        return false;
    }

    if (lexer->result_symbol != NONE) {
        return true;
    }

    if (valid_symbols[PERCENT_LITERAL_END] && HAS_ACTIVE_LITERAL(state)) {
        if (lexer->lookahead == ACTIVE_LITERAL(state).closing_char) {
            lex_advance(lexer);
            POP_LITERAL(state);
            lexer->result_symbol = PERCENT_LITERAL_END;
            return true;
        }
    }

    if (valid_symbols[DELIMITED_ARRAY_ELEMENT_START] && HAS_ACTIVE_LITERAL(state)) {
        lexer->result_symbol = DELIMITED_ARRAY_ELEMENT_START;
        return true;
    }

    if (valid_symbols[REGEX_MODIFIER] && scan_regex_modifier(state, lexer, valid_symbols)) {
        return true;
    }

    switch (lexer->lookahead) {
        case '{':
            if (valid_symbols[START_OF_BRACE_BLOCK]
                || valid_symbols[START_OF_HASH_OR_TUPLE]
                || valid_symbols[START_OF_TUPLE_TYPE]) {

                if (valid_symbols[START_OF_BRACE_BLOCK] && valid_symbols[START_OF_HASH_OR_TUPLE]
                    && valid_symbols[START_OF_TUPLE_TYPE]) {

                    if (valid_symbols[ERROR_RECOVERY]) {
                        return false;
                    } else {
                        // Shouldn't reach here
                        ASSERT(!(
                            valid_symbols[START_OF_BRACE_BLOCK]
                            && valid_symbols[START_OF_HASH_OR_TUPLE]
                            && valid_symbols[START_OF_TUPLE_TYPE]));
                        return false;
                    }
                } else if (valid_symbols[START_OF_BRACE_BLOCK] && valid_symbols[START_OF_HASH_OR_TUPLE]) {
                    // In Crystal, the '{' token may be used as the start of a block,
                    // or the start of another literal like a tuple. The language
                    // resolves this potential ambiguity by requiring that the first
                    // non-block argument to a method invoked without parentheses may
                    // not start with a '{'. In other words, if you want to pass a
                    // tuple as the first argument, the method call _must_ use
                    // parentheses.
                    //
                    // This means, if we see a '{' and we're in a context where a block
                    // could be valid, it must be the start of a block.
                    ASSERT(valid_symbols[START_OF_PARENLESS_ARGS]);

                    lex_advance(lexer);
                    lexer->result_symbol = START_OF_BRACE_BLOCK;
                    return true;
                } else if (valid_symbols[START_OF_BRACE_BLOCK] && valid_symbols[START_OF_TUPLE_TYPE]) {

                    lex_advance(lexer);

                    // We don't want to consume while looking ahead
                    lexer->mark_end(lexer);

                    // Use type lookahead to resolve conflict between start of block and start of tuple type
                    // For example, as a tuple type:
                    //   -> : -> {->} {
                    //     # ...
                    //   }
                    // Or as a block:
                    //   -> : -> { ; Proc(Nil).new{} }
                    if (lookahead_start_of_type(state, lexer, valid_symbols)) {
                        lexer->result_symbol = START_OF_TUPLE_TYPE;
                        return true;
                    } else {
                        lexer->result_symbol = START_OF_BRACE_BLOCK;
                        return true;
                    }
                } else if (valid_symbols[START_OF_HASH_OR_TUPLE] && valid_symbols[START_OF_TUPLE_TYPE]) {

                    lex_advance(lexer);

                    // We don't want to consume while looking ahead
                    lexer->mark_end(lexer);

                    // Use type lookahead to resolve conflict between start of hash/tuple and start of tuple type
                    // For example, as a tuple type:
                    //   def foo : ->{Char,Char}; ->{ {'a','b'} } end
                    // Or as a hash:
                    //   def foo : ->{'a'=>'b'}; ->{ nil } end
                    if (lookahead_start_of_type(state, lexer, valid_symbols)) {
                        lexer->result_symbol = START_OF_TUPLE_TYPE;
                        return true;
                    } else {
                        lexer->result_symbol = START_OF_HASH_OR_TUPLE;
                        return true;
                    }
                } else if (valid_symbols[START_OF_TUPLE_TYPE]) {
                    lex_advance(lexer);
                    lexer->result_symbol = START_OF_TUPLE_TYPE;
                    return true;
                } else if (valid_symbols[START_OF_BRACE_BLOCK]) {
                    lex_advance(lexer);
                    lexer->result_symbol = START_OF_BRACE_BLOCK;
                    return true;
                } else if (valid_symbols[START_OF_HASH_OR_TUPLE]) {
                    lex_advance(lexer);
                    lexer->result_symbol = START_OF_HASH_OR_TUPLE;
                    return true;
                } else {
                    ASSERT(!"This should never be reached");
                }
            }

            break;
        case '[':
            if (valid_symbols[START_OF_INDEX_OPERATOR]) {
                // If there's ambiguity whether '[' is the start of an index
                // access or an array literal, we assume it's an array if
                // there's leading whitespace and we're at the start of a
                // potential method call:
                //   foo [1]
                // If there's no leading whitespace, or we know this isn't the
                // first parameter of a method call, then it must be an index
                // operator:
                //   puts({42} [0])
                if (state->has_leading_whitespace && valid_symbols[START_OF_PARENLESS_ARGS]) {
                    return false;
                } else {
                    lex_advance(lexer);
                    lexer->result_symbol = START_OF_INDEX_OPERATOR;
                    return true;
                }
            }
            break;
        case '+':
            if (valid_symbols[UNARY_PLUS] || valid_symbols[BINARY_PLUS]) {
                lex_advance(lexer);

                if (lexer->lookahead == '=') {
                    return false;
                }

                // Give precedence to the unary operator if:
                // - there is space before but not after, e.g.
                //      puts +foo
                // - we are just after a range operator, e.g.
                //      -5 .. + foo
                bool unary_priority = (state->has_leading_whitespace && !iswspace(lexer->lookahead))
                    || valid_symbols[END_OF_RANGE];

                if (valid_symbols[UNARY_PLUS] && unary_priority) {
                    lexer->result_symbol = UNARY_PLUS;
                    DEBUG(" ==> returning UNARY_PLUS\n");
                } else if (valid_symbols[BINARY_PLUS]) {
                    lexer->result_symbol = BINARY_PLUS;
                    DEBUG(" ==> returning BINARY_PLUS\n");
                } else {
                    lexer->result_symbol = UNARY_PLUS;
                    DEBUG(" ==> returning UNARY_PLUS\n");
                }

                return true;
            }
            break;
        case '-':
            if (valid_symbols[UNARY_MINUS] || valid_symbols[BINARY_MINUS]) {
                lex_advance(lexer);

                if (lexer->lookahead == '=' || lexer->lookahead == '>') {
                    return false;
                }

                bool unary_priority = (state->has_leading_whitespace && !iswspace(lexer->lookahead))
                    || valid_symbols[END_OF_RANGE];

                if (valid_symbols[UNARY_MINUS] && unary_priority) {
                    lexer->result_symbol = UNARY_MINUS;
                    DEBUG(" ==> returning UNARY_MINUS\n");
                } else if (valid_symbols[BINARY_MINUS]) {
                    lexer->result_symbol = BINARY_MINUS;
                    DEBUG(" ==> returning BINARY_MINUS\n");
                } else {
                    lexer->result_symbol = UNARY_MINUS;
                    DEBUG(" ==> returning UNARY_MINUS\n");
                }

                return true;
            }
            break;

        case '*':
            if (valid_symbols[UNARY_STAR] || valid_symbols[BINARY_STAR] || valid_symbols[UNARY_DOUBLE_STAR] || valid_symbols[BINARY_DOUBLE_STAR]) {
                lex_advance(lexer);

                if (lexer->lookahead == '=') {
                    return false;
                }

                if (lexer->lookahead == '*') {
                    lex_advance(lexer);

                    if (lexer->lookahead == '=') {
                        return false;
                    }

                    bool unary_priority = state->has_leading_whitespace && !iswspace(lexer->lookahead);

                    if (valid_symbols[UNARY_DOUBLE_STAR] && unary_priority) {
                        lexer->result_symbol = UNARY_DOUBLE_STAR;
                        return true;
                    } else if (valid_symbols[BINARY_DOUBLE_STAR]) {
                        lexer->result_symbol = BINARY_DOUBLE_STAR;
                        return true;
                    } else if (valid_symbols[UNARY_DOUBLE_STAR] && !iswspace(lexer->lookahead)) {
                        // A splat _cannot_ have whitespace after the *
                        lexer->result_symbol = UNARY_DOUBLE_STAR;
                        return true;
                    }

                    return false;
                }

                bool unary_priority = state->has_leading_whitespace && !iswspace(lexer->lookahead);

                if (valid_symbols[UNARY_STAR] && unary_priority) {
                    lexer->result_symbol = UNARY_STAR;
                    return true;
                } else if (valid_symbols[BINARY_STAR]) {
                    lexer->result_symbol = BINARY_STAR;
                    return true;
                } else if (valid_symbols[UNARY_STAR] && !iswspace(lexer->lookahead)) {
                    // A splat _cannot_ have whitespace after the *
                    lexer->result_symbol = UNARY_STAR;
                    return true;
                }
            }
            break;

        case '&':
            if (
                valid_symbols[UNARY_WRAPPING_PLUS]
                || valid_symbols[UNARY_WRAPPING_MINUS]
                || valid_symbols[BINARY_WRAPPING_PLUS]
                || valid_symbols[BINARY_WRAPPING_MINUS]) {
                lex_advance(lexer);

                if (lexer->lookahead == '+') {
                    lex_advance(lexer);

                    if (lexer->lookahead == '=') {
                        return false;
                    }

                    // The binary form of &+ is always preferred. E.g.
                    //   foo! &+bar
                    // is still binary.
                    if (valid_symbols[BINARY_WRAPPING_PLUS]) {
                        lexer->result_symbol = BINARY_WRAPPING_PLUS;
                        return true;
                    } else if (valid_symbols[UNARY_WRAPPING_PLUS]) {
                        lexer->result_symbol = UNARY_WRAPPING_PLUS;
                        return true;
                    }

                    return false;
                }

                if (lexer->lookahead == '-') {
                    lex_advance(lexer);

                    if (lexer->lookahead == '=') {
                        return false;
                    }

                    if (valid_symbols[BINARY_WRAPPING_MINUS]) {
                        lexer->result_symbol = BINARY_WRAPPING_MINUS;
                        return true;
                    } else if (valid_symbols[UNARY_WRAPPING_MINUS]) {
                        lexer->result_symbol = UNARY_WRAPPING_MINUS;
                        return true;
                    }

                    return false;
                }
            }
            break;

        case '/':
            if (valid_symbols[REGEX_START]
                || valid_symbols[BINARY_SLASH]
                || BINARY_DOUBLE_SLASH) {

                lex_advance(lexer);

                if (lexer->lookahead == '=') {
                    return false;
                }

                if (lexer->lookahead == '/' && valid_symbols[BINARY_DOUBLE_SLASH]) {
                    lex_advance(lexer);

                    if (lexer->lookahead == '=') {
                        return false;
                    }

                    lexer->result_symbol = BINARY_DOUBLE_SLASH;
                    return true;
                }

                if (valid_symbols[BINARY_SLASH] && !valid_symbols[REGEX_START]) {
                    lexer->result_symbol = BINARY_SLASH;
                    return true;
                } else if (valid_symbols[REGEX_START] && !valid_symbols[BINARY_SLASH]) {
                    lexer->result_symbol = REGEX_START;
                    return true;
                } else {
                    // Both are valid
                    ASSERT(valid_symbols[REGEX_START] && valid_symbols[BINARY_SLASH]);

                    // This sort of ambiguity should only happen after an identifier without parentheses
                    ASSERT(valid_symbols[START_OF_PARENLESS_ARGS]);

                    if (state->has_leading_whitespace
                        && !(lexer->lookahead == ' '
                            || lexer->lookahead == '\t'
                            || lexer->lookahead == '\n'
                            || lexer->lookahead == '\r')) {
                        // If we're in the state
                        //   foo   /a
                        //         ^
                        // then we assume this is the start of a regex.
                        lexer->result_symbol = REGEX_START;
                        return true;
                    } else {
                        // We must be in one of these states:
                        //   foo/a
                        //      ^
                        // or
                        //   foo/ a
                        //      ^
                        // or
                        //   foo / a
                        //       ^
                        // In each of these cases, we give the slash operator
                        // higher precedence over a regex.
                        lexer->result_symbol = BINARY_SLASH;
                        return true;
                    }
                }
            }
            break;

        case '%':
            if (valid_symbols[STRING_PERCENT_LITERAL_START]
                || valid_symbols[COMMAND_PERCENT_LITERAL_START]
                || valid_symbols[STRING_ARRAY_PERCENT_LITERAL_START]
                || valid_symbols[SYMBOL_ARRAY_PERCENT_LITERAL_START]
                || valid_symbols[REGEX_PERCENT_LITERAL_START]) {
                lex_advance(lexer);

                if (lexer->lookahead == '=') {
                    return false;
                }

                LiteralType type = STRING;
                Token return_symbol = STRING_PERCENT_LITERAL_START;

                switch (lexer->lookahead) {
                    case 'Q':
                        lex_advance(lexer);
                        // type is already STRING
                        break;
                    case 'q':
                        lex_advance(lexer);
                        type = STRING_NO_ESCAPE;
                        break;
                    case 'x':
                        lex_advance(lexer);
                        type = COMMAND;
                        return_symbol = COMMAND_PERCENT_LITERAL_START;
                        break;
                    case 'w':
                        lex_advance(lexer);
                        type = STRING_ARRAY;
                        return_symbol = STRING_ARRAY_PERCENT_LITERAL_START;
                        break;
                    case 'i':
                        lex_advance(lexer);
                        type = SYMBOL_ARRAY;
                        return_symbol = SYMBOL_ARRAY_PERCENT_LITERAL_START;
                        break;
                    case 'r':
                        lex_advance(lexer);
                        type = REGEX;
                        return_symbol = REGEX_PERCENT_LITERAL_START;
                        break;
                }

                int32_t opening_char = 0, closing_char;

                switch (lexer->lookahead) {
                    case '{':
                        opening_char = '{';
                        closing_char = '}';
                        break;
                    case '(':
                        opening_char = '(';
                        closing_char = ')';
                        break;
                    case '[':
                        opening_char = '[';
                        closing_char = ']';
                        break;
                    case '<':
                        opening_char = '<';
                        closing_char = '>';
                        break;
                    case '|':
                        opening_char = '|';
                        closing_char = '|';
                        break;
                    default:
                        if (valid_symbols[MODULO_OPERATOR]) {
                            lexer->result_symbol = MODULO_OPERATOR;
                            return true;
                        }
                }

                if (opening_char) {
                    lex_advance(lexer);

                    if (!valid_symbols[return_symbol]) {
                        return false;
                    }

                    lexer->result_symbol = return_symbol;

                    if (state->literal_count >= MAX_LITERAL_COUNT) {
                        // Instead of overflowing the state (and accessing out-of-bounds memory)
                        // we'll just return false, resulting in an error in the syntax tree. The
                        // literals already on the stack can still be parsed successfully.
                        return false;
                    }

                    PUSH_LITERAL(state, ((PercentLiteral){
                                            .opening_char = opening_char,
                                            .closing_char = closing_char,
                                            .type = type,
                                            .nesting_level = 0,
                                        }));

                    return true;
                }

            } else if (valid_symbols[MODULO_OPERATOR]) {
                lex_advance(lexer);

                if (lexer->lookahead == '=') {
                    return false;
                }

                lexer->result_symbol = MODULO_OPERATOR;
                return true;
            }
            break;

        case '.':
            if (valid_symbols[BEGINLESS_RANGE_OPERATOR] && !valid_symbols[START_OF_PARENLESS_ARGS]) {
                lex_advance(lexer);
                if (lexer->lookahead != '.') {
                    return false;
                }
                lex_advance(lexer);
                if (lexer->lookahead == '.') {
                    lex_advance(lexer);
                }

                DEBUG(" ==> returning BEGINLESS_RANGE_OPERATOR\n");
                lexer->result_symbol = BEGINLESS_RANGE_OPERATOR;
                return true;
            }
            break;
        case 'i':
            if (valid_symbols[REGULAR_IF_KEYWORD] || valid_symbols[MODIFIER_IF_KEYWORD]) {
                lex_advance(lexer);
                if (lexer->lookahead != 'f') {
                    return false;
                }

                lex_advance(lexer);
                if (next_char_is_identifier(lexer)) {
                    // This is some other identifier, not 'if'
                    return false;
                }

                if (valid_symbols[MODIFIER_IF_KEYWORD] && !valid_symbols[REGULAR_IF_KEYWORD]) {
                    lexer->result_symbol = MODIFIER_IF_KEYWORD;
                    return true;
                } else if (valid_symbols[REGULAR_IF_KEYWORD] && !valid_symbols[MODIFIER_IF_KEYWORD]) {
                    lexer->result_symbol = REGULAR_IF_KEYWORD;
                    return true;
                } else {
                    // Both are valid
                    ASSERT(valid_symbols[MODIFIER_IF_KEYWORD] && valid_symbols[REGULAR_IF_KEYWORD]);

                    // This sort of ambiguity should only happen after an identifier without parentheses
                    ASSERT(valid_symbols[START_OF_PARENLESS_ARGS]);

                    if (valid_symbols[START_OF_PARENLESS_ARGS]) {
                        lexer->result_symbol = MODIFIER_IF_KEYWORD;
                        return true;
                    }
                }
            }
            break;
        case 'u':
            if (valid_symbols[REGULAR_UNLESS_KEYWORD] || valid_symbols[MODIFIER_UNLESS_KEYWORD]) {
                lex_advance(lexer);
                if (lexer->lookahead != 'n') { return false; }
                lex_advance(lexer);
                if (lexer->lookahead != 'l') { return false; }
                lex_advance(lexer);
                if (lexer->lookahead != 'e') { return false; }
                lex_advance(lexer);
                if (lexer->lookahead != 's') { return false; }
                lex_advance(lexer);
                if (lexer->lookahead != 's') { return false; }

                lex_advance(lexer);
                if (next_char_is_identifier(lexer)) {
                    // This is some other identifier, not 'unless'
                    return false;
                }

                if (valid_symbols[MODIFIER_UNLESS_KEYWORD] && !valid_symbols[REGULAR_UNLESS_KEYWORD]) {
                    lexer->result_symbol = MODIFIER_UNLESS_KEYWORD;
                    return true;
                } else if (valid_symbols[REGULAR_UNLESS_KEYWORD] && !valid_symbols[MODIFIER_UNLESS_KEYWORD]) {
                    lexer->result_symbol = REGULAR_UNLESS_KEYWORD;
                    return true;
                } else {
                    // Both are valid
                    ASSERT(valid_symbols[MODIFIER_UNLESS_KEYWORD] && valid_symbols[REGULAR_UNLESS_KEYWORD]);

                    // This sort of ambiguity should only happen after an identifier without parentheses
                    ASSERT(valid_symbols[START_OF_PARENLESS_ARGS]);

                    if (valid_symbols[START_OF_PARENLESS_ARGS]) {
                        lexer->result_symbol = MODIFIER_UNLESS_KEYWORD;
                        return true;
                    }
                }
            }
            break;
        case 'y':
            if (valid_symbols[END_OF_WITH_EXPRESSSION]) {
                // We don't want to consume the yield keyword
                lexer->mark_end(lexer);

                lex_advance(lexer);
                if (lexer->lookahead != 'i') { return false; }
                lex_advance(lexer);
                if (lexer->lookahead != 'e') { return false; }
                lex_advance(lexer);
                if (lexer->lookahead != 'l') { return false; }
                lex_advance(lexer);
                if (lexer->lookahead != 'd') { return false; }

                lex_advance(lexer);
                if (next_char_is_identifier(lexer)) {
                    // This is some other identifier, not 'yield'
                    return false;
                }

                lexer->result_symbol = END_OF_WITH_EXPRESSSION;
                return true;
            }
    }

    DEBUG(" ==> returning nothing at end\n");
    return false;
}

unsigned tree_sitter_crystal_external_scanner_serialize(void *payload, char *buffer) {
    State *state = (State *)payload;

    size_t state_size = sizeof(State);

    memcpy(buffer, state, state_size);

    return state_size;
}

void tree_sitter_crystal_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    State *state = (State *)payload;

    if (length < sizeof(State)) {
        memset(state, 0, sizeof(State));
    }

    memcpy(state, buffer, length);
}

void tree_sitter_crystal_external_scanner_destroy(void *payload) {
    State *state = (State *)payload;
    free(state);
}
