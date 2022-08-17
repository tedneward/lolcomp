grammar Calculator;

expression: operand (OPERATOR operand)+;

operand: 
    DIGIT 
    | LPAREN operand (OPERATOR operand)+ RPAREN
    ;

LPAREN: '(';
RPAREN: ')';

OPERATOR: ADD;

ADD: '+';

DIGIT: [0-9]+;
WS: [ \t\r\n]+ -> skip;
