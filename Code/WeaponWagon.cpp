#include "WeaponWagon.h"

SupplyWagon* WeaponWagon::clone() {

     supp = new WeaponSupp();
     SupplyWagon* wagon = new WeaponWagon();
     wagon->setSup(supp);
    return wagon;


}

ArmySupplies* WeaponWagon::getSupplies() {
    return supp;
}

WeaponWagon::~WeaponWagon(){
    delete supp;
}
