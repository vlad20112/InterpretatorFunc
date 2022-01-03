
%%
Start:  Main
	;
Main: /* ����� */
	|Block_Func
	;
Block_Func: /* ����� */ 
	| Function Block_Func
	;
Function: idkey '[' Arg_list ']' '=' Expr
    |LambdaExpr
    |BExpr
    |Cond
    |LetExpr
    |Type   /*��������������, ��� ��� ����� ��������� ����������� �������� */
	;
Arg_list:/* ����� */ 
	|idkey ',' Arg_list
	;
Expr: /* ����� */
	| Expr1 Expr
	;

Expr1: /* ����� */
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
BExpr: /* ����� */ 
	|BExpr1 BExpr
	;
BExpr1: /* ����� */
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