#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H
#include "Strategy.h"

class BattleField :public Strategy {

public:
	BattleField(int min,int minFavour);
	bool attack(Bannerman* myBannerman, Bannerman* enemyBannerman);
	~BattleField();
};

#endif
