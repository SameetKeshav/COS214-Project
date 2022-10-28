#ifndef TROOP_H
#define TROOP_H
#include "Kingdom.h"
#include "Strategy.h"
#include "Bannerman.h"
class Troop : public Bannerman {

private:
    int size;
    Strategy* strategy;
    int damage;

public:
    Troop(string name, int favor, int numFood, int Medical, int HP,WarTheatre*warZone,Strategy*strategy,MasterOfCoin* m, bool assassin, int size);

    int getHP();

    int getSize();

    void attackKingdom(Kingdom* X);

    void decreaseWeapons();
    void decreaseFood();
    void decreaseMedical();

    void changeStrategy(Strategy* strategy);

    void increaseFavour();

    void decreaseFavour();

    void increaseHP(int boost);

    int getDamage();

    void receiveDamage(int X);

    int getWeapons();

    int getFood();

    int getMedical();

    void setWeapons(int numWeapons);

    void setFood(int numFood);

    void setMedical(int numMedical);

    ~Troop();
};

#endif
