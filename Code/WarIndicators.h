#ifndef WARINDICATORS_H
#define WARINDICATORS_H
#include "Treasury.h"
class Treasury;
/** @todo An interface class for all classes that communicate 
 * with each other through Treasury mediator.
    @author Morgan Bentley
    @date October 2022
    */
class WarIndicators {

protected:
	/**Treasury mediator pointer**/
	Treasury* m;

public:
	/** @todo Default constructor. initializes m to null.
	*/
	WarIndicators(){
		m = nullptr;
	}
	/** @todo constructor. initializes m to the passed in Treasury object.
	 * @param m - mediator which is of Treasury pointer type
	*/
	WarIndicators(Treasury* m){
		this->m=m;
	}
	/** @todo sets m (Treasury mediator pointer) to the passed in Treasury pointer.
	 * @param m - mediator which is of Treasury pointer type
	*/
	void setTreasury(Treasury* m){
		this->m=m;
	}

	/** @todo destructor. deallocates Treasury pointer of this class**/
	virtual ~WarIndicators(){
		//delete m;
	}

	
};

#endif
