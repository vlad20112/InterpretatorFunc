{%
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    //Definition for lexer prototype
    int yylex();
    int yyerror(const char *p) {printf("Error \n");}
%}
//symbol semantics value
%union {
    int num;
    char id;
    bool bl;
    };

%token <num> number
%token <id> identifier
%token <bl> boolean
%type <num> Expr
%type <bl> BExpr
%%

Start:  Main
	;
Main: /* ����� */
	|Block_Func
	;
Block_Func: /* ����� */ 
	| Function Block_Func
	;
Function: identifier '[' Arg_list ']' '=' Expr
    |LambdaExpr
    |BExpr
    |Cond
    |LetExpr
    |Type   /*��������������, ��� ��� ����� ��������� ����������� �������� */
	;
Arg_list:/* ����� */ 
	|identifier ',' Arg_list
	;
Expr: /* ����� */
	| Expr1 Expr
	;

Expr1: Value
	|Expr1 '-' Value  
	|Expr1 '*' Value  
	|Expr1 '/' Value  
    |Expr1 '+' Value  
	;

LambdaExpr: 'lambda' identifier '.' LambdaExpr
    |Expr
    |Cond
    |BExpr
    |Type
	;
LetExpr: 'let' identifier '=' Expr
	;
Value: identifier
	| number
	;
BExpr: /* ����� */ 
	|BExpr1 BExpr
	;
BExpr1: /* ����� */
	| BValue BOp BExpr1
	;
BValue: identifier
    |boolean
	;
BOp: '&&'
	|'||'
    |'--'
	;

Cond: 'if' BExpr 'then' Type 'else' Type 
	;
Type: number
	|boolean
	;
%%