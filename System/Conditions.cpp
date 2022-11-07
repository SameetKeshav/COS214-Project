#include "Conditions.h"
#include <ctime>

void Conditions::sendScout() {
	// TODO - implement Conditions::sendScout
	//throw "Not yet implemented";
    
}

Conditions::Conditions(WarTheatre* myVenue_) {
    myVenue = myVenue_;
}


Conditions:: ~Conditions()
{
	delete myVenue;
}
