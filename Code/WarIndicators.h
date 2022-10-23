#ifndef WARINDICATORS_H
#define WARINDICATORS_H

class WarIndicators {

protected:
	Treasury* m;

public:
	WarIndicators(Treasury* m){
		this->m=m;
	}
	virtual ~WarIndicators(){
		delete m;
	}
};

#endif
