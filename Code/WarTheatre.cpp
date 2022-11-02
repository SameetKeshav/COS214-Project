#include "WarTheatre.h"

<<<<<<< Updated upstream
WarTheatre::WarTheatre(Strategy* myStrat) {
	// TODO - implement WarTheatre::WarTheatre
	//throw "Not yet implemented";
    strategy = myStrat;
    venue = decideVenue(strategy);
}

Strategy* WarTheatre::getStrategy() {
	// TODO - implement WarTheatre::sendScout
	//throw "Not yet implemented";
    return strategy;
}

char decideVenue(Strategy*)
{
   //TODO - implement decideVenue this way:
   if(strategy->getStrategyName() == "Battlefield") return  'a';
   if (strategy->getStrategyName() == "Siege") return 'b';
   if (strategy->getStrategyName() == "Ambush") return 'c';
   if (strategy->getStrategyName() == "Assassination") return 'd';
}

WarTheatre::WarTheatre(Strategy myStrat) {
	// TODO - implement WarTheatre::WarTheatre
	throw "Not yet implemented";
}
=======

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

>>>>>>> Stashed changes
