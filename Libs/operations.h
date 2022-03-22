//Файл, в котором описаны коды для основных операций
#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "types.h"
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
template<typename M, typename N, typename T>
M applyToCombinator(Comb cb , M f, N g, T x);
template<typename M, typename T>
M applyToCombinator(Comb cb, M x, T y);
template <typename T>
T applyToCombinator(Comb cb, T x);

#endif