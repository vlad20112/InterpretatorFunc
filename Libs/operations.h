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
M applyToCombinator(M f, N g, T x, Comb cb = S);
template<typename M, typename T>
T applyToCombinator(M x, T y, Comb cb = K);
template <typename T>
T applyToCombinator(T x, Comb cb = I);

#endif