#include "FoodWagon.h"

SupplyWagon* FoodWagon::clone() {

    supp = new FoodSupp();
    SupplyWagon* wagon = new FoodWagon();
    wagon->setSup(supp);
    return wagon;

}
void FoodWagon::setSup(ArmySupplies* sup){
    supp=sup;
}

ArmySupplies* FoodWagon::getSupplies() {
    return supp;
}
FoodWagon::~FoodWagon() {
    //cout<<supp<<endl;
    if(supp!=NULL){
        delete supp;
        supp=NULL;
        //cout<<"Deleted Food Wagon"<<endl;
    }
}