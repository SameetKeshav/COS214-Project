#ifndef ECONOMY_H
#define ECONOMY_H
#include "WarIndicators.h"

#include <iostream>
#include "State.h"

using namespace std;

class State;
//circular dependency with state
class Economy :public WarIndicators {
	
private:
	/**state of economy**/
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
