#ifndef FUNC_ADAP
#define FUNC_ADAP

#include "../Libs/tree.h"
#include "AbstractAdapter.hpp"
class FuncAdapter: public IAdapter
{
    private:
        func_node *m_func = NULL;
    public:
        FuncAdapter();
        FuncAdapter(func_node *func);
        ~FuncAdapter();
        void printBody() override;
        size_t getSize() override;
};

class FuncInfo {
private:
    func_node *m_func = NULL;
public:
    FuncInfo();
    FuncInfo(func_node *func);
    ~FuncInfo();
    size_t get_arg_count();
    void printTree();
    void printArgs();
    void print_app_args(arg_list *arguments);
    void print_lam_args(act_elem *body);
    int print_app_args_count(arg_list *arguments);
    int print_lam_args_count(act_elem *body);
};
#endif