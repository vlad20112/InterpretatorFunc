%{
    #include "../../Libs/types.h"
    #include "simple_example.tab.h"
    
%}
%option noyywrap
letter   [a-zA-Z]
num      [0-9]
num1     [1-9]
ID       {letter}({letter}|{num})*
NUM      (({num1}+({num})*)|0)
%%
"exit"      {return exit_com;}
"print"     {return print;}
{NUM}       {yylval.num = atoi(yytext); return number;}
{ID}        {printf("lenght \n"); yylval.id = (char *) malloc( strlen(yytext) * sizeof( char *) ); strcpy(yylval.id, yytext); printf("%s \n %s \n", yytext, yylval.id); return identifier;}
[-+*=;]       {return yytext[0];}
[ \n\t]         ;
.           {printf("What is that!?? \n");}
%%
