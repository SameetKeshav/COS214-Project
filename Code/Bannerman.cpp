#include "Bannerman.h"


Bannerman::Bannerman(string name, int favor, int numFood, int Medical, int HP,WarTheatre*warZone,Strategy*strategy,MasterOfCoin* m) {
    this->name =name;
    this->favour =favor;
    this->numFood =numFood;
    this->numMedical =Medical;
    this->HP =HP;
    this->warZone =warZone;
    this->strategy =strategy;
    this->m =m;
}
int Bannerman::getHP() {
    return this->HP;
}

void Bannerman::attackKingdom(Kingdom* X) {
    // TODO - implement Bannerman::attackKingdom
    throw "Not yet implemented";
}

string Bannerman::getName() {
    return this->name;
}

void Bannerman::attach(Raven o) {
    // TODO - implement Bannerman::attach
    throw "Not yet implemented";
}

void Bannerman::detach(Raven o) {
    // TODO - implement Bannerman::detach
    throw "Not yet implemented";
}


void Bannerman::increaseHP(int boost) {
    this->HP+= boost;
}

void Bannerman::changeStrategy(Strategy* strategy) {
    // TODO - implement Bannerman::changeStrategy
    throw "Not yet implemented";
}

void Bannerman::attack(Bannerman* myBannerman, Bannerman* enemyBannerman) {
    // TODO - implement Bannerman::attack
    throw "Not yet implemented";
}

void Bannerman::increasePower(int boost) {
    // TODO - implement Bannerman::increasePower
    throw "Not yet implemented";
}

void Bannerman::receiveDamage(int x){
    this->damage+= x;
}
void Bannerman::decreaseWeapons(){
    this->numWeapons-=1;
}
void Bannerman::decreaseFood(){
    this->numFood -=1;
}
void Bannerman::decreaseMedical(){
    this->numMedical -= 1;
}
WarTheatre* Bannerman::getWarZone(){
    return this->warZone;
}