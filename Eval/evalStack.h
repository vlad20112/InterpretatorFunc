/*под полями с шаблонами В и С могут быть как константные значения, так и указатели на результат некоторой операции */
#ifndef EVALSTACK_H
#define EVALSTACK_H
#include <list>
template <class A, class B>
class OperationLine{
    private:
        // здесь будет храниться код операции
        int operations;
        // здесь надо бы обдумать, что хранить 
        A argument_one; 
        // и здесь тоже нужно подумать
        B argument_two; 
        // здесь хранится результат выполнения операции. Пока это целочисленные значения
        int result;     
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
class OperationStack{
    private:
        std::list<OperationLine<A,B>> listComands;
    public:
    //Конструктор, дестркутор
        OperationStack();
        ~OperationStack();
    /* Реализация оператора возврата значения (например, действие ($2) должно вернуть 
       значение поля result из строки под номером 2)
    */
        const int &operator$(int index){ return listComands[index].getResult; }
        void addComand(OperationLine<A,B> elem) { listComands.push_back(elem); }
        void getResultStack()
        {
            for(int i = listComands.length();i > 1; i--)
            {
                int promRes = evalRes(
                listComands[i].getOperation(),
                listComands[i].getArgOne(),
                listComands[i].getArgTwo()
                );
            listComands[i].listComands.setResult(promRes);
            }   
        }
        
    };
#endif