#include "Ambush.h"

bool Ambush::attack(Bannerman* myBannerman, Bannerman* enemyBannerman){
	/*if (stealth>60)
	{
		//tell Thapelo we must decide on power or damage
		myBannerman->increasePower();
		//tell thapelo to implement decrease power
		enemyBannerman->decreasePower();
	}
	 
	while (myBannerman->getHP()>0&&enemyBannerman->getHP()>0)
	{
		//getDamage is how much damage the bannerman can inflict
		enemyBannerman->recieveDamage(myBannerman->getDamage());
		if ((enemyBannerman->getFood()+enemyBannerman->getMedical())<0)
		{
			enemyBannerman->recieveDamage(myBannerman->getDamage());
		} else {
			enemyBannerman->decreaseMedical();
			enemyBannerman->decreaseFood();
		}
		myBannerman->decreaseWeapons();
		
		myBannerman->recieveDamage(enemyBannerman->getDamage());
		if ((myBannerman->getFood()+myBannerman->getMedical())<0)
		{
			myBannerman->recieveDamage(enemyBannerman->getDamage());
		} else {
			myBannerman->decreaseMedical();
			myBannerman->decreaseFood();
		}
		enemyBannerman->decreaseWeapons();
	}
	
	if (myBannerman->getHP()>0&&enemyBannerman->getHP()<=0)
	{
		//tell Jules about the decrease favour implementation
		if(myBannerman->getFood()>enemyBannerman->getFood()){
			myBannerman->increaseFavour();
		}
		else
		{
			myBannerman->decreaseFavour();
			if (myBannerman->getFavour()<minFavour)
			{
				//add a remove(Bannerman* myBannerman) and add(Bannerman* myBannerman) method to 
				//remove/add a particular bannerman 
				myKingdom->remove(myBannerman);
				//tell thapelo to add id attribute and a getter, we must
				//formulate a way to make bannerman ids unique
				enemyKingdom->add(myBannerman);
				return false;
			}
			
		}
		if (myBannerman->getWeapons()<=minSupplies)
		{
			//tell sameet to add pointer asterisk in treasury class's notify
			m->notify(this);
		}
		enemyKingdom->remove(enemyBannerman);
		return true;
	}
	else if (myBannerman->getHP()<=0&&enemyBannerman->getHP()>0)
	{
		myKingdom->remove(myBannerman);
		return false;
	}
	else
	{
		return false;
	}*/
	throw "Not yet implemented";
}

Ambush::Ambush(int stealth,int min,int minFavour):Strategy(myKingdom,enemyKingdom,myBannerman,enemyBannerman,"Ambush",min,minFavour)  {
	this->stealth=stealth;
}

Ambush::~Ambush(){

}