#ifndef COMMANDER_H
#define COMMANDER_H

#include "Bannerman.h"
#include "ConIterator.h"
#include <list>
class Iterator;
using namespace std;
class Commander : public Bannerman {
private:
    list<Bannerman*> groundForces;

public:

    Commander();//new function

    Iterator* createIterator();

    void removeBannerman(Bannerman* x);

    void attackKingdom(Kingdom* X) override;

    void addBannerman(Bannerman* b);

    int getHP();

    int getDamage();

    void receiveDamage(int);

    void decreaseWeapons();
    void decreaseFood();
    void decreaseMedical();

    int getWeapons() override;

    int getFood() override;

    int getMedical() override;

    void increaseHP(int boost) override;

    void changeStrategy(Strategy* strategy) override;

    void increaseFavour() override;

    void decreaseFavour() override;

    void setWeapons(int numWeapons);

    void setFood(int numFood);

    void setMedical(int numMedical);

    ~Commander();//new function
};

#endif
