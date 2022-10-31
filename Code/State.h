#ifndef STATE_H
#define STATE_H
class Economy;
using namespace std;
#include <iostream>

class State {

protected:
	Economy* context;

public:
	State();
	void setContext(Economy* context);
	virtual void decreaseCurrency()=0;
	virtual State* getDemotionState();
<<<<<<< Updated upstream
	~State();
	virtual string getState()=0;
=======
	/** @todo destructor. deallocates context**/
	virtual string getState()=0;
	virtual ~State();
>>>>>>> Stashed changes
};

#endif
