#ifndef HISTORY_H
#define HISTORY_H
#include "Bannerman.h"
#include <iostream>
using namespace std;
class History { //memento

private:
	Bannerman* bannerman;

public:
	History(Bannerman* b);

	Bannerman* getBannerman();

	string getName();

	~History(){delete bannerman;};
};

#endif
