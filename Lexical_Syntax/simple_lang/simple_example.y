%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <limits.h>
    #include <string.h>
    //#define YYSTYPE double
    #include "../../Libs/contVar.h"
    #include "../../Libs/types.h"
    
    static contVar container[MAX_LENGHT] = {};
    static struct func_node funcContainer[MAX_LENGHT] = {};
    static act_elem cellFunction;
    static int indexer = 0;

//Definition for lexer prototype
    int yylex();
    int yyerror(const char *p) {printf("Error %s \n", p);}
    void addToArgs(char ch[], int val);
    int retIdValue(char ch[]);
    void translateLineToCombinator(char *line);
    void memArg(contVar *cell, char *newId, int newVal);
%}
//symbol semantics value
%union {
    int num;
    char *id;
    act_elem func;
    };
//Start terminal
//Tokens for some job in grammar
%token <num> number
%token <id> identifier
%token<id> string
%token print
%token exit_com
//Declaratons types for return value
%type <num> Expr Value
%type <id> id_line 
%type<func> funcExpr
%%
main:exit_com ';'                   {exit(EXIT_SUCCESS);}
     |print Expr ';'                   {printf("%d \n", $2);}
     |id_line ';'                         {printf("Argument has added \n Index: %d \n Value in container: %d identifier in container: %s", indexer, container[indexer - 1].value, container[indexer - 1].id);}
     |main id_line ';'                 {/* printf("Argument has added \n Index: %d \n Value in container: %d ", indexer, container[indexer].value); */}
     |main print Expr ';'           {printf("Result rec is: %d \n", $3);}
     |main exit_com ';'             {exit(EXIT_SUCCESS);}

id_line:identifier '=' Value  {printf("assigment \n"); addToArgs($1, $3);} 
    ;

function_decl: identifier '[' argList ']' '=' funcExpr
    ;
argList: 
    | identifier argList
    ;

funcExpr: identifier          { $$.act = VAR;
                                            $$.elem = (char *) malloc(sizeof(char *));
                                            strcpy($$.elem, $1);
                                          }           
    | funcExpr funcExpr     {
        $$.act = APP; 
        $$.firstArg = (act_elem *) malloc(sizeof(act_elem *));
        $$.secondArg = (act_elem *)malloc(sizeof(act_elem *));
     }
    ;
Expr:Value                        {$$ = $1;}
    |Expr '-' Value              {$$ = $1 - $3;}
	|Expr '*' Value              {$$ = $1 * $3;}
    |Expr '+' Value              {$$ = $1 + $3;}
	;


Value:number                   {$$ = $1;}
	| identifier                 {$$ = retIdValue($1);} ;
    ;
%%

void createCombinator(char *left, char *right)
{
    
}
int retIdValue(char ch[])
{

    int result = INT_MAX;
    for(int n = 0; n < indexer; n++)
        if (strcmp(container[n].id,ch) == 0)
            {
                result = container[n].value;
                break;
            }
            //printf("[%c, %d]\n", container[indexer].id, result);
    return result;
}
void memArg(contVar *cell, char *newId, int newVal)
{
    size_t lenCh = strlen(newId);
    cell->id = (char *) malloc(lenCh * sizeof(char *));
    strcpy(cell->id, newId);
    //printf("copy id %s \n", newId);
    cell->value = newVal;
    //printf("copy value \n");
}

void addToArgs(char ch[], int val)
{
    if(indexer == 0)
    {
        memArg(&container[indexer], ch, val);
        indexer++;
        return;
    }
    else
    for (int n = 0; n < indexer; n++)
        if(strcmp(container[n].id, ch) == 0)
        {
            container[n].value = val;
            //printf("Id: %c \n Value has perlaced: %d \n",ch, val);
            return;
        }
    memArg(&container[indexer], ch, val);
    //printf("Id container: %c \n Value in container: %d \n",
     //   container[indexer].id, container[indexer].value);
    indexer++;
    return;
}

/*void translateLineToCombinator(act_elem *node, char *left, char *right)
{
    node-> type = APP;
    node -> firstArg = (act_elem *) malloc(sizeof(act_elem *));
    node -> secondArg = (act_elem *) malloc(sizeof(act_elem *));

}*/

void translateLineToCombinator(char *line)
{
    cellFunction.act = VAR;
    cellFunction.elem = (char *) malloc(strlen(line) * sizeof(char *));
    strcpy(cellFunction.elem, line);
}

int main()
{
    yyparse();
    return 0;
}