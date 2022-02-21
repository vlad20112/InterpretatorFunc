/*В данном модуле планируется реализовать функции, которые 
  формируют специальную конструкцию для хранения одной функции, описанной в программе
  Подразумевается. что в программе может быть описан некоторый набор фукнкций
Function->(functionName, [ListArgs], Combinator *)*/
#ifndef CONSTR_H
#define CONSTR_H
#include "constructorElem.h"
#include "../Libs/combinators.h"
#include "../Libs/contVar.h"
template <typename T>
I createI();
template <typename T>
K<T> createK(T firstArg);
template <class T, class P>
S<T,P> createS(T firstArg, P secondArg);
template <class T>
T transformToSK(int ch, contVar container[])
{
  T result;
  return result;
}
#endif