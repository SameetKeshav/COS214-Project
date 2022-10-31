#ifndef WARINDICATORS_H
#define WARINDICATORS_H
#include "Treasury.h"

class WarIndicators {

protected:
	Treasury* m;

public:
	WarIndicators(){
		m=nullptr;
	}
	WarIndicators(Treasury* m){
		this->m=m;
	}
	virtual ~WarIndicators(){
		delete m;
	}
};

#endif
