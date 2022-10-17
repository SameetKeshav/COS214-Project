#ifndef SIEGE_H
#define SIEGE_H

class Siege : Strategy {

public:
	int stealth;

	Siege(int stealth);

	void attack(Bannerman* myBannerman, Bannerman* enemyBannerman);
};

#endif
