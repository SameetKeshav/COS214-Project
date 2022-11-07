#ifndef WEAPONSFAC_H
#define WEAPONSFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "WeaponSupp.h"

///@brief Factory class to serve as a concrete creator class used to create Weapons supplies
///@author Ronin Brookes 19069686
class WeaponsFac : public Factory {

public:

///@brief make() is the factory Method called in operation() to make the Weapon supplies.
///@return ArmySupplies pointer to the newly created Weapon supplies.
    ArmySupplies* make();

///@brief destructor for the WeaponsFac class to delete and free the supply variable.
    ~WeaponsFac();
};

#endif