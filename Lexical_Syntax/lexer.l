letter   [a-zA-Z]
num      [0-9]
num1     [1-9]
types    (Int|Bool|Float|Char|String)
keyword  (if|then|else|lambda|let)
ID       {letter}({letter}|{num})*
NUM      (({num1}+({num})*)|0)
DECNUM   ({num})+\.({num})*
KEY      {keyword}
TYPE	 {types}
int func_count, args_count;
%%
{TYPE}          {printf("%s", yytext);}
{KEY}           {printf("keyword_%s", yytext);}
{NUM}           {printf("numkey: %s", yytext);}
{ID}            {printf("idkey: %s", yytext); }
{DECNUM}        {printf("decnumkey: %s", yytext);}
\(              {printf("( : %s", yytext);}
\)              {printf(") : %s", yytext);}
\[              {printf("[");}
\]              {printf("]");}
\{              {printf("{");}
\}              {printf("}");}
\,              {printf(",");}
("&&")            {printf("logic_and");}
("||")            {printf("logic_or");}
\!             {printf("logic_not");}
\;				{printf(";");}
"="		        {printf("=");}
"'"				{printf("'");}
"+"	            {printf("+");}
"-"		        {printf("-");}
"=="            {printf("equal_term");}
"*"		        {printf("*");}
"/"		        {printf("/");}
" "             {printf(" ");}
\.              {printf(".");}
.               {printf("error");}
%%

main( argc, argv)
int argc;
char **argv;
{
    ++argv, --argc;
    if(argc > 0)
        yyin = fopen( argv[0],"r");
    else
        yyin = stdin;
    yylex();
}
int yywrap(){
    if(yyin != NULL) {
        return 0;
    }
    return 1;
}
void appendLexem (char *lexem){
    
}
