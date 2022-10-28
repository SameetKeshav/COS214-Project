#include "State.h"

State::State(Economy* context){
	this->context=context;
}

State* State::getDemotionState(){
	return nullptr;
}

State::~State(){
	delete context;
}
