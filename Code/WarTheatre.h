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

    Strategy* getStrategy(); //may need to make sendScout the virtual one instead

	virtual void sendScout() = 0;

    string decideVenue(Strategy*);
};

#endif
