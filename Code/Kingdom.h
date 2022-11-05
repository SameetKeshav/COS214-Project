#ifndef KINGDOM_H
#define KINGDOM_H

#include <list>
#include "Bannerman.h"
#include "Economy.h"

using namespace std;

class Bannerman;

/** @todo A Kingdom class that has all the fighting Bannerman and Economy.
    @author Morgan Bentley
    @date October 2022
    */
class Kingdom {

private:
	/**vector list of all Bannerman objects a Kingdom owns**/
	list<Bannerman*> bannerman;
	/**pointer to the Economy of the Kingdom**/
	Economy* economy;

public:
	/** @todo Constructor. initializes Economy pointer and vector list.
	 * @param economy - Economy pointer to player's Economy object.
	*/
	Kingdom(Economy* economy);
	/** @todo removes specified Bannerman from vector list.
	 * @param b - Bannerman that has lost a fight or defected to enemyKingdom.
	*/
	void remove(Bannerman* b);
	/** @todo adds specified Bannerman into vector list.
	 * @param b - Bannerman that has defected from enemyKingdom
	*/
	void add(Bannerman* b);
	/** @todo destructor. deallocates all pointers of this class**/
	virtual ~Kingdom();
	/** @todo returns current number of Bannerman in the Kingdom.
	 * @return integer representing the number of Bannerman in Kingdom.**/
	int getSize();
	/** @todo returns a particular allied Bannerman given a unique string name.
	 * @param n - unique name of a particular Bannerman.
	 * @return a particular allied Bannerman.**/
	Bannerman* getAlly(string n);
	/** @todo returns a list of Bannerman pointers in the Kingdom.
	 * @return vector list of all Bannerman objects a Kingdom owns.**/
	list<Bannerman*> getKingdom();
};

#endif
