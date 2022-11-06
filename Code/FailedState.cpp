#include "FailedState.h"

FailedState::FailedState() {
	context = nullptr;
}

void FailedState::decreaseCurrency() {
	//cout<<"State is bankrupt, out of funds"<<endl;	
}

string FailedState::getState(){
	return "has failed";
}
