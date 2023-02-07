#!/bin/bash
cd Lexical_Syntax
bison -d syntax.y
flex -o lexer.c --header-file=lexer.h lexer.l
#g++ -o tester lexer.c 
cd ../
g++ -o mainer Lexical_Syntax/myMain.cpp Lexical_Syntax/lexer.c Lexical_Syntax/syntax.tab.c  