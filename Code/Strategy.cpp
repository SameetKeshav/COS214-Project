#include "Strategy.h"
Strategy(Bannerman* myBannerman, Bannerman* enemyBannerman,string name){
	strategy=name;
	this->myBannerman=myBannerman;
	this->enemyBannerman=enemyBannerman;
}
void Strategy::attack(Bannerman* myBannerman, Bannerman* enemyBannerman,string name) {
	// TODO - implement Strategy::attack2
	
	throw "Not yet implemented";
}

Bannerman* Strategy::getMyBannerman() {
	return this->myBannerman;
}

Bannerman* Strategy::getEnemyBannerman() {
	return this->enemyBannerman;
}
