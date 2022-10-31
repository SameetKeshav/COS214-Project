#ifndef CONITERATOR_H
#define CONITERATOR_H
#include "Bannerman.h"
#include "Iterator.h"
#include <vector>
using namespace std;
<<<<<<< Updated upstream
class ConIterator : public Iterator {
private:
    list<Bannerman*> armyList;
    list<Bannerman*>::iterator it;
public:
    ConIterator(list<Bannerman*> X);
=======

/**
 * @Brief Concrete iterator class
 * Implements the interface for accessing and traversing bannerman elements in groundForces.
 * Keeps track of the current position in the traversal of the aggregate(groundForces vector).
 *  @author Thapelo Thoka
 *  @date October 2022
 */
class ConIterator : public Iterator {
private:
    /**
     * The vector of bannerman objects to traverse*/
    vector<Bannerman*> armyList;

    /**
     * An iterator which is a pointer to the current bannerman object in Commander's groundForces being accessed,
     * primative operations can be performed using this pointer.*/
    vector<Bannerman*>::iterator it;
public:
    /**
     * ConIterator Constructor which takes in a vector of bannerman objects.
     * @param X - the groundForces vector which will be accessed sequentially.
     * */
    ConIterator(vector<Bannerman*> X);
>>>>>>> Stashed changes

    Bannerman* Current();

    Bannerman* next();

<<<<<<< Updated upstream
=======
    /**
 * @brief Determines whether or not the current bannerman object which (*it) currently points to
 * is the last element in the vector or not
 * @returns false
 * @returns true */
>>>>>>> Stashed changes
    bool hasNext();

    bool isActive();
};

#endif
