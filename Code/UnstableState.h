#ifndef UNSTABLESTATE_H
#define UNSTABLESTATE_H
#include "State.h"
#include "Economy.h"
#include "FailedState.h"

<<<<<<< Updated upstream
=======

/** @brief A concrete state class.
    A class that is one of the alternative concrete states for Economy of Kingdom.
    @author Morgan Bentley
    @date October 2022
    */
>>>>>>> Stashed changes
class UnstableState :public State {


public:
	UnstableState();
	void setContext(Economy* context);

	void decreaseCurrency();
<<<<<<< Updated upstream

=======
	/** @todo gets lower level state of economy
	 * @return concrete State of Economy **/
	string getState();
>>>>>>> Stashed changes
	State* getDemotionState();

	string getState();
};

#endif
