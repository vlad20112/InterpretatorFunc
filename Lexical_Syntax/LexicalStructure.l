letter   [a-z]
letter1 [A-Z]
num      [0-9]
num1     [1-9]
types    (Int|Bool|Float|Char|Array)

ID {letter}({letter}|{letter1}|{num})*
NUM {num1}+({num})*
DECNUM ({num})+\.({num})*
KEY {keyword}
TYPE	  {types}
%%
{TYPE}          {printf("exist_type");}
{NUM}           {printf("numkey");}
{ID}            {printf("idkey"); }
{DECNUM}        {printf("decnumkey");}
\(              {printf("(");}
\)              {printf(")");}
\[              {printf("[");}
\]              {printf("]");}
\{              {printf("{");}
\}              {printf("}");}
\,              {printf(",");}
(и|"&&")            {printf("logic_and");}
(или|"||")            {printf("logic_or");}
(не|NOT)             {printf("not");}
\;				{printf(";");}
"="		        {printf("=");}
"'"				{printf("'");}
"+"	            {printf("+");}
"-"		        {printf("-");}
"--"            {printf("equal-type");}
"*"		        {printf("*");}
"/"		        {printf("/");}
"программа"     {printf("program_term");}
"делай"         {printf("do_term");}
"конец"         {printf("end_term");}
"функция"       {printf("function_term");}
"верно"         {printf("if_then_term");}
"иначе"         {printf("else_term");}
"нацело"		{printf("div");}
"остаток"		{printf("mod");}
"равно"         {printf("equal_func");}
"запись"		{printf("read");}
"вывод"			{printf("write");}
"\"             {printf("lambda_term");}
" "             {printf(" ");}
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