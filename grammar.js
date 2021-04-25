module.exports = grammar({
  name: 'crystal',

  rules: {
    source_file: $ => repeat($._statement),

    _statement: $ => choice(
      $._expression,
      // TODO: add definitions, etc.
    ),

    _expression: $ => choice(
      $.nil,
      $.true,
      $.false,
      $.integer,
      $.float,
      $.char,
      // $.identifier,
      // TODO: other expressions
    ),

    nil: $ => 'nil',

    true: $ => 'true',
    false: $ => 'false',

    integer: $ => {

      const sign = /[-+]/

      const binary_literal = seq('0b', repeat(/[01_]/))
      const octal_literal = seq('0o', repeat(/[0-7_]/))
      const hex_literal = seq('0x', repeat(/[0-9a-fA-F_]/))

      const decimal = seq(/[1-9]/, repeat(/[0-9_]/))
      const leading_zero_decimal = choice(
        '0',
        seq('0_', repeat(/[0-9_]/))
      )

      const type_suffix = choice(
        'u8', 'u16', 'u32', 'u64', 'u128',
        'i8', 'i16', 'i32', 'i64', 'i128',
      )

      return token(seq(
        optional(sign),
        choice(
          binary_literal,
          octal_literal,
          hex_literal,
          leading_zero_decimal,
          decimal
        ),
        optional(type_suffix)
      ))
     },

    float: $ => {
      const digit_or_underscore = /[0-9_]/
      const sign = /[-+]/

      const leading_non_zero_value = seq(/[1-9]/, repeat(digit_or_underscore))
      const leading_zero_value = choice(
        '0',
        seq('0_', repeat(/[0-9_]/))
      )
      const leading_number = choice(
        leading_non_zero_value,
        leading_zero_value
      )

      const decimal_and_trailing_value = seq(/\.[0-9]/, repeat(digit_or_underscore))

      const exponent = seq(/[eE]/, optional(seq(optional(sign), repeat1(digit_or_underscore))))

      const float_suffix = choice('f32', 'f64')

      // A float must contain at least one of {decimal point, exponent, suffix}
      return token(choice(
        seq(optional(sign), leading_number, decimal_and_trailing_value, optional(exponent), optional(float_suffix)),
        seq(optional(sign), leading_number, optional(decimal_and_trailing_value), exponent, optional(float_suffix)),
        seq(optional(sign), leading_number, optional(decimal_and_trailing_value), optional(exponent), float_suffix),
      ))
    },

    char: $ => seq(
      '\'',
      choice(token.immediate(/[^\\]/), $.char_escape_sequence),
      token.immediate('\'')
    ),

    char_escape_sequence: $ => {
      const char_unicode_escape = seq('u', choice(
        /[0-9a-fA-F]{4}/,
        /\{[0-9a-fA-F]{1,6}\}/
      ))

      return token.immediate(seq('\\', choice(
        '0' ,'\\', '\'', 'a', 'b', 'e', 'f', 'n', 'r', 't', 'v', char_unicode_escape
      )))
    },
  }
});
