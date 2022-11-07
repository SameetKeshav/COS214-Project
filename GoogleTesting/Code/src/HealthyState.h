#ifndef HEALTHYSTATE_H
#define HEALTHYSTATE_H
#include "State.h"
#include "Economy.h"
#include "UnstableState.h"

/** @brief A concrete state class.
    A class that is one of the alternative concrete states for Economy of Kingdom.
    @author Morgan Bentley
    @date October 2022
    */
class HealthyState :public State {


public:
	/** @brief Default constructor. initializes context to null.
	*/
	HealthyState();
	/** @todo decreases Economy currency and then checks if the conditions are sufficient for
	 * the economy to downgrade to a lower state**/
	void decreaseCurrency();
	/** @todo gets lower level state of economy
	 * @return concrete State of Economy **/
	virtual State* getDemotionState();
	/// @brief tells what the state of the economy is
	/// @return returns a string that says in text what the state is
	string getState();
};

#endif
