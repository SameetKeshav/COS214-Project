#ifndef SUPPLYWAGON_H
#define SUPPLYWAGON_H
#include "ArmySupplies.h"

///@brief Abstract Prototype class SupplyWagon to serve as the base class for all derived concrete prototypes
///@author Ronin Brookes 19069686
class SupplyWagon {

public:

    /// @brief initialize the supp variable.
    /// @param sup used to set the supp variable.
   virtual void setSup(ArmySupplies* sup)=0;
    /// @brief Clone the Supply Wagon object.
    /// @return the new Supply Wagon clone.
    virtual SupplyWagon* clone() = 0;
    /// @brief Return the supp variable.
    /// @return returns the supp variable. Returns the necessary supplies.
    virtual ArmySupplies* getSupplies()=0;
    /**pointer to the supplies in the wagon*/
    ArmySupplies* supp;
    //virtual ~SupplyWagon();

};

#endif
