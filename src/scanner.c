#include <tree_sitter/parser.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

	NONE,
};

void *tree_sitter_crystal_external_scanner_create() {
	State * state;

	state = malloc(sizeof(State));
	state->has_leading_whitespace = false;

	return state;
}

void skip(State *state, TSLexer *lexer) {
	state->has_leading_whitespace = true;
	lexer->advance(lexer, true);
}

bool scan_whitespace(State *state, TSLexer *lexer, const bool *valid_symbols) {
	bool crossed_newline = false;

	for(;;) {
		switch(lexer->lookahead) {
			case ' ':
			case '\t':
			case '\r':
				skip(state, lexer);
				break;

			case '\n':
				if (valid_symbols[LINE_BREAK] && !crossed_newline) {
					lexer->advance(lexer, false);
					lexer->mark_end(lexer);
					crossed_newline = true;
				} else {
					skip(state, lexer);
				}
				break;

			default:
				if (crossed_newline && lexer->lookahead != '.') {
					lexer->result_symbol = LINE_BREAK;
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
				lexer->advance(lexer, true);

				if (lexer->lookahead == '=') {
					return false;
				}

				if(valid_symbols[UNARY_PLUS] && state->has_leading_whitespace && !isspace(lexer->lookahead)) {
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
				lexer->advance(lexer, true);

				if (lexer->lookahead == '=' || lexer->lookahead == '>') {
					return false;
				}

				if(valid_symbols[UNARY_MINUS] && state->has_leading_whitespace && !isspace(lexer->lookahead)) {
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
