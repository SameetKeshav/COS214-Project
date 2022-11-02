#ifndef CONDITIONS_H
#define CONDITIONS_H
#include <cstdlib>
#include "WarTheatre.h"

/**@brief decorator class.
 * This is the class/object decorates the concreteComponent. Inherits from WarTheatre class.
 * @author Keabetswe Mothapo
 * @date October 2022
 */

class Conditions : public  WarTheatre {

private:
	/**Pointer to the decorated component*/
	WarTheatre* myVenue;
	
public:
<<<<<<< Updated upstream
    /**Pointer to the decorated component*/
	WarTheatre* myVenue;

	void sendScout();
=======

	/**@brief decorator function for thr pattern*/
	void sendScout() ;
>>>>>>> Stashed changes

    /**@brief constructor for the decorator class.
     * merely used to assign variables and call the decorator function
     * @param myVenue - pointer to the object that is to be decoraed
     */
	Conditions(WarTheatre* myVenue);
<<<<<<< Updated upstream
=======
	
	/**@brief destructor to delete the WarTheatre pointer*/
	virtual ~Conditions();
>>>>>>> Stashed changes
};

#endif
