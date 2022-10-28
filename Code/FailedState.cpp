#include "FailedState.h"

FailedState::FailedState(Economy* context):State(context) {
}

void FailedState::decreaseCurrency() {
	context->removeCurrency(22);
	if (context->getCurrency()<0)
	{
		context->SetState();
	}
}

