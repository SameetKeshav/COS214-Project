#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy : WarIndicators {

private:
	Bannerman* myBannerman;
	Bannerman* enemyBannerman;

public:
	void attack(Bannerman* myBannerman, Bannerman* enemyBannerman);

	Bannerman* getMyBannerman();

	Bannerman* getEnemyBannerman();
};

#endif
