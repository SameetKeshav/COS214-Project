#ifndef CONDITIONS_H
#define CONDITIONS_H

class Conditions : WarTheatre {

public:
	WarTheatre* myVenue;

	Strategy* getStrategy();

	Conditions(WarTheatre* myVenue);
};

#endif
