#ifndef MEDICALFAC_H
#define MEDICALFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "MedicalSupp.h"
class MedicalFac : Factory {


public:
    /// @brief Medical Factory makes Medical supplies.
    /// @return returns the supplies the Medical Factory just manufactured
    /// @author Ronin Brookes 19069686
    ArmySupplies* make() ;
};

#endif
