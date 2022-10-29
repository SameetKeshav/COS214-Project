#include "FailedState.h"

FailedState::FailedState() {
	context = nullptr;
}

void FailedState::decreaseCurrency() {
	context->removeCurrency(22);
	if (context->getCurrency()<0)
	{
		context->SetState();
	}
}

void State::setContext(Economy* context){
	this->context=context;
}

string FailedState::getState(){
	return "Has Failed";
}
