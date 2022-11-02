#include "Conditions.h"

void Conditions::sendScout() {
	// TODO - implement Conditions::sendScout
	//throw "Not yet implemented";
<<<<<<< Updated upstream

    //create weather here.
    //generate random value between -10 and 50
    srand(time(0));
    int ranVal = rand() % 60 + 1; //between 1 and 60
    ranVal -= 10; //minus 10 to make it between -10 and 50
    Weather myW = new Weather(ranVal);

    //create Topology object here
    Topology myTop = new Topology(venue);
    myTop.sendScout();

    //cout << "location decorated" << endl;
}

Conditions::Conditions(WarTheatre* myVenue) {
	// TODO - implement Conditions::Conditions
	throw "Not yet implemented";
    this->myVenue = myVenue;

   // myVenue->sendScout(); //what in the name is this - causes circulation!
   // cout << "Approaching war venue..." ;
=======
    
}

Conditions::Conditions(WarTheatre* myVenue_) {
    myVenue = myVenue_;
}

>>>>>>> Stashed changes

Conditions:: ~Conditions()
{
	delete myVenue;
}
