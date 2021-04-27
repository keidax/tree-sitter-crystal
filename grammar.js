const
  const_start = /[A-Z]/,
  ident_start = /[A-Za-z_\u{00a0}-\u{10ffff}]/u,
  ident_part = /[0-9A-Za-z_\u{00a0}-\u{10ffff}]/u

module.exports = grammar({
  name: 'crystal',

  rules: {
    source_file: $ => seq(
      optional($._statements)
    ),

    _terminator: $ => choice('\n', ';'),

    _statements: $ => choice(
      seq(
        repeat1(
          choice(
            seq($._statement, $._terminator),
            prec(-1, ';'),
          )
        ),
        optional($._statement)
      ),
      $._statement
    ),

    _parenthesized_statements: $ => seq(
      '(', optional($._statements), ')'
    ),

    _statement: $ => choice(
      $._expression,
      $.module,
      $.alias,
      // TODO:
      // class
      // lib
      // const
    ),

    _expression: $ => choice(
      $._parenthesized_statements,
      $.nil,
      $.true,
      $.false,
      $.integer,
      $.float,
      $.char,
      $.constant,
      // TODO: other expressions
      // string
      // symbol
      // array
      // hash
      // tuple
      $.begin_block,
      // begin/end
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

    module: $ => seq(
      'module',
      field('name', choice($.constant)), // TODO: generics
      $._terminator,
      field('body', optional($._statements)),
      'end'
    ),

    constant: $ => {
      const constant_segment = seq(const_start, repeat(ident_part))
      return token(seq(
        optional('::'),
        constant_segment,
        repeat(
          seq('::', constant_segment)
        ),
      ))
    },

    identifier: $ => seq(ident_start, repeat(ident_part)),

    _type: $ => choice(
      seq('(', $._type, ')'),
      $.constant,
      $.union_type,
      // TODO: rest of type grammar
      // Any types added here should also be added to _nested_union
    ),

    union_type: $ => prec.right(seq(
      $._nested_union_type, "|", $._nested_union_type, repeat(prec(1, seq("|", $._nested_union_type)))
    )),

    // Any nested union types are flattened
    _nested_union_type: $ => prec(1, choice(
      seq('(', $._nested_union_type, ')'),
      $.constant,
      $._inner_union_type,
    )),

    _inner_union_type: $ => prec.right(-1, seq(
      $._nested_union_type, "|", $._nested_union_type, repeat(seq("|", $._nested_union_type))
    )),

    alias: $ => seq(
      'alias',
      field('name', $.constant),
      '=',
      field('type', $._type)
    ),

    begin_block: $ => seq(
      'begin',
      optional($._terminator),
      field('body', optional($._statements)),
      field('rescue', optional($.rescue_block)),
      // TODO: else, ensure
      'end'
    ),

    rescue_block: $ => {
      const rescue_variable = field('variable', $.identifier)
      const rescue_type = field('type', $._type) // TODO: the entire type grammar isn't really valid here
      const rescue_body = field('body', optional($._statements))

      return seq(
        'rescue',
        optional(choice(
          seq(rescue_variable, ': ', rescue_type),
          rescue_variable,
          rescue_type,
        )),
        $._terminator,
        rescue_body
      )
    }
  }
});
