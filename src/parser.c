#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 45
#define LARGE_STATE_COUNT 10
#define SYMBOL_COUNT 30
#define ALIAS_COUNT 0
#define TOKEN_COUNT 19
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 3

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
  anon_sym_module = 14,
  anon_sym_end = 15,
  aux_sym_constant_token1 = 16,
  aux_sym_constant_token2 = 17,
  aux_sym_constant_token3 = 18,
  sym_source_file = 19,
  sym__terminator = 20,
  sym__statements = 21,
  sym__parenthesized_statements = 22,
  sym__statement = 23,
  sym__expression = 24,
  sym_char = 25,
  sym_module = 26,
  sym_constant = 27,
  aux_sym__statements_repeat1 = 28,
  aux_sym_constant_repeat1 = 29,
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
  [anon_sym_module] = "module",
  [anon_sym_end] = "end",
  [aux_sym_constant_token1] = "constant_token1",
  [aux_sym_constant_token2] = "constant_token2",
  [aux_sym_constant_token3] = "constant_token3",
  [sym_source_file] = "source_file",
  [sym__terminator] = "_terminator",
  [sym__statements] = "_statements",
  [sym__parenthesized_statements] = "_parenthesized_statements",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym_char] = "char",
  [sym_module] = "module",
  [sym_constant] = "constant",
  [aux_sym__statements_repeat1] = "_statements_repeat1",
  [aux_sym_constant_repeat1] = "constant_repeat1",
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
  [anon_sym_module] = anon_sym_module,
  [anon_sym_end] = anon_sym_end,
  [aux_sym_constant_token1] = aux_sym_constant_token1,
  [aux_sym_constant_token2] = aux_sym_constant_token2,
  [aux_sym_constant_token3] = aux_sym_constant_token3,
  [sym_source_file] = sym_source_file,
  [sym__terminator] = sym__terminator,
  [sym__statements] = sym__statements,
  [sym__parenthesized_statements] = sym__parenthesized_statements,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym_char] = sym_char,
  [sym_module] = sym_module,
  [sym_constant] = sym_constant,
  [aux_sym__statements_repeat1] = aux_sym__statements_repeat1,
  [aux_sym_constant_repeat1] = aux_sym_constant_repeat1,
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
  [anon_sym_module] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_end] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_constant_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_constant_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_constant_token3] = {
    .visible = false,
    .named = false,
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
  [sym_module] = {
    .visible = true,
    .named = true,
  },
  [sym_constant] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__statements_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_constant_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_body = 1,
  field_name = 2,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_body] = "body",
  [field_name] = "name",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_body, 3},
    {field_name, 1},
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
      if (eof) ADVANCE(47);
      if (lookahead == '\'') ADVANCE(69);
      if (lookahead == '(') ADVANCE(50);
      if (lookahead == ')') ADVANCE(51);
      if (lookahead == '0') ADVANCE(58);
      if (lookahead == ';') ADVANCE(49);
      if (lookahead == '\\') ADVANCE(37);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(45)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(61);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(73);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(74);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(48);
      if (lookahead == ')') ADVANCE(51);
      if (lookahead == ';') ADVANCE(49);
      if (lookahead == 'e') ADVANCE(23);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '0') ADVANCE(58);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(61);
      END_STATE();
    case 3:
      if (lookahead == '0') ADVANCE(56);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(57);
      END_STATE();
    case 4:
      if (lookahead == '1') ADVANCE(6);
      if (lookahead == '3') ADVANCE(5);
      if (lookahead == '6') ADVANCE(9);
      if (lookahead == '8') ADVANCE(55);
      END_STATE();
    case 5:
      if (lookahead == '2') ADVANCE(55);
      END_STATE();
    case 6:
      if (lookahead == '2') ADVANCE(11);
      if (lookahead == '6') ADVANCE(55);
      END_STATE();
    case 7:
      if (lookahead == '2') ADVANCE(63);
      END_STATE();
    case 8:
      if (lookahead == '3') ADVANCE(7);
      if (lookahead == '6') ADVANCE(10);
      END_STATE();
    case 9:
      if (lookahead == '4') ADVANCE(55);
      END_STATE();
    case 10:
      if (lookahead == '4') ADVANCE(63);
      END_STATE();
    case 11:
      if (lookahead == '8') ADVANCE(55);
      END_STATE();
    case 12:
      if (lookahead == '\\') ADVANCE(37);
      if (lookahead != 0) ADVANCE(68);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(20);
      END_STATE();
    case 14:
      if (lookahead == 'd') ADVANCE(72);
      END_STATE();
    case 15:
      if (lookahead == 'd') ADVANCE(28);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(53);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(54);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(71);
      END_STATE();
    case 19:
      if (lookahead == 'i') ADVANCE(21);
      END_STATE();
    case 20:
      if (lookahead == 'l') ADVANCE(26);
      END_STATE();
    case 21:
      if (lookahead == 'l') ADVANCE(52);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(18);
      END_STATE();
    case 23:
      if (lookahead == 'n') ADVANCE(14);
      END_STATE();
    case 24:
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 25:
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 26:
      if (lookahead == 's') ADVANCE(17);
      END_STATE();
    case 27:
      if (lookahead == 'u') ADVANCE(16);
      END_STATE();
    case 28:
      if (lookahead == 'u') ADVANCE(22);
      END_STATE();
    case 29:
      if (lookahead == '{') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(42);
      END_STATE();
    case 30:
      if (lookahead == '}') ADVANCE(70);
      END_STATE();
    case 31:
      if (lookahead == '}') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 32:
      if (lookahead == '}') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 33:
      if (lookahead == '}') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 34:
      if (lookahead == '}') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 35:
      if (lookahead == '}') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 36:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(65);
      END_STATE();
    case 37:
      if (sym_char_escape_sequence_character_set_1(lookahead)) ADVANCE(70);
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 38:
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(66);
      END_STATE();
    case 39:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(70);
      END_STATE();
    case 40:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
      END_STATE();
    case 41:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 42:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(41);
      END_STATE();
    case 43:
      if (eof) ADVANCE(47);
      if (lookahead == '\n') ADVANCE(48);
      if (lookahead == '\'') ADVANCE(69);
      if (lookahead == ';') ADVANCE(49);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(44)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (lookahead != 0 &&
          lookahead > '@' &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(74);
      END_STATE();
    case 44:
      if (eof) ADVANCE(47);
      if (lookahead == '\n') ADVANCE(48);
      if (lookahead == ';') ADVANCE(49);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(44)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (lookahead != 0 &&
          lookahead > '@' &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(74);
      END_STATE();
    case 45:
      if (eof) ADVANCE(47);
      if (lookahead == '\'') ADVANCE(67);
      if (lookahead == '(') ADVANCE(50);
      if (lookahead == ')') ADVANCE(51);
      if (lookahead == '0') ADVANCE(58);
      if (lookahead == ';') ADVANCE(49);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(45)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(61);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(73);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(74);
      END_STATE();
    case 46:
      if (eof) ADVANCE(47);
      if (lookahead == '\'') ADVANCE(67);
      if (lookahead == '(') ADVANCE(50);
      if (lookahead == ')') ADVANCE(51);
      if (lookahead == '0') ADVANCE(56);
      if (lookahead == ';') ADVANCE(49);
      if (lookahead == 'e') ADVANCE(23);
      if (lookahead == 'f') ADVANCE(13);
      if (lookahead == 'm') ADVANCE(24);
      if (lookahead == 'n') ADVANCE(19);
      if (lookahead == 't') ADVANCE(25);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(46)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(57);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(73);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(48);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_nil);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_integer);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(36);
      if (lookahead == '_') ADVANCE(57);
      if (lookahead == 'b') ADVANCE(59);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'o') ADVANCE(60);
      if (lookahead == 'u') ADVANCE(4);
      if (lookahead == 'x') ADVANCE(62);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(36);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'u') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(57);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '_') ADVANCE(61);
      if (lookahead == 'b') ADVANCE(59);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'o') ADVANCE(60);
      if (lookahead == 'u') ADVANCE(4);
      if (lookahead == 'x') ADVANCE(62);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'u') ADVANCE(4);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(59);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'u') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'u') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(61);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'u') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_float);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(66);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(65);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_char_token1);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_SQUOTE2);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_char_escape_sequence);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_module);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_end);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_constant_token1);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_constant_token2);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_constant_token3);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 46},
  [2] = {.lex_state = 46},
  [3] = {.lex_state = 46},
  [4] = {.lex_state = 46},
  [5] = {.lex_state = 46},
  [6] = {.lex_state = 46},
  [7] = {.lex_state = 46},
  [8] = {.lex_state = 46},
  [9] = {.lex_state = 46},
  [10] = {.lex_state = 46},
  [11] = {.lex_state = 46},
  [12] = {.lex_state = 43},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 43},
  [16] = {.lex_state = 43},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 43},
  [23] = {.lex_state = 43},
  [24] = {.lex_state = 43},
  [25] = {.lex_state = 43},
  [26] = {.lex_state = 43},
  [27] = {.lex_state = 43},
  [28] = {.lex_state = 43},
  [29] = {.lex_state = 43},
  [30] = {.lex_state = 43},
  [31] = {.lex_state = 43},
  [32] = {.lex_state = 43},
  [33] = {.lex_state = 12},
  [34] = {.lex_state = 46},
  [35] = {.lex_state = 12},
  [36] = {.lex_state = 46},
  [37] = {.lex_state = 43},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 46},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 43},
  [44] = {.lex_state = 46},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE2] = ACTIONS(1),
    [sym_char_escape_sequence] = ACTIONS(1),
    [aux_sym_constant_token1] = ACTIONS(1),
    [aux_sym_constant_token2] = ACTIONS(1),
    [aux_sym_constant_token3] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(41),
    [sym__statements] = STATE(40),
    [sym__parenthesized_statements] = STATE(22),
    [sym__statement] = STATE(22),
    [sym__expression] = STATE(22),
    [sym_char] = STATE(22),
    [sym_module] = STATE(22),
    [aux_sym__statements_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(9),
    [sym_true] = ACTIONS(9),
    [sym_false] = ACTIONS(9),
    [sym_integer] = ACTIONS(11),
    [sym_float] = ACTIONS(9),
    [anon_sym_SQUOTE] = ACTIONS(13),
    [anon_sym_module] = ACTIONS(15),
  },
  [2] = {
    [sym__statements] = STATE(38),
    [sym__parenthesized_statements] = STATE(14),
    [sym__statement] = STATE(14),
    [sym__expression] = STATE(14),
    [sym_char] = STATE(14),
    [sym_module] = STATE(14),
    [aux_sym__statements_repeat1] = STATE(6),
    [anon_sym_SEMI] = ACTIONS(17),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_RPAREN] = ACTIONS(21),
    [sym_nil] = ACTIONS(23),
    [sym_true] = ACTIONS(23),
    [sym_false] = ACTIONS(23),
    [sym_integer] = ACTIONS(25),
    [sym_float] = ACTIONS(23),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [anon_sym_module] = ACTIONS(29),
  },
  [3] = {
    [sym__statements] = STATE(44),
    [sym__parenthesized_statements] = STATE(14),
    [sym__statement] = STATE(14),
    [sym__expression] = STATE(14),
    [sym_char] = STATE(14),
    [sym_module] = STATE(14),
    [aux_sym__statements_repeat1] = STATE(6),
    [anon_sym_SEMI] = ACTIONS(17),
    [anon_sym_LPAREN] = ACTIONS(19),
    [sym_nil] = ACTIONS(23),
    [sym_true] = ACTIONS(23),
    [sym_false] = ACTIONS(23),
    [sym_integer] = ACTIONS(25),
    [sym_float] = ACTIONS(23),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [anon_sym_module] = ACTIONS(29),
    [anon_sym_end] = ACTIONS(31),
  },
  [4] = {
    [sym__statements] = STATE(42),
    [sym__parenthesized_statements] = STATE(14),
    [sym__statement] = STATE(14),
    [sym__expression] = STATE(14),
    [sym_char] = STATE(14),
    [sym_module] = STATE(14),
    [aux_sym__statements_repeat1] = STATE(6),
    [anon_sym_SEMI] = ACTIONS(17),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_RPAREN] = ACTIONS(33),
    [sym_nil] = ACTIONS(23),
    [sym_true] = ACTIONS(23),
    [sym_false] = ACTIONS(23),
    [sym_integer] = ACTIONS(25),
    [sym_float] = ACTIONS(23),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [anon_sym_module] = ACTIONS(29),
  },
  [5] = {
    [sym__parenthesized_statements] = STATE(29),
    [sym__statement] = STATE(29),
    [sym__expression] = STATE(29),
    [sym_char] = STATE(29),
    [sym_module] = STATE(29),
    [aux_sym__statements_repeat1] = STATE(5),
    [anon_sym_SEMI] = ACTIONS(35),
    [anon_sym_LPAREN] = ACTIONS(38),
    [anon_sym_RPAREN] = ACTIONS(41),
    [sym_nil] = ACTIONS(43),
    [sym_true] = ACTIONS(43),
    [sym_false] = ACTIONS(43),
    [sym_integer] = ACTIONS(46),
    [sym_float] = ACTIONS(43),
    [anon_sym_SQUOTE] = ACTIONS(49),
    [anon_sym_module] = ACTIONS(52),
    [anon_sym_end] = ACTIONS(41),
  },
  [6] = {
    [sym__parenthesized_statements] = STATE(13),
    [sym__statement] = STATE(13),
    [sym__expression] = STATE(13),
    [sym_char] = STATE(13),
    [sym_module] = STATE(13),
    [aux_sym__statements_repeat1] = STATE(5),
    [anon_sym_SEMI] = ACTIONS(55),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_RPAREN] = ACTIONS(57),
    [sym_nil] = ACTIONS(59),
    [sym_true] = ACTIONS(59),
    [sym_false] = ACTIONS(59),
    [sym_integer] = ACTIONS(61),
    [sym_float] = ACTIONS(59),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [anon_sym_module] = ACTIONS(29),
    [anon_sym_end] = ACTIONS(57),
  },
  [7] = {
    [sym__statements] = STATE(39),
    [sym__parenthesized_statements] = STATE(14),
    [sym__statement] = STATE(14),
    [sym__expression] = STATE(14),
    [sym_char] = STATE(14),
    [sym_module] = STATE(14),
    [aux_sym__statements_repeat1] = STATE(6),
    [anon_sym_SEMI] = ACTIONS(17),
    [anon_sym_LPAREN] = ACTIONS(19),
    [sym_nil] = ACTIONS(23),
    [sym_true] = ACTIONS(23),
    [sym_false] = ACTIONS(23),
    [sym_integer] = ACTIONS(25),
    [sym_float] = ACTIONS(23),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [anon_sym_module] = ACTIONS(29),
    [anon_sym_end] = ACTIONS(63),
  },
  [8] = {
    [sym__parenthesized_statements] = STATE(23),
    [sym__statement] = STATE(23),
    [sym__expression] = STATE(23),
    [sym_char] = STATE(23),
    [sym_module] = STATE(23),
    [aux_sym__statements_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(57),
    [anon_sym_SEMI] = ACTIONS(65),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(67),
    [sym_true] = ACTIONS(67),
    [sym_false] = ACTIONS(67),
    [sym_integer] = ACTIONS(69),
    [sym_float] = ACTIONS(67),
    [anon_sym_SQUOTE] = ACTIONS(13),
    [anon_sym_module] = ACTIONS(15),
  },
  [9] = {
    [sym__parenthesized_statements] = STATE(30),
    [sym__statement] = STATE(30),
    [sym__expression] = STATE(30),
    [sym_char] = STATE(30),
    [sym_module] = STATE(30),
    [aux_sym__statements_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(41),
    [anon_sym_SEMI] = ACTIONS(71),
    [anon_sym_LPAREN] = ACTIONS(38),
    [sym_nil] = ACTIONS(74),
    [sym_true] = ACTIONS(74),
    [sym_false] = ACTIONS(74),
    [sym_integer] = ACTIONS(77),
    [sym_float] = ACTIONS(74),
    [anon_sym_SQUOTE] = ACTIONS(49),
    [anon_sym_module] = ACTIONS(52),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(80), 1,
      sym_integer,
    ACTIONS(41), 10,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      anon_sym_SQUOTE,
      anon_sym_module,
      anon_sym_end,
  [16] = 2,
    ACTIONS(80), 1,
      sym_integer,
    ACTIONS(41), 9,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      anon_sym_SQUOTE,
      anon_sym_module,
  [31] = 4,
    ACTIONS(82), 1,
      anon_sym_LF,
    ACTIONS(84), 1,
      anon_sym_SEMI,
    STATE(16), 1,
      aux_sym_constant_repeat1,
    ACTIONS(86), 2,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
  [45] = 4,
    ACTIONS(88), 1,
      anon_sym_LF,
    ACTIONS(90), 1,
      anon_sym_SEMI,
    STATE(10), 1,
      sym__terminator,
    ACTIONS(92), 2,
      anon_sym_RPAREN,
      anon_sym_end,
  [59] = 4,
    ACTIONS(88), 1,
      anon_sym_LF,
    ACTIONS(90), 1,
      anon_sym_SEMI,
    STATE(10), 1,
      sym__terminator,
    ACTIONS(94), 2,
      anon_sym_RPAREN,
      anon_sym_end,
  [73] = 4,
    ACTIONS(96), 1,
      anon_sym_LF,
    ACTIONS(98), 1,
      anon_sym_SEMI,
    STATE(12), 1,
      aux_sym_constant_repeat1,
    ACTIONS(100), 2,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
  [87] = 4,
    ACTIONS(102), 1,
      anon_sym_LF,
    ACTIONS(104), 1,
      anon_sym_SEMI,
    STATE(16), 1,
      aux_sym_constant_repeat1,
    ACTIONS(106), 2,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
  [101] = 2,
    ACTIONS(109), 1,
      anon_sym_LF,
    ACTIONS(111), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
  [110] = 2,
    ACTIONS(113), 1,
      anon_sym_LF,
    ACTIONS(115), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
  [119] = 2,
    ACTIONS(117), 1,
      anon_sym_LF,
    ACTIONS(119), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
  [128] = 2,
    ACTIONS(121), 1,
      anon_sym_LF,
    ACTIONS(123), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
  [137] = 2,
    ACTIONS(125), 1,
      anon_sym_LF,
    ACTIONS(127), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
  [146] = 4,
    ACTIONS(57), 1,
      ts_builtin_sym_end,
    ACTIONS(129), 1,
      anon_sym_LF,
    ACTIONS(131), 1,
      anon_sym_SEMI,
    STATE(11), 1,
      sym__terminator,
  [159] = 4,
    ACTIONS(129), 1,
      anon_sym_LF,
    ACTIONS(131), 1,
      anon_sym_SEMI,
    ACTIONS(133), 1,
      ts_builtin_sym_end,
    STATE(11), 1,
      sym__terminator,
  [172] = 2,
    ACTIONS(115), 1,
      anon_sym_SEMI,
    ACTIONS(113), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [180] = 2,
    ACTIONS(119), 1,
      anon_sym_SEMI,
    ACTIONS(117), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [188] = 3,
    ACTIONS(135), 1,
      anon_sym_LF,
    ACTIONS(137), 1,
      anon_sym_SEMI,
    STATE(7), 1,
      sym__terminator,
  [198] = 2,
    ACTIONS(127), 1,
      anon_sym_SEMI,
    ACTIONS(125), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [206] = 2,
    ACTIONS(123), 1,
      anon_sym_SEMI,
    ACTIONS(121), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [214] = 3,
    ACTIONS(88), 1,
      anon_sym_LF,
    ACTIONS(90), 1,
      anon_sym_SEMI,
    STATE(10), 1,
      sym__terminator,
  [224] = 3,
    ACTIONS(129), 1,
      anon_sym_LF,
    ACTIONS(131), 1,
      anon_sym_SEMI,
    STATE(11), 1,
      sym__terminator,
  [234] = 2,
    ACTIONS(111), 1,
      anon_sym_SEMI,
    ACTIONS(109), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [242] = 3,
    ACTIONS(139), 1,
      anon_sym_LF,
    ACTIONS(141), 1,
      anon_sym_SEMI,
    STATE(3), 1,
      sym__terminator,
  [252] = 1,
    ACTIONS(143), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [257] = 2,
    ACTIONS(145), 1,
      aux_sym_constant_token1,
    STATE(26), 1,
      sym_constant,
  [264] = 1,
    ACTIONS(147), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [269] = 2,
    ACTIONS(145), 1,
      aux_sym_constant_token1,
    STATE(32), 1,
      sym_constant,
  [276] = 1,
    ACTIONS(149), 1,
      anon_sym_SQUOTE2,
  [280] = 1,
    ACTIONS(151), 1,
      anon_sym_RPAREN,
  [284] = 1,
    ACTIONS(153), 1,
      anon_sym_end,
  [288] = 1,
    ACTIONS(155), 1,
      ts_builtin_sym_end,
  [292] = 1,
    ACTIONS(157), 1,
      ts_builtin_sym_end,
  [296] = 1,
    ACTIONS(159), 1,
      anon_sym_RPAREN,
  [300] = 1,
    ACTIONS(161), 1,
      anon_sym_SQUOTE2,
  [304] = 1,
    ACTIONS(163), 1,
      anon_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(10)] = 0,
  [SMALL_STATE(11)] = 16,
  [SMALL_STATE(12)] = 31,
  [SMALL_STATE(13)] = 45,
  [SMALL_STATE(14)] = 59,
  [SMALL_STATE(15)] = 73,
  [SMALL_STATE(16)] = 87,
  [SMALL_STATE(17)] = 101,
  [SMALL_STATE(18)] = 110,
  [SMALL_STATE(19)] = 119,
  [SMALL_STATE(20)] = 128,
  [SMALL_STATE(21)] = 137,
  [SMALL_STATE(22)] = 146,
  [SMALL_STATE(23)] = 159,
  [SMALL_STATE(24)] = 172,
  [SMALL_STATE(25)] = 180,
  [SMALL_STATE(26)] = 188,
  [SMALL_STATE(27)] = 198,
  [SMALL_STATE(28)] = 206,
  [SMALL_STATE(29)] = 214,
  [SMALL_STATE(30)] = 224,
  [SMALL_STATE(31)] = 234,
  [SMALL_STATE(32)] = 242,
  [SMALL_STATE(33)] = 252,
  [SMALL_STATE(34)] = 257,
  [SMALL_STATE(35)] = 264,
  [SMALL_STATE(36)] = 269,
  [SMALL_STATE(37)] = 276,
  [SMALL_STATE(38)] = 280,
  [SMALL_STATE(39)] = 284,
  [SMALL_STATE(40)] = 288,
  [SMALL_STATE(41)] = 292,
  [SMALL_STATE(42)] = 296,
  [SMALL_STATE(43)] = 300,
  [SMALL_STATE(44)] = 304,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(5),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(4),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(29),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(29),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(35),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(36),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 1),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(9),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(30),
  [77] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(30),
  [80] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant, 2),
  [84] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant, 2),
  [86] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [90] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 2),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant, 1),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant, 1),
  [100] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_repeat1, 2),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_constant_repeat1, 2),
  [106] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_constant_repeat1, 2), SHIFT_REPEAT(16),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char, 3),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char, 3),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 2),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__parenthesized_statements, 2),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 5, .production_id = 2),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_module, 5, .production_id = 2),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 4, .production_id = 1),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_module, 4, .production_id = 1),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 3),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__parenthesized_statements, 3),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [157] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
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
    .field_names = ts_field_names,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
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
