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

public:
    /**Pointer to the decorated component*/
    WarTheatre* myVenue;

    Conditions();

    void sendScout() override ;

    /**@brief constructor for the decorator class.
     * merely used to assign variables and call the decorator function
     * @param myVenue - pointer to the object that is to be decoraed
     */
    Conditions(WarTheatre* myVenue);
};

#endif
