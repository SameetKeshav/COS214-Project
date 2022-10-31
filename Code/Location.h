#ifndef LOCATION_H
#define LOCATION_H
<<<<<<< Updated upstream
=======
#include <iostream>
#include "WarTheatre.h"
//#include "Conditions.h" causes circular dependency?
>>>>>>> Stashed changes

class Location : WarTheatre {


public:
	Location();

	Strategy* getStrategy();

	void createVenue(string venue);

<<<<<<< Updated upstream
	void ~Location();
=======
    /** @brief fress memory used in the pattern*/
	~Location();
>>>>>>> Stashed changes
};

#endif
