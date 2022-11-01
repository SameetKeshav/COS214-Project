#ifndef STATE_H
#define STATE_H
#include "Economy.h"
class Economy;
using namespace std;

/** @brief An Abstract state class.
    A class that provides an interface to the alternative concrete states for Economy of Kingdom.
    @author Morgan Bentley
    @date October 2022
    */
class State {

protected:
	/** Economy pointer of player's Kingdom**/
	Economy* context;

public:
	/** @brief Default constructor.
	*/
	State();
	/** @todo sets context variable.
	 * @param context - Economy pointer to player's Economy object.**/
	virtual void setContext(Economy* context);
	/** @todo Abstract method.**/
	virtual void decreaseCurrency()=0;
	/** @todo gets lower level state of economy with null being returned if no lower state is possible
	 * @return concrete State of Economy **/
	virtual State* getDemotionState();
	/** @todo destructor. deallocates context**/
	virtual ~State();
};

#endif
