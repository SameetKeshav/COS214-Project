#include "Troop.h"

Troop::Troop(string name, int favor, int numFood, int Medical, int HP,WarTheatre*warZone,Strategy*strategy,MasterOfCoin* m, bool assassin, int size): Bannerman(){

    this->size = size;

    this->name =name;
    this->favour =favor;
    this->numFood =numFood;
    this->numMedical =Medical;
    this->HP =HP;
    this->warZone =warZone;
    this->strategy =strategy;
    this->m =m;

    this->assassin = assassin;
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

void Troop::increaseHP(int boost){
    this->HP += boost;
}

void Troop::changeStrategy(Strategy* strategy){
    this->strategy = strategy;
}

int Troop::getDamage(){
    return this->damage;
}

void Troop::increaseFavour() {
    this->favour +=1;
}

void Troop::decreaseFavour() {
    this->favour -=1;
}

void Troop::decreaseWeapons(){
    this->numWeapons-=1;
}
void Troop::decreaseFood(){
    this->numFood-=1;
}
void Troop::decreaseMedical(){
    this->numMedical-=1;
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