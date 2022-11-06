#include "Historian.h"

void Historian::setAlly(Bannerman* b) {
	bannerman = b;
}

History* Historian::Store(){
	return new History(bannerman);
}

Bannerman* Historian::restoreAlly(History* h) {
	bannerman = h->getBannerman();
	return bannerman;
}

