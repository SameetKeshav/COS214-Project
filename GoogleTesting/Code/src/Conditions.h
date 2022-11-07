#ifndef CONDITIONS_H
#define CONDITIONS_H
#include <cstdlib>
#include "WarTheatre.h"
//#include "Weather.h"
//#include "Topology.h"
#include "Location.h"

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

	/**@brief decorator function for thr pattern*/
	void sendScout() ;

    /**@brief constructor for the decorator class.
     * merely used to assign variables and call the decorator function
     * @param myVenue - pointer to the object that is to be decoraed
     */
	Conditions(WarTheatre* myVenue);
	
	/**@brief destructor to delete the WarTheatre pointer*/
	virtual ~Conditions();
};

#endif
