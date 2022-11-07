#ifndef ASSASSINATE_H
#define ASSASSINATE_H
#include "Strategy.h"

/** @brief A concrete strategy class.
    A class that provides an alternative strategy for how Bannerman will fight enemyBannerman.
    @author Morgan Bentley
    @date October 2022
    */
class Assassinate :public Strategy {

private:
	/**skill level of Assassin from Bannerman using this strategy**/
	int stealth;
	/**life state of Bannerman's assassin, is false if assassin was killed**/
	bool alive;
public:
	/** @todo  constructor. initializes stealth and calls base class constructor to
	 * initialize myKingdom, enemyKingdom, myBannerman, enemyBannerman, strategy, min and minFavour.
	 * @param stealth - skill level of Bannerman's assassin.
	 * @param alive -life state of Bannerman's assassin, is false if assassin was killed.
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
	Assassinate(int stealth, bool alive,Kingdom* myKingdom,Kingdom* enemyKingdom,Bannerman* myBannerman, Bannerman* enemyBannerman,string name,int min,int minFavour, Historian* h, HistoryBook* hb);
	/** @todo makes assassin of attacking Bannerman try to kill enemyBannerman
	 * @param myBannerman - attacking Bannerman object.
	 * @param enemyBannerman - Bannerman object being attacked.
	 * @return battle result as a boolean with true implying the attacking Bannerman object
	 * won and false implying the opposite**/
	bool attack(Bannerman* myBannerman, Bannerman* enemyBannerman);
	/** @todo destructor.**/
	~Assassinate();
};

#endif
