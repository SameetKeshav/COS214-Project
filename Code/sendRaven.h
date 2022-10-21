#ifndef SENDRAVEN_H
#define SENDRAVEN_H

#include "SupplyWagon.h"
#include "Commander.h"
#include "MasterOfCoin.h"
#include "Raven.h"

class sendRaven : Raven {

private:
	int numFood;
	int numMedical;
	int numWeapons;
	SupplyWagon** supplies;
	Bannerman* subject;
	MasterOfCoin m;

public:
    sendRaven(SupplyWagon** supplies, Bannerman* subject);
	void update();
	void checkSupplies();
};

#endif
