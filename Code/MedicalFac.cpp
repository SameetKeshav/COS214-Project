#include "MedicalFac.h"

ArmySupplies* MedicalFac::make() {
    cout<<"Medicine is being Manufactured"<<endl;
    ArmySupplies* supplies = new MedicalSupp();
    return supplies;
}

MedicalFac::~MedicalFac() {

}
