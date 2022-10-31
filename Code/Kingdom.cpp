#include "Kingdom.h"

Kingdom::Kingdom(Economy* economy){
	this->economy=economy;
}

void Kingdom::remove(Bannerman* b){
	if (bannermen.size()>0)
	{
		for (vector<Bannerman*>::iterator it = bannermen.begin(); it !=bannermen.end(); it++)
		{
			//fix this, add unique IDs to Bannerman, should be initialized to -1
			if ((*it)->getName()==b->getName())
			{
				bannermen.erase(it);
			}
		}
	}
}

void Kingdom::add(Bannerman* b){
	bannermen.push_back(b);
}

Kingdom::~Kingdom(){
	delete economy;
	for (int i = 0; i < bannermen.size(); i++)
	{
		delete bannermen[i];
	}
}

vector<Bannerman*> Kingdom::getKingdom(){
<<<<<<< Updated upstream
	return bannermen;
}

int Kingdom::getSize(){
	return bannermen.size();
}

Bannerman* Kingdom::getAlly(string n){
	if (bannermen.size()>0)
	{
		for (vector<Bannerman*>::iterator it = bannermen.begin(); it !=bannermen.end(); it++)
=======
	return bannerman;
}

int Kingdom::getSize(){
	return bannerman.size();
}

Bannerman* Kingdom::getAlly(string n){
	if (bannerman.size()>0)
	{
		for (vector<Bannerman*>::iterator it = bannerman.begin(); it !=bannerman.end(); it++)
>>>>>>> Stashed changes
		{
			if ((*it)->getName()==n)
			{
				return *it;
			}
		}
	}
<<<<<<< Updated upstream
}

=======
}
>>>>>>> Stashed changes
