#include "Commander.h"

Commander::Commander():groundForces() {

}
Iterator* Commander::createIterator() {
    return new ConIterator(groundForces);
}



void Commander::addBannerman(Bannerman* b) {// TODO - Test
    groundForces.push_back(b);
}

void Commander::removeBannerman(Bannerman* x){
    groundForces.remove(x);
}

int Commander::getHP() {
    int totalHP = 0;

    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        totalHP+=(*it)->getHP();

    return totalHP;
}

void Commander::attack(Bannerman* myBannerman, Bannerman* enemyBannerman){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->attack(myBannerman, enemyBannerman);
}

int Commander::getDamage() {
    int totalDamage = 0;

    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        totalDamage+=(*it)->getDamage();

    return totalDamage;
}

void Commander::receiveDamage(int X){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->receiveDamage(X);
}

int Commander::getWeapons() {// TODO - Test
    int totalWeapons = 0;

    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        totalWeapons+=(*it)->getWeapons();

    return totalWeapons;
}

void Commander::decreaseWeapons(){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->decreaseWeapons();
}
void Commander::decreaseFood(){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->decreaseFood();
}
void Commander::decreaseMedical(){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->decreaseMedical();
}

void Commander::setWeapons(int numWeapons){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->setWeapons(numWeapons);
}

void Commander::setFood(int numFood){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->setFood(numFood);
}

void Commander::setMedical(int numMedical){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->setMedical(numMedical);
}


int Commander::getFood() {// TODO - Test
    int totalFood = 0;

    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        totalFood+=(*it)->getFood();

    return totalFood;
}

int Commander::getMedical() {// TODO - Test
    int totalMedical = 0;

    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        totalMedical+=(*it)->getMedical();

    return totalMedical;
}

void Commander::increaseHP(int boost){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->increaseHP(boost);
}

void Commander::changeStrategy(Strategy* strategy){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->changeStrategy(strategy);
}
void Commander::increaseFavour(){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->increaseFavour();
}

void Commander::decreaseFavour(){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->decreaseFavour();
}


Commander::~Commander() {// TODO - Test
    for (std::list<Bannerman*>::iterator it = groundForces.begin();it != groundForces.end(); ++it)
        delete *it;
}

void Commander::attach(Raven *o) {
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->attach(o);
}

void Commander::detach(Raven *o) {
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->detach(o);
}

void Commander::increasePower(int boost) {
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->increasePower(boost);
}
