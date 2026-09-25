Expression Converter and Evaluator

A C implementation of an arithmetic expression converter and evaluator using array-based stacks.

Features

- Infix to Postfix conversion
- Postfix expression evaluation
- Array-based stack implementation
- Operator precedence
- Parentheses "()" and square brackets "[]"
- Supported operators: "+", "-", "*", "/"

Example

Input

2*(3+4)

Postfix

234+*

Result

14

Data Structures

This project uses two array-based stacks:

- "stackChar" — stores operators during Infix to Postfix conversion
- "stackInt" — stores operands during Postfix evaluation

Current Limitations

- Currently supports single-digit operands ("0-9")
- Consecutive operators are not supported
- Input must be a valid expression
- Multi-digit operands are planned for a future version

Language

- C
