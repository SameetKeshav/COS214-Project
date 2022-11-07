#ifndef FAILEDSTATE_H
#define FAILEDSTATE_H
#include "State.h"
#include "Economy.h"

/** @brief A concrete state class.
    A class that is one of the alternative concrete states for Economy of Kingdom.
    @author Morgan Bentley
    @date October 2022
    */
class FailedState :public State {


public:
	/** @brief Default constructor. initializes context to null.
	*/
	FailedState();
	/** @brief prints out string stating that current State is FailedState**/
	void decreaseCurrency();
	/** @brief tells what the State of the Economy is.
	* @return returns a string that says in text what the State is.**/
	string getState();
};

#endif
