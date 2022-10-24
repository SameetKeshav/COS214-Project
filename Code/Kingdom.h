#ifndef KINGDOM_H
#define KINGDOM_H
using namespace std;
#include <vector>
#include "Bannerman.h"

class Kingdom {

private:
	vector<Bannerman*> bannerman;

public:
	Kingdom();
	void remove(Bannerman* b);
	void add(Bannerman* b);
};

#endif
