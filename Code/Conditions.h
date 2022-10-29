#ifndef CONDITIONS_H
#define CONDITIONS_H
#include <cstdlib>

class Conditions : public  WarTheatre {

public:
	WarTheatre* myVenue;

	void sendScout();

	Conditions(WarTheatre* myVenue);
};

#endif
