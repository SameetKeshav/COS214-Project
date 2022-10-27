#include "Troop.h"

Troop::Troop(string name, int favor, int numFood, int Medical, int HP,int size,WarTheatre*warZone,Strategy*strategy,MasterOfCoin* m): Bannerman(name,favor,numFood,Medical,HP,warZone,strategy,m){
    this->size = size;
}
int Troop::getHP() {
    return this->HP;
}

int Troop::getSize() {
    return this->size;
}

void Troop::attackKingdom(Kingdom* X) {
    // TODO - implement Troop::attackKingdom
    throw "Not yet implemented";
}

string Troop::getName(){
    return this->name;
}

void Troop::receiveDamage(int X) {
    this->damage+=X;
}
void Troop::setWeapons(int numWeapons){
    this->numWeapons  = numWeapons;
}

void Troop::setFood(int numFood){
    this->numFood = numFood;
}

void Troop::setMedical(int numMedical){
    this->numMedical = numMedical;
}

int Troop::getWeapons(){
    return this->numWeapons;
}

int Troop::getFood(){
    return this->numFood;
}

int Troop::getMedical(){
    return this->numMedical;
}

Troop::~Troop() {

}