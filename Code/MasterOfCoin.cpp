#include "MasterOfCoin.h"

MasterOfCoin::MasterOfCoin(Economy *economy, Raven *observer, Strategy* strategy)
{
    this->economy = economy;
    this->observer = observer;
    this->strategy = strategy;
}

void MasterOfCoin::notify(WarIndicators* sender)
{

    if(sender == strategy)
    {
        decreaseCurrency();
    }

    else if(sender == economy)
    {
        manufacture();
    }
}

void MasterOfCoin::decreaseCurrency()
{
    economy->decreaseCurrency();
}

void MasterOfCoin::manufacture()
{
    observer->update();
}

MasterOfCoin::~MasterOfCoin()
{
    delete economy;
    delete observer;
    delete strategy;
}