#include "Commander.h"
#include "MasterOfCoin.h"
#include "Troop.h"

//Julianna added and changed constructor
Commander::Commander(string n) :groundForces() {
    name = n;
    groundForces.push_back(new Troop("Squadron 1", 12, 20, 18, 200, nullptr, nullptr, nullptr, true, 200));
    groundForces.push_back(new Troop("Squadron 2", 12, 20, 18, 300, nullptr, nullptr, nullptr, true, 300));

}

Iterator* Commander::createIterator() {
    return new ConIterator(groundForces);
}



void Commander::addBannerman(Bannerman* b) {
    groundForces.push_back(b);
}

void Commander::removeBannerman(Bannerman* x){
    groundForces.remove(x);
}

int Commander::getHP() {
    int total=0;
    Iterator* IT = createIterator();

    total+=IT->Current()->getHP();

    while (IT->hasNext()){
        total+=IT->Current()->getHP();
        IT->next();
    }
    return total;

}


list<Bannerman*> Commander::getTroops(){
    return groundForces;
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

int Commander::getWeapons() {
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


int Commander::getFood() {
    int totalFood = 0;

    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        totalFood+=(*it)->getFood();

    return totalFood;
}

int Commander::getMedical() {
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

int Commander::getFavour(){
    int sum=0;
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        sum+=(*it)->getFavour();
    return sum;
}

Commander::~Commander() {
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

void Commander::decreasePower(int x){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->decreasePower(x);
}

//added functions:
//fixed
void Commander::setRaven(list<Raven*> r){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->setRaven(r);
}

//fixed
void Commander::setMaster(MasterOfCoin* m){
    for (std::list<Bannerman*>::iterator it = groundForces.begin(); it != groundForces.end(); ++it)
        (*it)->setMaster(m);
}

//fixed.
void Commander::setStrategy(Strategy* s){
    this->changeStrategy(s);
}

string Commander::getName() {
    return  name;
}