#ifndef WEAPONSFAC_H
#define WEAPONSFAC_H
#include "Factory.h"
#include "ArmySupplies.h"
#include "WeaponSupp.h"

class WeaponsFac : Factory {

public:
    /// @brief Weapon Factory makes Weapon supplies.
    /// @return returns the supplies the Weapon Factory just manufactured
    /// @author Ronin Brookes 19069686
    ArmySupplies* make() ;
};

#endif
