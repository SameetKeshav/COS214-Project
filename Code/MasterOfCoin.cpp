#include "MasterOfCoin.h"

void MasterOfCoin::notify(WarIndicators sender)
{

    if(sender == bannerman)
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
    factory->make();
}
