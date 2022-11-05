#ifndef HISTORY_H
#define HISTORY_H
#include "Bannerman.h"
#include <iostream>
using namespace std;
class History { //memento
/** @brief The memento class in the memento design pattern
 * @author Julianna Venter
 * @date November 2022
 */
private:
    /** a bannerman object that represents the current bannerman being stored - the one that has defected */
	Bannerman* bannerman;

public:
    /**
     * @brief constructor that sets class variable
     * @param b parameter that class variable is set to
     */
	History(Bannerman* b);

    /**
     * @brief returns the stored bannerman
     * @return the stored bannerman
     */
	Bannerman* getBannerman();

    /**
     * @brief the destructor
     */
	~History(){};
};

#endif
