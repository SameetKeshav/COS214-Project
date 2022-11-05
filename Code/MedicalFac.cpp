#include "MedicalFac.h"

ArmySupplies* MedicalFac::make() {
    ArmySupplies* supplies = new MedicalSupp();
    return supplies;
}

MedicalFac::~MedicalFac() {

}
