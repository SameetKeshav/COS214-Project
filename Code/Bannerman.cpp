#include "Bannerman.h"


Bannerman::Bannerman():ravenList() {

}

string Bannerman::getName() {
    return this->name;
}

WarTheatre* Bannerman::getWarZone(){
    return this->warZone;
}

Bannerman::~Bannerman() {

}