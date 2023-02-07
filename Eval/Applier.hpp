#ifndef APPLIER_H
#define APPLIER_H
#include <utility>
#include <string>
#include <iostream>
#include <cstring>
#include "../Libs/tree.h"
class Applier
{
    public:
        void applyArgumentToCombinator(apply_elem *result, combinator_elem *input, std::string argument);
        void deleteEmptyLeaf(apply_elem *node);
        void printApplyArgument(apply_elem *node);
        void setArgCount(apply_elem *node);
        void setCell(apply_elem *node, const char *str);
        void copyCells(apply_elem *dst, apply_elem *src);
        void setEmptyResult(apply_elem *result);
        bool applyIsEmpty(apply_elem *node);
};

#endif