#include "WeaponsFac.h"

ArmySupplies* WeaponsFac::make() {
    cout<<"Weaponry is being Manufactured"<<endl;
    ArmySupplies* supplies = new WeaponSupp();
    return supplies;
}
WeaponsFac::~WeaponsFac() {}
