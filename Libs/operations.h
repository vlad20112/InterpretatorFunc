//Файл, в котором описаны коды для основных операций
#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <cstdlib>
#include <cstring>
#include "types.h"

/*enum  BoolOperations{
    LOGAND = 20,
    LOGOR,
    LOGNOT
};
enum  CompOperations{
    LESS = 30,
    EQUAL,
    RATHER
};
*/

int isOperator(char ch);

//функция перевода выражения к промежуточному виду

void lineToAction(struct act_elem *result, char *line);

#endif