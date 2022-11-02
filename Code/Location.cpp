#include "Location.h"

Location::Location() {
    // TODO - implement Location::Location
    //throw "Not yet implemented";
    if(getVenue() == 'a') setLocation("Open war field")  ;
    if(getVenue() == 'b') setLocation("Fortress")  ;
    if(getVenue() == 'c') setLocation("Campsite")  ;
    if(getVenue() == 'd') setLocation("Castle")   ;

    setDifficulty(1);
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
    //delete strategy;
    // cout << venue  << " destroyed.";
}
