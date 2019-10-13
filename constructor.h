/*В данном модуле планируется реализовать функции, которые 
  формируют специальную конструкцию для хранения одной функции, описанной в программе
  Подразумевается. что в программе может быть описан некоторый набор фукнкций*/
/*Function->(functionName, [ListArgs], Combinator *)*/
#include "combinators.h"
#include <iostream>
template <class T>
I<T> createI(T elem)
{
    return I<T>(elem);
}
template <class T, typename N>
K<T, N> createK(T firstArg, N secondArg)
{
    return K<T, N>(firstArg, secondArg);
}
template <class T, class P>
S<T, P> createS(T firstArg, P secondArg)
{
    return S<T, P, N>(firstArg, secondArg);
}
}
;