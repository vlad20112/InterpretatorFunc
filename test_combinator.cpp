#include <iostream>
#include "Libs/types.h"
#include "Libs/operations.h"
using namespace std;
int main()
{
    Comb first = S;
    Comb second = K;
    Node myTree;
    myTree.push_back(first);
    myTree.push_back(second);
    auto res = applyToCombinator('+', 3, Comb::K);
    for(auto k:myTree)
        cout << k << endl;
    cout << first << " " << second << res << endl;
    return 0;   
}