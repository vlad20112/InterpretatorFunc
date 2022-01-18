%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
//Definition for lexer prototype
    int yylex();
    int yyerror(const char *p) {printf("Error %s \n", p);}
%}
//symbol semantics value
%union {
    int num;
    char id;
    };
//Start terminal
%start main
//Tokens for some job in grammar
%token <num> number
%token print
%token exit_com
%token <id> identifier 
//Declaratons types for return value
%type <num> Expr Value id_line
%%
main: exit_com          {exit(EXIT_SUCCESS);}
     |print Expr    {printf("Result is: %d \n", $2);}
     |id_line
     |Expr
     |main exit_com          {exit(EXIT_SUCCESS);}
     |main id_line
     |main Expr 
     |main print Expr    {printf("Result is: %d \n", $3);}
     ;

id_line: identifier '=' Value  {addToArgs($1, $3);}
    ;

Expr: Value           {$$ = $1;}
    |Expr '-' Value   {$$ = $1 - $3;}
	|Expr '*' Value    {$$ = $1 * $3;}
    |Expr '+' Value    {$$ = $1 + $3;}
	;

Value: number        {$$ = $1;}
	|identifier       {retIdValue($$);};
%%

int retIdValue(int ch)
{

    return 0;
}

void addToArgs(char ch, int val)
{
    return;
}

int main()
{
    yyparse();
    return 0;
}