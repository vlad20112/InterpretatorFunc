%token keyword_if
%token keyword_else
%token keyword_then
%token keyword_let
%token Bool
%token logic_or
%token logic_and
%token logic_not
%token String
%token Char
%token idkey
%token keyword_lambda
%token Int
%token Float
%%
Start:  Main
	;
Main: /* пусто */
	|Block_Func
	;
Block_Func: /* пусто */ 
	| Function Block_Func
	;
Function: idkey '[' Arg_list ']' '=' Expr
    |LambdaExpr
    |BExpr
    |Cond
    |LetExpr
    |Type   /*предполагается, что тут будут храниться константные значения */
	;
Arg_list:/* пусто */ 
	|idkey ',' Arg_list
	;
Expr: /* пусто */
	| Expr1 Expr
	;

Expr1: /* пусто */
	|Value '-'  Expr1
	|Value '*' Expr1
	|Value '/' Expr1
    |Value '+' Expr1
	;

LambdaExpr: keyword_lambda idkey '.' LambdaExpr
    |Expr
    |Cond
    |BExpr
    |Type
	;
LetExpr: keyword_let idkey '=' Expr
	;
Value: idkey
	| Type_number
	;
BExpr: /* пусто */ 
	|BExpr1 BExpr
	;
BExpr1: /* пусто */
	| BValue BOp BExpr1
	;
BValue: idkey
    |Type_boolean
	;
BOp: logic_and
	|logic_or
	|logic_not
	;

Cond: keyword_if BExpr keyword_then Type keyword_else Type
	;
Type: Type_number
	|Type_symbol
	|Type_boolean
	;
Type_number: Int
	|Float
	;
Type_symbol: Char
	|String
	;
Type_boolean: Bool
	;
%%