#include "FoodFac.h"

ArmySupplies* FoodFac::make() {
    cout<<"Food is being Manufactured"<<endl;
    ArmySupplies* supplies = new FoodSupp();
    return supplies;
}
FoodFac::~FoodFac(){
}