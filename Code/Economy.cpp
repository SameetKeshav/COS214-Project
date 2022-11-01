#include "Economy.h"

Economy::Economy(State* state,int currency) {
	cout<<"Economy constructor works"<<endl;
	state->setContext(this);
	this->state=state;
	this->currency=currency;
}

void Economy::SetState(){
	state=state->getDemotionState();
}

void Economy::decreaseCurrency(){
	state->decreaseCurrency();
}

int Economy::getCurrency(){
	return currency;
}

void Economy::removeCurrency(int i){
	currency-=i;
}

Economy::~Economy(){
	delete state;
}