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
	/** @brief decreases Economy currency and then checks if the conditions are sufficient for
	 * the economy to downgrade to a lower state**/
	void decreaseCurrency();
	/** @brief gets lower level state of economy
	 * @return concrete State of Economy **/
	virtual State* getDemotionState();
	/** @brief tells what the State of the Economy is.
	* @return returns a string that says in text what the State is.**/
	string getState();
};

#endif
