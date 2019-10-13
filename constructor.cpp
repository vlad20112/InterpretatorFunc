/*В данном модуле планируется реализовать функции, которые 
  формируют специальную конструкцию для хранения одной функции, описанной в программе
  Подразумевается. что в программе может быть описан некоторый набор фукнкций*/
/*Function->(functionName, [ListArgs], Combinator *)*/
#include "combinators.h"
#include <iostream>
template <class T, class P, typename N>
class Constructor
{
  Constructor(){};
  I<T> createI(T elem)
  {
    return I<T>(elem);
  }
  K<T, N> createK(T firstArg, N secondArg)
  {
    return K<T, N>(firstArg, secondArg);
  }
  S<T, P, N> createS(T firstArg, P secondArg, N thirdArg)
  {
    return S<T, P, N>(firstArg, secondArg, thirdArg);
  }
};