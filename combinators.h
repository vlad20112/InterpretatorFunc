/*
Combinator* fieldOne;
Combinator* fieldTwo;

Operators -> {(+),(-),(*),(/)}

Function -> (functionName, [ListArgs], Combinator)
Function2 -> ((FunctionName,TypeName),[(ListArgs,TypeArg]), Combinator)

Combinator -> {S, K, I, B, C, B', C'}
типы данных для комбинаторов:
S - 0;
K - 1;
I - 2;
B - 3;
C - 4;
*/
#ifndef COMBINATORS_H
#define COMBINATORS_H
#include <ostream>
using namespace std;
/*абстрактный класс, в котором хранится информация о типе комбинатора*/
class AbstractCombinator
{
private:
    int type;

public:
    void setType(int a)
    {
        type = a;
    }
    int getType() { return type; }
};
/*опиcание ккомбинатора S*/
template <class T, class N>
class S : public AbstractCombinator
{
private:
    T firstArg;
    T secondArg;
public:
    /*реализация конструктора комбинатора S*/
    S<T, N>(T f, N g) : firstArg(f),
                        secondArg(g)
    {
        setType(0);
    }
    T getfirstArg()
    {
        return firstArg;
    }
    N getSecondArg()
    {
        return secondArg;
    }
    /*описание методов ввода/вывода комбинатора S*/
    friend istream &operator>>(std::istream &in, const S<T, N> &elem)
    {
        in >> elem.firstArg >> elem.secondArg;
        return in;
    }
    friend ostream &operator<<(std::ostream &out, const S<T, N> &elem)
    {
        out << "S(" << elem.firstArg << "," << elem.secondArg << ")";
        return out;
    }
    
};
/*опиcание класса К*/
template <typename T>
class K : public AbstractCombinator
{
private:
    T firstArg;

public:
    K(T a);
    T getFirstArg()
    {
        return firstArg;
    }
    /*описание методов ввода/вывода комбинатора К*/
    friend std::ostream &operator<<(std::ostream &out, const K<T> &elem)
    {
        out << "K(" << elem.firstArg << ")";
        return out;
    }
    friend std::istream &operator>>(std::istream &in, const K<T> &elem)
    {
        in >> elem.firstArg ;
        return in;
    }
};
/*реализация конструктора комбинатора К*/
template <typename T>
K<T>::K(T a) : firstArg(a)
{
    setType(1);
}
/*Описание комбинатора I*/
template <typename T>
class I : public AbstractCombinator
{
private:
    T firstArg;

public:
    /*реализация конструктора I*/
    I<T>(T arg) : firstArg(arg)
    {
        setType(2);
    }
    T getArg()
    {
        return firstArg;
    }
    /*описание методов ввода/вывода комбинатора I*/
    friend istream &operator>>(std::istream &in, const I<T> &elem)
    {
        in >> elem.firstArg;
        return in;
    }

    friend ostream &operator<<(std::ostream &out, const I<T> &elem)
    {
        out << "I(" << elem.firstArg << ")";
        return out;
    }
};
#endif