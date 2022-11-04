#include <algorithm>
#include "HistoryBook.h"

void HistoryBook::add(History* h) {
	defectedAllies.push_back(h);
}

History* HistoryBook::getAlly() {
	History* temp = defectedAllies.front();
	defectedAllies.pop_front();
	return temp;
}
