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
    ///@brief destructor for the Medical Wagon class to delete and free the supply variable.
///@author Ronin Brookes 19069686
    ~MedicalWagon();
};

#endif
