#include <iostream>
#include "FuncAdapter.hpp"

//FuncInfo::FuncInfo(){}

FuncInfo::FuncInfo(func_node *func):m_func(func) { 
    if (m_func -> funcArgs != NULL)
        std::cout << "args " << m_func -> funcArgs << std::endl;
    if (m_func -> funcName != NULL)
        std::cout << " lolkek " << m_func -> funcName << std::endl;
    if (m_func -> funcBody != NULL)
        std::cout << " cheburek " << (int *)m_func -> funcBody << std::endl;
}

FuncInfo::~FuncInfo()
{
    //delete (m_func);
}

size_t FuncInfo::get_arg_count()
{
    arg_list *list = m_func->funcArgs;
    action_comb curComb = m_func->funcBody->act;
    size_t result = 0;
    std::cout << "Наинаю считать аргументы " << curComb << std::endl;
    switch(m_func -> funcBody -> act)
    {
        case action_comb::APP : {std::cout << "аргументы применение"; result = print_app_args_count(m_func->funcArgs); } break;
        case action_comb::VAR : {std::cout << "аргументы значение"; result = print_app_args_count(m_func->funcArgs); } break;
        case action_comb::LAM : {std::cout << "аргументы лямбда"; result = print_lam_args_count(m_func->funcBody); } break;
    }
    /*while(list->next != NULL)
    {
        result++;
        list = list->next;
    }*/
    return result;
}

void FuncInfo::printArgs()
{
    arg_list *list = m_func->funcArgs;
    switch(m_func -> funcBody->act)
    {
        case action_comb::APP: {print_app_args(m_func->funcArgs); std::cout << "аргументы применение ";} break;
        case action_comb::LAM: {print_lam_args(m_func->funcBody); std::cout << "аргументы лямбда";} break;
        case action_comb::VAR: {print_app_args(m_func->funcArgs); std::cout << "аргументы применение ";} break;
    }
}

void FuncInfo::print_app_args(arg_list *arguments)
{
    while (arguments ->next != NULL)
    {
        std::cout << arguments -> argument << std::endl;
        arguments = arguments -> next;
    }
}

void FuncInfo::print_lam_args(act_elem *body)
{
    while(body ->act == LAM)
    {
        std::cout << body -> elem << " ";
        body = body -> firstArg;
    }
}

int FuncInfo::print_lam_args_count(act_elem *body)
{
    int res = 0;
    while(body ->act == LAM)
    {
        res++;
        body = body -> firstArg;
    }
    return res;
}

int FuncInfo::print_app_args_count(arg_list *arguments)
{
    int res = 0;
    while(arguments->next != NULL)
    {
        res++;
        arguments = arguments->next;
    }
    return res;
}