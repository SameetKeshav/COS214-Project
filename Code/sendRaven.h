#ifndef SENDRAVEN_H
#define SENDRAVEN_H

class sendRaven : Raven {

private:
	int numFood;
	int numMedical;
	int numWeapons;
	SupplyWagon* supplies;
	Commander* subject;
	MasterOfCoin m;

public:
	void update();

	void checkSupplies();
};

#endif
