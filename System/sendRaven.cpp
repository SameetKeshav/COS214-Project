#include "sendRaven.h"

sendRaven::sendRaven(SupplyWagon **supplies, Bannerman *subject)
{
    this->supplies = supplies;
    this->subject = subject;
}

void sendRaven::update()
{
    numFood = subject->getFood();
    numMedical = subject->getMedical();
    numWeapons = subject->getWeapons();

    checkSupplies();
}

void sendRaven::checkSupplies()
{
    if(numWeapons <= 10)
    {
        SupplyWagon* s = supplies[1]->clone();
        ArmySupplies* as = s->getSupplies();
        subject->setWeapons(as->getAmount());
    }

    if(numFood <= 10)
    {
        SupplyWagon* s = supplies[0]->clone();
        ArmySupplies* as = s->getSupplies();
        subject->setFood(as->getAmount());
    }

    if(numMedical <= 10)
    {
        SupplyWagon* s = supplies[2]->clone();
        ArmySupplies* as = s->getSupplies();
        subject->setMedical(as->getAmount());
    }
    cout<<"Supplies have been received."<<endl;
}

sendRaven::~sendRaven()
{
    /*for(int i = 0; i < 3; i++)
    {
        delete supplies[i];
    }*/

    //delete supplies;
    delete subject;
}
