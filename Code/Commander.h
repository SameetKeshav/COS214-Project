#ifndef COMMANDER_H
#define COMMANDER_H

#include "Bannerman.h"
#include "ConIterator.h"
#include <list>
class Iterator;
using namespace std;

/** @brief A class that acts as a container/composite for bannerman objects as well as performing operations on and using various bannerman objects.
    @inherit Bannerman
    @author Thapelo Thoka
    @date October 2022
    */
class Commander : public Bannerman {
private:
    /**@brief list of bannerman components.
*/
    list<Bannerman*> groundForces;
    string name;

public:

    /** @brief Commander Constructor which takes in the name of a commander.
     * @param name - name of commander
*/
    Commander(string name);

    /**@brief creates a conIterator object, which is a means to traverse groundForces sequentially.
*/
    Iterator* createIterator();

    /**@brief removes a bannerman object from the groundforces list.
*/
    void removeBannerman(Bannerman* x);

    /**@brief uses strategy to make all troops in groundForces to attack another kingdom.
     * @param myBannerman - The attacking bannerman object.
     * @param enemyBannerman - The bannerman object being attacked.
*/
    void attack(Bannerman* myBannerman, Bannerman* enemyBannerman) override;

    /**@brief adds a bannerman object to the groundforces list.
*/
    void addBannerman(Bannerman* b);


    /**
 * @brief Accessor. Returns the HP.
 *
 * @return The total groundForces HP.
 */
    int getHP() override;

    /**
* @brief Accessor. Returns the damage.
*
* @return The total groundForces damage.
*/
    int getDamage() override;
/**
 * @brief Attaches a Raven observer to all the bannerman objects in the groundForces list
 * @param o - the Raven observer object*/
    void attach(Raven* o) override;

    /**
 * @brief Detaches a Raven observer from all the bannerman objects in the groundForces list
 * @param o - the Raven observer object*/
    void detach(Raven* o) override;

    /**
     * @brief increases the damage variables of the groundForces by x
     * @param x - the number by which to increase the damage variables of the bannerman objects in groundForces.
     * */
    void receiveDamage(int x) override;
    /** @brief decreases the numWeapons variables of the bannerman objects in groundForces by 1.
*/
    void decreaseWeapons() override;
    /** @brief decreases the numFood variables of the bannerman objects in groundForces by 1.
*/
    void decreaseFood() override;
    /** @brief decreases the numMedical variables of the bannerman objects in groundForces by 1.
*/
    void decreaseMedical() override;

        /**@brief increases the damage variables of the bannerman objects in groundForces.
@param boost - The number by which to increase the damage of the bannerman objects in groundForces.
*/
    void increasePower(int boost) override;

    /**
* @brief Accessor. Returns numWeapons.
*
* @return The total groundForces number of Weapons.
*/
    int getWeapons() override;

    /**
* @brief Accessor. Returns the total groundForces amount of food.
*
* @return numFood.
*/
    int getFood() override;

    /**
* @brief Accessor. Returns the total groundForces amount of medical supplies
*
* @return numMedical.
*/
    int getMedical() override;


    /** @brief increases the HP variables of the bannerman objects in groundForces.
@param boost - The number by which to increase the HPs of the bannerman objects in groundForces.
*/
    void increaseHP(int boost) override;

    /** @brief Changes the attack strategy variable of the bannerman objects in groundForces.
@param strategy - The new strategy bannerman objects in groundForces should have.
*/
    void changeStrategy(Strategy* strategy) override;

    /** @brief Increases the loyalty favour levels variable of the bannerman objects in groundForces by 1.
*/
    void increaseFavour() override;

    /** @brief Decreases the loyalty favour levels variable of the bannerman objects in groundForces by 1.
*/
    void decreaseFavour() override;

    int getFavour();

    /** @brief Sets the number of weapon supplies of the bannerman objects in groundForces.
@param numWeapons - The new numWeapons bannerman objects in groundForces should have.
*/
    void setWeapons(int numWeapons) override;

    /** @brief Sets the number of food supplies of the bannerman objects in groundForces.
@param numFood - The new numFood bannerman objects in groundForces should have.
*/
    void setFood(int numFood) override;

    /** @brief Sets the number of medical supplies of the bannerman objects in groundForces.
@param numMedical - The new numMedical bannerman objects in groundForces should have.
*/
    void setMedical(int numMedical) override;

    /** @brief Decreases the damage capability of all the bannerman objects in groundForces.
* @param x - the number by which to decrease damage.
*/
    void decreasePower(int x);

    /** @brief Default destructor.
    */
    ~Commander() ;
    

    //Julianna added:

    /**
 * @brief Assigns a Raven observer list to all the bannerman objects in the groundForces list
 * @param r - the Raven observer list to attach*/
    void setRaven(list<Raven*> r);

    /** @brief Assigns a MasterofCoin mediator all the bannerman objects in
     * the groundForces list to ensure that the army has the supplies it needs.
* @param m - the new MasterOfCoin mediator.
*/
    void setMaster(MasterOfCoin* m);

    /** @brief Sets the attack strategy variable of the bannerman objects in groundForces.
@param strategy - The new strategy bannerman objects in groundForces should have.
*/
    void setStrategy(Strategy* s);
};

#endif
