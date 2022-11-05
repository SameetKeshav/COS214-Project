#ifndef MASTEROFCOIN_H
#define MASTEROFCOIN_H

#include "Economy.h"
#include "Raven.h"
#include "Strategy.h"
#include "Treasury.h"
#include "WarIndicators.h"

class Strategy;
/** @brief The Concrete class for the Mediator
    A class that allows for other classes to talk to when key changes are made
    @author Sameet Keshav u21479373
    @date October 2022
    */

class MasterOfCoin : public Treasury {

private:
    /// The Economy that the mediator uses
	Economy* economy;

    /// The Observer that the mediator uses
	Raven* observer;

    /// The Strategy the mediator uses
	Strategy* strategy;

public:
    ///@brief Constructor to set the variables in this class
    ///@param economy holds the Economy that will be using the mediator
    ///@param observer holds the observer that will use the mediator
    ///@param strategy holds the strategy object that will use the mediator
    MasterOfCoin(Economy* economy, Raven* observer, Strategy* strategy);

    ///@brief This is the method that all objects will use to call the mediator when a change is made
    ///@param sender is the variable that holds the object who sent the notify request
	void notify(WarIndicators* sender);

    ///@brief Will call the decreaseCurrency method of the Economy
	void decreaseCurrency();

    ///@brief will call on the obsever to create more supplies
	void manufacture();

    ///@brief This is the destructer used to deallocate all memory used in this class
    ~MasterOfCoin();
};

#endif
