/*
    Этот модуль предназначен для тестирования разных функций, которые будут
    появляться при написании кода
    команда в консоли для компиляции:
    g++ -o <Название_исполняемого_файла>.exe test.cpp -std=c++1y 
*/
#include "Libs/combinators.h"
#include "evaluator.cpp"
#include "constructor.cpp"
#include "constructorElem.h"
#include "evalStack.h"
#include <iostream>
using namespace std;
int main()
{
    /*тестирование на создание комбинаторов*/
    K<char> firArg('+');
    K<int> numb(2);
    I<char> send('x');
    I<int> send2(2);
    S<K<char>, K<int>> combik(firArg, numb);
    S<K<char>, I<int>> combik2(firArg, send2);
    std::pair<char, int> combik3 = applyToCombinator('+',10);
    auto combik4 = createK('-');
    auto combik6 = createI(3);
    auto combik7 = createS(numb, send);
    auto combik8 = createS(combik, combik2);
    auto combik9 = createS(combik, combik6);
    /*сомнительный момент. Надо бы подумать над тем, чтобы выводил корректный результат.
    Разобрался. Дело было в типе данных того аргумента, который задавался при создании I комбинатора*/
    auto res5 = applyToCombinator(combik9, 46);
    auto res4 = applyToCombinator(combik8, 6);
    auto res = applyToCombinator(combik, 5);
    auto res2 = applyToCombinator(combik2,7);
    /*вывыод комбинаторов*/
    cout << firArg << endl;
    cout << send << endl;
    cout << send.getType() << endl;
    cout << applyToCombinator(firArg, 2) << endl;
    cout << res << endl;
    cout <<"res 2 "<< res2 << endl;
   // cout << combik.getFirstArg() << endl;
    //cout << combik.getSecondArg() << endl;
    //cout << applyToCombinator(send, 4) << endl;
    //cout << applyToCombinator(numb, '4') << endl;
    cout << "I comb res " << applyToCombinator(send2, 45) << endl;
    cout << combik4 << endl;
    cout << combik6 << endl;
    cout << combik7 << endl;
    cout << combik8 << endl;
    //cout << combik3.first << " " << combik3.second << endl;
    cout << combik << endl;
    cout << combik2 << endl;
    /*Проверка корректности выполнения команд*/
    cout << "this is comand number: " << translateToComand('+')<<endl;
    cout << "this is comand number: " << translateToComand('=')<<endl;
    cout << "this is comand number: " << translateToComand('*')<<endl;
    cout << "this is comand number: " << translateToComand('-')<<endl;
    cout << "this is comand number: " << translateToComand('4')<<endl;
    cout << res4 << endl;
    cout << res5 << endl;
    cout << "result of working: "<< evalRes(10, 4, 2) << endl;
    OperationLine<int, int> line(11, 3, 6);
    int co = line.getOperation();
    cout << co << endl;
    int kk = line.getArgOne();
    int pp = line.getArgTwo();
    line.setOperation(11);
    line.setArgOne(3);
    line.setArgTwo(6);
    line.setResult(evalRes(co, kk, pp));
    cout <<"Res: " << evalRes(co, kk, pp) << endl;
    cout << "result in struct: " << line.getResult() << endl;
    return 0;
}
