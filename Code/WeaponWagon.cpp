#include "WeaponWagon.h"

SupplyWagon* WeaponWagon::clone() {

     supp = new WeaponSupp();
     SupplyWagon* wagon = new WeaponWagon();
     wagon->setSup(supp);
    return wagon;


}
void WeaponWagon::setSup(ArmySupplies* sup){
    supp=sup;
}