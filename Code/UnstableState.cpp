#include "UnstableState.h"

UnstableState::UnstableState() {
	context = nullptr;
}

void UnstableState::decreaseCurrency() {
	context->removeCurrency(25);
	if (context->getCurrency()<0)
	{
		context->SetState();
	}
}

State* UnstableState::getDemotionState(){
	State* h = new FailedState();
	h->setContext(context);
	return h;
}

string UnstableState::getState(){
	return "is unstable";
}
