#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Libs/tree.h"
#include "TransformModule/transform.cpp"
#include "TransformModule/transformFunc.cpp"
#include "TransformModule/transformCombinator.h"
#include "Eval/Applier.hpp"
using namespace std;
int main()
{
// Тесты для первичных комбинаторных конструкций
    int a;
    char *testExpr = "x + y";
    act_elem myElem;
    myElem.act = VAR;
    myElem.elem = "34";
    myElem.firstArg = NULL;
    myElem.secondArg = NULL;
    act_elem *myRes = transformVarToTree("x");
    act_elem *multRes = transformVarToTree("*");
    act_elem *numRes = transformVarToTree("12");
    act_elem *experimRes = transformAppToTree("y","+",numRes);
    act_elem *myResExpr = transformAppToTree("y", "+", myRes);
    act_elem *myResExprTwo = transformAppToTree("p", "*", myResExpr);
    act_elem *myResLamOne = transformLamToTree("x", &myElem);
    act_elem *myResLamTwo = transformLamToTree("y", myResLamOne);
    //std::cout << ((sizeof(myReыs) > 0)? myRes->elem : "No") << std::endl;
    act_elem *promer = myResExprTwo;

    combinator_elem *SComb, *KComb, *IComb;
    IComb = createI();
    KComb = createK(multRes);
    SComb = createS(myRes, "21");
    SComb -> element = S;
    SComb->firstArg = KComb;
    SComb ->secondArg = IComb;
    //printTreeElem(promer);
    promer = myResExprTwo;
    //printTreeElem(myResLamTwo);
    arg_list *argus, *tail;
    argus = (arg_list *)malloc(sizeof(arg_list *));
    argus -> next = NULL;
    addArgToList(argus, "kukaracha");
    addArgToList(argus, "lolkek");
    std::cout << "печатаю аргументы" << std::endl;
    printArgList(argus);
    char *liner;
   // liner = (char *)malloc(sizeof(char *) * 10);
    liner = "lolkekche";
    std::cout << "It's OK \n" << std::endl;
    std::cout <<liner << std::endl;
    //liner = (char *)realloc(liner, 20);
    std::cout << liner << std::endl;
    std::cout << "It's OK again \n" << std::endl;
    printTreeElem(myResExpr);
    //free(liner);
    /*char **linerMas;
    linerMas = (char **) calloc(10, sizeof(char **));
    std::cout << "It's OK three \n" << std::endl;
    for(size_t i; i < 10; i++)
        strcpy(*(linerMas), "lolkek"); 
    while(*(linerMas) !=NULL)
        {
            if(*(linerMas) == NULL)
                std::cout << "0" << std::endl;
            else
                std::cout << "1" << std::endl;
            linerMas++;
        }
    free(linerMas);*/
//Тесты для первичного преобразования к SK-виду
    combinator_elem *myElementus = transformToSK(myResExpr, "x");
    combinator_elem *Ielem, *nextElem, *KElem, *SElem, *SSelem;
    Ielem = createI();
    std::cout << "Я создал комбинатор I" << std::endl;
    KElem = createK(myRes);
    std::cout << "Я создал комбинатор K" << std::endl;
    nextElem = transformToSKLate(Ielem, "p");
    printCombinator(myElementus);
    std::cout << std::endl;
    std::cout << "Вывод комбинатора I" << std::endl;
    std::cout << std::endl;
    printCombinator(nextElem);
    nextElem = transformToSKLate(KElem, "x");
    std::cout << "Вывод комбинатор K" << std::endl;
    printCombinator(nextElem);
    SElem = createS(myResExpr, "p");
    SSelem = createS(experimRes, "y");
    nextElem = transformToSKLate(myElementus, "y");
    std::cout << "Вывод комбинатор S" << std::endl;
    printCombinator(nextElem);
    nextElem = transformToSKLate(SSelem, "y");
    std::cout << std::endl;
    printCombinator(SComb);
    std::cout << "Проверяю функции применения аргументов к комбинаторам" << std::endl;
    Applier apper;
    std::string combResult = "17";
    apply_elem *endSeq;
    endSeq = (apply_elem *) malloc(sizeof(apply_elem *));
    //strcpy(endSeq.cell,"lololo");
    apper.applyArgumentToCombinator(endSeq, nextElem, combResult);
    //apper.deleteEmptyLeaf(endSeq);
    //apper.applyArgumentToCombinator(endSeq, next, combResult);
    std::cout << "Вывожу результат применения аргумента" << std::endl;
    apper.printApplyArgument(endSeq);
}