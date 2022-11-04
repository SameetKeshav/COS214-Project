#include "History.h"

History::History(Bannerman* b) {
	bannerman = b;
}

string History::getName(){
	return bannerman->getName();
}

Bannerman* History::getBannerman() {
	return this->bannerman;
}
