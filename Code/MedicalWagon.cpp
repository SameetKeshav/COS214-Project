#include "MedicalWagon.h"

SupplyWagon* MedicalWagon::clone() {

    supp = new MedicalSupp();
    SupplyWagon* wagon = new MedicalWagon();
    wagon->setSup(supp);
    return wagon;

}
void MedicalWagon::setSup(ArmySupplies* sup){
    supp=sup;
}

ArmySupplies* MedicalWagon::getSupplies() {
    return supp;
}

MedicalWagon::~MedicalWagon() {
    //cout<<supp<<endl;
    if(supp!=NULL){
        delete supp;
        supp=NULL;
        //cout<<"Deleted Medical Wagon"<<endl;
    }
}