%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <limits.h>
    #include <string.h>
    //#define YYSTYPE double
    #include "../../Libs/contVar.h"
    static contVar container[MAX_LENGHT] = {};
    static int indexer = 0;
//Definition for lexer prototype
    int yylex();
    int yyerror(const char *p) {printf("Error %s \n", p);}
    void addToArgs(int ch, int val);
    int retIdValue(int ch);
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
%token <id> identifier
%token print
%token exit_com
//Declaratons types for return value
%type <num> Expr Value
%type <id> id_line
%%
main: id_line                   {;/* printf("Argument has added \n Index: %d \n Value in container: %d identifier in container: %c", indexer, container[indexer - 1].value, container[indexer - 1].id); */}
     |exit_com                  {exit(EXIT_SUCCESS);} 
     |print Expr                {printf("%d \n", $2);}
     |main id_line              {;/* printf("Argument has added \n Index: %d \n Value in container: %d ", indexer, container[indexer].value); */}
     |main print Expr           {printf("Result rec is: %d \n", $3);}
     |main exit_com             {exit(EXIT_SUCCESS);}
     ;

id_line: identifier '=' Expr   {addToArgs($1, $3);} 
    ;

Expr: Value                     {$$ = $1;}
    |Expr '-' Value              {$$ = $1 - $3;}
	|Expr '*' Value              {$$ = $1 * $3;}
    |Expr '+' Value              {$$ = $1 + $3;}
	;

Value: number                   {$$ = $1;}
	|identifier                 {$$ = retIdValue($1);} ;
%%

int retIdValue(int ch)
{
    int result = INT_MAX;
    for(int n = 0; n < indexer; n++)
        if (container[n].id == ch)
            {
                result = container[n].value;
                break;
            }
            //printf("[%c, %d]\n", container[indexer].id, result);
    return result;
}

void addToArgs(int ch, int val)
{
    for (int n = 0; n < indexer; n++)
        if(container[n].id == (char)ch)
        {
            container[n].value = val;
            //printf("Id: %c \n Value has perlaced: %d \n",ch, val);
            return;
        }
    container[indexer].id = (char)ch; container[indexer].value = val;
    //printf("Id container: %c \n Value in container: %d \n",container[indexer].id, container[indexer].value);
    indexer++;
    return;
}

int main()
{
    yyparse();
    return 0;
}