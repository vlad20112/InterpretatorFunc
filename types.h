#ifndef TYPES_H
#define TYPES_H
/*перечсляемый тип для булевых операций*/
enum BoolFunc
{
    FALSE,
    TRUE
};
/*перечисляемый тип для операций сравнения*/
enum Ord
{
    LT,
    EQ,
    RT
};
/*Перечисляемый тип для идентификации типа каждого комбинатора*/
enum Comb
{
    SS,
    KK,
    II,
    BB,
    CC
};
#endif