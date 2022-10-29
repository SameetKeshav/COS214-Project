#ifndef ASSASSINATE_H
#define ASSASSINATE_H
#include "Strategy.h"
class Assassinate :public Strategy {

private:
	/**skill level of Assassin from Bannerman using this strategy**/
	int stealth;
	/**life state of Bannerman's assassin, is false if assassin was killed**/
	bool alive;
public:
	/** @todo  constructor. initializes stealth and calls base class constructor to
	 * initialize min and minFavour.
	 * @param stealth - skill level of Bannerman's assassin.
	 * @param min - minimum supplies for food,weapons and medicine
	 * @param minFavour - minimum favour below which bannerman change allegiances
	*/
	Assassinate(int stealth, bool alive,int min,int minFavour);
	bool attack(Bannerman* myBannerman, Bannerman* enemyBannerman);
	~Assassinate();
};

#endif
