#include "WarTheatre.h"

WarTheatre::WarTheatre(string* myStrat) {
    // TODO - implement WarTheatre::WarTheatre
    //throw "Not yet implemented";
    strategy = myStrat;
    venue = decideVenue(myStrat);
}

WarTheatre::WarTheatre ()
{

}

//Strategy* WarTheatre::getStrategy() {
//	// TODO - implement WarTheatre::sendScout
//	//throw "Not yet implemented";
//    return strategy;
//}

char WarTheatre::decideVenue(string* strategy)
{
    //TODO - implement decideVenue this way:
//   if(strategy->getStrategyName() == "Battlefield") return  'a';
//   if (strategy->getStrategyName() == "Siege") return 'b';
//   if (strategy->getStrategyName() == "Ambush") return 'c';
//   if (strategy->getStrategyName() == "Assassination") return 'd';
    return 'a';
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
//WarTheatre::WarTheatre(Strategy myStrat) {
//	// TODO - implement WarTheatre::WarTheatre
//	throw "Not yet implemented";
//}
