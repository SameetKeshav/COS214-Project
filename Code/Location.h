#ifndef LOCATION_H
#define LOCATION_H

class Location : WarTheatre {


public:
	Location();

	Strategy* getStrategy();

	void createVenue(string venue);

	void ~Location();
};

#endif
