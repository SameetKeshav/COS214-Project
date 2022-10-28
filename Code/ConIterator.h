#ifndef CONITERATOR_H
#define CONITERATOR_H
#include "Bannerman.h"
#include "Iterator.h"
#include <list>
using namespace std;
class ConIterator : public Iterator {
private:
    list<Bannerman*> armyList;
    list<Bannerman*>::iterator it;
public:
    ConIterator(list<Bannerman*> X);

    Bannerman* Current();

    Bannerman* next();

    bool hasNext();

    bool isActive();
};

#endif
