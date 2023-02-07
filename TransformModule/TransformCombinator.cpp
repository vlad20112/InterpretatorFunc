#include "TransformCombinator.hpp"

combinator_elem &Creater::applyArgToComb(combinator_elem *node, const char *arg)
{
    combinator_elem res;
    switch(node->element)
    {

        case K:{ res.firstArg = &createK(node, arg);} break;
        case S:{ 
                res.firstArg = &createS(node->firstArg, arg),
                res.secondArg = &createS(node->secondArg, arg);
                } break;
        case I: {res.firstArg = &createI(node, arg);} break;
    }
    return res;
}

combinator_elem &Creater::createK(combinator_elem *node, const char *arg)
{
    combinator_elem res;
    res.element = K;
    strcpy(res.help_field, arg);
    res.firstArg = NULL;
    res.secondArg = NULL;
    return res;
}


combinator_elem &Creater::createI(combinator_elem *node, const char *arg)
{

}

comb_elem &createS(comb_elem *node, const char *arg)
{
    combinator_elem res;
    res.element = S;
    switch(node->firstArg->element)
    {
        case S:
            {res.firstArg = &createS(node->firstArg, arg);} break;
        case K:
            {}
            
             break;
        case I:
            {} break;
    }
    switch(node->secondArg->element)
    {
        case S:{
            res.secondArg = &createS(node->secondArg, arg);} break;
        case K:{} break;
        case I:{} break;
    }
    return res;
}
