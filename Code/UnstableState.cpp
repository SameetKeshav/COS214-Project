#include "UnstableState.h"
using namespace std;
#include <iostream>

UnstableState::UnstableState() {
	context = nullptr;
}

void UnstableState::decreaseCurrency() {
	context->removeCurrency(10);
	if (context->getCurrency()<30)
	{
		context->SetState();
	}
}

void State::setContext(Economy* context){
	this->context=context;
}

State* UnstableState::getDemotionState(){
	State* h = new FailedState();
	h->setContext(context);
	return h;
}

string UnstableState::getState(){
	return "is Unstable";
}
