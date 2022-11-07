#include "FailedState.h"

FailedState::FailedState() {
	context = nullptr;
}

void FailedState::decreaseCurrency() {
	cout<<"State is bankrupt, cannot decrease currency"<<endl;	
}

string FailedState::getState(){
	return "has failed";
}
