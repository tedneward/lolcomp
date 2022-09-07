/*
Reference: https://github.com/jynnantonix/lolcode/blob/master/BNFGrammar.txt
*/
grammar lolcode;

program: opening code_block? closing? EOF;
   
opening
   : 'HAI' version?
   ;

version
   : '1.0'
   | '1.1'
   | '1.2'
   ;

closing
   : 'KTHXBYE'
   ;

code_block: statement+;

statement
   : declaration
   | expression
   | print_block
   | input_block
   | assignment
   /*
   | comment
   | if_block
   | loop
   | import
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

input_block
   : 'GIMMEH' LABEL
   ;

assignment
   : LABEL 'R' expression
   ;

/*
comment
   : 'BTW' ~ [\r\n]*
   | 'OBTW' ~ 'TLDR'
   ;

loop
   : 'IM IN YR' LABEL 'WILE' expression code_block 'IM OUTTA YR' LABEL
   ;

if_block
   : expression ', O RLY?' 'YA RLY' code_block 'OIC'
   | expression ', O RLY?' 'YA RLY' code_block else_if_block 'OIC'
   ;

else_if_block
   : 'MEBBE' expression code_block else_if_block
   | 'NO WAI' code_block
   | 'MEBBE' expression code_block
   ;

func_decl
   : 'HOW DUZ I' LABEL (('YR' LABEL) ('AN YR' LABEL)*)? code_block 'IF U SAY SO'
   ;

import
   : 'CAN HAS' LABEL '?'
   ;
*/

expression
   : maths
   | atom=ATOM
   | label=LABEL
   /*
   | comparison
   | logicals
   | cast
   | func_call
   */
   ;

maths
   : op=('PRODUKT OF'|'QUOSHUNT OF'|'MOD OF') left=expression 'AN' right=expression
   | op=('SUM OF'|'DIFF OF') left=expression 'AN' right=expression
   ;

/*
comparison
   : equals
   | not_equals
   | greater
   | less
   ;

equals
   : 'BOTH SAEM' expression 'AN' expression
   ;

not_equals
   : 'DIFFRINT' expression 'AN' expression
   ;

greater
   : 'BIGGR OF' expression 'AN' expression
   ;

less
   : 'SMALLR OF' expression 'AN' expression
   ;
 */

/*
logicals
   : all
   | any
   | both
   | either
   | not
   ;

all
   : 'ALL OF' expression ('AN' expression)* 'MKAY?'
   ;

any
   : 'ANY OF' expression ('AN' expression)* 'MKAY?'
   ;

both
   : 'BOTH OF' expression 'AN' expression
   ;

either
   : 'EITHER OF' expression 'AN' expression
   ;

not
   : 'NOT' expression
   ;
 */

/*
cast
   : 'MAEK' expression 'A' < type >
   ;

type
   : 'YARN'
   | 'NUMBR'
   | 'NUMBAR'
   | 'TROOF'
   | 'BUKKIT'
   ;
 */


/*
func_call
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
   | '-' ('0' .. '9')+
   | '-' ('0' .. '9')* '.' ('0' .. '9')*
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

