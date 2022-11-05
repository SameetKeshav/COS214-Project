#ifndef WARTHEATRE_H
#define WARTHEATRE_H
#include "Strategy.h"
#include <string>
#include <iostream>

using namespace std;

class Strategy;
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
	int difficulty = 1;


public:
    /**@brief Constructor */
	WarTheatre();

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
	
	/**@brief returns the venue the battle is based in
     * @return the venue variable*/
	char getVenue();
	
	/**@brief sets the strategy the location is based on*/
	void setStrategy(Strategy* myStrat);
	
	/**@brief sets the location of the battle*/
	void setLocation(string loc);
	
	/**@brief sets the difficulty variable*/
	void setDifficulty(int num);
	
	/**@brief returns the difficulty value of the theatre
     * @return the difficulty value*/
	int getDifficulty();

    void setVenue(char v);
};

#endif
