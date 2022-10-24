#include "Commander.h"

Commander::Commander():groundForces() {

}
ConIterator* Commander::createIterator() {
    return new ConIterator(groundForces);
}

void Commander::attackKingdom(Kingdom* X) {// TODO - Test

    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->attackKingdom(X);

}

void Commander::addBannerman(Bannerman* b) {// TODO - Test
    groundForces.push_back(b);
}

int Commander::getTotalWeapons() {// TODO - Test
    int totalWeapons = 0;

    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        totalWeapons+=(*it)->getWeapons();

    return totalWeapons;
}

int Commander::getTotalFood() {// TODO - Test
    int totalFood = 0;

    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        totalFood+=(*it)->getFood();

    return totalFood;
}

int Commander::getTotalMedical() {// TODO - Test
    int totalMedical = 0;

    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        totalMedical+=(*it)->getMedical();

    return totalMedical;
}

Commander::~Commander() {// TODO - Test
    for (std::list<Bannerman*>::iterator it = groundForces.begin();it != groundForces.end(); ++it)
        delete *it;
}
