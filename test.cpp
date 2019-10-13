#include "combinators.h"
#include "evaluator.cpp"
#include <iostream>
using namespace std;
int main()
{

    K<char> firArg('+');
    I<char> send('s');
    cout << firArg << endl;
    cout << send << endl;
    cout << send.getType() << endl;
    //cout << applyToCombinator(send, 2) << endl;
    return 0;
}
