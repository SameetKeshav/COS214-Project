#ifndef UNSTABLESTATE_H
#define UNSTABLESTATE_H
#include "State.h"
#include "Economy.h"
#include "FailedState.h"

/** @brief A concrete state class.
    A class that is one of the alternative concrete states for Economy of Kingdom.
    @author Morgan Bentley
    @date October 2022
    */
class UnstableState :public State {


public:
	/** @brief Default constructor. initializes context to null.
	*/
	UnstableState();
	/** @todo decreases Economy currency and then checks if the conditions are sufficient for
	 * the economy to downgrade to a lower state**/
	void decreaseCurrency();
	/** @todo gets lower level state of economy
	 * @return concrete State of Economy **/
	State* getDemotionState();
	/** @todo tells what the State of the Economy is.
	* @return returns a string that says in text what the State is.**/
	string getState();
};

#endif
