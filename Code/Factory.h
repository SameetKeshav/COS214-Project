
#ifndef FACTORY_H
#define FACTORY_H
#include "WarIndicators.h"
#include "ArmySupplies.h"

class Factory : WarIndicators {

public:
    /// @brief Calls the method needed to manufacture the supplies.
    /// @author Ronin Brookes 19069686
    void operation();
    /// @brief Returns supplies.
    /// @return returns the supplies the Factory manufactured
    /// @author Ronin Brookes 19069686
    ArmySupplies* getSupply();
    /// @brief Deletes allocated memory to supply variable.
    /// @author Ronin Brookes 19069686
    void ~Factory();
protected:
    virtual ArmySupplies* make() = 0;
private:
    ArmySupplies* supply;

};

#endif
