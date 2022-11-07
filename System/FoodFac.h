#ifndef FOODFAC_H
#define FOODFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "FoodSupp.h"

///@brief Factory class to serve as a concrete creator class used to create Food supplies
///@author Ronin Brookes 19069686
class FoodFac : public Factory {


public:
///@brief make() is the factory Method called in operation() to make the Food supplies.
///@return ArmySupplies pointer to the newly created Food supplies.
    ArmySupplies* make();
///@brief destructor for the FoodFac class to delete and free the supply variable.
    ~FoodFac();
};

#endif
