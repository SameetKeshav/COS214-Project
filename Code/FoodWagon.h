#ifndef FOODWAGON_H
#define FOODWAGON_H

class FoodWagon : SupplyWagon {

public:
	SupplyWagon* foodList;

	SupplyWagon* clone();
};

#endif
