#ifndef KINGDOM_H
#define KINGDOM_H
using namespace std;
#include <vector>
#include "Bannerman.h"
#include "Economy.h"

class Kingdom {

private:
	vector<Bannerman*> bannermen;
	Economy* economy;

public:
	Kingdom(Economy* economy);
	void remove(Bannerman* b);
	void add(Bannerman* b);
	vector<Bannerman*> getKingdom();
	int getSize(); //added
	Bannerman* getAlly(string n); //added
	virtual ~Kingdom();
};

#endif
