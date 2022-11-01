#include "HealthyState.h"

HealthyState::HealthyState(){
	cout<<"Economy entered healthy state"<<endl;
	context = nullptr;
}

void HealthyState::decreaseCurrency() {
	context->removeCurrency(5);
	if (context->getCurrency()<50)
	{
		context->SetState();
	}
}

State* HealthyState::getDemotionState(){
	State* h = new UnstableState();
	h->setContext(context);
	return h;
}

string HealthyState::getState(){
	return "is healthy";
}
