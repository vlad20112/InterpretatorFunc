#include <iostream>
#include "Libs/operations.h"

using namespace std;
int main()
{
    /*K<char> Kcom('-');
    I Icom;
    S<K<char>, I> sept(Kcom, Icom);
    auto complex = createS(sept, sept);
    cout << applyToCombinator(Icom, '+') << endl;
    cout << applyToCombinator(Kcom, 3) << endl;
    auto res = applyToCombinator(complex, 3);
    cout << res << endl;*/
    char experiment_string[] = "2 + x";
    struct act_elem *myNode;
    myNode = (struct act_elem *) malloc( sizeof(struct act_elem *) );
    cout << sizeof(myNode)<< endl;
    return 0;
}