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
    int id;//redundant, because we have a name @ Morgan
    list<Raven> ravenList;
    bool assassin;
    MasterOfCoin* m;
    Strategy* strategy;
    WarTheatre* warZone;
    int HP;


public:
    Bannerman();
    /*please note that due to bannerman being an abstract class
     * in accordance with GoF composite design pattern, it's necessary to
     * call the troop constructor instead of the bannerman constructor.*/

    virtual void attackKingdom(Kingdom* X)=0;

    virtual void increaseFavour() = 0;

    virtual void decreaseFavour() = 0;

    virtual void attach(Raven o);

    virtual void detach(Raven o);

    virtual void increaseHP(int boost) = 0;//implement

    virtual void changeStrategy(Strategy* strategy) = 0;

    virtual void attack(Bannerman* myBannerman, Bannerman* enemyBannerman);

    virtual void increasePower(int boost);//what is power?

    string getName();

    virtual int getHP() = 0;

    virtual int getDamage() = 0;

    virtual void receiveDamage(int) = 0;
    virtual void decreaseWeapons() = 0;
    virtual void decreaseFood() = 0;
    virtual void decreaseMedical() = 0;

    warTheatre* getWarZone();

    virtual int getWeapons() = 0;

    virtual int getFood() = 0;

    virtual int getMedical() = 0;

    virtual void setWeapons(int numWeapons) = 0;

    virtual void setFood(int numFood) = 0;

    virtual void setMedical(int numMedical) = 0;
};

#endif
