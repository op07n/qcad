#ifndef RS_ARC_H
#define RS_ARC_H

#include "rs_atomicentity.h"

class RS_ArcData {
public:
	RS_ArcData() {}

	RS_ArcData(const RS_Vector& center,
		double radius,
		double angle1, double angle2,
		bool reversed) {

			this->center = center;
			this->radius = radius;
			this->angle1 = angle1;
			this->angle2 = angle2;
			this->reversed = reversed;
	}

	void resset() {
		center = RS_Vector(false);
		radius = 0.0;
		angle1 = 0.0;
		angle2 = 0.0;
		reversed = false;	
	}

	bool isValid() {
		return (center.valid && radius > RS_TOLERANCE &&
			    fabs(angle1-angle2)> RS_TOLERANCE_ANGLE);
	}

	friend std::ostream& operator << (std::ostream& os, const RS_ArcData& ad) {
		os << "(" << ad.center <<
			"/" << ad.radius<<
			" " << ad.angle1<<
			"," << ad.angle2<<
			")";
		return os;
	}

public:
	RS_Vector center;
	double radius;
	double angle1;
	double angle2;
	bool reversed;
};