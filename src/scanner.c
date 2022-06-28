#include <tree_sitter/parser.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wctype.h>

enum LiteralType {
    STRING,
    STRING_NO_ESCAPE,
    STRING_ARRAY,
};
typedef enum LiteralType LiteralType;

struct PercentLiteral {
    int32_t opening_char;
    int32_t closing_char;
    LiteralType type;
};
typedef struct PercentLiteral PercentLiteral;

struct State {
    bool has_leading_whitespace;
    PercentLiteral literal;
};
typedef struct State State;

#ifdef TREE_SITTER_INTERNAL_BUILD
#define DEBUG(...)                                                                          \
    if (getenv("TREE_SITTER_DEBUG") && strncmp(getenv("TREE_SITTER_DEBUG"), "1", 1) == 0) { \
        fprintf(stderr, __VA_ARGS__);                                                       \
    }
#else
#define DEBUG(...)
#endif

enum Token {
    LINE_BREAK,

    START_OF_BRACE_BLOCK,

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

    REGULAR_IF_KEYWORD,
    MODIFIER_IF_KEYWORD,

    REGULAR_UNLESS_KEYWORD,
    MODIFIER_UNLESS_KEYWORD,

    MODULO_OPERATOR,

    PERCENT_LITERAL_START,
    PERCENT_LITERAL_END,
    DELIMITED_STRING_CONTENTS,

    // Never returned
    START_OF_PARENLESS_ARGS,
    END_OF_RANGE,
    NONE,
};

void *tree_sitter_crystal_external_scanner_create() {
    State *state;

    state = malloc(sizeof(State));
    state->has_leading_whitespace = false;
    state->literal.opening_char = 0;
    state->literal.closing_char = 0;

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

    for (;;) {
        if (lexer->eof(lexer)) {
            DEBUG("reached EOF\n");
            return found_content;
        }

        switch (lexer->lookahead) {
            case '\\':
                switch (state->literal.type) {
                    case STRING:
                        return found_content;
                    case STRING_NO_ESCAPE:
                        break;
                    case STRING_ARRAY:
                        // TODO: %w and %i allow only '\ ' as an escape sequence
                        break;
                }
                break;
            case '"':
            case '|':
                // These delimiters can't nest
                if (state->literal.closing_char == lexer->lookahead) {
                    return found_content;
                }
                break;
            case '(':
            case '[':
            case '{':
            case '<':
                if (state->literal.opening_char == lexer->lookahead) {
                    // TODO: increase nesting
                }
                break;
            case ')':
            case ']':
            case '}':
            case '>':
                // TODO: check nesting
                if (state->literal.closing_char == lexer->lookahead) {
                    return found_content;
                }
                break;
                // TODO: # interpolation
        }

        lex_advance(lexer);
        found_content = true;
    }
}

bool tree_sitter_crystal_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    DEBUG("\n ==> starting external scan\n");
    DEBUG(" ==> char is '%c'\n", lexer->lookahead);
    DEBUG(" ==> valid symbols are:\n");
    if (valid_symbols[LINE_BREAK]) DEBUG("\tLINE_BREAK\n");
    if (valid_symbols[START_OF_BRACE_BLOCK]) DEBUG("\tSTART_OF_BRACE_BLOCK\n");
    if (valid_symbols[END_OF_WITH_EXPRESSSION]) DEBUG("\tEND_OF_WITH_EXPRESSSION\n");
    if (valid_symbols[UNARY_PLUS]) DEBUG("\tUNARY_PLUS\n");
    if (valid_symbols[UNARY_MINUS]) DEBUG("\tUNARY_MINUS\n");
    if (valid_symbols[BINARY_PLUS]) DEBUG("\tBINARY_PLUS\n");
    if (valid_symbols[BINARY_MINUS]) DEBUG("\tBINARY_MINUS\n");
    if (valid_symbols[UNARY_STAR]) DEBUG("\tUNARY_STAR\n");
    if (valid_symbols[BINARY_STAR]) DEBUG("\tBINARY_STAR\n");
    if (valid_symbols[START_OF_PARENLESS_ARGS]) DEBUG("\tSTART_OF_PARENLESS_ARGS\n");
    if (valid_symbols[REGULAR_IF_KEYWORD]) DEBUG("\tREGULAR_IF_KEYWORD\n");
    if (valid_symbols[MODIFIER_IF_KEYWORD]) DEBUG("\tMODIFIER_IF_KEYWORD\n");
    if (valid_symbols[REGULAR_UNLESS_KEYWORD]) DEBUG("\tREGULAR_UNLESS_KEYWORD\n");
    if (valid_symbols[MODIFIER_UNLESS_KEYWORD]) DEBUG("\tMODIFIER_UNLESS_KEYWORD\n");
    if (valid_symbols[END_OF_RANGE]) DEBUG("\tEND_OF_RANGE\n");
    if (valid_symbols[BEGINLESS_RANGE_OPERATOR]) DEBUG("\tBEGINLESS_RANGE_OPERATOR\n");
    if (valid_symbols[PERCENT_LITERAL_START]) DEBUG("\tPERCENT_LITERAL_START\n");
    if (valid_symbols[PERCENT_LITERAL_END]) DEBUG("\tPERCENT_LITERAL_END\n");
    if (valid_symbols[DELIMITED_STRING_CONTENTS]) DEBUG("\tDELIMITED_STRING_CONTENTS\n");
    if (valid_symbols[NONE]) DEBUG("\tNONE\n");

    State *state = (State *)payload;
    state->has_leading_whitespace = false;

    if (valid_symbols[DELIMITED_STRING_CONTENTS] && scan_string_contents(state, lexer, valid_symbols)) {
        lexer->result_symbol = DELIMITED_STRING_CONTENTS;
        return true;
    }

    lexer->result_symbol = NONE;

    if (!scan_whitespace(state, lexer, valid_symbols)) {
        return false;
    }

    if (lexer->result_symbol != NONE) {
        return true;
    }

    if (valid_symbols[PERCENT_LITERAL_END] && state->literal.closing_char != 0) {
        DEBUG(" %%%%%% checking PERCENT_LITERAL_END\n");
        if (lexer->lookahead == state->literal.closing_char) {
            lex_advance(lexer);
            state->literal.opening_char = 0;
            state->literal.closing_char = 0;
            lexer->result_symbol = PERCENT_LITERAL_END;
            return true;
        }
    }

    switch (lexer->lookahead) {
        case '{':
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

            // TODO: do we need to check START_OF_PARENLESS_ARGS here?
            /* if (valid_symbols[START_OF_BRACE_BLOCK] && valid_symbols[START_OF_PARENLESS_ARGS]) { */
            if (valid_symbols[START_OF_BRACE_BLOCK]) {
                lex_advance(lexer);
                lexer->result_symbol = START_OF_BRACE_BLOCK;
                return true;
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
                // first parameter of a method call, then it must be an intex
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
            if (valid_symbols[UNARY_PLUS] || valid_symbols[BINARY_PLUS]) {
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

                if (lexer->lookahead == '*') {
                    lex_advance(lexer);

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

                    // The binary form of &+ is alway preferred. E.g.
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

        case '%':
            if (valid_symbols[PERCENT_LITERAL_START]) {
                DEBUG(" %%%%%% checking PERCENT_LITERAL_START\n");
                lex_advance(lexer);

                LiteralType type = STRING;

                switch (lexer->lookahead) {
                    case 'Q':
                        lex_advance(lexer);
                        // type is already STRING
                        break;
                    case 'q':
                        lex_advance(lexer);
                        type = STRING_NO_ESCAPE;
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
                    lexer->result_symbol = PERCENT_LITERAL_START;

                    state->literal = (PercentLiteral){
                        .opening_char = opening_char,
                        .closing_char = closing_char,
                        .type = type};

                    return true;
                }

            } else if (valid_symbols[MODULO_OPERATOR]) {
                lex_advance(lexer);
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
                } else if (valid_symbols[REGULAR_IF_KEYWORD] && !valid_symbols[MODIFIER_IF_KEYWORD]) {
                    lexer->result_symbol = REGULAR_IF_KEYWORD;
                } else {
                    // Both are valid
                    if (valid_symbols[START_OF_PARENLESS_ARGS]) {
                        lexer->result_symbol = MODIFIER_IF_KEYWORD;
                    } else {
                        // probably this shouldn't be reached in valid code?
                        return false;
                    }
                }
                return true;
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
                } else if (valid_symbols[REGULAR_UNLESS_KEYWORD] && !valid_symbols[MODIFIER_UNLESS_KEYWORD]) {
                    lexer->result_symbol = REGULAR_UNLESS_KEYWORD;
                } else {
                    // Both are valid
                    if (valid_symbols[START_OF_PARENLESS_ARGS]) {
                        lexer->result_symbol = MODIFIER_UNLESS_KEYWORD;
                    } else {
                        // probably this shouldn't be reached in valid code?
                        return false;
                    }
                }
                return true;
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

    memcpy(state, buffer, length);
}

void tree_sitter_crystal_external_scanner_destroy(void *payload) {
    State *state = (State *)payload;
    free(state);
}
