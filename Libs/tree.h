#ifndef TREE_H
#define TREE_H
#include "types.h"

typedef struct {
    char *left;
    char *op;
    char *right;
    }parseExpr;

//структура для хранения первичного дерева
typedef struct action_elem{
action_comb act;
char *elem;
struct action_elem *firstArg;
struct action_elem *secondArg;
}act_elem;


// структура для хранения комбинаторного дерева -- Хаха, она ТАК ОТЛИЧАЕТСЯ от той, что лежит сверху))
typedef struct comb_elem {
    combinator element;
    char *help_field;
    struct comb_elem *firstArg;
    struct comb_elem *secondArg;
}combinator_elem;

typedef struct ap_elem
{
    char *cell;
    int argCount;
    struct ap_elem *left;
    struct ap_elem *right;
    combinator_elem *reserve;
}apply_elem;

typedef struct arg_list{
    char *argument;
    struct arg_list *next;
}arg_list;

struct func_node{
    char *funcName;
    arg_list *funcArgs;
    act_elem *funcBody;
};
// ЛОООЛ, ну это вообще уже смещноо ))) минус один элемент и поле другого типа!! :))
struct comb_node
{
    char *funcName;
    combinator_elem *comb_body;
};


#endif