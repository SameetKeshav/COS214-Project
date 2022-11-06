#ifndef MEDICALFAC_H
#define MEDICALFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "MedicalSupp.h"
class MedicalFac : public Factory {

public:
///@brief make() is the factory Method called in operation() to make the Medical supplies.
///@return ArmySupplies pointer to the newly created Medical supplies.
///@author Ronin Brookes 19069686
    ArmySupplies* make();
///@brief destructor for the MedicalFac class to delete and free the supply variable.
///@author Ronin Brookes 19069686
    ~MedicalFac();
};

#endif

