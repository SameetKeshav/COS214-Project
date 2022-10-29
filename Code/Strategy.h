#ifndef STRATEGY_H
#define STRATEGY_H
using namespace std;
#include <string>
#include "Bannerman.h"
#include "WarIndicators.h"
#include "MasterOfCoin.h"
#include "Kingdom.h"

/** @brief An Abstract strategy class.
    A class that provides an interface to the alternative concrete strategies for how Bannerman
	 will fight enemyBannerman.
    @author Morgan Bentley
    @date October 2022
    */
class Strategy : public WarIndicators  {

protected:
	/**Kingdom pointer of attacking Bannerman's Kingdom**/
	Kingdom* myKingdom;
	/**Kingdom pointer of enemyBannerman's Kingdom**/
	Kingdom* enemyKingdom;
	/**attacking Bannerman**/
	Bannerman* myBannerman;
	/**defending Bannerman**/
	Bannerman* enemyBannerman;
	/**name of concrete strategy**/
	string strategy;
	/**minimum favour below which Bannerman change allegiances**/
	int minFavour;
	/**minimum supplies for food,weapons and medicine**/
	int minSupplies;
public:
	/** @todo  constructor. initializes myKingdom, enemyKingdom, myBannerman, enemyBannerman, strategy, minSupplies
	 *  and minFavour.
	 * @param stealth - skill level of Bannerman.
	 * @param min - minimum supplies for food,weapons and medicine
	 * @param minFavour - minimum favour below which bannerman change allegiances
	*/
	Strategy(Kingdom* myKingdom,Kingdom* enemyKingdom,Bannerman* myBannerman, Bannerman* enemyBannerman,string name,int min,int minFavour);
	/** @todo Abstract method
	 * @param myBannerman - attacking bannerman object.
	 * @param enemyBannerman - Bannerman object being attacked.
	 * @return battle result as a boolean with true implying the attacking bannerman object
	 * won and false implying the opposite**/
	virtual bool attack(Bannerman* myBannerman, Bannerman* enemyBannerman)=0;
	/** @todo gets strategy variable
	 * @return strategy variable**/
	virtual string getStrategyName();
	/** @todo gets attacking Bannerman
	 *  @return myBannerman pointer**/
	virtual Bannerman* getMyBannerman();
	/** @todo gets Bannerman being attacked
	 *  @return enemyBannerman pointer**/
	virtual Bannerman* getEnemyBannerman();
	/** @todo destructor. deallocates all pointers of this class**/
	virtual ~Strategy();
};
#endif
