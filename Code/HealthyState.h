#ifndef HEALTHYSTATE_H
#define HEALTHYSTATE_H
#include "State.h"
#include "Economy.h"
#include "UnstableState.h"

class HealthyState :public State {


public:
	HealthyState(Economy* context);

	void decreaseCurrency();

	virtual State* getDemotionState();
};

#endif
