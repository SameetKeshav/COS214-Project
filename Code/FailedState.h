#ifndef FAILEDSTATE_H
#define FAILEDSTATE_H

class FailedState : State {


public:
	FailedState(Economy* context, MasterOfCoin* m);

	void decreaseCurrency();

	void increaseCurrency();
};

#endif
