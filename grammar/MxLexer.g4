lexer grammar MxLexer;
/*Keywords*/
Void: 'void';
Bool: 'bool';
Int: 'int';
String: 'string';
New: 'new';
Class: 'class';
fragment Null: 'null';
True: 'true';
False: 'false';
This: 'this';
If: 'if';
Else: 'else';
For: 'for';
While: 'while';
Break: 'break';
Continue: 'continue';
Return: 'return';

/*Operators*/
Plus: '+';
Minus: '-';
Star: '*';
Div: '/';
Mod: '%';

Greater: '>';
Less: '<';
GreaterEqual: '>=';
LessEqual: '<=';
NotEqual: '!=';
Equal: '==';

AndAnd: '&&';
OrOr: '||';
Not: '!';

RightShift: '>>';
LeftShift: '<<';
And: '&';
Or: '|';
Caret: '^';
Tilde: '~';

Assign: '=';

PlusPlus: '++';
MinusMinus: '--';

Dot: '.';

LeftBracket: '[';
RightBracket: ']';

LeftParen: '(';
RightParen: ')';

Comma: ',';
Semi: ';';
LeftBrace: '{';
RightBrace: '}';

LineComment: Comment ~ '\n'* -> skip;
BlockComment: '/*' .*? '*/' -> skip;

Space: ' ' -> skip;
Tab: '\t' -> skip;
Eol: '\n' -> skip;
Comment: '//';
fragment Quotation: '"';

fragment Alphabet: [a-zA-Z];
fragment Digit: [0-9];
fragment NonZeroDigit: [1-9];
fragment Underline: '_';
fragment IdentifierChars: Alphabet | Digit | Underline;
Identifier: Alphabet IdentifierChars*;

/*Literal*/
BoolLiteral: True | False;
IntLiteral: '0' | NonZeroDigit Digit*;
fragment Escapesequence: '\\n' | '\\"' | '\\\\';
fragment Schar: ~ ["\\\n\r]| Escapesequence;
StringLiteral: '"' Schar* '"';
NullLiteral: Null;


