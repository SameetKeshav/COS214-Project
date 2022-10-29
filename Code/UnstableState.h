#ifndef UNSTABLESTATE_H
#define UNSTABLESTATE_H
#include "State.h"
#include "Economy.h"
#include "FailedState.h"

class UnstableState :public State {


public:
	UnstableState();
	void setContext(Economy* context);

	void decreaseCurrency();

	State* getDemotionState();

	string getState();
};

#endif
