#include "operations.h"
template <typename M, typename N, typename P>
M applyToCombinator(Comb cb,  M f, N g , P x )
{
    M result;

    return result;
}


template <typename M, typename T>
M applyToCombinator(Comb cb, M x, T y)
{
    return x;
}
template <typename T>
T applyToCombinator(Comb cb, T x)
{
    return x;
}
