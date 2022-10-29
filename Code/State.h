#ifndef STATE_H
#define STATE_H
class Economy;

class State {

protected:
	Economy* context;

public:
	State();
	void setContext(Economy* context);
	virtual void decreaseCurrency()=0;
	virtual State* getDemotionState();
	~State();
};

#endif
