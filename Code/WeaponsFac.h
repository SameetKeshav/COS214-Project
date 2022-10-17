#ifndef WEAPONSFAC_H
#define WEAPONSFAC_H

class WeaponsFac : Factory {


public:
	virtual ArmySupplies* make() = 0;
};

#endif
