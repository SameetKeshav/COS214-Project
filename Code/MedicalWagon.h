#ifndef MEDICALWAGON_H
#define MEDICALWAGON_H
#include "Factory.h"
#include "SupplyWagon.h"
#include "ArmySupplies.h"
#include "MedicalSupp.h"
class MedicalWagon : SupplyWagon {

public:
    ArmySupplies* supp;
    ~MedicalWagon(){
        delete supp;
    }
};

#endif
