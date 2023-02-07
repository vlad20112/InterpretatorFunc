#ifndef TR_COMBINATOR_H
#define TR_COMBINATOR_H
#include <stdlib.h>
#include <stdio.h>
#include "../Libs/tree.h"
#include "string.h"

static act_elem emptyAct;

void initEmptyAct(act_elem *node);
combinator_elem *transformToSK(act_elem *node, const char *arg);
combinator_elem *transformToSKLate(combinator_elem *node, const char *arg);

combinator_elem *createS(act_elem *left, const char *arg);
combinator_elem *createK(act_elem *left);
combinator_elem *createEmptyK();
//combinator_elem *createK(act_elem *left, const char *arg);
combinator_elem *createI();
combinator_elem *applyS(combinator_elem *left, combinator_elem *right);
combinator_elem *applyK();
combinator_elem *applyK(const char *arg);
combinator_elem *applyI();
combinator checkCombinator(act_elem *node, const char *arg);
void printCombinator(combinator_elem *node);


#endif