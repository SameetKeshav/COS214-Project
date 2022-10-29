#ifndef TOPOLOGY_H
#define TOPOLOGY_H

/**@brief concrete decorator B.
 * This is class that decorates the topology of the venue. Inherits from Conditions class
 * @author Keabetswe Mothapo
 * @date October 2022
 */
class Topology : public Conditions {

public:

    /**@brief getter for the Topology object
     * @return - this topology object*/
	Topology* getTopology();

    /**@brief setter for the topology of the war venue
     * uses the inherited venue variable to adjust difficuty of teh terrian*/
    void setTopology();

    /**@brief default constructor that calls the decorator function*/
	Topology();

    /**@brief implements the decorator function*/
    void sendScout();
};

#endif
