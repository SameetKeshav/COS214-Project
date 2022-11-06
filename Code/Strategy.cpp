#include "Strategy.h"

Strategy::Strategy(Kingdom* myKingdom,Kingdom* enemyKingdom,Bannerman* myBannerman, Bannerman* enemyBannerman,string name,int min,int minFavour, Historian* h, HistoryBook* hb){
	strategy=name;
	minSupplies=min;
	this->minFavour=minFavour;
	this->myBannerman=myBannerman;
	this->enemyBannerman=enemyBannerman;
	this->enemyKingdom=enemyKingdom;
	this->myKingdom=myKingdom;
	Greg = h;
	BookOfDura = hb;
	defectedAllies=0;
}


string Strategy::getStrategyName(){
	return strategy;
}

Bannerman* Strategy::getMyBannerman() {
	return this->myBannerman;
}

Bannerman* Strategy::getEnemyBannerman() {
	return this->enemyBannerman;
}

Strategy::~Strategy(){
	delete myKingdom;
	delete enemyKingdom;
}