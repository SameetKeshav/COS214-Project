#ifndef HISTORY_H
#define HISTORY_H
#include "Bannerman.h"
#include <iostream>
using namespace std;
class History {

private:
	Bannerman* bannerman;

public:
	History(Bannerman* b);

	Bannerman* getBannerman();

	~History(){delete bannerman;};
};

#endif
