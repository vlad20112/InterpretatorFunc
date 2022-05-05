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
    static struct func_node cellFuncNode;
    static int indexer = 0;

//Definition for lexer prototype
    int yylex();
    int yyerror(const char *p) {printf("Error %s \n", p);}
    void addToArgs(char ch[], int val);
    int retIdValue(char ch[]);
    int retIdFunction(char ch[]);
    void translateLineToCombinator(char *line);
    void memArg(contVar *cell, char *newId, int newVal);
    void fillFuncNode(char *funcName, char **argList, act_elem node);
%}
//symbol semantics value
%union {
    int num;
    char *id;
    char **list;
    char op;
    act_elem func;
    struct func_node funcer;
    };
//Start terminal
//Tokens for some job in grammar
%token <num> number
%token <id> identifier operator
%token<id> string
%token print
%token lambda
%token exit_com
//Declaratons types for return value
%type <num> Expr Value
%type <id> id_line 
%type<func> funcExpr funcValue 
%type<list> argList
%%
main:exit_com ';'                   {exit(EXIT_SUCCESS);}
     |print Expr ';'                   {printf("%d \n", $2);}
     |id_line ';'                         {printf("Argument has added \n Index: %d \n Value in container: %d identifier in container: %s", indexer, container[indexer - 1].value, container[indexer - 1].id);}
     |lam_func_decl ';'             {}
     |function_decl ';'              {printf("Function has declared \n Index: %d \n", indexer);}
     |main id_line ';'                 {/* printf("Argument has added \n Index: %d \n Value in container: %d ", indexer, container[indexer].value); */}
     |main print Expr ';'           {printf("Result rec is: %d \n", $3);}
     |main exit_com ';'             {exit(EXIT_SUCCESS);}
     |main lam_func_decl ';'    {}
     |main function_decl ';'      {}


id_line:identifier '=' Value  {printf("assigment \n"); addToArgs($1, $3);} 
    ;

function_decl: identifier argList '{' funcExpr '}' { printf("write function \n"); fillFuncNode( $1, $2, $4);}
    ;
lam_func_decl: funcExpr          {}
    | lambda identifier lam_func_decl         {} 
    ;
argList: '[' list ']'
    ;
list: 
    | identifier            {printf('tnedi \n');}
    | identifier list      {printf("ident \n");}  
    ;

funcExpr: funcValue                     {;$$ = $1; }
        |funcValue funcExpr     {
        $$.act = APP; 
        $$.firstArg = (act_elem *) malloc(sizeof(act_elem *));
        $$.secondArg = (act_elem *)malloc(sizeof(act_elem *));
        $$.firstArg = (struct elem *) &$1;
        $$.secondArg = (struct elem *)&$2;
     }
     funcValue: identifier{ 
                                        printf("Variable \n");
                                        $$.act = VAR;
                                        $$.elem = (char *) malloc(sizeof(char *));
                                        strcpy($$.elem, $1);
                                     } 
                    |operator {   
                                        printf("Operator \n");
                                        $$.act = VAR;
                                        $$.elem = (char *) malloc(sizeof(char *));
                                        strcpy($$.elem, (char *)&$1);
                                    } 
                    |number {
                                        printf("Number \n");
                                  }         
    ;
Expr:Value                        {$$ = $1;}
    |Expr operator Value    {
            printf("my operator: %c \n", yylval.op);
            if(yylval.op == '+')
                $$ = $1 + $3;
            if (yylval.op == '-')
                $$ = $1 - $3;
            if (yylval.op =='*' )
                $$ = $1 * $3;
            }
	;


Value:number                   {$$ = $1;}
	| identifier                 {$$ = retIdValue($1);} 
    ;

%%

// Вернёт закрепленное за переменной значение
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

int retIdFunction(char ch[])
{

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

/*
void translateLineToCombinator(act_elem node, char *line)
{
    node.act = VAR;
    node.elem = (char *) malloc(strlen(line) * sizeof(char *));
    strcpy(node.elem, line);
}*/

void fillFuncNode(char *funcName, char **argList, act_elem node)
{
    funcContainer[indexer].funcName = (char *) malloc(sizeof(char *));
    strcpy(funcContainer[indexer].funcName, funcName);
    funcContainer[indexer].funcBody = node;
    indexer++;
}

void printCombNode(act_elem *node)
{
    switch(node -> act)
    {
        case APP: {} break;
        case VAR:{printf("Variable %s ", node -> elem);} break;
        case LAM:{} break;
    }
}

int main()
{
    yyparse();
    return 0;
}