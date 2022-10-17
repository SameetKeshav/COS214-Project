#ifndef FACTORY_H
#define FACTORY_H

class Factory : WarIndicators {

public:
	ArmySupplies* supply;

	virtual ArmySupplies* make() = 0;
};

#endif
