#include "Kingdom.h"

Kingdom::Kingdom(){
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
