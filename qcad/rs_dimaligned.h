#ifndef RS_DIMALIGNED_H
#define RS_DIMALIGNED_H

#include "rs_dimension.h"

/** 
* Holds the data that defines an aligned dimension entity.
*/

class RS_DimAlignedData {
public:
	/** 
	* Default constructor. Leaves the data object uninitialized.
	*/
	RS_DimAlignedData() {}

	/** 
	* Constructor with initialisation.
	*
	   * @para extensionPoint1 definition point. Startpoint of the 
	*          first extension line.
	   * @para extensionPoint2 definition point. Startpoint of the
	*          second extension line.
	*/
	RS_DimAlignedData(const RS_Vector& extensionPoint1,
		              const RS_Vector& extensionPoint2) {
						  this->extensionPoint1 = extensionPoint1;
						  this->extensionPoint2 = extensionPoint2;
	}

private:
	/** definition point, Startpoint of the first extension line, */
	RS_Vector extensionPoint1;
	/** definition point, Startpoint of the second extension line, */
	RS_Vector extensionPoint2;
};

#endif