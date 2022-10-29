#include "Location.h"

Location::Location(String venue) {
	// TODO - implement Location::Location
	//throw "Not yet implemented";
    cout << "Bannermen arrived " << venue << "!";
}

void Location::sendScout() {
	// TODO - implement Location::sendScout
	throw "Not yet implemented";
    //update conditions and all
}

void Location::createVenue(string venue) {
	// TODO - implement Location::createVenue
	//throw "Not yet implemented";
   Conditions myDecorator = new Conditions(this); //check the pointer passed
   //then decorate
   myDecorator.sendScout();

}

Location::~Location() {
    cout << venue  << " destroyed.";
}
