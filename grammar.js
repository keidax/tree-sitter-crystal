const
  const_start = /[A-Z]/,
  ident_start = /[a-z_\u{00a0}-\u{10ffff}]/u,
  ident_part = /[0-9A-Za-z_\u{00a0}-\u{10ffff}]/u

const PREC = {
  CONDITIONAL: 30,
  RANGE: 35,
  OR: 40,
  AND: 45,
  BINARY_OR: 60,
  BINARY_AND: 65,
  SHIFT: 70,
  ADDITIVE: 75,
  MULTIPLICATIVE: 80,
  EXPONENTIAL: 85,
  UNARY: 90,
  DOT: 100,
}

module.exports = grammar({
  name: 'crystal',

  externals: $ => [
    $._line_break,

    $.unary_plus,
    $.unary_minus,
    $.binary_plus,
    $.binary_minus,

    $._unary_star,
    $._binary_star,
    $._unary_double_star,
    $._binary_double_star,

    $._beginless_range_operator,

    $._regular_if_keyword,
    $._modifier_if_keyword,

    $._regular_unless_keyword,
    $._modifier_unless_keyword,

    // These symbols are never actually returned. They signal the current scope
    // to the scanner.
    $._start_of_parenless_args,
    $._end_of_range,
  ],

  extras: $ => [
    /\s/,
    $.comment,
  ],

  word: $ => $.identifier,

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
      '(', $._statements, ')'
    ),

    _statement: $ => choice(
      $._expression,
      $.const_assign,
      $.module_def,
      $.class_def,
      $.alias,
      $.method_def,
      $.require,
      $.modifier_if,
      $.modifier_unless,

      $.return,
      $.next,
      $.break,
      // TODO:
      // struct
      // enum
      // lib
      // fun def
      // macro def
      // union
      // lib variables
      // lib type
    ),

    _expression: $ => choice(
      // Literals
      $.nil,
      $.true,
      $.false,
      $.integer,
      $.float,
      $.char,
      $.array,
      $.hash,
      $.string,
      alias($.operator_symbol, $.symbol),
      alias($.unquoted_symbol, $.symbol),
      alias($.quoted_symbol, $.symbol),
      $.range,
      alias($.beginless_range, $.range),
      $.tuple,
      $.named_tuple,
      // TODO: other expressions
      // regex
      // proc
      // `command`

      // Groupings
      alias($.empty_parens, $.nil),
      $._parenthesized_statements,
      $.begin_block,

      // Symbols
      $.self,
      $.constant,
      $.pseudo_constant,
      $.identifier,
      $.instance_var,
      $.class_var,

      // Control structures
      $.while,
      $.until,
      $.if,
      $.unless,
      $.conditional,
      // TODO
      // unless modifier
      // rescue modifier
      // case
      // macro interpolation
      // macro if
      // macro for
      // macro verbatim
      // macro fresh variables

      // Methods
      $.call,
      alias($.additive_operator, $.op_call),
      alias($.unary_additive_operator, $.op_call),
      alias($.multiplicative_operator, $.op_call),
      alias($.exponential_operator, $.op_call),
      alias($.shift_operator, $.op_call),
      alias($.complement_operator, $.op_call),
      alias($.binary_and_operator, $.op_call),
      alias($.binary_or_operator, $.op_call),
      $.assign,
      // TODO:
      // multi assignment
      // operator assignment
      // index operator
      // index assignment
      // annotations

      // Logical operators
      $.not,
      $.and,
      $.or,

      // Keywords and special methods
      // TODO
      // super
      // previous_def
      // typeof
      // is_a?
      // nil?
      // responds_to?
      // as
      // as?
      // pointerof
      // sizeof
      // instance_sizeof
      // offsetof
      // uninitialized
    ),

    comment: $ => /#.*/,

    empty_parens: $ => seq('(',')'),

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

    // TODO:
    // multiple string literals joined by backslashes
    // percent literals
    // heredocs
    string: $ => seq(
      '"',
      repeat(choice(
        token.immediate(prec(1, /[^\\"]/)),
        $.string_escape_sequence,
        $.ignored_backslash,
        $.interpolation,
      )),
      token.immediate('"'),
    ),

    ignored_backslash: $ => {
      return token.immediate(seq('\\',
        /[^\n\\"abefnrtuvx0-7]/
      ))
    },

    string_escape_sequence: $ => {
      const octal_escape = seq(/[0-7]{1,3}/)
      const hex_escape = seq('x', /[0-9a-fA-F]{2}/)

      const long_unicode_character = /[0-9a-fA-F]{1,6}/
      const unicode_escape = seq('u', choice(
        /[0-9a-fA-F]{4}/,
        seq('{', long_unicode_character, repeat(seq(' ', long_unicode_character)), '}')
      ))

      return token.immediate(seq('\\', choice(
        '\n', '\\', '"', 'a', 'b', 'e', 'f', 'n', 'r', 't', 'v',
        octal_escape, hex_escape, unicode_escape,
      )))
    },

    interpolation: $ => seq(
      token.immediate(prec(1, '#{')), $._expression, '}'
    ),

    operator_symbol: $ => token(seq(
      ':',
      token.immediate(
        choice(
          '+',
          '-',
          '*',
          '/',
          '%',
          '&',
          '|',
          '^',
          '**',
          '>>',
          '<<',
          '==',
          '!=',
          '<',
          '<=',
          '>',
          '>=',
          '<=>',
          '===',
          '[]',
          '[]?',
          '[]=',
          '!',
          '~',
          '!~',
          '=~',
        )
      )
    )),

    unquoted_symbol: $ => token(seq(
      ':',
      token.immediate(
        seq(
          choice(ident_start, const_start),
          repeat(ident_part),
          optional(/[?!]/)
        )
      )
    )),

    quoted_symbol: $ => seq(
      ':"',
      seq(
        repeat(choice(
          token.immediate(prec(1, /[^\\"]/)),
          $.string_escape_sequence,
          $.ignored_backslash,
        )),
        token.immediate('"'),
      ),
    ),

    array: $ => {
      const of_type = field('of', seq('of', $._type))

      return choice(
        seq(
          '[',
          $._expression,
          repeat(seq(',', $._expression, )),
          optional(','),
          ']',
          optional(of_type),
        ),
        seq(
          '[',
          ']',
          of_type,
        ),
      )
    },

    hash: $ => {
      const of_type = seq('of', field('of_key', $._type), '=>', field('of_value', $._type))

      return choice(
        seq(
          '{',
          $.hash_entry,
          repeat(seq(',', $.hash_entry)),
          optional(','),
          '}',
          optional(of_type),
        ),
        seq(
          '{',
          '}',
          of_type,
        ),
      )
    },

    hash_entry: $ => seq($._expression, "=>", $._expression),

    tuple: $ => seq(
      '{',
      $._expression,
      repeat(seq(',', $._expression)),
      optional(','),
      '}'
    ),

    named_tuple_entry: $ => {
      const symbol_name = alias(token(seq(choice(const_start, ident_start), repeat(ident_part))), $.identifier)
      const string_name = $.string

      return seq(
        choice(symbol_name, string_name),
        token.immediate(':'),
        $._expression,
      )
    },

    named_tuple: $ => seq(
      '{',
      $.named_tuple_entry,
      repeat(seq(',', $.named_tuple_entry)),
      optional(','),
      '}'
    ),

    range: $ => {
      const begin = field('begin', $._expression)
      const range_op = field('operator', alias(choice('..', '...'), $.operator))
      const end = field('end', $._expression)

      return prec.left(PREC.RANGE, seq(
        begin,
        range_op,
        optional($._end_of_range),
        optional(end),
      ))
    },

    beginless_range: $ => {
      const range_op = field('operator', alias($._beginless_range_operator, $.operator))
      const end = field('end', $._expression)

      return prec.left(PREC.RANGE, seq(
        range_op,
        optional($._end_of_range),
        optional(end),
      ))
    },

    module_def: $ => seq(
      'module',
      field('name', $.constant), // TODO: generics
      seq(optional($._statements)),
      'end'
    ),

    class_def: $ => seq(
      'class',
      field('name', choice($.constant)), // TODO: generics
      optional(seq(
        '<', field('superclass', $.constant)
      )),
      seq(optional($._statements)),
      'end'
    ),

    method_def: $ => {
      // TODO:
      // visibility
      // abstract
      // forall
      // class methods
      const name = field('name', choice($.identifier, alias($.identifier_method_call, $.identifier)))
      const params = seq('(', field('params', optional($.param_list)), ')')
      const return_type = field('type', seq(/[ \t]:\s/, $._type))


      return prec(1, seq(
        'def',
        name,
        optional(params),
        optional(return_type),
        optional($._statements),
        'end'
      ))
    },

    param_list: $ => seq($.param, repeat(seq(',', $.param)), optional(',')),

    param: $ => {
      const extern_name = field('extern_name', $.identifier)
      const name = field('name', choice($.identifier, $.instance_var, $.class_var))
      const type = field('type', seq(/[ \t]:\s/, $._type))
      const default_value = field('default', seq('=', $._expression))

      return prec(1, seq(
        optional(extern_name),
        name,
        optional(type),
        optional(default_value)
      ))
    },

    // TODO:
    // splat_param
    // double splat_param
    // block param

    return: $ => seq('return', optional($._expression)),

    next: $ => seq('next', optional($._expression)),

    break: $ => seq('break', optional($._expression)),

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

    pseudo_constant: $ => choice(
      "__LINE__",
      "__END_LINE__",
      "__FILE__",
      "__DIR__",
    ),

    identifier: $ => token(seq(ident_start, repeat(ident_part))),
    identifier_method_call: $ => token(seq(ident_start, repeat(ident_part), /[?!]/)),

    instance_var: $ => token(seq("@", ident_start, repeat(ident_part))),

    class_var: $ => token(seq("@@", ident_start, repeat(ident_part))),

    self: $ => 'self',

    _type: $ => choice(
      seq('(', $._type, ')'),
      $.constant,
      $.union_type,
      // TODO: rest of type grammar
      // nilable
      // pointer
      // static array
      // tuple
      // named tuple
      // proc
      // self
      // class
      // underscore
      // typeof
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

    _dot_call: $ => prec(PREC.DOT, seq(
      field('receiver', $._expression),
      '.',
      field('method', choice(
        $.identifier,
        alias($.identifier_method_call, $.identifier),
        // TODO: include operator calls
      )),
    )),

    call: $ => {
      const receiver_call = choice(
        $._dot_call,
        field('method', alias($.identifier_method_call, $.identifier)),
      )
      const ambiguous_call = field('method', $.identifier)

      const argument_list = field('arguments', choice(
        alias($.argument_list_with_parens, $.argument_list),
        alias($.argument_list_no_parens, $.argument_list),
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
      return choice(
        seq(receiver_call, optional(argument_list)),
        seq(ambiguous_call, argument_list),
      )
    },

    // A subset of method calls that can be the LHS of an assignment
    assign_call: $ => {
      const receiver = field('receiver', $._expression)
      const method_identifier = field('method', $.identifier)

      return prec(PREC.DOT, seq(receiver, '.', method_identifier))
    },

    not: $ => prec(PREC.UNARY, seq('!', $._expression)),
    and: $ => prec.left(PREC.AND, seq($._expression, '&&', $._expression)),
    or: $ => prec.left(PREC.OR, seq($._expression, '||', $._expression)),

    additive_operator: $ => {
      const operator = choice($.binary_plus, $.binary_minus, '&+', '&-')

      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.left(PREC.ADDITIVE,
        seq(receiver, method, arg),
      )
    },

    unary_additive_operator: $ => {
      const operator = choice($.unary_plus, $.unary_minus) // TODO: &+ and &-

      return prec(PREC.UNARY, seq(
        field('operator', alias(operator, $.operator)),
        field('receiver', $._expression)
      ))
    },

    multiplicative_operator: $ => {
      const operator = choice($._binary_star, '&*', '/', '//', '%')

      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.left(PREC.MULTIPLICATIVE, seq(
        receiver, method, arg
      ))
    },

    exponential_operator: $ => {
      const operator = choice($._binary_double_star, '&**')

      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.right(PREC.EXPONENTIAL, seq(
        receiver, method, arg
      ))
    },

    shift_operator: $ => {
      const operator = choice('<<', '>>')

      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.left(PREC.SHIFT, seq(
        receiver, method, arg
      ))
    },

    complement_operator: $ => {
      const operator = '~'

      return prec(PREC.UNARY, seq(
        field('operator', alias(operator, $.operator)),
        field('receiver', $._expression)
      ))
    },

    binary_and_operator: $ => {
      const operator = '&'
      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.left(PREC.BINARY_AND, seq(
        receiver, method, arg
      ))
    },

    binary_or_operator: $ => {
      const operator = choice('|', '^')
      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.left(PREC.BINARY_OR, seq(
        receiver, method, arg
      ))
    },

    // TODO: does this need prec?
    splat: $ => seq($._unary_star, $._expression),

    double_splat: $ => seq($._unary_double_star, $._expression),

    argument_list_no_parens: $ => {
      const arguments = [$._expression, $.splat, $.double_splat]

      return prec.right(seq(
        choice(
          $._start_of_parenless_args,
          ...arguments,
        ),
        repeat(seq(',', choice(...arguments)))
      ))
    },

    argument_list_with_parens: $ => {
      const arguments = [$._expression, $.splat]

      return prec.right(seq(
        token.immediate('('),
        optional(seq(
          choice(...arguments),
          repeat(seq(',', choice(...arguments))),
          optional(','),
        )),
        ')'
      ))
    },

    assign: $ => {
      const lhs = field('lhs', choice($.identifier, $.instance_var, $.class_var, $.assign_call))
      const rhs = field('rhs', $._expression)

      return seq(
        lhs, '=', rhs
      )
    },

    const_assign: $ => {
      const lhs = field('lhs', $.constant)
      const rhs = field('rhs', $._statement)

      return prec.right(seq(
        lhs, '=', rhs
      ))
    },

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
    },

    while: $ => seq(
      'while',
      field('condition', $._expression),
      $._terminator,
      optional($._statements),
      'end'
    ),

    until: $ => seq(
      'until',
      field('condition', $._expression),
      $._terminator,
      optional($._statements),
      'end'
    ),

    if: $ => {
      const cond = field('cond', $._expression)
      const then = field('then', $.then)
      const else_ = field('else', choice($.elsif, $.else))

      return seq(
        $._regular_if_keyword,
        cond,
        $._terminator,
        optional(then),
        optional(else_),
        'end',
      )
    },

    unless: $ => {
      const cond = field('cond', $._expression)
      const then = field('then', $.then)
      const else_ = field('else', $.else)

      return seq(
        $._regular_unless_keyword,
        cond,
        $._terminator,
        optional(then),
        optional(else_),
        'end',
      )
    },

    then: $ => seq($._statements),

    elsif: $ => {
      const cond = field('cond', $._expression)
      const then = field('then', $.then)
      const else_ = field('else', choice($.elsif, $.else))

      return seq(
        'elsif',
        cond,
        $._terminator,
        optional(then),
        optional(else_),
      )

    },

    else: $ => seq('else', optional($._statements)),

    conditional: $ => prec.right(PREC.CONDITIONAL,seq(
      field('cond', $._expression),
      '?',
      field('then', $._expression),
      ':',
      field('else', $._expression)
    )),

    modifier_if: $ => seq(
      field('then', $._statement),
      $._modifier_if_keyword,
      field('cond', $._expression)
    ),

    modifier_unless: $ => seq(
      field('then', $._statement),
      $._modifier_unless_keyword,
      field('cond', $._expression)
    ),

    require: $ => seq('require', $.string),
  }
});
