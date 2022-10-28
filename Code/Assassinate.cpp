#include "Assassinate.h"

Assassinate::Assassinate(int stealth, bool alive,int min,int minFavour):Strategy(myKingdom,enemyKingdom,myBannerman,enemyBannerman,"Assassinate",min,minFavour) {
	this->alive=alive;
	this->stealth=stealth;
}

bool Assassinate::attack(Bannerman* myBannerman, Bannerman* enemyBannerman) {
	if (alive)
	{
		if (stealth>60)
		{
			enemyBannerman->recieveDamage(myBannerman->getDamage());
			enemyBannerman->decreaseFavour();
		}
		else
		{
			alive=false;
		}
		
	}
	return alive;
}

Assassinate::~Assassinate(){

}
