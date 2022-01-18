/*
 В данном модуле описана структура данных, которая выполняет хранение
 всей необходимой информации для составления функции. Неплохо бы 
 её протестировать на наличие недочетов в её проектировании.
*/
#ifndef CONSTRUCTORELEM_H
#define CONSTRUCTORELEM_H
#include <list>
#include <string>
template <class T>
class Construction
{
private:
    // комбинаторная контрукция
    T constructorTree; 
    // имя функции. По нему происходит поиск среди существующих функций и вызов с аргументами
    std::string functionName; 
    // список параметров, применяемых внутри тела функции 
    std::list<std::string> functionArguments; 

public:
    Construction(std::string name, std::list<std::string> arguments, T combinator) : functionName(name),
                                                                                     functionArguments(arguments),
                                                                                     constructorTree(combinator) {}
    T getConstructorTree()
    {
        return constructorTree;
    }
    std::string getFunctionName()
    {
        return functionName;
    }
    std::list<std::string> getArguments()
    {
        return functionArguments;
    }
};
#endif