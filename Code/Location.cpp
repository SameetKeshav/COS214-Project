#include "Location.h"

Location::Location() {
    if(getVenue() == 'a') setLocation("Open war field")  ;
    if(getVenue() == 'b') setLocation("Fortress")  ;
    if(getVenue() == 'c') setLocation("Campsite")  ;
    if(getVenue() == 'd') setLocation("Castle") ;
}

void Location::sendScout() {
    cout << "Gathering weather report..." << endl;
}



