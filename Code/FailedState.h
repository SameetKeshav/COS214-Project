#ifndef FAILEDSTATE_H
#define FAILEDSTATE_H
#include "State.h"
#include "Economy.h"

class FailedState :public State {


public:
	FailedState(Economy* context);
	void decreaseCurrency();
};

#endif
