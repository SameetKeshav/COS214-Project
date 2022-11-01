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

ArmySupplies* WeaponWagon::getSupplies() {
    return supp;
}

WeaponWagon::~WeaponWagon() {
    //cout<<supp<<endl;
    if(supp!=NULL){
        delete supp;
        supp=NULL;
       // cout<<"Deleted Weapon Wagon"<<endl;
    }
}
