#ifndef BANNERMAN_H
#define BANNERMAN_H

class Bannerman : WarIndicators {

protected:
    int favour;
    int numWeapons;
    int damage;
    int numFood;
    int numMedical;
    int id;
    list<Raven> ravenList;

private:
    bool assassin;
    MasterOfCoin m;
    Strategy* strategy;
    warTheatre* warZone;
    int HP;

public:
    Iterator* createIterator();

    virtual void attackKingdom(Kingdom* X);

    virtual void increaseFavour();

    virtual void decreaseFavour();

    virtual void attach(Raven o);

    virtual void detach(Raven o);

    virtual void increaseHP(int boost);

    virtual void changeStrategy(Strategy* strategy);

    virtual void attack(Bannerman* myBannerman, Bannerman* enemyBannerman);

    virtual void increasePower(int boost);

    virtual int getHP();
    virtual int getDamage();
    virtual void receiveDamage(int);
    virtual void decreaseWeapons();
    virtual void decreaseFood();
    virtual void decreaseMedical();

    virtual warTheatre* getWarZone();

    virtual int getWeapons();

    virtual int getFood();

    virtual int getMedical();

    virtual void setWeapons(int numWeapons);

    virtual void setFood(int numFood);

    virtual void setMedical(int numMedical);
};

#endif
