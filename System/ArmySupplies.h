#ifndef ARMYSUPPLIES_H
#define ARMYSUPPLIES_H

///@brief Abstract Class containing the information on the supplies.
///@author Ronin Brookes 19069686
class ArmySupplies {

public:

///@brief getAmount() is used to return the amount of supplies.
///@return an integer representation of the amount of supplies.
    virtual int getAmount() = 0;
};

#endif
