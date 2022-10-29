#include "Conditions.h"

void Conditions::sendScout() {
	// TODO - implement Conditions::sendScout
	throw "Not yet implemented";
    //ai ga ke tsebe gore ko Khoda eng moo - come back later.
}

Conditions::Conditions(WarTheatre* myVenue) {
	// TODO - implement Conditions::Conditions
	throw "Not yet implemented";
    cout << "Approaching war venue..." ;
    //create weather and topology objects here.
    //generate random value between -10 and 50
    srand(time(0));
    int ranVal = rand() % 60 + 1; //between 1 and 60
    ranVal -= 10; //minus 10 to make it between -10 and 50
    Weather myW = new Weather(ranVal);
    //use setters for weather (done) and topology here

}
