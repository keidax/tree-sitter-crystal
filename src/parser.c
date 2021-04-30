#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 249
#define LARGE_STATE_COUNT 41
#define SYMBOL_COUNT 62
#define ALIAS_COUNT 0
#define TOKEN_COUNT 36
#define EXTERNAL_TOKEN_COUNT 5
#define FIELD_COUNT 8
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 26

enum {
  anon_sym_SEMI = 1,
  anon_sym_LPAREN = 2,
  anon_sym_RPAREN = 3,
  sym_nil = 4,
  sym_true = 5,
  sym_false = 6,
  aux_sym_integer_token1 = 7,
  aux_sym_integer_token2 = 8,
  aux_sym_float_token1 = 9,
  aux_sym_float_token2 = 10,
  anon_sym_SQUOTE = 11,
  aux_sym_char_token1 = 12,
  anon_sym_SQUOTE2 = 13,
  sym_char_escape_sequence = 14,
  anon_sym_module = 15,
  anon_sym_end = 16,
  sym_constant = 17,
  sym_identifier = 18,
  sym_identifier_method_call = 19,
  sym_self = 20,
  anon_sym_PIPE = 21,
  anon_sym_DOT = 22,
  anon_sym_AMP_PLUS = 23,
  anon_sym_AMP_DASH = 24,
  anon_sym_COMMA = 25,
  anon_sym_alias = 26,
  anon_sym_EQ = 27,
  anon_sym_begin = 28,
  anon_sym_rescue = 29,
  anon_sym_COLON = 30,
  sym__line_break = 31,
  sym_unary_plus = 32,
  sym_unary_minus = 33,
  sym_binary_plus = 34,
  sym_binary_minus = 35,
  sym_source_file = 36,
  sym__terminator = 37,
  sym__statements = 38,
  sym__parenthesized_statements = 39,
  sym__statement = 40,
  sym__expression = 41,
  sym_integer = 42,
  sym_float = 43,
  sym_char = 44,
  sym_module = 45,
  sym__type = 46,
  sym_union_type = 47,
  sym__nested_union_type = 48,
  sym__inner_union_type = 49,
  sym_call = 50,
  sym_additive_operator = 51,
  sym_unary_additive_operator = 52,
  sym_argument_list = 53,
  sym_argument_list_with_trailing_comma = 54,
  sym_alias = 55,
  sym_begin_block = 56,
  sym_rescue_block = 57,
  aux_sym__statements_repeat1 = 58,
  aux_sym_union_type_repeat1 = 59,
  aux_sym__inner_union_type_repeat1 = 60,
  aux_sym_argument_list_repeat1 = 61,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SEMI] = ";",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_nil] = "nil",
  [sym_true] = "true",
  [sym_false] = "false",
  [aux_sym_integer_token1] = "integer_token1",
  [aux_sym_integer_token2] = "integer_token2",
  [aux_sym_float_token1] = "float_token1",
  [aux_sym_float_token2] = "float_token2",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_char_token1] = "char_token1",
  [anon_sym_SQUOTE2] = "'",
  [sym_char_escape_sequence] = "char_escape_sequence",
  [anon_sym_module] = "module",
  [anon_sym_end] = "end",
  [sym_constant] = "constant",
  [sym_identifier] = "identifier",
  [sym_identifier_method_call] = "identifier",
  [sym_self] = "self",
  [anon_sym_PIPE] = "|",
  [anon_sym_DOT] = ".",
  [anon_sym_AMP_PLUS] = "identifier",
  [anon_sym_AMP_DASH] = "identifier",
  [anon_sym_COMMA] = ",",
  [anon_sym_alias] = "alias",
  [anon_sym_EQ] = "=",
  [anon_sym_begin] = "begin",
  [anon_sym_rescue] = "rescue",
  [anon_sym_COLON] = ": ",
  [sym__line_break] = "_line_break",
  [sym_unary_plus] = "+",
  [sym_unary_minus] = "-",
  [sym_binary_plus] = "identifier",
  [sym_binary_minus] = "identifier",
  [sym_source_file] = "source_file",
  [sym__terminator] = "_terminator",
  [sym__statements] = "_statements",
  [sym__parenthesized_statements] = "_parenthesized_statements",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym_integer] = "integer",
  [sym_float] = "float",
  [sym_char] = "char",
  [sym_module] = "module",
  [sym__type] = "_type",
  [sym_union_type] = "union_type",
  [sym__nested_union_type] = "_nested_union_type",
  [sym__inner_union_type] = "_inner_union_type",
  [sym_call] = "call",
  [sym_additive_operator] = "call",
  [sym_unary_additive_operator] = "call",
  [sym_argument_list] = "argument_list",
  [sym_argument_list_with_trailing_comma] = "argument_list",
  [sym_alias] = "alias",
  [sym_begin_block] = "begin_block",
  [sym_rescue_block] = "rescue_block",
  [aux_sym__statements_repeat1] = "_statements_repeat1",
  [aux_sym_union_type_repeat1] = "union_type_repeat1",
  [aux_sym__inner_union_type_repeat1] = "_inner_union_type_repeat1",
  [aux_sym_argument_list_repeat1] = "argument_list_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_nil] = sym_nil,
  [sym_true] = sym_true,
  [sym_false] = sym_false,
  [aux_sym_integer_token1] = aux_sym_integer_token1,
  [aux_sym_integer_token2] = aux_sym_integer_token2,
  [aux_sym_float_token1] = aux_sym_float_token1,
  [aux_sym_float_token2] = aux_sym_float_token2,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_char_token1] = aux_sym_char_token1,
  [anon_sym_SQUOTE2] = anon_sym_SQUOTE,
  [sym_char_escape_sequence] = sym_char_escape_sequence,
  [anon_sym_module] = anon_sym_module,
  [anon_sym_end] = anon_sym_end,
  [sym_constant] = sym_constant,
  [sym_identifier] = sym_identifier,
  [sym_identifier_method_call] = sym_identifier,
  [sym_self] = sym_self,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_AMP_PLUS] = sym_identifier,
  [anon_sym_AMP_DASH] = sym_identifier,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_alias] = anon_sym_alias,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_begin] = anon_sym_begin,
  [anon_sym_rescue] = anon_sym_rescue,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym__line_break] = sym__line_break,
  [sym_unary_plus] = sym_unary_plus,
  [sym_unary_minus] = sym_unary_minus,
  [sym_binary_plus] = sym_identifier,
  [sym_binary_minus] = sym_identifier,
  [sym_source_file] = sym_source_file,
  [sym__terminator] = sym__terminator,
  [sym__statements] = sym__statements,
  [sym__parenthesized_statements] = sym__parenthesized_statements,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym_integer] = sym_integer,
  [sym_float] = sym_float,
  [sym_char] = sym_char,
  [sym_module] = sym_module,
  [sym__type] = sym__type,
  [sym_union_type] = sym_union_type,
  [sym__nested_union_type] = sym__nested_union_type,
  [sym__inner_union_type] = sym__inner_union_type,
  [sym_call] = sym_call,
  [sym_additive_operator] = sym_call,
  [sym_unary_additive_operator] = sym_call,
  [sym_argument_list] = sym_argument_list,
  [sym_argument_list_with_trailing_comma] = sym_argument_list,
  [sym_alias] = sym_alias,
  [sym_begin_block] = sym_begin_block,
  [sym_rescue_block] = sym_rescue_block,
  [aux_sym__statements_repeat1] = aux_sym__statements_repeat1,
  [aux_sym_union_type_repeat1] = aux_sym_union_type_repeat1,
  [aux_sym__inner_union_type_repeat1] = aux_sym__inner_union_type_repeat1,
  [aux_sym_argument_list_repeat1] = aux_sym_argument_list_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
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
  [aux_sym_integer_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_integer_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_float_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_float_token2] = {
    .visible = false,
    .named = false,
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
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier_method_call] = {
    .visible = true,
    .named = true,
  },
  [sym_self] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_PLUS] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_AMP_DASH] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
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
  [sym__line_break] = {
    .visible = false,
    .named = true,
  },
  [sym_unary_plus] = {
    .visible = true,
    .named = false,
  },
  [sym_unary_minus] = {
    .visible = true,
    .named = false,
  },
  [sym_binary_plus] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_minus] = {
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
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_float] = {
    .visible = true,
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
  [sym_call] = {
    .visible = true,
    .named = true,
  },
  [sym_additive_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_additive_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_argument_list] = {
    .visible = true,
    .named = true,
  },
  [sym_argument_list_with_trailing_comma] = {
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
  [aux_sym_union_type_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__inner_union_type_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_argument_list_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_arguments = 1,
  field_body = 2,
  field_method = 3,
  field_name = 4,
  field_receiver = 5,
  field_rescue = 6,
  field_type = 7,
  field_variable = 8,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_arguments] = "arguments",
  [field_body] = "body",
  [field_method] = "method",
  [field_name] = "name",
  [field_receiver] = "receiver",
  [field_rescue] = "rescue",
  [field_type] = "type",
  [field_variable] = "variable",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [4] = {.index = 5, .length = 3},
  [5] = {.index = 8, .length = 1},
  [6] = {.index = 9, .length = 1},
  [7] = {.index = 10, .length = 3},
  [8] = {.index = 13, .length = 3},
  [9] = {.index = 16, .length = 1},
  [10] = {.index = 17, .length = 4},
  [11] = {.index = 21, .length = 2},
  [12] = {.index = 23, .length = 1},
  [13] = {.index = 24, .length = 1},
  [14] = {.index = 25, .length = 1},
  [15] = {.index = 26, .length = 1},
  [16] = {.index = 27, .length = 2},
  [17] = {.index = 29, .length = 4},
  [18] = {.index = 33, .length = 2},
  [19] = {.index = 35, .length = 2},
  [20] = {.index = 37, .length = 2},
  [21] = {.index = 39, .length = 2},
  [22] = {.index = 41, .length = 5},
  [23] = {.index = 46, .length = 2},
  [24] = {.index = 48, .length = 6},
  [25] = {.index = 54, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_method, 0},
  [1] =
    {field_method, 0},
    {field_receiver, 1},
  [3] =
    {field_arguments, 1},
    {field_method, 0},
  [5] =
    {field_arguments, 1},
    {field_arguments, 2},
    {field_method, 0},
  [8] =
    {field_body, 1},
  [9] =
    {field_rescue, 1},
  [10] =
    {field_arguments, 2},
    {field_method, 1},
    {field_receiver, 0},
  [13] =
    {field_method, 2},
    {field_receiver, 0},
    {field_receiver, 1},
  [16] =
    {field_name, 1},
  [17] =
    {field_arguments, 1},
    {field_arguments, 2},
    {field_arguments, 3},
    {field_method, 0},
  [21] =
    {field_name, 1},
    {field_type, 3},
  [23] =
    {field_variable, 1},
  [24] =
    {field_body, 2},
  [25] =
    {field_type, 1},
  [26] =
    {field_rescue, 2},
  [27] =
    {field_body, 1},
    {field_rescue, 2},
  [29] =
    {field_arguments, 3},
    {field_method, 2},
    {field_receiver, 0},
    {field_receiver, 1},
  [33] =
    {field_body, 3},
    {field_name, 1},
  [35] =
    {field_body, 3},
    {field_variable, 1},
  [37] =
    {field_body, 3},
    {field_type, 1},
  [39] =
    {field_body, 2},
    {field_rescue, 3},
  [41] =
    {field_arguments, 3},
    {field_arguments, 4},
    {field_method, 2},
    {field_receiver, 0},
    {field_receiver, 1},
  [46] =
    {field_type, 3},
    {field_variable, 1},
  [48] =
    {field_arguments, 3},
    {field_arguments, 4},
    {field_arguments, 5},
    {field_method, 2},
    {field_receiver, 0},
    {field_receiver, 1},
  [54] =
    {field_body, 5},
    {field_type, 3},
    {field_variable, 1},
};

static TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [2] = {
    [0] = sym_identifier,
  },
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
      if (eof) ADVANCE(57);
      if (lookahead == '&') ADVANCE(9);
      if (lookahead == '\'') ADVANCE(86);
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == ')') ADVANCE(60);
      if (lookahead == ',') ADVANCE(131);
      if (lookahead == '.') ADVANCE(128);
      if (lookahead == '0') ADVANCE(65);
      if (lookahead == ':') ADVANCE(1);
      if (lookahead == ';') ADVANCE(58);
      if (lookahead == '=') ADVANCE(133);
      if (lookahead == '\\') ADVANCE(44);
      if (lookahead == 'a') ADVANCE(111);
      if (lookahead == 'b') ADVANCE(97);
      if (lookahead == 'e') ADVANCE(114);
      if (lookahead == 'f') ADVANCE(92);
      if (lookahead == 'm') ADVANCE(116);
      if (lookahead == 'n') ADVANCE(108);
      if (lookahead == 'r') ADVANCE(98);
      if (lookahead == 's') ADVANCE(103);
      if (lookahead == 't') ADVANCE(117);
      if (lookahead == '|') ADVANCE(127);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(53)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(66);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(137);
      if (lookahead == ':') ADVANCE(51);
      END_STATE();
    case 2:
      if (lookahead == '&') ADVANCE(9);
      if (lookahead == '\'') ADVANCE(84);
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == ',') ADVANCE(131);
      if (lookahead == '.') ADVANCE(128);
      if (lookahead == '0') ADVANCE(71);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead == ';') ADVANCE(58);
      if (lookahead == 'b') ADVANCE(97);
      if (lookahead == 'e') ADVANCE(114);
      if (lookahead == 'f') ADVANCE(92);
      if (lookahead == 'n') ADVANCE(108);
      if (lookahead == 'r') ADVANCE(98);
      if (lookahead == 's') ADVANCE(103);
      if (lookahead == 't') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 3:
      if (lookahead == '&') ADVANCE(9);
      if (lookahead == '\'') ADVANCE(84);
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == ',') ADVANCE(131);
      if (lookahead == '.') ADVANCE(128);
      if (lookahead == '0') ADVANCE(71);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead == ';') ADVANCE(58);
      if (lookahead == 'b') ADVANCE(97);
      if (lookahead == 'e') ADVANCE(114);
      if (lookahead == 'f') ADVANCE(92);
      if (lookahead == 'n') ADVANCE(108);
      if (lookahead == 's') ADVANCE(103);
      if (lookahead == 't') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(84);
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == '0') ADVANCE(65);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead == 'b') ADVANCE(97);
      if (lookahead == 'f') ADVANCE(92);
      if (lookahead == 'n') ADVANCE(108);
      if (lookahead == 's') ADVANCE(103);
      if (lookahead == 't') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(66);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 5:
      if (lookahead == '\'') ADVANCE(84);
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == '0') ADVANCE(71);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead == ';') ADVANCE(58);
      if (lookahead == 'a') ADVANCE(111);
      if (lookahead == 'b') ADVANCE(97);
      if (lookahead == 'e') ADVANCE(114);
      if (lookahead == 'f') ADVANCE(92);
      if (lookahead == 'm') ADVANCE(116);
      if (lookahead == 'n') ADVANCE(108);
      if (lookahead == 'r') ADVANCE(98);
      if (lookahead == 's') ADVANCE(103);
      if (lookahead == 't') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 6:
      if (lookahead == '\'') ADVANCE(84);
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == '0') ADVANCE(71);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead == ';') ADVANCE(58);
      if (lookahead == 'a') ADVANCE(111);
      if (lookahead == 'b') ADVANCE(97);
      if (lookahead == 'e') ADVANCE(114);
      if (lookahead == 'f') ADVANCE(92);
      if (lookahead == 'm') ADVANCE(116);
      if (lookahead == 'n') ADVANCE(108);
      if (lookahead == 's') ADVANCE(103);
      if (lookahead == 't') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(84);
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == '0') ADVANCE(71);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead == 'b') ADVANCE(97);
      if (lookahead == 'f') ADVANCE(92);
      if (lookahead == 'n') ADVANCE(108);
      if (lookahead == 's') ADVANCE(103);
      if (lookahead == 't') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 8:
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead == ';') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 9:
      if (lookahead == '+') ADVANCE(129);
      if (lookahead == '-') ADVANCE(130);
      END_STATE();
    case 10:
      if (lookahead == '1') ADVANCE(14);
      if (lookahead == '3') ADVANCE(12);
      if (lookahead == '6') ADVANCE(20);
      if (lookahead == '8') ADVANCE(64);
      END_STATE();
    case 11:
      if (lookahead == '1') ADVANCE(17);
      if (lookahead == '3') ADVANCE(15);
      if (lookahead == '6') ADVANCE(22);
      if (lookahead == '8') ADVANCE(70);
      END_STATE();
    case 12:
      if (lookahead == '2') ADVANCE(64);
      END_STATE();
    case 13:
      if (lookahead == '2') ADVANCE(76);
      END_STATE();
    case 14:
      if (lookahead == '2') ADVANCE(24);
      if (lookahead == '6') ADVANCE(64);
      END_STATE();
    case 15:
      if (lookahead == '2') ADVANCE(70);
      END_STATE();
    case 16:
      if (lookahead == '2') ADVANCE(80);
      END_STATE();
    case 17:
      if (lookahead == '2') ADVANCE(25);
      if (lookahead == '6') ADVANCE(70);
      END_STATE();
    case 18:
      if (lookahead == '3') ADVANCE(13);
      if (lookahead == '6') ADVANCE(21);
      END_STATE();
    case 19:
      if (lookahead == '3') ADVANCE(16);
      if (lookahead == '6') ADVANCE(23);
      END_STATE();
    case 20:
      if (lookahead == '4') ADVANCE(64);
      END_STATE();
    case 21:
      if (lookahead == '4') ADVANCE(76);
      END_STATE();
    case 22:
      if (lookahead == '4') ADVANCE(70);
      END_STATE();
    case 23:
      if (lookahead == '4') ADVANCE(80);
      END_STATE();
    case 24:
      if (lookahead == '8') ADVANCE(64);
      END_STATE();
    case 25:
      if (lookahead == '8') ADVANCE(70);
      END_STATE();
    case 26:
      if (lookahead == ':') ADVANCE(51);
      END_STATE();
    case 27:
      if (lookahead == '\\') ADVANCE(44);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 28:
      if (lookahead == 'c') ADVANCE(34);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(89);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(33);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(135);
      END_STATE();
    case 32:
      if (lookahead == 'n') ADVANCE(29);
      END_STATE();
    case 33:
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 34:
      if (lookahead == 'u') ADVANCE(31);
      END_STATE();
    case 35:
      if (lookahead == '{') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 36:
      if (lookahead == '}') ADVANCE(87);
      END_STATE();
    case 37:
      if (lookahead == '}') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      END_STATE();
    case 38:
      if (lookahead == '}') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    case 39:
      if (lookahead == '}') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(38);
      END_STATE();
    case 40:
      if (lookahead == '}') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 41:
      if (lookahead == '}') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(40);
      END_STATE();
    case 42:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      END_STATE();
    case 43:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(82);
      END_STATE();
    case 44:
      if (sym_char_escape_sequence_character_set_1(lookahead)) ADVANCE(87);
      if (lookahead == 'u') ADVANCE(35);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(79);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(83);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(87);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(41);
      END_STATE();
    case 49:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 50:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 51:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      END_STATE();
    case 52:
      if (eof) ADVANCE(57);
      if (lookahead == '&') ADVANCE(9);
      if (lookahead == '\'') ADVANCE(86);
      if (lookahead == ')') ADVANCE(60);
      if (lookahead == ',') ADVANCE(131);
      if (lookahead == '.') ADVANCE(128);
      if (lookahead == ';') ADVANCE(58);
      if (lookahead == 'e') ADVANCE(32);
      if (lookahead == 'r') ADVANCE(30);
      if (lookahead == '|') ADVANCE(127);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(55)
      END_STATE();
    case 53:
      if (eof) ADVANCE(57);
      if (lookahead == '&') ADVANCE(9);
      if (lookahead == '\'') ADVANCE(84);
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == ')') ADVANCE(60);
      if (lookahead == ',') ADVANCE(131);
      if (lookahead == '.') ADVANCE(128);
      if (lookahead == '0') ADVANCE(71);
      if (lookahead == ':') ADVANCE(1);
      if (lookahead == ';') ADVANCE(58);
      if (lookahead == '=') ADVANCE(133);
      if (lookahead == 'a') ADVANCE(111);
      if (lookahead == 'b') ADVANCE(97);
      if (lookahead == 'e') ADVANCE(114);
      if (lookahead == 'f') ADVANCE(92);
      if (lookahead == 'm') ADVANCE(116);
      if (lookahead == 'n') ADVANCE(108);
      if (lookahead == 'r') ADVANCE(98);
      if (lookahead == 's') ADVANCE(103);
      if (lookahead == 't') ADVANCE(117);
      if (lookahead == '|') ADVANCE(127);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(53)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 54:
      if (eof) ADVANCE(57);
      if (lookahead == '&') ADVANCE(9);
      if (lookahead == '\'') ADVANCE(84);
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == ')') ADVANCE(60);
      if (lookahead == ',') ADVANCE(131);
      if (lookahead == '.') ADVANCE(128);
      if (lookahead == '0') ADVANCE(71);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead == ';') ADVANCE(58);
      if (lookahead == 'b') ADVANCE(97);
      if (lookahead == 'f') ADVANCE(92);
      if (lookahead == 'n') ADVANCE(108);
      if (lookahead == 's') ADVANCE(103);
      if (lookahead == 't') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(54)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 55:
      if (eof) ADVANCE(57);
      if (lookahead == '&') ADVANCE(9);
      if (lookahead == ')') ADVANCE(60);
      if (lookahead == ',') ADVANCE(131);
      if (lookahead == '.') ADVANCE(128);
      if (lookahead == ';') ADVANCE(58);
      if (lookahead == 'e') ADVANCE(32);
      if (lookahead == 'r') ADVANCE(30);
      if (lookahead == '|') ADVANCE(127);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(55)
      END_STATE();
    case 56:
      if (eof) ADVANCE(57);
      if (lookahead == '\'') ADVANCE(84);
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == ')') ADVANCE(60);
      if (lookahead == '0') ADVANCE(71);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead == ';') ADVANCE(58);
      if (lookahead == 'a') ADVANCE(111);
      if (lookahead == 'b') ADVANCE(97);
      if (lookahead == 'f') ADVANCE(92);
      if (lookahead == 'm') ADVANCE(116);
      if (lookahead == 'n') ADVANCE(108);
      if (lookahead == 's') ADVANCE(103);
      if (lookahead == 't') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(56)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(91);
      if (lookahead != 0 &&
          lookahead > '^' &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_nil);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_true);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_false);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_integer_token1);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_integer_token1);
      if (lookahead == '.') ADVANCE(42);
      if (lookahead == '_') ADVANCE(66);
      if (lookahead == 'b') ADVANCE(67);
      if (lookahead == 'f') ADVANCE(18);
      if (lookahead == 'i') ADVANCE(10);
      if (lookahead == 'o') ADVANCE(68);
      if (lookahead == 'u') ADVANCE(10);
      if (lookahead == 'x') ADVANCE(69);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(77);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_integer_token1);
      if (lookahead == '.') ADVANCE(42);
      if (lookahead == 'f') ADVANCE(18);
      if (lookahead == 'i') ADVANCE(10);
      if (lookahead == 'u') ADVANCE(10);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_integer_token1);
      if (lookahead == 'i') ADVANCE(10);
      if (lookahead == 'u') ADVANCE(10);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(67);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_integer_token1);
      if (lookahead == 'i') ADVANCE(10);
      if (lookahead == 'u') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(68);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_integer_token1);
      if (lookahead == 'i') ADVANCE(10);
      if (lookahead == 'u') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(69);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_integer_token2);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_integer_token2);
      if (lookahead == '.') ADVANCE(43);
      if (lookahead == '_') ADVANCE(72);
      if (lookahead == 'b') ADVANCE(73);
      if (lookahead == 'f') ADVANCE(19);
      if (lookahead == 'i') ADVANCE(11);
      if (lookahead == 'o') ADVANCE(74);
      if (lookahead == 'u') ADVANCE(11);
      if (lookahead == 'x') ADVANCE(75);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_integer_token2);
      if (lookahead == '.') ADVANCE(43);
      if (lookahead == 'f') ADVANCE(19);
      if (lookahead == 'i') ADVANCE(11);
      if (lookahead == 'u') ADVANCE(11);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(72);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_integer_token2);
      if (lookahead == 'i') ADVANCE(11);
      if (lookahead == 'u') ADVANCE(11);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(73);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_integer_token2);
      if (lookahead == 'i') ADVANCE(11);
      if (lookahead == 'u') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(74);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_integer_token2);
      if (lookahead == 'i') ADVANCE(11);
      if (lookahead == 'u') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_float_token1);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_float_token1);
      if (lookahead == 'f') ADVANCE(18);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(79);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_float_token1);
      if (lookahead == 'f') ADVANCE(18);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(78);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_float_token1);
      if (lookahead == 'f') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(79);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_float_token2);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_float_token2);
      if (lookahead == 'f') ADVANCE(19);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(83);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_float_token2);
      if (lookahead == 'f') ADVANCE(19);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(82);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_float_token2);
      if (lookahead == 'f') ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_char_token1);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_SQUOTE2);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_char_escape_sequence);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_module);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_end);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_end);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_constant);
      if (lookahead == ':') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ';' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(91);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(112);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(119);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(123);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(90);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(122);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(105);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(118);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(62);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(63);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(88);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(136);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(110);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(126);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(106);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(115);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(93);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(109);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(61);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(104);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(107);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(120);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(101);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(95);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(134);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(96);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(121);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(94);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(132);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(100);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(99);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(113);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(102);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_identifier_method_call);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_self);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_AMP_PLUS);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_AMP_DASH);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_alias);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_begin);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_rescue);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_rescue);
      if (lookahead == '!' ||
          lookahead == '?') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead > '/' &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || 159 < lookahead)) ADVANCE(124);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 56, .external_lex_state = 2},
  [2] = {.lex_state = 5, .external_lex_state = 3},
  [3] = {.lex_state = 5, .external_lex_state = 3},
  [4] = {.lex_state = 5, .external_lex_state = 2},
  [5] = {.lex_state = 54, .external_lex_state = 1},
  [6] = {.lex_state = 2, .external_lex_state = 1},
  [7] = {.lex_state = 5, .external_lex_state = 2},
  [8] = {.lex_state = 54, .external_lex_state = 1},
  [9] = {.lex_state = 2, .external_lex_state = 1},
  [10] = {.lex_state = 2, .external_lex_state = 1},
  [11] = {.lex_state = 54, .external_lex_state = 1},
  [12] = {.lex_state = 54, .external_lex_state = 1},
  [13] = {.lex_state = 56, .external_lex_state = 2},
  [14] = {.lex_state = 2, .external_lex_state = 1},
  [15] = {.lex_state = 56, .external_lex_state = 2},
  [16] = {.lex_state = 3, .external_lex_state = 1},
  [17] = {.lex_state = 2, .external_lex_state = 1},
  [18] = {.lex_state = 56, .external_lex_state = 2},
  [19] = {.lex_state = 56, .external_lex_state = 2},
  [20] = {.lex_state = 56, .external_lex_state = 2},
  [21] = {.lex_state = 3, .external_lex_state = 1},
  [22] = {.lex_state = 54, .external_lex_state = 1},
  [23] = {.lex_state = 54, .external_lex_state = 1},
  [24] = {.lex_state = 56, .external_lex_state = 2},
  [25] = {.lex_state = 2, .external_lex_state = 1},
  [26] = {.lex_state = 3, .external_lex_state = 1},
  [27] = {.lex_state = 3, .external_lex_state = 1},
  [28] = {.lex_state = 3, .external_lex_state = 1},
  [29] = {.lex_state = 5, .external_lex_state = 2},
  [30] = {.lex_state = 6, .external_lex_state = 2},
  [31] = {.lex_state = 56, .external_lex_state = 2},
  [32] = {.lex_state = 6, .external_lex_state = 2},
  [33] = {.lex_state = 6, .external_lex_state = 2},
  [34] = {.lex_state = 5, .external_lex_state = 2},
  [35] = {.lex_state = 56, .external_lex_state = 2},
  [36] = {.lex_state = 3, .external_lex_state = 1},
  [37] = {.lex_state = 56, .external_lex_state = 2},
  [38] = {.lex_state = 56, .external_lex_state = 2},
  [39] = {.lex_state = 6, .external_lex_state = 2},
  [40] = {.lex_state = 6, .external_lex_state = 2},
  [41] = {.lex_state = 54, .external_lex_state = 4},
  [42] = {.lex_state = 6, .external_lex_state = 2},
  [43] = {.lex_state = 54, .external_lex_state = 4},
  [44] = {.lex_state = 6, .external_lex_state = 2},
  [45] = {.lex_state = 54, .external_lex_state = 4},
  [46] = {.lex_state = 4, .external_lex_state = 2},
  [47] = {.lex_state = 4, .external_lex_state = 2},
  [48] = {.lex_state = 4, .external_lex_state = 2},
  [49] = {.lex_state = 4, .external_lex_state = 2},
  [50] = {.lex_state = 4, .external_lex_state = 2},
  [51] = {.lex_state = 4, .external_lex_state = 2},
  [52] = {.lex_state = 4, .external_lex_state = 2},
  [53] = {.lex_state = 54, .external_lex_state = 2},
  [54] = {.lex_state = 54, .external_lex_state = 2},
  [55] = {.lex_state = 54, .external_lex_state = 2},
  [56] = {.lex_state = 54, .external_lex_state = 2},
  [57] = {.lex_state = 54, .external_lex_state = 2},
  [58] = {.lex_state = 54, .external_lex_state = 2},
  [59] = {.lex_state = 54, .external_lex_state = 2},
  [60] = {.lex_state = 54, .external_lex_state = 2},
  [61] = {.lex_state = 54, .external_lex_state = 2},
  [62] = {.lex_state = 54, .external_lex_state = 2},
  [63] = {.lex_state = 54, .external_lex_state = 2},
  [64] = {.lex_state = 54, .external_lex_state = 2},
  [65] = {.lex_state = 54, .external_lex_state = 2},
  [66] = {.lex_state = 56, .external_lex_state = 2},
  [67] = {.lex_state = 5, .external_lex_state = 2},
  [68] = {.lex_state = 6, .external_lex_state = 2},
  [69] = {.lex_state = 52, .external_lex_state = 5},
  [70] = {.lex_state = 52, .external_lex_state = 5},
  [71] = {.lex_state = 52, .external_lex_state = 5},
  [72] = {.lex_state = 52, .external_lex_state = 5},
  [73] = {.lex_state = 52, .external_lex_state = 5},
  [74] = {.lex_state = 52, .external_lex_state = 5},
  [75] = {.lex_state = 52, .external_lex_state = 5},
  [76] = {.lex_state = 52, .external_lex_state = 5},
  [77] = {.lex_state = 52, .external_lex_state = 5},
  [78] = {.lex_state = 52, .external_lex_state = 5},
  [79] = {.lex_state = 52, .external_lex_state = 5},
  [80] = {.lex_state = 52, .external_lex_state = 5},
  [81] = {.lex_state = 52, .external_lex_state = 5},
  [82] = {.lex_state = 52, .external_lex_state = 5},
  [83] = {.lex_state = 52, .external_lex_state = 5},
  [84] = {.lex_state = 52, .external_lex_state = 5},
  [85] = {.lex_state = 52, .external_lex_state = 5},
  [86] = {.lex_state = 52, .external_lex_state = 5},
  [87] = {.lex_state = 52, .external_lex_state = 5},
  [88] = {.lex_state = 52, .external_lex_state = 5},
  [89] = {.lex_state = 52, .external_lex_state = 5},
  [90] = {.lex_state = 52, .external_lex_state = 5},
  [91] = {.lex_state = 52, .external_lex_state = 5},
  [92] = {.lex_state = 52, .external_lex_state = 5},
  [93] = {.lex_state = 52, .external_lex_state = 5},
  [94] = {.lex_state = 0, .external_lex_state = 5},
  [95] = {.lex_state = 52, .external_lex_state = 5},
  [96] = {.lex_state = 52, .external_lex_state = 5},
  [97] = {.lex_state = 52, .external_lex_state = 5},
  [98] = {.lex_state = 0, .external_lex_state = 5},
  [99] = {.lex_state = 0, .external_lex_state = 5},
  [100] = {.lex_state = 0, .external_lex_state = 5},
  [101] = {.lex_state = 0, .external_lex_state = 5},
  [102] = {.lex_state = 52, .external_lex_state = 5},
  [103] = {.lex_state = 52, .external_lex_state = 5},
  [104] = {.lex_state = 52, .external_lex_state = 5},
  [105] = {.lex_state = 52, .external_lex_state = 5},
  [106] = {.lex_state = 52, .external_lex_state = 5},
  [107] = {.lex_state = 8, .external_lex_state = 6},
  [108] = {.lex_state = 52, .external_lex_state = 5},
  [109] = {.lex_state = 0, .external_lex_state = 5},
  [110] = {.lex_state = 0, .external_lex_state = 5},
  [111] = {.lex_state = 52, .external_lex_state = 5},
  [112] = {.lex_state = 52, .external_lex_state = 5},
  [113] = {.lex_state = 52, .external_lex_state = 5},
  [114] = {.lex_state = 52, .external_lex_state = 6},
  [115] = {.lex_state = 0, .external_lex_state = 5},
  [116] = {.lex_state = 52, .external_lex_state = 5},
  [117] = {.lex_state = 52, .external_lex_state = 6},
  [118] = {.lex_state = 52, .external_lex_state = 6},
  [119] = {.lex_state = 52, .external_lex_state = 6},
  [120] = {.lex_state = 52, .external_lex_state = 6},
  [121] = {.lex_state = 52, .external_lex_state = 6},
  [122] = {.lex_state = 52, .external_lex_state = 6},
  [123] = {.lex_state = 52, .external_lex_state = 6},
  [124] = {.lex_state = 0, .external_lex_state = 7},
  [125] = {.lex_state = 0, .external_lex_state = 7},
  [126] = {.lex_state = 0, .external_lex_state = 7},
  [127] = {.lex_state = 52, .external_lex_state = 5},
  [128] = {.lex_state = 0, .external_lex_state = 7},
  [129] = {.lex_state = 0, .external_lex_state = 7},
  [130] = {.lex_state = 0, .external_lex_state = 7},
  [131] = {.lex_state = 52, .external_lex_state = 6},
  [132] = {.lex_state = 0, .external_lex_state = 7},
  [133] = {.lex_state = 0, .external_lex_state = 7},
  [134] = {.lex_state = 0, .external_lex_state = 7},
  [135] = {.lex_state = 0, .external_lex_state = 7},
  [136] = {.lex_state = 0, .external_lex_state = 7},
  [137] = {.lex_state = 0, .external_lex_state = 7},
  [138] = {.lex_state = 0, .external_lex_state = 7},
  [139] = {.lex_state = 0, .external_lex_state = 7},
  [140] = {.lex_state = 0, .external_lex_state = 7},
  [141] = {.lex_state = 0, .external_lex_state = 7},
  [142] = {.lex_state = 0, .external_lex_state = 7},
  [143] = {.lex_state = 52, .external_lex_state = 6},
  [144] = {.lex_state = 0, .external_lex_state = 7},
  [145] = {.lex_state = 0, .external_lex_state = 7},
  [146] = {.lex_state = 0, .external_lex_state = 7},
  [147] = {.lex_state = 0, .external_lex_state = 7},
  [148] = {.lex_state = 0, .external_lex_state = 7},
  [149] = {.lex_state = 52, .external_lex_state = 6},
  [150] = {.lex_state = 0, .external_lex_state = 7},
  [151] = {.lex_state = 0, .external_lex_state = 7},
  [152] = {.lex_state = 0, .external_lex_state = 7},
  [153] = {.lex_state = 0, .external_lex_state = 7},
  [154] = {.lex_state = 52, .external_lex_state = 6},
  [155] = {.lex_state = 0, .external_lex_state = 7},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 52, .external_lex_state = 6},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 52, .external_lex_state = 6},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 52, .external_lex_state = 6},
  [163] = {.lex_state = 52, .external_lex_state = 6},
  [164] = {.lex_state = 0, .external_lex_state = 6},
  [165] = {.lex_state = 52, .external_lex_state = 6},
  [166] = {.lex_state = 52, .external_lex_state = 6},
  [167] = {.lex_state = 0, .external_lex_state = 6},
  [168] = {.lex_state = 0, .external_lex_state = 6},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 52, .external_lex_state = 6},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 52, .external_lex_state = 6},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0, .external_lex_state = 6},
  [188] = {.lex_state = 0, .external_lex_state = 6},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 0, .external_lex_state = 6},
  [191] = {.lex_state = 52},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0, .external_lex_state = 6},
  [197] = {.lex_state = 52},
  [198] = {.lex_state = 0, .external_lex_state = 6},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 52},
  [201] = {.lex_state = 52},
  [202] = {.lex_state = 0, .external_lex_state = 6},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 8},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 8},
  [208] = {.lex_state = 8},
  [209] = {.lex_state = 27},
  [210] = {.lex_state = 8},
  [211] = {.lex_state = 27},
  [212] = {.lex_state = 8},
  [213] = {.lex_state = 8},
  [214] = {.lex_state = 8},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 52},
  [222] = {.lex_state = 52},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 52},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 52},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 0},
  [230] = {.lex_state = 52},
  [231] = {.lex_state = 52},
  [232] = {.lex_state = 52},
  [233] = {.lex_state = 0},
  [234] = {.lex_state = 52},
  [235] = {.lex_state = 52},
  [236] = {.lex_state = 52},
  [237] = {.lex_state = 52},
  [238] = {.lex_state = 0},
  [239] = {.lex_state = 0},
  [240] = {.lex_state = 52},
  [241] = {.lex_state = 52},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 0},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 52},
  [247] = {.lex_state = 52},
  [248] = {.lex_state = 0},
};

enum {
  ts_external_token__line_break = 0,
  ts_external_token_unary_plus = 1,
  ts_external_token_unary_minus = 2,
  ts_external_token_binary_plus = 3,
  ts_external_token_binary_minus = 4,
};

static TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__line_break] = sym__line_break,
  [ts_external_token_unary_plus] = sym_unary_plus,
  [ts_external_token_unary_minus] = sym_unary_minus,
  [ts_external_token_binary_plus] = sym_binary_plus,
  [ts_external_token_binary_minus] = sym_binary_minus,
};

static bool ts_external_scanner_states[8][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__line_break] = true,
    [ts_external_token_unary_plus] = true,
    [ts_external_token_unary_minus] = true,
    [ts_external_token_binary_plus] = true,
    [ts_external_token_binary_minus] = true,
  },
  [2] = {
    [ts_external_token_unary_plus] = true,
    [ts_external_token_unary_minus] = true,
  },
  [3] = {
    [ts_external_token__line_break] = true,
    [ts_external_token_unary_plus] = true,
    [ts_external_token_unary_minus] = true,
  },
  [4] = {
    [ts_external_token_unary_plus] = true,
    [ts_external_token_unary_minus] = true,
    [ts_external_token_binary_plus] = true,
    [ts_external_token_binary_minus] = true,
  },
  [5] = {
    [ts_external_token__line_break] = true,
    [ts_external_token_binary_plus] = true,
    [ts_external_token_binary_minus] = true,
  },
  [6] = {
    [ts_external_token__line_break] = true,
  },
  [7] = {
    [ts_external_token_binary_plus] = true,
    [ts_external_token_binary_minus] = true,
  },
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
    [aux_sym_integer_token1] = ACTIONS(1),
    [aux_sym_integer_token2] = ACTIONS(1),
    [aux_sym_float_token1] = ACTIONS(1),
    [aux_sym_float_token2] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE2] = ACTIONS(1),
    [sym_char_escape_sequence] = ACTIONS(1),
    [anon_sym_module] = ACTIONS(1),
    [anon_sym_end] = ACTIONS(1),
    [sym_constant] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_identifier_method_call] = ACTIONS(1),
    [sym_self] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_AMP_PLUS] = ACTIONS(1),
    [anon_sym_AMP_DASH] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_alias] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_begin] = ACTIONS(1),
    [anon_sym_rescue] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym__line_break] = ACTIONS(1),
    [sym_unary_plus] = ACTIONS(1),
    [sym_unary_minus] = ACTIONS(1),
    [sym_binary_plus] = ACTIONS(1),
    [sym_binary_minus] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(244),
    [sym__statements] = STATE(243),
    [sym__parenthesized_statements] = STATE(115),
    [sym__statement] = STATE(167),
    [sym__expression] = STATE(115),
    [sym_integer] = STATE(115),
    [sym_float] = STATE(115),
    [sym_char] = STATE(115),
    [sym_module] = STATE(167),
    [sym_call] = STATE(115),
    [sym_additive_operator] = STATE(115),
    [sym_unary_additive_operator] = STATE(115),
    [sym_alias] = STATE(167),
    [sym_begin_block] = STATE(115),
    [aux_sym__statements_repeat1] = STATE(35),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(9),
    [sym_true] = ACTIONS(9),
    [sym_false] = ACTIONS(9),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [sym_constant] = ACTIONS(19),
    [sym_identifier] = ACTIONS(21),
    [sym_identifier_method_call] = ACTIONS(23),
    [sym_self] = ACTIONS(9),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(29),
    [sym_unary_minus] = ACTIONS(29),
  },
  [2] = {
    [sym__terminator] = STATE(7),
    [sym__statements] = STATE(201),
    [sym__parenthesized_statements] = STATE(116),
    [sym__statement] = STATE(166),
    [sym__expression] = STATE(116),
    [sym_integer] = STATE(116),
    [sym_float] = STATE(116),
    [sym_char] = STATE(116),
    [sym_module] = STATE(166),
    [sym_call] = STATE(116),
    [sym_additive_operator] = STATE(116),
    [sym_unary_additive_operator] = STATE(116),
    [sym_alias] = STATE(166),
    [sym_begin_block] = STATE(116),
    [sym_rescue_block] = STATE(246),
    [aux_sym__statements_repeat1] = STATE(29),
    [anon_sym_SEMI] = ACTIONS(31),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(33),
    [sym_true] = ACTIONS(33),
    [sym_false] = ACTIONS(33),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [anon_sym_end] = ACTIONS(35),
    [sym_constant] = ACTIONS(37),
    [sym_identifier] = ACTIONS(39),
    [sym_identifier_method_call] = ACTIONS(41),
    [sym_self] = ACTIONS(33),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [anon_sym_rescue] = ACTIONS(43),
    [sym__line_break] = ACTIONS(31),
    [sym_unary_plus] = ACTIONS(45),
    [sym_unary_minus] = ACTIONS(45),
  },
  [3] = {
    [sym__terminator] = STATE(4),
    [sym__statements] = STATE(191),
    [sym__parenthesized_statements] = STATE(116),
    [sym__statement] = STATE(166),
    [sym__expression] = STATE(116),
    [sym_integer] = STATE(116),
    [sym_float] = STATE(116),
    [sym_char] = STATE(116),
    [sym_module] = STATE(166),
    [sym_call] = STATE(116),
    [sym_additive_operator] = STATE(116),
    [sym_unary_additive_operator] = STATE(116),
    [sym_alias] = STATE(166),
    [sym_begin_block] = STATE(116),
    [sym_rescue_block] = STATE(232),
    [aux_sym__statements_repeat1] = STATE(29),
    [anon_sym_SEMI] = ACTIONS(47),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(33),
    [sym_true] = ACTIONS(33),
    [sym_false] = ACTIONS(33),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [anon_sym_end] = ACTIONS(49),
    [sym_constant] = ACTIONS(37),
    [sym_identifier] = ACTIONS(39),
    [sym_identifier_method_call] = ACTIONS(41),
    [sym_self] = ACTIONS(33),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [anon_sym_rescue] = ACTIONS(43),
    [sym__line_break] = ACTIONS(47),
    [sym_unary_plus] = ACTIONS(45),
    [sym_unary_minus] = ACTIONS(45),
  },
  [4] = {
    [sym__statements] = STATE(197),
    [sym__parenthesized_statements] = STATE(116),
    [sym__statement] = STATE(166),
    [sym__expression] = STATE(116),
    [sym_integer] = STATE(116),
    [sym_float] = STATE(116),
    [sym_char] = STATE(116),
    [sym_module] = STATE(166),
    [sym_call] = STATE(116),
    [sym_additive_operator] = STATE(116),
    [sym_unary_additive_operator] = STATE(116),
    [sym_alias] = STATE(166),
    [sym_begin_block] = STATE(116),
    [sym_rescue_block] = STATE(221),
    [aux_sym__statements_repeat1] = STATE(29),
    [anon_sym_SEMI] = ACTIONS(51),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(33),
    [sym_true] = ACTIONS(33),
    [sym_false] = ACTIONS(33),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [anon_sym_end] = ACTIONS(53),
    [sym_constant] = ACTIONS(37),
    [sym_identifier] = ACTIONS(39),
    [sym_identifier_method_call] = ACTIONS(41),
    [sym_self] = ACTIONS(33),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [anon_sym_rescue] = ACTIONS(43),
    [sym_unary_plus] = ACTIONS(45),
    [sym_unary_minus] = ACTIONS(45),
  },
  [5] = {
    [sym__parenthesized_statements] = STATE(100),
    [sym__expression] = STATE(100),
    [sym_integer] = STATE(100),
    [sym_float] = STATE(100),
    [sym_char] = STATE(100),
    [sym_call] = STATE(100),
    [sym_additive_operator] = STATE(100),
    [sym_unary_additive_operator] = STATE(100),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(100),
    [ts_builtin_sym_end] = ACTIONS(55),
    [anon_sym_SEMI] = ACTIONS(55),
    [anon_sym_LPAREN] = ACTIONS(57),
    [anon_sym_RPAREN] = ACTIONS(55),
    [sym_nil] = ACTIONS(59),
    [sym_true] = ACTIONS(59),
    [sym_false] = ACTIONS(59),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [sym_constant] = ACTIONS(61),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(59),
    [anon_sym_DOT] = ACTIONS(55),
    [anon_sym_AMP_PLUS] = ACTIONS(55),
    [anon_sym_AMP_DASH] = ACTIONS(55),
    [anon_sym_COMMA] = ACTIONS(55),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(55),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
    [sym_binary_plus] = ACTIONS(55),
    [sym_binary_minus] = ACTIONS(55),
  },
  [6] = {
    [sym__parenthesized_statements] = STATE(96),
    [sym__expression] = STATE(96),
    [sym_integer] = STATE(96),
    [sym_float] = STATE(96),
    [sym_char] = STATE(96),
    [sym_call] = STATE(96),
    [sym_additive_operator] = STATE(96),
    [sym_unary_additive_operator] = STATE(96),
    [sym_argument_list] = STATE(83),
    [sym_begin_block] = STATE(96),
    [anon_sym_SEMI] = ACTIONS(69),
    [anon_sym_LPAREN] = ACTIONS(71),
    [sym_nil] = ACTIONS(73),
    [sym_true] = ACTIONS(73),
    [sym_false] = ACTIONS(73),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(75),
    [sym_constant] = ACTIONS(77),
    [sym_identifier] = ACTIONS(79),
    [sym_identifier_method_call] = ACTIONS(81),
    [sym_self] = ACTIONS(73),
    [anon_sym_DOT] = ACTIONS(69),
    [anon_sym_AMP_PLUS] = ACTIONS(69),
    [anon_sym_AMP_DASH] = ACTIONS(69),
    [anon_sym_COMMA] = ACTIONS(69),
    [anon_sym_begin] = ACTIONS(27),
    [anon_sym_rescue] = ACTIONS(75),
    [sym__line_break] = ACTIONS(69),
    [sym_unary_plus] = ACTIONS(83),
    [sym_unary_minus] = ACTIONS(83),
    [sym_binary_plus] = ACTIONS(69),
    [sym_binary_minus] = ACTIONS(69),
  },
  [7] = {
    [sym__statements] = STATE(200),
    [sym__parenthesized_statements] = STATE(116),
    [sym__statement] = STATE(166),
    [sym__expression] = STATE(116),
    [sym_integer] = STATE(116),
    [sym_float] = STATE(116),
    [sym_char] = STATE(116),
    [sym_module] = STATE(166),
    [sym_call] = STATE(116),
    [sym_additive_operator] = STATE(116),
    [sym_unary_additive_operator] = STATE(116),
    [sym_alias] = STATE(166),
    [sym_begin_block] = STATE(116),
    [sym_rescue_block] = STATE(241),
    [aux_sym__statements_repeat1] = STATE(29),
    [anon_sym_SEMI] = ACTIONS(51),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(33),
    [sym_true] = ACTIONS(33),
    [sym_false] = ACTIONS(33),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [anon_sym_end] = ACTIONS(85),
    [sym_constant] = ACTIONS(37),
    [sym_identifier] = ACTIONS(39),
    [sym_identifier_method_call] = ACTIONS(41),
    [sym_self] = ACTIONS(33),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [anon_sym_rescue] = ACTIONS(43),
    [sym_unary_plus] = ACTIONS(45),
    [sym_unary_minus] = ACTIONS(45),
  },
  [8] = {
    [sym__parenthesized_statements] = STATE(100),
    [sym__expression] = STATE(100),
    [sym_integer] = STATE(100),
    [sym_float] = STATE(100),
    [sym_char] = STATE(100),
    [sym_call] = STATE(100),
    [sym_additive_operator] = STATE(100),
    [sym_unary_additive_operator] = STATE(100),
    [sym_argument_list] = STATE(83),
    [sym_begin_block] = STATE(100),
    [ts_builtin_sym_end] = ACTIONS(69),
    [anon_sym_SEMI] = ACTIONS(69),
    [anon_sym_LPAREN] = ACTIONS(71),
    [anon_sym_RPAREN] = ACTIONS(69),
    [sym_nil] = ACTIONS(59),
    [sym_true] = ACTIONS(59),
    [sym_false] = ACTIONS(59),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [sym_constant] = ACTIONS(61),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(59),
    [anon_sym_DOT] = ACTIONS(69),
    [anon_sym_AMP_PLUS] = ACTIONS(69),
    [anon_sym_AMP_DASH] = ACTIONS(69),
    [anon_sym_COMMA] = ACTIONS(69),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(69),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
    [sym_binary_plus] = ACTIONS(69),
    [sym_binary_minus] = ACTIONS(69),
  },
  [9] = {
    [sym__parenthesized_statements] = STATE(96),
    [sym__expression] = STATE(96),
    [sym_integer] = STATE(96),
    [sym_float] = STATE(96),
    [sym_char] = STATE(96),
    [sym_call] = STATE(96),
    [sym_additive_operator] = STATE(96),
    [sym_unary_additive_operator] = STATE(96),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(96),
    [anon_sym_SEMI] = ACTIONS(55),
    [anon_sym_LPAREN] = ACTIONS(57),
    [sym_nil] = ACTIONS(73),
    [sym_true] = ACTIONS(73),
    [sym_false] = ACTIONS(73),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(87),
    [sym_constant] = ACTIONS(77),
    [sym_identifier] = ACTIONS(79),
    [sym_identifier_method_call] = ACTIONS(81),
    [sym_self] = ACTIONS(73),
    [anon_sym_DOT] = ACTIONS(55),
    [anon_sym_AMP_PLUS] = ACTIONS(55),
    [anon_sym_AMP_DASH] = ACTIONS(55),
    [anon_sym_COMMA] = ACTIONS(55),
    [anon_sym_begin] = ACTIONS(27),
    [anon_sym_rescue] = ACTIONS(87),
    [sym__line_break] = ACTIONS(55),
    [sym_unary_plus] = ACTIONS(83),
    [sym_unary_minus] = ACTIONS(83),
    [sym_binary_plus] = ACTIONS(55),
    [sym_binary_minus] = ACTIONS(55),
  },
  [10] = {
    [sym__parenthesized_statements] = STATE(96),
    [sym__expression] = STATE(96),
    [sym_integer] = STATE(96),
    [sym_float] = STATE(96),
    [sym_char] = STATE(96),
    [sym_call] = STATE(96),
    [sym_additive_operator] = STATE(96),
    [sym_unary_additive_operator] = STATE(96),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(96),
    [anon_sym_SEMI] = ACTIONS(89),
    [anon_sym_LPAREN] = ACTIONS(57),
    [sym_nil] = ACTIONS(73),
    [sym_true] = ACTIONS(73),
    [sym_false] = ACTIONS(73),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(91),
    [sym_constant] = ACTIONS(77),
    [sym_identifier] = ACTIONS(79),
    [sym_identifier_method_call] = ACTIONS(81),
    [sym_self] = ACTIONS(73),
    [anon_sym_DOT] = ACTIONS(89),
    [anon_sym_AMP_PLUS] = ACTIONS(89),
    [anon_sym_AMP_DASH] = ACTIONS(89),
    [anon_sym_COMMA] = ACTIONS(89),
    [anon_sym_begin] = ACTIONS(27),
    [anon_sym_rescue] = ACTIONS(91),
    [sym__line_break] = ACTIONS(89),
    [sym_unary_plus] = ACTIONS(83),
    [sym_unary_minus] = ACTIONS(83),
    [sym_binary_plus] = ACTIONS(89),
    [sym_binary_minus] = ACTIONS(89),
  },
  [11] = {
    [sym__parenthesized_statements] = STATE(100),
    [sym__expression] = STATE(100),
    [sym_integer] = STATE(100),
    [sym_float] = STATE(100),
    [sym_char] = STATE(100),
    [sym_call] = STATE(100),
    [sym_additive_operator] = STATE(100),
    [sym_unary_additive_operator] = STATE(100),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(100),
    [ts_builtin_sym_end] = ACTIONS(89),
    [anon_sym_SEMI] = ACTIONS(89),
    [anon_sym_LPAREN] = ACTIONS(57),
    [anon_sym_RPAREN] = ACTIONS(89),
    [sym_nil] = ACTIONS(59),
    [sym_true] = ACTIONS(59),
    [sym_false] = ACTIONS(59),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [sym_constant] = ACTIONS(61),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(59),
    [anon_sym_DOT] = ACTIONS(89),
    [anon_sym_AMP_PLUS] = ACTIONS(89),
    [anon_sym_AMP_DASH] = ACTIONS(89),
    [anon_sym_COMMA] = ACTIONS(89),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(89),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
    [sym_binary_plus] = ACTIONS(89),
    [sym_binary_minus] = ACTIONS(89),
  },
  [12] = {
    [sym__parenthesized_statements] = STATE(98),
    [sym__expression] = STATE(98),
    [sym_integer] = STATE(98),
    [sym_float] = STATE(98),
    [sym_char] = STATE(98),
    [sym_call] = STATE(98),
    [sym_additive_operator] = STATE(98),
    [sym_unary_additive_operator] = STATE(98),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(98),
    [ts_builtin_sym_end] = ACTIONS(89),
    [anon_sym_SEMI] = ACTIONS(89),
    [anon_sym_LPAREN] = ACTIONS(93),
    [anon_sym_RPAREN] = ACTIONS(89),
    [sym_nil] = ACTIONS(95),
    [sym_true] = ACTIONS(95),
    [sym_false] = ACTIONS(95),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [sym_constant] = ACTIONS(97),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(95),
    [anon_sym_DOT] = ACTIONS(89),
    [anon_sym_AMP_PLUS] = ACTIONS(89),
    [anon_sym_AMP_DASH] = ACTIONS(89),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(89),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
    [sym_binary_plus] = ACTIONS(89),
    [sym_binary_minus] = ACTIONS(89),
  },
  [13] = {
    [sym__statements] = STATE(239),
    [sym__parenthesized_statements] = STATE(109),
    [sym__statement] = STATE(167),
    [sym__expression] = STATE(109),
    [sym_integer] = STATE(109),
    [sym_float] = STATE(109),
    [sym_char] = STATE(109),
    [sym_module] = STATE(167),
    [sym_call] = STATE(109),
    [sym_additive_operator] = STATE(109),
    [sym_unary_additive_operator] = STATE(109),
    [sym_argument_list_with_trailing_comma] = STATE(219),
    [sym_alias] = STATE(167),
    [sym_begin_block] = STATE(109),
    [aux_sym__statements_repeat1] = STATE(35),
    [anon_sym_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_RPAREN] = ACTIONS(99),
    [sym_nil] = ACTIONS(101),
    [sym_true] = ACTIONS(101),
    [sym_false] = ACTIONS(101),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [sym_constant] = ACTIONS(103),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(101),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
  },
  [14] = {
    [sym__parenthesized_statements] = STATE(95),
    [sym__expression] = STATE(95),
    [sym_integer] = STATE(95),
    [sym_float] = STATE(95),
    [sym_char] = STATE(95),
    [sym_call] = STATE(95),
    [sym_additive_operator] = STATE(95),
    [sym_unary_additive_operator] = STATE(95),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(95),
    [anon_sym_SEMI] = ACTIONS(55),
    [anon_sym_LPAREN] = ACTIONS(93),
    [sym_nil] = ACTIONS(105),
    [sym_true] = ACTIONS(105),
    [sym_false] = ACTIONS(105),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(87),
    [sym_constant] = ACTIONS(107),
    [sym_identifier] = ACTIONS(79),
    [sym_identifier_method_call] = ACTIONS(81),
    [sym_self] = ACTIONS(105),
    [anon_sym_DOT] = ACTIONS(55),
    [anon_sym_AMP_PLUS] = ACTIONS(55),
    [anon_sym_AMP_DASH] = ACTIONS(55),
    [anon_sym_begin] = ACTIONS(27),
    [anon_sym_rescue] = ACTIONS(87),
    [sym__line_break] = ACTIONS(55),
    [sym_unary_plus] = ACTIONS(83),
    [sym_unary_minus] = ACTIONS(83),
    [sym_binary_plus] = ACTIONS(55),
    [sym_binary_minus] = ACTIONS(55),
  },
  [15] = {
    [sym__statements] = STATE(220),
    [sym__parenthesized_statements] = STATE(109),
    [sym__statement] = STATE(167),
    [sym__expression] = STATE(109),
    [sym_integer] = STATE(109),
    [sym_float] = STATE(109),
    [sym_char] = STATE(109),
    [sym_module] = STATE(167),
    [sym_call] = STATE(109),
    [sym_additive_operator] = STATE(109),
    [sym_unary_additive_operator] = STATE(109),
    [sym_argument_list_with_trailing_comma] = STATE(242),
    [sym_alias] = STATE(167),
    [sym_begin_block] = STATE(109),
    [aux_sym__statements_repeat1] = STATE(35),
    [anon_sym_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_RPAREN] = ACTIONS(109),
    [sym_nil] = ACTIONS(101),
    [sym_true] = ACTIONS(101),
    [sym_false] = ACTIONS(101),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [sym_constant] = ACTIONS(103),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(101),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
  },
  [16] = {
    [sym__parenthesized_statements] = STATE(105),
    [sym__expression] = STATE(105),
    [sym_integer] = STATE(105),
    [sym_float] = STATE(105),
    [sym_char] = STATE(105),
    [sym_call] = STATE(105),
    [sym_additive_operator] = STATE(105),
    [sym_unary_additive_operator] = STATE(105),
    [sym_argument_list] = STATE(83),
    [sym_begin_block] = STATE(105),
    [anon_sym_SEMI] = ACTIONS(69),
    [anon_sym_LPAREN] = ACTIONS(71),
    [sym_nil] = ACTIONS(111),
    [sym_true] = ACTIONS(111),
    [sym_false] = ACTIONS(111),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(75),
    [sym_constant] = ACTIONS(113),
    [sym_identifier] = ACTIONS(115),
    [sym_identifier_method_call] = ACTIONS(117),
    [sym_self] = ACTIONS(111),
    [anon_sym_DOT] = ACTIONS(69),
    [anon_sym_AMP_PLUS] = ACTIONS(69),
    [anon_sym_AMP_DASH] = ACTIONS(69),
    [anon_sym_COMMA] = ACTIONS(69),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(69),
    [sym_unary_plus] = ACTIONS(119),
    [sym_unary_minus] = ACTIONS(119),
    [sym_binary_plus] = ACTIONS(69),
    [sym_binary_minus] = ACTIONS(69),
  },
  [17] = {
    [sym__parenthesized_statements] = STATE(95),
    [sym__expression] = STATE(95),
    [sym_integer] = STATE(95),
    [sym_float] = STATE(95),
    [sym_char] = STATE(95),
    [sym_call] = STATE(95),
    [sym_additive_operator] = STATE(95),
    [sym_unary_additive_operator] = STATE(95),
    [sym_argument_list] = STATE(83),
    [sym_begin_block] = STATE(95),
    [anon_sym_SEMI] = ACTIONS(69),
    [anon_sym_LPAREN] = ACTIONS(121),
    [sym_nil] = ACTIONS(105),
    [sym_true] = ACTIONS(105),
    [sym_false] = ACTIONS(105),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(75),
    [sym_constant] = ACTIONS(107),
    [sym_identifier] = ACTIONS(79),
    [sym_identifier_method_call] = ACTIONS(81),
    [sym_self] = ACTIONS(105),
    [anon_sym_DOT] = ACTIONS(69),
    [anon_sym_AMP_PLUS] = ACTIONS(69),
    [anon_sym_AMP_DASH] = ACTIONS(69),
    [anon_sym_begin] = ACTIONS(27),
    [anon_sym_rescue] = ACTIONS(75),
    [sym__line_break] = ACTIONS(69),
    [sym_unary_plus] = ACTIONS(83),
    [sym_unary_minus] = ACTIONS(83),
    [sym_binary_plus] = ACTIONS(69),
    [sym_binary_minus] = ACTIONS(69),
  },
  [18] = {
    [sym__statements] = STATE(220),
    [sym__parenthesized_statements] = STATE(109),
    [sym__statement] = STATE(167),
    [sym__expression] = STATE(109),
    [sym_integer] = STATE(109),
    [sym_float] = STATE(109),
    [sym_char] = STATE(109),
    [sym_module] = STATE(167),
    [sym_call] = STATE(109),
    [sym_additive_operator] = STATE(109),
    [sym_unary_additive_operator] = STATE(109),
    [sym_argument_list_with_trailing_comma] = STATE(225),
    [sym_alias] = STATE(167),
    [sym_begin_block] = STATE(109),
    [aux_sym__statements_repeat1] = STATE(35),
    [anon_sym_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_RPAREN] = ACTIONS(123),
    [sym_nil] = ACTIONS(101),
    [sym_true] = ACTIONS(101),
    [sym_false] = ACTIONS(101),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [sym_constant] = ACTIONS(103),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(101),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
  },
  [19] = {
    [sym__statements] = STATE(239),
    [sym__parenthesized_statements] = STATE(109),
    [sym__statement] = STATE(167),
    [sym__expression] = STATE(109),
    [sym_integer] = STATE(109),
    [sym_float] = STATE(109),
    [sym_char] = STATE(109),
    [sym_module] = STATE(167),
    [sym_call] = STATE(109),
    [sym_additive_operator] = STATE(109),
    [sym_unary_additive_operator] = STATE(109),
    [sym_argument_list_with_trailing_comma] = STATE(219),
    [sym_alias] = STATE(167),
    [sym_begin_block] = STATE(109),
    [aux_sym__statements_repeat1] = STATE(35),
    [anon_sym_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_RPAREN] = ACTIONS(125),
    [sym_nil] = ACTIONS(101),
    [sym_true] = ACTIONS(101),
    [sym_false] = ACTIONS(101),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [sym_constant] = ACTIONS(103),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(101),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
  },
  [20] = {
    [sym__statements] = STATE(239),
    [sym__parenthesized_statements] = STATE(109),
    [sym__statement] = STATE(167),
    [sym__expression] = STATE(109),
    [sym_integer] = STATE(109),
    [sym_float] = STATE(109),
    [sym_char] = STATE(109),
    [sym_module] = STATE(167),
    [sym_call] = STATE(109),
    [sym_additive_operator] = STATE(109),
    [sym_unary_additive_operator] = STATE(109),
    [sym_argument_list_with_trailing_comma] = STATE(228),
    [sym_alias] = STATE(167),
    [sym_begin_block] = STATE(109),
    [aux_sym__statements_repeat1] = STATE(35),
    [anon_sym_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_RPAREN] = ACTIONS(127),
    [sym_nil] = ACTIONS(101),
    [sym_true] = ACTIONS(101),
    [sym_false] = ACTIONS(101),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [sym_constant] = ACTIONS(103),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(101),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
  },
  [21] = {
    [sym__parenthesized_statements] = STATE(105),
    [sym__expression] = STATE(105),
    [sym_integer] = STATE(105),
    [sym_float] = STATE(105),
    [sym_char] = STATE(105),
    [sym_call] = STATE(105),
    [sym_additive_operator] = STATE(105),
    [sym_unary_additive_operator] = STATE(105),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(105),
    [anon_sym_SEMI] = ACTIONS(55),
    [anon_sym_LPAREN] = ACTIONS(57),
    [sym_nil] = ACTIONS(111),
    [sym_true] = ACTIONS(111),
    [sym_false] = ACTIONS(111),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(87),
    [sym_constant] = ACTIONS(113),
    [sym_identifier] = ACTIONS(115),
    [sym_identifier_method_call] = ACTIONS(117),
    [sym_self] = ACTIONS(111),
    [anon_sym_DOT] = ACTIONS(55),
    [anon_sym_AMP_PLUS] = ACTIONS(55),
    [anon_sym_AMP_DASH] = ACTIONS(55),
    [anon_sym_COMMA] = ACTIONS(55),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(55),
    [sym_unary_plus] = ACTIONS(119),
    [sym_unary_minus] = ACTIONS(119),
    [sym_binary_plus] = ACTIONS(55),
    [sym_binary_minus] = ACTIONS(55),
  },
  [22] = {
    [sym__parenthesized_statements] = STATE(98),
    [sym__expression] = STATE(98),
    [sym_integer] = STATE(98),
    [sym_float] = STATE(98),
    [sym_char] = STATE(98),
    [sym_call] = STATE(98),
    [sym_additive_operator] = STATE(98),
    [sym_unary_additive_operator] = STATE(98),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(98),
    [ts_builtin_sym_end] = ACTIONS(55),
    [anon_sym_SEMI] = ACTIONS(55),
    [anon_sym_LPAREN] = ACTIONS(93),
    [anon_sym_RPAREN] = ACTIONS(55),
    [sym_nil] = ACTIONS(95),
    [sym_true] = ACTIONS(95),
    [sym_false] = ACTIONS(95),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [sym_constant] = ACTIONS(97),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(95),
    [anon_sym_DOT] = ACTIONS(55),
    [anon_sym_AMP_PLUS] = ACTIONS(55),
    [anon_sym_AMP_DASH] = ACTIONS(55),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(55),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
    [sym_binary_plus] = ACTIONS(55),
    [sym_binary_minus] = ACTIONS(55),
  },
  [23] = {
    [sym__parenthesized_statements] = STATE(98),
    [sym__expression] = STATE(98),
    [sym_integer] = STATE(98),
    [sym_float] = STATE(98),
    [sym_char] = STATE(98),
    [sym_call] = STATE(98),
    [sym_additive_operator] = STATE(98),
    [sym_unary_additive_operator] = STATE(98),
    [sym_argument_list] = STATE(83),
    [sym_begin_block] = STATE(98),
    [ts_builtin_sym_end] = ACTIONS(69),
    [anon_sym_SEMI] = ACTIONS(69),
    [anon_sym_LPAREN] = ACTIONS(121),
    [anon_sym_RPAREN] = ACTIONS(69),
    [sym_nil] = ACTIONS(95),
    [sym_true] = ACTIONS(95),
    [sym_false] = ACTIONS(95),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [sym_constant] = ACTIONS(97),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(95),
    [anon_sym_DOT] = ACTIONS(69),
    [anon_sym_AMP_PLUS] = ACTIONS(69),
    [anon_sym_AMP_DASH] = ACTIONS(69),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(69),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
    [sym_binary_plus] = ACTIONS(69),
    [sym_binary_minus] = ACTIONS(69),
  },
  [24] = {
    [sym__statements] = STATE(239),
    [sym__parenthesized_statements] = STATE(109),
    [sym__statement] = STATE(167),
    [sym__expression] = STATE(109),
    [sym_integer] = STATE(109),
    [sym_float] = STATE(109),
    [sym_char] = STATE(109),
    [sym_module] = STATE(167),
    [sym_call] = STATE(109),
    [sym_additive_operator] = STATE(109),
    [sym_unary_additive_operator] = STATE(109),
    [sym_argument_list_with_trailing_comma] = STATE(228),
    [sym_alias] = STATE(167),
    [sym_begin_block] = STATE(109),
    [aux_sym__statements_repeat1] = STATE(35),
    [anon_sym_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_RPAREN] = ACTIONS(129),
    [sym_nil] = ACTIONS(101),
    [sym_true] = ACTIONS(101),
    [sym_false] = ACTIONS(101),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [sym_constant] = ACTIONS(103),
    [sym_identifier] = ACTIONS(63),
    [sym_identifier_method_call] = ACTIONS(65),
    [sym_self] = ACTIONS(101),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(67),
    [sym_unary_minus] = ACTIONS(67),
  },
  [25] = {
    [sym__parenthesized_statements] = STATE(95),
    [sym__expression] = STATE(95),
    [sym_integer] = STATE(95),
    [sym_float] = STATE(95),
    [sym_char] = STATE(95),
    [sym_call] = STATE(95),
    [sym_additive_operator] = STATE(95),
    [sym_unary_additive_operator] = STATE(95),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(95),
    [anon_sym_SEMI] = ACTIONS(89),
    [anon_sym_LPAREN] = ACTIONS(93),
    [sym_nil] = ACTIONS(105),
    [sym_true] = ACTIONS(105),
    [sym_false] = ACTIONS(105),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(91),
    [sym_constant] = ACTIONS(107),
    [sym_identifier] = ACTIONS(79),
    [sym_identifier_method_call] = ACTIONS(81),
    [sym_self] = ACTIONS(105),
    [anon_sym_DOT] = ACTIONS(89),
    [anon_sym_AMP_PLUS] = ACTIONS(89),
    [anon_sym_AMP_DASH] = ACTIONS(89),
    [anon_sym_begin] = ACTIONS(27),
    [anon_sym_rescue] = ACTIONS(91),
    [sym__line_break] = ACTIONS(89),
    [sym_unary_plus] = ACTIONS(83),
    [sym_unary_minus] = ACTIONS(83),
    [sym_binary_plus] = ACTIONS(89),
    [sym_binary_minus] = ACTIONS(89),
  },
  [26] = {
    [sym__parenthesized_statements] = STATE(105),
    [sym__expression] = STATE(105),
    [sym_integer] = STATE(105),
    [sym_float] = STATE(105),
    [sym_char] = STATE(105),
    [sym_call] = STATE(105),
    [sym_additive_operator] = STATE(105),
    [sym_unary_additive_operator] = STATE(105),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(105),
    [anon_sym_SEMI] = ACTIONS(89),
    [anon_sym_LPAREN] = ACTIONS(57),
    [sym_nil] = ACTIONS(111),
    [sym_true] = ACTIONS(111),
    [sym_false] = ACTIONS(111),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(91),
    [sym_constant] = ACTIONS(113),
    [sym_identifier] = ACTIONS(115),
    [sym_identifier_method_call] = ACTIONS(117),
    [sym_self] = ACTIONS(111),
    [anon_sym_DOT] = ACTIONS(89),
    [anon_sym_AMP_PLUS] = ACTIONS(89),
    [anon_sym_AMP_DASH] = ACTIONS(89),
    [anon_sym_COMMA] = ACTIONS(89),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(89),
    [sym_unary_plus] = ACTIONS(119),
    [sym_unary_minus] = ACTIONS(119),
    [sym_binary_plus] = ACTIONS(89),
    [sym_binary_minus] = ACTIONS(89),
  },
  [27] = {
    [sym__parenthesized_statements] = STATE(106),
    [sym__expression] = STATE(106),
    [sym_integer] = STATE(106),
    [sym_float] = STATE(106),
    [sym_char] = STATE(106),
    [sym_call] = STATE(106),
    [sym_additive_operator] = STATE(106),
    [sym_unary_additive_operator] = STATE(106),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(106),
    [anon_sym_SEMI] = ACTIONS(55),
    [anon_sym_LPAREN] = ACTIONS(93),
    [sym_nil] = ACTIONS(131),
    [sym_true] = ACTIONS(131),
    [sym_false] = ACTIONS(131),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(87),
    [sym_constant] = ACTIONS(133),
    [sym_identifier] = ACTIONS(115),
    [sym_identifier_method_call] = ACTIONS(117),
    [sym_self] = ACTIONS(131),
    [anon_sym_DOT] = ACTIONS(55),
    [anon_sym_AMP_PLUS] = ACTIONS(55),
    [anon_sym_AMP_DASH] = ACTIONS(55),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(55),
    [sym_unary_plus] = ACTIONS(119),
    [sym_unary_minus] = ACTIONS(119),
    [sym_binary_plus] = ACTIONS(55),
    [sym_binary_minus] = ACTIONS(55),
  },
  [28] = {
    [sym__parenthesized_statements] = STATE(106),
    [sym__expression] = STATE(106),
    [sym_integer] = STATE(106),
    [sym_float] = STATE(106),
    [sym_char] = STATE(106),
    [sym_call] = STATE(106),
    [sym_additive_operator] = STATE(106),
    [sym_unary_additive_operator] = STATE(106),
    [sym_argument_list] = STATE(83),
    [sym_begin_block] = STATE(106),
    [anon_sym_SEMI] = ACTIONS(69),
    [anon_sym_LPAREN] = ACTIONS(121),
    [sym_nil] = ACTIONS(131),
    [sym_true] = ACTIONS(131),
    [sym_false] = ACTIONS(131),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(75),
    [sym_constant] = ACTIONS(133),
    [sym_identifier] = ACTIONS(115),
    [sym_identifier_method_call] = ACTIONS(117),
    [sym_self] = ACTIONS(131),
    [anon_sym_DOT] = ACTIONS(69),
    [anon_sym_AMP_PLUS] = ACTIONS(69),
    [anon_sym_AMP_DASH] = ACTIONS(69),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(69),
    [sym_unary_plus] = ACTIONS(119),
    [sym_unary_minus] = ACTIONS(119),
    [sym_binary_plus] = ACTIONS(69),
    [sym_binary_minus] = ACTIONS(69),
  },
  [29] = {
    [sym__parenthesized_statements] = STATE(116),
    [sym__statement] = STATE(165),
    [sym__expression] = STATE(116),
    [sym_integer] = STATE(116),
    [sym_float] = STATE(116),
    [sym_char] = STATE(116),
    [sym_module] = STATE(165),
    [sym_call] = STATE(116),
    [sym_additive_operator] = STATE(116),
    [sym_unary_additive_operator] = STATE(116),
    [sym_alias] = STATE(165),
    [sym_begin_block] = STATE(116),
    [aux_sym__statements_repeat1] = STATE(34),
    [anon_sym_SEMI] = ACTIONS(135),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(33),
    [sym_true] = ACTIONS(33),
    [sym_false] = ACTIONS(33),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [anon_sym_end] = ACTIONS(137),
    [sym_constant] = ACTIONS(37),
    [sym_identifier] = ACTIONS(39),
    [sym_identifier_method_call] = ACTIONS(41),
    [sym_self] = ACTIONS(33),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [anon_sym_rescue] = ACTIONS(137),
    [sym_unary_plus] = ACTIONS(45),
    [sym_unary_minus] = ACTIONS(45),
  },
  [30] = {
    [sym__statements] = STATE(226),
    [sym__parenthesized_statements] = STATE(127),
    [sym__statement] = STATE(176),
    [sym__expression] = STATE(127),
    [sym_integer] = STATE(127),
    [sym_float] = STATE(127),
    [sym_char] = STATE(127),
    [sym_module] = STATE(176),
    [sym_call] = STATE(127),
    [sym_additive_operator] = STATE(127),
    [sym_unary_additive_operator] = STATE(127),
    [sym_alias] = STATE(176),
    [sym_begin_block] = STATE(127),
    [aux_sym__statements_repeat1] = STATE(44),
    [anon_sym_SEMI] = ACTIONS(139),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(141),
    [sym_true] = ACTIONS(141),
    [sym_false] = ACTIONS(141),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [anon_sym_end] = ACTIONS(143),
    [sym_constant] = ACTIONS(145),
    [sym_identifier] = ACTIONS(147),
    [sym_identifier_method_call] = ACTIONS(149),
    [sym_self] = ACTIONS(141),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(151),
    [sym_unary_minus] = ACTIONS(151),
  },
  [31] = {
    [sym__statements] = STATE(220),
    [sym__parenthesized_statements] = STATE(115),
    [sym__statement] = STATE(167),
    [sym__expression] = STATE(115),
    [sym_integer] = STATE(115),
    [sym_float] = STATE(115),
    [sym_char] = STATE(115),
    [sym_module] = STATE(167),
    [sym_call] = STATE(115),
    [sym_additive_operator] = STATE(115),
    [sym_unary_additive_operator] = STATE(115),
    [sym_alias] = STATE(167),
    [sym_begin_block] = STATE(115),
    [aux_sym__statements_repeat1] = STATE(35),
    [anon_sym_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_RPAREN] = ACTIONS(153),
    [sym_nil] = ACTIONS(9),
    [sym_true] = ACTIONS(9),
    [sym_false] = ACTIONS(9),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [sym_constant] = ACTIONS(19),
    [sym_identifier] = ACTIONS(21),
    [sym_identifier_method_call] = ACTIONS(23),
    [sym_self] = ACTIONS(9),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(29),
    [sym_unary_minus] = ACTIONS(29),
  },
  [32] = {
    [sym__statements] = STATE(231),
    [sym__parenthesized_statements] = STATE(127),
    [sym__statement] = STATE(176),
    [sym__expression] = STATE(127),
    [sym_integer] = STATE(127),
    [sym_float] = STATE(127),
    [sym_char] = STATE(127),
    [sym_module] = STATE(176),
    [sym_call] = STATE(127),
    [sym_additive_operator] = STATE(127),
    [sym_unary_additive_operator] = STATE(127),
    [sym_alias] = STATE(176),
    [sym_begin_block] = STATE(127),
    [aux_sym__statements_repeat1] = STATE(44),
    [anon_sym_SEMI] = ACTIONS(139),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(141),
    [sym_true] = ACTIONS(141),
    [sym_false] = ACTIONS(141),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [anon_sym_end] = ACTIONS(155),
    [sym_constant] = ACTIONS(145),
    [sym_identifier] = ACTIONS(147),
    [sym_identifier_method_call] = ACTIONS(149),
    [sym_self] = ACTIONS(141),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(151),
    [sym_unary_minus] = ACTIONS(151),
  },
  [33] = {
    [sym__statements] = STATE(247),
    [sym__parenthesized_statements] = STATE(127),
    [sym__statement] = STATE(176),
    [sym__expression] = STATE(127),
    [sym_integer] = STATE(127),
    [sym_float] = STATE(127),
    [sym_char] = STATE(127),
    [sym_module] = STATE(176),
    [sym_call] = STATE(127),
    [sym_additive_operator] = STATE(127),
    [sym_unary_additive_operator] = STATE(127),
    [sym_alias] = STATE(176),
    [sym_begin_block] = STATE(127),
    [aux_sym__statements_repeat1] = STATE(44),
    [anon_sym_SEMI] = ACTIONS(139),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(141),
    [sym_true] = ACTIONS(141),
    [sym_false] = ACTIONS(141),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [anon_sym_end] = ACTIONS(157),
    [sym_constant] = ACTIONS(145),
    [sym_identifier] = ACTIONS(147),
    [sym_identifier_method_call] = ACTIONS(149),
    [sym_self] = ACTIONS(141),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(151),
    [sym_unary_minus] = ACTIONS(151),
  },
  [34] = {
    [sym__parenthesized_statements] = STATE(115),
    [sym__statement] = STATE(187),
    [sym__expression] = STATE(115),
    [sym_integer] = STATE(115),
    [sym_float] = STATE(115),
    [sym_char] = STATE(115),
    [sym_module] = STATE(187),
    [sym_call] = STATE(115),
    [sym_additive_operator] = STATE(115),
    [sym_unary_additive_operator] = STATE(115),
    [sym_alias] = STATE(187),
    [sym_begin_block] = STATE(115),
    [aux_sym__statements_repeat1] = STATE(34),
    [anon_sym_SEMI] = ACTIONS(159),
    [anon_sym_LPAREN] = ACTIONS(162),
    [sym_nil] = ACTIONS(165),
    [sym_true] = ACTIONS(165),
    [sym_false] = ACTIONS(165),
    [aux_sym_integer_token2] = ACTIONS(168),
    [aux_sym_float_token2] = ACTIONS(171),
    [anon_sym_SQUOTE] = ACTIONS(174),
    [anon_sym_module] = ACTIONS(177),
    [anon_sym_end] = ACTIONS(180),
    [sym_constant] = ACTIONS(182),
    [sym_identifier] = ACTIONS(185),
    [sym_identifier_method_call] = ACTIONS(188),
    [sym_self] = ACTIONS(165),
    [anon_sym_alias] = ACTIONS(191),
    [anon_sym_begin] = ACTIONS(194),
    [anon_sym_rescue] = ACTIONS(180),
    [sym_unary_plus] = ACTIONS(197),
    [sym_unary_minus] = ACTIONS(197),
  },
  [35] = {
    [sym__parenthesized_statements] = STATE(115),
    [sym__statement] = STATE(164),
    [sym__expression] = STATE(115),
    [sym_integer] = STATE(115),
    [sym_float] = STATE(115),
    [sym_char] = STATE(115),
    [sym_module] = STATE(164),
    [sym_call] = STATE(115),
    [sym_additive_operator] = STATE(115),
    [sym_unary_additive_operator] = STATE(115),
    [sym_alias] = STATE(164),
    [sym_begin_block] = STATE(115),
    [aux_sym__statements_repeat1] = STATE(37),
    [ts_builtin_sym_end] = ACTIONS(200),
    [anon_sym_SEMI] = ACTIONS(202),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_RPAREN] = ACTIONS(200),
    [sym_nil] = ACTIONS(9),
    [sym_true] = ACTIONS(9),
    [sym_false] = ACTIONS(9),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [sym_constant] = ACTIONS(19),
    [sym_identifier] = ACTIONS(21),
    [sym_identifier_method_call] = ACTIONS(23),
    [sym_self] = ACTIONS(9),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(29),
    [sym_unary_minus] = ACTIONS(29),
  },
  [36] = {
    [sym__parenthesized_statements] = STATE(106),
    [sym__expression] = STATE(106),
    [sym_integer] = STATE(106),
    [sym_float] = STATE(106),
    [sym_char] = STATE(106),
    [sym_call] = STATE(106),
    [sym_additive_operator] = STATE(106),
    [sym_unary_additive_operator] = STATE(106),
    [sym_argument_list] = STATE(73),
    [sym_begin_block] = STATE(106),
    [anon_sym_SEMI] = ACTIONS(89),
    [anon_sym_LPAREN] = ACTIONS(93),
    [sym_nil] = ACTIONS(131),
    [sym_true] = ACTIONS(131),
    [sym_false] = ACTIONS(131),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_end] = ACTIONS(91),
    [sym_constant] = ACTIONS(133),
    [sym_identifier] = ACTIONS(115),
    [sym_identifier_method_call] = ACTIONS(117),
    [sym_self] = ACTIONS(131),
    [anon_sym_DOT] = ACTIONS(89),
    [anon_sym_AMP_PLUS] = ACTIONS(89),
    [anon_sym_AMP_DASH] = ACTIONS(89),
    [anon_sym_begin] = ACTIONS(27),
    [sym__line_break] = ACTIONS(89),
    [sym_unary_plus] = ACTIONS(119),
    [sym_unary_minus] = ACTIONS(119),
    [sym_binary_plus] = ACTIONS(89),
    [sym_binary_minus] = ACTIONS(89),
  },
  [37] = {
    [sym__parenthesized_statements] = STATE(115),
    [sym__statement] = STATE(198),
    [sym__expression] = STATE(115),
    [sym_integer] = STATE(115),
    [sym_float] = STATE(115),
    [sym_char] = STATE(115),
    [sym_module] = STATE(198),
    [sym_call] = STATE(115),
    [sym_additive_operator] = STATE(115),
    [sym_unary_additive_operator] = STATE(115),
    [sym_alias] = STATE(198),
    [sym_begin_block] = STATE(115),
    [aux_sym__statements_repeat1] = STATE(37),
    [ts_builtin_sym_end] = ACTIONS(204),
    [anon_sym_SEMI] = ACTIONS(206),
    [anon_sym_LPAREN] = ACTIONS(162),
    [anon_sym_RPAREN] = ACTIONS(204),
    [sym_nil] = ACTIONS(165),
    [sym_true] = ACTIONS(165),
    [sym_false] = ACTIONS(165),
    [aux_sym_integer_token2] = ACTIONS(168),
    [aux_sym_float_token2] = ACTIONS(171),
    [anon_sym_SQUOTE] = ACTIONS(174),
    [anon_sym_module] = ACTIONS(177),
    [sym_constant] = ACTIONS(182),
    [sym_identifier] = ACTIONS(185),
    [sym_identifier_method_call] = ACTIONS(188),
    [sym_self] = ACTIONS(165),
    [anon_sym_alias] = ACTIONS(191),
    [anon_sym_begin] = ACTIONS(194),
    [sym_unary_plus] = ACTIONS(197),
    [sym_unary_minus] = ACTIONS(197),
  },
  [38] = {
    [sym__statements] = STATE(239),
    [sym__parenthesized_statements] = STATE(115),
    [sym__statement] = STATE(167),
    [sym__expression] = STATE(115),
    [sym_integer] = STATE(115),
    [sym_float] = STATE(115),
    [sym_char] = STATE(115),
    [sym_module] = STATE(167),
    [sym_call] = STATE(115),
    [sym_additive_operator] = STATE(115),
    [sym_unary_additive_operator] = STATE(115),
    [sym_alias] = STATE(167),
    [sym_begin_block] = STATE(115),
    [aux_sym__statements_repeat1] = STATE(35),
    [anon_sym_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_RPAREN] = ACTIONS(209),
    [sym_nil] = ACTIONS(9),
    [sym_true] = ACTIONS(9),
    [sym_false] = ACTIONS(9),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [sym_constant] = ACTIONS(19),
    [sym_identifier] = ACTIONS(21),
    [sym_identifier_method_call] = ACTIONS(23),
    [sym_self] = ACTIONS(9),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(29),
    [sym_unary_minus] = ACTIONS(29),
  },
  [39] = {
    [sym__statements] = STATE(224),
    [sym__parenthesized_statements] = STATE(127),
    [sym__statement] = STATE(176),
    [sym__expression] = STATE(127),
    [sym_integer] = STATE(127),
    [sym_float] = STATE(127),
    [sym_char] = STATE(127),
    [sym_module] = STATE(176),
    [sym_call] = STATE(127),
    [sym_additive_operator] = STATE(127),
    [sym_unary_additive_operator] = STATE(127),
    [sym_alias] = STATE(176),
    [sym_begin_block] = STATE(127),
    [aux_sym__statements_repeat1] = STATE(44),
    [anon_sym_SEMI] = ACTIONS(139),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(141),
    [sym_true] = ACTIONS(141),
    [sym_false] = ACTIONS(141),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [anon_sym_end] = ACTIONS(211),
    [sym_constant] = ACTIONS(145),
    [sym_identifier] = ACTIONS(147),
    [sym_identifier_method_call] = ACTIONS(149),
    [sym_self] = ACTIONS(141),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(151),
    [sym_unary_minus] = ACTIONS(151),
  },
  [40] = {
    [sym__statements] = STATE(230),
    [sym__parenthesized_statements] = STATE(127),
    [sym__statement] = STATE(176),
    [sym__expression] = STATE(127),
    [sym_integer] = STATE(127),
    [sym_float] = STATE(127),
    [sym_char] = STATE(127),
    [sym_module] = STATE(176),
    [sym_call] = STATE(127),
    [sym_additive_operator] = STATE(127),
    [sym_unary_additive_operator] = STATE(127),
    [sym_alias] = STATE(176),
    [sym_begin_block] = STATE(127),
    [aux_sym__statements_repeat1] = STATE(44),
    [anon_sym_SEMI] = ACTIONS(139),
    [anon_sym_LPAREN] = ACTIONS(7),
    [sym_nil] = ACTIONS(141),
    [sym_true] = ACTIONS(141),
    [sym_false] = ACTIONS(141),
    [aux_sym_integer_token2] = ACTIONS(11),
    [aux_sym_float_token2] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(15),
    [anon_sym_module] = ACTIONS(17),
    [anon_sym_end] = ACTIONS(213),
    [sym_constant] = ACTIONS(145),
    [sym_identifier] = ACTIONS(147),
    [sym_identifier_method_call] = ACTIONS(149),
    [sym_self] = ACTIONS(141),
    [anon_sym_alias] = ACTIONS(25),
    [anon_sym_begin] = ACTIONS(27),
    [sym_unary_plus] = ACTIONS(151),
    [sym_unary_minus] = ACTIONS(151),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 13,
    ACTIONS(215), 1,
      anon_sym_LPAREN,
    ACTIONS(219), 1,
      aux_sym_integer_token2,
    ACTIONS(221), 1,
      aux_sym_float_token2,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    ACTIONS(225), 1,
      sym_constant,
    ACTIONS(227), 1,
      sym_identifier,
    ACTIONS(229), 1,
      sym_identifier_method_call,
    ACTIONS(231), 1,
      anon_sym_begin,
    STATE(128), 1,
      sym_argument_list,
    ACTIONS(233), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(217), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    ACTIONS(55), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
    STATE(124), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [58] = 17,
    ACTIONS(162), 1,
      anon_sym_LPAREN,
    ACTIONS(168), 1,
      aux_sym_integer_token2,
    ACTIONS(171), 1,
      aux_sym_float_token2,
    ACTIONS(174), 1,
      anon_sym_SQUOTE,
    ACTIONS(177), 1,
      anon_sym_module,
    ACTIONS(180), 1,
      anon_sym_end,
    ACTIONS(182), 1,
      sym_constant,
    ACTIONS(185), 1,
      sym_identifier,
    ACTIONS(188), 1,
      sym_identifier_method_call,
    ACTIONS(191), 1,
      anon_sym_alias,
    ACTIONS(194), 1,
      anon_sym_begin,
    ACTIONS(235), 1,
      anon_sym_SEMI,
    STATE(42), 1,
      aux_sym__statements_repeat1,
    ACTIONS(197), 2,
      sym_unary_plus,
      sym_unary_minus,
    STATE(202), 3,
      sym__statement,
      sym_module,
      sym_alias,
    ACTIONS(165), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(115), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [124] = 13,
    ACTIONS(219), 1,
      aux_sym_integer_token2,
    ACTIONS(221), 1,
      aux_sym_float_token2,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    ACTIONS(225), 1,
      sym_constant,
    ACTIONS(227), 1,
      sym_identifier,
    ACTIONS(229), 1,
      sym_identifier_method_call,
    ACTIONS(231), 1,
      anon_sym_begin,
    ACTIONS(238), 1,
      anon_sym_LPAREN,
    STATE(147), 1,
      sym_argument_list,
    ACTIONS(233), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(217), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    ACTIONS(69), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
    STATE(124), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [182] = 17,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(13), 1,
      aux_sym_float_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(17), 1,
      anon_sym_module,
    ACTIONS(25), 1,
      anon_sym_alias,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(137), 1,
      anon_sym_end,
    ACTIONS(145), 1,
      sym_constant,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(149), 1,
      sym_identifier_method_call,
    ACTIONS(240), 1,
      anon_sym_SEMI,
    STATE(42), 1,
      aux_sym__statements_repeat1,
    ACTIONS(151), 2,
      sym_unary_plus,
      sym_unary_minus,
    STATE(174), 3,
      sym__statement,
      sym_module,
      sym_alias,
    ACTIONS(141), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(127), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [248] = 13,
    ACTIONS(215), 1,
      anon_sym_LPAREN,
    ACTIONS(219), 1,
      aux_sym_integer_token2,
    ACTIONS(221), 1,
      aux_sym_float_token2,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    ACTIONS(225), 1,
      sym_constant,
    ACTIONS(227), 1,
      sym_identifier,
    ACTIONS(229), 1,
      sym_identifier_method_call,
    ACTIONS(231), 1,
      anon_sym_begin,
    STATE(128), 1,
      sym_argument_list,
    ACTIONS(233), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(217), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    ACTIONS(89), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
    STATE(124), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [306] = 13,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(115), 1,
      sym_identifier,
    ACTIONS(117), 1,
      sym_identifier_method_call,
    ACTIONS(244), 1,
      aux_sym_integer_token1,
    ACTIONS(246), 1,
      aux_sym_float_token1,
    ACTIONS(248), 1,
      aux_sym_float_token2,
    ACTIONS(250), 1,
      sym_constant,
    ACTIONS(119), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(242), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(77), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [358] = 13,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(39), 1,
      sym_identifier,
    ACTIONS(41), 1,
      sym_identifier_method_call,
    ACTIONS(244), 1,
      aux_sym_integer_token1,
    ACTIONS(246), 1,
      aux_sym_float_token1,
    ACTIONS(248), 1,
      aux_sym_float_token2,
    ACTIONS(250), 1,
      sym_constant,
    ACTIONS(45), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(242), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(77), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [410] = 13,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(21), 1,
      sym_identifier,
    ACTIONS(23), 1,
      sym_identifier_method_call,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(244), 1,
      aux_sym_integer_token1,
    ACTIONS(246), 1,
      aux_sym_float_token1,
    ACTIONS(248), 1,
      aux_sym_float_token2,
    ACTIONS(250), 1,
      sym_constant,
    ACTIONS(29), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(242), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(77), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [462] = 13,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(63), 1,
      sym_identifier,
    ACTIONS(65), 1,
      sym_identifier_method_call,
    ACTIONS(244), 1,
      aux_sym_integer_token1,
    ACTIONS(246), 1,
      aux_sym_float_token1,
    ACTIONS(248), 1,
      aux_sym_float_token2,
    ACTIONS(250), 1,
      sym_constant,
    ACTIONS(67), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(242), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(77), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [514] = 13,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(149), 1,
      sym_identifier_method_call,
    ACTIONS(244), 1,
      aux_sym_integer_token1,
    ACTIONS(246), 1,
      aux_sym_float_token1,
    ACTIONS(248), 1,
      aux_sym_float_token2,
    ACTIONS(250), 1,
      sym_constant,
    ACTIONS(151), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(242), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(77), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [566] = 13,
    ACTIONS(219), 1,
      aux_sym_integer_token2,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    ACTIONS(227), 1,
      sym_identifier,
    ACTIONS(229), 1,
      sym_identifier_method_call,
    ACTIONS(231), 1,
      anon_sym_begin,
    ACTIONS(252), 1,
      anon_sym_LPAREN,
    ACTIONS(256), 1,
      aux_sym_integer_token1,
    ACTIONS(258), 1,
      aux_sym_float_token1,
    ACTIONS(260), 1,
      aux_sym_float_token2,
    ACTIONS(262), 1,
      sym_constant,
    ACTIONS(233), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(254), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(152), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [618] = 13,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(79), 1,
      sym_identifier,
    ACTIONS(81), 1,
      sym_identifier_method_call,
    ACTIONS(244), 1,
      aux_sym_integer_token1,
    ACTIONS(246), 1,
      aux_sym_float_token1,
    ACTIONS(248), 1,
      aux_sym_float_token2,
    ACTIONS(250), 1,
      sym_constant,
    ACTIONS(83), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(242), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(77), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [670] = 12,
    ACTIONS(219), 1,
      aux_sym_integer_token2,
    ACTIONS(221), 1,
      aux_sym_float_token2,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    ACTIONS(227), 1,
      sym_identifier,
    ACTIONS(229), 1,
      sym_identifier_method_call,
    ACTIONS(231), 1,
      anon_sym_begin,
    ACTIONS(252), 1,
      anon_sym_LPAREN,
    ACTIONS(264), 1,
      anon_sym_RPAREN,
    ACTIONS(268), 1,
      sym_constant,
    ACTIONS(233), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(266), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(141), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [719] = 12,
    ACTIONS(219), 1,
      aux_sym_integer_token2,
    ACTIONS(221), 1,
      aux_sym_float_token2,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    ACTIONS(227), 1,
      sym_identifier,
    ACTIONS(229), 1,
      sym_identifier_method_call,
    ACTIONS(231), 1,
      anon_sym_begin,
    ACTIONS(252), 1,
      anon_sym_LPAREN,
    ACTIONS(268), 1,
      sym_constant,
    ACTIONS(270), 1,
      anon_sym_RPAREN,
    ACTIONS(233), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(266), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(141), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [768] = 11,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(13), 1,
      aux_sym_float_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(63), 1,
      sym_identifier,
    ACTIONS(65), 1,
      sym_identifier_method_call,
    ACTIONS(274), 1,
      sym_constant,
    ACTIONS(67), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(272), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(110), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [814] = 11,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(13), 1,
      aux_sym_float_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(39), 1,
      sym_identifier,
    ACTIONS(41), 1,
      sym_identifier_method_call,
    ACTIONS(278), 1,
      sym_constant,
    ACTIONS(45), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(276), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(90), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [860] = 11,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(13), 1,
      aux_sym_float_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(115), 1,
      sym_identifier,
    ACTIONS(117), 1,
      sym_identifier_method_call,
    ACTIONS(278), 1,
      sym_constant,
    ACTIONS(119), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(276), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(90), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [906] = 11,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(13), 1,
      aux_sym_float_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(115), 1,
      sym_identifier,
    ACTIONS(117), 1,
      sym_identifier_method_call,
    ACTIONS(282), 1,
      sym_constant,
    ACTIONS(119), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(280), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(113), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [952] = 11,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(13), 1,
      aux_sym_float_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(149), 1,
      sym_identifier_method_call,
    ACTIONS(278), 1,
      sym_constant,
    ACTIONS(151), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(276), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(90), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [998] = 11,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(13), 1,
      aux_sym_float_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(79), 1,
      sym_identifier,
    ACTIONS(81), 1,
      sym_identifier_method_call,
    ACTIONS(278), 1,
      sym_constant,
    ACTIONS(83), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(276), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(90), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [1044] = 11,
    ACTIONS(219), 1,
      aux_sym_integer_token2,
    ACTIONS(221), 1,
      aux_sym_float_token2,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    ACTIONS(227), 1,
      sym_identifier,
    ACTIONS(229), 1,
      sym_identifier_method_call,
    ACTIONS(231), 1,
      anon_sym_begin,
    ACTIONS(252), 1,
      anon_sym_LPAREN,
    ACTIONS(286), 1,
      sym_constant,
    ACTIONS(233), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(284), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(137), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [1090] = 11,
    ACTIONS(219), 1,
      aux_sym_integer_token2,
    ACTIONS(221), 1,
      aux_sym_float_token2,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    ACTIONS(227), 1,
      sym_identifier,
    ACTIONS(229), 1,
      sym_identifier_method_call,
    ACTIONS(231), 1,
      anon_sym_begin,
    ACTIONS(252), 1,
      anon_sym_LPAREN,
    ACTIONS(268), 1,
      sym_constant,
    ACTIONS(233), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(266), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(141), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [1136] = 11,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(13), 1,
      aux_sym_float_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(63), 1,
      sym_identifier,
    ACTIONS(65), 1,
      sym_identifier_method_call,
    ACTIONS(278), 1,
      sym_constant,
    ACTIONS(67), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(276), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(90), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [1182] = 11,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(13), 1,
      aux_sym_float_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(21), 1,
      sym_identifier,
    ACTIONS(23), 1,
      sym_identifier_method_call,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(278), 1,
      sym_constant,
    ACTIONS(29), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(276), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(90), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [1228] = 11,
    ACTIONS(7), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      aux_sym_integer_token2,
    ACTIONS(13), 1,
      aux_sym_float_token2,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(27), 1,
      anon_sym_begin,
    ACTIONS(79), 1,
      sym_identifier,
    ACTIONS(81), 1,
      sym_identifier_method_call,
    ACTIONS(290), 1,
      sym_constant,
    ACTIONS(83), 2,
      sym_unary_plus,
      sym_unary_minus,
    ACTIONS(288), 4,
      sym_nil,
      sym_true,
      sym_false,
      sym_self,
    STATE(104), 9,
      sym__parenthesized_statements,
      sym__expression,
      sym_integer,
      sym_float,
      sym_char,
      sym_call,
      sym_additive_operator,
      sym_unary_additive_operator,
      sym_begin_block,
  [1274] = 2,
    ACTIONS(180), 9,
      sym_nil,
      sym_true,
      sym_false,
      aux_sym_integer_token2,
      anon_sym_module,
      sym_identifier,
      sym_self,
      anon_sym_alias,
      anon_sym_begin,
    ACTIONS(204), 10,
      sym_unary_plus,
      sym_unary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      aux_sym_float_token2,
      anon_sym_SQUOTE,
      sym_constant,
      sym_identifier_method_call,
  [1298] = 2,
    ACTIONS(204), 8,
      sym_unary_plus,
      sym_unary_minus,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      aux_sym_float_token2,
      anon_sym_SQUOTE,
      sym_constant,
      sym_identifier_method_call,
    ACTIONS(180), 11,
      sym_nil,
      sym_true,
      sym_false,
      aux_sym_integer_token2,
      anon_sym_module,
      anon_sym_end,
      sym_identifier,
      sym_self,
      anon_sym_alias,
      anon_sym_begin,
      anon_sym_rescue,
  [1322] = 2,
    ACTIONS(204), 8,
      sym_unary_plus,
      sym_unary_minus,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      aux_sym_float_token2,
      anon_sym_SQUOTE,
      sym_constant,
      sym_identifier_method_call,
    ACTIONS(180), 10,
      sym_nil,
      sym_true,
      sym_false,
      aux_sym_integer_token2,
      anon_sym_module,
      anon_sym_end,
      sym_identifier,
      sym_self,
      anon_sym_alias,
      anon_sym_begin,
  [1345] = 1,
    ACTIONS(292), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1360] = 1,
    ACTIONS(294), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1375] = 1,
    ACTIONS(296), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1390] = 1,
    ACTIONS(298), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1405] = 1,
    ACTIONS(300), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1420] = 1,
    ACTIONS(302), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1435] = 1,
    ACTIONS(304), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1450] = 1,
    ACTIONS(306), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1465] = 1,
    ACTIONS(308), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1480] = 1,
    ACTIONS(310), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1495] = 1,
    ACTIONS(312), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1510] = 1,
    ACTIONS(314), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1525] = 1,
    ACTIONS(316), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1540] = 1,
    ACTIONS(318), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1555] = 1,
    ACTIONS(320), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1570] = 1,
    ACTIONS(322), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1585] = 1,
    ACTIONS(324), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1600] = 1,
    ACTIONS(326), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1615] = 1,
    ACTIONS(328), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1630] = 1,
    ACTIONS(330), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1645] = 1,
    ACTIONS(332), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1660] = 1,
    ACTIONS(334), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1675] = 2,
    ACTIONS(318), 1,
      anon_sym_COMMA,
    ACTIONS(306), 11,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_rescue,
  [1692] = 1,
    ACTIONS(336), 12,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1707] = 2,
    ACTIONS(318), 1,
      anon_sym_COMMA,
    ACTIONS(294), 11,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_rescue,
  [1724] = 2,
    STATE(101), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(338), 10,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [1740] = 5,
    ACTIONS(342), 1,
      anon_sym_DOT,
    ACTIONS(346), 1,
      anon_sym_COMMA,
    STATE(102), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(340), 4,
      sym__line_break,
      anon_sym_SEMI,
      anon_sym_end,
      anon_sym_rescue,
    ACTIONS(344), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [1762] = 5,
    ACTIONS(342), 1,
      anon_sym_DOT,
    ACTIONS(346), 1,
      anon_sym_COMMA,
    STATE(103), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(340), 4,
      sym__line_break,
      anon_sym_SEMI,
      anon_sym_end,
      anon_sym_rescue,
    ACTIONS(344), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [1784] = 3,
    ACTIONS(350), 1,
      anon_sym_COMMA,
    STATE(97), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(348), 9,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_SEMI,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_rescue,
  [1802] = 5,
    ACTIONS(353), 1,
      anon_sym_DOT,
    ACTIONS(357), 1,
      anon_sym_COMMA,
    STATE(99), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(340), 4,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    ACTIONS(355), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [1824] = 3,
    ACTIONS(357), 1,
      anon_sym_COMMA,
    STATE(101), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(338), 9,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [1842] = 5,
    ACTIONS(353), 1,
      anon_sym_DOT,
    ACTIONS(357), 1,
      anon_sym_COMMA,
    STATE(94), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(340), 4,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    ACTIONS(355), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [1864] = 3,
    ACTIONS(359), 1,
      anon_sym_COMMA,
    STATE(101), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(348), 9,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [1882] = 3,
    ACTIONS(346), 1,
      anon_sym_COMMA,
    STATE(97), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(338), 9,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_SEMI,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_rescue,
  [1900] = 2,
    STATE(97), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(338), 10,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_SEMI,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1916] = 3,
    ACTIONS(342), 1,
      anon_sym_DOT,
    ACTIONS(344), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
    ACTIONS(348), 5,
      sym__line_break,
      anon_sym_SEMI,
      anon_sym_end,
      anon_sym_COMMA,
      anon_sym_rescue,
  [1933] = 5,
    ACTIONS(362), 1,
      anon_sym_DOT,
    ACTIONS(366), 1,
      anon_sym_COMMA,
    STATE(108), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(340), 3,
      sym__line_break,
      anon_sym_SEMI,
      anon_sym_end,
    ACTIONS(364), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [1954] = 5,
    ACTIONS(362), 1,
      anon_sym_DOT,
    ACTIONS(366), 1,
      anon_sym_COMMA,
    STATE(112), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(340), 3,
      sym__line_break,
      anon_sym_SEMI,
      anon_sym_end,
    ACTIONS(364), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [1975] = 7,
    ACTIONS(370), 1,
      anon_sym_LPAREN,
    ACTIONS(372), 1,
      sym_constant,
    ACTIONS(374), 1,
      sym_identifier,
    STATE(30), 1,
      sym__terminator,
    ACTIONS(368), 2,
      sym__line_break,
      anon_sym_SEMI,
    STATE(196), 2,
      sym__type,
      sym_union_type,
    STATE(233), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2000] = 2,
    STATE(111), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(338), 9,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_SEMI,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2015] = 6,
    ACTIONS(353), 1,
      anon_sym_DOT,
    ACTIONS(378), 1,
      anon_sym_RPAREN,
    ACTIONS(380), 1,
      anon_sym_COMMA,
    STATE(199), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(376), 2,
      sym__line_break,
      anon_sym_SEMI,
    ACTIONS(355), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [2038] = 3,
    ACTIONS(353), 1,
      anon_sym_DOT,
    ACTIONS(355), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
    ACTIONS(348), 5,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [2055] = 3,
    ACTIONS(382), 1,
      anon_sym_COMMA,
    STATE(111), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(348), 8,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_SEMI,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [2072] = 3,
    ACTIONS(366), 1,
      anon_sym_COMMA,
    STATE(111), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(338), 8,
      sym__line_break,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_SEMI,
      anon_sym_end,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [2089] = 3,
    ACTIONS(362), 1,
      anon_sym_DOT,
    ACTIONS(348), 4,
      sym__line_break,
      anon_sym_SEMI,
      anon_sym_end,
      anon_sym_COMMA,
    ACTIONS(364), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [2105] = 4,
    ACTIONS(387), 1,
      anon_sym_PIPE,
    STATE(119), 1,
      aux_sym_union_type_repeat1,
    STATE(195), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(385), 6,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [2123] = 3,
    ACTIONS(389), 1,
      anon_sym_DOT,
    ACTIONS(376), 4,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
    ACTIONS(391), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [2139] = 3,
    ACTIONS(393), 1,
      anon_sym_DOT,
    ACTIONS(376), 4,
      sym__line_break,
      anon_sym_SEMI,
      anon_sym_end,
      anon_sym_rescue,
    ACTIONS(395), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [2155] = 3,
    ACTIONS(399), 1,
      anon_sym_PIPE,
    STATE(120), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(397), 6,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [2170] = 3,
    ACTIONS(403), 1,
      anon_sym_PIPE,
    STATE(118), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(401), 6,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [2185] = 3,
    ACTIONS(408), 1,
      anon_sym_PIPE,
    STATE(122), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(406), 6,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [2200] = 3,
    ACTIONS(412), 1,
      anon_sym_PIPE,
    STATE(118), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(410), 6,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [2215] = 2,
    STATE(120), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(414), 7,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_PIPE,
      anon_sym_rescue,
  [2228] = 3,
    ACTIONS(416), 1,
      anon_sym_PIPE,
    STATE(122), 1,
      aux_sym_union_type_repeat1,
    ACTIONS(414), 6,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [2243] = 2,
    STATE(120), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(401), 7,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_PIPE,
      anon_sym_rescue,
  [2256] = 5,
    ACTIONS(340), 1,
      anon_sym_RPAREN,
    ACTIONS(419), 1,
      anon_sym_DOT,
    ACTIONS(423), 1,
      anon_sym_COMMA,
    STATE(125), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(421), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [2275] = 2,
    STATE(126), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(338), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2288] = 3,
    ACTIONS(425), 1,
      anon_sym_COMMA,
    STATE(126), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(348), 6,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [2303] = 3,
    ACTIONS(428), 1,
      anon_sym_DOT,
    ACTIONS(376), 3,
      sym__line_break,
      anon_sym_SEMI,
      anon_sym_end,
    ACTIONS(430), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [2318] = 1,
    ACTIONS(300), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2328] = 1,
    ACTIONS(314), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2338] = 1,
    ACTIONS(330), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2348] = 1,
    ACTIONS(401), 7,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_PIPE,
      anon_sym_rescue,
  [2358] = 1,
    ACTIONS(312), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2368] = 1,
    ACTIONS(328), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2378] = 1,
    ACTIONS(326), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2388] = 1,
    ACTIONS(322), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2398] = 1,
    ACTIONS(292), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2408] = 1,
    ACTIONS(334), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2418] = 1,
    ACTIONS(318), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2428] = 1,
    ACTIONS(294), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2438] = 1,
    ACTIONS(332), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2448] = 3,
    ACTIONS(419), 1,
      anon_sym_DOT,
    ACTIONS(348), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
    ACTIONS(421), 4,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
  [2462] = 1,
    ACTIONS(304), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2472] = 2,
    ACTIONS(434), 1,
      anon_sym_PIPE,
    ACTIONS(432), 6,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [2484] = 1,
    ACTIONS(310), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2494] = 1,
    ACTIONS(302), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2504] = 1,
    ACTIONS(316), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2514] = 1,
    ACTIONS(320), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2524] = 1,
    ACTIONS(324), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2534] = 1,
    ACTIONS(436), 7,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_PIPE,
      anon_sym_rescue,
  [2544] = 1,
    ACTIONS(306), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2554] = 1,
    ACTIONS(336), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2564] = 1,
    ACTIONS(308), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2574] = 1,
    ACTIONS(298), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2584] = 1,
    ACTIONS(414), 7,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_PIPE,
      anon_sym_rescue,
  [2594] = 1,
    ACTIONS(296), 7,
      sym_binary_plus,
      sym_binary_minus,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_AMP_PLUS,
      anon_sym_AMP_DASH,
      anon_sym_COMMA,
  [2604] = 4,
    ACTIONS(438), 1,
      anon_sym_LPAREN,
    ACTIONS(440), 1,
      sym_constant,
    STATE(218), 2,
      sym__nested_union_type,
      sym__inner_union_type,
    STATE(227), 2,
      sym__type,
      sym_union_type,
  [2619] = 1,
    ACTIONS(442), 6,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [2628] = 4,
    ACTIONS(370), 1,
      anon_sym_LPAREN,
    ACTIONS(372), 1,
      sym_constant,
    STATE(157), 2,
      sym__type,
      sym_union_type,
    STATE(233), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2643] = 4,
    ACTIONS(370), 1,
      anon_sym_LPAREN,
    ACTIONS(372), 1,
      sym_constant,
    STATE(188), 2,
      sym__type,
      sym_union_type,
    STATE(233), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2658] = 1,
    ACTIONS(444), 6,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [2667] = 4,
    ACTIONS(438), 1,
      anon_sym_LPAREN,
    ACTIONS(440), 1,
      sym_constant,
    STATE(218), 2,
      sym__nested_union_type,
      sym__inner_union_type,
    STATE(238), 2,
      sym__type,
      sym_union_type,
  [2682] = 1,
    ACTIONS(446), 6,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [2691] = 1,
    ACTIONS(448), 6,
      sym__line_break,
      ts_builtin_sym_end,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_rescue,
  [2700] = 3,
    STATE(66), 1,
      sym__terminator,
    ACTIONS(450), 2,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
    ACTIONS(452), 2,
      sym__line_break,
      anon_sym_SEMI,
  [2712] = 3,
    STATE(67), 1,
      sym__terminator,
    ACTIONS(450), 2,
      anon_sym_end,
      anon_sym_rescue,
    ACTIONS(454), 2,
      sym__line_break,
      anon_sym_SEMI,
  [2724] = 3,
    STATE(67), 1,
      sym__terminator,
    ACTIONS(200), 2,
      anon_sym_end,
      anon_sym_rescue,
    ACTIONS(454), 2,
      sym__line_break,
      anon_sym_SEMI,
  [2736] = 3,
    STATE(66), 1,
      sym__terminator,
    ACTIONS(200), 2,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
    ACTIONS(452), 2,
      sym__line_break,
      anon_sym_SEMI,
  [2748] = 3,
    ACTIONS(458), 1,
      anon_sym_COLON,
    STATE(39), 1,
      sym__terminator,
    ACTIONS(456), 2,
      sym__line_break,
      anon_sym_SEMI,
  [2759] = 3,
    ACTIONS(460), 1,
      anon_sym_LPAREN,
    ACTIONS(462), 1,
      sym_constant,
    STATE(217), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2770] = 3,
    ACTIONS(464), 1,
      anon_sym_LPAREN,
    ACTIONS(466), 1,
      sym_constant,
    STATE(131), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2781] = 3,
    ACTIONS(460), 1,
      anon_sym_LPAREN,
    ACTIONS(468), 1,
      sym_constant,
    STATE(194), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2792] = 3,
    ACTIONS(460), 1,
      anon_sym_LPAREN,
    ACTIONS(470), 1,
      sym_constant,
    STATE(205), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2803] = 3,
    ACTIONS(464), 1,
      anon_sym_LPAREN,
    ACTIONS(472), 1,
      sym_constant,
    STATE(123), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2814] = 3,
    ACTIONS(450), 1,
      anon_sym_end,
    STATE(68), 1,
      sym__terminator,
    ACTIONS(474), 2,
      sym__line_break,
      anon_sym_SEMI,
  [2825] = 3,
    ACTIONS(460), 1,
      anon_sym_LPAREN,
    ACTIONS(476), 1,
      sym_constant,
    STATE(185), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2836] = 3,
    ACTIONS(200), 1,
      anon_sym_end,
    STATE(68), 1,
      sym__terminator,
    ACTIONS(474), 2,
      sym__line_break,
      anon_sym_SEMI,
  [2847] = 3,
    ACTIONS(460), 1,
      anon_sym_LPAREN,
    ACTIONS(478), 1,
      sym_constant,
    STATE(216), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2858] = 3,
    ACTIONS(464), 1,
      anon_sym_LPAREN,
    ACTIONS(480), 1,
      sym_constant,
    STATE(154), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2869] = 3,
    ACTIONS(460), 1,
      anon_sym_LPAREN,
    ACTIONS(482), 1,
      sym_constant,
    STATE(203), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2880] = 4,
    ACTIONS(385), 1,
      anon_sym_RPAREN,
    ACTIONS(484), 1,
      anon_sym_PIPE,
    STATE(192), 1,
      aux_sym_union_type_repeat1,
    STATE(195), 1,
      aux_sym__inner_union_type_repeat1,
  [2893] = 3,
    ACTIONS(460), 1,
      anon_sym_LPAREN,
    ACTIONS(486), 1,
      sym_constant,
    STATE(180), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2904] = 3,
    ACTIONS(464), 1,
      anon_sym_LPAREN,
    ACTIONS(488), 1,
      sym_constant,
    STATE(121), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2915] = 3,
    ACTIONS(464), 1,
      anon_sym_LPAREN,
    ACTIONS(490), 1,
      sym_constant,
    STATE(114), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2926] = 3,
    ACTIONS(460), 1,
      anon_sym_LPAREN,
    ACTIONS(492), 1,
      sym_constant,
    STATE(215), 2,
      sym__nested_union_type,
      sym__inner_union_type,
  [2937] = 2,
    STATE(195), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(414), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [2945] = 3,
    ACTIONS(401), 1,
      anon_sym_RPAREN,
    ACTIONS(494), 1,
      anon_sym_PIPE,
    STATE(186), 1,
      aux_sym__inner_union_type_repeat1,
  [2955] = 2,
    STATE(67), 1,
      sym__terminator,
    ACTIONS(454), 2,
      sym__line_break,
      anon_sym_SEMI,
  [2963] = 2,
    STATE(33), 1,
      sym__terminator,
    ACTIONS(497), 2,
      sym__line_break,
      anon_sym_SEMI,
  [2971] = 3,
    ACTIONS(348), 1,
      anon_sym_RPAREN,
    ACTIONS(425), 1,
      anon_sym_COMMA,
    STATE(189), 1,
      aux_sym_argument_list_repeat1,
  [2981] = 2,
    STATE(40), 1,
      sym__terminator,
    ACTIONS(499), 2,
      sym__line_break,
      anon_sym_SEMI,
  [2989] = 3,
    ACTIONS(501), 1,
      anon_sym_end,
    ACTIONS(503), 1,
      anon_sym_rescue,
    STATE(234), 1,
      sym_rescue_block,
  [2999] = 3,
    ACTIONS(406), 1,
      anon_sym_RPAREN,
    ACTIONS(505), 1,
      anon_sym_PIPE,
    STATE(193), 1,
      aux_sym_union_type_repeat1,
  [3009] = 3,
    ACTIONS(414), 1,
      anon_sym_RPAREN,
    ACTIONS(507), 1,
      anon_sym_PIPE,
    STATE(193), 1,
      aux_sym_union_type_repeat1,
  [3019] = 2,
    STATE(195), 1,
      aux_sym__inner_union_type_repeat1,
    ACTIONS(401), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [3027] = 3,
    ACTIONS(410), 1,
      anon_sym_RPAREN,
    ACTIONS(510), 1,
      anon_sym_PIPE,
    STATE(186), 1,
      aux_sym__inner_union_type_repeat1,
  [3037] = 2,
    STATE(32), 1,
      sym__terminator,
    ACTIONS(512), 2,
      sym__line_break,
      anon_sym_SEMI,
  [3045] = 3,
    ACTIONS(503), 1,
      anon_sym_rescue,
    ACTIONS(514), 1,
      anon_sym_end,
    STATE(236), 1,
      sym_rescue_block,
  [3055] = 2,
    STATE(66), 1,
      sym__terminator,
    ACTIONS(452), 2,
      sym__line_break,
      anon_sym_SEMI,
  [3063] = 3,
    ACTIONS(264), 1,
      anon_sym_RPAREN,
    ACTIONS(516), 1,
      anon_sym_COMMA,
    STATE(189), 1,
      aux_sym_argument_list_repeat1,
  [3073] = 3,
    ACTIONS(503), 1,
      anon_sym_rescue,
    ACTIONS(518), 1,
      anon_sym_end,
    STATE(222), 1,
      sym_rescue_block,
  [3083] = 3,
    ACTIONS(503), 1,
      anon_sym_rescue,
    ACTIONS(520), 1,
      anon_sym_end,
    STATE(240), 1,
      sym_rescue_block,
  [3093] = 2,
    STATE(68), 1,
      sym__terminator,
    ACTIONS(474), 2,
      sym__line_break,
      anon_sym_SEMI,
  [3101] = 3,
    ACTIONS(397), 1,
      anon_sym_RPAREN,
    ACTIONS(522), 1,
      anon_sym_PIPE,
    STATE(195), 1,
      aux_sym__inner_union_type_repeat1,
  [3111] = 2,
    ACTIONS(524), 1,
      sym_identifier,
    ACTIONS(526), 1,
      sym_identifier_method_call,
  [3118] = 2,
    ACTIONS(528), 1,
      anon_sym_RPAREN,
    ACTIONS(530), 1,
      anon_sym_PIPE,
  [3125] = 1,
    ACTIONS(436), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [3130] = 2,
    ACTIONS(532), 1,
      sym_identifier,
    ACTIONS(534), 1,
      sym_identifier_method_call,
  [3137] = 2,
    ACTIONS(536), 1,
      sym_identifier,
    ACTIONS(538), 1,
      sym_identifier_method_call,
  [3144] = 1,
    ACTIONS(540), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [3149] = 2,
    ACTIONS(542), 1,
      sym_identifier,
    ACTIONS(544), 1,
      sym_identifier_method_call,
  [3156] = 1,
    ACTIONS(546), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [3161] = 2,
    ACTIONS(548), 1,
      sym_identifier,
    ACTIONS(550), 1,
      sym_identifier_method_call,
  [3168] = 2,
    ACTIONS(552), 1,
      sym_identifier,
    ACTIONS(554), 1,
      sym_identifier_method_call,
  [3175] = 2,
    ACTIONS(556), 1,
      sym_identifier,
    ACTIONS(558), 1,
      sym_identifier_method_call,
  [3182] = 2,
    ACTIONS(530), 1,
      anon_sym_PIPE,
    ACTIONS(560), 1,
      anon_sym_RPAREN,
  [3189] = 1,
    ACTIONS(401), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [3194] = 1,
    ACTIONS(414), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [3199] = 2,
    ACTIONS(528), 1,
      anon_sym_RPAREN,
    ACTIONS(562), 1,
      anon_sym_PIPE,
  [3206] = 1,
    ACTIONS(564), 1,
      anon_sym_RPAREN,
  [3210] = 1,
    ACTIONS(566), 1,
      anon_sym_RPAREN,
  [3214] = 1,
    ACTIONS(568), 1,
      anon_sym_end,
  [3218] = 1,
    ACTIONS(570), 1,
      anon_sym_end,
  [3222] = 1,
    ACTIONS(572), 1,
      anon_sym_EQ,
  [3226] = 1,
    ACTIONS(574), 1,
      anon_sym_end,
  [3230] = 1,
    ACTIONS(576), 1,
      anon_sym_RPAREN,
  [3234] = 1,
    ACTIONS(578), 1,
      anon_sym_end,
  [3238] = 1,
    ACTIONS(580), 1,
      anon_sym_RPAREN,
  [3242] = 1,
    ACTIONS(582), 1,
      anon_sym_RPAREN,
  [3246] = 1,
    ACTIONS(444), 1,
      anon_sym_RPAREN,
  [3250] = 1,
    ACTIONS(584), 1,
      anon_sym_end,
  [3254] = 1,
    ACTIONS(586), 1,
      anon_sym_end,
  [3258] = 1,
    ACTIONS(588), 1,
      anon_sym_end,
  [3262] = 1,
    ACTIONS(590), 1,
      anon_sym_PIPE,
  [3266] = 1,
    ACTIONS(592), 1,
      anon_sym_end,
  [3270] = 1,
    ACTIONS(594), 1,
      anon_sym_SQUOTE2,
  [3274] = 1,
    ACTIONS(596), 1,
      anon_sym_end,
  [3278] = 1,
    ACTIONS(598), 1,
      anon_sym_SQUOTE2,
  [3282] = 1,
    ACTIONS(600), 1,
      anon_sym_RPAREN,
  [3286] = 1,
    ACTIONS(602), 1,
      anon_sym_RPAREN,
  [3290] = 1,
    ACTIONS(604), 1,
      anon_sym_end,
  [3294] = 1,
    ACTIONS(606), 1,
      anon_sym_end,
  [3298] = 1,
    ACTIONS(608), 1,
      anon_sym_RPAREN,
  [3302] = 1,
    ACTIONS(610), 1,
      ts_builtin_sym_end,
  [3306] = 1,
    ACTIONS(612), 1,
      ts_builtin_sym_end,
  [3310] = 1,
    ACTIONS(614), 1,
      sym_constant,
  [3314] = 1,
    ACTIONS(616), 1,
      anon_sym_end,
  [3318] = 1,
    ACTIONS(618), 1,
      anon_sym_end,
  [3322] = 1,
    ACTIONS(620), 1,
      sym_constant,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(41)] = 0,
  [SMALL_STATE(42)] = 58,
  [SMALL_STATE(43)] = 124,
  [SMALL_STATE(44)] = 182,
  [SMALL_STATE(45)] = 248,
  [SMALL_STATE(46)] = 306,
  [SMALL_STATE(47)] = 358,
  [SMALL_STATE(48)] = 410,
  [SMALL_STATE(49)] = 462,
  [SMALL_STATE(50)] = 514,
  [SMALL_STATE(51)] = 566,
  [SMALL_STATE(52)] = 618,
  [SMALL_STATE(53)] = 670,
  [SMALL_STATE(54)] = 719,
  [SMALL_STATE(55)] = 768,
  [SMALL_STATE(56)] = 814,
  [SMALL_STATE(57)] = 860,
  [SMALL_STATE(58)] = 906,
  [SMALL_STATE(59)] = 952,
  [SMALL_STATE(60)] = 998,
  [SMALL_STATE(61)] = 1044,
  [SMALL_STATE(62)] = 1090,
  [SMALL_STATE(63)] = 1136,
  [SMALL_STATE(64)] = 1182,
  [SMALL_STATE(65)] = 1228,
  [SMALL_STATE(66)] = 1274,
  [SMALL_STATE(67)] = 1298,
  [SMALL_STATE(68)] = 1322,
  [SMALL_STATE(69)] = 1345,
  [SMALL_STATE(70)] = 1360,
  [SMALL_STATE(71)] = 1375,
  [SMALL_STATE(72)] = 1390,
  [SMALL_STATE(73)] = 1405,
  [SMALL_STATE(74)] = 1420,
  [SMALL_STATE(75)] = 1435,
  [SMALL_STATE(76)] = 1450,
  [SMALL_STATE(77)] = 1465,
  [SMALL_STATE(78)] = 1480,
  [SMALL_STATE(79)] = 1495,
  [SMALL_STATE(80)] = 1510,
  [SMALL_STATE(81)] = 1525,
  [SMALL_STATE(82)] = 1540,
  [SMALL_STATE(83)] = 1555,
  [SMALL_STATE(84)] = 1570,
  [SMALL_STATE(85)] = 1585,
  [SMALL_STATE(86)] = 1600,
  [SMALL_STATE(87)] = 1615,
  [SMALL_STATE(88)] = 1630,
  [SMALL_STATE(89)] = 1645,
  [SMALL_STATE(90)] = 1660,
  [SMALL_STATE(91)] = 1675,
  [SMALL_STATE(92)] = 1692,
  [SMALL_STATE(93)] = 1707,
  [SMALL_STATE(94)] = 1724,
  [SMALL_STATE(95)] = 1740,
  [SMALL_STATE(96)] = 1762,
  [SMALL_STATE(97)] = 1784,
  [SMALL_STATE(98)] = 1802,
  [SMALL_STATE(99)] = 1824,
  [SMALL_STATE(100)] = 1842,
  [SMALL_STATE(101)] = 1864,
  [SMALL_STATE(102)] = 1882,
  [SMALL_STATE(103)] = 1900,
  [SMALL_STATE(104)] = 1916,
  [SMALL_STATE(105)] = 1933,
  [SMALL_STATE(106)] = 1954,
  [SMALL_STATE(107)] = 1975,
  [SMALL_STATE(108)] = 2000,
  [SMALL_STATE(109)] = 2015,
  [SMALL_STATE(110)] = 2038,
  [SMALL_STATE(111)] = 2055,
  [SMALL_STATE(112)] = 2072,
  [SMALL_STATE(113)] = 2089,
  [SMALL_STATE(114)] = 2105,
  [SMALL_STATE(115)] = 2123,
  [SMALL_STATE(116)] = 2139,
  [SMALL_STATE(117)] = 2155,
  [SMALL_STATE(118)] = 2170,
  [SMALL_STATE(119)] = 2185,
  [SMALL_STATE(120)] = 2200,
  [SMALL_STATE(121)] = 2215,
  [SMALL_STATE(122)] = 2228,
  [SMALL_STATE(123)] = 2243,
  [SMALL_STATE(124)] = 2256,
  [SMALL_STATE(125)] = 2275,
  [SMALL_STATE(126)] = 2288,
  [SMALL_STATE(127)] = 2303,
  [SMALL_STATE(128)] = 2318,
  [SMALL_STATE(129)] = 2328,
  [SMALL_STATE(130)] = 2338,
  [SMALL_STATE(131)] = 2348,
  [SMALL_STATE(132)] = 2358,
  [SMALL_STATE(133)] = 2368,
  [SMALL_STATE(134)] = 2378,
  [SMALL_STATE(135)] = 2388,
  [SMALL_STATE(136)] = 2398,
  [SMALL_STATE(137)] = 2408,
  [SMALL_STATE(138)] = 2418,
  [SMALL_STATE(139)] = 2428,
  [SMALL_STATE(140)] = 2438,
  [SMALL_STATE(141)] = 2448,
  [SMALL_STATE(142)] = 2462,
  [SMALL_STATE(143)] = 2472,
  [SMALL_STATE(144)] = 2484,
  [SMALL_STATE(145)] = 2494,
  [SMALL_STATE(146)] = 2504,
  [SMALL_STATE(147)] = 2514,
  [SMALL_STATE(148)] = 2524,
  [SMALL_STATE(149)] = 2534,
  [SMALL_STATE(150)] = 2544,
  [SMALL_STATE(151)] = 2554,
  [SMALL_STATE(152)] = 2564,
  [SMALL_STATE(153)] = 2574,
  [SMALL_STATE(154)] = 2584,
  [SMALL_STATE(155)] = 2594,
  [SMALL_STATE(156)] = 2604,
  [SMALL_STATE(157)] = 2619,
  [SMALL_STATE(158)] = 2628,
  [SMALL_STATE(159)] = 2643,
  [SMALL_STATE(160)] = 2658,
  [SMALL_STATE(161)] = 2667,
  [SMALL_STATE(162)] = 2682,
  [SMALL_STATE(163)] = 2691,
  [SMALL_STATE(164)] = 2700,
  [SMALL_STATE(165)] = 2712,
  [SMALL_STATE(166)] = 2724,
  [SMALL_STATE(167)] = 2736,
  [SMALL_STATE(168)] = 2748,
  [SMALL_STATE(169)] = 2759,
  [SMALL_STATE(170)] = 2770,
  [SMALL_STATE(171)] = 2781,
  [SMALL_STATE(172)] = 2792,
  [SMALL_STATE(173)] = 2803,
  [SMALL_STATE(174)] = 2814,
  [SMALL_STATE(175)] = 2825,
  [SMALL_STATE(176)] = 2836,
  [SMALL_STATE(177)] = 2847,
  [SMALL_STATE(178)] = 2858,
  [SMALL_STATE(179)] = 2869,
  [SMALL_STATE(180)] = 2880,
  [SMALL_STATE(181)] = 2893,
  [SMALL_STATE(182)] = 2904,
  [SMALL_STATE(183)] = 2915,
  [SMALL_STATE(184)] = 2926,
  [SMALL_STATE(185)] = 2937,
  [SMALL_STATE(186)] = 2945,
  [SMALL_STATE(187)] = 2955,
  [SMALL_STATE(188)] = 2963,
  [SMALL_STATE(189)] = 2971,
  [SMALL_STATE(190)] = 2981,
  [SMALL_STATE(191)] = 2989,
  [SMALL_STATE(192)] = 2999,
  [SMALL_STATE(193)] = 3009,
  [SMALL_STATE(194)] = 3019,
  [SMALL_STATE(195)] = 3027,
  [SMALL_STATE(196)] = 3037,
  [SMALL_STATE(197)] = 3045,
  [SMALL_STATE(198)] = 3055,
  [SMALL_STATE(199)] = 3063,
  [SMALL_STATE(200)] = 3073,
  [SMALL_STATE(201)] = 3083,
  [SMALL_STATE(202)] = 3093,
  [SMALL_STATE(203)] = 3101,
  [SMALL_STATE(204)] = 3111,
  [SMALL_STATE(205)] = 3118,
  [SMALL_STATE(206)] = 3125,
  [SMALL_STATE(207)] = 3130,
  [SMALL_STATE(208)] = 3137,
  [SMALL_STATE(209)] = 3144,
  [SMALL_STATE(210)] = 3149,
  [SMALL_STATE(211)] = 3156,
  [SMALL_STATE(212)] = 3161,
  [SMALL_STATE(213)] = 3168,
  [SMALL_STATE(214)] = 3175,
  [SMALL_STATE(215)] = 3182,
  [SMALL_STATE(216)] = 3189,
  [SMALL_STATE(217)] = 3194,
  [SMALL_STATE(218)] = 3199,
  [SMALL_STATE(219)] = 3206,
  [SMALL_STATE(220)] = 3210,
  [SMALL_STATE(221)] = 3214,
  [SMALL_STATE(222)] = 3218,
  [SMALL_STATE(223)] = 3222,
  [SMALL_STATE(224)] = 3226,
  [SMALL_STATE(225)] = 3230,
  [SMALL_STATE(226)] = 3234,
  [SMALL_STATE(227)] = 3238,
  [SMALL_STATE(228)] = 3242,
  [SMALL_STATE(229)] = 3246,
  [SMALL_STATE(230)] = 3250,
  [SMALL_STATE(231)] = 3254,
  [SMALL_STATE(232)] = 3258,
  [SMALL_STATE(233)] = 3262,
  [SMALL_STATE(234)] = 3266,
  [SMALL_STATE(235)] = 3270,
  [SMALL_STATE(236)] = 3274,
  [SMALL_STATE(237)] = 3278,
  [SMALL_STATE(238)] = 3282,
  [SMALL_STATE(239)] = 3286,
  [SMALL_STATE(240)] = 3290,
  [SMALL_STATE(241)] = 3294,
  [SMALL_STATE(242)] = 3298,
  [SMALL_STATE(243)] = 3302,
  [SMALL_STATE(244)] = 3306,
  [SMALL_STATE(245)] = 3310,
  [SMALL_STATE(246)] = 3314,
  [SMALL_STATE(247)] = 3318,
  [SMALL_STATE(248)] = 3322,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(248),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(245),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(133),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 3, .production_id = 8),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call, 3, .production_id = 8),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 1, .production_id = 1),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call, 1, .production_id = 1),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rescue_block, 2),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [147] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rescue_block, 3, .production_id = 14),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rescue_block, 5, .production_id = 23),
  [159] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(34),
  [162] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(38),
  [165] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(115),
  [168] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(74),
  [171] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(79),
  [174] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(211),
  [177] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(248),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2),
  [182] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(115),
  [185] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(22),
  [188] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(12),
  [191] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(245),
  [194] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(3),
  [197] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(48),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 1),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [206] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(37),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rescue_block, 3, .production_id = 12),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(163),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [217] = {.entry = {.count = 1, .reusable = false}}, SHIFT(124),
  [219] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [235] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(42),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [242] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [244] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [248] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [254] = {.entry = {.count = 1, .reusable = false}}, SHIFT(152),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list_with_trailing_comma, 2),
  [266] = {.entry = {.count = 1, .reusable = false}}, SHIFT(141),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list_with_trailing_comma, 3),
  [272] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [276] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [280] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [284] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [288] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 3, .production_id = 6),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 5, .production_id = 22),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float, 2),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 6, .production_id = 24),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 2, .production_id = 3),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer, 1),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer, 2),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 3, .production_id = 4),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_additive_operator, 2, .production_id = 2),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 4, .production_id = 13),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float, 1),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 4, .production_id = 15),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 4, .production_id = 16),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 2),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 4, .production_id = 17),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 3, .production_id = 5),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized_statements, 3),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 3),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 2),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char, 3),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call, 4, .production_id = 10),
  [334] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_additive_operator, 3, .production_id = 7),
  [336] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_begin_block, 5, .production_id = 21),
  [338] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 2),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 1),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [350] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(65),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [359] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(55),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [376] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list_with_trailing_comma, 1),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [382] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(58),
  [385] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_union_type, 3),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__inner_union_type, 3),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__inner_union_type_repeat1, 2),
  [403] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__inner_union_type_repeat1, 2), SHIFT_REPEAT(170),
  [406] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_union_type, 4),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [410] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__inner_union_type, 4),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [414] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_union_type_repeat1, 2),
  [416] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_union_type_repeat1, 2), SHIFT_REPEAT(178),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [425] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(62),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [432] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type, 1),
  [434] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__nested_union_type, 1),
  [436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__nested_union_type, 3),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [442] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alias, 4, .production_id = 11),
  [444] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type, 3),
  [446] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 5, .production_id = 18),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 4, .production_id = 9),
  [450] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [494] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__inner_union_type_repeat1, 2), SHIFT_REPEAT(177),
  [497] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [505] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [507] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_union_type_repeat1, 2), SHIFT_REPEAT(169),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [524] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [532] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [536] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [542] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [548] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [550] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [552] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [554] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [556] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [558] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [560] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [562] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [564] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [566] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [568] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [570] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [572] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [574] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 4, .production_id = 19),
  [576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [578] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 3, .production_id = 13),
  [580] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [582] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [584] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [586] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 4, .production_id = 20),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [590] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [592] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [594] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [596] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [600] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [608] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [610] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [612] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [614] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [616] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [618] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rescue_block, 6, .production_id = 25),
  [620] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_crystal_external_scanner_create(void);
void tree_sitter_crystal_external_scanner_destroy(void *);
bool tree_sitter_crystal_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_crystal_external_scanner_serialize(void *, char *);
void tree_sitter_crystal_external_scanner_deserialize(void *, const char *, unsigned);

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
    .external_scanner = {
      (const bool *)ts_external_scanner_states,
      ts_external_scanner_symbol_map,
      tree_sitter_crystal_external_scanner_create,
      tree_sitter_crystal_external_scanner_destroy,
      tree_sitter_crystal_external_scanner_scan,
      tree_sitter_crystal_external_scanner_serialize,
      tree_sitter_crystal_external_scanner_deserialize,
    },
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
