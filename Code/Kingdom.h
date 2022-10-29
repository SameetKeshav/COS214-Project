#ifndef KINGDOM_H
#define KINGDOM_H
using namespace std;
#include <vector>
#include "Bannerman.h"
#include "Economy.h"

class Kingdom {

private:
	vector<Bannerman*> bannerman;
	Economy* economy;

public:
	Kingdom(Economy* economy,vector<Bannerman*> bannerman);
	void remove(Bannerman* b);
	void add(Bannerman* b);
	virtual ~Kingdom();
};

#endif
