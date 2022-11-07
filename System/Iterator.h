#ifndef ITERATOR_H
#define ITERATOR_H
#include "Bannerman.h"

/**
 * @brief Iterator class
 * Defines an interface for accessing and traversing bannerman elements in groundForces.
 *  @author Thapelo Thoka
 *   @date October 2022
  */
class Iterator {


public:
    /**
     * @brief Abstract. Returns a pointer to the current bannerman object in groundForces being accessed,
     * , primitive operations can be performed on the returned bannerman object
     * @returns Bannerman*
     * */
    virtual Bannerman* Current()=0;
    /**
     * @brief Abstract. determines whether or not the current bannerman object being accessed in groundForces
     * is the last element in the list or not
     * @returns false
     * @returns true */
    virtual bool hasNext() = 0;

    /**
 * @brief Abstract. Sets the current pointer to the next bannerman object in groundForces to be accessed and returns it,
     * , primitive operations can be performed on the returned bannerman object
 * @returns Bannerman*
     * */
    virtual Bannerman* next() = 0;

    /** @brief Abstract. Returns whether or not the current item is active or not
     * @returns true
     * @returns false
     * */
    virtual bool isActive() = 0;
};

#endif
