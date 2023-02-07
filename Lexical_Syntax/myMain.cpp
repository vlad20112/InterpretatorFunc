#include <iostream>
#include "../Libs/tree.h"
#include "stdio.h"
#include "syntax.tab.h"
#include "lexer.h"
#include "../TransformModule/transform.h"
#include "../TransformModule/transformFunc.h"
#include "../TransformModule/transformCombinator.h"
#include "FuncAdapter.hpp"

int main()
{
    func_node resulter;
    yyparse(&resulter);
    std::cout << ((resulter.funcName == NULL)? "name is empty \n" : resulter.funcName) << std::endl;
    std::cout << ((resulter.funcBody == NULL)? "body is empty \n" : (const char *)resulter.funcBody) << std::endl;
    std::cout << ((resulter.funcArgs == NULL)? "Args is empty \n" : (const char *)resulter.funcArgs) << std::endl;
    FuncInfo myFunc(&resulter);
    //printArgList((&resulter)->funcArgs);
    std::cout << "out result: " << std::endl;
    std::cout << myFunc.get_arg_count() << std::endl;
    myFunc.printArgs();
    printTreeElem((&resulter) -> funcBody);
    std::cout << " из адаптера \n" << myFunc.get_arg_count() << std::endl;
    return 0;
}