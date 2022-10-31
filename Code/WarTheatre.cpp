#include "WarTheatre.h"

WarTheatre::WarTheatre(Strategy myStrat) {
	// TODO - implement WarTheatre::WarTheatre
	//throw "Not yet implemented";
    strategy = myStrat;
    venue = decideVenue(strategy);
}

void WarTheatre::sendScout() {
	// TODO - implement WarTheatre::sendScout
	throw "Not yet implemented";
}

string decideVenue(Strategy*)
{
   //TODO - implement decideVenue this way:
        //if strategy.getName == xx, then return yy
        //do for all available strategies.
}
