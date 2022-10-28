#include "UnstableState.h"

UnstableState::UnstableState(Economy* context):State(context) {
}

void UnstableState::decreaseCurrency() {
	context->removeCurrency(10);
	if (context->getCurrency()<30)
	{
		context->SetState();
	}
}

State* UnstableState::getDemotionState(){
	return new FailedState(context);
}
