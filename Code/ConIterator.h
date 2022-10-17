#ifndef CONITERATOR_H
#define CONITERATOR_H

class ConIterator : Iterator {


public:
	Bannerman* next();

	bool hasNext();

	bool isActive();
};

#endif
