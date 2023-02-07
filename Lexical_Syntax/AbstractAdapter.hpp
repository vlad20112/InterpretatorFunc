#ifndef ABST_ADAP
#define ABST_ADAP
#include <cstdlib>
class IAdapter
{
    public:
        virtual void printBody();
        virtual size_t getSize();
};

#endif