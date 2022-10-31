#ifndef HEALTHYSTATE_H
#define HEALTHYSTATE_H
#include "State.h"
#include "Economy.h"
#include "UnstableState.h"
#include <iostream>
using namespace std;
class HealthyState :public State {


public:
	HealthyState();
	void setContext(Economy* context);

	void decreaseCurrency();

	virtual State* getDemotionState();
	string getState();
};

#endif
