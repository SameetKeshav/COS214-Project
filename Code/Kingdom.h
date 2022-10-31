#ifndef KINGDOM_H
#define KINGDOM_H
using namespace std;
#include <vector>
#include "Bannerman.h"
#include "Economy.h"

class Kingdom {

private:
	vector<Bannerman*> bannermen;
	Economy* economy;

public:
<<<<<<< Updated upstream
	Kingdom(Economy* economy);
=======
	/** @brief Constructor. initializes Economy pointer and vector list.
	 * @param economy - Economy pointer to player's Economy object.
	 * @param bannerman - vector list of Bannerman objects.
	*/
	Kingdom(Economy* economy);
	/** @brief removes specified Bannerman from vector list.
	 * @param b - Bannerman that has lost a fight or defected to enemyKingdom.
	*/
>>>>>>> Stashed changes
	void remove(Bannerman* b);
	void add(Bannerman* b);
	vector<Bannerman*> getKingdom();
	int getSize(); //added
	Bannerman* getAlly(string n); //added
	virtual ~Kingdom();
	int getSize(); //added
	Bannerman* getAlly(string n); //added
	vector<Bannerman*> getKingdom();
};

#endif
