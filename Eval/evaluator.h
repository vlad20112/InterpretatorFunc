/* на вход поступает комбинаторная конструкция,
затем происходит её разбор и вычисление результата.
Требуется использовать доплнительные переменные для хранения промежуточного
результата. Например, может возникнуть ситуация появлнения каррированной функции
(ну там (+2)). Такое следует запоминать для дальнейшего выполнения действий.
Также, в этом модуле должен присутствовать оператор применения(изображается как (@)), 
возможны изменения.
 функция преобразует комбинаторную конструкцию к паре вида
 (аргумент 1, аргумент 2), где могут находиться другие пары.
 Пока она реализована в виде сопоставления с образцом.
 Хорошо это или плохо, не знаю. Пока кое-как работает */
#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "evalStack.h"
#include "../Construct/constructor.h"
#include "../Libs/operations.h"
#include "../Libs/combinators.h"
template<typename T, typename P>
auto applyToCombinator(K<T> a, P b);
template<typename T, typename P>
auto applyToCombinator(I<T> a, P b);
template<class T, class N, typename P>
std::pair<T,N> applyToCombinator(S<T,N> a, P b);
template<typename T, typename N, typename P>
std::pair<T,N> applyToCombinator(S<K<T>,K<N>> a, P b);
template<typename T,typename N, typename P>
std::pair<T,P> applyToCombinator(S<K<T>,I<N>> a, P b);
template <typename N, typename P>
std::pair<N, P> applyToCombinator (N a, P b);
int evalRes(int a, int b, int c);
int translateToComand(char a);
//функция возвращает код хранимой в комбинаторе операции
int translateToComand(char a);
BoolFunc evalRes(int a, BoolFunc b, BoolFunc c);
BoolFunc logicAnd(BoolFunc a, BoolFunc b);
BoolFunc logicOr(BoolFunc a, BoolFunc b);
BoolFunc logicNot (BoolFunc a);
Ord compValues (int a, int b, int c);
#endif 