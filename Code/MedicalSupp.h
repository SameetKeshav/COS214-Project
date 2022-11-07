#ifndef MEDICALSUPP_H
#define MEDICALSUPP_H
#include "ArmySupplies.h"

class MedicalSupp : public ArmySupplies {


public:
///@brief getAmount() is used to return the amount of Medical supplies.
///@return an integer representation of the amount of Medical supplies.
///@author Ronin Brookes 19069686
    int getAmount();
};

#endif
