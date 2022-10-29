#ifndef COMMANDER_H
#define COMMANDER_H


class Commander : Bannerman {

public:
	list<Bannerman*> groundForces;

	Iterator* createIterator();

	void giveCommand();

	void attackKingdom(Kingdom* X);

	void addBannerman(Bannerman* b);

	int getWeapons();

	int getFood();

	int getMedical();

	void setWeapons(int numWeapons);

	void setFood(int numFood);

	void setMedical(int numMedical);
};

#endif
