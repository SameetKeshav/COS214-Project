#ifndef WEAPONSUPP_H
#define WEAPONSUPP_H
#include "ArmySupplies.h"

class WeaponSupp : public ArmySupplies {

public:
///@brief getAmount() is used to return the amount of Weapon supplies.
///@return an integer representation of the amount of Weapon supplies.
///@author Ronin Brookes 19069686
    int getAmount();
};

#endif
