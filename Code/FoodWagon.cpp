#include "FoodWagon.h"

SupplyWagon* FoodWagon::clone() {

    supp = new FoodSupp();
    SupplyWagon* wagon = new FoodWagon();
    wagon->setSup(supp);
    return wagon;

}

ArmySupplies* FoodWagon::getSupplies() {
    return supp;
}

FoodWagon::~FoodWagon() {
    delete supp;
}
