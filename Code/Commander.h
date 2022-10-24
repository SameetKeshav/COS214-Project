#ifndef COMMANDER_H
#define COMMANDER_H

#include "Bannerman.h"
#include "ConIterator.h"
#include <list>
class Iterator;
using namespace std;
class Commander : Bannerman {
private:
    list<Bannerman*> groundForces;

public:

    Commander();//new function

    ConIterator* createIterator();

    void removeTroop(Bannerman* x);

    void attackKingdom(Kingdom* X);

    void addBannerman(Bannerman* b);

    int getTotalWeapons();

    int getTotalFood();

    int getTotalMedical();

    ~Commander();//new function
};

#endif
