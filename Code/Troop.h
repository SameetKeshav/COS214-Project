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
    Troop(string name, int favor, int numFood, int Medical, int HP,int size,WarTheatre*warZone,Strategy*strategy,MasterOfCoin* m);

    int getHP();

    int getSize();
    string getName();

    void attackKingdom(Kingdom* X);

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
