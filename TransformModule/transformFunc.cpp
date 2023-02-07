#include "transformFunc.h"

func_node *transformLineToFunc(char *name, arg_list *list, act_elem *node)
{
    func_node *res;
    //Выделяем память для новой функции
    printf("name func before %d \n", sizeof(name));
    printf("arg list before %d \n", sizeof(list));
    printf("func body before %d \n", sizeof(node));
    res = (func_node *) malloc(sizeof(func_node *));
    res -> funcName = (char *) malloc(sizeof(char *));
    res -> funcArgs = (arg_list *) malloc(sizeof(arg_list *));
    res -> funcBody = (act_elem *) malloc(sizeof(act_elem *));
    strcpy(res -> funcName, name);
    res -> funcArgs = list;
    res -> funcBody = node;
    //memcpy((unsigned char *)res -> funcArgs, (unsigned char *)list, sizeof(unsigned char *));
    //memcpy((unsigned char *)res -> funcBody, (unsigned char *)node, sizeof(unsigned char *));
    
    printf("name func after %d \n", sizeof(name));
    printf("arg list after %d \n", sizeof(list));
    printf("func body after %d \n", sizeof(node));
    return res;
}

void addArgToList(arg_list *list, char *from)
{
    if(list == NULL)
    {
        printf("allocate new memoy place for args \n");
        list = (arg_list *) malloc(sizeof(arg_list *));
        list -> argument = (char *) malloc(sizeof(char *));
        strcpy(list -> argument, from);
        list -> next = (arg_list *) malloc(sizeof(arg_list *));
        list -> next -> next = NULL;
        return;
    }
    while(list -> next != NULL)
        list = list -> next;
// пишем новый аргумент в список
    list -> argument = (char *) malloc(sizeof(char *));
    strcpy(list -> argument, from);
    printf("Args %s записан \n", list -> argument);
    list -> next = (arg_list *) malloc(sizeof(arg_list *));
    list -> next -> next = NULL;
}

void printArgList(arg_list *list)
{
    if(list == NULL)
    {
        printf("Empty Args \n");
        return;
    }
    while(list -> next != NULL)
        {
            printf("%s \n", list -> argument);
            list = list -> next;
        }
    
}

/*size_t str_elem_count(char **list)
{
    size_t res = 0;
    if(list == NULL)
        {
            printf("Empty list \n");
            return -1;
        }
    else
    {
        while(*(list) != NULL)
        {
            printf("%s \n", *list);
            list++;
            res++;
        }
    }
    return res;
}*/