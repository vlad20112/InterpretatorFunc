//Далее описаны перечисляемые классы для булевого типа, результаты сравнения и типы комбинаторов
#ifndef TYPES_H
#define TYPES_H
#include <list>
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

//структура для хранения комбинаторного дерева
typedef std::list<Comb> Node;

#endif