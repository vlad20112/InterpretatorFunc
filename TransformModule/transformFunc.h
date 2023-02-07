#ifndef TRFUNC_H
#define TRFUNC_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../Libs/tree.h"

func_node *transformLineToFunc(char *name, arg_list *list, act_elem *node);
void addArgToList(arg_list *list, char *from);
void printArgList(arg_list *list);
//size_t str_elem_count(char *list);

#endif