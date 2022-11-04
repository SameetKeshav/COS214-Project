#ifndef HISTORYBOOK_H
#define HISTORYBOOK_H
#include "History.h"
#include <list>
class HistoryBook {
/** @brief The caretaker class in the memento design pattern
 * @author Julianna Venter
 * @date November 2022
 */
private:
    /** the list of history (memento) objects that represent bannermen that have defected */
	list<History*> defectedAllies;

public:
    /**
     * @brief adds the passed in history object to the class list
     * @param h the history object to be added
     */
	void add(History* h);

    /**
     * @brief gets the required history object to be restored
     * @return the history object that will be restored
     */
	History* getAlly();  
};

#endif
