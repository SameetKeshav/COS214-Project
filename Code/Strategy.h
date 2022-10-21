#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy : WarIndicators {

private:
	Bannerman* myBannerman;
	Bannerman* enemyBannerman;
	string strategy;

public:
	Strategy(Bannerman* myBannerman, Bannerman* enemyBannerman,string name);
	void attack(Bannerman* myBannerman, Bannerman* enemyBannerman);

	Bannerman* getMyBannerman();

	Bannerman* getEnemyBannerman();
};

#endif
