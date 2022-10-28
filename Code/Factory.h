
#ifndef FACTORY_H
#define FACTORY_H
#include "WarIndicators.h"
#include "ArmySupplies.h"

class Factory : WarIndicators {

public:
    void operation();
    ArmySupplies* getSupply();
    void ~Factory();
protected:
    virtual ArmySupplies* make() = 0;
private:
    ArmySupplies* supply;

};

#endif
