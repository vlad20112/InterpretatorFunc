#include "transform.h"

act_elem *transformVarToTree(char *ident)
{
    act_elem *res;
    res = (act_elem *) malloc(sizeof(act_elem *));
    res -> elem = (char *) malloc(strlen(ident) * sizeof(char *));
    //strcpy(res->elem, ident);
    strncpy(res -> elem, ident, sizeof(char *));
    res -> firstArg = NULL;
    res -> secondArg = NULL;
    res -> act = VAR;
    printf("значение \n");
    return res;
}

act_elem *transformLamToTree(char *ident, act_elem *body)
{
    act_elem *res;
    res = (act_elem *) malloc(sizeof(act_elem *));
    res -> elem = (char *) malloc(sizeof(char *));
    strncpy(res -> elem, ident, sizeof(char ));
    res -> act = LAM;
    res -> firstArg = (act_elem *) malloc(sizeof(act_elem *));
    res -> firstArg = body;
    res -> secondArg = NULL;   
    printf("лямбда \n");
    return res;
}

act_elem *transformAppToTree(char *left, char *op, act_elem *right)
{
    act_elem *res;                                                
    res = (act_elem *) malloc(sizeof(act_elem *));
    printf("Применение %s \n", op);
    res -> elem = (char *) malloc(sizeof(char *));
    strncpy(res ->elem, op, sizeof(char));
    res-> act = APP;
    res -> firstArg = (act_elem *) malloc(sizeof(act_elem *));
    res -> firstArg = transformVarToTree(op);
    res -> secondArg = (act_elem *) malloc(sizeof(act_elem *));
    res -> secondArg = transformVarToTree(left);
    res -> secondArg -> firstArg = (act_elem *) malloc(sizeof(act_elem *));
    res -> secondArg -> firstArg = right;
    return res;
}

void printTreeElem(act_elem *tree)
{
    while(tree != NULL)
    {
        switch(tree->act)
	    {  
		case LAM:{printf("LAM (%s) \n", tree ->elem);} break;
		case VAR:{printf("VAR (%s) ", tree -> elem);} break;
		case APP:{printf("APP ");} break;
	    }
    printTreeElem(tree -> firstArg);
    tree = tree -> secondArg;
    }
    return;
}