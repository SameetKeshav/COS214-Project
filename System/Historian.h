#ifndef HISTORIAN_H
#define HISTORIAN_H
#include "Bannerman.h"
#include "History.h"
class History;
class Historian { 
/** @brief The originator class in the memento design pattern.
 * @author Julianna Venter.
 * @date November 2022.
 */
private:
    /** a bannerman object that represents the current bannerman being stored - the one that has defected */
	Bannerman* bannerman;

 public:
    /** @brief sets the bannerman variable
     * @param b the bannerman being set to the class variable
     */
	void setAlly(Bannerman* b);

    /** @brief stores the bannerman in a memento object (history).
     * @return the resulting history object with the bannerman.
     */
	History* Store();

    /**
     * @brief reverts the bannerman that was stored to original state for when they return.
     * @param h the history object being restored.
     * @return the bannerman that was restored from the stored history object.
     */
	Bannerman* restoreAlly(History* h); 

    /**
     * @brief the destructor.
     */
	~Historian(){};
};

#endif
