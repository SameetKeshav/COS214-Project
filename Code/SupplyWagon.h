#ifndef SUPPLYWAGON_H
#define SUPPLYWAGON_H
#include "ArmySupplies.h"

class SupplyWagon {

public:
    void setSup(ArmySupplies* sup)=0;
    virtual SupplyWagon* clone() = 0;
};

#endif
