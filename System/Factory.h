
#ifndef FACTORY_H
#define FACTORY_H
#include "WarIndicators.h"
#include "ArmySupplies.h"
#include <iostream>
using namespace std;
///@brief Factory class to serve as a base class for all factory concrete classes used to create supplies
///@author Ronin Brookes 19069686
class Factory : public WarIndicators {

protected:
///@brief make() is the factory Method called in operation() to make the new supplies.
///@return ArmySupplies pointer to the newly created supplies.
    virtual ArmySupplies* make() = 0;
public:
///@brief operation() is the template Method that calls make(), indirectly manufacturing the supplies.
    void operation();
///@brief getsupply() is the get Method used to get the supply variable.
///@return ArmySupplies pointer to the newly created supplies.
    ArmySupplies* getSupply();
///@brief ~Factory() is the destructer for the Factory class. It is never implemented as its derived classes delete the supply pointer.
    virtual ~Factory();
private:
    /**pointer to the supplies */
    ArmySupplies* supply;
};

#endif
