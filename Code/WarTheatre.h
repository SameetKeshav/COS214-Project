#ifndef WARTHEATRE_H
#define WARTHEATRE_H

#include "Strategy.h"
using namespace std;

/**@brief Abstract object.
 * This is the Component participant in the decorator pattern.
 * @author Keabetswe Mothapo
 * @date October 2022
 */

class WarTheatre {

private:
    /**Name of Strategy as it determines the venue of the battle*/
	Strategy* strategy;
    /**Char representing the venue. options a to d only*/
	char venue;

    /**The location of the venue as a string*/
    string location;

    /**Integer representing the difficulty of the battle at the decorated venue*/
	int difficulty;


public:
    /**@brief Constructor
     * @param myStrat - a pointer to te strategy object used in the battle*/
	WarTheatre(Strategy* myStrat);

    /**@brief returns the strategy the location is based on
     * @return the strategy pointer*/
    Strategy* getStrategy(); //may need to make sendScout the virtual one instead

    /**@brief Abstract. Decorates the location of the battle*/
	virtual void sendScout() = 0;

    /**@brief function that uses the parameter to decide the venue of the war
     * @param strategy - a pointer to te strategy object used in the battle
     * @return char variable of the location. options are a, b, c and d only
     */
    char decideVenue(Strategy* strategy);

	WarTheatre(Strategy myStrat);
};

#endif
