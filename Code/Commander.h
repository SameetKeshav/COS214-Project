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
    void attack(Bannerman* myBannerman, Bannerman* enemyBannerman) override;

    void addBannerman(Bannerman* b);


    /**
 * Returns the HP.
 *
 * @return The total Bannermen HP.
 */
    int getHP() override;

    /**
* Returns the damage.
*
* @return The total Bannermen damage.
*/
    int getDamage() override;

    void attach(Raven* o) override;

    void detach(Raven* o) override;

    void receiveDamage(int) override;

    void decreaseWeapons() override;
    void decreaseFood() override;
    void decreaseMedical() override;

    void increasePower(int boost) override;

    /**
* Returns numWeapons.
*
* @return The total Bannermen number of Weapons.
*/
    int getWeapons() override;

    /**
* Returns numFood.
*
* @return The total Bannermen amount of food.
*/
    int getFood() override;

    /**
* Returns numMedical.
*
* @return The total Bannermen amount of medicals.
*/
    int getMedical() override;


    /** increases the HP variables of the bannerman objects in groundForces.
@param boost - The number by which to increase the HPs of the bannerman objects in groundForces.
*/
    void increaseHP(int boost) override;

    /** Changes the strategy variable of the bannerman objects in groundForces.
@param strategy - The new strategy bannerman objects in groundForces should have.
*/
    void changeStrategy(Strategy* strategy) override;

    /** Increases the loyalty favour levels variable of the bannerman objects in groundForces by 1.
*/
    void increaseFavour() override;

    /** Decreases the loyalty favour levels variable of the bannerman objects in groundForces by 1.
*/
    void decreaseFavour() override;

    /** Sets the number of weapon supplies of the bannerman objects in groundForces.
@param numWeapons - The new numWeapons bannerman objects in groundForces should have.
*/
    void setWeapons(int numWeapons) override;

    /** Sets the number of food supplies of the bannerman objects in groundForces.
@param numFood - The new numFood bannerman objects in groundForces should have.
*/
    void setFood(int numFood) override;

    /** Sets the number of medical supplies of the bannerman objects in groundForces.
@param numMedical - The new numMedical bannerman objects in groundForces should have.
*/
    void setMedical(int numMedical) override;

    /** Default destructor.
    */
    ~Commander() override;
};

#endif
