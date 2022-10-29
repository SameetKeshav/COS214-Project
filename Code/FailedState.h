#ifndef FAILEDSTATE_H
#define FAILEDSTATE_H
#include "State.h"
#include "Economy.h"
using namespace std;
#include <iostream>
class FailedState :public State {


public:
	FailedState();
	void setContext(Economy* context);
	void decreaseCurrency();
	string getState();
};

#endif
