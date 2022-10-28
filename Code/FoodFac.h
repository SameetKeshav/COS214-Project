#ifndef FOODFAC_H
#define FOODFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "FoodSupp.h"
class FoodFac : Factory {


public:
    /// @brief Food Factory makes Food supplies.
    /// @return returns the supplies the Food Factory just manufactured
    /// @author Ronin Brookes 19069686
	 ArmySupplies* make();
};

#endif
