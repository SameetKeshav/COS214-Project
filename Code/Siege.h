#ifndef SIEGE_H
#define SIEGE_H
#include "Strategy.h"
class Siege :public Strategy {

public:
	int stealth;
	Siege(int stealth,int min,int minFavour);
	bool attack(Bannerman* myBannerman, Bannerman* enemyBannerman);
	~Siege();
};

#endif
