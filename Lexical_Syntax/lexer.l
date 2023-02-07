
%{
    #include <string.h>
    #include "../Libs/tree.h"
    #include "syntax.tab.h"
%}
%option noyywrap
letter   [a-zA-Z]
dig      [0-9]
dig1     [1-9]
ID       {letter}({letter}|{dig})*
NUM      (({dig1}+({dig})*)|0)
DECNUM   ({dig})+\.({dig})*
STRING   ((ID)*|(NUM)*|(DECNUM)*)

%%

"lambda"        {return lamTok;}
{ID}|{NUM}            {yylval.str = (char *)malloc(sizeof(char *)); strcpy(yylval.str, yytext); return Identifier;}
[\&\|\!]            {printf("%c", yytext[0]);/*return bOp;*/}
[\+\-\*]           {yylval.id = yytext[0]; return Op;}
[\[\]\=\,\.\(\)]         {return yytext[0];}
"\n"            {return endLn;}

[ ]             {;}
.               {printf("error");}

%%

void convertToString (char *dest, const char * src)
{
    dest = (char *) malloc(strlen(src) * sizeof(char *));
    strcpy(dest, src);
}