#ifndef WEAPONWAGON_H
#define WEAPONWAGON_H
#include "Factory.h"
#include "SupplyWagon.h"
#include "ArmySupplies.h"
#include "WeaponSupp.h"

class WeaponWagon : public SupplyWagon {

public:

    void setSup(ArmySupplies* sup);
    SupplyWagon* clone();
    ArmySupplies* getSupplies();
    ArmySupplies* supp;
    ///@brief destructor for the Weapon Wagon class to delete and free the supply variable.
///@author Ronin Brookes 19069686
    ~WeaponWagon();
};

#endif
