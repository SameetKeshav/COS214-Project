#ifndef MASTEROFCOIN_H
#define MASTEROFCOIN_H

class MasterOfCoin : Treasury {

private:
	Economy* economy;
	Bannermanb* bannerman;
	Factory* factory;
	Strategy* strategy;

public:
	void notify(WarIndicators sender);

	void decreaseCurrency();

	void manufacture();
};

#endif
