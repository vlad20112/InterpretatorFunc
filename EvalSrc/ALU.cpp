/*
Пока я представляю себе этот модуль как 
набор реализованных основных операций,
которые можно выполнять над данными.
На данный момент присутствуют макеты
арифметических и логических операций.
*/
/*Посмотреть на файл evaluator.cpp и переписать поведение следующей функции под неё*/
#include "../Libs/operations.h"
#include "../Libs/types.h"
/*функция вычисления арифметических выражений*/
template <typename M, typename P>
P eval(NumOperations a, M firstArg, M secondArg)
{
    switch(a)
    {
        case NumOperations::ADD :{
            return firstArg + secondArg;
        }
        break;
        case NumOperations::SUB :{
            return firstArg - secondArg;
        }
        break;
        case NumOperations::MULT :{
            return firstArg * secondArg;
        }
        break;
    }

}
/*функции вычисления логических выражений*/
BoolFunc eval(BoolOperations a, BoolFunc b, BoolFunc c)
{
    switch(a)
    {
        case BoolOperations::LOGAND :{
            return (b == BoolFunc::TRUE) ? c : BoolFunc::FALSE;
        }
        break;
        case BoolOperations::LOGOR :{
            return (a == BoolFunc::TRUE) ? BoolFunc::TRUE : c;
        }
        break;
        case BoolOperations::LOGNOT :{
            return b == BoolFunc::TRUE ? BoolFunc::FALSE : BoolFunc::TRUE;
        }
        break;
    }
}

/*функция вычисления операция сравнения*/
BoolFunc eval(CompOperations a, int b, int c)
{
    switch(a)
    {
        
        case CompOperations::LESS :{
            return ((b - c) < 0) ? BoolFunc::TRUE : BoolFunc::FALSE;
        }
        break;
        case CompOperations::EQUAL :{
            return ((b - c) == 0) ? BoolFunc::TRUE : BoolFunc::FALSE;
        }
        break;
        case CompOperations::RATHER :{
            return ((b - c) > 0) ? BoolFunc::TRUE : BoolFunc::FALSE;
        }
        break;
    }
}