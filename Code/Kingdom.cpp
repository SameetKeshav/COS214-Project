#include "Kingdom.h"

Kingdom::Kingdom(Economy* economy){
	this->economy=economy;
}

void Kingdom::remove(Bannerman* b){
	if (bannerman.size()>0)
	{
		for (list<Bannerman*>::iterator it = bannerman.begin(); it !=bannerman.end(); it++)
		{
			//fix this, add unique IDs to Bannerman, should be initialized to -1
			if ((*it)->getName()==b->getName())
			{
				bannerman.erase(it);
			}
		}
	}
}

void Kingdom::add(Bannerman* b){
	bannerman.push_back(b);
}

Kingdom::~Kingdom(){
	delete economy;
	for (int i = 0; i < bannerman.size(); i++)
	{
		list<Bannerman*>::iterator it = bannerman.begin();
        advance(it, i);
		delete *it;
	}
}

list<Bannerman *> Kingdom::getKingdom(){
	return bannerman;
}

int Kingdom::getSize(){
	int s = bannerman.size();
	return s;
}

Bannerman* Kingdom::getAlly(string n){
	if (bannerman.size()>0)
	{
		for (list<Bannerman*>::iterator it = bannerman.begin(); it !=bannerman.end(); it++)
		{
			if ((*it)->getName()==n)
			{
				return *it;
			}
		}
	}else{
		return nullptr;
	}
}