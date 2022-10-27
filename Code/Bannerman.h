#ifndef BANNERMAN_H
#define BANNERMAN_H
#include "Strategy.h"
#include "Iterator.h"
#include "WarTheatre.h"
#include <string>
class Bannerman : public WarIndicators {

protected:
    string name;
    int favour;
    int numWeapons;
    int damage;
    int numFood;
    int numMedical;
    int id;
    list<Raven> ravenList;

    int HP;
private:
    bool assassin;
    MasterOfCoin* m;
    Strategy* strategy;
    WarTheatre* warZone;

public:
    Bannerman(string name, int favor, int numFood, int Medical, int HP,WarTheatre*warZone,Strategy*strategy,MasterOfCoin* m);

    virtual void attackKingdom(Kingdom* X)=0;

    virtual void increaseFavour();

    virtual void decreaseFavour();

    virtual void attach(Raven o);

    virtual void detach(Raven o);

    virtual void increaseHP(int boost) = 0;//implement

    virtual void changeStrategy(Strategy* strategy);

    virtual void attack(Bannerman* myBannerman, Bannerman* enemyBannerman);

    virtual void increasePower(int boost);

    virtual string getName() = 0;

    virtual int getHP() = 0;

    virtual int getDamage() = 0;

    virtual void receiveDamage(int);
    virtual void decreaseWeapons();
    virtual void decreaseFood();
    virtual void decreaseMedical();
    warTheatre* getWarZone();

    virtual int getWeapons() = 0;

    virtual int getFood() = 0;

    virtual int getMedical() = 0;

    virtual void setWeapons(int numWeapons) = 0;

    virtual void setFood(int numFood) = 0;

    virtual void setMedical(int numMedical) = 0;
};

#endif
