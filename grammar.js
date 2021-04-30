const
  const_start = /[A-Z]/,
  ident_start = /[a-z_\u{00a0}-\u{10ffff}]/u,
  ident_part = /[0-9A-Za-z_\u{00a0}-\u{10ffff}]/u

const PREC = {
  CALL: 50,
  ADDITIVE: 75,
  UNARY: 90,
}

module.exports = grammar({
  name: 'crystal',

  externals: $ => [
    $._line_break,

    $.unary_plus,
    $.unary_minus,
	$.binary_plus,
	$.binary_minus,
  ],

  rules: {
    source_file: $ => seq(
      optional($._statements)
    ),

    _terminator: $ => choice($._line_break, ';'),

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
      // Literals
      $.nil,
      $.true,
      $.false,
      $.integer,
      $.float,
      $.char,
      // TODO: other expressions
      // string
      // symbol
      // array
      // hash
      // tuple

      // Groupings
      $._parenthesized_statements,
      $.begin_block,

      // Symbols
      $.constant,
      $.identifier,

      // Methods
      $.call,
      alias($.additive_operator, $.call),
      alias($.unary_additive_operator, $.call),
    ),

    nil: $ => 'nil',

    true: $ => 'true',
    false: $ => 'false',

    integer: $ => {
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

      const numeric_component = seq(
        choice(
          binary_literal,
          octal_literal,
          hex_literal,
          leading_zero_decimal,
          decimal
        ),
        optional(type_suffix)
      )

      const sign = choice(alias($.unary_minus, '-'), alias($.unary_plus, '+'))

      return choice(
        seq(sign, token.immediate(numeric_component)),
        token(numeric_component),
      )
    },

    float: $ => {
      const digit_or_underscore = /[0-9_]/

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

      const exponent = seq(/[eE]/, optional(seq(optional(/[+-]/), repeat1(digit_or_underscore))))

      const float_suffix = choice('f32', 'f64')

      // A float must contain at least one of {decimal point, exponent, suffix}
      const numeric_component = choice(
        seq(leading_number, decimal_and_trailing_value, optional(exponent), optional(float_suffix)),
        seq(leading_number, optional(decimal_and_trailing_value), exponent, optional(float_suffix)),
        seq(leading_number, optional(decimal_and_trailing_value), optional(exponent), float_suffix),
      )

      const sign = choice(alias($.unary_minus, '-'), alias($.unary_plus, '+'))

      return choice(
        seq(sign, token.immediate(numeric_component)),
        token(numeric_component)
      )
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

    identifier: $ => token(seq(ident_start, repeat(ident_part))),
    identifier_method_call: $ => token(seq(ident_start, repeat(ident_part), /[?!]/)),

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

    call: $ => {
      const receiver = field('receiver', seq($._expression, '.'))

      const method_identifier = field('method', alias($.identifier_method_call, $.identifier))
      const optional_method_identifier = field('method', choice($.identifier, alias($.identifier_method_call, $.identifier)))

      const argument_list = field('arguments', choice(
        seq(
          '(',
          optional(alias(
            $.argument_list_with_trailing_comma,
            $.argument_list,
          )),
          ')'
        ),
        $.argument_list
      ))

      // how do we distingush a method call from a variable?
      // at least one of these is required:
      // - receiver
      // - ends in ? or !
      // - parentheses
      // - arguments
      // - block arg

      // TODO:
      // named arguments
      // blocks
      return prec(PREC.CALL, seq(choice(
        seq(receiver, optional_method_identifier, optional(argument_list)),
        seq(optional(receiver), method_identifier, optional(argument_list)),
        seq(optional(receiver), optional_method_identifier, argument_list),
      )))
    },

    additive_operator: $ => {
      const operator = choice($.binary_plus, $.binary_minus, '&+', '&-')
      const whitespace = /\s+/

      const receiver = field('receiver', $._expression)
      const method = field('method', alias(operator, $.identifier))
      const arg = field('arguments', $._expression)

      return prec.left(PREC.ADDITIVE,
        seq(receiver, method, arg),
      )
    },

    unary_additive_operator: $ => {
      const operator = choice($.unary_plus, $.unary_minus) // TODO: &+ and &-

      return prec(PREC.UNARY, seq(
        field('method', alias(operator, $.identifier)),
        field('receiver', $._expression)
      ))
    },

    argument_list: $ => prec.right(1, seq($._expression, repeat(seq(',', $._expression)))),
    argument_list_with_trailing_comma: $ => prec.right(1, seq($._expression, repeat(seq(',', $._expression)), optional(','))),

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
