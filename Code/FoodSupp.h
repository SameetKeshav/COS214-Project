#ifndef FOODSUPP_H
#define FOODSUPP_H
#include "ArmySupplies.h"

class FoodSupp : public ArmySupplies {

public:
    ///@brief getAmount() is used to return the amount of Food supplies.
///@return an integer representation of the amount of Food supplies.
///@author Ronin Brookes 19069686
    int getAmount();
};

#endif

