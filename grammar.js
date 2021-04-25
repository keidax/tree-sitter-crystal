module.exports = grammar({
  name: 'crystal',

  rules: {
    source_file: $ => repeat($._statement),

    _statement: $ => choice(
      $._expression,
      // TODO: add definitions, etc.
    ),

    _expression: $ => choice(
      $._bool
      // $.identifier,
      // TODO: other expressions
    ),

    _bool: $ => choice($.true, $.false),
    true: $ => "true",
    false: $ => "false"

  }
});
