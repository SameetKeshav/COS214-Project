#ifndef FOODFAC_H
#define FOODFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "FoodSupp.h"
class FoodFac : public Factory {


public:

    ArmySupplies* make();
    ~FoodFac();
};

#endif
