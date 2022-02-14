bison -d simple_example.y
flex simple_lexer.l
gcc -o simple_lang simple_example.tab.c lex.yy.c