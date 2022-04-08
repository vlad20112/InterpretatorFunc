//Далее описаны перечисляемые классы для булевого типа, результаты сравнения и типы комбинаторов
#ifndef TYPES_H
#define TYPES_H

#define MULT 42
#define PLUS 43
#define MINUS 45
#define DIVIDE 47
/*перечсляемый тип для булевых операций*/
enum BoolFunc
{
    TRUE = 0,
    FALSE
};
/*перечисляемый тип для операций сравнения*/
enum Ord
{
    LT = 10,
    EQ,
    RT
};
/*Перечисляемый тип для идентификации комбинаторов*/
enum Comb
{
    S = 100,
    K,
    I,
    B,
    C
};
enum action_comb{
    APP = 101,
    VAR,
    LAM
};

struct act_elem{
action_comb act;
char *elem;
act_elem *firstArg;
act_elem *secondArg;
};

//структура для хранения комбинаторного дерева

#endif