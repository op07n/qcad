#ifndef RS_CIRCLE_H
#define RS_CIRCLE_H

#include "rs_atomicentity.h"

/**
* 
*/

class RS_CircleData {
public:
	RS_CircleData() {}

	RS_CircleData(const RS_Vector& center,
		          double radius) {

					  this->center = center;
					  this->radius = radius;
	}

	void reset() {
		center = RS_Vector(false);
		radius = 0.0;
	}

	bool isValid() {
		return (center.valid && radius>RS_TOLERANCE);
	}

	friend class RS_Circle;

	friend std::ostream& operator << (std::ostream& os,
		                              const RS_CircleData& ad) {
             os <<"("<<ad.center <<
				 "/"<<ad.radius<<
				 ")";
			 return os;
 	}

public:
	RS_Vector center;
	double radius;
}

#endif