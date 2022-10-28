#ifndef MEDICALFAC_H
#define MEDICALFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "MedicalSupp.h"
class MedicalFac : Factory {


public:
    ArmySupplies* make() ;
};

#endif
