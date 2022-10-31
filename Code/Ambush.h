#ifndef AMBUSH_H
#define AMBUSH_H
#include "Strategy.h"


class Ambush : Strategy {

public:
	int stealth;
	Ambush(int stealth,int min,int minFavour);
	bool attack(Bannerman* myBannerman, Bannerman* enemyBannerman);
	~Ambush();
};

#endif
