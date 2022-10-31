#ifndef FOODWAGON_H
#define FOODWAGON_H
#include "Factory.h"
#include "SupplyWagon.h"
#include "ArmySupplies.h"
#include "FoodSupp.h"

class FoodWagon : SupplyWagon {

public:
    ArmySupplies* supp;
    ~FoodWagon(){
        delete supp;
    }
};

#endif
