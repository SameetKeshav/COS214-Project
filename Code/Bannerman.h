#ifndef BANNERMAN_H
#define BANNERMAN_H
#include "Strategy.h"
#include "Iterator.h"
#include "MasterOfCoin.h"
#include "WarIndicators.h"
#include "Raven.h"
#include "WarTheatre.h"
#include <string>
#include <list>


/** @brief An abstract component class.
    A class that provides the interface with which the client interacts with the country's army.
    @author Thapelo Thoka
    @date October 2022
    */
class Bannerman{

protected:

    /**Name of the bannerman */
    string name;

    /**Amount of favour the bannerman has */
    int favour;

    /**Number of weapons the bannerman has */
    int numWeapons;

    /**Damage capability the bannerman has */
    int damage;

    /**Amount of food the bannerman has */
    int numFood;

    /**Amount of medical supplies the bannerman has */
    int numMedical;

    /**A list of Raven observers that have been attached to the bannerman object */
    list<Raven*> ravenList;

    /**Indicates whether or not the bannerman is an assassin */
    bool assassin;

    /**Mediator for ensuring that the bannerman/army has the supplies it needs. */
    MasterOfCoin* m;

    /**The attack strategy the bannerman uses */
    Strategy* strategy;

    /**The health points of the bannerman */
    int HP;


public:
    /** @brief Default constructor.
*/
    Bannerman(string n);

    /** @brief Abstract. increases the favour of the bannerman.
        */
    virtual void increaseFavour() = 0;

    /** @brief Abstract. decreases the favour of the bannerman.
    */
    virtual void decreaseFavour() = 0;
    
    virtual int getFavour()=0;

    /** @brief Abstract. Attaches a Raven Observer on the bannerman.
     * @param o - the Raven Observer to attach.
*/
    virtual void attach(Raven* o)=0;

    /** @brief Abstract. detaches a Raven Observer from the bannerman.
     * @param o - the Raven Observer to detach.
*/
    virtual void detach(Raven* o)=0;

    /** @brief Abstract. increases the health points(HP) of the bannerman.
     * @param boost - the number by which to increase HP.
*/
    virtual void increaseHP(int boost) = 0;//implement

    /** @brief Abstract. changes the attack strategy of the bannerman.
 * @param strategy - the new attack strategy.
*/
    virtual void changeStrategy(Strategy* strategy) = 0;

    /**@brief Abstract. uses strategy to attack another kingdom.
 * @param myBannerman - The attacking bannerman object.
 * @param enemyBannerman - The bannerman object being attacked.
*/
    virtual void attack(Bannerman* myBannerman, Bannerman* enemyBannerman) = 0;

    /** @brief Abstract. increases the damage capability of the bannerman.
 * @param boost - the number by which to increase damage.
*/
    virtual void increasePower(int boost) = 0;

    /** @brief Accessor that returns the name of the bannerman.
     * @return The name of the bannerman.
        */
    string getName();

    /**@brief Abstract. Accessor that returns the name of the component.
     * @return The name of the bannerman.
        */
    virtual int getHP() = 0;

    /**@brief Abstract. Accessor that returns the damage capability of the bannerman.
 * @return The damage of the bannerman.
    */
    virtual int getDamage() = 0;

    /**@brief Abstract. Increases the damage capability of the bannerman.
* @param boost - the number by which to increase damage
     * */
    virtual void receiveDamage(int boost) = 0;

    /**@brief Abstract. Decreases the number of weapons that the bannerman has */
    virtual void decreaseWeapons() = 0;

    /**@brief Abstract. Decreases the number of food supplies that the bannerman has */
    virtual void decreaseFood() = 0;

    /**@brief Abstract. Decreases the number of medical supplies that the bannerman has */
    virtual void decreaseMedical() = 0;

    /**@brief Abstract. Accessor that returns the number of weapons of the bannerman.
* @return The numWeapons of the bannerman.
*/
    virtual int getWeapons() = 0;

    /**@brief Abstract. Accessor that returns number of food supplies that the bannerman has.
* @return The numFood of the bannerman.
*/
    virtual int getFood() = 0;

    /**@brief Abstract. Accessor that returns the number of medical supplies that the bannerman has.
* @return The numMedical of the bannerman.
*/
    virtual int getMedical() = 0;


    /**@brief Abstract. Sets the  number of weapons of the bannerman
        @param numWeapons - The new name the numWeapons should have
        */
    virtual void setWeapons(int numWeapons) = 0;

    /**@brief Abstract. Sets the number of food supplies that the bannerman has.
    @param numFood - The new numFood the component should have
    */
    virtual void setFood(int numFood) = 0;

    /**@brief Abstract. Sets the number of medical supplies that the bannerman has.
    @param numMedical - The new numMedical the component should have
    */
    virtual void setMedical(int numMedical) = 0;

    /**@brief Default destructor.
*/
    ~Bannerman();
};

#endif