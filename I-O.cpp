/*
Здесь планировалось реализовать функции,
решающие задачу ввода и вывода пользовательских данных
и результатов вычисления.

 */
#include "combinators.h"
#include <iostream>
using namespace std;
template <typename T, typename N>
class InputOutput
{
  /*ввод-вывод комбинатора К*/
  std::istream &operator>>(std::istream &in, const K<T, N> &elem)
  {
    return in;
  }

  std::ostream &operator<<(std::ostream &out, const K<T, N> &elem)
  {
    out << "K(" << elem.secondArg << "," << elem.secondArg << ")";
    return out;
  }

  /*ввод-вывод комбинатора S*/
  std::istream &operator>>(std::istream &in, const S<T, N> &elem)
  {
    return in;
  }

  std::ostream &operator<<(std::ostream &out, const S<T, N> &elem)
  {
    out << "S(" << elem.firstArg << "," << elem.secondArg << ")";
    return out;
  }
  /*ввод-вывод комбинатора I*/
  std::istream &operator>>(std::istream &in, const I<T> &elem)
  {
    in >> elem.firstArg;
    return in;
  }

  std::ostream &operator<<(std::ostream &out, const I<T> &elem)
  {
    out << "I(" << elem.firstArg << ")";
    return out;
  }
};