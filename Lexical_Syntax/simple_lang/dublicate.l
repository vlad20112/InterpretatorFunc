%{
       
%}
%option noyywrap
letter   [a-zA-Z]
num      [0-9]
num1     [1-9]
ID       {letter}({letter}|{num})*
NUM      (({num1}+({num})*)|0)
%%
"exit"      {}
"print"     {}
{NUM}       {printf("number: %s", yytext);}
{ID}        {printf("id: %s", yytext);}
[-+*=;]       {printf("%s", yytext);}
[ \n\t\[\]]     {printf("%c", yytext[0]);}    
.           {printf("What is that!?? \n");}
%%

int main()
{
    yylex();
}