#ifndef MEDICALFAC_H
#define MEDICALFAC_H

class MedicalFac : Factory {


public:
	virtual ArmySupplies* make() = 0;
};

#endif
