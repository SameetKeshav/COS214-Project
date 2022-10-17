#ifndef HEALTHYSTATE_H
#define HEALTHYSTATE_H

class HealthyState : State {


public:
	HealthyState(Economy* context, MasterOfCoin* m);

	void decreaseCurrency();

	void increaseCurrency();
};

#endif
