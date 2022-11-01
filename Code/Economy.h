#ifndef ECONOMY_H
#define ECONOMY_H
//#include "WarIndicators.h"
using namespace std;
#include <iostream>
#include "State.h"
class State;
//circular dependency with state
class Economy {//:public WarIndicators {
	
private:
	/**state of economy**/
	State* state;
	int currency;

public:
	Economy(State* state,int currency);

	void SetState();

	void decreaseCurrency();

	int getCurrency();

	void removeCurrency(int i);

	virtual ~Economy();
};
#endif
