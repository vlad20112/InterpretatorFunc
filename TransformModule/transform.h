#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Libs/tree.h"

act_elem *transformLamToTree(char *ident, act_elem *body);
act_elem *transformVarToTree(char *ident);
act_elem *transformAppToTree(char *left, char *op, act_elem *right);
void printTreeElem(act_elem *tree);
#endif