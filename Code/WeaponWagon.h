#ifndef WEAPONWAGON_H
#define WEAPONWAGON_H
#include "Factory.h"
#include "SupplyWagon.h"
#include "ArmySupplies.h"
#include "WeaponSupp.h"

class WeaponWagon : public SupplyWagon {

public:

    /// @brief initialize the supp variable for the WeaponWagon.
    /// @param sup is used to set the supp variable,
    /// @author Ronin Brookes 19069686
    void setSup(ArmySupplies* sup);
    /// @brief Clone the Weapon Supply Wagon object.
    /// @return the new Weapon Supply Wagon clone.
    /// @author Ronin Brookes 19069686
    SupplyWagon* clone();
    /// @brief Return the supp variable for the Weapon Wagon.
    /// @return returns the supp variable. Returns the necessary supplies.
    /// @author Ronin Brookes 19069686
    ArmySupplies* getSupplies();
    /**pointer to the supplies in the Weapon wagon*/
    ArmySupplies* supp;
    ///@brief destructor for the Weapon Wagon class to delete and free the supply variable.
///@author Ronin Brookes 19069686
    ~WeaponWagon();
};

#endif
