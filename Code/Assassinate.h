#ifndef ASSASSINATE_H
#define ASSASSINATE_H
#include "Strategy.h"
class Assassinate :public Strategy {

private:
	int stealth;
	bool alive;
public:
	Assassinate(int stealth, bool alive,int min,int minFavour);
	bool attack(Bannerman* myBannerman, Bannerman* enemyBannerman);
	~Assassinate();
};

#endif
