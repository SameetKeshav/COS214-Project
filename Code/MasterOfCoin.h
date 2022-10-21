#ifndef MASTEROFCOIN_H
#define MASTEROFCOIN_H

#include "Economy.h"
#include "Raven.h"
#include "Factory.h"
#include "Strategy.h"
#include "Treasury.h"

class MasterOfCoin : Treasury {

private:
	Economy* economy;
	Raven* observer;
	Strategy* strategy;

public:
    MasterOfCoin(Economy* economy, Raven* observer, Factory* factory, Strategy strategy);
	void notify(WarIndicators sender);
	void decreaseCurrency();
	void manufacture();
    ~MasterOfCoin();
};

#endif
