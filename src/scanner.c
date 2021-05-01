#include <tree_sitter/parser.h>

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct State {
	bool has_leading_whitespace;
};
typedef struct State State;

enum Token {
	LINE_BREAK,

	UNARY_PLUS,
	UNARY_MINUS,
	BINARY_PLUS,
	BINARY_MINUS,

	NONE
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

	// printf(" ==> calling scan with char '%c'\n", lexer->lookahead);
	// printf(" ==> valid symbols are ");
	// if (valid_symbols[LINE_BREAK]) printf("LINE_BREAK,");
	// if (valid_symbols[UNARY_PLUS]) printf("UNARY_PLUS,");
	// if (valid_symbols[UNARY_MINUS]) printf("UNARY_MINUS,");
	// if (valid_symbols[BINARY_PLUS]) printf("BINARY_PLUS,");
	// if (valid_symbols[BINARY_MINUS]) printf("BINARY_MINUS,");
	// printf("\n");

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
				} else if (valid_symbols[BINARY_PLUS]) {
					lexer->result_symbol = BINARY_PLUS;
				} else {
					lexer->result_symbol = UNARY_PLUS;
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
				} else if (valid_symbols[BINARY_MINUS]) {
					lexer->result_symbol = BINARY_MINUS;
				} else {
					lexer->result_symbol = UNARY_MINUS;
				}

				return true;
			}
			break;
	}

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
