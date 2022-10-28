#include "MedicalWagon.h"

SupplyWagon* MedicalWagon::clone() {

    supp = new MedicalSupp();
    SupplyWagon* wagon = new MedicalWagon();
    wagon->setSup(supp);
    return wagon;

}


ArmySupplies* MedicalWagon::getSupplies() {
    return supp;
}

MedicalWagon::~MedicalWagon() {
    delete supp;
}