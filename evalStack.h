/*под полями с шаблонами В и С могут быть как константные значения, так и указатели на результат некоторой операции */
#ifndef EVALSTACK_H
#define EVALSTACK_H
template <class A, class B>
class OperationLine{
    private:
        int operations; // здесь будет храниться код операции
        A argument_one; // здесь надо бы обдумать, что хранить
        B argument_two; // и здесь тоже нужно подумать
        int result;     // здесь хранится результат выполнения операции. Пока это целочисленные значения
    public:
        OperationLine(const int &opCode, const A &a, const B &b):
            operations(opCode),
            argument_one(a),
            argument_two(b),
            result(0){}
        void setOperation(int a){ operations = a;}
        void setArgOne(A a) {argument_one = a;}
        void setArgTwo(B a) {argument_two = a;}
        void setResult(int a){result = a;}
        int getOperation() {return operations;}
        int getResult() {return result;}
        A getArgOne() {return argument_one;}
        B getArgTwo() {return argument_two;}
};

template<class A, class B>
auto createOperationLine(const int &opCode,const A &a, const B &b)
{
    OperationLine<A,B> res (opCode, a, b);
    return res;
}
template<class A, class B>
struct OperationStack{
    std::list<OperationLine<A,B>> listComands;
};
template<class A, class B>
void getResultStack(OperationStack<A,B> comandsList)
{
    for(int i = comandsList.listComands.length(); i--;i > 1)
    {
        int promRes = evalRes(
            comandsList.listComands.getOperation(),
            comandsList.listComands.getArgOne(),
            comandsList.listComands.getArgTwo()
        );
        comandsList.listComands.setResult(promRes);
    }   
}

#endif