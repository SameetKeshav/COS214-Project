#include "WeaponsFac.h"

ArmySupplies* WeaponsFac::make() {
    ArmySupplies supplies = new FoodSupp();
    return supplies;
}
