#ifndef TR_COMBINATOR_H
#define TR_COMBINATOR_H
#include "../Libs/tree.h"
#include <stdlib.h>
#include "string.h"

class CreaterCombinator
{
    private:
        combinator_elem m_elem;
    public:
        combinator_elem getCombinator() {return this -> m_elem;};
        void setCombinator(combinator_elem comb) {m_elem = comb;};
        virtual combinator_elem &applyArgToComb(combinator_elem *node, const char *arg) = 0;
        virtual combinator_elem &createS(act_elem &left, const char *arg) = 0;
        virtual combinator_elem &createS(combinator_elem *left, const char *arg) = 0;
        virtual combinator_elem &createK(combinator_elem *node, const char *arg) = 0;
        virtual combinator_elem &createI(combinator_elem *node, const char *arg) = 0;
};
class Creater: public CreaterCombinator
{
    public:
        combinator_elem &applyArgToComb(combinator_elem *node, const char *arg) override;
        combinator_elem &createS(act_elem &left, const char *arg) override;
        combinator_elem &createS(combinator_elem *left, const char *arg) override;
        combinator_elem &createK(combinator_elem *node, const char *arg) override;
        combinator_elem &createI(combinator_elem *node, const char *arg) override;
};

combinator checkCombinator(act_elem *node, const char *arg);


#endif