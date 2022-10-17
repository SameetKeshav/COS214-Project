#ifndef FOODFAC_H
#define FOODFAC_H

class FoodFac : Factory {


public:
	virtual ArmySupplies* make() = 0;
};

#endif
