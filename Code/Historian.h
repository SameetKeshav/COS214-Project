#ifndef HISTORIAN_H
#define HISTORIAN_H
#include "Bannerman.h"
#include "History.h"
class Historian { //originator

private:
	Bannerman* bannerman;

 public:
	void setAlly(Bannerman* b);

	History* Store();

	Bannerman* restoreAlly(History* h); 

	~Historian(){delete bannerman;};
};

#endif
