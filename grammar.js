const
  const_start = /[A-Z]/,
  ident_start = /[a-z_\u{00a0}-\u{10ffff}]/u,
  ident_part = /[0-9A-Za-z_\u{00a0}-\u{10ffff}]/u

// All the operators that can used as unquoted symbols or in dot calls.
// A few operators like '&&', '||', and '..' are not included here.
const operator_tokens = [
  '+',
  '-',
  '*',
  '/',
  '//',
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
  '&+',
  '&-',
  '&*',
  '&**',
]

module.exports = grammar({
  name: 'crystal',

  externals: $ => [
    $._line_break,

    $._start_of_brace_block,

    $._start_of_index_operator,

    // To help the parser deal with a state like
    //   with foo yield yield
    // we insert an invisible token just before the first yield, which signals
    // the end of the "with" expression.
    $._end_of_with_expression,

    $.unary_plus,
    $.unary_minus,
    $.binary_plus,
    $.binary_minus,

    $.unary_wrapping_plus,
    $.unary_wrapping_minus,
    $.binary_wrapping_plus,
    $.binary_wrapping_minus,

    $._unary_star,
    $._binary_star,
    $._unary_double_star,
    $._binary_double_star,

    $._beginless_range_operator,

    $._regex_start,
    $._binary_slash,
    $._binary_double_slash,

    $._regular_if_keyword,
    $._modifier_if_keyword,

    $._regular_unless_keyword,
    $._modifier_unless_keyword,

    $._modulo_operator,

    $._string_percent_literal_start,
    $._command_percent_literal_start,
    $._string_array_percent_literal_start,
    $._symbol_array_percent_literal_start,
    $._regex_percent_literal_start,
    $._percent_literal_end,
    $._delimited_string_contents,
    $._delimited_array_element_start,
    $._delimited_array_element_end,

    $.regex_modifier,

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

  precedences: $ => [
    // Operator precedence, as defined by
    // https://crystal-lang.org/reference/1.4/syntax_and_semantics/operators.html#operator-precedence
    [
      'index_operator',
      'dot_operator',
      'unary_operator',
      'exponential_operator',
      'multiplicative_operator',
      'additive_operator',
      'shift_operator',
      'binary_and_operator',
      'binary_or_operator',
      'logical_and_operator',
      'logical_or_operator',
      'range_operator',
      'ternary_operator',
      'assignment_operator',
      'splat_operator',
      $.named_arg,
      'comma',
    ],

    // Operator precedence for the type grammar
    [
      $.union_type,
      $.proc_type,
    ],

    // Ensure `*a = b` parses as `(*a) = b`, when encountered as a standalone statement
    [
      $.lhs_splat,
      'assignment_operator',
    ],

    // Ensure `a b { 1 }` parses as `a(b { 1 })`
    [
      'brace_block_call',
      $._expression,
    ],

    // Ensure `a b do 1 end` parses as `a(b) do 1 end`
    [
      $._expression,
      'do_end_block_call',
    ],

    // Ensure `a b() { 1 }` parses as `a(b() { 1 })`
    [
      'brace_block_call',
      'no_block_call',
    ],

    // Ensure `a b() do 1 end` parses as `a(b()) do 1 end`
    [
      'no_block_call',
      'do_end_block_call',
    ],

    // Ensure `[] of A | B` parses as `[] of (A | B)`
    [
      $.union_type,
      $.array,
    ],

    // Ensure `[ [] of Int32, Int32 -> String ]` resolves to ` [ [] of (Int32, Int32 -> String) ]`
    [
      $.proc_type,
      $.array,
    ],

    // Ensure `{} of K => A | B` parses as `{} of K => (A | B)`
    [
      $.union_type,
      $.hash,
    ],
  ],

  conflicts: $ => [
    // When the parser is in this state:
    //   def foo(bar : String,
    //                       ^
    // we need to consider both of these interpretations as legitimate:
    //   def foo(bar : String, baz : String)
    // and
    //   def foo(bar : String, String -> Int32)
    [
      $.param, $.proc_type,
    ],

    // Splat and double splat parameters are similar situations to above
    [
      $.splat_param, $.proc_type,
    ],
    [
      $.double_splat_param, $.proc_type,
    ],


    // When the parser is in this state:
    //   { {} of A => B,
    //                 ^
    // we need to consider both of these interpretations as legitimate:
    //   { {} of A => B, 77 }
    // and
    //   { {} of A => B, C -> D }
    // (which is equivalent to)
    //   { {} of A => Proc(B, C, D) }
    [
      $.hash, $.proc_type,
    ],
  ],

  rules: {
    source_file: $ => seq(
      optional($._statements),
    ),

    _terminator: $ => choice($._line_break, ';'),

    _statements: $ => choice(
      seq(
        repeat1(
          choice(
            seq($._statement, $._terminator),
            prec(-1, ';'),
          ),
        ),
        optional($._statement),
      ),
      $._statement,
    ),

    _parenthesized_statements: $ => seq(
      '(', $._statements, ')',
    ),

    _statement: $ => choice(
      $._expression,
      $.const_assign,
      $.multi_assign,
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
      alias($.string_percent_literal, $.string),
      alias($.string_array_percent_literal, $.array),
      alias($.operator_symbol, $.symbol),
      alias($.unquoted_symbol, $.symbol),
      alias($.quoted_symbol, $.symbol),
      alias($.symbol_array_percent_literal, $.array),
      $.range,
      alias($.beginless_range, $.range),
      $.tuple,
      $.named_tuple,
      $.proc,
      $.command,
      alias($.command_percent_literal, $.command),
      $.regex,
      alias($.regex_percent_literal, $.regex),

      // Groupings
      alias($.empty_parens, $.nil),
      $._parenthesized_statements,
      $.begin_block,

      // Symbols
      $.self,
      $.constant,
      $.pseudo_constant,
      $.special_variable,
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
      alias($.index_operator, $.index_call),
      $.assign,
      alias($.operator_assign, $.op_assign),
      // TODO:
      // annotations

      // Logical operators
      $.not,
      $.and,
      $.or,

      // Keywords and special methods
      $.yield,
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

    empty_parens: $ => seq('(', ')'),

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
        seq('0_', repeat(/[0-9_]/)),
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
          decimal,
        ),
        optional(type_suffix),
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
        seq('0_', repeat(/[0-9_]/)),
      )
      const leading_number = choice(
        leading_non_zero_value,
        leading_zero_value,
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
        token(numeric_component),
      )
    },

    char: $ => seq(
      '\'',
      choice(token.immediate(/[^\\]/), $.char_escape_sequence),
      token.immediate('\''),
    ),

    char_escape_sequence: $ => {
      const char_unicode_escape = seq('u', choice(
        /[0-9a-fA-F]{4}/,
        /\{[0-9a-fA-F]{1,6}\}/,
      ))

      return token.immediate(seq('\\', choice(
        '0', '\\', '\'', 'a', 'b', 'e', 'f', 'n', 'r', 't', 'v', char_unicode_escape,
      )))
    },

    // TODO:
    // multiple string literals joined by backslashes
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
        /[^\n\\"abefnrtuvx0-7]/,
      ))
    },

    string_escape_sequence: $ => {
      const octal_escape = seq(/[0-7]{1,3}/)
      const hex_escape = seq('x', /[0-9a-fA-F]{2}/)

      const long_unicode_character = /[0-9a-fA-F]{1,6}/
      const unicode_escape = seq('u', choice(
        /[0-9a-fA-F]{4}/,
        seq('{', long_unicode_character, repeat(seq(' ', long_unicode_character)), '}'),
      ))

      return token.immediate(seq('\\', choice(
        '\n', '\\', '"', 'a', 'b', 'e', 'f', 'n', 'r', 't', 'v',
        octal_escape, hex_escape, unicode_escape,
      )))
    },

    interpolation: $ => seq(
      token.immediate(prec(1, '#{')), $._expression, '}',
    ),

    string_percent_literal: $ => seq(
      $._string_percent_literal_start,
      repeat(choice(
        $._delimited_string_contents,
        $.interpolation,
        $.string_escape_sequence,
        $.ignored_backslash,
      )),
      $._percent_literal_end,
    ),

    string_array_percent_literal: $ => seq(
      $._string_array_percent_literal_start,
      repeat(
        alias($.percent_literal_array_word, $.string),
      ),
      $._percent_literal_end,
    ),

    symbol_array_percent_literal: $ => seq(
      $._symbol_array_percent_literal_start,
      repeat(
        alias($.percent_literal_array_word, $.symbol),
      ),
      $._percent_literal_end,
    ),

    percent_literal_array_word: $ => seq(
      $._delimited_array_element_start,
      repeat(choice(
        $._delimited_string_contents,
        $.ignored_backslash,
      )),
      $._delimited_array_element_end,
    ),

    operator_symbol: $ => token(seq(
      ':',
      token.immediate(
        choice(...operator_tokens),
      ),
    )),

    unquoted_symbol: $ => token(seq(
      ':',
      token.immediate(
        seq(
          choice(ident_start, const_start),
          repeat(ident_part),
          optional(/[?!]/),
        ),
      ),
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

    command: $ => seq(
      '`',
      repeat(choice(
        token.immediate(prec(1, /[^\\`]/)),
        $.string_escape_sequence,
        $.ignored_backslash,
        $.interpolation,
      )),
      token.immediate('`'),
    ),

    command_percent_literal: $ => seq(
      $._command_percent_literal_start,
      repeat(choice(
        $._delimited_string_contents,
        $.interpolation,
        $.string_escape_sequence,
        $.ignored_backslash,
      )),
      $._percent_literal_end,
    ),

    regex: $ => seq(
      $._regex_start,
      repeat(choice(
        token.immediate(prec(1, /[^\\/]/)),
        $.regex_escape_sequence,
        $.interpolation,
      )),
      token.immediate('/'),
      optional($.regex_modifier),
    ),

    regex_escape_sequence: $ => {
      // These are PCRE escape sequences
      const octal_escape = seq(/[0-7]{1,3}/)
      const long_octal_escape = seq('o{', repeat1(/[0-7]/), '}')

      const hex_escape = seq('x', /[0-9a-fA-F]{1,2}/)
      const long_hex_escape = seq('x{', repeat1(/[0-9a-fA-F]/), '}')

      const ctrl_escape = seq(/c[\x01-\x7f]/) // eslint-disable-line no-control-regex

      // TODO: handle rest of PCRE escape syntax:
      // https://www.pcre.org/original/doc/html/pcresyntax.html

      return token.immediate(seq('\\', choice(
        '/', '\\', 'a', 'e', 'f', 'n', 'r', 't',
        octal_escape, long_octal_escape,
        hex_escape, long_hex_escape,
        ctrl_escape,
      )))
    },

    regex_percent_literal: $ => seq(
      $._regex_percent_literal_start,
      repeat(choice(
        $._delimited_string_contents,
        $.regex_escape_sequence,
        $.ignored_backslash,
        $.interpolation,
      )),
      $._percent_literal_end,
      optional($.regex_modifier),
    ),

    array: $ => {
      const of_type = field('of', seq('of', $._type))

      return choice(
        seq(
          '[',
          $._expression,
          repeat(seq(',', $._expression)),
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

    hash_entry: $ => seq($._expression, '=>', $._expression),

    tuple: $ => seq(
      '{',
      $._expression,
      repeat(seq(',', $._expression)),
      optional(','),
      '}',
    ),

    named_tuple_entry: $ => {
      const symbol_name = alias(
        token(seq(choice(const_start, ident_start), repeat(ident_part))),
        $.identifier,
      )
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
      '}',
    ),

    range: $ => {
      const begin = field('begin', $._expression)
      const range_op = field('operator', alias(choice('..', '...'), $.operator))
      const end = field('end', $._expression)

      return prec.left('range_operator', seq(
        begin,
        range_op,
        optional($._end_of_range),
        optional(end),
      ))
    },

    beginless_range: $ => {
      const range_op = field('operator', alias($._beginless_range_operator, $.operator))
      const end = field('end', $._expression)

      return prec.left('range_operator', seq(
        range_op,
        optional($._end_of_range),
        optional(end),
      ))
    },

    proc: $ => {
      const params = seq(
        '(',
        field('params', optional(alias($.proc_param_list, $.param_list))),
        ')',
      )
      const return_type = field('type', seq(/:\s/, $._type))
      const block = field('block', choice(
        alias($.do_end_block, $.block),
        alias($.brace_block, $.block),
      ))

      return seq(
        '->',
        optional(params),
        optional(return_type),
        block,
      )
    },

    proc_param_list: $ => seq(
      $.param,
      repeat(seq(',', $.param)),
      optional(','),
    ),

    module_def: $ => seq(
      'module',
      field('name', $.constant), // TODO: generics
      seq(optional($._statements)),
      'end',
    ),

    class_def: $ => seq(
      'class',
      field('name', choice($.constant)), // TODO: generics
      optional(seq(
        '<', field('superclass', $.constant),
      )),
      seq(optional($._statements)),
      'end',
    ),

    method_def: $ => {
      // TODO:
      // visibility
      // abstract
      // forall
      // class methods
      const name = field('name', choice(
        $.identifier,
        alias($.identifier_method_call, $.identifier),
      ))
      const params = seq('(', field('params', optional($.param_list)), ')')
      const return_type = field('type', seq(/[ \t]:\s/, $._type))

      // Method defs require at least one of the following after the name
      // - parameters wrapped in ()
      // - a return type
      // - a newline or semicolon
      //
      // In other words, these are all valid:
      //   def foo(bar) end
      //   def foo : Bool true end
      //   def foo; end
      const param_spec = choice(
        seq(params, optional(return_type), optional($._terminator)),
        seq(optional(params), return_type, optional($._terminator)),
        seq(optional(params), optional(return_type), $._terminator),
      )

      return seq(
        'def',
        name,
        param_spec,
        optional($._statements),
        'end',
      )
    },

    param_list: $ => {
      // Splat and double splat params have restrictions on where they can appear in the parameter
      // list: https://crystal-lang.org/reference/1.4/syntax_and_semantics/default_values_named_arguments_splats_tuples_and_overloading.html
      // However, it's much simpler for the grammar to treat them interchangably. (Otherwise the
      // repeats and comma placement would be ugly.) We'll leave the rest up to the compiler.
      const param = choice($.param, $.splat_param, $.double_splat_param)

      return choice(
        seq(
          param,
          repeat(seq(',', param)),
          optional(seq(',', optional($.block_param))),
        ),
        $.block_param,
      )
    },

    param: $ => {
      const extern_name = field('extern_name', $.identifier)
      const name = field('name', choice($.identifier, $.instance_var, $.class_var))
      const type = field('type', seq(/[ \t]:\s/, $._type))
      const default_value = field('default', seq('=', $._expression))

      return seq(
        optional(extern_name),
        name,
        optional(type),
        optional(default_value),
      )
    },

    splat_param: $ => {
      const name = field('name', choice($.identifier, $.instance_var, $.class_var))
      const type = field('type', seq(/[ \t]:\s/, $._type))

      return seq(
        '*',
        optional(name),
        optional(type),
      )
    },

    double_splat_param: $ => {
      const name = field('name', choice($.identifier, $.instance_var, $.class_var))
      const type = field('type', seq(/[ \t]:\s/, $._type))

      return seq(
        '**',
        name,
        optional(type),
      )
    },

    block_param: $ => {
      const name = field('name', choice($.identifier, $.instance_var, $.class_var))
      const type = field('type', seq(/:\s/, $._type))

      return seq(
        '&',
        optional(name),
        optional(type),
      )
    },

    return: $ => seq('return', optional($._expression)),

    next: $ => seq('next', optional($._expression)),

    break: $ => seq('break', optional($._expression)),

    yield: $ => {
      const with_expr = field('with', $._expression)

      const argument_list = field('arguments', choice(
        alias($.argument_list_with_parens, $.argument_list),
        alias($.argument_list_no_parens, $.argument_list),
      ))

      return seq(
        optional(seq('with', with_expr, $._end_of_with_expression)),
        'yield',
        optional(argument_list),
      )
    },

    constant: $ => {
      const constant_segment = seq(const_start, repeat(ident_part))
      return token(seq(
        optional('::'),
        constant_segment,
        repeat(
          seq('::', constant_segment),
        ),
      ))
    },

    pseudo_constant: $ => choice(
      '__LINE__',
      '__END_LINE__',
      '__FILE__',
      '__DIR__',
    ),

    special_variable: $ => token(choice(
      '$?',
      '$~',
      /\$[0-9]+/,
      /\$[0-9]+\?/,
    )),

    identifier: $ => token(seq(ident_start, repeat(ident_part))),
    identifier_method_call: $ => token(seq(ident_start, repeat(ident_part), /[?!]/)),

    instance_var: $ => token(seq('@', ident_start, repeat(ident_part))),

    class_var: $ => token(seq('@@', ident_start, repeat(ident_part))),

    self: $ => 'self',

    _type: $ => choice(
      seq('(', $._type, ')'),
      $.constant,
      $.generic_type,
      $.union_type,
      $.proc_type,
      // TODO: rest of type grammar
      // nilable
      // pointer
      // static array
      // tuple
      // named tuple
      // self
      // class
      // underscore
      // typeof
    ),

    union_type: $ => prec.right(seq(
      $._type, repeat1(prec.left(seq('|', $._type)))),
    ),

    proc_type: $ => {
      const param_types = seq(
        $._type,
        repeat(prec.left(seq(',', $._type))),
      )

      const return_type = field('return', $._type)

      return prec.left(seq(
        optional(param_types),
        '->',
        optional(return_type),
      ))
    },

    generic_type: $ => seq(
      $.constant,
      token.immediate('('),
      field('params', optional(alias($.type_param_list, $.param_list))),
      ')',
    ),

    type_param_list: $ => seq(
      $._type,
      repeat(prec.left(seq(',', $._type))),
      optional(','),
    ),

    _dot_call: $ => {
      const receiver = field('receiver', $._expression)

      const method = field('method', choice(
        $.identifier,
        alias($.identifier_method_call, $.identifier),
        alias(choice(...operator_tokens), $.operator),
      ))

      // In the case of something like
      //   a.[*{0}]
      // we need to parse the arguments here, because they're embedded in the
      // method "name".
      const bracket_method = seq(
        field('method', alias('[', $.operator)),
        alias($.bracket_argument_list, $.argument_list),
        ']',
        optional(choice(
          token.immediate('?'),
          '=',
        )),
      )

      return prec('dot_operator', seq(
        receiver,
        '.',
        choice(method, bracket_method),
      ))
    },

    bracket_argument_list: $ => {
      const args = choice($._expression, $.splat, $.double_splat, $.named_arg)

      return seq(
        args,
        repeat(seq(',', args)),
        optional(','),
      )
    },

    // how do we distingush a method call from a variable?
    // at least one of these is required:
    // - receiver
    // - ends in ? or !
    // - parentheses
    // - arguments
    // - block arg
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

      const brace_block = field('block', alias($.brace_block, $.block))

      const do_end_block = field('block', alias($.do_end_block, $.block))

      return choice(
        prec('no_block_call', seq(receiver_call, optional(argument_list))),
        prec('no_block_call', seq(ambiguous_call, argument_list)),

        prec('brace_block_call', seq(receiver_call, optional(argument_list), brace_block)),
        prec('brace_block_call', seq(ambiguous_call, optional(argument_list), brace_block)),

        prec('do_end_block_call', seq(receiver_call, optional(argument_list), do_end_block)),
        prec('do_end_block_call', seq(ambiguous_call, optional(argument_list), do_end_block)),
      )
    },

    // A subset of method calls that can be the LHS of an assignment
    assign_call: $ => {
      const receiver = field('receiver', $._expression)
      const method_identifier = field('method', $.identifier)

      return prec('dot_operator', seq(receiver, '.', method_identifier))
    },

    index_operator: $ => {
      const receiver = field('receiver', $._expression)
      const args = field('arguments', alias($.bracket_argument_list, $.argument_list))

      return prec('index_operator', seq(
        receiver,
        $._start_of_index_operator,
        args,
        choice(']', ']?'),
      ))
    },

    not: $ => prec('unary_operator', seq('!', $._expression)),
    and: $ => prec.left('logical_and_operator', seq($._expression, '&&', $._expression)),
    or: $ => prec.left('logical_or_operator', seq($._expression, '||', $._expression)),

    additive_operator: $ => {
      const operator = choice(
        $.binary_plus,
        $.binary_minus,
        $.binary_wrapping_plus,
        $.binary_wrapping_minus,
      )

      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.left('additive_operator',
        seq(receiver, method, arg),
      )
    },

    unary_additive_operator: $ => {
      const operator = choice(
        $.unary_plus,
        $.unary_minus,
        $.unary_wrapping_plus,
        $.unary_wrapping_minus,
      )

      return prec('unary_operator', seq(
        field('operator', alias(operator, $.operator)),
        field('receiver', $._expression),
      ))
    },

    multiplicative_operator: $ => {
      const operator = choice(
        $._binary_star,
        '&*',
        $._binary_slash,
        $._binary_double_slash,
        $._modulo_operator,
      )

      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.left('multiplicative_operator', seq(
        receiver, method, arg,
      ))
    },

    exponential_operator: $ => {
      const operator = choice($._binary_double_star, '&**')

      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.right('exponential_operator', seq(
        receiver, method, arg,
      ))
    },

    shift_operator: $ => {
      const operator = choice('<<', '>>')

      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.left('shift_operator', seq(
        receiver, method, arg,
      ))
    },

    complement_operator: $ => {
      const operator = '~'

      return prec('unary_operator', seq(
        field('operator', alias(operator, $.operator)),
        field('receiver', $._expression),
      ))
    },

    binary_and_operator: $ => {
      const operator = '&'
      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.left('binary_and_operator', seq(
        receiver, method, arg,
      ))
    },

    binary_or_operator: $ => {
      const operator = choice('|', '^')
      const receiver = field('receiver', $._expression)
      const method = field('operator', alias(operator, $.operator))
      const arg = field('argument', $._expression)

      return prec.left('binary_or_operator', seq(
        receiver, method, arg,
      ))
    },

    splat: $ => prec('splat_operator', seq($._unary_star, $._expression)),

    double_splat: $ => prec('splat_operator', seq($._unary_double_star, $._expression)),

    named_arg: $ => {
      const name = field('name', $.identifier)

      return seq(
        name,
        token.immediate(':'),
        $._expression,
      )
    },

    argument_list_no_parens: $ => {
      const args = choice($._expression, $.splat, $.double_splat, $.named_arg)

      return prec.right(seq(
        optional($._start_of_parenless_args),
        args,
        repeat(prec('comma', seq(',', args))),
      ))
    },

    argument_list_with_parens: $ => {
      const args = choice($._expression, $.splat, $.double_splat, $.named_arg)

      return prec.right(seq(
        token.immediate('('),
        optional(seq(
          args,
          repeat(seq(',', args)),
          optional(','),
        )),
        ')',
      ))
    },

    assign: $ => {
      const lhs = field('lhs', choice(
        $.identifier,
        $.instance_var,
        $.class_var,
        $.assign_call,
        alias($.index_operator, $.index_call),
      ))
      const rhs = field('rhs', $._expression)

      return prec('assignment_operator', seq(
        lhs, '=', rhs,
      ))
    },

    const_assign: $ => {
      const lhs = field('lhs', $.constant)
      const rhs = field('rhs', $._statement)

      return prec.right('assignment_operator', seq(
        lhs, '=', rhs,
      ))
    },

    operator_assign: $ => {
      // https://crystal-lang.org/reference/1.5/syntax_and_semantics/operators.html#combined-assignments
      const combined_operators = [
        '+=',
        '&+=',
        '-=',
        '&-=',
        '*=',
        '&*=',
        '/=',
        '//=',
        '%=',
        '|=',
        '&=',
        '^=',
        '**=',
        '<<=',
        '>>=',
        '||=',
        '&&=',
      ]

      const lhs = field('lhs', choice(
        $.identifier,
        $.instance_var,
        $.class_var,
        $.assign_call,
        alias($.index_operator, $.index_call),
      ))
      const rhs = field('rhs', $._expression)

      return prec('assignment_operator', seq(
        lhs, choice(...combined_operators), rhs,
      ))
    },


    lhs_splat: $ => seq('*', choice(
      $.identifier,
      $.instance_var,
      $.class_var,
      $.assign_call,
      alias($.index_operator, $.index_call),
    )),

    multi_assign: $ => {
      const lhs_basic = choice(
        $.identifier,
        $.instance_var,
        $.class_var,
        $.assign_call,
        alias($.index_operator, $.index_call),
      )
      const lhs_splat = field('lhs', alias($.lhs_splat, $.splat))
      const lhs = field('lhs', choice(lhs_basic, alias($.lhs_splat, $.splat)))
      const multi_lhs = seq(repeat1(seq(lhs, ',')), lhs)

      const rhs = field('rhs', $._expression)
      const multi_rhs = seq(repeat1(seq(rhs, ',')), rhs)

      return choice(
        seq(lhs_splat, '=', rhs),
        seq(multi_lhs, '=', rhs),
        seq(lhs_splat, '=', multi_rhs),
        seq(multi_lhs, '=', multi_rhs),
      )
    },

    alias: $ => seq(
      'alias',
      field('name', $.constant),
      '=',
      field('type', $._type),
    ),

    block_body_param: $ => field('name', $.identifier),

    block_body_splat_param: $ => seq(
      '*',
      field('name', $.identifier),
    ),

    _block_body_nested_param: $ => {
      const param = alias($.block_body_param, $.param)

      return seq(
        '(',
        param,
        repeat(seq(',', param)),
        optional(','),
        ')',
      )
    },

    block_param_list: $ => {
      const param = choice(
        alias($.block_body_param, $.param),
        alias($.block_body_splat_param, $.splat_param),
        $._block_body_nested_param,
      )

      return seq(
        param,
        repeat(seq(',', param)),
        optional(','),
      )
    },

    do_end_block: $ => {
      const params = seq('|', field('params', alias($.block_param_list, $.param_list)), '|')

      return seq(
        'do',
        optional(params),
        optional($._statements),
        'end',
      )
    },

    brace_block: $ => {
      const params = seq('|', field('params', alias($.block_param_list, $.param_list)), '|')

      return seq(
        $._start_of_brace_block,
        optional(params),
        optional($._statements),
        '}',
      )
    },

    begin_block: $ => seq(
      'begin',
      optional($._terminator),
      field('body', optional($._statements)),
      field('rescue', optional($.rescue_block)),
      // TODO: else, ensure
      'end',
    ),

    rescue_block: $ => {
      const rescue_variable = field('variable', $.identifier)
      const rescue_type = field('type', $._type)
      const rescue_body = field('body', optional($._statements))

      return seq(
        'rescue',
        optional(choice(
          seq(rescue_variable, ': ', rescue_type),
          rescue_variable,
          rescue_type,
        )),
        $._terminator,
        rescue_body,
      )
    },

    while: $ => seq(
      'while',
      field('condition', $._expression),
      $._terminator,
      optional($._statements),
      'end',
    ),

    until: $ => seq(
      'until',
      field('condition', $._expression),
      $._terminator,
      optional($._statements),
      'end',
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

    conditional: $ => prec.right('ternary_operator', seq(
      field('cond', $._expression),
      '?',
      field('then', $._expression),
      ':',
      field('else', $._expression),
    )),

    modifier_if: $ => seq(
      field('then', $._statement),
      $._modifier_if_keyword,
      field('cond', $._expression),
    ),

    modifier_unless: $ => seq(
      field('then', $._statement),
      $._modifier_unless_keyword,
      field('cond', $._expression),
    ),

    require: $ => seq('require', $.string),
  },
})
