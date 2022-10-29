#include "Factory.h"

void Factory::operation() {
    supply=make();
}

ArmySupplies* Factory::getSupply() {
    return supply;
}

Factory::~Factory() {
    delete supply;
}