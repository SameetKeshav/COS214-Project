#include "Economy.h"

Economy::Economy(State* state,int currency) {
	this->state=state;
	this->currency=currency;
}

void Economy::SetState(){
	state=state->getDemotionState();
}

void Economy::decreaseCurrency(){
	state->decreaseCurrency();
}

int getCurrency(){
	return currency;
}

void removeCurrency(int i){
	currency-=i;
}

Economy::~Economy(){
	delete state;
}