#ifndef ECONOMY_H
#define ECONOMY_H
#include "WarIndicators.h"

#include <iostream>
#include "State.h"

using namespace std;

class State;
/** @brief keeps all variables relating to the state of Economy, is context of States.
    A class that provides an alternative strategy for how Bannerman will fight enemyBannerman.
    @author Morgan Bentley
    @date October 2022
    */
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
	/** @brief tells State to invoke its getDemotionState method.**/
	void SetState();
	/** @brief returns State pointer.
	 * @return State of Economy. **/
	State* getState();
	/** @brief tells State to invoke its decreaseCurrency method and then
	 * it invokes notify method of MasterofCoin passing itself as the argument.**/
	void decreaseCurrency();
	/** @brief returns currency.
	 * @return currency of Economy. **/
	int getCurrency();
	/** @brief reduces currency by the passed in amount.
	 * @param i - Expense of manufacturing required Supplies.**/
	void removeCurrency(int i);
	/** @brief destructor. deallocates State.**/
	virtual ~Economy();
};
#endif
