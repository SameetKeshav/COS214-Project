#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator {


public:
	virtual bool hasNext() = 0;

	virtual Bannerman* next() = 0;

	virtual bool isActive() = 0;
};

#endif
