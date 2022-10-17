#ifndef WEAPONWAGON_H
#define WEAPONWAGON_H

class WeaponWagon : SupplyWagon {

public:
	SupplyWagon* weaponList;

	SupplyWagon* clone();
};

#endif
