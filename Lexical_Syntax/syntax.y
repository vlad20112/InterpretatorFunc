%{
    #include <stdio.h>
    #include <stdlib.h>
	#include <string.h>
	#include "../Libs/tree.h"
	#include "../TransformModule/transform.cpp"
	#include "../TransformModule/transformFunc.cpp"
    //Definition for lexer prototype
    int yylex();
    int yyerror(func_node *fn, const char *p) {printf("Error %s \n", p);
	static arg_list argVedro[] = {};
	}

%}
//symbol semantics value
%union{
    char id;
	char *str;
	arg_list *str_list;
    int bl;
	act_elem *action;
	struct func_node *node;
    };
%parse-param {func_node *myResult}
%token <str> Identifier lamTok 
%token <id> Op endLn
%token <bl> bOp
%type <node> Function
%type <str_list> Arg_list 
%type <action> Expr LambdaExpr ExprEval Value
%%

Start: Main
	;
Main: /* empty */
	|Function {printf("parse has over \n");return 0;}
	;
Function: {printf("Я нашел функцию \n");}/* empty */
	|Identifier '[' Arg_list ']' '=' Expr endLn	{
		//printf("malloc memory for combinator \n");
		$$ = transformLineToFunc($1, $3, $6);
		strcpy(myResult -> funcName, $1);
		myResult ->funcArgs = $$ -> funcArgs;
		myResult->funcBody = $$ -> funcBody;
		//printArgList(myResult -> funcArgs);

	}	
	|LambdaExpr endLn {}
Arg_list: {
	//printf("здесь ничего нету \n");
	$$ = (arg_list *)malloc(sizeof(arg_list *));
	$$ -> next = NULL; 
	} 
	|Identifier {
		//printf("где ты будешь вызываться??");
		$$ = (arg_list *) malloc(sizeof(arg_list *));
		addArgToList($$, $1);
		}
	|Identifier Arg_list {
		//printf("А вот ты где будешь вызываться??");
		//printf("Сохраняю аргументы \n");
		addArgToList($2, $1);
		$$ = (arg_list *) malloc (sizeof(arg_list *));
		$$ = $2;
		}	
	;
Expr: /* empty */
	|ExprEval {$$ = $1;} 	
	|BExpr	
	|Value	{ $$ = $1;}
	;

ExprEval: 
	| Value { $$ = $1;}	
// Здесь надо подумать ещё над процесом корректного перевода к виду APP
	|Identifier Op ExprEval 	{
		$$ = (act_elem *)malloc(sizeof(act_elem *));
		$$ = transformAppToTree($1, &($2), $3);
		}  
	;
Value: Identifier 	{
		//printf("Создание комбинатора %s \n", yylval.str);
		$$ = (act_elem *) malloc(sizeof(act_elem *));
		printf("выделении памяти \n");
		if($$ != 0) 
			{
				printf("начало выделения памяти \n");
				$$ = transformVarToTree(yylval.str);
			}
		else
			 printf("ошибка при выделении памяти \n");
		}
	;
BExpr: /* empty */ 
	|BExpr bOp Value
	;

LambdaExpr:	lamTok Identifier '.' Expr
	{
		printf("lam expr \n");
		act_elem *bodyLam;
		bodyLam = (act_elem *) malloc(sizeof(act_elem *));
		bodyLam = transformLamToTree($2, $4);
		strcpy(myResult -> funcName, "lambda");
		printf("Запись лямбда-выражения %d \n", bodyLam -> act);
		myResult -> funcBody = bodyLam;
		$$ = bodyLam;
	}
	|lamTok Identifier '.' LambdaExpr {
		printf("summer time \n");
		//act_elem *bodyLam;
		//bodyLam = (act_elem *) malloc(sizeof(act_elem *));
		$$ = transformLamToTree($2, $4);
		strcpy(myResult -> funcName, "lambda");
		printf("Запись лямбда-убервыражения %d %d \n", $4 -> act, $$ -> act);
		$$ -> firstArg = $4;
		myResult -> funcBody = $$;
	 }
	;

%%