#ifndef FOODWAGON_H
#define FOODWAGON_H
#include "Factory.h"
#include "SupplyWagon.h"
#include "ArmySupplies.h"
#include "FoodSupp.h"

class FoodWagon : public SupplyWagon {

public:
    void setSup(ArmySupplies* sup);
    SupplyWagon* clone();
    ArmySupplies* getSupplies();
    ArmySupplies* supp;
    ~FoodWagon();
};

#endif
