#ifndef STATE_H
#define STATE_H

class State {

private:
	MasterOfCoin m;
	Economy* context;

public:
	void decreaseCurrency();

	void increaseCurrency();
};

#endif
