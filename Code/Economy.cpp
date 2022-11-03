#include "Economy.h"

Economy::Economy(State* state,int currency) {
	state->setContext(this);
	this->state=state;
	this->currency=currency;
}

void Economy::SetState(){
	state=state->getDemotionState();
}

State* Economy::getState(){
	return state;
}

void Economy::decreaseCurrency(){
	state->decreaseCurrency();
	if (currency>0)
	{
		m->notify(this);
	}
	
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