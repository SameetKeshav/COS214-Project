#ifndef UNSTABLESTATE_H
#define UNSTABLESTATE_H

class UnstableState : State {


public:
	UnstableState(Economy* context, MasterOfCoin* m);

	void decreaseCurrency();

	void increaseCurrency();
};

#endif
