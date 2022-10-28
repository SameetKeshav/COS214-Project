#include "FoodFac.h"

ArmySupplies* FoodFac::make() {
    ArmySupplies supplies = new FoodSupp();
    return supplies;
}
