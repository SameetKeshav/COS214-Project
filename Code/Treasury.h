#ifndef TREASURY_H
#define TREASURY_H

/** @brief The Abstract class for the Mediator
    A class that the Concrete Mediator class inherits from
    @author Sameet Keshav u21479373
    @date October 2022
    */
#include "WarIndicators.h"
class Treasury {


public:
    /// The pure virtual function for the notify function
	virtual void notify(WarIndicators* sender) = 0;
};

#endif
