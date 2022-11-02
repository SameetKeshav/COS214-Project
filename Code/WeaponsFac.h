#ifndef WEAPONSFAC_H
#define WEAPONSFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "WeaponSupp.h"

class WeaponsFac : public Factory {

public:
    ArmySupplies* make();
    ~WeaponsFac();
};

#endif