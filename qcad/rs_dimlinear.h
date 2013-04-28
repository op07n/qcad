#ifndef RS_DIMLINEAR_H
#define RS_DIMLINEAR_H

#include "rs_dimension.h"


/** 
* Holds the data that defines a lineaer dimension entity.
*/
class RS_DimLinearData {
public:
	/** 
	* Default constructor. Leaves the data object uninitialized.
	*/

	RS_DimLinearData() {}

	/** 
	* Constructor with initialisation.
	*
	* 
	* @param extensionPoint1 Startpoint of the first extension line.
	* @param extensionPoint2 Startpoint of the second extension line.
	* @param angle Rotation angle  in rad.
	* @param oblique Oblique angle in rad.
	*/
	RS_DimLinearData(const RS_Vector& extensionPoint1,
		             const RS_Vector& extensionPoint2,
					 double angle, double oblique) {
						 this->extensionPoint1 = extensionPoint1;
						 this->extensionPoint2 = extensionPoint2;
						 this->angle = angle;
						 this->oblique = oblique;
	}

	friend class RS_DimLinear;
	friend class RS_ActionDimLinear;

	friend std::ostream& operator << (std::ostream& os,
		                              const RS_DimLinearData& dd) {
										  os << "("<<dd.extensionPoint1<<"/"dd.extensionPoint2<<")";
										  return os;
	}

public:
	/** Definition point, Startpoint of the first definition line. */
	RS_Vector extensionPoint1;
	/** definition point. Startpoint of the second definition lien. */
	RS_Vector extensionPoint2;
	/** Rotation angle in rad */
	double angle;
	/** Oblique angle in rad. */
	double oblique;
};
#endif