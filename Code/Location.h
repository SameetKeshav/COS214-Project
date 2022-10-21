#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>

using namespace std;

class Location : public WarTheatre {


public:
	Location(string);

	void sendScout();

	void createVenue(string venue);

	void ~Location();
};

#endif
