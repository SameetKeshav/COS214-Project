#ifndef WEAPONWAGON_H
#define WEAPONWAGON_H
#include "Factory.h"
#include "SupplyWagon.h"
#include "ArmySupplies.h"
#include "WeaponSupp.h"

class WeaponWagon : SupplyWagon {

public:
	ArmySupplies* supp;

~WeaponWagon(){
    delete supp;
}
};

#endif
