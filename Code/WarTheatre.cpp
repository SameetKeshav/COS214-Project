#include "WarTheatre.h"


WarTheatre::WarTheatre ()
{
	venue = 'a'; //default ankere
}

Strategy* WarTheatre::getStrategy() {;
    return strategy;
}

char WarTheatre::decideVenue(Strategy* strategy)
{
   if(strategy->getStrategyName() == "Battlefield") {
		setStrategy(strategy);
		return  'a';
	}
   if (strategy->getStrategyName() == "Siege") {
		setStrategy(strategy);
		return  'b';
	}
   if (strategy->getStrategyName() == "Ambush"){
		setStrategy(strategy);
		return  'c';
	}
   if (strategy->getStrategyName() == "Assassination") {
		setStrategy(strategy);
		return  'd';
	} else{
		return 'a';
	}
}

void WarTheatre::setStrategy(Strategy* myStrat)
{
	strategy = myStrat;
}

char WarTheatre::getVenue()
{
	return venue;
}

void WarTheatre::setLocation(string loc)
{
	location = loc;
}

void WarTheatre::setDifficulty(int num)
{
	difficulty = num;
}

int WarTheatre::getDifficulty()
{
	return difficulty;
}

void WarTheatre::setVenue(char v)
{
    venue = v;
}