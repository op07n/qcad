#ifndef RS_DIMRADIAL_H
#define RS_DIMRADIAL_H

#include "rs_dimension.h"

/** 
* Holds the data that defines a radial dimension entity.
*/
class RS_DimRadialData {
public:
	/** 
	* default constructor. Leaves the data object uninitialized.
	*/
	RS_DimRadialData() {}

	/** 
	* Constructor with initialisation.
	* @param definitionPoint Definition point of the radial dimension
	* @param leader Leader length.
	*/
	RS_DimRadialData(const RS_Vector& definitionPoint,
		             double leader) {
						 this->definitionPoint = definitionPoint;
						 this->leader = leader;
	}

	friend class RS_DimRadial;
	//

	friend std::ostream& operator << (std::ostream& os,
		                               const RS_DimRadialData& dd) {
	       os<< "(" << dd.definitionPoint << "/"<<dd.leader<<")";
		   return os;
	}

public:
	/** Definnition point */
	RS_Vector definitionPoint;
	/** Leader length */
	double leader;
};
#endif