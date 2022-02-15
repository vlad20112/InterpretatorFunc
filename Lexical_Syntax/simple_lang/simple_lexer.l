%{
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
{ID}        {yylval.id = yytext[0]; return identifier;}
[-+=]       {return yytext[0];}
" "         ;
.           {printf("What is that!?? \n");}
%%
