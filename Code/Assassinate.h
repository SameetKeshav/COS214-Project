#ifndef ASSASSINATE_H
#define ASSASSINATE_H

class Assassinate : Strategy {

private:
	int stealth;
	bool alive;

public:
	Assassinate(int stealth, bool alive);

	void attack(Bannerman* myBannerman, Bannerman* enemyBannerman);
};

#endif
