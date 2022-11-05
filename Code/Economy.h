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
	/**Monetary reserves of the Kingdom**/
	int currency;

public:
	/** @brief Constructor. initializes State pointer and currency.
	 * @param state - State of Economy.
	 * @param currency - Monetary reserves of the Kingdom.
	*/
	Economy(State* state,int currency);
	/** @todo tells State to invoke its getDemotionState method.**/
	void SetState();
	/** @todo returns State pointer.
	 * @return State of Economy. **/
	State* getState();
	/** @todo tells State to invoke its decreaseCurrency method and then
	 * it invokes notify method of MasterofCoin passing itself as the argument.**/
	void decreaseCurrency();
	/** @todo returns currency.
	 * @return currency of Economy. **/
	int getCurrency();
	/** @todo reduces currency by the passed in amount.
	 * @param i - Expense of manufacturing required Supplies.**/
	void removeCurrency(int i);
	/** @todo destructor. deallocates State.**/
	virtual ~Economy();
};
#endif
