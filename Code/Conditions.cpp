#include "Conditions.h"

void Conditions::sendScout() {
	// TODO - implement Conditions::sendScout
	//throw "Not yet implemented";

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

    myVenue->sendScout();
   // cout << "Approaching war venue..." ;

}
