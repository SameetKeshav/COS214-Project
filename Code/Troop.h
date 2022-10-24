#ifndef TROOP_H
#define TROOP_H
#include "Kingdom.h"
#include "Strategy.h"
#include "Bannerman.h"
class Troop : Bannerman {

private:
    int HP;
    int size;
    Strategy* strategy;
    int damage;

public:
    Troop(int HP, int tSize, Strategy* strategy);

    int getHP();

    int getSize();

    void attackKingdom(Kingdom* X);

    void receiveDamage(int X);

    ~Troop();
};

#endif
