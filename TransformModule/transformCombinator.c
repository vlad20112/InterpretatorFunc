#include "transformCombinator.h"

// TODO пройтись взглядом по коду на момент бросающихся косяков


combinator_elem *transformToSK(act_elem *node, const char *arg)
{
    combinator_elem *res;
    res = (combinator_elem *)malloc(sizeof(combinator_elem *));
    switch(node -> act)
    {
        case VAR:{ 
            if(node -> firstArg == NULL)
                {
                    if(strcmp(arg, node -> elem) == 0) 
                        res = createI();
                    else
                        res = createK(node);
                }
            else
            {
                res->element = S;
                const char *promer = (const char *)node -> firstArg -> elem;
                const char *promerTwo = arg;
                if(strcmp(arg, node->elem) == 0)
                    res -> firstArg = createI();
                else
                    res->firstArg = createK(node);
                if(strcmp(promerTwo, promer) == 0)
                    res -> secondArg = createI();
                else
                    res ->secondArg = createK(node->firstArg);
            } 
        }
        break;
        case APP:{
            //Здесь нужно проверять содержимое листа. если там APP
            res ->element = S;
            res -> firstArg = transformToSK(node ->firstArg, arg);
            res -> secondArg = transformToSK(node->secondArg, arg);
        }; break;
        case LAM:{}; break;
    }
    return res;
}
combinator_elem *transformToSKLate(combinator_elem *node, const char *arg)
{
    combinator_elem *res;
    res = (combinator_elem *) malloc(sizeof(combinator_elem *));
    switch(node -> element)
    {
        case S:
        {
            emptyAct.act = APP;
            combinator_elem *prom = createS(&emptyAct, arg);
            emptyAct.act = VAR;
            prom->firstArg = createK(&emptyAct);
            emptyAct.act = APP;
            prom -> firstArg -> firstArg = createS(&emptyAct, arg);
            prom -> secondArg = createS(&emptyAct, arg);
            prom -> secondArg -> firstArg = transformToSKLate(node->firstArg, arg);
            prom -> secondArg -> secondArg = transformToSKLate(node->secondArg, arg); 
            res = prom;
        }; break;
        case K:{
            emptyAct.act = APP;
            combinator_elem *prom = createS(&emptyAct, arg);
            emptyAct.act = VAR;
            prom ->firstArg = createK(&emptyAct);
            prom ->firstArg->firstArg = createK(&emptyAct);
            if(strcmp(arg, node -> help_field) == 0)
                prom -> secondArg = createI();
            else
                prom -> secondArg = node;
            res = prom;
        }; break;
        case I:{
            initEmptyAct(&emptyAct);
            combinator_elem *prom = createK(&emptyAct);
            prom ->firstArg = node;
            res = prom;
        }; break;
    }
    return res;
}

/*combinator_elem *applyArg(combinator_elem *node, char *arg)
{
    switch(node -> element)
    {
        case S: {} break;
        case K: {} break;
        case I: { strcpy(res.help_field, arg);} break;
    }
}*/

combinator_elem *createI()
{
    combinator_elem *res;
    res = (combinator_elem *) malloc(sizeof(combinator_elem *));
    res -> element = I;
    res -> firstArg = (combinator_elem *) malloc(sizeof(combinator_elem *));
    res -> secondArg = (combinator_elem *) malloc(sizeof(combinator_elem *));
    res -> firstArg = NULL;
    res -> secondArg = NULL;
    return res;
}

combinator_elem *createK(act_elem *left)
{
    combinator_elem *res;
    res = (combinator_elem *)malloc(sizeof(combinator_elem *));
    res -> element = K;
    res->help_field = (char *) malloc(sizeof(char *));
    if(strcmp(left->elem, "") != 0)
        strcpy(res -> help_field, left->elem);
    if(left->firstArg != NULL)
        {
            res -> firstArg = createK(left ->firstArg);
            res -> secondArg = NULL;
        }
    else    
    {
        res -> firstArg = NULL;
        res -> secondArg = NULL;
    }
    return res;
}

/*combinator_elem *createK(act_elem *left, const char *arg)
{
    combinator_elem *res;
    res = (combinator_elem *)malloc(sizeof(combinator_elem *));
    res ->element = K;
    res -> help_field = (char *) malloc(sizeof(char *));
    strcpy(res ->help_field, arg);
    return res;
}*/



combinator_elem *createS(act_elem *left, const char *arg)
{
    combinator_elem *res;
    res = (combinator_elem *) malloc(sizeof(combinator_elem *));
    switch(left -> act)
    {
        case APP: {
                res ->element = S;
                if((left -> firstArg == NULL) && (left -> secondArg == NULL))
                    {
                        res -> firstArg = (combinator_elem *) malloc(sizeof(combinator_elem *));
                        res -> secondArg = (combinator_elem *) malloc(sizeof(combinator_elem *));
                        res -> firstArg = NULL;
                        res -> secondArg = NULL;
                        return res;
                    }
                switch(left ->firstArg->act)
                {
                    case APP: {res -> firstArg = createS(left -> firstArg, arg); } break;
                    case VAR: {res -> firstArg = createK(left->firstArg);} break;
                }
                switch(left -> secondArg ->act)
                {
                    case APP: {res -> secondArg = createS(left -> secondArg, arg);} break;
                    case VAR: {res -> secondArg = createK(left ->secondArg);} break;
                }
        }; break;
        case VAR: {
                res -> firstArg = createK(left);
        }; break;
    }
    return res;
}

combinator_elem *applyS(combinator_elem *left, combinator_elem *right)
{
    combinator_elem *res;
    /*
    В этом месте должОна быть реализация, вот какая была выше, только с другим типом
    */
    return res;
}

combinator checkCombinator(act_elem *node, const char *arg)
{
    combinator res;
    switch(node -> act)
    {
        case VAR:{ 
            if(strcmp(arg, node -> elem) == 0)
                res = I;
            else
                res = K;
            } break;
        case APP:{
            res = S;
            } break;
    };

    return res;
}

void printCombinator(combinator_elem *node)
{
    if(node != NULL)
    {
        switch(node ->element)
        {
            case S:
            {
                if(node -> firstArg == NULL && node -> secondArg == NULL)
                    return;
                else
                {
                    printf("S(");
                    printCombinator(node ->firstArg);
                    printf(",");
                    printCombinator(node ->secondArg);
                    printf(")");
                }
            } break;
            case K:
            {
                if(node ->firstArg == NULL)
                    return;
                else
                {
                    printf("K%s ", node ->help_field);
                    printCombinator(node -> firstArg);
                    return;
                }
                } break;
            case I: {printf("I"); return;} break;
        }
    }
    return;
}

void initEmptyAct(act_elem *node)
{
    node -> act = VAR;
    node -> elem = (char *) malloc (sizeof(char *));
    strcpy(node->elem, "");
    node ->firstArg = NULL;
    node -> secondArg = NULL;
}