#include "ConIterator.h"

ConIterator::ConIterator(list<Bannerman*> X) {
    armyList = X;
    it = armyList.begin();
}

Bannerman* ConIterator::Current() {
    return (*it);
}


Bannerman* ConIterator::next() {///Test
    if(hasNext()) {
        ++it;
        return (*it);
    }else{
        return (*it);
    }
}

bool ConIterator::hasNext() {///Test
    if(it!= armyList.end())
        return true;
    else
        return false;
}

bool ConIterator::isActive() {///Test

    if((*it)->getHP()>0)
        return true;
    else
        return false;
}
