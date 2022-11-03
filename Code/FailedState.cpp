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

string FailedState::getState(){
	return "has failed";
}
