#ifndef HISTORIAN_H
#define HISTORIAN_H
#include "Bannerman.h"
#include "History.h"
class Historian {

private:
	Bannerman* bannerman;

public:
	Historian(Bannerman* b);

	History* setAlly();

	Bannerman* restoreAlly(History* h);

	~Historian(){delete bannerman;};
};

#endif
