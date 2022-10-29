#ifndef KINGDOM_H
#define KINGDOM_H
using namespace std;
#include <vector>
#include "Bannerman.h"
#include "Economy.h"

/** @brief A Kingdom class that has all the fighting Bannerman and Economy.
    @author Morgan Bentley
    @date October 2022
    */
class Kingdom {

private:
	/**vector list of all Bannerman objects a Kingdom owns**/
	vector<Bannerman*> bannerman;
	/**pointer to the Economy of the Kingdom**/
	Economy* economy;

public:
	/** @brief Constructor. initializes Economy pointer and vector list.
	 * @param economy - Economy pointer to player's Economy object.
	 * @param bannerman - vector list of Bannerman objects.
	*/
	Kingdom(Economy* economy,vector<Bannerman*> bannerman);
	/** @brief removes specified Bannerman from vector list.
	 * @param b - Bannerman that has lost a fight or defected to enemyKingdom.
	*/
	void remove(Bannerman* b);
	/** @brief adds specified Bannerman into vector list.
	 * @param b - Bannerman that has defected from enemyKingdom
	*/
	void add(Bannerman* b);
	/** @todo destructor. deallocates all pointers of this class**/
	virtual ~Kingdom();
};

#endif
