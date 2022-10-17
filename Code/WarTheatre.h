#ifndef WARTHEATRE_H
#define WARTHEATRE_H

class WarTheatre {

private:
	Strategy* strategy;
	string venue;
	int difficulity;
	int attribute;

public:
	WarTheatre();

	virtual Strategy* getStrategy() = 0;

	void sendScout();
};

#endif
