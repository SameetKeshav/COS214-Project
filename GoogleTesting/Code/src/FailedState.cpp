#include "FailedState.h"

FailedState::FailedState() {
	context = nullptr;
}

void FailedState::decreaseCurrency() {
	context->removeCurrency(22);	
}

string FailedState::getState(){
	return "has failed";
}
