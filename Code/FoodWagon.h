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
    ArmySupplies* supp=NULL;
///@brief destructor for the Food Wagon class to delete and free the supply variable.
///@author Ronin Brookes 19069686
    ~FoodWagon();
};

#endif
