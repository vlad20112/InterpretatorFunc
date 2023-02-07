#ifndef COMBINATOR_ADAPTER_H
#define COMBINATOR_ADAPTER_H
#include <cstdlib>
#include "../Libs/tree.h"
#include "AbstractAdapter.hpp"


class CombinatorAdapter: public IAdapter 
{
    private:
        comb_node *m_comb = NULL;
    public:
        CombinatorAdapter();
        CombinatorAdapter(comb_node *comb);
        ~CombinatorAdapter();
        void printBody() override;
        size_t getSize() override;
};

#endif
