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

    integer: $ => /[-+]?(0b[01_]*|0o[0-7_]*|0x[0-9a-fA-F_]*|0(_[0-9_]*)?|[1-9][0-9_]*)((i|u)(8|16|32|64|128))?/,
  }
});
