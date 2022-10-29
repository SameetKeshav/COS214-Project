#include "WarTheatre.h"

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
