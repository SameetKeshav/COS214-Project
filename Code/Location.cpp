#include "Location.h"

Location::Location() {
	// TODO - implement Location::Location
	//throw "Not yet implemented";
    if(venue == 'a') location =  "Open war field";
    if(venue == 'b') location =  "Fortress";
    if(venue == 'c') location =  "Campsite";
    if(venue == 'd') location =  "Castle";

    difficulty = 1;
    createVenue();
}

void Location::sendScout() {
	// TODO - implement Location::sendScout
	//throw "Not yet implemented";
    //update conditions and all
    //the function jules will call
    cout << "waiting for conditions to update..." << endl;
    createVenue();
//    strategy->getEnemyBannerman()->
//    strategy->getMyBannerman()->
}

void Location::createVenue() {
	// TODO - implement Location::createVenue
	//throw "Not yet implemented";
   Conditions myDecorator = new Conditions(this); //check the pointer passed
   //then decorate
   myDecorator.sendScout();
}

Location::~Location() {
    delete strategy;
    cout << venue  << " destroyed.";
}
