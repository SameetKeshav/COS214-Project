#ifndef MEDICALWAGON_H
#define MEDICALWAGON_H

class MedicalWagon : SupplyWagon {

public:
	SupplyWagon* medicalList;

	SupplyWagon* clone();
};

#endif
