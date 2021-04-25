#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 5
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 11
#define ALIAS_COUNT 0
#define TOKEN_COUNT 6
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 2
#define PRODUCTION_ID_COUNT 1

enum {
  sym_nil = 1,
  sym_true = 2,
  sym_false = 3,
  sym_integer = 4,
  sym_float = 5,
  sym_source_file = 6,
  sym__statement = 7,
  sym__expression = 8,
  sym__bool = 9,
  aux_sym_source_file_repeat1 = 10,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_nil] = "nil",
  [sym_true] = "true",
  [sym_false] = "false",
  [sym_integer] = "integer",
  [sym_float] = "float",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym__bool] = "_bool",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_nil] = sym_nil,
  [sym_true] = sym_true,
  [sym_false] = sym_false,
  [sym_integer] = sym_integer,
  [sym_float] = sym_float,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym__bool] = sym__bool,
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
      if (eof) ADVANCE(21);
      if (lookahead == '0') ADVANCE(26);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 'n') ADVANCE(13);
      if (lookahead == 't') ADVANCE(16);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(27);
      END_STATE();
    case 1:
      if (lookahead == '0') ADVANCE(26);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(27);
      END_STATE();
    case 2:
      if (lookahead == '1') ADVANCE(5);
      if (lookahead == '3') ADVANCE(3);
      if (lookahead == '6') ADVANCE(7);
      if (lookahead == '8') ADVANCE(25);
      END_STATE();
    case 3:
      if (lookahead == '2') ADVANCE(25);
      END_STATE();
    case 4:
      if (lookahead == '2') ADVANCE(31);
      END_STATE();
    case 5:
      if (lookahead == '2') ADVANCE(9);
      if (lookahead == '6') ADVANCE(25);
      END_STATE();
    case 6:
      if (lookahead == '3') ADVANCE(4);
      if (lookahead == '6') ADVANCE(8);
      END_STATE();
    case 7:
      if (lookahead == '4') ADVANCE(25);
      END_STATE();
    case 8:
      if (lookahead == '4') ADVANCE(31);
      END_STATE();
    case 9:
      if (lookahead == '8') ADVANCE(25);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(14);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 13:
      if (lookahead == 'i') ADVANCE(15);
      END_STATE();
    case 14:
      if (lookahead == 'l') ADVANCE(17);
      END_STATE();
    case 15:
      if (lookahead == 'l') ADVANCE(22);
      END_STATE();
    case 16:
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 17:
      if (lookahead == 's') ADVANCE(12);
      END_STATE();
    case 18:
      if (lookahead == 'u') ADVANCE(11);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(34);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_nil);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_integer);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(19);
      if (lookahead == '_') ADVANCE(27);
      if (lookahead == 'b') ADVANCE(28);
      if (lookahead == 'f') ADVANCE(6);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'o') ADVANCE(29);
      if (lookahead == 'u') ADVANCE(2);
      if (lookahead == 'x') ADVANCE(30);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(32);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.') ADVANCE(19);
      if (lookahead == 'f') ADVANCE(6);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'u') ADVANCE(2);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'u') ADVANCE(2);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'u') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == 'i') ADVANCE(2);
      if (lookahead == 'u') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_float);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(6);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(34);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(6);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'f') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(34);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_nil] = ACTIONS(1),
    [sym_true] = ACTIONS(1),
    [sym_false] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_float] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(4),
    [sym__statement] = STATE(2),
    [sym__expression] = STATE(2),
    [sym__bool] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_nil] = ACTIONS(5),
    [sym_true] = ACTIONS(5),
    [sym_false] = ACTIONS(5),
    [sym_integer] = ACTIONS(7),
    [sym_float] = ACTIONS(5),
  },
  [2] = {
    [sym__statement] = STATE(3),
    [sym__expression] = STATE(3),
    [sym__bool] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym_nil] = ACTIONS(11),
    [sym_true] = ACTIONS(11),
    [sym_false] = ACTIONS(11),
    [sym_integer] = ACTIONS(13),
    [sym_float] = ACTIONS(11),
  },
  [3] = {
    [sym__statement] = STATE(3),
    [sym__expression] = STATE(3),
    [sym__bool] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(15),
    [sym_nil] = ACTIONS(17),
    [sym_true] = ACTIONS(17),
    [sym_false] = ACTIONS(17),
    [sym_integer] = ACTIONS(20),
    [sym_float] = ACTIONS(17),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [20] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [23] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
