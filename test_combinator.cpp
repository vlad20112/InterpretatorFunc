#include <iostream>
#include "Libs/types.h"
#include "Libs/operations.cpp"
using namespace std;
int main()
{
    Comb first = S;
    Comb second = K;
    Node myTree;
    myTree.push_back(first);
    myTree.push_back(second);
    auto res = applyToCombinator(second, '+', 3);
    for(auto k:myTree)
        cout << k << endl;
    cout << first << " " << second << "  ___  " << res << endl;
    return 0;   
}