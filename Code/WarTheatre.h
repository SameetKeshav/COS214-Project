#ifndef WARTHEATRE_H
#define WARTHEATRE_H

using namespace std;

class WarTheatre {

private:
	Strategy* strategy;
	string venue;
	int difficulty;
	int attribute;

public:
	WarTheatre(Strategy myStrat);

	virtual Strategy* getStrategy() = 0; //may need to make sendScout the virtual one instead

	void sendScout();

    string decideVenue(Strategy*);
};

#endif
