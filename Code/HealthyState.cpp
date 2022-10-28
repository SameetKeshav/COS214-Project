#include "HealthyState.h"

HealthyState::HealthyState(Economy* context):State(context) {

}

void HealthyState::decreaseCurrency() {
	context->removeCurrency(5);
	if (context->getCurrency()<50)
	{
		context->SetState();
	}
}

State* HealthyState::getDemotionState(){
	return new UnstableState(context);
}
