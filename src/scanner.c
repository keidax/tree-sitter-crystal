#include <tree_sitter/parser.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wctype.h>

struct State {
	bool has_leading_whitespace;
};
typedef struct State State;

#define DEBUG(...) if (getenv("TS_CRYSTAL_DEBUG") && \
	strncmp(getenv("TS_CRYSTAL_DEBUG"), "1", 1) == 0) { \
		fprintf(stderr, __VA_ARGS__); \
}

enum Token {
	LINE_BREAK,

	UNARY_PLUS,
	UNARY_MINUS,
	BINARY_PLUS,
	BINARY_MINUS,

	UNARY_STAR,
	BINARY_STAR,

	UNARY_DOUBLE_STAR,
	BINARY_DOUBLE_STAR,

	BEGINLESS_RANGE_OPERATOR,

	REGULAR_IF_KEYWORD,
	MODIFIER_IF_KEYWORD,

	REGULAR_UNLESS_KEYWORD,
	MODIFIER_UNLESS_KEYWORD,

	// Never returned
	START_OF_PARENLESS_ARGS,
	END_OF_RANGE,
	NONE,
};

void *tree_sitter_crystal_external_scanner_create() {
	State * state;

	state = malloc(sizeof(State));
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

	for(;;) {
		switch(lexer->lookahead) {
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

bool tree_sitter_crystal_external_scanner_scan(void *payload, TSLexer *lexer,
const bool *valid_symbols) {
	DEBUG("\n ==> starting external scan\n");
	DEBUG(" ==> char is '%c'\n", lexer->lookahead);
	DEBUG(" ==> valid symbols are:\n");
	if (valid_symbols[LINE_BREAK]) DEBUG("\tLINE_BREAK\n");
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
	if (valid_symbols[NONE]) DEBUG("\tNONE\n");

	State * state = (State*)payload;
	state->has_leading_whitespace = false;

	lexer->result_symbol = NONE;

	if (!scan_whitespace(state, lexer, valid_symbols)) {
		return false;
	}

	if (lexer->result_symbol != NONE) {
		return true;
	}

	switch(lexer->lookahead) {
		case '+':
			if (valid_symbols[UNARY_PLUS] || valid_symbols[BINARY_PLUS]) {
				lex_advance(lexer);

				if (lexer->lookahead == '=') {
					return false;
				}

				// Give precendence to the unary operator if:
				// - there is space before but not after, e.g.
				//		puts +foo
				// - we are just after a range operator, e.g.
				//		-5 .. + foo
				bool unary_priority = (state->has_leading_whitespace && !iswspace(lexer->lookahead))
					|| valid_symbols[END_OF_RANGE];

				if(valid_symbols[UNARY_PLUS] && unary_priority) {
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

				if(valid_symbols[UNARY_MINUS] && unary_priority) {
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
				if(lexer->lookahead != 'n') { return false; }
				lex_advance(lexer);
				if(lexer->lookahead != 'l') { return false; }
				lex_advance(lexer);
				if(lexer->lookahead != 'e') { return false; }
				lex_advance(lexer);
				if(lexer->lookahead != 's') { return false; }
				lex_advance(lexer);
				if(lexer->lookahead != 's') { return false; }

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
	}

	DEBUG(" ==> returning nothing at end\n");
	return false;
}

unsigned tree_sitter_crystal_external_scanner_serialize(void *payload, char *buffer) {
	State * state = (State*)payload;

	if (state->has_leading_whitespace) {
		*buffer = 1;
	} else {
		*buffer = 0;
	}

	return 1;
}

void tree_sitter_crystal_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
	State * state = (State*)payload;

	state->has_leading_whitespace = false;

	if (length == 0) {
		return;
	}

	if (*buffer) {
		state->has_leading_whitespace = true;
	} else {
		state->has_leading_whitespace = false;
	}
}

void tree_sitter_crystal_external_scanner_destroy(void *payload) {
	State * state = (State*)payload;
	free(state);
}
