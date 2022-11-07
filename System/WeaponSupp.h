#ifndef WEAPONSUPP_H
#define WEAPONSUPP_H
#include "ArmySupplies.h"

///@brief Concrete Product Class containing the information on the Weapon supplies.
///@author Ronin Brookes 19069686
class WeaponSupp : public ArmySupplies {

public:
///@brief getAmount() is used to return the amount of Weapon supplies.
///@return an integer representation of the amount of Weapon supplies.
    int getAmount();
};

#endif
