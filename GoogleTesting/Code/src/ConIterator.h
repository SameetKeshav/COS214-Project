#ifndef CONITERATOR_H
#define CONITERATOR_H
#include "Bannerman.h"
#include "Iterator.h"
#include <list>
using namespace std;

/**
 * @Brief Concrete iterator class
 * Implements the interface for accessing and traversing bannerman elements in groundForces.
 * Keeps track of the current position in the traversal of the aggregate(groundForces list).
 *  @author Thapelo Thoka
 *  @date October 2022
 */
class ConIterator : public Iterator {
private:
    /**
     * The list of bannerman objects to traverse*/
    list<Bannerman*> armyList;

    /**
     * An iterator which is a pointer to the current bannerman object in Commander's groundForces being accessed,
     * primative operations can be performed using this pointer.*/
    list<Bannerman*>::iterator it;
public:
    /**
     * ConIterator Constructor which takes in a list of bannerman objects.
     * @param X - the groundForces list which will be accessed sequentially.
     * */
    ConIterator(list<Bannerman*> X);

    /**
 * @brief Returns a pointer to the current bannerman object in groundForces being accessed,
 * , primitive operations can be performed on the returned bannerman object
 * @returns Bannerman*
 * */
    Bannerman* Current();


    /**
* @brief Sets the (*it) pointer to the next bannerman object in groundForces to be accessed and returns it,
 * , primitive operations can be performed on the returned bannerman object
* @returns Bannerman*
 * */
    Bannerman* next();

    /**
 * @brief Determines whether or not the current bannerman object which (*it) currently points to
 * is the last element in the list or not
 * @returns false
 * @returns true */
    bool hasNext();

    /**@Brief Returns whether or not the current item is active or not by determining whether HP>0 or not
 * @returns true
 * @returns false
 * */
    bool isActive();
};

#endif
