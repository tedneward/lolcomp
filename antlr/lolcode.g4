/*
Reference: https://github.com/jynnantonix/lolcode/blob/master/BNFGrammar.txt
*/
grammar lolcode;

program: opening code_block? 'KTHXBYE'? EOF;
   
opening
   : 'HAI' version?
   ;

version
   : '1.0'
   | '1.1'
   | '1.2'
   ;

code_block: statement+;

statement
   : declaration
   | print_block
   | expression
   /*
   | assignment
   | loop
   | comment
   | if_block
   | input_block
   | func_decl
   */
   ;

declaration
   : 'I HAS A' LABEL 
   | 'I HAS A' LABEL 'ITZ' expression
   ;

print_block
   : 'VISIBLE' expression* 'MKAY?'? 
   ;

/*
loop
   : 'IM IN YR' LABEL 'WILE' expression code_block 'IM OUTTA YR' LABEL
   ;

comment
   : 'BTW' LABEL* NEWLINE
   | 'OBTW' LABEL* 'TLDR'
   ;

if_block
   : 'O RLY?' 'YA RLY' code_block 'OIC'
   | 'O RLY?' 'YA RLY' code_block else_if_block 'OIC'
   ;

else_if_block
   : 'MEBBE' expression code_block else_if_block
   | 'NO WAI' code_block
   | 'MEBBE' expression code_block
   ;

input_block
   : 'GIMMEH' LABEL
   ;

func_decl
   : 'HOW DUZ I' LABEL (('YR' LABEL) ('AN YR' LABEL)*)? code_block 'IF U SAY SO'
   ;

assignment
   : LABEL 'R' expression
   ;
*/

expression
   : 
   /*
   equals
   | both
   | not_equals
   | greater
   | less
   | add
   | sub
   | mul
   | div
   | mod
   | cast
   | either
   | all
   | any
   | not
   | func
   | 
   */ATOM
   | LABEL
   ;

/*
equals
   : 'BOTH SAEM' expression 'AN' expression
   ;

not_equals
   : 'DIFFRINT' expression 'AN' expression
   ;

both
   : 'BOTH OF' expression 'AN' expression
   ;

either
   : 'EITHER OF' expression 'AN' expression
   ;

greater
   : 'BIGGR OF' expression 'AN' expression
   ;

less
   : 'SMALLR OF' expression 'AN' expression
   ;

add
   : 'SUM OF' expression 'AN' expression
   ;

sub
   : 'DIFF OF' expression 'AN' expression
   ;

mul
   : 'PRODUKT OF' expression 'AN' expression
   ;

div
   : 'QUOSHUNT OF' expression 'AN' expression
   ;

mod
   : 'MOD OF' expression 'AN' expression
   ;

cast
   : 'MAEK' expression 'A' < type >
   ;

all
   : 'ALL OF' expression ('AN' expression)* 'MKAY?'
   ;

any
   : 'ANY OF' expression ('AN' expression)* 'MKAY?'
   ;

not
   : 'NOT' expression
   ;

func
   : LABEL expression+ 'MKAY?'
   ;
*/

LABEL
   : ('a' .. 'z' | 'A' .. 'Z') ('a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_')*
   ;

ATOM
   : 'WIN'
   | 'FAIL'
   | 'NOOB'
   | ('0' .. '9')+
   | ('0' .. '9')* '.' ('0' .. '9')*
   | STRING
   ;

STRING
   : '"' ('\'"' | ~ '"')* '"'
   ;

NEWLINE
   : ('\r'? '\n' | '\r' | '\n')+ -> skip
   ;

WS
   : (' ' | '\t') -> skip
   ;

