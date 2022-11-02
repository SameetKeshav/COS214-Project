#ifndef SUPPLYWAGON_H
#define SUPPLYWAGON_H
#include "ArmySupplies.h"

class SupplyWagon {

public:

    /// @brief initialize the supp variable.
    /// @param sup is used to set the supp variable,
    /// @author Ronin Brookes 19069686
   virtual void setSup(ArmySupplies* sup)=0;
    /// @brief Clone the Supply Wagon object.
    /// @return the new Supply Wagon clone.
    /// @author Ronin Brookes 19069686
    virtual SupplyWagon* clone() = 0;
    /// @brief Return the supp variable.
    /// @return returns the supp variable. Returns the necessary supplies.
    /// @author Ronin Brookes 19069686
    virtual ArmySupplies* getSupplies()=0;
    ArmySupplies* supp;
    //virtual ~SupplyWagon();

};

#endif
