#ifndef RAVEN_H
#define RAVEN_H

/** @brief The Abstract class for the Observer
    A class that the Concrete Observer class inherits from
    @author Sameet Keshav u21479373
    @date October 2022
    */
class Raven {


public:
    /// The Pure Virtual function for the update method that the concrete class uses
	virtual void update() = 0;
};

#endif
