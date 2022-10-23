#ifndef BANNERMAN_H
#define BANNERMAN_H

class Bannerman : WarIndicators {

protected:
	int favour;
	int numWeapons;
	int numFood;
	int numMedical;
	list<Raven> ravenList;
private:
	bool assassin;
	MasterOfCoin m;
	Strategy* strategy;
	warTheatre* warZone;
	int HP;

public:
    int getHP();
    void setHP(int);

    Strategy* getStrategy();
    void setStrategy(Strategy* s);

	void giveCommand();

	Iterator* createIterator();

	void attackKingdom(Kingdom* X);

	void increaseFavour();

	void decreaseFavour();

	void attach(Raven o);

	void detach(Raven o);

	void increaseHP(int boost);

	void changeStrategy(Strategy* strategy);

	void attack(Bannerman* myBannerman, Bannerman* enemyBannerman);

	void increasePower(int boost);
};

#endif
