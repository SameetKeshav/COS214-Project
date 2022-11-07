#ifndef FOODSUPP_H
#define FOODSUPP_H
#include "ArmySupplies.h"

///@brief Concrete Product Class containing the information on the Food supplies.
///@author Ronin Brookes 19069686
class FoodSupp : public ArmySupplies {

public:
    ///@brief getAmount() is used to return the amount of Food supplies.
///@return an integer representation of the amount of Food supplies.
    int getAmount();
};

#endif

