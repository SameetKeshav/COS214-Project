#ifndef TROOP_H
#define TROOP_H
#include "Kingdom.h"
#include "Strategy.h"
#include "Bannerman.h"

/** @brief A class that defines the primitive objects of the Bannerman composition
 * @inherit Bannerman
    @author Thapelo Thoka
    @date October 2022
    */
class Troop : public Bannerman {

private:

    /**The number of soldiers in the troop*/
    int size;

    /**The attack strategy used by the troop in battle*/
    Strategy* strategy;

    /**The damage capability which the troop has*/
    int damage;

public:
    /**
     * @brief Constructor. Initializes the name; favour; numFood;  Medical;
     * HP; warZone; strategy; m; assassin and size variables of the troop.
     * */
    Troop(string name, int favor, int numFood, int Medical, int HP,WarTheatre*warZone,Strategy*strategy,MasterOfCoin* m, bool assassin, int size);

    /**
* @brief Returns the troop's HP.
*
* @return HP.
*/
    int getHP() override;

    /**
* @brief Returns the troop's size.
*
* @return size.
*/
    int getSize();

    /**
 * @brief Attaches a Raven observer to the troop.
 * @param o - the Raven observer object to attach*/
    void attach(Raven* o) override;

    /**
 * @brief Detaches a Raven observer to the troop.
 * @param o - the Raven observer object to detach*/
    void detach(Raven* o) override;

    /**@brief increases the damage variables of the troop.
@param boost - The number by which to increase the damage of the troop.
*/
    void increasePower(int boost) override;

    /**@brief uses strategy to make a troop attack another kingdom.
 * @param myBannerman - The attacking bannerman object.
 * @param enemyBannerman - The bannerman object being attacked.
*/
    void attack(Bannerman* myBannerman, Bannerman* enemyBannerman) override;

    /** @brief decreases the numWeapons variable of the troop by 1.
*/
    void decreaseWeapons() override;

    /** @brief decreases the numFood variable of the troop by 1.
*/
    void decreaseFood() override;

    /** @brief decreases the numMedical variable of the troop by 1.
*/
    void decreaseMedical() override;

    /** @brief Changes the attack strategy of the troop.
@param strategy - The new strategy the troop should have.
*/
    void changeStrategy(Strategy* strategy) override;

    /** @brief Increases the loyalty favour level of the troop by 1.
*/
    void increaseFavour() override;

    /** @brief Decreases the loyalty favour level of the troop by 1.
*/
    void decreaseFavour() override;

    int getFavour();

    /** @brief increases the HP of the troop.
@param boost - The number by which to increase the HP of the troop.
*/
    void increaseHP(int boost) override;
    /**
    * @brief Accessor. Returns the damage capacity of the troop.
    *
    * @return damage.
    */
    int getDamage() override;

    /**
 * @brief increases the damage capacity of the troop.
 * @param X - the number by which to increase the damage capacity of the troop.
 * */
    void receiveDamage(int X) override;

    /**
* @brief Accessor. Returns the number of weapons the troop has.
*
* @return numWeapons.
*/
    int getWeapons() override;

    /**
* @brief Accessor. Returns the amount of food the troop has.
*
* @return numFood.
*/
    int getFood() override;

    /**
* @brief Accessor. Returns the number of medical supplies the troop has.
*
* @return numMedical.
*/
    int getMedical() override;

    /** @brief Sets the number of weapon supplies the troop has.
@param numWeapons - The new numWeapons the troop should have.
*/
    void setWeapons(int numWeapons) override;

    /** @brief Sets the number of food supplies the troop has.
@param numFood - The new numFood the troop should have.
*/
    void setFood(int numFood) override;



    /** @brief Decreases the damage capability of the troop.
 * @param x - the number by which to decrease damage.
*/
    void decreasePower(int x);


    /** @brief Sets the number of medical supplies the troop has.
@param numMedical - The new numMedical the troop should have.
*/
    void setMedical(int numMedical) override;

/** @brief Assigns a list of Raven Observers to the troop's ravenList.
* @param r - the list of Raven Observers to attach to the troop.
*/
    void setRaven(list<Raven*> r);

    /** @brief Assigns a MasterofCoin mediator to ensure that the troop has the supplies it needs.
* @param m - the new MasterOfCoin mediator to assign to the troop.
*/
    void setMaster(MasterOfCoin* m);

    /** Default destructor.
*/
    ~Troop();
};

#endif
