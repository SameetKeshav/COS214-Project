#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>
#include <ctime>
#include "Bannerman.h"
#include "WarIndicators.h"
#include "MasterOfCoin.h"
#include "Kingdom.h"
#include "HistoryBook.h"
#include "Historian.h"

using namespace std;
class Historian;
class HistoryBook;
class Bannerman;
class Kingdom;
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
	/**Caretaker for memento implementation**/
	HistoryBook* BookOfDura;
	/**Historian (originator) to save defected bannemen**/
	Historian* Greg;
	/**amount of defected allies**/
	int defectedAllies;
public:
	/** @brief  constructor. initializes myKingdom, enemyKingdom, myBannerman, enemyBannerman, strategy, minSupplies
	 *  and minFavour.
	 * @param myKingdom - Kingdom pointer of attacking Bannerman's Kingdom.
	 * @param enemyKingdom - Kingdom pointer of enemyBannerman's Kingdom.
	 * @param myBannerman - attacking Bannerman.
	 * @param enemyBannerman - defending Bannerman.
	 * @param name - name of concrete strategy.
	 * @param min - minimum supplies for food,weapons and medicine
	 * @param minFavour - minimum favour below which bannerman change allegiances
	 * @param h - Historian (originator) to save defected bannemen.
	 * @param hb - Caretaker for memento implementation.
	*/
	Strategy(Kingdom* myKingdom,Kingdom* enemyKingdom,Bannerman* myBannerman, Bannerman* enemyBannerman,string name,int min,int minFavour, Historian* h, HistoryBook* hb);
	/** @brief Abstract method
	 * @param myBannerman - attacking Bannerman object.
	 * @param enemyBannerman - Bannerman object being attacked.
	 * @return battle result as a boolean with true implying the attacking bannerman object
	 * won and false implying the opposite**/
	virtual bool attack(Bannerman* myBannerman, Bannerman* enemyBannerman)=0;
	/** @brief gets strategy variable
	 * @return strategy variable**/
	virtual string getStrategyName();
	/** @brief gets attacking Bannerman
	 *  @return myBannerman pointer**/
	virtual Bannerman* getMyBannerman();
	/** @brief gets Bannerman being attacked
	 *  @return enemyBannerman pointer**/
	virtual Bannerman* getEnemyBannerman();
	/** @brief destructor. deallocates all pointers of this class**/
	virtual ~Strategy();
};
#endif
