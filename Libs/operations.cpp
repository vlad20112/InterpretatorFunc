#include "operations.h"

int isOperator(char ch)
{
    int res = 0;
    switch(ch)
    {

        case PLUS: {} break;
        case MINUS: {} break;
        case MULT: {} break;
        case DIVIDE: {} break;
        default: {res = -1;} break; 
    }
    return res;
}

void addChar(char *accumulator, const char *line)
{
    (*accumulator) = (*line);
    accumulator++;
    line++;
}

void lineToAction(struct act_elem *result, char *line)
{
    if(strlen(line) == 0)
    {
        result->firstArg = NULL;
        result->secondArg = NULL;
        return;
    }
    char *leftSide,  *rightSide;
    size_t sizeComand = strlen(line);
    leftSide = calloc(char *, sizeComand);
    rightSide = calloc(char *, sizeComand);
    while(line != NULL) || (!isOperator( (*line)))
    {
        addChar(leftSide, line);
    }
    while(line != NULL)
    {
        addChar(rightSide, line);
    }

    result -> firstArg = (struct act_elem *) malloc(sizeof( struct act_elem * ));
    result -> secondArg = (struct act_elem *) malloc(sizeof( struct act_elem* ));
    result -> firstArg = lineToAction(result->firstArg,  leftSide);
    result -> secondArg = lineToAction(result->secondArg,  rightSide);
    return ;
}