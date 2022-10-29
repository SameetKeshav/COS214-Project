#ifndef ECONOMY_H
#define ECONOMY_H
#include "WarIndicators.h"
#include "State.h"
//circular dependency with state
class Economy :public WarIndicators {

private:
	State* state;
	int currency;

public:
	Economy(State* state,int currency);

	void SetState();

	State* getState();

	void decreaseCurrency();

	int getCurrency();

	void removeCurrency(int i);

	virtual ~Economy();
};
#endif
