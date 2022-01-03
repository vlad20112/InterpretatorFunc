#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(int argc, char **argv)
{
    int ntoken, vtoken;
    ntoken = yylex();
    while(ntoken) {
        ntoken = yylex();
    }
}
