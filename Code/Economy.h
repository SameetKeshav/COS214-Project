#ifndef ECONOMY_H
#define ECONOMY_H

class Economy : WarIndicators {

private:
	State* state;
	int currency;

public:
	Economy(State* state, int currency);

	void decreaseCurrency();

	void increaseCurrency();
};

#endif
