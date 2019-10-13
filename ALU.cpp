/*
Пока я представляю себе этот модуль как 
набор реализованных основных операций,
которые можно выполнять над данными.
На данный момент присутствуют макеты
арифметических и логических операций.

*/
enum class Operators
{
    Add = 1,
    Sub,
    Mult,
    Div
};
enum class BoolFunc
{
    FALSE,
    TRUE

};
enum class Ord
{
    LT,
    EQ,
    RT
};
template <class T, typename N>
class Eval
{
    int add(T x, N, y)
    {
    }
    int sub(T x, N y)
    {
    }
    int mult(T x, N y)
    {
    }

    int div(T x, N y)
    {
    }
};
BoolFunc logAnd(BoolFunc x, BoolFunc y)
{
    return (x == BoolFunc::TRUE) ? y : BoolFunc::FALSE;
}
BoolFunc logOr(BoolFunc x, BoolFunc y)
{
    return (x == BoolFunc::TRUE) ? BoolFunc::TRUE : y;
}
BoolFunc logNot(BoolFunc x)
{
    x == BoolFunc::TRUE ? BoolFunc::FALSE : BoolFunc::TRUE;
}