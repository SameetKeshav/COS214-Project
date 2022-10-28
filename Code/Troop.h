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

    int getHP() override;

    int getSize();

    void attach(Raven* o) override;

    void detach(Raven* o) override;
    void increasePower(int boost) override;

    void attackKingdom(Kingdom* X);

    void decreaseWeapons() override;
    void decreaseFood() override;
    void decreaseMedical() override;

    void changeStrategy(Strategy* strategy) override;

    void increaseFavour() override;

    void decreaseFavour() override;

    void increaseHP(int boost) override;

    int getDamage() override;

    void receiveDamage(int X) override;

    int getWeapons() override;

    int getFood() override;

    int getMedical() override;

    void setWeapons(int numWeapons) override;

    void setFood(int numFood) override;

    void setMedical(int numMedical) override;

    /** Default destructor.
*/
    ~Troop() override;
};

#endif
