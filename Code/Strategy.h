#ifndef STRATEGY_H
#define STRATEGY_H
using namespace std;
#include <string>
#include "Bannerman.h"
#include "WarIndicators.h"
#include "MasterOfCoin.h"
#include "Kingdom.h"

class Strategy : public WarIndicators  {

protected:
	//modify kingdom to have a getter for bannerman list
	Kingdom* myKingdom;
	Kingdom* enemyKingdom;
	Bannerman* myBannerman;
	Bannerman* enemyBannerman;
	string strategy;
	int minFavour;
	int minSupplies;
public:
	Strategy(Kingdom* myKingdom,Kingdom* enemyKingdom,Bannerman* myBannerman, Bannerman* enemyBannerman,string name,int min,int minFavour);
	virtual bool attack(Bannerman* myBannerman, Bannerman* enemyBannerman);
	string getStrategyName();
	Bannerman* getMyBannerman();
	Bannerman* getEnemyBannerman();
	virtual ~Strategy();
};
#endif
