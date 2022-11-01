#include "Factory.h"
using namespace std;
void Factory::operation() {
    supply=make();
}

ArmySupplies* Factory::getSupply() {
    return supply;
}

Factory::~Factory() {
    if(supply){
        delete supply;
        supply=NULL;
        cout<<"Deleted!!!"<<endl;
    }
}