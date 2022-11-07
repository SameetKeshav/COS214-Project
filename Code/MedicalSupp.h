#ifndef MEDICALSUPP_H
#define MEDICALSUPP_H
#include "ArmySupplies.h"

///@brief Concrete Product Class containing the information on the Medical supplies.
///@author Ronin Brookes 19069686
class MedicalSupp : public ArmySupplies {


public:
///@brief getAmount() is used to return the amount of Medical supplies.
///@return an integer representation of the amount of Medical supplies.
    int getAmount();
};

#endif
