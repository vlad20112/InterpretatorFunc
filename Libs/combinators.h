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
#include "types.h"
using namespace std;
/*абстрактный класс, в котором хранится информация о типе комбинатора*/
class AbstractCombinator
{
private:
    int type;
public:
    void setType(int a) { type = a; }
    const int getType() { return type; }
};
/*опиcание ккомбинатора S*/
template <class T, class N>
class S : public AbstractCombinator
{
private:
    T firstArg;
    N secondArg;
public:
    /*реализация конструктора комбинатора S*/
    S<T, N> (T f, N g) : firstArg(f),
                         secondArg(g)
    {setType(Comb::SS);}
    S<T, N> (T f, N): firstArg(f)
    {setType(Comb::SS);}
    T getFirstArg() { return firstArg; }
    N getSecondArg(){ return secondArg; }
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
    K<T>(T a) : firstArg(a) {setType(Comb::KK);}
    T getFirstArg() {return firstArg;}
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

/*Описание комбинатора I*/
class I : public AbstractCombinator
{
public:
    /*реализация конструктора I*/
    I() {setType(Comb::II);}
    /*описание методов ввода/вывода комбинатора I*/

    friend ostream &operator<<(std::ostream &out, const I &elem)
    {
        out << "I";
        return out;
    }
};
/*реализация B комбинатора*/
template<class T, class N>
class B: public AbstractCombinator
{
private:
    T firstArg;
    N secondArg;
public:
    B<T,N> (T a, N b): firstArg(a),
                       secondArg(b)
    {setType(Comb::BB);}
    T getFirstArg() { return firstArg;}
    N getSecondArg() { return secondArg;}
    friend ostream &operator<<(std::ostream &out, const B<T,N> &elem)
    {
        out << "B(" << elem.firstArg << "," << elem.secondArg << ")";
        return out;
    }
};
//Описание С комбинатора
template<class T, class N>
class C: public AbstractCombinator
{
private:
    T firstArg;
    N secondArg;
public:
    C<T,N> (T a, N b): firstArg(a),
                       secondArg(b)
    {setType(Comb::CC);}
    T getFirstArg() {return firstArg;}
    N getSecondArg() {return secondArg;}
    friend ostream &operator<<(std::ostream &out, const C<T,N> &elem)
    {
        out << "C(" << elem.firstArg << "," << elem.secondArg << ")";
        return out;
    }
};
//дополнительная реализация для вывода на консоль переменных типа std::pair
template <typename T, typename P>
ostream &operator<<(std::ostream &out, std::pair<T,P> &elem){
        out <<"(" << elem.first << "," << elem.second << ")";
        return out;
    }
#endif