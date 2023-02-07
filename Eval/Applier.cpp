#include "Applier.hpp"
#include "../TransformModule/transformCombinator.h"

void Applier::applyArgumentToCombinator(apply_elem *result, combinator_elem *input, std::string argument)
{
    switch(input->element)
    {
        case I: { 
            setCell(result, argument.c_str());
        }
        break;
        case K: {
            if(input->firstArg == NULL)
            {
                setCell(result, input->help_field);
            }
            else
                result->reserve = input->firstArg;
        }
        break;
        case S:
            if(input->firstArg == NULL && input -> secondArg == NULL)
                return; 
            if(input->firstArg->element == S)
                applyArgumentToCombinator(result, input->firstArg, argument);
            else
                {
                    result -> left = (apply_elem *) malloc(sizeof(apply_elem *));
                    result -> right = NULL;
                    result -> cell = NULL;
                    result ->reserve = NULL;
                    applyArgumentToCombinator(result->left, (input->firstArg), argument);    
                }
            if(input->firstArg->element == S)
                applyArgumentToCombinator(result, input->firstArg, argument);
            else
                {
                    result -> right = (apply_elem *) malloc(sizeof(apply_elem *));
                    result -> left = NULL;
                    result -> cell = NULL;
                    result ->reserve = NULL;
                    applyArgumentToCombinator(result->right, (input->secondArg), argument);    
                }
            /*{
                //setEmptyResult(result);
                result -> left = (apply_elem *) malloc(sizeof(apply_elem *));
                result -> right = (apply_elem *) malloc(sizeof(apply_elem *));
                result -> cell = NULL;
                result ->reserve = NULL;
                applyArgumentToCombinator(result->left, (input->firstArg), argument);
                applyArgumentToCombinator(result->right, (input->secondArg), argument);
                setArgCount(result);
            }*/
        break;
    }
}

void Applier::printApplyArgument(apply_elem *node)
{
    if(applyIsEmpty(node) && node -> cell != NULL)
        {
            std::cout << node->cell;
            return;
        }
    if(node->reserve != NULL)
    {
        printCombinator(node->reserve);
        return;
    }
    else
    {
        if((node -> left->cell == NULL) || (node -> right -> cell == NULL))
        {
            std::cout << "(";
            printApplyArgument(node->left);
            std::cout <<",";
            printApplyArgument(node->right);
            std::cout <<")";
        }
        else
            return;
    }
}

bool Applier::applyIsEmpty(apply_elem *node)
{
    return node ->left == NULL && node -> right == NULL;
}

bool cellIsEmpty(apply_elem *node)
{
    return node->cell == NULL; 
}
void Applier::setArgCount(apply_elem * node)
{
    int res;
    if(!cellIsEmpty(node->left))
        res++;
    if(!cellIsEmpty(node->right))
        res++;
    node ->argCount = res;
}

void Applier::setCell(apply_elem *node, const char *str)
{
    node->cell = (char *) malloc(sizeof(char *));   
    strcpy(node->cell, str);
    node->reserve =NULL; node->left =NULL; node->right = NULL;
}

void Applier::copyCells(apply_elem *dst, apply_elem *src)
{
    if (cellIsEmpty(src->left))
        dst->left = src ->left;
    if(cellIsEmpty(src->right))
        dst->right = src->right;    
}

void Applier::deleteEmptyLeaf(apply_elem *node)
{
    apply_elem *res;
    res = (apply_elem *) malloc(sizeof(apply_elem *));
    while(node != NULL)
    {
        copyCells(res, node);
        if (!applyIsEmpty(node->right))
                node = node->right;
    }
    node = res;
}

void Applier::setEmptyResult(apply_elem *result)
{
    result -> left = (apply_elem *) malloc(sizeof(apply_elem *));
    result -> right = (apply_elem *) malloc(sizeof(apply_elem *));
    result -> cell = NULL;
    result ->reserve = NULL;
}