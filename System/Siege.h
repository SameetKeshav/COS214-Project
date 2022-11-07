#ifndef SIEGE_H
#define SIEGE_H
#include "Strategy.h"

/** @brief A concrete strategy class.
    A class that provides an alternative strategy for how Bannerman will fight enemyBannerman.
    @author Morgan Bentley
    @date October 2022
    */
class Siege :public Strategy {
private:
	/**skill level of Bannerman using this strategy**/
	int stealth;
public:
	/** @brief  constructor. initializes stealth and calls base class constructor to
	 * initialize myKingdom, enemyKingdom, myBannerman, enemyBannerman, strategy, min and minFavour.
	 * @param stealth - skill level of Bannerman.
	 * @param min - minimum supplies for food,weapons and medicine
	 * @param minFavour - minimum favour below which bannerman change allegiances
	*/
	Siege(int stealth,Kingdom* myKingdom,Kingdom* enemyKingdom,Bannerman* myBannerman, Bannerman* enemyBannerman,string name,int min,int minFavour, Historian* h, HistoryBook* hb);
	/** @brief makes two bannerman from enemy kingdoms fight each other until one loses
	 * @param myBannerman - attacking bannerman object.
	 * @param enemyBannerman - Bannerman object being attacked.
	 * @return battle result as a boolean with true implying the attacking bannerman object
	 * won and false implying the opposite**/
	bool attack(Bannerman* myBannerman, Bannerman* enemyBannerman);
	/** @brief destructor.**/
	~Siege();
};

#endif
