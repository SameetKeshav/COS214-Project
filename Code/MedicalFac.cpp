#include "MedicalFac.h"

ArmySupplies* MedicalFac::make() {
    ArmySupplies supplies = new FoodSupp();
    return supplies;
}
