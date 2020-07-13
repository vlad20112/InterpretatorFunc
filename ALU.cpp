/*
Пока я представляю себе этот модуль как 
набор реализованных основных операций,
которые можно выполнять над данными.
На данный момент присутствуют макеты
арифметических и логических операций.
*/
/*Посмотреть на файл evaluator.cpp и переписать поведение следующей функции под неё*/
#include "operations.h"
/*функция вычисления арифметических выражений*/
template <typename M, typename P>
P eval(NumOperations a, M firstArg, M secondArg)
{
    switch(a)
    {
        case NumOperations::Add :{
            return firstArg + secondArg;
        }
        break;
        case NumOperations::Sub :{
            return firstArg - secondArg;
        }
        break;
        case NumOperations::Mult :{
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
        BoolOperations::logAnd :{
            return (x == BoolFunc::TRUE) ? y : BoolFunc::FALSE;
        }
        break;
        BoolOperations::logOr :{
            return (x == BoolFunc::TRUE) ? BoolFunc::TRUE : y;
        }
        break;
        BoolOperations::logNot :{
            return x == BoolFunc::TRUE ? BoolFunc::FALSE : BoolFunc::TRUE;
        }
        break;
    }
}

/*функция вычисления операция сравнения*/
BoolFunc eval(CompOperations a, int b, int c)
{
    switch(a)
    {
        
        case CompOperations::Less :{
            return ((b - c) < 0) ? BoolFunc::TRUE : BoolFunc::FALSE;
        }
        break;
        case CompOperations::Equal :{
            return ((b - c) == 0) ? BoolFunc::TRUE : BoolFunc::FALSE;
        }
        break;
        case CompOperations::Rather :{
            return ((b - c) > 0) ? BoolFunc::TRUE : BoolFunc::FALSE;
        }
        break;
    }
}