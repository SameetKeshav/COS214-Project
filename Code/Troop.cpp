#include "Troop.h"

Troop::Troop(int HP, int tSize, Strategy* strategy) {
    this->HP = HP;
    this->size =tSize;
    this->strategy =strategy;
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

void Troop::receiveDamage(int X) {
    this->damage+=X;
}

Troop::~Troop() {

}