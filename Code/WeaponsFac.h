#ifndef WEAPONSFAC_H
#define WEAPONSFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "WeaponSupp.h"

class WeaponsFac : public Factory {

public:

///@brief make() is the factory Method called in operation() to make the Weapon supplies.
///@return ArmySupplies pointer to the newly created Weapon supplies.
///@author Ronin Brookes 19069686
    ArmySupplies* make();

///@brief destructor for the WeaponsFac class to delete and free the supply variable.
///@author Ronin Brookes 19069686
    ~WeaponsFac();
};

#endif