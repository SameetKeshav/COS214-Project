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
    damage = 12;
    this->assassin = assassin;
}
int Troop::getHP() {
    return this->HP;
}

void Troop::attach(Raven* o){
    this->ravenList.push_back(o);
}

void Troop::detach(Raven* o){
    this->ravenList.remove(o);
}

void Troop::increasePower(int boost){
    this->damage+= boost;
}

int Troop::getSize() {
    return this->size;
}
void Troop::attack(Bannerman* myBannerman, Bannerman* enemyBannerman){
    strategy->attack(myBannerman,enemyBannerman);
}

string Troop::getName() {
    return  name;
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

int Troop::getFavour(){
    return favour;
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
    this->HP-=X;
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

void Troop::setRaven(list<Raven*> r){
    this->ravenList = r;
}
void Troop::setMaster(MasterOfCoin* m){
    this->m = m;
}

void Troop::decreasePower(int x){
    this->damage -= x;
}
Troop::~Troop() {

}

list<Bannerman*> Troop::getTroops(){
    list<Bannerman*> empty;
    return empty;
}