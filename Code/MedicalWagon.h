#ifndef MEDICALWAGON_H
#define MEDICALWAGON_H
#include "Factory.h"
#include "SupplyWagon.h"
#include "ArmySupplies.h"
#include "MedicalSupp.h"
class MedicalWagon : public SupplyWagon {

public:
    void setSup(ArmySupplies* sup);
    SupplyWagon* clone();
    ArmySupplies* getSupplies();
    ArmySupplies* supp;
    ~MedicalWagon();
};

#endif
