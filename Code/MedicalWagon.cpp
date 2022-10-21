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
