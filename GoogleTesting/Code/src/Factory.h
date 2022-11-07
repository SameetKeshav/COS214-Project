
#ifndef FACTORY_H
#define FACTORY_H
#include "WarIndicators.h"
#include "ArmySupplies.h"
#include <iostream>
using namespace std;

class Factory : public WarIndicators {

protected:
    virtual ArmySupplies* make() = 0;
public:
    void operation();
    ArmySupplies* getSupply();
    virtual ~Factory();
private:
    ArmySupplies* supply;
};

#endif
