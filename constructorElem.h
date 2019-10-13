#define CONSTRUCTORELEM_H
template <class T>
#include <list>
#include <string>
class Construction
{
private:
    std::string functionName;
    std::list functionArguments;
    T constructorTree;

public:
    Construction(std::string name, std::list arguments, T tree) : functionName(name),
                                                                  functionArguments(arguments),
                                                                  constructorЕree(tree) {}
    T getConstructorTree()
    {
        return constructorTree;
    }
    std::string getFunctionName()
    {
        return functionName;
    }
    std::list getArguments()
    {
        return functionArguments;
    }
};