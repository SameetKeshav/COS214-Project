#include "State.h"

State::State(){

}

void State::setContext(Economy* context){
	this->context=context;
}

State* State::getDemotionState(){
	return nullptr;
}

State::~State(){
	delete context;
}
