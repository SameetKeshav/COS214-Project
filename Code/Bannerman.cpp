#include "Bannerman.h"

int Bannerman::getHP() {
    return this->HP;
}

Iterator* Bannerman::createIterator() {
    // TODO - implement Bannerman::createIterator
    throw "Not yet implemented";
}

void Bannerman::attackKingdom(Kingdom* X) {
    // TODO - implement Bannerman::attackKingdom
    throw "Not yet implemented";
}

void Bannerman::increaseFavour() {
    this->favour +=1;
}

void Bannerman::decreaseFavour() {
    this->favour -=1;
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

int Bannerman::getDamage(){
    return this->damage;
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
warTheatre* Bannerman::getWarZone(){
    return this->warZone;
}


int Bannerman::getWeapons(){
    return this->numWeapons;
}

int Bannerman::getFood(){
    return this->numFood;
}

int Bannerman::getMedical(){
    return this->numMedical;
}
void Bannerman::setWeapons(int numWeapons){
    this->numWeapons = numWeapons;
}

void Bannerman::setFood(int numFood){
    this->numFood = numFood;
}


void Bannerman::setMedical(int numMedical){
    this->numMedical = numMedical;

}