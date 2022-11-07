#include "WeaponsFac.h"

ArmySupplies* WeaponsFac::make() {
    ArmySupplies* supplies = new WeaponSupp();
    return supplies;
}
WeaponsFac::~WeaponsFac() {}
