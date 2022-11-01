#include "UnstableState.h"

UnstableState::UnstableState() {
	cout<<"Economy entered unstable state"<<endl;
	context = nullptr;
}

void UnstableState::decreaseCurrency() {
	context->removeCurrency(10);
	if (context->getCurrency()<30)
	{
		context->SetState();
	}
}

State* UnstableState::getDemotionState(){
	State* h = new FailedState();
	h->setContext(context);
	return h;
}
