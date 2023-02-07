#!/bin/bash

bison -d syntax.y
flex -o lexer.c --header-file=lexer.h lexer.l
g++ -o tester lexer.c  