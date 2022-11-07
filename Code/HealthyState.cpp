#include "HealthyState.h"

HealthyState::HealthyState(){
	context = nullptr;
}

void HealthyState::decreaseCurrency() {
	context->removeCurrency(25);
	if (context->getCurrency()<60)
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
