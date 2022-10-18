#ifndef MASTEROFCOIN_H
#define MASTEROFCOIN_H

#include "Economy.h"
#include "Bannerman.h"
#include "Factory.h"
#include "Strategy.h"
#include "Treasury.h"

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
