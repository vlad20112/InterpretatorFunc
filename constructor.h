/*В данном модуле планируется реализовать функции, которые 
  формируют специальную конструкцию для хранения одной функции, описанной в программе
  Подразумевается. что в программе может быть описан некоторый набор фукнкций*/
/*Function->(functionName, [ListArgs], Combinator *)*/
template <typename T>
I<T> createI(T elem);
template <typename T>
K<T> createK(T firstArg);
template <class T, class P>
S<T,P> createS(T firstArg, P secondArg);