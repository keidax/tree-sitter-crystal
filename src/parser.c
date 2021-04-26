#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 30
#define LARGE_STATE_COUNT 8
#define SYMBOL_COUNT 22
#define ALIAS_COUNT 0
#define TOKEN_COUNT 14
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_LF = 1,
  anon_sym_SEMI = 2,
  anon_sym_LPAREN = 3,
  anon_sym_RPAREN = 4,
  sym_nil = 5,
  sym_true = 6,
  sym_false = 7,
  sym_integer = 8,
  sym_float = 9,
  anon_sym_SQUOTE = 10,
  aux_sym_char_token1 = 11,
  anon_sym_SQUOTE2 = 12,
  sym_char_escape_sequence = 13,
  sym_source_file = 14,
  sym__terminator = 15,
  sym__statements = 16,
  sym__parenthesized_statements = 17,
  sym__statement = 18,
  sym__expression = 19,
  sym_char = 20,
  aux_sym__statements_repeat1 = 21,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LF] = "\n",
  [anon_sym_SEMI] = ";",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_nil] = "nil",
  [sym_true] = "true",
  [sym_false] = "false",
  [sym_integer] = "integer",
  [sym_float] = "float",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_char_token1] = "char_token1",
  [anon_sym_SQUOTE2] = "'",
  [sym_char_escape_sequence] = "char_escape_sequence",
  [sym_source_file] = "source_file",
  [sym__terminator] = "_terminator",
  [sym__statements] = "_statements",
  [sym__parenthesized_statements] = "_parenthesized_statements",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym_char] = "char",
  [aux_sym__statements_repeat1] = "_statements_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_nil] = sym_nil,
  [sym_true] = sym_true,
  [sym_false] = sym_false,
  [sym_integer] = sym_integer,
  [sym_float] = sym_float,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_char_token1] = aux_sym_char_token1,
  [anon_sym_SQUOTE2] = anon_sym_SQUOTE,
  [sym_char_escape_sequence] = sym_char_escape_sequence,
  [sym_source_file] = sym_source_file,
  [sym__terminator] = sym__terminator,
  [sym__statements] = sym__statements,
  [sym__parenthesized_statements] = sym__parenthesized_statements,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym_char] = sym_char,
  [aux_sym__statements_repeat1] = aux_sym__statements_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_nil] = {
    .visible = true,
    .named = true,
  },
  [sym_true] = {
    .visible = true,
    .named = true,
  },
  [sym_false] = {
    .visible = true,
    .named = true,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_float] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_char_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE2] = {
    .visible = true,
    .named = false,
  },
  [sym_char_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__terminator] = {
    .visible = false,
    .named = true,
  },
  [sym__statements] = {
    .visible = false,
    .named = true,
  },
  [sym__parenthesized_statements] = {
    .visible = false,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_char] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__statements_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static inline bool sym_char_escape_sequence_character_set_1(int32_t c) {
  return (c < 'e'
    ? (c < '\\'
      ? (c < '0'
        ? c == '\''
        : c <= '0')
      : (c <= '\\' || (c >= 'a' && c <= 'b')))
    : (c <= 'f' || (c < 't'
      ? (c < 'r'
        ? c == 'n'
        : c <= 'r')
      : (c <= 't' || c == 'v'))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(37);
      if (lookahead == '\'') ADVANCE(57);
      if (lookahead == '(') ADVANCE(40);
      if (lookahead == ')') ADVANCE(41);
      if (lookahead == '0') ADVANCE(46);
      if (lookahead == ';') ADVANCE(39);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead == 'f') ADVANCE(11);
      if (lookahead == 'n') ADVANCE(14);
      if (lookahead == 't') ADVANCE(17);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(36)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(47);
      END_STATE();
    case 1:
      if (lookahead == '0') ADVANCE(46);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(47);
      END_STATE();
    case 2:
      if (lookahead == '1') ADVANCE(5);
      if (lookahead == '3') ADVANCE(3);
      if (lookahead == '6') ADVANCE(7);
      if (lookahead == '8') ADVANCE(45);
      END_STATE();
    case 3:
      if (lookahead == '2') ADVANCE(45);
      END_STATE();
    case 4:
      if (lookahead == '2') ADVANCE(51);
      END_STATE();
    case 5:
      if (lookahead == '2') ADVANCE(9);
      if (lookahead == '6') ADVANCE(45);
      END_STATE();
    case 6:
      if (lookahead == '3') ADVANCE(4);
      if (lookahead == '6') ADVANCE(8);
      END_STATE();
    case 7:
      if (lookahead == '4') ADVANCE(45);
      END_STATE();
    case 8:
      if (lookahead == '4') ADVANCE(51);
      END_STATE();
    case 9:
      if (lookahead == '8') ADVANCE(45);
      END_STATE();
    case 10:
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead != 0) ADVANCE(56);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(15);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(43);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(44);
      END_STATE();
    case 14:
      if (lookahead == 'i') ADVANCE(16);
      END_STATE();
    case 15:
      if (lookahead == 'l') ADVANCE(18);
      END_STATE();
    case 16:
      if (lookahead == 'l') ADVANCE(42);
      END_STATE();
    case 17:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 18:
      if (lookahead == 's') ADVANCE(13);
      END_STATE();
    case 19:
      if (lookahead == 'u') ADVANCE(12);
      END_STATE();
    case 20:
      if (lookahead == '{') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 21:
      if (lookahead == '}') ADVANCE(58);
      END_STATE();
    case 22:
      if (lookahead == '}') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(21);
      END_STATE();
    case 23:
      if (lookahead == '}') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 24:
      if (lookahead == '}') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(23);
      END_STATE();
    case 25:
      if (lookahead == '}') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 26:
      if (lookahead == '}') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(53);
      END_STATE();
    case 28:
      if (sym_char_escape_sequence_character_set_1(lookahead)) ADVANCE(58);
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 29:
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(54);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(58);
      END_STATE();
    case 31:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 34:
      if (eof) ADVANCE(37);
      if (lookahead == '\n') ADVANCE(38);
      if (lookahead == '\'') ADVANCE(57);
      if (lookahead == ')') ADVANCE(41);
      if (lookahead == ';') ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(35)
      END_STATE();
    case 35:
      if (eof) ADVANCE(37);
      if (lookahead == '\n') ADVANCE(38);
      if (lookahead == ')') ADVANCE(41);
      if (lookahead == ';') ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(35)
      END_STATE();
    case 36:
      if (eof) ADVANCE(37);
      if (lookahead == '\'') ADVANCE(55);
      if (lookahead == '(') ADVANCE(40);
      if (lookahead == ')') ADVANCE(41);
      if (lookahead == '0') ADVANCE(46);
      if (lookahead == ';') ADVANCE(39);
      if (lookahead == 'f') ADVANCE(11);
      if (lookahead == 'n') ADVANCE(14);
      if (lookahead == 't') ADVANCE(17);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(36)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(47);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_nil);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_integer);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '_') ADVANCE(47);
      if (lookahead == 'b') ADVANCE(48);
      if (lookahead == 'f') ADVANCE(6);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'o') ADVANCE(49);
      if (lookahead == 'u') ADVANCE(2);
      if (lookahead == 'x') ADVANCE(50);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == 'f') ADVANCE(6);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'u') ADVANCE(2);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(47);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'u') ADVANCE(2);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(48);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'u') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'u') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_float);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(6);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(54);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(6);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_char_token1);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_SQUOTE2);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_char_escape_sequence);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 36},
  [2] = {.lex_state = 36},
  [3] = {.lex_state = 36},
  [4] = {.lex_state = 36},
  [5] = {.lex_state = 36},
  [6] = {.lex_state = 36},
  [7] = {.lex_state = 36},
  [8] = {.lex_state = 36},
  [9] = {.lex_state = 36},
  [10] = {.lex_state = 34},
  [11] = {.lex_state = 34},
  [12] = {.lex_state = 34},
  [13] = {.lex_state = 34},
  [14] = {.lex_state = 34},
  [15] = {.lex_state = 34},
  [16] = {.lex_state = 34},
  [17] = {.lex_state = 34},
  [18] = {.lex_state = 34},
  [19] = {.lex_state = 34},
  [20] = {.lex_state = 34},
  [21] = {.lex_state = 34},
  [22] = {.lex_state = 10},
  [23] = {.lex_state = 10},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 34},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 34},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_nil] = ACTIONS(1),
    [sym_true] = ACTIONS(1),
    [sym_false] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_float] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE2] = ACTIONS(1),
    [sym_char_escape_sequence] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(27),
    [sym__statements] = STATE(26),
    [sym__parenthesized_statements] = STATE(13),
    [sym__statement] = STATE(13),
    [sym__expression] = STATE(13),
    [sym_char] = STATE(13),
    [aux_sym__statements_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(9),
    [sym_true] = ACTIONS(9),
    [sym_false] = ACTIONS(9),
    [sym_integer] = ACTIONS(11),
    [sym_float] = ACTIONS(9),
    [anon_sym_SQUOTE] = ACTIONS(13),
  },
  [2] = {
    [sym__statements] = STATE(24),
    [sym__parenthesized_statements] = STATE(12),
    [sym__statement] = STATE(12),
    [sym__expression] = STATE(12),
    [sym_char] = STATE(12),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(15),
    [anon_sym_LPAREN] = ACTIONS(17),
    [anon_sym_RPAREN] = ACTIONS(19),
    [sym_nil] = ACTIONS(21),
    [sym_true] = ACTIONS(21),
    [sym_false] = ACTIONS(21),
    [sym_integer] = ACTIONS(23),
    [sym_float] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(25),
  },
  [3] = {
    [sym__statements] = STATE(28),
    [sym__parenthesized_statements] = STATE(12),
    [sym__statement] = STATE(12),
    [sym__expression] = STATE(12),
    [sym_char] = STATE(12),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(15),
    [anon_sym_LPAREN] = ACTIONS(17),
    [anon_sym_RPAREN] = ACTIONS(27),
    [sym_nil] = ACTIONS(21),
    [sym_true] = ACTIONS(21),
    [sym_false] = ACTIONS(21),
    [sym_integer] = ACTIONS(23),
    [sym_float] = ACTIONS(21),
    [anon_sym_SQUOTE] = ACTIONS(25),
  },
  [4] = {
    [sym__parenthesized_statements] = STATE(16),
    [sym__statement] = STATE(16),
    [sym__expression] = STATE(16),
    [sym_char] = STATE(16),
    [aux_sym__statements_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(29),
    [anon_sym_SEMI] = ACTIONS(31),
    [anon_sym_LPAREN] = ACTIONS(34),
    [sym_nil] = ACTIONS(37),
    [sym_true] = ACTIONS(37),
    [sym_false] = ACTIONS(37),
    [sym_integer] = ACTIONS(40),
    [sym_float] = ACTIONS(37),
    [anon_sym_SQUOTE] = ACTIONS(43),
  },
  [5] = {
    [sym__parenthesized_statements] = STATE(21),
    [sym__statement] = STATE(21),
    [sym__expression] = STATE(21),
    [sym_char] = STATE(21),
    [aux_sym__statements_repeat1] = STATE(5),
    [anon_sym_SEMI] = ACTIONS(46),
    [anon_sym_LPAREN] = ACTIONS(34),
    [anon_sym_RPAREN] = ACTIONS(29),
    [sym_nil] = ACTIONS(49),
    [sym_true] = ACTIONS(49),
    [sym_false] = ACTIONS(49),
    [sym_integer] = ACTIONS(52),
    [sym_float] = ACTIONS(49),
    [anon_sym_SQUOTE] = ACTIONS(43),
  },
  [6] = {
    [sym__parenthesized_statements] = STATE(11),
    [sym__statement] = STATE(11),
    [sym__expression] = STATE(11),
    [sym_char] = STATE(11),
    [aux_sym__statements_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(55),
    [anon_sym_SEMI] = ACTIONS(57),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(59),
    [sym_true] = ACTIONS(59),
    [sym_false] = ACTIONS(59),
    [sym_integer] = ACTIONS(61),
    [sym_float] = ACTIONS(59),
    [anon_sym_SQUOTE] = ACTIONS(13),
  },
  [7] = {
    [sym__parenthesized_statements] = STATE(10),
    [sym__statement] = STATE(10),
    [sym__expression] = STATE(10),
    [sym_char] = STATE(10),
    [aux_sym__statements_repeat1] = STATE(5),
    [anon_sym_SEMI] = ACTIONS(63),
    [anon_sym_LPAREN] = ACTIONS(17),
    [anon_sym_RPAREN] = ACTIONS(55),
    [sym_nil] = ACTIONS(65),
    [sym_true] = ACTIONS(65),
    [sym_false] = ACTIONS(65),
    [sym_integer] = ACTIONS(67),
    [sym_float] = ACTIONS(65),
    [anon_sym_SQUOTE] = ACTIONS(25),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(69), 1,
      sym_integer,
    ACTIONS(29), 8,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      anon_sym_SQUOTE,
  [14] = 2,
    ACTIONS(69), 1,
      sym_integer,
    ACTIONS(29), 8,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      anon_sym_SQUOTE,
  [28] = 4,
    ACTIONS(71), 1,
      anon_sym_LF,
    ACTIONS(73), 1,
      anon_sym_SEMI,
    ACTIONS(75), 1,
      anon_sym_RPAREN,
    STATE(8), 1,
      sym__terminator,
  [41] = 4,
    ACTIONS(77), 1,
      ts_builtin_sym_end,
    ACTIONS(79), 1,
      anon_sym_LF,
    ACTIONS(81), 1,
      anon_sym_SEMI,
    STATE(9), 1,
      sym__terminator,
  [54] = 4,
    ACTIONS(71), 1,
      anon_sym_LF,
    ACTIONS(73), 1,
      anon_sym_SEMI,
    ACTIONS(83), 1,
      anon_sym_RPAREN,
    STATE(8), 1,
      sym__terminator,
  [67] = 4,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    ACTIONS(79), 1,
      anon_sym_LF,
    ACTIONS(81), 1,
      anon_sym_SEMI,
    STATE(9), 1,
      sym__terminator,
  [80] = 2,
    ACTIONS(87), 1,
      anon_sym_SEMI,
    ACTIONS(85), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [88] = 2,
    ACTIONS(91), 1,
      anon_sym_SEMI,
    ACTIONS(89), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [96] = 3,
    ACTIONS(79), 1,
      anon_sym_LF,
    ACTIONS(81), 1,
      anon_sym_SEMI,
    STATE(9), 1,
      sym__terminator,
  [106] = 2,
    ACTIONS(93), 1,
      anon_sym_LF,
    ACTIONS(95), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [114] = 2,
    ACTIONS(95), 1,
      anon_sym_SEMI,
    ACTIONS(93), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [122] = 2,
    ACTIONS(85), 1,
      anon_sym_LF,
    ACTIONS(87), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [130] = 2,
    ACTIONS(89), 1,
      anon_sym_LF,
    ACTIONS(91), 2,
      anon_sym_SEMI,
      anon_sym_RPAREN,
  [138] = 3,
    ACTIONS(71), 1,
      anon_sym_LF,
    ACTIONS(73), 1,
      anon_sym_SEMI,
    STATE(8), 1,
      sym__terminator,
  [148] = 1,
    ACTIONS(97), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [153] = 1,
    ACTIONS(99), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [158] = 1,
    ACTIONS(101), 1,
      anon_sym_RPAREN,
  [162] = 1,
    ACTIONS(103), 1,
      anon_sym_SQUOTE2,
  [166] = 1,
    ACTIONS(105), 1,
      ts_builtin_sym_end,
  [170] = 1,
    ACTIONS(107), 1,
      ts_builtin_sym_end,
  [174] = 1,
    ACTIONS(109), 1,
      anon_sym_RPAREN,
  [178] = 1,
    ACTIONS(111), 1,
      anon_sym_SQUOTE2,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(8)] = 0,
  [SMALL_STATE(9)] = 14,
  [SMALL_STATE(10)] = 28,
  [SMALL_STATE(11)] = 41,
  [SMALL_STATE(12)] = 54,
  [SMALL_STATE(13)] = 67,
  [SMALL_STATE(14)] = 80,
  [SMALL_STATE(15)] = 88,
  [SMALL_STATE(16)] = 96,
  [SMALL_STATE(17)] = 106,
  [SMALL_STATE(18)] = 114,
  [SMALL_STATE(19)] = 122,
  [SMALL_STATE(20)] = 130,
  [SMALL_STATE(21)] = 138,
  [SMALL_STATE(22)] = 148,
  [SMALL_STATE(23)] = 153,
  [SMALL_STATE(24)] = 158,
  [SMALL_STATE(25)] = 162,
  [SMALL_STATE(26)] = 166,
  [SMALL_STATE(27)] = 170,
  [SMALL_STATE(28)] = 174,
  [SMALL_STATE(29)] = 178,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(4),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(3),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(16),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(16),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(23),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(5),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(21),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(21),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 1),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 2),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 3),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__parenthesized_statements, 3),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char, 3),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char, 3),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 2),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__parenthesized_statements, 2),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [107] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_crystal(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = (const uint16_t *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
