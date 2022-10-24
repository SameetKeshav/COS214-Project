#include "Commander.h"

Commander::Commander():groundForces() {

}
ConIterator* Commander::createIterator() {
    return new ConIterator(groundForces);
}

void Commander::giveCommand() {
    // TODO - implement Commander::giveCommand
    throw "Not yet implemented";
}

//void Commander::attackKingdom(Kingdom* X) {// TODO - Test
//
//    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
//        (*it)->attackKingdom(X);
//
//}

void Commander::addBannerman(Bannerman* b) {// TODO - Test
    groundForces.push_back(b);
}



int Commander::getWeapons() {// TODO - Test
    return this->numWeapons;
}

int Commander::getFood() {// TODO - Test
    return this->numFood;
}

int Commander::getMedical() {// TODO - Test
    return this->numMedical;
}

void Commander::setWeapons(int numWeapons) {
    this->numWeapons = numWeapons;
}

void Commander::setFood(int numFood) {
    this->numFood = numFood;
}

void Commander::setMedical(int numMedical) {
    this->numMedical = numMedical;
}

Commander::~Commander() {// TODO - Test
    for (std::list<Bannerman*>::iterator it = groundForces.begin();it != groundForces.end(); ++it)
        delete *it;
}
