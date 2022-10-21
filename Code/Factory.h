
#ifndef FACTORY_H
#define FACTORY_H
#include "WarIndicators.h"
#include "ArmySupplies.h"

class Factory : WarIndicators {

protected:
    virtual ArmySupplies* make() = 0;
public:
    void operation();
private:
    ArmySupplies* supply;

};

#endif
