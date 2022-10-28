#ifndef FOODFAC_H
#define FOODFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "FoodSupp.h"
class FoodFac : Factory {


public:
	 ArmySupplies* make();
};

#endif
