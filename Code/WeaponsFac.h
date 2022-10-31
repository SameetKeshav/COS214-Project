#ifndef WEAPONSFAC_H
#define WEAPONSFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "WeaponSupp.h"

class WeaponsFac : Factory {

public:
    ArmySupplies* make() {
        ArmySupplies supplies = new WeaponSupp();
        return supplies;
    }
};

#endif
