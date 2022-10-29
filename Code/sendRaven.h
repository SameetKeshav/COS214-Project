#ifndef SENDRAVEN_H
#define SENDRAVEN_H

#include "SupplyWagon.h"
#include "Commander.h"
#include "MasterOfCoin.h"
#include "Raven.h"
#include "Bannerman.h"


///@author Sameet Keshav, u21479373
class sendRaven : Raven {

private:
	int numFood;
	int numMedical;
	int numWeapons;
	SupplyWagon** supplies;
	Bannerman* subject;

public:
    ///@brief constructor for the concrete Raven class
    ///@param supplies is an array of pointer objects of type SupplyWagon
    ///@param subject is a pointer for the Bannerman subject that this Observer will observe
    sendRaven(SupplyWagon** supplies, Bannerman* subject);

    ///@brief This method will be called from outside the class, this method will get the amount of resources the subject has, then call the check method
	void update();

    ///@brief This method will check to see if there is too little supplies then call the appropriate Supply Wagon to fill it up
	void checkSupplies();

    ///@brief The Destructor will be used to deference all pointer variables used by this class to stop all memory leaks
    ~sendRaven();
};

#endif
