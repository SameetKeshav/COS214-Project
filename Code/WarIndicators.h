#ifndef WARINDICATORS_H
#define WARINDICATORS_H
#include "Treasury.h"

class Treasury;
/** @brief An interface class for all classes that communicate 
 * with each other through Treasury mediator.
    @author Morgan Bentley
    @date October 2022
    */
class WarIndicators {

protected:
	/**Treasury mediator pointer**/
	Treasury* m;

public:
	/** @brief Default constructor. initializes m to null.
	*/
	WarIndicators(){
		m = nullptr;
	}

	/** @brief constructor. initializes m to the passed in Treasury object.
	 * @param m - mediator which is of Treasury pointer type
	*/
	WarIndicators(Treasury* m){
		this->m=m;
	}

	/** @todo destructor. deallocates Treasury pointer of this class**/
	virtual ~WarIndicators(){
		//delete m;
	}
};

#endif
