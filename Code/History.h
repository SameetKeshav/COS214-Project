#ifndef HISTORY_H
#define HISTORY_H

class History {

private:
	Bannerman* bannerman;

public:
	History(Bannerman* f);

	Bannerman* getBannerman();

	void ~Memento();
};

#endif
