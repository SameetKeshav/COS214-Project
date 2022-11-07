#ifndef FOODWAGON_H
#define FOODWAGON_H
#include "Factory.h"
#include "SupplyWagon.h"
#include "ArmySupplies.h"
#include "FoodSupp.h"

///@brief Concrete Prototype class to serve as the wagon for Food
///@author Ronin Brookes 19069686
class FoodWagon : public SupplyWagon {

public:
    /// @brief initialize the supp variable for the FoodWagon.
    /// @param sup is used to set the supp variable,
    void setSup(ArmySupplies* sup);
    /// @brief Clone the Food Supply Wagon object.
    /// @return the new Food Supply Wagon clone.
    SupplyWagon* clone();
    /// @brief Return the supp variable for the Food Wagon.
    /// @return returns the supp variable. Returns the necessary supplies.
    ArmySupplies* getSupplies();
    /**pointer to the supplies in the Food wagon*/
    ArmySupplies* supp=NULL;
///@brief destructor for the Food Wagon class to delete and free the supply variable.
    ~FoodWagon();
};

#endif
