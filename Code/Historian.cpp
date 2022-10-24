#include "Historian.h"

/// @brief constructor
/// @param b bannerman that is defecting
Historian::Historian(Bannerman* b) {
	bannerman = b;
}

/// @brief set the memento object of the defecting bannerman
/// @return the created memento object for that bannerman
History* Historian::setAlly() {
	History* h = new History(bannerman);
	return h;
}

/// @brief return the bannerman that defected
/// @param h the memento object that needs to be restored
/// @return the bannerman of that object
Bannerman* Historian::restoreAlly(History* h) {
	bannerman = h->getBannerman();
	return bannerman;
}

