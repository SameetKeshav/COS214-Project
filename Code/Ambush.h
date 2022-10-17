#ifndef AMBUSH_H
#define AMBUSH_H

class Ambush : Strategy {

public:
	int stealth;

	void attack(Bannerman* myBannerman, Bannerman* enemyBannerman);

	Ambush(int stealth);
};

#endif
