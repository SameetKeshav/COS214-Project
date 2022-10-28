#include "Kingdom.h"

Kingdom::Kingdom(Economy* economy,vector<Bannerman*> bannerman){
	this->bannerman=bannerman;
	this->economy=economy;
}

void Kingdom::remove(Bannerman* b){
	if (bannerman.size()>0)
	{
		for (vector<Bannerman*>::iterator it = bannerman.begin(); it !=bannerman.end(); it++)
		{
			//fix this, add unique IDs to Bannerman, should be initialized to -1
			if ((*it)->getID()==b->getID())
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
		delete bannerman[i];
	}
}
