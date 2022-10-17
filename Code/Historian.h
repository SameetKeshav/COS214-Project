#ifndef HISTORIAN_H
#define HISTORIAN_H

class Historian {

private:
	Bannerman* Bannerman;

public:
	Historian(Bannerman* b);

	History* setAlly();

	Bannerman* restoreAlly(History* m);

	void ~Originator();
};

#endif
