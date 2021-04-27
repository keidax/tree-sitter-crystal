#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 112
#define LARGE_STATE_COUNT 16
#define SYMBOL_COUNT 42
#define ALIAS_COUNT 0
#define TOKEN_COUNT 25
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 16

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
  sym_constant = 16,
  aux_sym_identifier_token1 = 17,
  aux_sym_identifier_token2 = 18,
  anon_sym_PIPE = 19,
  anon_sym_alias = 20,
  anon_sym_EQ = 21,
  anon_sym_begin = 22,
  anon_sym_rescue = 23,
  anon_sym_COLON = 24,
  sym_source_file = 25,
  sym__terminator = 26,
  sym__statements = 27,
  sym__parenthesized_statements = 28,
  sym__statement = 29,
  sym__expression = 30,
  sym_char = 31,
  sym_module = 32,
  sym_identifier = 33,
  sym__type = 34,
  sym_union_type = 35,
  sym_alias = 36,
  sym_begin_block = 37,
  sym_rescue_block = 38,
  aux_sym__statements_repeat1 = 39,
  aux_sym_identifier_repeat1 = 40,
  aux_sym_union_type_repeat1 = 41,
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
  [sym_constant] = "constant",
  [aux_sym_identifier_token1] = "identifier_token1",
  [aux_sym_identifier_token2] = "identifier_token2",
  [anon_sym_PIPE] = "|",
  [anon_sym_alias] = "alias",
  [anon_sym_EQ] = "=",
  [anon_sym_begin] = "begin",
  [anon_sym_rescue] = "rescue",
  [anon_sym_COLON] = ": ",
  [sym_source_file] = "source_file",
  [sym__terminator] = "_terminator",
  [sym__statements] = "_statements",
  [sym__parenthesized_statements] = "_parenthesized_statements",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym_char] = "char",
  [sym_module] = "module",
  [sym_identifier] = "identifier",
  [sym__type] = "_type",
  [sym_union_type] = "union_type",
  [sym_alias] = "alias",
  [sym_begin_block] = "begin_block",
  [sym_rescue_block] = "rescue_block",
  [aux_sym__statements_repeat1] = "_statements_repeat1",
  [aux_sym_identifier_repeat1] = "identifier_repeat1",
  [aux_sym_union_type_repeat1] = "union_type_repeat1",
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
  [sym_constant] = sym_constant,
  [aux_sym_identifier_token1] = aux_sym_identifier_token1,
  [aux_sym_identifier_token2] = aux_sym_identifier_token2,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_alias] = anon_sym_alias,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_begin] = anon_sym_begin,
  [anon_sym_rescue] = anon_sym_rescue,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_source_file] = sym_source_file,
  [sym__terminator] = sym__terminator,
  [sym__statements] = sym__statements,
  [sym__parenthesized_statements] = sym__parenthesized_statements,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym_char] = sym_char,
  [sym_module] = sym_module,
  [sym_identifier] = sym_identifier,
  [sym__type] = sym__type,
  [sym_union_type] = sym_union_type,
  [sym_alias] = sym_alias,
  [sym_begin_block] = sym_begin_block,
  [sym_rescue_block] = sym_rescue_block,
  [aux_sym__statements_repeat1] = aux_sym__statements_repeat1,
  [aux_sym_identifier_repeat1] = aux_sym_identifier_repeat1,
  [aux_sym_union_type_repeat1] = aux_sym_union_type_repeat1,
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
  [sym_constant] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_identifier_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_identifier_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_alias] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_begin] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rescue] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
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
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [sym_union_type] = {
    .visible = true,
    .named = true,
  },
  [sym_alias] = {
    .visible = true,
    .named = true,
  },
  [sym_begin_block] = {
    .visible = true,
    .named = true,
  },
  [sym_rescue_block] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__statements_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_identifier_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_union_type_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_body = 1,
  field_name = 2,
  field_rescue = 3,
  field_type = 4,
  field_variable = 5,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_body] = "body",
  [field_name] = "name",
  [field_rescue] = "rescue",
  [field_type] = "type",
  [field_variable] = "variable",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 2},
  [5] = {.index = 5, .length = 1},
  [6] = {.index = 6, .length = 1},
  [7] = {.index = 7, .length = 1},
  [8] = {.index = 8, .length = 1},
  [9] = {.index = 9, .length = 2},
  [10] = {.index = 11, .length = 2},
  [11] = {.index = 13, .length = 2},
  [12] = {.index = 15, .length = 2},
  [13] = {.index = 17, .length = 2},
  [14] = {.index = 19, .length = 2},
  [15] = {.index = 21, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_body, 1},
  [1] =
    {field_rescue, 1},
  [2] =
    {field_name, 1},
  [3] =
    {field_name, 1},
    {field_type, 3},
  [5] =
    {field_body, 2},
  [6] =
    {field_variable, 1},
  [7] =
    {field_type, 1},
  [8] =
    {field_rescue, 2},
  [9] =
    {field_body, 1},
    {field_rescue, 2},
  [11] =
    {field_body, 3},
    {field_name, 1},
  [13] =
    {field_body, 3},
    {field_variable, 1},
  [15] =
    {field_body, 3},
    {field_type, 1},
  [17] =
    {field_body, 2},
    {field_rescue, 3},
  [19] =
    {field_type, 3},
    {field_variable, 1},
  [21] =
    {field_body, 5},
    {field_type, 3},
    {field_variable, 1},
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
      if (eof) ADVANCE(65);
      if (lookahead == '\'') ADVANCE(87);
      if (lookahead == '(') ADVANCE(68);
      if (lookahead == ')') ADVANCE(69);
      if (lookahead == '0') ADVANCE(76);
      if (lookahead == ':') ADVANCE(5);
      if (lookahead == ';') ADVANCE(67);
      if (lookahead == '=') ADVANCE(96);
      if (lookahead == '\\') ADVANCE(55);
      if (lookahead == '|') ADVANCE(94);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(63)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(79);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(92);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(66);
      if (lookahead == '\'') ADVANCE(87);
      if (lookahead == ':') ADVANCE(16);
      if (lookahead == ';') ADVANCE(67);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(92);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(66);
      if (lookahead == ':') ADVANCE(16);
      if (lookahead == ';') ADVANCE(67);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(92);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(66);
      if (lookahead == ':') ADVANCE(4);
      if (lookahead == ';') ADVANCE(67);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < '<' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(93);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(99);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(99);
      if (lookahead == ':') ADVANCE(61);
      END_STATE();
    case 6:
      if (lookahead == '0') ADVANCE(76);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(79);
      END_STATE();
    case 7:
      if (lookahead == '0') ADVANCE(74);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 8:
      if (lookahead == '1') ADVANCE(10);
      if (lookahead == '3') ADVANCE(9);
      if (lookahead == '6') ADVANCE(13);
      if (lookahead == '8') ADVANCE(73);
      END_STATE();
    case 9:
      if (lookahead == '2') ADVANCE(73);
      END_STATE();
    case 10:
      if (lookahead == '2') ADVANCE(15);
      if (lookahead == '6') ADVANCE(73);
      END_STATE();
    case 11:
      if (lookahead == '2') ADVANCE(81);
      END_STATE();
    case 12:
      if (lookahead == '3') ADVANCE(11);
      if (lookahead == '6') ADVANCE(14);
      END_STATE();
    case 13:
      if (lookahead == '4') ADVANCE(73);
      END_STATE();
    case 14:
      if (lookahead == '4') ADVANCE(81);
      END_STATE();
    case 15:
      if (lookahead == '8') ADVANCE(73);
      END_STATE();
    case 16:
      if (lookahead == ':') ADVANCE(61);
      END_STATE();
    case 17:
      if (lookahead == '\\') ADVANCE(55);
      if (lookahead != 0) ADVANCE(86);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(35);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(42);
      END_STATE();
    case 20:
      if (lookahead == 'c') ADVANCE(46);
      END_STATE();
    case 21:
      if (lookahead == 'd') ADVANCE(90);
      END_STATE();
    case 22:
      if (lookahead == 'd') ADVANCE(45);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(29);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(71);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(72);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(89);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(98);
      END_STATE();
    case 29:
      if (lookahead == 'g') ADVANCE(30);
      END_STATE();
    case 30:
      if (lookahead == 'i') ADVANCE(38);
      END_STATE();
    case 31:
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 32:
      if (lookahead == 'i') ADVANCE(33);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(70);
      END_STATE();
    case 34:
      if (lookahead == 'l') ADVANCE(31);
      END_STATE();
    case 35:
      if (lookahead == 'l') ADVANCE(43);
      END_STATE();
    case 36:
      if (lookahead == 'l') ADVANCE(27);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(21);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(97);
      END_STATE();
    case 39:
      if (lookahead == 'o') ADVANCE(22);
      END_STATE();
    case 40:
      if (lookahead == 'r') ADVANCE(44);
      END_STATE();
    case 41:
      if (lookahead == 's') ADVANCE(20);
      END_STATE();
    case 42:
      if (lookahead == 's') ADVANCE(95);
      END_STATE();
    case 43:
      if (lookahead == 's') ADVANCE(26);
      END_STATE();
    case 44:
      if (lookahead == 'u') ADVANCE(25);
      END_STATE();
    case 45:
      if (lookahead == 'u') ADVANCE(36);
      END_STATE();
    case 46:
      if (lookahead == 'u') ADVANCE(28);
      END_STATE();
    case 47:
      if (lookahead == '{') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(60);
      END_STATE();
    case 48:
      if (lookahead == '}') ADVANCE(88);
      END_STATE();
    case 49:
      if (lookahead == '}') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 50:
      if (lookahead == '}') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 51:
      if (lookahead == '}') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 52:
      if (lookahead == '}') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
      END_STATE();
    case 53:
      if (lookahead == '}') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 54:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(83);
      END_STATE();
    case 55:
      if (sym_char_escape_sequence_character_set_1(lookahead)) ADVANCE(88);
      if (lookahead == 'u') ADVANCE(47);
      END_STATE();
    case 56:
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(84);
      END_STATE();
    case 57:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(88);
      END_STATE();
    case 58:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      END_STATE();
    case 59:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      END_STATE();
    case 60:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 61:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      END_STATE();
    case 62:
      if (eof) ADVANCE(65);
      if (lookahead == '\n') ADVANCE(66);
      if (lookahead == '\'') ADVANCE(85);
      if (lookahead == '(') ADVANCE(68);
      if (lookahead == ')') ADVANCE(69);
      if (lookahead == '0') ADVANCE(74);
      if (lookahead == ':') ADVANCE(5);
      if (lookahead == ';') ADVANCE(67);
      if (lookahead == 'a') ADVANCE(34);
      if (lookahead == 'b') ADVANCE(23);
      if (lookahead == 'e') ADVANCE(37);
      if (lookahead == 'f') ADVANCE(18);
      if (lookahead == 'm') ADVANCE(39);
      if (lookahead == 'n') ADVANCE(32);
      if (lookahead == 'r') ADVANCE(24);
      if (lookahead == 't') ADVANCE(40);
      if (lookahead == '|') ADVANCE(94);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(62)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      END_STATE();
    case 63:
      if (eof) ADVANCE(65);
      if (lookahead == '\'') ADVANCE(85);
      if (lookahead == '(') ADVANCE(68);
      if (lookahead == ')') ADVANCE(69);
      if (lookahead == '0') ADVANCE(76);
      if (lookahead == ':') ADVANCE(5);
      if (lookahead == ';') ADVANCE(67);
      if (lookahead == '=') ADVANCE(96);
      if (lookahead == '|') ADVANCE(94);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(63)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(79);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(92);
      END_STATE();
    case 64:
      if (eof) ADVANCE(65);
      if (lookahead == '\'') ADVANCE(85);
      if (lookahead == '(') ADVANCE(68);
      if (lookahead == ')') ADVANCE(69);
      if (lookahead == '0') ADVANCE(74);
      if (lookahead == ':') ADVANCE(16);
      if (lookahead == ';') ADVANCE(67);
      if (lookahead == 'a') ADVANCE(34);
      if (lookahead == 'b') ADVANCE(23);
      if (lookahead == 'e') ADVANCE(37);
      if (lookahead == 'f') ADVANCE(18);
      if (lookahead == 'm') ADVANCE(39);
      if (lookahead == 'n') ADVANCE(32);
      if (lookahead == 'r') ADVANCE(24);
      if (lookahead == 't') ADVANCE(40);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(64)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_nil);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_integer);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(54);
      if (lookahead == '_') ADVANCE(75);
      if (lookahead == 'b') ADVANCE(77);
      if (lookahead == 'f') ADVANCE(12);
      if (lookahead == 'i') ADVANCE(8);
      if (lookahead == 'o') ADVANCE(78);
      if (lookahead == 'u') ADVANCE(8);
      if (lookahead == 'x') ADVANCE(80);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(82);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(54);
      if (lookahead == 'f') ADVANCE(12);
      if (lookahead == 'i') ADVANCE(8);
      if (lookahead == 'u') ADVANCE(8);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(75);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '_') ADVANCE(79);
      if (lookahead == 'b') ADVANCE(77);
      if (lookahead == 'i') ADVANCE(8);
      if (lookahead == 'o') ADVANCE(78);
      if (lookahead == 'u') ADVANCE(8);
      if (lookahead == 'x') ADVANCE(80);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(8);
      if (lookahead == 'u') ADVANCE(8);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(77);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(8);
      if (lookahead == 'u') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(78);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(8);
      if (lookahead == 'u') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(79);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(8);
      if (lookahead == 'u') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_float);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(12);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(84);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(12);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(84);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_char_token1);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_SQUOTE2);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_char_escape_sequence);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_module);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_end);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_constant);
      if (lookahead == ':') ADVANCE(16);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ';' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(91);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym_identifier_token2);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_begin);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_rescue);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 64},
  [2] = {.lex_state = 62},
  [3] = {.lex_state = 62},
  [4] = {.lex_state = 64},
  [5] = {.lex_state = 64},
  [6] = {.lex_state = 64},
  [7] = {.lex_state = 64},
  [8] = {.lex_state = 64},
  [9] = {.lex_state = 64},
  [10] = {.lex_state = 64},
  [11] = {.lex_state = 64},
  [12] = {.lex_state = 64},
  [13] = {.lex_state = 64},
  [14] = {.lex_state = 64},
  [15] = {.lex_state = 64},
  [16] = {.lex_state = 64},
  [17] = {.lex_state = 64},
  [18] = {.lex_state = 64},
  [19] = {.lex_state = 64},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 62},
  [22] = {.lex_state = 62},
  [23] = {.lex_state = 62},
  [24] = {.lex_state = 62},
  [25] = {.lex_state = 62},
  [26] = {.lex_state = 62},
  [27] = {.lex_state = 62},
  [28] = {.lex_state = 62},
  [29] = {.lex_state = 62},
  [30] = {.lex_state = 62},
  [31] = {.lex_state = 62},
  [32] = {.lex_state = 3},
  [33] = {.lex_state = 62},
  [34] = {.lex_state = 62},
  [35] = {.lex_state = 62},
  [36] = {.lex_state = 62},
  [37] = {.lex_state = 62},
  [38] = {.lex_state = 62},
  [39] = {.lex_state = 62},
  [40] = {.lex_state = 62},
  [41] = {.lex_state = 62},
  [42] = {.lex_state = 62},
  [43] = {.lex_state = 62},
  [44] = {.lex_state = 62},
  [45] = {.lex_state = 62},
  [46] = {.lex_state = 3},
  [47] = {.lex_state = 3},
  [48] = {.lex_state = 62},
  [49] = {.lex_state = 62},
  [50] = {.lex_state = 62},
  [51] = {.lex_state = 62},
  [52] = {.lex_state = 62},
  [53] = {.lex_state = 62},
  [54] = {.lex_state = 62},
  [55] = {.lex_state = 62},
  [56] = {.lex_state = 62},
  [57] = {.lex_state = 62},
  [58] = {.lex_state = 64},
  [59] = {.lex_state = 62},
  [60] = {.lex_state = 62},
  [61] = {.lex_state = 64},
  [62] = {.lex_state = 64},
  [63] = {.lex_state = 64},
  [64] = {.lex_state = 62},
  [65] = {.lex_state = 64},
  [66] = {.lex_state = 62},
  [67] = {.lex_state = 62},
  [68] = {.lex_state = 64},
  [69] = {.lex_state = 62},
  [70] = {.lex_state = 64},
  [71] = {.lex_state = 62},
  [72] = {.lex_state = 62},
  [73] = {.lex_state = 62},
  [74] = {.lex_state = 62},
  [75] = {.lex_state = 62},
  [76] = {.lex_state = 62},
  [77] = {.lex_state = 62},
  [78] = {.lex_state = 62},
  [79] = {.lex_state = 62},
  [80] = {.lex_state = 17},
  [81] = {.lex_state = 17},
  [82] = {.lex_state = 64},
  [83] = {.lex_state = 64},
  [84] = {.lex_state = 64},
  [85] = {.lex_state = 64},
  [86] = {.lex_state = 64},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 1},
  [89] = {.lex_state = 64},
  [90] = {.lex_state = 64},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 64},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 64},
  [98] = {.lex_state = 64},
  [99] = {.lex_state = 64},
  [100] = {.lex_state = 64},
  [101] = {.lex_state = 64},
  [102] = {.lex_state = 64},
  [103] = {.lex_state = 64},
  [104] = {.lex_state = 64},
  [105] = {.lex_state = 64},
  [106] = {.lex_state = 64},
  [107] = {.lex_state = 64},
  [108] = {.lex_state = 64},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 64},
  [111] = {.lex_state = 64},
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
    [sym_constant] = ACTIONS(1),
    [aux_sym_identifier_token1] = ACTIONS(1),
    [aux_sym_identifier_token2] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(92),
    [sym__statements] = STATE(91),
    [sym__parenthesized_statements] = STATE(51),
    [sym__statement] = STATE(51),
    [sym__expression] = STATE(51),
    [sym_char] = STATE(51),
    [sym_module] = STATE(51),
    [sym_alias] = STATE(51),
    [sym_begin_block] = STATE(51),
    [aux_sym__statements_repeat1] = STATE(16),
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
    [sym_constant] = ACTIONS(9),
    [anon_sym_alias] = ACTIONS(17),
    [anon_sym_begin] = ACTIONS(19),
  },
  [2] = {
    [sym__terminator] = STATE(4),
    [sym__statements] = STATE(65),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [sym_rescue_block] = STATE(83),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_LF] = ACTIONS(21),
    [anon_sym_SEMI] = ACTIONS(23),
    [anon_sym_LPAREN] = ACTIONS(25),
    [sym_nil] = ACTIONS(27),
    [sym_true] = ACTIONS(27),
    [sym_false] = ACTIONS(27),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_module] = ACTIONS(31),
    [anon_sym_end] = ACTIONS(33),
    [sym_constant] = ACTIONS(27),
    [anon_sym_alias] = ACTIONS(35),
    [anon_sym_begin] = ACTIONS(37),
    [anon_sym_rescue] = ACTIONS(39),
  },
  [3] = {
    [sym__terminator] = STATE(5),
    [sym__statements] = STATE(63),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [sym_rescue_block] = STATE(100),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_LF] = ACTIONS(41),
    [anon_sym_SEMI] = ACTIONS(43),
    [anon_sym_LPAREN] = ACTIONS(25),
    [sym_nil] = ACTIONS(27),
    [sym_true] = ACTIONS(27),
    [sym_false] = ACTIONS(27),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_module] = ACTIONS(31),
    [anon_sym_end] = ACTIONS(45),
    [sym_constant] = ACTIONS(27),
    [anon_sym_alias] = ACTIONS(35),
    [anon_sym_begin] = ACTIONS(37),
    [anon_sym_rescue] = ACTIONS(39),
  },
  [4] = {
    [sym__statements] = STATE(61),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [sym_rescue_block] = STATE(101),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(49),
    [sym_nil] = ACTIONS(51),
    [sym_true] = ACTIONS(51),
    [sym_false] = ACTIONS(51),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(51),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [anon_sym_end] = ACTIONS(57),
    [sym_constant] = ACTIONS(51),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
    [anon_sym_rescue] = ACTIONS(63),
  },
  [5] = {
    [sym__statements] = STATE(58),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [sym_rescue_block] = STATE(107),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(49),
    [sym_nil] = ACTIONS(51),
    [sym_true] = ACTIONS(51),
    [sym_false] = ACTIONS(51),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(51),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [anon_sym_end] = ACTIONS(65),
    [sym_constant] = ACTIONS(51),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
    [anon_sym_rescue] = ACTIONS(63),
  },
  [6] = {
    [sym__parenthesized_statements] = STATE(79),
    [sym__statement] = STATE(79),
    [sym__expression] = STATE(79),
    [sym_char] = STATE(79),
    [sym_module] = STATE(79),
    [sym_alias] = STATE(79),
    [sym_begin_block] = STATE(79),
    [aux_sym__statements_repeat1] = STATE(6),
    [anon_sym_SEMI] = ACTIONS(67),
    [anon_sym_LPAREN] = ACTIONS(70),
    [anon_sym_RPAREN] = ACTIONS(73),
    [sym_nil] = ACTIONS(75),
    [sym_true] = ACTIONS(75),
    [sym_false] = ACTIONS(75),
    [sym_integer] = ACTIONS(78),
    [sym_float] = ACTIONS(75),
    [anon_sym_SQUOTE] = ACTIONS(81),
    [anon_sym_module] = ACTIONS(84),
    [anon_sym_end] = ACTIONS(73),
    [sym_constant] = ACTIONS(75),
    [anon_sym_alias] = ACTIONS(87),
    [anon_sym_begin] = ACTIONS(90),
    [anon_sym_rescue] = ACTIONS(73),
  },
  [7] = {
    [sym__parenthesized_statements] = STATE(25),
    [sym__statement] = STATE(25),
    [sym__expression] = STATE(25),
    [sym_char] = STATE(25),
    [sym_module] = STATE(25),
    [sym_alias] = STATE(25),
    [sym_begin_block] = STATE(25),
    [aux_sym__statements_repeat1] = STATE(6),
    [anon_sym_SEMI] = ACTIONS(93),
    [anon_sym_LPAREN] = ACTIONS(49),
    [anon_sym_RPAREN] = ACTIONS(95),
    [sym_nil] = ACTIONS(97),
    [sym_true] = ACTIONS(97),
    [sym_false] = ACTIONS(97),
    [sym_integer] = ACTIONS(99),
    [sym_float] = ACTIONS(97),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [anon_sym_end] = ACTIONS(95),
    [sym_constant] = ACTIONS(97),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
    [anon_sym_rescue] = ACTIONS(95),
  },
  [8] = {
    [sym__statements] = STATE(99),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(49),
    [sym_nil] = ACTIONS(51),
    [sym_true] = ACTIONS(51),
    [sym_false] = ACTIONS(51),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(51),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [anon_sym_end] = ACTIONS(101),
    [sym_constant] = ACTIONS(51),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
  },
  [9] = {
    [sym__statements] = STATE(87),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(49),
    [anon_sym_RPAREN] = ACTIONS(103),
    [sym_nil] = ACTIONS(51),
    [sym_true] = ACTIONS(51),
    [sym_false] = ACTIONS(51),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(51),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [sym_constant] = ACTIONS(51),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
  },
  [10] = {
    [sym__statements] = STATE(103),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(49),
    [sym_nil] = ACTIONS(51),
    [sym_true] = ACTIONS(51),
    [sym_false] = ACTIONS(51),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(51),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [anon_sym_end] = ACTIONS(105),
    [sym_constant] = ACTIONS(51),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
  },
  [11] = {
    [sym__statements] = STATE(93),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(49),
    [anon_sym_RPAREN] = ACTIONS(107),
    [sym_nil] = ACTIONS(51),
    [sym_true] = ACTIONS(51),
    [sym_false] = ACTIONS(51),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(51),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [sym_constant] = ACTIONS(51),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
  },
  [12] = {
    [sym__statements] = STATE(108),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(49),
    [sym_nil] = ACTIONS(51),
    [sym_true] = ACTIONS(51),
    [sym_false] = ACTIONS(51),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(51),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [anon_sym_end] = ACTIONS(109),
    [sym_constant] = ACTIONS(51),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
  },
  [13] = {
    [sym__statements] = STATE(86),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(49),
    [sym_nil] = ACTIONS(51),
    [sym_true] = ACTIONS(51),
    [sym_false] = ACTIONS(51),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(51),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [anon_sym_end] = ACTIONS(111),
    [sym_constant] = ACTIONS(51),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
  },
  [14] = {
    [sym__statements] = STATE(84),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(49),
    [sym_nil] = ACTIONS(51),
    [sym_true] = ACTIONS(51),
    [sym_false] = ACTIONS(51),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(51),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [anon_sym_end] = ACTIONS(113),
    [sym_constant] = ACTIONS(51),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
  },
  [15] = {
    [sym__statements] = STATE(82),
    [sym__parenthesized_statements] = STATE(27),
    [sym__statement] = STATE(27),
    [sym__expression] = STATE(27),
    [sym_char] = STATE(27),
    [sym_module] = STATE(27),
    [sym_alias] = STATE(27),
    [sym_begin_block] = STATE(27),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(49),
    [sym_nil] = ACTIONS(51),
    [sym_true] = ACTIONS(51),
    [sym_false] = ACTIONS(51),
    [sym_integer] = ACTIONS(27),
    [sym_float] = ACTIONS(51),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [anon_sym_end] = ACTIONS(115),
    [sym_constant] = ACTIONS(51),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(13), 1,
      anon_sym_SQUOTE,
    ACTIONS(15), 1,
      anon_sym_module,
    ACTIONS(17), 1,
      anon_sym_alias,
    ACTIONS(19), 1,
      anon_sym_begin,
    ACTIONS(95), 1,
      ts_builtin_sym_end,
    ACTIONS(117), 1,
      anon_sym_SEMI,
    ACTIONS(121), 1,
      sym_integer,
    STATE(17), 1,
      aux_sym__statements_repeat1,
    ACTIONS(119), 5,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      sym_constant,
    STATE(48), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [44] = 11,
    ACTIONS(70), 1,
      anon_sym_LPAREN,
    ACTIONS(73), 1,
      ts_builtin_sym_end,
    ACTIONS(81), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_module,
    ACTIONS(87), 1,
      anon_sym_alias,
    ACTIONS(90), 1,
      anon_sym_begin,
    ACTIONS(123), 1,
      anon_sym_SEMI,
    ACTIONS(129), 1,
      sym_integer,
    STATE(17), 1,
      aux_sym__statements_repeat1,
    ACTIONS(126), 5,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      sym_constant,
    STATE(76), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [88] = 2,
    ACTIONS(132), 1,
      sym_integer,
    ACTIONS(73), 14,
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
      sym_constant,
      anon_sym_alias,
      anon_sym_begin,
      anon_sym_rescue,
  [108] = 2,
    ACTIONS(132), 1,
      sym_integer,
    ACTIONS(73), 12,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      anon_sym_SQUOTE,
      anon_sym_module,
      sym_constant,
      anon_sym_alias,
      anon_sym_begin,
  [126] = 7,
    ACTIONS(134), 1,
      anon_sym_LF,
    ACTIONS(136), 1,
      anon_sym_SEMI,
    ACTIONS(138), 1,
      sym_constant,
    ACTIONS(140), 1,
      aux_sym_identifier_token1,
    STATE(14), 1,
      sym__terminator,
    STATE(50), 1,
      sym_identifier,
    STATE(73), 2,
      sym__type,
      sym_union_type,
  [149] = 4,
    ACTIONS(142), 1,
      anon_sym_LF,
    ACTIONS(146), 1,
      anon_sym_PIPE,
    STATE(23), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(144), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [165] = 4,
    ACTIONS(146), 1,
      anon_sym_PIPE,
    ACTIONS(148), 1,
      anon_sym_LF,
    STATE(21), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(150), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [181] = 4,
    ACTIONS(152), 1,
      anon_sym_LF,
    ACTIONS(156), 1,
      anon_sym_PIPE,
    STATE(23), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(154), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [197] = 3,
    ACTIONS(159), 1,
      anon_sym_LF,
    ACTIONS(163), 1,
      anon_sym_PIPE,
    ACTIONS(161), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [210] = 4,
    ACTIONS(165), 1,
      anon_sym_LF,
    ACTIONS(167), 1,
      anon_sym_SEMI,
    STATE(18), 1,
      sym__terminator,
    ACTIONS(169), 3,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [225] = 2,
    ACTIONS(152), 1,
      anon_sym_LF,
    ACTIONS(154), 5,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_PIPE,
      anon_sym_rescue,
  [236] = 4,
    ACTIONS(165), 1,
      anon_sym_LF,
    ACTIONS(167), 1,
      anon_sym_SEMI,
    STATE(18), 1,
      sym__terminator,
    ACTIONS(171), 3,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [251] = 2,
    ACTIONS(173), 1,
      anon_sym_LF,
    ACTIONS(175), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [261] = 4,
    ACTIONS(154), 1,
      anon_sym_SEMI,
    ACTIONS(177), 1,
      anon_sym_PIPE,
    STATE(29), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(152), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [275] = 4,
    ACTIONS(144), 1,
      anon_sym_SEMI,
    ACTIONS(180), 1,
      anon_sym_PIPE,
    STATE(29), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(142), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [289] = 2,
    ACTIONS(182), 1,
      anon_sym_LF,
    ACTIONS(184), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [299] = 4,
    ACTIONS(186), 1,
      anon_sym_LF,
    ACTIONS(190), 1,
      aux_sym_identifier_token2,
    STATE(46), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(188), 2,
      anon_sym_SEMI,
      anon_sym_COLON,
  [313] = 4,
    ACTIONS(150), 1,
      anon_sym_SEMI,
    ACTIONS(180), 1,
      anon_sym_PIPE,
    STATE(30), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(148), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [327] = 2,
    ACTIONS(192), 1,
      anon_sym_LF,
    ACTIONS(194), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [337] = 2,
    ACTIONS(196), 1,
      anon_sym_LF,
    ACTIONS(198), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [347] = 2,
    ACTIONS(200), 1,
      anon_sym_LF,
    ACTIONS(202), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [357] = 2,
    ACTIONS(204), 1,
      anon_sym_LF,
    ACTIONS(206), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [367] = 2,
    ACTIONS(208), 1,
      anon_sym_LF,
    ACTIONS(210), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [377] = 2,
    ACTIONS(212), 1,
      anon_sym_LF,
    ACTIONS(214), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [387] = 2,
    ACTIONS(216), 1,
      anon_sym_LF,
    ACTIONS(218), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [397] = 2,
    ACTIONS(220), 1,
      anon_sym_LF,
    ACTIONS(222), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [407] = 2,
    ACTIONS(224), 1,
      anon_sym_LF,
    ACTIONS(226), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [417] = 2,
    ACTIONS(228), 1,
      anon_sym_LF,
    ACTIONS(230), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [427] = 2,
    ACTIONS(232), 1,
      anon_sym_LF,
    ACTIONS(234), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [437] = 2,
    ACTIONS(236), 1,
      anon_sym_LF,
    ACTIONS(238), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [447] = 4,
    ACTIONS(240), 1,
      anon_sym_LF,
    ACTIONS(244), 1,
      aux_sym_identifier_token2,
    STATE(47), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(242), 2,
      anon_sym_SEMI,
      anon_sym_COLON,
  [461] = 4,
    ACTIONS(246), 1,
      anon_sym_LF,
    ACTIONS(250), 1,
      aux_sym_identifier_token2,
    STATE(47), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(248), 2,
      anon_sym_SEMI,
      anon_sym_COLON,
  [475] = 4,
    ACTIONS(253), 1,
      ts_builtin_sym_end,
    ACTIONS(255), 1,
      anon_sym_LF,
    ACTIONS(257), 1,
      anon_sym_SEMI,
    STATE(19), 1,
      sym__terminator,
  [488] = 2,
    ACTIONS(152), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(154), 2,
      anon_sym_SEMI,
      anon_sym_PIPE,
  [497] = 4,
    ACTIONS(259), 1,
      anon_sym_LF,
    ACTIONS(261), 1,
      anon_sym_SEMI,
    ACTIONS(263), 1,
      anon_sym_COLON,
    STATE(12), 1,
      sym__terminator,
  [510] = 4,
    ACTIONS(95), 1,
      ts_builtin_sym_end,
    ACTIONS(255), 1,
      anon_sym_LF,
    ACTIONS(257), 1,
      anon_sym_SEMI,
    STATE(19), 1,
      sym__terminator,
  [523] = 3,
    ACTIONS(161), 1,
      anon_sym_SEMI,
    ACTIONS(265), 1,
      anon_sym_PIPE,
    ACTIONS(159), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [534] = 2,
    ACTIONS(218), 1,
      anon_sym_SEMI,
    ACTIONS(216), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [542] = 2,
    ACTIONS(226), 1,
      anon_sym_SEMI,
    ACTIONS(224), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [550] = 2,
    ACTIONS(194), 1,
      anon_sym_SEMI,
    ACTIONS(192), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [558] = 3,
    ACTIONS(267), 1,
      anon_sym_LF,
    ACTIONS(269), 1,
      anon_sym_SEMI,
    STATE(10), 1,
      sym__terminator,
  [568] = 3,
    ACTIONS(271), 1,
      anon_sym_LF,
    ACTIONS(273), 1,
      anon_sym_SEMI,
    STATE(8), 1,
      sym__terminator,
  [578] = 3,
    ACTIONS(63), 1,
      anon_sym_rescue,
    ACTIONS(275), 1,
      anon_sym_end,
    STATE(89), 1,
      sym_rescue_block,
  [588] = 2,
    ACTIONS(222), 1,
      anon_sym_SEMI,
    ACTIONS(220), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [596] = 2,
    ACTIONS(184), 1,
      anon_sym_SEMI,
    ACTIONS(182), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [604] = 3,
    ACTIONS(63), 1,
      anon_sym_rescue,
    ACTIONS(277), 1,
      anon_sym_end,
    STATE(105), 1,
      sym_rescue_block,
  [614] = 2,
    ACTIONS(279), 1,
      sym_constant,
    STATE(37), 2,
      sym__type,
      sym_union_type,
  [622] = 3,
    ACTIONS(63), 1,
      anon_sym_rescue,
    ACTIONS(281), 1,
      anon_sym_end,
    STATE(85), 1,
      sym_rescue_block,
  [632] = 2,
    ACTIONS(234), 1,
      anon_sym_SEMI,
    ACTIONS(232), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [640] = 3,
    ACTIONS(63), 1,
      anon_sym_rescue,
    ACTIONS(283), 1,
      anon_sym_end,
    STATE(102), 1,
      sym_rescue_block,
  [650] = 2,
    ACTIONS(230), 1,
      anon_sym_SEMI,
    ACTIONS(228), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [658] = 3,
    ACTIONS(285), 1,
      anon_sym_LF,
    ACTIONS(287), 1,
      anon_sym_SEMI,
    STATE(13), 1,
      sym__terminator,
  [668] = 2,
    ACTIONS(279), 1,
      sym_constant,
    STATE(57), 2,
      sym__type,
      sym_union_type,
  [676] = 2,
    ACTIONS(206), 1,
      anon_sym_SEMI,
    ACTIONS(204), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [684] = 2,
    ACTIONS(289), 1,
      sym_constant,
    STATE(69), 2,
      sym__type,
      sym_union_type,
  [692] = 2,
    ACTIONS(198), 1,
      anon_sym_SEMI,
    ACTIONS(196), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [700] = 2,
    ACTIONS(238), 1,
      anon_sym_SEMI,
    ACTIONS(236), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [708] = 3,
    ACTIONS(291), 1,
      anon_sym_LF,
    ACTIONS(293), 1,
      anon_sym_SEMI,
    STATE(15), 1,
      sym__terminator,
  [718] = 2,
    ACTIONS(210), 1,
      anon_sym_SEMI,
    ACTIONS(208), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [726] = 2,
    ACTIONS(202), 1,
      anon_sym_SEMI,
    ACTIONS(200), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [734] = 3,
    ACTIONS(255), 1,
      anon_sym_LF,
    ACTIONS(257), 1,
      anon_sym_SEMI,
    STATE(19), 1,
      sym__terminator,
  [744] = 2,
    ACTIONS(214), 1,
      anon_sym_SEMI,
    ACTIONS(212), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [752] = 2,
    ACTIONS(175), 1,
      anon_sym_SEMI,
    ACTIONS(173), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [760] = 3,
    ACTIONS(165), 1,
      anon_sym_LF,
    ACTIONS(167), 1,
      anon_sym_SEMI,
    STATE(18), 1,
      sym__terminator,
  [770] = 1,
    ACTIONS(295), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [775] = 1,
    ACTIONS(297), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [780] = 1,
    ACTIONS(299), 1,
      anon_sym_end,
  [784] = 1,
    ACTIONS(301), 1,
      anon_sym_end,
  [788] = 1,
    ACTIONS(303), 1,
      anon_sym_end,
  [792] = 1,
    ACTIONS(305), 1,
      anon_sym_end,
  [796] = 1,
    ACTIONS(307), 1,
      anon_sym_end,
  [800] = 1,
    ACTIONS(309), 1,
      anon_sym_RPAREN,
  [804] = 1,
    ACTIONS(311), 1,
      anon_sym_SQUOTE2,
  [808] = 1,
    ACTIONS(313), 1,
      anon_sym_end,
  [812] = 1,
    ACTIONS(315), 1,
      sym_constant,
  [816] = 1,
    ACTIONS(317), 1,
      ts_builtin_sym_end,
  [820] = 1,
    ACTIONS(319), 1,
      ts_builtin_sym_end,
  [824] = 1,
    ACTIONS(321), 1,
      anon_sym_RPAREN,
  [828] = 1,
    ACTIONS(323), 1,
      anon_sym_SQUOTE2,
  [832] = 1,
    ACTIONS(325), 1,
      sym_constant,
  [836] = 1,
    ACTIONS(327), 1,
      anon_sym_EQ,
  [840] = 1,
    ACTIONS(329), 1,
      sym_constant,
  [844] = 1,
    ACTIONS(331), 1,
      sym_constant,
  [848] = 1,
    ACTIONS(333), 1,
      anon_sym_end,
  [852] = 1,
    ACTIONS(335), 1,
      anon_sym_end,
  [856] = 1,
    ACTIONS(337), 1,
      anon_sym_end,
  [860] = 1,
    ACTIONS(339), 1,
      anon_sym_end,
  [864] = 1,
    ACTIONS(341), 1,
      anon_sym_end,
  [868] = 1,
    ACTIONS(343), 1,
      sym_constant,
  [872] = 1,
    ACTIONS(345), 1,
      anon_sym_end,
  [876] = 1,
    ACTIONS(347), 1,
      sym_constant,
  [880] = 1,
    ACTIONS(349), 1,
      anon_sym_end,
  [884] = 1,
    ACTIONS(351), 1,
      anon_sym_end,
  [888] = 1,
    ACTIONS(353), 1,
      anon_sym_EQ,
  [892] = 1,
    ACTIONS(355), 1,
      sym_constant,
  [896] = 1,
    ACTIONS(357), 1,
      sym_constant,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(16)] = 0,
  [SMALL_STATE(17)] = 44,
  [SMALL_STATE(18)] = 88,
  [SMALL_STATE(19)] = 108,
  [SMALL_STATE(20)] = 126,
  [SMALL_STATE(21)] = 149,
  [SMALL_STATE(22)] = 165,
  [SMALL_STATE(23)] = 181,
  [SMALL_STATE(24)] = 197,
  [SMALL_STATE(25)] = 210,
  [SMALL_STATE(26)] = 225,
  [SMALL_STATE(27)] = 236,
  [SMALL_STATE(28)] = 251,
  [SMALL_STATE(29)] = 261,
  [SMALL_STATE(30)] = 275,
  [SMALL_STATE(31)] = 289,
  [SMALL_STATE(32)] = 299,
  [SMALL_STATE(33)] = 313,
  [SMALL_STATE(34)] = 327,
  [SMALL_STATE(35)] = 337,
  [SMALL_STATE(36)] = 347,
  [SMALL_STATE(37)] = 357,
  [SMALL_STATE(38)] = 367,
  [SMALL_STATE(39)] = 377,
  [SMALL_STATE(40)] = 387,
  [SMALL_STATE(41)] = 397,
  [SMALL_STATE(42)] = 407,
  [SMALL_STATE(43)] = 417,
  [SMALL_STATE(44)] = 427,
  [SMALL_STATE(45)] = 437,
  [SMALL_STATE(46)] = 447,
  [SMALL_STATE(47)] = 461,
  [SMALL_STATE(48)] = 475,
  [SMALL_STATE(49)] = 488,
  [SMALL_STATE(50)] = 497,
  [SMALL_STATE(51)] = 510,
  [SMALL_STATE(52)] = 523,
  [SMALL_STATE(53)] = 534,
  [SMALL_STATE(54)] = 542,
  [SMALL_STATE(55)] = 550,
  [SMALL_STATE(56)] = 558,
  [SMALL_STATE(57)] = 568,
  [SMALL_STATE(58)] = 578,
  [SMALL_STATE(59)] = 588,
  [SMALL_STATE(60)] = 596,
  [SMALL_STATE(61)] = 604,
  [SMALL_STATE(62)] = 614,
  [SMALL_STATE(63)] = 622,
  [SMALL_STATE(64)] = 632,
  [SMALL_STATE(65)] = 640,
  [SMALL_STATE(66)] = 650,
  [SMALL_STATE(67)] = 658,
  [SMALL_STATE(68)] = 668,
  [SMALL_STATE(69)] = 676,
  [SMALL_STATE(70)] = 684,
  [SMALL_STATE(71)] = 692,
  [SMALL_STATE(72)] = 700,
  [SMALL_STATE(73)] = 708,
  [SMALL_STATE(74)] = 718,
  [SMALL_STATE(75)] = 726,
  [SMALL_STATE(76)] = 734,
  [SMALL_STATE(77)] = 744,
  [SMALL_STATE(78)] = 752,
  [SMALL_STATE(79)] = 760,
  [SMALL_STATE(80)] = 770,
  [SMALL_STATE(81)] = 775,
  [SMALL_STATE(82)] = 780,
  [SMALL_STATE(83)] = 784,
  [SMALL_STATE(84)] = 788,
  [SMALL_STATE(85)] = 792,
  [SMALL_STATE(86)] = 796,
  [SMALL_STATE(87)] = 800,
  [SMALL_STATE(88)] = 804,
  [SMALL_STATE(89)] = 808,
  [SMALL_STATE(90)] = 812,
  [SMALL_STATE(91)] = 816,
  [SMALL_STATE(92)] = 820,
  [SMALL_STATE(93)] = 824,
  [SMALL_STATE(94)] = 828,
  [SMALL_STATE(95)] = 832,
  [SMALL_STATE(96)] = 836,
  [SMALL_STATE(97)] = 840,
  [SMALL_STATE(98)] = 844,
  [SMALL_STATE(99)] = 848,
  [SMALL_STATE(100)] = 852,
  [SMALL_STATE(101)] = 856,
  [SMALL_STATE(102)] = 860,
  [SMALL_STATE(103)] = 864,
  [SMALL_STATE(104)] = 868,
  [SMALL_STATE(105)] = 872,
  [SMALL_STATE(106)] = 876,
  [SMALL_STATE(107)] = 880,
  [SMALL_STATE(108)] = 884,
  [SMALL_STATE(109)] = 888,
  [SMALL_STATE(110)] = 892,
  [SMALL_STATE(111)] = 896,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(6),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(11),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(79),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(79),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(80),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(110),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(111),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(2),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 1),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 5, .production_id = 14),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 3, .production_id = 6),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 2),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 3, .production_id = 7),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [123] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(17),
  [126] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(76),
  [129] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(76),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [136] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_union_type, 4),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_union_type, 4),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_union_type, 3),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_union_type, 3),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_union_type_repeat1, 2),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_union_type_repeat1, 2),
  [156] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_union_type_repeat1, 2), SHIFT_REPEAT(104),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type, 1),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__type, 1),
  [163] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [167] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 2),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 4, .production_id = 9),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 4, .production_id = 9),
  [177] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_union_type_repeat1, 2), SHIFT_REPEAT(106),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 5, .production_id = 13),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 5, .production_id = 13),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1),
  [190] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 5, .production_id = 10),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_module, 5, .production_id = 10),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 4, .production_id = 8),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 4, .production_id = 8),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 4, .production_id = 5),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 4, .production_id = 5),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alias, 4, .production_id = 4),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_alias, 4, .production_id = 4),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 4, .production_id = 3),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_module, 4, .production_id = 3),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 3, .production_id = 2),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 3, .production_id = 2),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 3, .production_id = 1),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 3, .production_id = 1),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 3),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 3),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char, 3),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char, 3),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 3),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__parenthesized_statements, 3),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 2),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 2),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 2),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__parenthesized_statements, 2),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 2),
  [242] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 2),
  [244] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2),
  [250] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2), SHIFT_REPEAT(47),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [257] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [261] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [263] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [265] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [269] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [273] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [287] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [293] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 4, .production_id = 12),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 3, .production_id = 5),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [319] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 6, .production_id = 15),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 4, .production_id = 11),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
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
