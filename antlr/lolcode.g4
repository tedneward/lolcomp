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
   | comparison
   | atom=ATOM
   | label=LABEL
   /*
   | logicals
   | func_call
   */
   ;

maths
   : op=('PRODUKT OF'|'QUOSHUNT OF'|'MOD OF') left=expression 'AN' right=expression
   | op=('SUM OF'|'DIFF OF') left=expression 'AN' right=expression
   ;

comparison
   : op=('BOTH SAEM'|'DIFFRINT'|'BIGGR OF'|'SMALLR OF') left=expression 'AN' right=expression
   ;

/*
logicals
   : op=('ALL OF'|'ANY OF') ('AN' expression)* 'MKAY?'
   | op=('BOTH OF'|'EITHER OF') left=expression 'AN' right=expression
   | 'NOT' expression
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

