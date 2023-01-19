#include <tree_sitter/parser.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wctype.h>

// Functions for converting between UTF-8 and UTF-32
#include "unicode.c"

/*
 * Token types
 */

enum Token {
    LINE_BREAK,

    START_OF_BRACE_BLOCK,
    START_OF_HASH_OR_TUPLE,
    START_OF_NAMED_TUPLE,
    START_OF_TUPLE_TYPE,
    START_OF_NAMED_TUPLE_TYPE,

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

    HEREDOC_START,
    HEREDOC_BODY_START,
    HEREDOC_CONTENT,
    HEREDOC_END,

    REGEX_MODIFIER,

    // Never returned
    START_OF_PARENLESS_ARGS,
    END_OF_RANGE,

    // Only used when error recovery mode is active
    ERROR_RECOVERY,

    NONE,
};
typedef enum Token Token;

/*
 * Helpful macros
 */
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

/*
 * State types
 */

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

struct Heredoc {
    // The length of this identifer in bytes, after UTF-8 encoding.
    uint8_t byte_size;
    bool allow_escapes : 1;
    bool started : 1;
};
typedef struct Heredoc Heredoc;

#define MAX_LITERAL_COUNT 16
#define MAX_HEREDOC_COUNT 16
// The maximum number of bytes that can be stored in the state, across all heredocs
#define HEREDOC_BUFFER_SIZE 512
// We only use a single byte to store the size
#define MAX_HEREDOC_WORD_SIZE 255

struct State {
    bool has_leading_whitespace;

    // It's possible to have nested delimited literals, like
    //   %(#{%(foo)})
    // We can handle up to MAX_LITERAL_COUNT levels of nesting.
    uint8_t literal_count;
    PercentLiteral literal_stack[MAX_LITERAL_COUNT];

    uint8_t heredoc_count;
    Heredoc heredoc_queue[MAX_HEREDOC_COUNT];

    // Contains heredoc identifiers, encoded as UTF-8
    uint8_t heredoc_buffer[HEREDOC_BUFFER_SIZE];
};
typedef struct State State;

_Static_assert(sizeof(State) <= TREE_SITTER_SERIALIZATION_BUFFER_SIZE, "mesg");

/*
 * State-related macros and functions
 */

#define HAS_ACTIVE_LITERAL(state) \
    (state->literal_count > 0)

#define ACTIVE_LITERAL(state) \
    (state->literal_stack[state->literal_count - 1])

#define PUSH_LITERAL(state, literal) \
    (state->literal_stack[state->literal_count++] = literal)

#define POP_LITERAL(state) \
    (state->literal_stack[--state->literal_count] = (PercentLiteral){0, 0, 0, 0})

// Return true if any heredoc is started
static bool has_active_heredoc(State *state) {
    for (uint8_t i = 0; i < state->heredoc_count; i++) {
        if (state->heredoc_queue[i].started) {
            return true;
        }
    }
    return false;
}

// Return true if the first heredoc on the queue is unstarted
static bool has_unstarted_heredoc(State *state) {
    if (state->heredoc_count == 0) {
        return false;
    }

    return !state->heredoc_queue[0].started;
}

// Return the number of bytes currently stored in the heredoc word buffer
static size_t heredoc_current_buffer_size(State *state) {
    size_t bytes = 0;
    for (int i = 0; i < state->heredoc_count; i++) {
        bytes += state->heredoc_queue[i].byte_size;
    }
    return bytes;
}

// Pop the active heredoc off the queue
static void pop_heredoc(State *state) {
    ASSERT(state->heredoc_count > 0);
    ASSERT(state->heredoc_queue[0].started);

    uint8_t old_byte_size = state->heredoc_queue[0].byte_size;

    uint8_t count = state->heredoc_count - 1;
    state->heredoc_count = count;

    // Shift the queue forward by one element
    memmove(state->heredoc_queue, state->heredoc_queue + 1, sizeof(Heredoc) * count);

    // Zero out the empty space at the tail of the queue
    state->heredoc_queue[count] = (Heredoc){0, 0, 0};

    // Shift the word buffer forward
    size_t buffer_byte_size = heredoc_current_buffer_size(state);
    memmove(state->heredoc_buffer, state->heredoc_buffer + old_byte_size, buffer_byte_size);

    // Zero out the empty space in the word buffer
    memset(state->heredoc_buffer + buffer_byte_size, 0, old_byte_size);
}

// Return true if state has room to track another heredoc
static bool has_room_for_heredoc(State *state, Heredoc heredoc) {
    if (state->heredoc_count >= MAX_HEREDOC_COUNT) {
        return false;
    }

    size_t current_bytes = heredoc_current_buffer_size(state);
    return (current_bytes + heredoc.byte_size) <= HEREDOC_BUFFER_SIZE;
}

// Push a heredoc onto the end of the state queue. If there's already an active
// heredoc, the new heredoc must be nested, so it is added to the queue before
// the active heredoc.
static void push_heredoc(State *state, Heredoc heredoc, uint8_t *word) {
    ASSERT(state->heredoc_count < MAX_HEREDOC_COUNT);

    if (has_active_heredoc(state)) {
        // This must be a nested heredoc, so insert it before the currently-active heredoc
        uint8_t index;
        for (index = 0; index < state->heredoc_count; index++) {
            if (state->heredoc_queue[index].started) {
                break;
            }
        }
        ASSERT(index < state->heredoc_count);

        size_t heredocs_to_shift = state->heredoc_count - index;

        uint8_t *start_of_buffer_shift = state->heredoc_buffer;
        for (int i = 0; i < index; i++) {
            start_of_buffer_shift += state->heredoc_queue[i].byte_size;
        }

        size_t bytes_to_shift = 0;
        for (int i = index; i < state->heredoc_count; i++) {
            bytes_to_shift += state->heredoc_queue[i].byte_size;
        }

        // Make room in the word buffer
        memcpy(start_of_buffer_shift + heredoc.byte_size, start_of_buffer_shift, bytes_to_shift);

        // Copy in the new word
        memcpy(start_of_buffer_shift, word, heredoc.byte_size);

        // Make room in the queue
        memcpy(state->heredoc_queue + index + 1, state->heredoc_queue + index, sizeof(Heredoc) * heredocs_to_shift);

        // Copy in the new heredoc
        state->heredoc_queue[index] = heredoc;
        state->heredoc_count++;

    } else {
        size_t buffer_byte_size = heredoc_current_buffer_size(state);

        state->heredoc_queue[state->heredoc_count++] = heredoc;

        memcpy(state->heredoc_buffer + buffer_byte_size, word, heredoc.byte_size);
    }
}

enum LookaheadResult {
    LOOKAHEAD_UNKNOWN = 0,
    LOOKAHEAD_TYPE,
    LOOKAHEAD_NAMED_TUPLE,
};
typedef enum LookaheadResult LookaheadResult;

void *tree_sitter_crystal_external_scanner_create() {
    State *state;

    state = malloc(sizeof(State));
    memset(state, 0, sizeof(State));
    state->has_leading_whitespace = false;

    return state;
}

static void lex_skip(State *state, TSLexer *lexer) {
    state->has_leading_whitespace = true;
    lexer->advance(lexer, true);
}

// NOTE: apparently this can't be called `advance` because it conflicts with a
// symbol in glibc
static void lex_advance(TSLexer *lexer) {
    lexer->advance(lexer, false);
}

static bool next_char_is_identifier(TSLexer *lexer) {
    int32_t lookahead = lexer->lookahead;

    return iswalnum(lookahead)
        || lookahead == '_'
        || lookahead == '?'
        || lookahead == '!'
        || lookahead >= 0xa0;
}

// Usually scan_whitespace will handle starting heredocs, but it won't be called if a heredoc is
// already active. This function is called before heredoc contents or whitespace is scanned, so it
// can handle the start of a nested heredoc.
static bool check_for_heredoc_start(State *state, TSLexer *lexer, const bool *valid_symbols) {
    // Note: calling get_column(lexer) at EOF seems to cause loops, so make sure EOF is checked first
    if (valid_symbols[HEREDOC_BODY_START]
        && has_unstarted_heredoc(state)
        && !lexer->eof(lexer)
        && lexer->get_column(lexer) == 0) {

        ASSERT(state->heredoc_count > 0);
        ASSERT(!state->heredoc_queue[0].started);

        state->heredoc_queue[0].started = true;

        lexer->result_symbol = HEREDOC_BODY_START;
        return true;
    }
    return false;
}

static bool scan_whitespace(State *state, TSLexer *lexer, const bool *valid_symbols) {
    bool crossed_newline = false;

    for (;;) {
        switch (lexer->lookahead) {
            case ' ':
            case '\t':
            case '\r':
                lex_skip(state, lexer);
                break;

            case '\n':
                if (valid_symbols[HEREDOC_BODY_START] && has_unstarted_heredoc(state)) {
                    ASSERT(state->heredoc_count > 0);
                    ASSERT(!state->heredoc_queue[0].started);

                    state->heredoc_queue[0].started = true;
                    // HEREDOC_BODY_START is a zero-width token. Use skip instead
                    // of advance because we don't want to include the newline.
                    lex_skip(state, lexer);
                    lexer->result_symbol = HEREDOC_BODY_START;
                    return true;
                } else if (valid_symbols[LINE_BREAK] && !crossed_newline) {
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
                return false;

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
static bool scan_string_contents(State *state, TSLexer *lexer, const bool *valid_symbols) {
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

// Scan for heredoc contents, and return true if the body or end tag of the
// current heredoc is matched. This function will scan across multiple lines,
// so one heredoc_content node will contain as many characters as possible.
static bool scan_heredoc_contents(State *state, TSLexer *lexer, const bool *valid_symbols) {
    if (valid_symbols[ERROR_RECOVERY] && !has_active_heredoc(state)) {
        return false;
    }

    ASSERT(state->heredoc_count > 0);
    ASSERT(has_active_heredoc(state));

    bool found_content = false;

    Heredoc active_heredoc;
    bool heredoc_pending_start;

    if (state->heredoc_queue[0].started) {
        heredoc_pending_start = false;
        active_heredoc = state->heredoc_queue[0];
    } else {
        // The first heredoc in the queue isn't started, which means it's a
        // pending nested heredoc that will begin on the next line.
        heredoc_pending_start = true;
        for (uint8_t i = 1; i < state->heredoc_count; i++) {
            if (state->heredoc_queue[i].started) {
                active_heredoc = state->heredoc_queue[i];
                break;
            }
        }
    }

    for (;;) {
    start_of_line:
        if (found_content && heredoc_pending_start) {
            // We matched the remaining heredoc_content on a previous line after
            // the start of a nested heredoc. Now we return that content, and
            // the next call to the scanner will trigger check_for_heredoc_start.
            return true;
        }

        if (valid_symbols[HEREDOC_END] && !lexer->eof(lexer) && lexer->get_column(lexer) == 0) {
            if (found_content) {
                lexer->mark_end(lexer);
                while (lexer->lookahead == '\t' || lexer->lookahead == ' ') {
                    lex_advance(lexer);
                }

            } else {
                while (lexer->lookahead == '\t' || lexer->lookahead == ' ') {
                    lex_skip(state, lexer);
                }
                lexer->mark_end(lexer);
            }

            uint8_t byte_size = active_heredoc.byte_size;
            size_t matched_codepoint_count;

            // Load all the expected codepoints at once. Theoretically this is less efficient than
            // checking one codepoint at a time, but the actual performance impact is minimal.
            int32_t codepoints[MAX_HEREDOC_WORD_SIZE];
            size_t codepoint_count = utf8_to_codepoints(codepoints, state->heredoc_buffer, byte_size);

            for (matched_codepoint_count = 0; matched_codepoint_count < codepoint_count; matched_codepoint_count++) {
                int32_t expected_codepoint = codepoints[matched_codepoint_count];

                if (lexer->lookahead == expected_codepoint) {
                    lex_advance(lexer);
                } else {
                    break;
                }
            }

            bool end_of_line = (lexer->lookahead == '\n' || lexer->lookahead == '\r' || lexer->eof(lexer));

            if ((matched_codepoint_count == codepoint_count) && end_of_line) {
                if (found_content) {
                    // We already scanned content on a previous line, which must be
                    // returned. The next call to the scanner will match this heredoc word
                    // again, and return it.
                    return true;
                } else {
                    pop_heredoc(state);

                    lexer->mark_end(lexer);
                    lexer->result_symbol = HEREDOC_END;
                    return true;
                }
            }

            if (matched_codepoint_count > 0) {
                // lex_advance was called at least once while scanning for the heredoc
                // word, make sure those characters are counted as content.
                found_content = true;
                lexer->mark_end(lexer);
            }
        }

        // We found either a partial or no match for the heredoc identifier, so scan for string contents
        lexer->result_symbol = HEREDOC_CONTENT;

        for (;;) {
            if (lexer->eof(lexer)) {
                DEBUG("reached EOF\n");
                return found_content;
            }

            switch (lexer->lookahead) {
                case '\\':
                    if (active_heredoc.allow_escapes) {
                        return found_content;
                    }
                    break;

                case '#':
                    if (!active_heredoc.allow_escapes) {
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

                case '\r':
                    lex_advance(lexer);
                    lexer->mark_end(lexer);
                    found_content = true;

                    if (lexer->lookahead != '\n') {
                        continue;
                    }
                case '\n':
                    lex_advance(lexer);
                    lexer->mark_end(lexer);
                    found_content = true;
                    goto start_of_line;
            }

            lex_advance(lexer);
            lexer->mark_end(lexer);
            found_content = true;
        }
    }
}

static bool scan_regex_modifier(State *state, TSLexer *lexer, const bool *valid_symbols) {
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

static void skip_space(State *state, TSLexer *lexer) {
    while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
        lex_skip(state, lexer);
    }
}

static void skip_space_and_newline(State *state, TSLexer *lexer) {
    while (lexer->lookahead == ' '
        || lexer->lookahead == '\t'
        || lexer->lookahead == '\r'
        || lexer->lookahead == '\n') {
        lex_skip(state, lexer);
    }
}

static bool is_ident_part(int32_t codepoint) {
    // identifier token characters are in the range [0-9A-Za-z_\u{00a0}-\u{10ffff}]
    // (except for the first and last character)
    return ('0' <= codepoint && codepoint <= '9')
        || ('A' <= codepoint && codepoint <= 'Z')
        || ('a' <= codepoint && codepoint <= 'z')
        || (codepoint == '_')
        || (0x00a0 <= codepoint && codepoint <= 0x10ffffff);
}

static void consume_const(State *state, TSLexer *lexer) {
    if ('A' <= lexer->lookahead && lexer->lookahead <= 'Z') {
        lex_advance(lexer);

        while (is_ident_part(lexer->lookahead)) {
            lex_advance(lexer);
        }
    }
}

static void consume_string_literal(State *state, TSLexer *lexer) {
    bool can_escape = true, can_nest;
    int32_t opening_char = 0, closing_char, nesting_level = 0;

    if (lexer->lookahead == '"') {
        opening_char = '"';
        closing_char = '"';
        can_nest = false;
    } else if (lexer->lookahead == '%') {
        lex_advance(lexer);

        if (lexer->lookahead == 'q') {
            can_escape = false;
            lex_advance(lexer);
        } else if (lexer->lookahead == 'Q') {
            lex_advance(lexer);
        }

        switch (lexer->lookahead) {
            case '{':
                opening_char = '{';
                closing_char = '}';
                can_nest = true;
                break;
            case '(':
                opening_char = '(';
                closing_char = ')';
                can_nest = true;
                break;
            case '[':
                opening_char = '[';
                closing_char = ']';
                can_nest = true;
                break;
            case '<':
                opening_char = '<';
                closing_char = '>';
                can_nest = true;
                break;
            case '|':
                opening_char = '|';
                closing_char = '|';
                can_nest = false;
                break;
        }
    }

    if (!opening_char) {
        // this isn't a string
        return;
    }

    // advance past opening char
    lex_advance(lexer);

    for (;;) {

        if (lexer->eof(lexer)) {
            return;
        }

        if (lexer->lookahead == '\\' && can_escape) {
            // consume the backslash and next character
            lex_advance(lexer);
            lex_advance(lexer);
            continue;
        }

        if (lexer->lookahead == closing_char) {
            lex_advance(lexer);

            if (nesting_level == 0) {
                // reached the end of the literal
                return;
            }

            ASSERT(nesting_level > 0);
            nesting_level--;
            continue;
        }

        if (lexer->lookahead == opening_char && can_nest) {
            lex_advance(lexer);
            nesting_level++;
            continue;
        }

        lex_advance(lexer);
    }
}

// Check if there is a type suffix (e.g. `?` or `.class`) or a delimiter like `|`
static LookaheadResult lookahead_delimiter_or_type_suffix(State *state, TSLexer *lexer) {
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
            if (is_ident_part(lexer->lookahead)) {
                // the keyword doesn't end after `class`
                return LOOKAHEAD_UNKNOWN;
            } else {
                // .class type
                return LOOKAHEAD_TYPE;
            }

        case '?':
        case '*':
            lex_advance(lexer);
            return lookahead_delimiter_or_type_suffix(state, lexer);

        case '-':
            lex_advance(lexer);
            if (lexer->lookahead == '>') {
                // Const -> is considered a type suffix
                return LOOKAHEAD_TYPE;
            }
            return LOOKAHEAD_UNKNOWN;

        case '=':
            lex_advance(lexer);
            switch (lexer->lookahead) {
                case '>':
                    // Const => is considered a type suffix
                    return LOOKAHEAD_TYPE;
                case '=':
                case '~':
                    // other operators
                    return LOOKAHEAD_UNKNOWN;
                default:
                    // Const = is considered a type suffix
                    return LOOKAHEAD_TYPE;
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
            return LOOKAHEAD_TYPE;

        default:
            return LOOKAHEAD_UNKNOWN;
    }
}

// Check if there is an identifier followed by `:` indicating the start of a named tuple item
static LookaheadResult lookahead_start_of_named_tuple_entry(State *state, TSLexer *lexer, bool started) {
    if (started
        || ('a' <= lexer->lookahead && lexer->lookahead <= 'z')
        || ('A' <= lexer->lookahead && lexer->lookahead <= 'Z')
        || (lexer->lookahead == '_')
        || (0x00a0 <= lexer->lookahead && lexer->lookahead <= 0x10ffffff)) {

        while (('0' <= lexer->lookahead && lexer->lookahead <= '9')
            || ('A' <= lexer->lookahead && lexer->lookahead <= 'Z')
            || ('a' <= lexer->lookahead && lexer->lookahead <= 'z')
            || (lexer->lookahead == '_')
            || (0x00a0 <= lexer->lookahead && lexer->lookahead <= 0x10ffffff)) {
            lex_advance(lexer);
        }

        if ((lexer->lookahead == '!') || (lexer->lookahead == '?')) {
            lex_advance(lexer);
        }

        if (lexer->lookahead == ':') {
            lex_advance(lexer);
            if (lexer->lookahead == ':') {
                return LOOKAHEAD_UNKNOWN;
            }

            return LOOKAHEAD_NAMED_TUPLE;
        }
    }

    if (lexer->lookahead == '"' || lexer->lookahead == '%') {
        consume_string_literal(state, lexer);

        if (lexer->lookahead == ':') {
            lex_advance(lexer);
            if (lexer->lookahead == ':') {
                return LOOKAHEAD_UNKNOWN;
            }

            return LOOKAHEAD_NAMED_TUPLE;
        }
    }

    return LOOKAHEAD_UNKNOWN;
}

// Check to see if the next token is part of the type grammar or not. Based on
// https://github.com/crystal-lang/crystal/blob/cd2b7d6490301e092cecc22dfbc91d0f9553ba20/src/compiler/crystal/syntax/parser.cr#L5195
// As the compiler code notes, these conditions are not completely accurate in determining what
// could or could not be a type.
static LookaheadResult lookahead_start_of_type(State *state, TSLexer *lexer) {

    skip_space(state, lexer);

    if (lexer->eof(lexer)) {
        DEBUG("reached EOF\n");
        return LOOKAHEAD_UNKNOWN;
    }

    while (lexer->lookahead == '{' || lexer->lookahead == '(') {
        lex_advance(lexer);
        skip_space_and_newline(state, lexer);
    }

    // Check for identifier
    if (lexer->lookahead == 't') {
        lex_advance(lexer);
        if (lexer->lookahead == 'y') {
            lex_advance(lexer);
            if (lexer->lookahead == 'p') {
                lex_advance(lexer);
                if (lexer->lookahead == 'e') {
                    lex_advance(lexer);
                    if (lexer->lookahead == 'o') {
                        lex_advance(lexer);
                        if (lexer->lookahead == 'f') {
                            lex_advance(lexer);

                            if (lexer->lookahead == ':') {
                                // named tuple start
                                return LOOKAHEAD_NAMED_TUPLE;
                            }

                            if (is_ident_part(lexer->lookahead)
                                || (lexer->lookahead == '!')
                                || (lexer->lookahead == '?')) {
                                // identifier continues beyond `typeof`
                                return lookahead_start_of_named_tuple_entry(state, lexer, true);
                            }

                            return LOOKAHEAD_TYPE;
                        }
                    }
                }
            }
        }
    } else if (lexer->lookahead == 's') {
        lex_advance(lexer);
        if (lexer->lookahead == 'e') {
            lex_advance(lexer);
            if (lexer->lookahead == 'l') {
                lex_advance(lexer);
                if (lexer->lookahead == 'f') {
                    lex_advance(lexer);

                    if (lexer->lookahead == ':') {
                        // named tuple start
                        return LOOKAHEAD_NAMED_TUPLE;
                    }

                    if (is_ident_part(lexer->lookahead)
                        || (lexer->lookahead == '!')) {
                        // identifier continues beyond `self`
                        return lookahead_start_of_named_tuple_entry(state, lexer, true);
                    }

                    skip_space(state, lexer);
                    return lookahead_delimiter_or_type_suffix(state, lexer);
                }
            }
        }
    } else if (('a' <= lexer->lookahead && lexer->lookahead <= 'z')
        || (0x00a0 <= lexer->lookahead && lexer->lookahead <= 0x10ffffff)) {
        // other identifiers are not part of the type grammar
        return lookahead_start_of_named_tuple_entry(state, lexer, false);
    }

    // Check for constant
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
                return LOOKAHEAD_NAMED_TUPLE;
            }
        } else {
            skip_space(state, lexer);
            return lookahead_delimiter_or_type_suffix(state, lexer);
        }
    }

    switch (lexer->lookahead) {
        case '_':
            lex_advance(lexer);
            if (!iswalnum(lexer->lookahead)) {
                // This is just a plain underscore
                return LOOKAHEAD_TYPE;
            }
            break;
        case '-':
            lex_advance(lexer);
            if (lexer->lookahead == '>') {
                // proc type
                return LOOKAHEAD_TYPE;
            }
            break;
        case '*':
            lex_advance(lexer);
            skip_space_and_newline(state, lexer);
            if (lexer->lookahead == '*') {
                // double splat is not a valid type operator
                return LOOKAHEAD_UNKNOWN;
            } else {
                if (lookahead_start_of_type(state, lexer) == LOOKAHEAD_TYPE) {
                    return LOOKAHEAD_TYPE;
                } else {
                    // If lookahead_start_of_type returns LOOKAHEAD_NAMED_TUPLE
                    // at this point, it's not valid, because named tuple tags
                    // can't start with '*'
                    return LOOKAHEAD_UNKNOWN;
                }
            }
            break;
        case '"':
        case '%':
            return lookahead_start_of_named_tuple_entry(state, lexer, false);
    }

    DEBUG("Not the start of a type\n");
    return LOOKAHEAD_UNKNOWN;
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
    LOG_SYMBOL(START_OF_NAMED_TUPLE);
    LOG_SYMBOL(START_OF_TUPLE_TYPE);
    LOG_SYMBOL(START_OF_NAMED_TUPLE_TYPE);
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
    LOG_SYMBOL(HEREDOC_START);
    LOG_SYMBOL(HEREDOC_BODY_START);
    LOG_SYMBOL(HEREDOC_CONTENT);
    LOG_SYMBOL(HEREDOC_END);
    LOG_SYMBOL(REGEX_MODIFIER);
    LOG_SYMBOL(START_OF_PARENLESS_ARGS);
    LOG_SYMBOL(END_OF_RANGE);
    LOG_SYMBOL(ERROR_RECOVERY);

    State *state = (State *)payload;
    state->has_leading_whitespace = false;

    if (check_for_heredoc_start(state, lexer, valid_symbols)) {
        return true;
    }

    if (valid_symbols[DELIMITED_STRING_CONTENTS] && HAS_ACTIVE_LITERAL(state) && scan_string_contents(state, lexer, valid_symbols)) {
        return true;
    }

    if (valid_symbols[HEREDOC_CONTENT] && state->heredoc_count > 0 && scan_heredoc_contents(state, lexer, valid_symbols)) {
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

            // We expect these symbols to always be valid or not valid together
            ASSERT(valid_symbols[START_OF_HASH_OR_TUPLE] == valid_symbols[START_OF_NAMED_TUPLE]);
            ASSERT(valid_symbols[START_OF_TUPLE_TYPE] == valid_symbols[START_OF_NAMED_TUPLE_TYPE]);

#define BRACE_BLOCK (valid_symbols[START_OF_BRACE_BLOCK])
#define BRACE_EXPR (valid_symbols[START_OF_HASH_OR_TUPLE] || valid_symbols[START_OF_NAMED_TUPLE])
#define BRACE_TYPE (valid_symbols[START_OF_TUPLE_TYPE] || valid_symbols[START_OF_NAMED_TUPLE_TYPE])

            if (BRACE_BLOCK || BRACE_EXPR || BRACE_TYPE) {
                if (BRACE_BLOCK && BRACE_EXPR && BRACE_TYPE) {
                    if (valid_symbols[ERROR_RECOVERY]) {
                        return false;
                    } else {
                        // Shouldn't reach here
                        ASSERT(!(
                            valid_symbols[START_OF_BRACE_BLOCK]
                            && (valid_symbols[START_OF_HASH_OR_TUPLE] || valid_symbols[START_OF_NAMED_TUPLE])
                            && (valid_symbols[START_OF_TUPLE_TYPE] || valid_symbols[START_OF_NAMED_TUPLE_TYPE])));
                        return false;
                    }
                } else if (BRACE_BLOCK && BRACE_EXPR) {
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
                } else if (BRACE_BLOCK && BRACE_TYPE) {

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

                    switch (lookahead_start_of_type(state, lexer)) {
                        case LOOKAHEAD_TYPE:
                            ASSERT(valid_symbols[START_OF_TUPLE_TYPE]);
                            lexer->result_symbol = START_OF_TUPLE_TYPE;
                            return true;

                        case LOOKAHEAD_NAMED_TUPLE:
                            // When the Crystal parser is trying to resolve whether a token is part
                            // of a type or not, anything that looks like the start of a named
                            // tuple is assumed _not_ to be a type.
                            lexer->result_symbol = START_OF_BRACE_BLOCK;
                            return true;

                        default:
                            lexer->result_symbol = START_OF_BRACE_BLOCK;
                            return true;
                    }

                } else if (BRACE_EXPR && BRACE_TYPE) {

                    lex_advance(lexer);
                    // We don't want to consume while looking ahead
                    lexer->mark_end(lexer);

                    // Use type lookahead to resolve conflict between start of hash/tuple and start of tuple type
                    // For example, as a tuple type:
                    //   def foo : ->{Char,Char}; ->{ {'a','b'} } end
                    // Or as a hash:
                    //   def foo : ->{'a'=>'b'}; ->{ nil } end

                    switch (lookahead_start_of_type(state, lexer)) {
                        case LOOKAHEAD_TYPE:
                            ASSERT(valid_symbols[START_OF_TUPLE_TYPE]);
                            lexer->result_symbol = START_OF_TUPLE_TYPE;
                            return true;

                        case LOOKAHEAD_NAMED_TUPLE:
                            // When the Crystal parser is trying to resolve whether a token is part
                            // of a type or not, anything that looks like the start of a named
                            // tuple is assumed _not_ to be a type.
                            ASSERT(valid_symbols[START_OF_NAMED_TUPLE]);
                            lexer->result_symbol = START_OF_NAMED_TUPLE;
                            return true;

                        default:
                            ASSERT(valid_symbols[START_OF_HASH_OR_TUPLE]);
                            lexer->result_symbol = START_OF_HASH_OR_TUPLE;
                            return true;
                    }

                } else if (BRACE_EXPR) {
                    lex_advance(lexer);
                    // We don't want to consume while looking ahead
                    lexer->mark_end(lexer);
                    skip_space_and_newline(state, lexer);

                    switch (lookahead_start_of_named_tuple_entry(state, lexer, false)) {
                        case LOOKAHEAD_NAMED_TUPLE:
                            ASSERT(valid_symbols[START_OF_NAMED_TUPLE]);
                            lexer->result_symbol = START_OF_NAMED_TUPLE;
                            return true;

                        default:
                            ASSERT(valid_symbols[START_OF_HASH_OR_TUPLE]);
                            lexer->result_symbol = START_OF_HASH_OR_TUPLE;
                            return true;
                    }

                } else if (BRACE_TYPE) {
                    lex_advance(lexer);
                    // We don't want to consume while looking ahead
                    lexer->mark_end(lexer);
                    skip_space_and_newline(state, lexer);

                    switch (lookahead_start_of_named_tuple_entry(state, lexer, false)) {
                        case LOOKAHEAD_NAMED_TUPLE:
                            ASSERT(valid_symbols[START_OF_NAMED_TUPLE_TYPE]);
                            lexer->result_symbol = START_OF_NAMED_TUPLE_TYPE;
                            return true;

                        default:
                            ASSERT(valid_symbols[START_OF_TUPLE_TYPE]);
                            lexer->result_symbol = START_OF_TUPLE_TYPE;
                            return true;
                    }

                } else if (BRACE_BLOCK) {
                    lex_advance(lexer);
                    lexer->result_symbol = START_OF_BRACE_BLOCK;
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

        case '<':
            if (valid_symbols[HEREDOC_START]) {
                lex_advance(lexer);

                if (lexer->lookahead == '<') {
                    lex_advance(lexer);

                    if (lexer->lookahead == '-') {
                        lex_advance(lexer);
                        bool quoted = false;
                        bool got_end_quote = false;

                        if (lexer->lookahead == '\'') {
                            quoted = true;
                            lex_advance(lexer);
                        }

                        // How much space is left for this heredoc identifier.
                        size_t max_word_size = HEREDOC_BUFFER_SIZE - heredoc_current_buffer_size(state);
                        if (max_word_size < 1) {
                            return false;
                        }

                        if (max_word_size > MAX_HEREDOC_WORD_SIZE) {
                            max_word_size = MAX_HEREDOC_WORD_SIZE;
                        }

                        uint8_t word[max_word_size + 4];
                        size_t word_length = 0;

                        // First character must be valid in an identifier, even for a quoted heredoc
                        if (is_ident_part(lexer->lookahead)) {
                            size_t byte_size = codepoint_to_utf8(lexer->lookahead, word);
                            if (byte_size == 0) {
                                // We couldn't convert the codepoint
                                return false;
                            }

                            word_length = byte_size;
                            lex_advance(lexer);
                        } else {
                            return false;
                        }

                        while (word_length <= max_word_size) {
                            if (lexer->lookahead == '\r' || lexer->lookahead == '\n' || lexer->eof(lexer)) {
                                // Reached the end of the line
                                break;
                            }

                            if (lexer->lookahead == '\'' && quoted) {
                                // This must be the end of the identifier
                                got_end_quote = true;
                                lex_advance(lexer);
                                break;
                            }

                            if (quoted || is_ident_part(lexer->lookahead)) {
                                // Add to the identifier buffer
                                size_t byte_size = codepoint_to_utf8(lexer->lookahead, word + word_length);
                                if (byte_size == 0) {
                                    // We couldn't convert the codepoint
                                    return false;
                                }

                                word_length += byte_size;
                                lex_advance(lexer);
                            } else {
                                // Not a valid identifier character
                                break;
                            }
                        }

                        if (word_length == 0) {
                            // There wasn't a valid heredoc identifier
                            return false;
                        } else if ((word_length > max_word_size) || (word_length == max_word_size && is_ident_part(lexer->lookahead))) {
                            // The heredoc identifier is too big to store in state.
                            return false;
                        } else if (quoted && !got_end_quote) {
                            // Unterminated quoted heredoc
                            return false;
                        } else {
                            // word contains a heredoc identifier we can store.
                            Heredoc heredoc = {
                                .allow_escapes = !quoted,
                                .started = false,
                                .byte_size = word_length,
                            };

                            // double check we can safely store the new heredoc
                            if (!has_room_for_heredoc(state, heredoc)) {
                                return false;
                            }

                            push_heredoc(state, heredoc, word);

                            lexer->result_symbol = HEREDOC_START;
                            DEBUG(" ==> returning HEREDOC_START (size %d)\n", word_length);
                            return true;
                        }
                    }
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
                || valid_symbols[BINARY_DOUBLE_SLASH]) {

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
            break;
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
