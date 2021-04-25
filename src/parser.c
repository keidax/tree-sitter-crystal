#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 8
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 16
#define ALIAS_COUNT 0
#define TOKEN_COUNT 10
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  sym_nil = 1,
  sym_true = 2,
  sym_false = 3,
  sym_integer = 4,
  sym_float = 5,
  anon_sym_SQUOTE = 6,
  aux_sym_char_token1 = 7,
  anon_sym_SQUOTE2 = 8,
  sym_char_escape_sequence = 9,
  sym_source_file = 10,
  sym__statement = 11,
  sym__expression = 12,
  sym__bool = 13,
  sym_char = 14,
  aux_sym_source_file_repeat1 = 15,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym__bool] = "_bool",
  [sym_char] = "char",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
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
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym__bool] = sym__bool,
  [sym_char] = sym_char,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
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
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym__bool] = {
    .visible = false,
    .named = true,
  },
  [sym_char] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
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

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(36);
      if (lookahead == '\'') ADVANCE(52);
      if (lookahead == '0') ADVANCE(41);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead == 'f') ADVANCE(12);
      if (lookahead == 'n') ADVANCE(15);
      if (lookahead == 't') ADVANCE(18);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(35)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(42);
      END_STATE();
    case 1:
      if (lookahead == '\'') ADVANCE(52);
      END_STATE();
    case 2:
      if (lookahead == '0') ADVANCE(41);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(42);
      END_STATE();
    case 3:
      if (lookahead == '1') ADVANCE(6);
      if (lookahead == '3') ADVANCE(4);
      if (lookahead == '6') ADVANCE(8);
      if (lookahead == '8') ADVANCE(40);
      END_STATE();
    case 4:
      if (lookahead == '2') ADVANCE(40);
      END_STATE();
    case 5:
      if (lookahead == '2') ADVANCE(46);
      END_STATE();
    case 6:
      if (lookahead == '2') ADVANCE(10);
      if (lookahead == '6') ADVANCE(40);
      END_STATE();
    case 7:
      if (lookahead == '3') ADVANCE(5);
      if (lookahead == '6') ADVANCE(9);
      END_STATE();
    case 8:
      if (lookahead == '4') ADVANCE(40);
      END_STATE();
    case 9:
      if (lookahead == '4') ADVANCE(46);
      END_STATE();
    case 10:
      if (lookahead == '8') ADVANCE(40);
      END_STATE();
    case 11:
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead != 0) ADVANCE(51);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(16);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(39);
      END_STATE();
    case 15:
      if (lookahead == 'i') ADVANCE(17);
      END_STATE();
    case 16:
      if (lookahead == 'l') ADVANCE(19);
      END_STATE();
    case 17:
      if (lookahead == 'l') ADVANCE(37);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(20);
      END_STATE();
    case 19:
      if (lookahead == 's') ADVANCE(14);
      END_STATE();
    case 20:
      if (lookahead == 'u') ADVANCE(13);
      END_STATE();
    case 21:
      if (lookahead == '{') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 22:
      if (lookahead == '}') ADVANCE(53);
      END_STATE();
    case 23:
      if (lookahead == '}') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 24:
      if (lookahead == '}') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(23);
      END_STATE();
    case 25:
      if (lookahead == '}') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 26:
      if (lookahead == '}') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 27:
      if (lookahead == '}') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      END_STATE();
    case 28:
      if (lookahead == '\'' ||
          lookahead == '\\' ||
          lookahead == 'a' ||
          lookahead == 'b' ||
          lookahead == 'e' ||
          lookahead == 'f' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't' ||
          lookahead == 'v') ADVANCE(53);
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 29:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(48);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(49);
      END_STATE();
    case 31:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(27);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 34:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 35:
      if (eof) ADVANCE(36);
      if (lookahead == '\'') ADVANCE(50);
      if (lookahead == '0') ADVANCE(41);
      if (lookahead == 'f') ADVANCE(12);
      if (lookahead == 'n') ADVANCE(15);
      if (lookahead == 't') ADVANCE(18);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(35)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(42);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_nil);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_integer);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(29);
      if (lookahead == '_') ADVANCE(42);
      if (lookahead == 'b') ADVANCE(43);
      if (lookahead == 'f') ADVANCE(7);
      if (lookahead == 'i') ADVANCE(3);
      if (lookahead == 'o') ADVANCE(44);
      if (lookahead == 'u') ADVANCE(3);
      if (lookahead == 'x') ADVANCE(45);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(47);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(29);
      if (lookahead == 'f') ADVANCE(7);
      if (lookahead == 'i') ADVANCE(3);
      if (lookahead == 'u') ADVANCE(3);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(3);
      if (lookahead == 'u') ADVANCE(3);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(3);
      if (lookahead == 'u') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(3);
      if (lookahead == 'u') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_float);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(7);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(49);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(7);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(48);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_char_token1);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_SQUOTE2);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_char_escape_sequence);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 35},
  [2] = {.lex_state = 35},
  [3] = {.lex_state = 35},
  [4] = {.lex_state = 35},
  [5] = {.lex_state = 11},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 1},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
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
    [sym_source_file] = STATE(6),
    [sym__statement] = STATE(2),
    [sym__expression] = STATE(2),
    [sym__bool] = STATE(2),
    [sym_char] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_nil] = ACTIONS(5),
    [sym_true] = ACTIONS(5),
    [sym_false] = ACTIONS(5),
    [sym_integer] = ACTIONS(7),
    [sym_float] = ACTIONS(5),
    [anon_sym_SQUOTE] = ACTIONS(9),
  },
  [2] = {
    [sym__statement] = STATE(3),
    [sym__expression] = STATE(3),
    [sym__bool] = STATE(3),
    [sym_char] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(11),
    [sym_nil] = ACTIONS(13),
    [sym_true] = ACTIONS(13),
    [sym_false] = ACTIONS(13),
    [sym_integer] = ACTIONS(15),
    [sym_float] = ACTIONS(13),
    [anon_sym_SQUOTE] = ACTIONS(9),
  },
  [3] = {
    [sym__statement] = STATE(3),
    [sym__expression] = STATE(3),
    [sym__bool] = STATE(3),
    [sym_char] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(17),
    [sym_nil] = ACTIONS(19),
    [sym_true] = ACTIONS(19),
    [sym_false] = ACTIONS(19),
    [sym_integer] = ACTIONS(22),
    [sym_float] = ACTIONS(19),
    [anon_sym_SQUOTE] = ACTIONS(25),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(30), 1,
      sym_integer,
    ACTIONS(28), 6,
      ts_builtin_sym_end,
      sym_nil,
      sym_true,
      sym_false,
      sym_float,
      anon_sym_SQUOTE,
  [12] = 1,
    ACTIONS(32), 2,
      aux_sym_char_token1,
      sym_char_escape_sequence,
  [17] = 1,
    ACTIONS(34), 1,
      ts_builtin_sym_end,
  [21] = 1,
    ACTIONS(36), 1,
      anon_sym_SQUOTE2,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 12,
  [SMALL_STATE(6)] = 17,
  [SMALL_STATE(7)] = 21,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [22] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char, 3),
  [30] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char, 3),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [34] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
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
