#include "evaluator.h"
#include <iostream>
BoolFunc logicAnd(BoolFunc a, BoolFunc b);
BoolFunc logicOr(BoolFunc a, BoolFunc b);
BoolFunc logicNot(BoolFunc a);

/*функции выполнения операции применения аргумента к комбинаторам*/
//Функция для К-комбинатора
template<typename T, typename P>
auto applyToCombinator(K<T> a, P b) {
    return a.getFirstArg();
}
//Функция для I - комбинатора
template<typename H, typename P>
auto applyToCombinator(I<H> a, P b)
{
    return b;
}

/*Возможные случаи для S-комбинатора*/
template<class T, class N, typename P>
std::pair<T,N> applyToCombinator(S<T,N> a, P b)
{
    auto leftLeaf = applyToCombinator(a.getFirstArg(),b);
    auto rightLeaf = applyToCombinator(a.getSecondArg(),b);
    return std::make_pair(leftLeaf, rightLeaf);
}
// Случай S(S(_,_),S(_,_))
template<typename T, typename N, typename H, typename K, typename P>
std::pair<std::pair<T,H>, std::pair<N,K>> applyToCombinator(S<S<T,H>, S<N,K> > a, P b)
{
    auto leftLeaf = applyToCombinator(a.getFirstArg(), b);
    //std::cout << "left comb" << leftLeaf << endl; 
    auto rightLeaf = applyToCombinator(a.getSecondArg(), b);
    //std::cout << "right comb" << rightLeaf << endl;
    auto result = std::make_pair(leftLeaf, rightLeaf);
    //std::cout << "final combinator: "<< result << endl;
    return result;
    //return std::make_pair(leftLeaf, rightLeaf);
}


//Случай S(K,K)
template<typename T, typename N, typename P>
std::pair<T,N> applyToCombinator(S<K<T>,K<N> > a, P b)
{
    auto leftLeaf = applyToCombinator(a.getFirstArg(),b);
    std::cout << "left comb" << leftLeaf << endl;
    auto rightLeaf = applyToCombinator(a.getSecondArg(),b);
    std::cout << "left comb" << rightLeaf << endl;
    return std::make_pair(leftLeaf, rightLeaf);
}
//случай S(K,I)
template<typename T, typename N, typename P>
std::pair<T,P> applyToCombinator(S<K<T>,I<N> > a, P b)
{
    auto leftLeaf = applyToCombinator(a.getFirstArg(),b);
    auto rightLeaf = applyToCombinator(a.getSecondArg(),b);
    return std::make_pair(leftLeaf, rightLeaf);
}
//Случай S(S(K,K),I)
template<typename T, typename H, typename R, typename P>
std::pair<std::pair<T,H>,R> applyToCombinator(S <S <K<T>, K<H> >, I<R> > a, P b)
{
    auto leftLeaf = applyToCombinator(a.getFirstArg(), b);
    auto rightLeaf = applyToCombinator(a.getSecondArg(), b);
    return std::make_pair(leftLeaf, rightLeaf);
}
//Случай получений на вход элемента типа (a,b)
template<typename N, typename P>
std::pair<N, P> applyToCombinator(N a, P b){
    return std::make_pair(a,b);
}

// Функция получения кода команды из символа операции 
int translateToComand(char a)
{
    int b = (int) a;
    int prom = -1;
    switch(b)
    {
        /*блок получения кода операций сравнения*/
        //Знак >
        case 62: {prom = CompOperations::RATHER;} break;
        //Знак =
        case 61: {prom = CompOperations::EQUAL;} break;
        //Знак <
        case 60: {prom = CompOperations::LESS;} break;
        /*блок получения кода булевых операций операций*/
        //Знак |
        case 124:{prom = BoolOperations::LOGOR;} break;
        //Знак &
        case 38:{prom = BoolOperations::LOGAND;} break;
        //Знак ^
        case 94:{prom = BoolOperations::LOGNOT;} break;
        /*Блок получения арифметичесих операций*/
        //Знак +
        case 43:{prom = NumOperations::ADD;} break;
        //Знак -
        case 45:{prom = NumOperations::SUB;} break;
        //Знак *
        case 42:{prom = NumOperations::MULT;} break;
    }
    return prom;
}
/*функция вычисления арифметических операций*/
int evalRes(int a, int b, int c){
    int res = 0;
    switch(a)
    {
        case NumOperations::ADD:  { res = b + c;} break;
        case NumOperations::SUB:  { res = b - c;} break;
        case NumOperations::MULT: { res =  b * c;} break;
    }
    return res;
}
/*функция вычисления логических операций*/
BoolFunc evalRes(int a, BoolFunc b, BoolFunc c)
{
	BoolFunc res = BoolFunc::FALSE;
	switch (a)
	{
		case BoolOperations::LOGAND: { res = logicAnd(b, c); } break;
		case BoolOperations::LOGOR:  { res = logicOr(b, c); } break;
		case BoolOperations::LOGNOT: { res = logicNot(b); } break;
	}
	return res;
}

/*фукнции вычисления логических операций*/
BoolFunc logicAnd(BoolFunc a, BoolFunc b)
{
	return ((a == BoolFunc::TRUE) && (b == BoolFunc::TRUE)) ? BoolFunc::TRUE : BoolFunc::FALSE;
}

BoolFunc logicOr(BoolFunc a, BoolFunc b)
{
	return ((a == BoolFunc::TRUE) || (b == BoolFunc::TRUE)) ? BoolFunc::TRUE : BoolFunc::FALSE;
}
BoolFunc logicNot (BoolFunc a)
{
	return (a == BoolFunc::FALSE) ? BoolFunc::TRUE : BoolFunc::FALSE;
}

/*Функия вычисления результата сравнения*/
Ord compValues (int a, int b, int c)
{
	Ord res = Ord::EQ;
	int interEval = b - c;
	switch(a)
	{
		case CompOperations::EQUAL: { if (interEval == 0) {} } break;
		case CompOperations::LESS:  { if (interEval < 0) res = Ord::LT;} break;
		case CompOperations::RATHER: { if (interEval > 0) res = Ord::RT;} break;
	}
	return res;
}
