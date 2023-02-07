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

static const char *operators[] = {"+", "-", "*", "/", "&&", "||"};
/*перечисляемый тип для операций сравнения*/
enum Ord
{
    LT = 10,
    EQ,
    RT
};
//Тип узла для первичного дерева
typedef enum {
    APP = 101,
    VAR,
    LAM
}action_comb;

/*Перечисляемый тип для идентификации комбинаторов*/
typedef enum {
    S = 200,
    K,
    I,
    B,
    C, 
    Y,
    END
}combinator;

#endif