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
"lambda" {return lambda;}
{NUM}       {yylval.num = atoi(yytext);printf("%s \n", yytext); return number;}
{ID}        {yylval.id = (char *) malloc( strlen(yytext) * sizeof( char *) ); strcpy(yylval.id, yytext); printf("%s 'n", yytext);return identifier;}
[-+*]       {yylval.op = (char)yytext[0]; printf("lolkek %c \n", yytext[0]); printf("azaaza %c \n", yylval.op); return operator;}
[\t\[\]\{\}=;]    {printf("%c", yytext[0]); return yytext[0];}
[\n ]             ;
.           {printf("What is that!?? \n");}
%%
