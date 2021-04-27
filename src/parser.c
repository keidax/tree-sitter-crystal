#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 167
#define LARGE_STATE_COUNT 8
#define SYMBOL_COUNT 45
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
  sym__nested_union_type = 36,
  sym__inner_union_type = 37,
  sym_alias = 38,
  sym_begin_block = 39,
  sym_rescue_block = 40,
  aux_sym__statements_repeat1 = 41,
  aux_sym_identifier_repeat1 = 42,
  aux_sym_union_type_repeat1 = 43,
  aux_sym__inner_union_type_repeat1 = 44,
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
  [sym__nested_union_type] = "_nested_union_type",
  [sym__inner_union_type] = "_inner_union_type",
  [sym_alias] = "alias",
  [sym_begin_block] = "begin_block",
  [sym_rescue_block] = "rescue_block",
  [aux_sym__statements_repeat1] = "_statements_repeat1",
  [aux_sym_identifier_repeat1] = "identifier_repeat1",
  [aux_sym_union_type_repeat1] = "union_type_repeat1",
  [aux_sym__inner_union_type_repeat1] = "_inner_union_type_repeat1",
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
  [sym__nested_union_type] = sym__nested_union_type,
  [sym__inner_union_type] = sym__inner_union_type,
  [sym_alias] = sym_alias,
  [sym_begin_block] = sym_begin_block,
  [sym_rescue_block] = sym_rescue_block,
  [aux_sym__statements_repeat1] = aux_sym__statements_repeat1,
  [aux_sym_identifier_repeat1] = aux_sym_identifier_repeat1,
  [aux_sym_union_type_repeat1] = aux_sym_union_type_repeat1,
  [aux_sym__inner_union_type_repeat1] = aux_sym__inner_union_type_repeat1,
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
  [sym__nested_union_type] = {
    .visible = false,
    .named = true,
  },
  [sym__inner_union_type] = {
    .visible = false,
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
  [aux_sym__inner_union_type_repeat1] = {
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
      if (lookahead == '(') ADVANCE(68);
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
      if (lookahead == '(') ADVANCE(68);
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
  [29] = {.lex_state = 64},
  [30] = {.lex_state = 62},
  [31] = {.lex_state = 64},
  [32] = {.lex_state = 64},
  [33] = {.lex_state = 64},
  [34] = {.lex_state = 62},
  [35] = {.lex_state = 62},
  [36] = {.lex_state = 62},
  [37] = {.lex_state = 62},
  [38] = {.lex_state = 62},
  [39] = {.lex_state = 64},
  [40] = {.lex_state = 62},
  [41] = {.lex_state = 64},
  [42] = {.lex_state = 62},
  [43] = {.lex_state = 62},
  [44] = {.lex_state = 62},
  [45] = {.lex_state = 62},
  [46] = {.lex_state = 62},
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
  [58] = {.lex_state = 62},
  [59] = {.lex_state = 62},
  [60] = {.lex_state = 3},
  [61] = {.lex_state = 62},
  [62] = {.lex_state = 62},
  [63] = {.lex_state = 62},
  [64] = {.lex_state = 62},
  [65] = {.lex_state = 3},
  [66] = {.lex_state = 62},
  [67] = {.lex_state = 62},
  [68] = {.lex_state = 62},
  [69] = {.lex_state = 64},
  [70] = {.lex_state = 64},
  [71] = {.lex_state = 64},
  [72] = {.lex_state = 64},
  [73] = {.lex_state = 64},
  [74] = {.lex_state = 64},
  [75] = {.lex_state = 64},
  [76] = {.lex_state = 64},
  [77] = {.lex_state = 64},
  [78] = {.lex_state = 64},
  [79] = {.lex_state = 64},
  [80] = {.lex_state = 62},
  [81] = {.lex_state = 62},
  [82] = {.lex_state = 64},
  [83] = {.lex_state = 64},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 62},
  [86] = {.lex_state = 64},
  [87] = {.lex_state = 62},
  [88] = {.lex_state = 64},
  [89] = {.lex_state = 64},
  [90] = {.lex_state = 64},
  [91] = {.lex_state = 64},
  [92] = {.lex_state = 64},
  [93] = {.lex_state = 62},
  [94] = {.lex_state = 62},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 62},
  [97] = {.lex_state = 62},
  [98] = {.lex_state = 62},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 62},
  [101] = {.lex_state = 62},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 62},
  [104] = {.lex_state = 62},
  [105] = {.lex_state = 62},
  [106] = {.lex_state = 64},
  [107] = {.lex_state = 62},
  [108] = {.lex_state = 62},
  [109] = {.lex_state = 64},
  [110] = {.lex_state = 64},
  [111] = {.lex_state = 62},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 62},
  [114] = {.lex_state = 62},
  [115] = {.lex_state = 62},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 62},
  [118] = {.lex_state = 62},
  [119] = {.lex_state = 62},
  [120] = {.lex_state = 62},
  [121] = {.lex_state = 62},
  [122] = {.lex_state = 64},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 62},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 17},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 17},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 64},
  [136] = {.lex_state = 64},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 64},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 1},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 64},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 64},
  [146] = {.lex_state = 64},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 64},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 64},
  [151] = {.lex_state = 64},
  [152] = {.lex_state = 64},
  [153] = {.lex_state = 64},
  [154] = {.lex_state = 64},
  [155] = {.lex_state = 1},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 64},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 64},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 64},
  [164] = {.lex_state = 64},
  [165] = {.lex_state = 64},
  [166] = {.lex_state = 64},
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
    [sym_source_file] = STATE(144),
    [sym__statements] = STATE(143),
    [sym__parenthesized_statements] = STATE(80),
    [sym__statement] = STATE(80),
    [sym__expression] = STATE(80),
    [sym_char] = STATE(80),
    [sym_module] = STATE(80),
    [sym_alias] = STATE(80),
    [sym_begin_block] = STATE(80),
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
    [sym__statements] = STATE(122),
    [sym__parenthesized_statements] = STATE(38),
    [sym__statement] = STATE(38),
    [sym__expression] = STATE(38),
    [sym_char] = STATE(38),
    [sym_module] = STATE(38),
    [sym_alias] = STATE(38),
    [sym_begin_block] = STATE(38),
    [sym_rescue_block] = STATE(150),
    [aux_sym__statements_repeat1] = STATE(6),
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
    [sym__statements] = STATE(109),
    [sym__parenthesized_statements] = STATE(38),
    [sym__statement] = STATE(38),
    [sym__expression] = STATE(38),
    [sym_char] = STATE(38),
    [sym_module] = STATE(38),
    [sym_alias] = STATE(38),
    [sym_begin_block] = STATE(38),
    [sym_rescue_block] = STATE(142),
    [aux_sym__statements_repeat1] = STATE(6),
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
    [sym__statements] = STATE(110),
    [sym__parenthesized_statements] = STATE(38),
    [sym__statement] = STATE(38),
    [sym__expression] = STATE(38),
    [sym_char] = STATE(38),
    [sym_module] = STATE(38),
    [sym_alias] = STATE(38),
    [sym_begin_block] = STATE(38),
    [sym_rescue_block] = STATE(145),
    [aux_sym__statements_repeat1] = STATE(6),
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
    [sym__statements] = STATE(106),
    [sym__parenthesized_statements] = STATE(38),
    [sym__statement] = STATE(38),
    [sym__expression] = STATE(38),
    [sym_char] = STATE(38),
    [sym_module] = STATE(38),
    [sym_alias] = STATE(38),
    [sym_begin_block] = STATE(38),
    [sym_rescue_block] = STATE(146),
    [aux_sym__statements_repeat1] = STATE(6),
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
    [sym__parenthesized_statements] = STATE(40),
    [sym__statement] = STATE(40),
    [sym__expression] = STATE(40),
    [sym_char] = STATE(40),
    [sym_module] = STATE(40),
    [sym_alias] = STATE(40),
    [sym_begin_block] = STATE(40),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(67),
    [anon_sym_LPAREN] = ACTIONS(49),
    [anon_sym_RPAREN] = ACTIONS(69),
    [sym_nil] = ACTIONS(71),
    [sym_true] = ACTIONS(71),
    [sym_false] = ACTIONS(71),
    [sym_integer] = ACTIONS(73),
    [sym_float] = ACTIONS(71),
    [anon_sym_SQUOTE] = ACTIONS(53),
    [anon_sym_module] = ACTIONS(55),
    [anon_sym_end] = ACTIONS(69),
    [sym_constant] = ACTIONS(71),
    [anon_sym_alias] = ACTIONS(59),
    [anon_sym_begin] = ACTIONS(61),
    [anon_sym_rescue] = ACTIONS(69),
  },
  [7] = {
    [sym__parenthesized_statements] = STATE(101),
    [sym__statement] = STATE(101),
    [sym__expression] = STATE(101),
    [sym_char] = STATE(101),
    [sym_module] = STATE(101),
    [sym_alias] = STATE(101),
    [sym_begin_block] = STATE(101),
    [aux_sym__statements_repeat1] = STATE(7),
    [anon_sym_SEMI] = ACTIONS(75),
    [anon_sym_LPAREN] = ACTIONS(78),
    [anon_sym_RPAREN] = ACTIONS(81),
    [sym_nil] = ACTIONS(83),
    [sym_true] = ACTIONS(83),
    [sym_false] = ACTIONS(83),
    [sym_integer] = ACTIONS(86),
    [sym_float] = ACTIONS(83),
    [anon_sym_SQUOTE] = ACTIONS(89),
    [anon_sym_module] = ACTIONS(92),
    [anon_sym_end] = ACTIONS(81),
    [sym_constant] = ACTIONS(83),
    [anon_sym_alias] = ACTIONS(95),
    [anon_sym_begin] = ACTIONS(98),
    [anon_sym_rescue] = ACTIONS(81),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 12,
    ACTIONS(27), 1,
      sym_integer,
    ACTIONS(47), 1,
      anon_sym_SEMI,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(53), 1,
      anon_sym_SQUOTE,
    ACTIONS(55), 1,
      anon_sym_module,
    ACTIONS(59), 1,
      anon_sym_alias,
    ACTIONS(61), 1,
      anon_sym_begin,
    ACTIONS(101), 1,
      anon_sym_RPAREN,
    STATE(6), 1,
      aux_sym__statements_repeat1,
    STATE(137), 1,
      sym__statements,
    ACTIONS(51), 5,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      sym_constant,
    STATE(38), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [47] = 12,
    ACTIONS(27), 1,
      sym_integer,
    ACTIONS(47), 1,
      anon_sym_SEMI,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(53), 1,
      anon_sym_SQUOTE,
    ACTIONS(55), 1,
      anon_sym_module,
    ACTIONS(59), 1,
      anon_sym_alias,
    ACTIONS(61), 1,
      anon_sym_begin,
    ACTIONS(103), 1,
      anon_sym_end,
    STATE(6), 1,
      aux_sym__statements_repeat1,
    STATE(152), 1,
      sym__statements,
    ACTIONS(51), 5,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      sym_constant,
    STATE(38), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [94] = 12,
    ACTIONS(27), 1,
      sym_integer,
    ACTIONS(47), 1,
      anon_sym_SEMI,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(53), 1,
      anon_sym_SQUOTE,
    ACTIONS(55), 1,
      anon_sym_module,
    ACTIONS(59), 1,
      anon_sym_alias,
    ACTIONS(61), 1,
      anon_sym_begin,
    ACTIONS(105), 1,
      anon_sym_end,
    STATE(6), 1,
      aux_sym__statements_repeat1,
    STATE(153), 1,
      sym__statements,
    ACTIONS(51), 5,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      sym_constant,
    STATE(38), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [141] = 12,
    ACTIONS(27), 1,
      sym_integer,
    ACTIONS(47), 1,
      anon_sym_SEMI,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(53), 1,
      anon_sym_SQUOTE,
    ACTIONS(55), 1,
      anon_sym_module,
    ACTIONS(59), 1,
      anon_sym_alias,
    ACTIONS(61), 1,
      anon_sym_begin,
    ACTIONS(107), 1,
      anon_sym_end,
    STATE(6), 1,
      aux_sym__statements_repeat1,
    STATE(148), 1,
      sym__statements,
    ACTIONS(51), 5,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      sym_constant,
    STATE(38), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [188] = 12,
    ACTIONS(27), 1,
      sym_integer,
    ACTIONS(47), 1,
      anon_sym_SEMI,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(53), 1,
      anon_sym_SQUOTE,
    ACTIONS(55), 1,
      anon_sym_module,
    ACTIONS(59), 1,
      anon_sym_alias,
    ACTIONS(61), 1,
      anon_sym_begin,
    ACTIONS(109), 1,
      anon_sym_end,
    STATE(6), 1,
      aux_sym__statements_repeat1,
    STATE(154), 1,
      sym__statements,
    ACTIONS(51), 5,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      sym_constant,
    STATE(38), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [235] = 12,
    ACTIONS(27), 1,
      sym_integer,
    ACTIONS(47), 1,
      anon_sym_SEMI,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(53), 1,
      anon_sym_SQUOTE,
    ACTIONS(55), 1,
      anon_sym_module,
    ACTIONS(59), 1,
      anon_sym_alias,
    ACTIONS(61), 1,
      anon_sym_begin,
    ACTIONS(111), 1,
      anon_sym_RPAREN,
    STATE(6), 1,
      aux_sym__statements_repeat1,
    STATE(139), 1,
      sym__statements,
    ACTIONS(51), 5,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      sym_constant,
    STATE(38), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [282] = 12,
    ACTIONS(27), 1,
      sym_integer,
    ACTIONS(47), 1,
      anon_sym_SEMI,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(53), 1,
      anon_sym_SQUOTE,
    ACTIONS(55), 1,
      anon_sym_module,
    ACTIONS(59), 1,
      anon_sym_alias,
    ACTIONS(61), 1,
      anon_sym_begin,
    ACTIONS(113), 1,
      anon_sym_end,
    STATE(6), 1,
      aux_sym__statements_repeat1,
    STATE(163), 1,
      sym__statements,
    ACTIONS(51), 5,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      sym_constant,
    STATE(38), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [329] = 12,
    ACTIONS(27), 1,
      sym_integer,
    ACTIONS(47), 1,
      anon_sym_SEMI,
    ACTIONS(49), 1,
      anon_sym_LPAREN,
    ACTIONS(53), 1,
      anon_sym_SQUOTE,
    ACTIONS(55), 1,
      anon_sym_module,
    ACTIONS(59), 1,
      anon_sym_alias,
    ACTIONS(61), 1,
      anon_sym_begin,
    ACTIONS(115), 1,
      anon_sym_end,
    STATE(6), 1,
      aux_sym__statements_repeat1,
    STATE(138), 1,
      sym__statements,
    ACTIONS(51), 5,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      sym_constant,
    STATE(38), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [376] = 11,
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
    ACTIONS(69), 1,
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
    STATE(87), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [420] = 11,
    ACTIONS(78), 1,
      anon_sym_LPAREN,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    ACTIONS(89), 1,
      anon_sym_SQUOTE,
    ACTIONS(92), 1,
      anon_sym_module,
    ACTIONS(95), 1,
      anon_sym_alias,
    ACTIONS(98), 1,
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
    STATE(104), 7,
      sym__parenthesized_statements,
      sym__statement,
      sym__expression,
      sym_char,
      sym_module,
      sym_alias,
      sym_begin_block,
  [464] = 2,
    ACTIONS(132), 1,
      sym_integer,
    ACTIONS(81), 14,
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
  [484] = 2,
    ACTIONS(132), 1,
      sym_integer,
    ACTIONS(81), 12,
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
  [502] = 9,
    ACTIONS(134), 1,
      anon_sym_LF,
    ACTIONS(136), 1,
      anon_sym_SEMI,
    ACTIONS(138), 1,
      anon_sym_LPAREN,
    ACTIONS(140), 1,
      sym_constant,
    ACTIONS(142), 1,
      aux_sym_identifier_token1,
    STATE(10), 1,
      sym__terminator,
    STATE(68), 1,
      sym_identifier,
    STATE(114), 2,
      sym__type,
      sym_union_type,
    STATE(141), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [532] = 5,
    ACTIONS(144), 1,
      anon_sym_LF,
    ACTIONS(148), 1,
      anon_sym_PIPE,
    STATE(27), 1,
      aux_sym_union_type_repeat1,
    STATE(99), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(146), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [551] = 4,
    ACTIONS(150), 1,
      anon_sym_LF,
    ACTIONS(154), 1,
      anon_sym_PIPE,
    STATE(24), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(152), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [567] = 4,
    ACTIONS(156), 1,
      anon_sym_LF,
    ACTIONS(160), 1,
      anon_sym_PIPE,
    STATE(22), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(158), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [583] = 4,
    ACTIONS(162), 1,
      anon_sym_LF,
    ACTIONS(166), 1,
      anon_sym_PIPE,
    STATE(24), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(164), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [599] = 4,
    ACTIONS(169), 1,
      anon_sym_LF,
    ACTIONS(173), 1,
      anon_sym_PIPE,
    STATE(25), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(171), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [615] = 3,
    ACTIONS(162), 1,
      anon_sym_LF,
    STATE(22), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(164), 5,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_PIPE,
      anon_sym_rescue,
  [629] = 4,
    ACTIONS(176), 1,
      anon_sym_LF,
    ACTIONS(180), 1,
      anon_sym_PIPE,
    STATE(25), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(178), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [645] = 3,
    ACTIONS(169), 1,
      anon_sym_LF,
    STATE(22), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(171), 5,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_PIPE,
      anon_sym_rescue,
  [659] = 4,
    ACTIONS(182), 1,
      anon_sym_LPAREN,
    ACTIONS(184), 1,
      sym_constant,
    STATE(115), 2,
      sym__type,
      sym_union_type,
    STATE(141), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [674] = 2,
    ACTIONS(162), 1,
      anon_sym_LF,
    ACTIONS(164), 5,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_PIPE,
      anon_sym_rescue,
  [685] = 4,
    ACTIONS(186), 1,
      anon_sym_LPAREN,
    ACTIONS(188), 1,
      sym_constant,
    STATE(128), 2,
      sym__nested_union_type,
      sym__inner_union_type,
    STATE(149), 2,
      sym__type,
      sym_union_type,
  [700] = 4,
    ACTIONS(190), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 1,
      sym_constant,
    STATE(100), 2,
      sym__type,
      sym_union_type,
    STATE(162), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [715] = 4,
    ACTIONS(186), 1,
      anon_sym_LPAREN,
    ACTIONS(188), 1,
      sym_constant,
    STATE(128), 2,
      sym__nested_union_type,
      sym__inner_union_type,
    STATE(156), 2,
      sym__type,
      sym_union_type,
  [730] = 3,
    ACTIONS(194), 1,
      anon_sym_LF,
    ACTIONS(198), 1,
      anon_sym_PIPE,
    ACTIONS(196), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [743] = 5,
    ACTIONS(146), 1,
      anon_sym_SEMI,
    ACTIONS(200), 1,
      anon_sym_PIPE,
    STATE(64), 1,
      aux_sym_union_type_repeat1,
    STATE(99), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(144), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [760] = 2,
    ACTIONS(202), 1,
      anon_sym_LF,
    ACTIONS(204), 5,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_PIPE,
      anon_sym_rescue,
  [771] = 2,
    ACTIONS(169), 1,
      anon_sym_LF,
    ACTIONS(171), 5,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_PIPE,
      anon_sym_rescue,
  [782] = 4,
    ACTIONS(206), 1,
      anon_sym_LF,
    ACTIONS(208), 1,
      anon_sym_SEMI,
    STATE(18), 1,
      sym__terminator,
    ACTIONS(210), 3,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [797] = 4,
    ACTIONS(182), 1,
      anon_sym_LPAREN,
    ACTIONS(184), 1,
      sym_constant,
    STATE(53), 2,
      sym__type,
      sym_union_type,
    STATE(141), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [812] = 4,
    ACTIONS(206), 1,
      anon_sym_LF,
    ACTIONS(208), 1,
      anon_sym_SEMI,
    STATE(18), 1,
      sym__terminator,
    ACTIONS(212), 3,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [827] = 4,
    ACTIONS(186), 1,
      anon_sym_LPAREN,
    ACTIONS(188), 1,
      sym_constant,
    STATE(128), 2,
      sym__nested_union_type,
      sym__inner_union_type,
    STATE(157), 2,
      sym__type,
      sym_union_type,
  [842] = 2,
    ACTIONS(214), 1,
      anon_sym_LF,
    ACTIONS(216), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [852] = 2,
    ACTIONS(218), 1,
      anon_sym_LF,
    ACTIONS(220), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [862] = 2,
    ACTIONS(222), 1,
      anon_sym_LF,
    ACTIONS(224), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [872] = 3,
    STATE(51), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(162), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(164), 2,
      anon_sym_SEMI,
      anon_sym_PIPE,
  [884] = 2,
    ACTIONS(226), 1,
      anon_sym_LF,
    ACTIONS(228), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [894] = 4,
    ACTIONS(230), 1,
      anon_sym_LF,
    ACTIONS(234), 1,
      aux_sym_identifier_token2,
    STATE(60), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(232), 2,
      anon_sym_SEMI,
      anon_sym_COLON,
  [908] = 2,
    ACTIONS(236), 1,
      anon_sym_LF,
    ACTIONS(238), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [918] = 4,
    ACTIONS(171), 1,
      anon_sym_SEMI,
    ACTIONS(240), 1,
      anon_sym_PIPE,
    STATE(49), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(169), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [932] = 2,
    ACTIONS(243), 1,
      anon_sym_LF,
    ACTIONS(245), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [942] = 4,
    ACTIONS(152), 1,
      anon_sym_SEMI,
    ACTIONS(247), 1,
      anon_sym_PIPE,
    STATE(52), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(150), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [956] = 4,
    ACTIONS(164), 1,
      anon_sym_SEMI,
    ACTIONS(249), 1,
      anon_sym_PIPE,
    STATE(52), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(162), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [970] = 2,
    ACTIONS(252), 1,
      anon_sym_LF,
    ACTIONS(254), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [980] = 4,
    ACTIONS(158), 1,
      anon_sym_SEMI,
    ACTIONS(256), 1,
      anon_sym_PIPE,
    STATE(51), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(156), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [994] = 2,
    ACTIONS(258), 1,
      anon_sym_LF,
    ACTIONS(260), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [1004] = 2,
    ACTIONS(262), 1,
      anon_sym_LF,
    ACTIONS(264), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [1014] = 2,
    ACTIONS(266), 1,
      anon_sym_LF,
    ACTIONS(268), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [1024] = 2,
    ACTIONS(270), 1,
      anon_sym_LF,
    ACTIONS(272), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [1034] = 2,
    ACTIONS(274), 1,
      anon_sym_LF,
    ACTIONS(276), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [1044] = 4,
    ACTIONS(278), 1,
      anon_sym_LF,
    ACTIONS(282), 1,
      aux_sym_identifier_token2,
    STATE(60), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(280), 2,
      anon_sym_SEMI,
      anon_sym_COLON,
  [1058] = 2,
    ACTIONS(285), 1,
      anon_sym_LF,
    ACTIONS(287), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [1068] = 2,
    ACTIONS(289), 1,
      anon_sym_LF,
    ACTIONS(291), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [1078] = 2,
    ACTIONS(293), 1,
      anon_sym_LF,
    ACTIONS(295), 4,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [1088] = 4,
    ACTIONS(178), 1,
      anon_sym_SEMI,
    ACTIONS(297), 1,
      anon_sym_PIPE,
    STATE(49), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(176), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1102] = 4,
    ACTIONS(299), 1,
      anon_sym_LF,
    ACTIONS(303), 1,
      aux_sym_identifier_token2,
    STATE(47), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(301), 2,
      anon_sym_SEMI,
      anon_sym_COLON,
  [1116] = 3,
    STATE(51), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(169), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(171), 2,
      anon_sym_SEMI,
      anon_sym_PIPE,
  [1128] = 2,
    ACTIONS(202), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(204), 2,
      anon_sym_SEMI,
      anon_sym_PIPE,
  [1137] = 4,
    ACTIONS(305), 1,
      anon_sym_LF,
    ACTIONS(307), 1,
      anon_sym_SEMI,
    ACTIONS(309), 1,
      anon_sym_COLON,
    STATE(15), 1,
      sym__terminator,
  [1150] = 3,
    ACTIONS(311), 1,
      anon_sym_LPAREN,
    ACTIONS(313), 1,
      sym_constant,
    STATE(132), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1161] = 3,
    ACTIONS(315), 1,
      anon_sym_LPAREN,
    ACTIONS(317), 1,
      sym_constant,
    STATE(45), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1172] = 3,
    ACTIONS(311), 1,
      anon_sym_LPAREN,
    ACTIONS(319), 1,
      sym_constant,
    STATE(131), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1183] = 3,
    ACTIONS(315), 1,
      anon_sym_LPAREN,
    ACTIONS(321), 1,
      sym_constant,
    STATE(85), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1194] = 3,
    ACTIONS(315), 1,
      anon_sym_LPAREN,
    ACTIONS(323), 1,
      sym_constant,
    STATE(66), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1205] = 3,
    ACTIONS(325), 1,
      anon_sym_LPAREN,
    ACTIONS(327), 1,
      sym_constant,
    STATE(28), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1216] = 3,
    ACTIONS(311), 1,
      anon_sym_LPAREN,
    ACTIONS(329), 1,
      sym_constant,
    STATE(127), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1227] = 3,
    ACTIONS(315), 1,
      anon_sym_LPAREN,
    ACTIONS(331), 1,
      sym_constant,
    STATE(35), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1238] = 3,
    ACTIONS(311), 1,
      anon_sym_LPAREN,
    ACTIONS(333), 1,
      sym_constant,
    STATE(112), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1249] = 3,
    ACTIONS(325), 1,
      anon_sym_LPAREN,
    ACTIONS(335), 1,
      sym_constant,
    STATE(37), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1260] = 3,
    ACTIONS(311), 1,
      anon_sym_LPAREN,
    ACTIONS(337), 1,
      sym_constant,
    STATE(134), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1271] = 4,
    ACTIONS(69), 1,
      ts_builtin_sym_end,
    ACTIONS(339), 1,
      anon_sym_LF,
    ACTIONS(341), 1,
      anon_sym_SEMI,
    STATE(19), 1,
      sym__terminator,
  [1284] = 2,
    ACTIONS(162), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(164), 2,
      anon_sym_SEMI,
      anon_sym_PIPE,
  [1293] = 3,
    ACTIONS(325), 1,
      anon_sym_LPAREN,
    ACTIONS(343), 1,
      sym_constant,
    STATE(26), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1304] = 3,
    ACTIONS(315), 1,
      anon_sym_LPAREN,
    ACTIONS(345), 1,
      sym_constant,
    STATE(81), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1315] = 4,
    ACTIONS(144), 1,
      anon_sym_RPAREN,
    ACTIONS(347), 1,
      anon_sym_PIPE,
    STATE(95), 1,
      aux_sym_union_type_repeat1,
    STATE(99), 1,
      aux_sym__inner_union_type_repeat1,
  [1328] = 2,
    ACTIONS(169), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(171), 2,
      anon_sym_SEMI,
      anon_sym_PIPE,
  [1337] = 3,
    ACTIONS(311), 1,
      anon_sym_LPAREN,
    ACTIONS(349), 1,
      sym_constant,
    STATE(116), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1348] = 4,
    ACTIONS(339), 1,
      anon_sym_LF,
    ACTIONS(341), 1,
      anon_sym_SEMI,
    ACTIONS(351), 1,
      ts_builtin_sym_end,
    STATE(19), 1,
      sym__terminator,
  [1361] = 3,
    ACTIONS(325), 1,
      anon_sym_LPAREN,
    ACTIONS(353), 1,
      sym_constant,
    STATE(30), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1372] = 3,
    ACTIONS(311), 1,
      anon_sym_LPAREN,
    ACTIONS(355), 1,
      sym_constant,
    STATE(133), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1383] = 3,
    ACTIONS(311), 1,
      anon_sym_LPAREN,
    ACTIONS(357), 1,
      sym_constant,
    STATE(84), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1394] = 3,
    ACTIONS(325), 1,
      anon_sym_LPAREN,
    ACTIONS(359), 1,
      sym_constant,
    STATE(21), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1405] = 3,
    ACTIONS(311), 1,
      anon_sym_LPAREN,
    ACTIONS(361), 1,
      sym_constant,
    STATE(125), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [1416] = 3,
    ACTIONS(196), 1,
      anon_sym_SEMI,
    ACTIONS(198), 1,
      anon_sym_PIPE,
    ACTIONS(194), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1427] = 2,
    ACTIONS(228), 1,
      anon_sym_SEMI,
    ACTIONS(226), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1435] = 3,
    ACTIONS(176), 1,
      anon_sym_RPAREN,
    ACTIONS(363), 1,
      anon_sym_PIPE,
    STATE(123), 1,
      aux_sym_union_type_repeat1,
  [1445] = 2,
    ACTIONS(268), 1,
      anon_sym_SEMI,
    ACTIONS(266), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1453] = 3,
    ACTIONS(365), 1,
      anon_sym_LF,
    ACTIONS(367), 1,
      anon_sym_SEMI,
    STATE(11), 1,
      sym__terminator,
  [1463] = 2,
    ACTIONS(295), 1,
      anon_sym_SEMI,
    ACTIONS(293), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1471] = 3,
    ACTIONS(150), 1,
      anon_sym_RPAREN,
    ACTIONS(369), 1,
      anon_sym_PIPE,
    STATE(102), 1,
      aux_sym__inner_union_type_repeat1,
  [1481] = 2,
    ACTIONS(254), 1,
      anon_sym_SEMI,
    ACTIONS(252), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1489] = 3,
    ACTIONS(206), 1,
      anon_sym_LF,
    ACTIONS(208), 1,
      anon_sym_SEMI,
    STATE(18), 1,
      sym__terminator,
  [1499] = 3,
    ACTIONS(162), 1,
      anon_sym_RPAREN,
    ACTIONS(371), 1,
      anon_sym_PIPE,
    STATE(102), 1,
      aux_sym__inner_union_type_repeat1,
  [1509] = 2,
    ACTIONS(245), 1,
      anon_sym_SEMI,
    ACTIONS(243), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1517] = 3,
    ACTIONS(339), 1,
      anon_sym_LF,
    ACTIONS(341), 1,
      anon_sym_SEMI,
    STATE(19), 1,
      sym__terminator,
  [1527] = 2,
    ACTIONS(260), 1,
      anon_sym_SEMI,
    ACTIONS(258), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1535] = 3,
    ACTIONS(63), 1,
      anon_sym_rescue,
    ACTIONS(374), 1,
      anon_sym_end,
    STATE(151), 1,
      sym_rescue_block,
  [1545] = 2,
    ACTIONS(224), 1,
      anon_sym_SEMI,
    ACTIONS(222), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1553] = 2,
    ACTIONS(272), 1,
      anon_sym_SEMI,
    ACTIONS(270), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1561] = 3,
    ACTIONS(63), 1,
      anon_sym_rescue,
    ACTIONS(376), 1,
      anon_sym_end,
    STATE(135), 1,
      sym_rescue_block,
  [1571] = 3,
    ACTIONS(63), 1,
      anon_sym_rescue,
    ACTIONS(378), 1,
      anon_sym_end,
    STATE(159), 1,
      sym_rescue_block,
  [1581] = 2,
    ACTIONS(216), 1,
      anon_sym_SEMI,
    ACTIONS(214), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1589] = 3,
    ACTIONS(156), 1,
      anon_sym_RPAREN,
    ACTIONS(380), 1,
      anon_sym_PIPE,
    STATE(99), 1,
      aux_sym__inner_union_type_repeat1,
  [1599] = 2,
    ACTIONS(264), 1,
      anon_sym_SEMI,
    ACTIONS(262), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1607] = 3,
    ACTIONS(382), 1,
      anon_sym_LF,
    ACTIONS(384), 1,
      anon_sym_SEMI,
    STATE(14), 1,
      sym__terminator,
  [1617] = 3,
    ACTIONS(386), 1,
      anon_sym_LF,
    ACTIONS(388), 1,
      anon_sym_SEMI,
    STATE(9), 1,
      sym__terminator,
  [1627] = 2,
    STATE(99), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(162), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1635] = 2,
    ACTIONS(238), 1,
      anon_sym_SEMI,
    ACTIONS(236), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1643] = 2,
    ACTIONS(276), 1,
      anon_sym_SEMI,
    ACTIONS(274), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1651] = 2,
    ACTIONS(287), 1,
      anon_sym_SEMI,
    ACTIONS(285), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1659] = 2,
    ACTIONS(291), 1,
      anon_sym_SEMI,
    ACTIONS(289), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1667] = 3,
    ACTIONS(390), 1,
      anon_sym_LF,
    ACTIONS(392), 1,
      anon_sym_SEMI,
    STATE(12), 1,
      sym__terminator,
  [1677] = 3,
    ACTIONS(63), 1,
      anon_sym_rescue,
    ACTIONS(394), 1,
      anon_sym_end,
    STATE(136), 1,
      sym_rescue_block,
  [1687] = 3,
    ACTIONS(169), 1,
      anon_sym_RPAREN,
    ACTIONS(396), 1,
      anon_sym_PIPE,
    STATE(123), 1,
      aux_sym_union_type_repeat1,
  [1697] = 2,
    ACTIONS(220), 1,
      anon_sym_SEMI,
    ACTIONS(218), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [1705] = 2,
    STATE(99), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(169), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1713] = 1,
    ACTIONS(399), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [1718] = 2,
    ACTIONS(401), 1,
      anon_sym_RPAREN,
    ACTIONS(403), 1,
      anon_sym_PIPE,
  [1725] = 2,
    ACTIONS(401), 1,
      anon_sym_RPAREN,
    ACTIONS(405), 1,
      anon_sym_PIPE,
  [1732] = 1,
    ACTIONS(202), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1737] = 1,
    ACTIONS(407), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [1742] = 2,
    ACTIONS(403), 1,
      anon_sym_PIPE,
    ACTIONS(409), 1,
      anon_sym_RPAREN,
  [1749] = 2,
    ACTIONS(403), 1,
      anon_sym_PIPE,
    ACTIONS(411), 1,
      anon_sym_RPAREN,
  [1756] = 1,
    ACTIONS(169), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1761] = 1,
    ACTIONS(162), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1766] = 1,
    ACTIONS(413), 1,
      anon_sym_end,
  [1770] = 1,
    ACTIONS(415), 1,
      anon_sym_end,
  [1774] = 1,
    ACTIONS(417), 1,
      anon_sym_RPAREN,
  [1778] = 1,
    ACTIONS(419), 1,
      anon_sym_end,
  [1782] = 1,
    ACTIONS(421), 1,
      anon_sym_RPAREN,
  [1786] = 1,
    ACTIONS(423), 1,
      anon_sym_SQUOTE2,
  [1790] = 1,
    ACTIONS(425), 1,
      anon_sym_PIPE,
  [1794] = 1,
    ACTIONS(427), 1,
      anon_sym_end,
  [1798] = 1,
    ACTIONS(429), 1,
      ts_builtin_sym_end,
  [1802] = 1,
    ACTIONS(431), 1,
      ts_builtin_sym_end,
  [1806] = 1,
    ACTIONS(433), 1,
      anon_sym_end,
  [1810] = 1,
    ACTIONS(435), 1,
      anon_sym_end,
  [1814] = 1,
    ACTIONS(437), 1,
      anon_sym_EQ,
  [1818] = 1,
    ACTIONS(439), 1,
      anon_sym_end,
  [1822] = 1,
    ACTIONS(441), 1,
      anon_sym_RPAREN,
  [1826] = 1,
    ACTIONS(443), 1,
      anon_sym_end,
  [1830] = 1,
    ACTIONS(445), 1,
      anon_sym_end,
  [1834] = 1,
    ACTIONS(447), 1,
      anon_sym_end,
  [1838] = 1,
    ACTIONS(449), 1,
      anon_sym_end,
  [1842] = 1,
    ACTIONS(451), 1,
      anon_sym_end,
  [1846] = 1,
    ACTIONS(453), 1,
      anon_sym_SQUOTE2,
  [1850] = 1,
    ACTIONS(455), 1,
      anon_sym_RPAREN,
  [1854] = 1,
    ACTIONS(457), 1,
      anon_sym_RPAREN,
  [1858] = 1,
    ACTIONS(270), 1,
      anon_sym_RPAREN,
  [1862] = 1,
    ACTIONS(459), 1,
      anon_sym_end,
  [1866] = 1,
    ACTIONS(461), 1,
      anon_sym_EQ,
  [1870] = 1,
    ACTIONS(463), 1,
      sym_constant,
  [1874] = 1,
    ACTIONS(465), 1,
      anon_sym_PIPE,
  [1878] = 1,
    ACTIONS(467), 1,
      anon_sym_end,
  [1882] = 1,
    ACTIONS(469), 1,
      sym_constant,
  [1886] = 1,
    ACTIONS(471), 1,
      sym_constant,
  [1890] = 1,
    ACTIONS(473), 1,
      sym_constant,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(8)] = 0,
  [SMALL_STATE(9)] = 47,
  [SMALL_STATE(10)] = 94,
  [SMALL_STATE(11)] = 141,
  [SMALL_STATE(12)] = 188,
  [SMALL_STATE(13)] = 235,
  [SMALL_STATE(14)] = 282,
  [SMALL_STATE(15)] = 329,
  [SMALL_STATE(16)] = 376,
  [SMALL_STATE(17)] = 420,
  [SMALL_STATE(18)] = 464,
  [SMALL_STATE(19)] = 484,
  [SMALL_STATE(20)] = 502,
  [SMALL_STATE(21)] = 532,
  [SMALL_STATE(22)] = 551,
  [SMALL_STATE(23)] = 567,
  [SMALL_STATE(24)] = 583,
  [SMALL_STATE(25)] = 599,
  [SMALL_STATE(26)] = 615,
  [SMALL_STATE(27)] = 629,
  [SMALL_STATE(28)] = 645,
  [SMALL_STATE(29)] = 659,
  [SMALL_STATE(30)] = 674,
  [SMALL_STATE(31)] = 685,
  [SMALL_STATE(32)] = 700,
  [SMALL_STATE(33)] = 715,
  [SMALL_STATE(34)] = 730,
  [SMALL_STATE(35)] = 743,
  [SMALL_STATE(36)] = 760,
  [SMALL_STATE(37)] = 771,
  [SMALL_STATE(38)] = 782,
  [SMALL_STATE(39)] = 797,
  [SMALL_STATE(40)] = 812,
  [SMALL_STATE(41)] = 827,
  [SMALL_STATE(42)] = 842,
  [SMALL_STATE(43)] = 852,
  [SMALL_STATE(44)] = 862,
  [SMALL_STATE(45)] = 872,
  [SMALL_STATE(46)] = 884,
  [SMALL_STATE(47)] = 894,
  [SMALL_STATE(48)] = 908,
  [SMALL_STATE(49)] = 918,
  [SMALL_STATE(50)] = 932,
  [SMALL_STATE(51)] = 942,
  [SMALL_STATE(52)] = 956,
  [SMALL_STATE(53)] = 970,
  [SMALL_STATE(54)] = 980,
  [SMALL_STATE(55)] = 994,
  [SMALL_STATE(56)] = 1004,
  [SMALL_STATE(57)] = 1014,
  [SMALL_STATE(58)] = 1024,
  [SMALL_STATE(59)] = 1034,
  [SMALL_STATE(60)] = 1044,
  [SMALL_STATE(61)] = 1058,
  [SMALL_STATE(62)] = 1068,
  [SMALL_STATE(63)] = 1078,
  [SMALL_STATE(64)] = 1088,
  [SMALL_STATE(65)] = 1102,
  [SMALL_STATE(66)] = 1116,
  [SMALL_STATE(67)] = 1128,
  [SMALL_STATE(68)] = 1137,
  [SMALL_STATE(69)] = 1150,
  [SMALL_STATE(70)] = 1161,
  [SMALL_STATE(71)] = 1172,
  [SMALL_STATE(72)] = 1183,
  [SMALL_STATE(73)] = 1194,
  [SMALL_STATE(74)] = 1205,
  [SMALL_STATE(75)] = 1216,
  [SMALL_STATE(76)] = 1227,
  [SMALL_STATE(77)] = 1238,
  [SMALL_STATE(78)] = 1249,
  [SMALL_STATE(79)] = 1260,
  [SMALL_STATE(80)] = 1271,
  [SMALL_STATE(81)] = 1284,
  [SMALL_STATE(82)] = 1293,
  [SMALL_STATE(83)] = 1304,
  [SMALL_STATE(84)] = 1315,
  [SMALL_STATE(85)] = 1328,
  [SMALL_STATE(86)] = 1337,
  [SMALL_STATE(87)] = 1348,
  [SMALL_STATE(88)] = 1361,
  [SMALL_STATE(89)] = 1372,
  [SMALL_STATE(90)] = 1383,
  [SMALL_STATE(91)] = 1394,
  [SMALL_STATE(92)] = 1405,
  [SMALL_STATE(93)] = 1416,
  [SMALL_STATE(94)] = 1427,
  [SMALL_STATE(95)] = 1435,
  [SMALL_STATE(96)] = 1445,
  [SMALL_STATE(97)] = 1453,
  [SMALL_STATE(98)] = 1463,
  [SMALL_STATE(99)] = 1471,
  [SMALL_STATE(100)] = 1481,
  [SMALL_STATE(101)] = 1489,
  [SMALL_STATE(102)] = 1499,
  [SMALL_STATE(103)] = 1509,
  [SMALL_STATE(104)] = 1517,
  [SMALL_STATE(105)] = 1527,
  [SMALL_STATE(106)] = 1535,
  [SMALL_STATE(107)] = 1545,
  [SMALL_STATE(108)] = 1553,
  [SMALL_STATE(109)] = 1561,
  [SMALL_STATE(110)] = 1571,
  [SMALL_STATE(111)] = 1581,
  [SMALL_STATE(112)] = 1589,
  [SMALL_STATE(113)] = 1599,
  [SMALL_STATE(114)] = 1607,
  [SMALL_STATE(115)] = 1617,
  [SMALL_STATE(116)] = 1627,
  [SMALL_STATE(117)] = 1635,
  [SMALL_STATE(118)] = 1643,
  [SMALL_STATE(119)] = 1651,
  [SMALL_STATE(120)] = 1659,
  [SMALL_STATE(121)] = 1667,
  [SMALL_STATE(122)] = 1677,
  [SMALL_STATE(123)] = 1687,
  [SMALL_STATE(124)] = 1697,
  [SMALL_STATE(125)] = 1705,
  [SMALL_STATE(126)] = 1713,
  [SMALL_STATE(127)] = 1718,
  [SMALL_STATE(128)] = 1725,
  [SMALL_STATE(129)] = 1732,
  [SMALL_STATE(130)] = 1737,
  [SMALL_STATE(131)] = 1742,
  [SMALL_STATE(132)] = 1749,
  [SMALL_STATE(133)] = 1756,
  [SMALL_STATE(134)] = 1761,
  [SMALL_STATE(135)] = 1766,
  [SMALL_STATE(136)] = 1770,
  [SMALL_STATE(137)] = 1774,
  [SMALL_STATE(138)] = 1778,
  [SMALL_STATE(139)] = 1782,
  [SMALL_STATE(140)] = 1786,
  [SMALL_STATE(141)] = 1790,
  [SMALL_STATE(142)] = 1794,
  [SMALL_STATE(143)] = 1798,
  [SMALL_STATE(144)] = 1802,
  [SMALL_STATE(145)] = 1806,
  [SMALL_STATE(146)] = 1810,
  [SMALL_STATE(147)] = 1814,
  [SMALL_STATE(148)] = 1818,
  [SMALL_STATE(149)] = 1822,
  [SMALL_STATE(150)] = 1826,
  [SMALL_STATE(151)] = 1830,
  [SMALL_STATE(152)] = 1834,
  [SMALL_STATE(153)] = 1838,
  [SMALL_STATE(154)] = 1842,
  [SMALL_STATE(155)] = 1846,
  [SMALL_STATE(156)] = 1850,
  [SMALL_STATE(157)] = 1854,
  [SMALL_STATE(158)] = 1858,
  [SMALL_STATE(159)] = 1862,
  [SMALL_STATE(160)] = 1866,
  [SMALL_STATE(161)] = 1870,
  [SMALL_STATE(162)] = 1874,
  [SMALL_STATE(163)] = 1878,
  [SMALL_STATE(164)] = 1882,
  [SMALL_STATE(165)] = 1886,
  [SMALL_STATE(166)] = 1890,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(124),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(166),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 1),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(7),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(13),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(101),
  [86] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(101),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(130),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(165),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(166),
  [98] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(3),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 5, .production_id = 14),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 2),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 3, .production_id = 7),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 3, .production_id = 6),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [123] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(17),
  [126] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(104),
  [129] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(104),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [136] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [142] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_union_type, 3),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_union_type, 3),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__inner_union_type, 4),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__inner_union_type, 4),
  [154] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__inner_union_type, 3),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__inner_union_type, 3),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__inner_union_type_repeat1, 2),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__inner_union_type_repeat1, 2),
  [166] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__inner_union_type_repeat1, 2), SHIFT_REPEAT(88),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_union_type_repeat1, 2),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_union_type_repeat1, 2),
  [173] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_union_type_repeat1, 2), SHIFT_REPEAT(78),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_union_type, 4),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_union_type, 4),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type, 1),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__type, 1),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__nested_union_type, 1),
  [200] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__nested_union_type, 3),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__nested_union_type, 3),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [208] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 2),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 3),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 3),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 2),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 2),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 3, .production_id = 1),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 3, .production_id = 1),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char, 3),
  [228] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char, 3),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 2),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 2),
  [234] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 3),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__parenthesized_statements, 3),
  [240] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_union_type_repeat1, 2), SHIFT_REPEAT(72),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 4, .production_id = 3),
  [245] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_module, 4, .production_id = 3),
  [247] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [249] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__inner_union_type_repeat1, 2), SHIFT_REPEAT(83),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alias, 4, .production_id = 4),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_alias, 4, .production_id = 4),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 3, .production_id = 2),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 3, .production_id = 2),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 2),
  [264] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__parenthesized_statements, 2),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 4, .production_id = 5),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 4, .production_id = 5),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type, 3),
  [272] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__type, 3),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 4, .production_id = 8),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 4, .production_id = 8),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2),
  [280] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2),
  [282] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2), SHIFT_REPEAT(60),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 4, .production_id = 9),
  [287] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 4, .production_id = 9),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 5, .production_id = 10),
  [291] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_module, 5, .production_id = 10),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 5, .production_id = 13),
  [295] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_begin_block, 5, .production_id = 13),
  [297] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1),
  [301] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1),
  [303] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [307] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [309] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [341] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [367] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [371] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__inner_union_type_repeat1, 2), SHIFT_REPEAT(79),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [384] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [388] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [392] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [396] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_union_type_repeat1, 2), SHIFT_REPEAT(89),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [419] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 4, .production_id = 11),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [429] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [431] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 6, .production_id = 15),
  [449] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 3, .production_id = 5),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 4, .production_id = 12),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
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
