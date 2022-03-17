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
  /*B-комбинатор*/
    friend ostream &operator<<(std::ostream &out, const B<T,N> &elem)
    {
        out << "B(" << elem.firstArg << "," << elem.secondArg << ")";
        return out;
    }
    /*С-комбинатор*/
      friend ostream &operator<<(std::ostream &out, const C<T,N> &elem)
    {
        out << "C(" << elem.firstArg << "," << elem.secondArg << ")";
        return out;
    }
  //дополнительная реализация для вывода на консоль переменных типа std::pair
template <typename T, typename P>
ostream &operator<<(std::ostream &out, std::pair<T,P> &elem){
        out <<"(" << elem.first << "," << elem.second << ")";
        return out;
    }  
};