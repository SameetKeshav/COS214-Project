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
	/** @brief sets context variable.
	 * @param context - Economy pointer to player's Economy object.**/
	virtual void setContext(Economy* context);
	/** @brief Abstract method.**/
	virtual void decreaseCurrency()=0;
	/** @brief gets lower level state of Economy with null being returned if no lower State is possible
	 * @return concrete State of Economy **/
	virtual State* getDemotionState();
	/** @brief destructor. deallocates context**/
	virtual ~State();
	/** @brief Abstract method.
	 * @return name of State as a string.**/
	virtual string getState()=0;
};

#endif
