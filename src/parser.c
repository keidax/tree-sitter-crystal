#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 51
#define LARGE_STATE_COUNT 8
#define SYMBOL_COUNT 32
#define ALIAS_COUNT 0
#define TOKEN_COUNT 20
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
  anon_sym_COLON_COLON = 16,
  aux_sym_constant_token1 = 17,
  aux_sym_constant_token2 = 18,
  aux_sym_constant_token3 = 19,
  sym_source_file = 20,
  sym__terminator = 21,
  sym__statements = 22,
  sym__parenthesized_statements = 23,
  sym__statement = 24,
  sym__expression = 25,
  sym_char = 26,
  sym_module = 27,
  sym_scope = 28,
  sym_constant = 29,
  aux_sym__statements_repeat1 = 30,
  aux_sym_constant_repeat1 = 31,
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
  [anon_sym_COLON_COLON] = "::",
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
  [sym_scope] = "scope",
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
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
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
  [sym_scope] = sym_scope,
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
  [anon_sym_COLON_COLON] = {
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
  [sym_scope] = {
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
      if (eof) ADVANCE(48);
      if (lookahead == '\'') ADVANCE(70);
      if (lookahead == '(') ADVANCE(51);
      if (lookahead == ')') ADVANCE(52);
      if (lookahead == '0') ADVANCE(59);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == ';') ADVANCE(50);
      if (lookahead == '\\') ADVANCE(38);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(46)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(62);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(75);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(76);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(49);
      if (lookahead == ')') ADVANCE(52);
      if (lookahead == ';') ADVANCE(50);
      if (lookahead == 'e') ADVANCE(24);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '0') ADVANCE(59);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(62);
      END_STATE();
    case 3:
      if (lookahead == '0') ADVANCE(57);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(58);
      END_STATE();
    case 4:
      if (lookahead == '1') ADVANCE(6);
      if (lookahead == '3') ADVANCE(5);
      if (lookahead == '6') ADVANCE(9);
      if (lookahead == '8') ADVANCE(56);
      END_STATE();
    case 5:
      if (lookahead == '2') ADVANCE(56);
      END_STATE();
    case 6:
      if (lookahead == '2') ADVANCE(11);
      if (lookahead == '6') ADVANCE(56);
      END_STATE();
    case 7:
      if (lookahead == '2') ADVANCE(64);
      END_STATE();
    case 8:
      if (lookahead == '3') ADVANCE(7);
      if (lookahead == '6') ADVANCE(10);
      END_STATE();
    case 9:
      if (lookahead == '4') ADVANCE(56);
      END_STATE();
    case 10:
      if (lookahead == '4') ADVANCE(64);
      END_STATE();
    case 11:
      if (lookahead == '8') ADVANCE(56);
      END_STATE();
    case 12:
      if (lookahead == ':') ADVANCE(74);
      END_STATE();
    case 13:
      if (lookahead == '\\') ADVANCE(38);
      if (lookahead != 0) ADVANCE(69);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(21);
      END_STATE();
    case 15:
      if (lookahead == 'd') ADVANCE(73);
      END_STATE();
    case 16:
      if (lookahead == 'd') ADVANCE(29);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(54);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(55);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(72);
      END_STATE();
    case 20:
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 21:
      if (lookahead == 'l') ADVANCE(27);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(53);
      END_STATE();
    case 23:
      if (lookahead == 'l') ADVANCE(19);
      END_STATE();
    case 24:
      if (lookahead == 'n') ADVANCE(15);
      END_STATE();
    case 25:
      if (lookahead == 'o') ADVANCE(16);
      END_STATE();
    case 26:
      if (lookahead == 'r') ADVANCE(28);
      END_STATE();
    case 27:
      if (lookahead == 's') ADVANCE(18);
      END_STATE();
    case 28:
      if (lookahead == 'u') ADVANCE(17);
      END_STATE();
    case 29:
      if (lookahead == 'u') ADVANCE(23);
      END_STATE();
    case 30:
      if (lookahead == '{') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      END_STATE();
    case 31:
      if (lookahead == '}') ADVANCE(71);
      END_STATE();
    case 32:
      if (lookahead == '}') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 33:
      if (lookahead == '}') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 34:
      if (lookahead == '}') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 35:
      if (lookahead == '}') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 36:
      if (lookahead == '}') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
      END_STATE();
    case 37:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(66);
      END_STATE();
    case 38:
      if (sym_char_escape_sequence_character_set_1(lookahead)) ADVANCE(71);
      if (lookahead == 'u') ADVANCE(30);
      END_STATE();
    case 39:
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(67);
      END_STATE();
    case 40:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(71);
      END_STATE();
    case 41:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      END_STATE();
    case 42:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(40);
      END_STATE();
    case 43:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(42);
      END_STATE();
    case 44:
      if (eof) ADVANCE(48);
      if (lookahead == '\n') ADVANCE(49);
      if (lookahead == '\'') ADVANCE(70);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == ';') ADVANCE(50);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(45)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      if (lookahead != 0 &&
          lookahead > '@' &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(76);
      END_STATE();
    case 45:
      if (eof) ADVANCE(48);
      if (lookahead == '\n') ADVANCE(49);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == ';') ADVANCE(50);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(45)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      if (lookahead != 0 &&
          lookahead > '@' &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(76);
      END_STATE();
    case 46:
      if (eof) ADVANCE(48);
      if (lookahead == '\'') ADVANCE(68);
      if (lookahead == '(') ADVANCE(51);
      if (lookahead == ')') ADVANCE(52);
      if (lookahead == '0') ADVANCE(59);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == ';') ADVANCE(50);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(46)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(62);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(75);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(76);
      END_STATE();
    case 47:
      if (eof) ADVANCE(48);
      if (lookahead == '\'') ADVANCE(68);
      if (lookahead == '(') ADVANCE(51);
      if (lookahead == ')') ADVANCE(52);
      if (lookahead == '0') ADVANCE(57);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == ';') ADVANCE(50);
      if (lookahead == 'e') ADVANCE(24);
      if (lookahead == 'f') ADVANCE(14);
      if (lookahead == 'm') ADVANCE(25);
      if (lookahead == 'n') ADVANCE(20);
      if (lookahead == 't') ADVANCE(26);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(47)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(75);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_nil);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_integer);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == '_') ADVANCE(58);
      if (lookahead == 'b') ADVANCE(60);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'o') ADVANCE(61);
      if (lookahead == 'u') ADVANCE(4);
      if (lookahead == 'x') ADVANCE(63);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'u') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '_') ADVANCE(62);
      if (lookahead == 'b') ADVANCE(60);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'o') ADVANCE(61);
      if (lookahead == 'u') ADVANCE(4);
      if (lookahead == 'x') ADVANCE(63);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'u') ADVANCE(4);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'u') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(61);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'u') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == 'u') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(63);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_float);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(67);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(8);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(67);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_char_token1);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_SQUOTE2);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_char_escape_sequence);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_module);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_end);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_constant_token1);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_constant_token2);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_constant_token3);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 47},
  [2] = {.lex_state = 47},
  [3] = {.lex_state = 47},
  [4] = {.lex_state = 47},
  [5] = {.lex_state = 47},
  [6] = {.lex_state = 47},
  [7] = {.lex_state = 47},
  [8] = {.lex_state = 47},
  [9] = {.lex_state = 47},
  [10] = {.lex_state = 47},
  [11] = {.lex_state = 47},
  [12] = {.lex_state = 44},
  [13] = {.lex_state = 44},
  [14] = {.lex_state = 44},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 44},
  [18] = {.lex_state = 44},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 47},
  [22] = {.lex_state = 44},
  [23] = {.lex_state = 44},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 44},
  [27] = {.lex_state = 44},
  [28] = {.lex_state = 47},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 44},
  [31] = {.lex_state = 44},
  [32] = {.lex_state = 44},
  [33] = {.lex_state = 44},
  [34] = {.lex_state = 44},
  [35] = {.lex_state = 44},
  [36] = {.lex_state = 44},
  [37] = {.lex_state = 44},
  [38] = {.lex_state = 44},
  [39] = {.lex_state = 13},
  [40] = {.lex_state = 47},
  [41] = {.lex_state = 47},
  [42] = {.lex_state = 13},
  [43] = {.lex_state = 47},
  [44] = {.lex_state = 44},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 44},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 47},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
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
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [aux_sym_constant_token1] = ACTIONS(1),
    [aux_sym_constant_token2] = ACTIONS(1),
    [aux_sym_constant_token3] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(50),
    [sym__statements] = STATE(49),
    [sym__parenthesized_statements] = STATE(17),
    [sym__statement] = STATE(17),
    [sym__expression] = STATE(17),
    [sym_char] = STATE(17),
    [sym_module] = STATE(17),
    [aux_sym__statements_repeat1] = STATE(9),
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
    [sym__statements] = STATE(47),
    [sym__parenthesized_statements] = STATE(15),
    [sym__statement] = STATE(15),
    [sym__expression] = STATE(15),
    [sym_char] = STATE(15),
    [sym_module] = STATE(15),
    [aux_sym__statements_repeat1] = STATE(3),
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
    [sym__parenthesized_statements] = STATE(16),
    [sym__statement] = STATE(16),
    [sym__expression] = STATE(16),
    [sym_char] = STATE(16),
    [sym_module] = STATE(16),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(31),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_RPAREN] = ACTIONS(33),
    [sym_nil] = ACTIONS(35),
    [sym_true] = ACTIONS(35),
    [sym_false] = ACTIONS(35),
    [sym_integer] = ACTIONS(37),
    [sym_float] = ACTIONS(35),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [anon_sym_module] = ACTIONS(29),
    [anon_sym_end] = ACTIONS(33),
  },
  [4] = {
    [sym__statements] = STATE(48),
    [sym__parenthesized_statements] = STATE(15),
    [sym__statement] = STATE(15),
    [sym__expression] = STATE(15),
    [sym_char] = STATE(15),
    [sym_module] = STATE(15),
    [aux_sym__statements_repeat1] = STATE(3),
    [anon_sym_SEMI] = ACTIONS(17),
    [anon_sym_LPAREN] = ACTIONS(19),
    [sym_nil] = ACTIONS(23),
    [sym_true] = ACTIONS(23),
    [sym_false] = ACTIONS(23),
    [sym_integer] = ACTIONS(25),
    [sym_float] = ACTIONS(23),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [anon_sym_module] = ACTIONS(29),
    [anon_sym_end] = ACTIONS(39),
  },
  [5] = {
    [sym__statements] = STATE(45),
    [sym__parenthesized_statements] = STATE(15),
    [sym__statement] = STATE(15),
    [sym__expression] = STATE(15),
    [sym_char] = STATE(15),
    [sym_module] = STATE(15),
    [aux_sym__statements_repeat1] = STATE(3),
    [anon_sym_SEMI] = ACTIONS(17),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_RPAREN] = ACTIONS(41),
    [sym_nil] = ACTIONS(23),
    [sym_true] = ACTIONS(23),
    [sym_false] = ACTIONS(23),
    [sym_integer] = ACTIONS(25),
    [sym_float] = ACTIONS(23),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [anon_sym_module] = ACTIONS(29),
  },
  [6] = {
    [sym__statements] = STATE(43),
    [sym__parenthesized_statements] = STATE(15),
    [sym__statement] = STATE(15),
    [sym__expression] = STATE(15),
    [sym_char] = STATE(15),
    [sym_module] = STATE(15),
    [aux_sym__statements_repeat1] = STATE(3),
    [anon_sym_SEMI] = ACTIONS(17),
    [anon_sym_LPAREN] = ACTIONS(19),
    [sym_nil] = ACTIONS(23),
    [sym_true] = ACTIONS(23),
    [sym_false] = ACTIONS(23),
    [sym_integer] = ACTIONS(25),
    [sym_float] = ACTIONS(23),
    [anon_sym_SQUOTE] = ACTIONS(27),
    [anon_sym_module] = ACTIONS(29),
    [anon_sym_end] = ACTIONS(43),
  },
  [7] = {
    [sym__parenthesized_statements] = STATE(36),
    [sym__statement] = STATE(36),
    [sym__expression] = STATE(36),
    [sym_char] = STATE(36),
    [sym_module] = STATE(36),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(45),
    [anon_sym_LPAREN] = ACTIONS(48),
    [anon_sym_RPAREN] = ACTIONS(51),
    [sym_nil] = ACTIONS(53),
    [sym_true] = ACTIONS(53),
    [sym_false] = ACTIONS(53),
    [sym_integer] = ACTIONS(56),
    [sym_float] = ACTIONS(53),
    [anon_sym_SQUOTE] = ACTIONS(59),
    [anon_sym_module] = ACTIONS(62),
    [anon_sym_end] = ACTIONS(51),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(48), 1,
      anon_sym_LPAREN,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
    ACTIONS(59), 1,
      anon_sym_SQUOTE,
    ACTIONS(62), 1,
      anon_sym_module,
    ACTIONS(65), 1,
      anon_sym_SEMI,
    ACTIONS(71), 1,
      sym_integer,
    STATE(8), 1,
      aux_sym__statements_repeat1,
    ACTIONS(68), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
    STATE(30), 5,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
  [35] = 9,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(13), 1,
      anon_sym_SQUOTE,
    ACTIONS(15), 1,
      anon_sym_module,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(74), 1,
      anon_sym_SEMI,
    ACTIONS(78), 1,
      sym_integer,
    STATE(8), 1,
      aux_sym__statements_repeat1,
    ACTIONS(76), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
    STATE(18), 5,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
  [70] = 2,
    ACTIONS(80), 1,
      sym_integer,
    ACTIONS(51), 10,
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
  [86] = 2,
    ACTIONS(80), 1,
      sym_integer,
    ACTIONS(51), 9,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      anon_sym_SQUOTE,
      anon_sym_module,
  [101] = 4,
    ACTIONS(82), 1,
      anon_sym_LF,
    STATE(12), 1,
      aux_sym_constant_repeat1,
    ACTIONS(84), 2,
      anon_sym_SEMI,
      anon_sym_COLON_COLON,
    ACTIONS(86), 2,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
  [116] = 4,
    ACTIONS(89), 1,
      anon_sym_LF,
    STATE(14), 1,
      aux_sym_constant_repeat1,
    ACTIONS(91), 2,
      anon_sym_SEMI,
      anon_sym_COLON_COLON,
    ACTIONS(93), 2,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
  [131] = 4,
    ACTIONS(95), 1,
      anon_sym_LF,
    STATE(12), 1,
      aux_sym_constant_repeat1,
    ACTIONS(97), 2,
      anon_sym_SEMI,
      anon_sym_COLON_COLON,
    ACTIONS(99), 2,
      aux_sym_constant_token2,
      aux_sym_constant_token3,
  [146] = 4,
    ACTIONS(101), 1,
      anon_sym_LF,
    ACTIONS(103), 1,
      anon_sym_SEMI,
    STATE(10), 1,
      sym__terminator,
    ACTIONS(105), 2,
      anon_sym_RPAREN,
      anon_sym_end,
  [160] = 4,
    ACTIONS(101), 1,
      anon_sym_LF,
    ACTIONS(103), 1,
      anon_sym_SEMI,
    STATE(10), 1,
      sym__terminator,
    ACTIONS(107), 2,
      anon_sym_RPAREN,
      anon_sym_end,
  [174] = 4,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(109), 1,
      anon_sym_LF,
    ACTIONS(111), 1,
      anon_sym_SEMI,
    STATE(11), 1,
      sym__terminator,
  [187] = 4,
    ACTIONS(109), 1,
      anon_sym_LF,
    ACTIONS(111), 1,
      anon_sym_SEMI,
    ACTIONS(113), 1,
      ts_builtin_sym_end,
    STATE(11), 1,
      sym__terminator,
  [200] = 2,
    ACTIONS(115), 1,
      anon_sym_LF,
    ACTIONS(117), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
  [209] = 2,
    ACTIONS(119), 1,
      anon_sym_LF,
    ACTIONS(121), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
  [218] = 4,
    ACTIONS(123), 1,
      anon_sym_COLON_COLON,
    ACTIONS(125), 1,
      aux_sym_constant_token1,
    STATE(26), 1,
      sym_scope,
    STATE(27), 1,
      sym_constant,
  [231] = 4,
    ACTIONS(127), 1,
      anon_sym_LF,
    ACTIONS(129), 1,
      anon_sym_SEMI,
    ACTIONS(131), 1,
      anon_sym_COLON_COLON,
    STATE(6), 1,
      sym__terminator,
  [244] = 4,
    ACTIONS(127), 1,
      anon_sym_LF,
    ACTIONS(129), 1,
      anon_sym_SEMI,
    ACTIONS(133), 1,
      anon_sym_COLON_COLON,
    STATE(6), 1,
      sym__terminator,
  [257] = 2,
    ACTIONS(135), 1,
      anon_sym_LF,
    ACTIONS(137), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
  [266] = 2,
    ACTIONS(139), 1,
      anon_sym_LF,
    ACTIONS(141), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
  [275] = 4,
    ACTIONS(133), 1,
      anon_sym_COLON_COLON,
    ACTIONS(143), 1,
      anon_sym_LF,
    ACTIONS(145), 1,
      anon_sym_SEMI,
    STATE(4), 1,
      sym__terminator,
  [288] = 4,
    ACTIONS(131), 1,
      anon_sym_COLON_COLON,
    ACTIONS(143), 1,
      anon_sym_LF,
    ACTIONS(145), 1,
      anon_sym_SEMI,
    STATE(4), 1,
      sym__terminator,
  [301] = 4,
    ACTIONS(123), 1,
      anon_sym_COLON_COLON,
    ACTIONS(125), 1,
      aux_sym_constant_token1,
    STATE(22), 1,
      sym_constant,
    STATE(23), 1,
      sym_scope,
  [314] = 2,
    ACTIONS(147), 1,
      anon_sym_LF,
    ACTIONS(149), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
  [323] = 3,
    ACTIONS(109), 1,
      anon_sym_LF,
    ACTIONS(111), 1,
      anon_sym_SEMI,
    STATE(11), 1,
      sym__terminator,
  [333] = 2,
    ACTIONS(151), 1,
      anon_sym_LF,
    ACTIONS(153), 2,
      anon_sym_SEMI,
      anon_sym_COLON_COLON,
  [341] = 2,
    ACTIONS(137), 1,
      anon_sym_SEMI,
    ACTIONS(135), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [349] = 2,
    ACTIONS(141), 1,
      anon_sym_SEMI,
    ACTIONS(139), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [357] = 2,
    ACTIONS(155), 1,
      anon_sym_LF,
    ACTIONS(157), 2,
      anon_sym_SEMI,
      anon_sym_COLON_COLON,
  [365] = 2,
    ACTIONS(117), 1,
      anon_sym_SEMI,
    ACTIONS(115), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [373] = 3,
    ACTIONS(101), 1,
      anon_sym_LF,
    ACTIONS(103), 1,
      anon_sym_SEMI,
    STATE(10), 1,
      sym__terminator,
  [383] = 2,
    ACTIONS(121), 1,
      anon_sym_SEMI,
    ACTIONS(119), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [391] = 2,
    ACTIONS(149), 1,
      anon_sym_SEMI,
    ACTIONS(147), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [399] = 1,
    ACTIONS(159), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [404] = 2,
    ACTIONS(125), 1,
      aux_sym_constant_token1,
    STATE(31), 1,
      sym_constant,
  [411] = 2,
    ACTIONS(125), 1,
      aux_sym_constant_token1,
    STATE(34), 1,
      sym_constant,
  [418] = 1,
    ACTIONS(161), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [423] = 1,
    ACTIONS(163), 1,
      anon_sym_end,
  [427] = 1,
    ACTIONS(165), 1,
      anon_sym_SQUOTE2,
  [431] = 1,
    ACTIONS(167), 1,
      anon_sym_RPAREN,
  [435] = 1,
    ACTIONS(169), 1,
      anon_sym_SQUOTE2,
  [439] = 1,
    ACTIONS(171), 1,
      anon_sym_RPAREN,
  [443] = 1,
    ACTIONS(173), 1,
      anon_sym_end,
  [447] = 1,
    ACTIONS(175), 1,
      ts_builtin_sym_end,
  [451] = 1,
    ACTIONS(177), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(8)] = 0,
  [SMALL_STATE(9)] = 35,
  [SMALL_STATE(10)] = 70,
  [SMALL_STATE(11)] = 86,
  [SMALL_STATE(12)] = 101,
  [SMALL_STATE(13)] = 116,
  [SMALL_STATE(14)] = 131,
  [SMALL_STATE(15)] = 146,
  [SMALL_STATE(16)] = 160,
  [SMALL_STATE(17)] = 174,
  [SMALL_STATE(18)] = 187,
  [SMALL_STATE(19)] = 200,
  [SMALL_STATE(20)] = 209,
  [SMALL_STATE(21)] = 218,
  [SMALL_STATE(22)] = 231,
  [SMALL_STATE(23)] = 244,
  [SMALL_STATE(24)] = 257,
  [SMALL_STATE(25)] = 266,
  [SMALL_STATE(26)] = 275,
  [SMALL_STATE(27)] = 288,
  [SMALL_STATE(28)] = 301,
  [SMALL_STATE(29)] = 314,
  [SMALL_STATE(30)] = 323,
  [SMALL_STATE(31)] = 333,
  [SMALL_STATE(32)] = 341,
  [SMALL_STATE(33)] = 349,
  [SMALL_STATE(34)] = 357,
  [SMALL_STATE(35)] = 365,
  [SMALL_STATE(36)] = 373,
  [SMALL_STATE(37)] = 383,
  [SMALL_STATE(38)] = 391,
  [SMALL_STATE(39)] = 399,
  [SMALL_STATE(40)] = 404,
  [SMALL_STATE(41)] = 411,
  [SMALL_STATE(42)] = 418,
  [SMALL_STATE(43)] = 423,
  [SMALL_STATE(44)] = 427,
  [SMALL_STATE(45)] = 431,
  [SMALL_STATE(46)] = 435,
  [SMALL_STATE(47)] = 439,
  [SMALL_STATE(48)] = 443,
  [SMALL_STATE(49)] = 447,
  [SMALL_STATE(50)] = 451,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 1),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(7),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(5),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(36),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(36),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(42),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(21),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(8),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(30),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(30),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [80] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_repeat1, 2),
  [84] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_constant_repeat1, 2),
  [86] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_constant_repeat1, 2), SHIFT_REPEAT(12),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant, 1),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant, 1),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant, 2),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant, 2),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 2),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char, 3),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char, 3),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 3),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__parenthesized_statements, 3),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [129] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scope, 1),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 4, .production_id = 1),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_module, 4, .production_id = 1),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 5, .production_id = 2),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_module, 5, .production_id = 2),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [145] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 2),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__parenthesized_statements, 2),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scope, 3),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scope, 3),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scope, 2),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scope, 2),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [177] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
