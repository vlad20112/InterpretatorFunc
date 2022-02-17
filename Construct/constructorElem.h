/*
 В данном модуле описана структура данных, которая выполняет хранение
 всей необходимой информации для составления функции. Неплохо бы 
 её протестировать на наличие недочетов в её проектировании.
*/
#ifndef CONSTRUCTORELEM_H
#define CONSTRUCTORELEM_H
#include <list>
#include <string>
#include "../Libs/types.h"

class Construction
{
private:
    // комбинаторная контрукция
    Node constructorTree; 
    // имя функции. По нему происходит поиск среди существующих функций и вызов с аргументами
    std::string functionName; 
    // список параметров, применяемых внутри тела функции 
    std::list<std::string> functionArguments; 

public:
    Construction(std::string name, std::list<std::string> arguments, Node combinator) : functionName(name),
                                                                                     functionArguments(arguments),
                                                                                     constructorTree(combinator) {}
                                                                                     //Получение комбинаторного дерева
    const Node getConstructorTree()
    {
        return constructorTree;
    }
    //Получение имени функции
    const std::string getFunctionName()
    {
        return functionName;
    }
    //получение набора аргументов
    const std::list<std::string> getArguments()
    {
        return functionArguments;
    }
};
#endif