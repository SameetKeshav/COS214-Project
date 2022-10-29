#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>

using namespace std;

class Location : public WarTheatre {


public:
	Location();

	void sendScout();

	void createVenue();

	void ~Location();
};

#endif
