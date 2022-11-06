#include "HealthyState.h"

HealthyState::HealthyState(){
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
