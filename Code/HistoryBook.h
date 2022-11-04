#ifndef HISTORYBOOK_H
#define HISTORYBOOK_H
#include "History.h"
#include <list>
class HistoryBook {

private:
	list<History*> defectedAllies;

public:
	void add(History* h);

	History* getAlly();  
};

#endif
