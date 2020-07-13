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
    T constructorTree; // комбинаторная контрукция
    std::string functionName; // имя функции. По нему происходит поиск среди существующих функций и вызов с аргументами
    std::list<std::string> functionArguments; // список параметров, применяемых внутри тела функции 

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