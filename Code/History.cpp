#include "History.h"

/// @brief constructor
/// @param b initialisor for bannerman object whos state needs to be stored
History::History(Bannerman* b) {
	bannerman = b;
}

/// @brief get current saved bannerman
/// @return the saved bannerman that is defecting
Bannerman* History::getBannerman() {
	return this->bannerman;
}
