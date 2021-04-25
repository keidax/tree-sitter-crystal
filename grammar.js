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
      $._bool,
      $.integer,
      // $.identifier,
      // TODO: other expressions
    ),

    nil: $ => "nil",

    _bool: $ => choice($.true, $.false),
    true: $ => "true",
    false: $ => "false",

    integer: $ => {

      const leading_sign = /[-+]/

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
        optional(leading_sign),
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
  }
});
