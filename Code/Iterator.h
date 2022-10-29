#ifndef ITERATOR_H
#define ITERATOR_H
#include "Bannerman.h"
class Iterator {


public:
    virtual Bannerman* Current()=0;

    virtual bool hasNext() = 0;

    virtual Bannerman* next() = 0;

    virtual bool isActive() = 0;
};

#endif
