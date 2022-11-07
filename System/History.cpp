#include "History.h"

History::History(Bannerman* b) {
	bannerman = b;
}

Bannerman* History::getBannerman() {
	return this->bannerman;
}
