//Файл, в котором описаны коды для основных операций
#ifndef OPERATIONS_H
#define OPERATIONS_H
enum NumOperations
{
    ADD = 10,
    SUB,
    MULT
};
enum BoolOperations{
    LOGAND = 20,
    LOGOR,
    LOGNOT
};
enum CompOperations{
    LESS = 30,
    EQUAL,
    RATHER
};
#endif