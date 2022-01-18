/*В данном модуле планируется реализовать функции, которые 
  формируют специальную конструкцию для хранения одной функции, описанной в программе
  Подразумевается. что в программе может быть описан некоторый набор фукнкций
Function->(functionName, [ListArgs], Combinator *)
Сами комбинаторы не дожны ничего знать о типе данных, которые в них помещаются*/

#include "../Libs/combinators.h"
#include "constructor.h"
#include <iostream>

template <typename T>
I<T> createI(T elem)
  {
    return I<T>(elem);
  }
template<typename T>
K<T> createK(T firstArg)
  {
    K<T> result(firstArg);
    return result;
  }
template<class T, class P>
S<T,P> createS(T firstArg, P secondArg)
  {
    return S<T, P>(firstArg, secondArg);
  }
//Затравка для дальнейших изменений
