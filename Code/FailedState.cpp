#include "FailedState.h"

FailedState::FailedState() {
	cout<<"Economy is a failed state"<<endl;
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
