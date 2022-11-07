#ifndef MEDICALWAGON_H
#define MEDICALWAGON_H
#include "Factory.h"
#include "SupplyWagon.h"
#include "ArmySupplies.h"
#include "MedicalSupp.h"

///@brief Concrete Prototype class to serve as the wagon for Medical
///@author Ronin Brookes 19069686
class MedicalWagon : public SupplyWagon {

public:
    /// @brief initialize the supp variable for the MedicalWagon.
    /// @param sup is used to set the supp variable,
    void setSup(ArmySupplies* sup);
    /// @brief Clone the Medical Supply Wagon object.
    /// @return the new Medical Supply Wagon clone.
    SupplyWagon* clone();
    /// @brief Return the supp variable for the Medical Wagon.
    /// @return returns the supp variable. Returns the necessary supplies.
    ArmySupplies* getSupplies();
    /**pointer to the supplies in the Medical wagon*/
    ArmySupplies* supp;
    ///@brief destructor for the Medical Wagon class to delete and free the supply variable.
    ~MedicalWagon();
};

#endif
