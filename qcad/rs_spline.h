#ifndef RS_SPLINE_H
#define RS_SPLINE_H


#include "rs_entitycontainer.h"
#include "rs_valuelist.h"

/** 
* Holds the data defines a line.
*/
class RS_SplineData {
public:
	/** 
	* Default constructor Leaves the data object uninitialized
	*/
	RS_SplineData() {}

	RS_SplineData(int degree, bool closed) {
		this->degree = degree;
		this->closed = closed;
	}
	

	friend std::ostream& operator <<(std::ostream& os, const RS_SplineData& ld) {
		os << " ( degree: " << ld.degree <<
			" closed: " << ld.closed <<
			")";
		return os;
	}
public:
	/** Degree of the spline (1,2,3) */
	int degree;
	/** Closed flag */
	bool closed;
	/** Control points of the spline */
	RS_ValueList<RS_Vector> controlPoints;
};


/*
* CLass for a spline entity.
*/

class RS_Spline : public RS_EntityContainer {
public:
	RS_Spline(RS_EntityContainer* parent,
		      const RS_SplineData& d);

    virtual RS_Entity* clone();

	virtual ~RS_Spline();

	/** @return RS2::EntitySpline */
	virtual RS2::EntityType rtti() const {
		return RS2::EntitySpline;
	}

	/** @return false */
	virtual bool isEdge() const {
		return false;
	}

	/** @return false */
	virtual bool isEdge() const {
		return false;
	}

	/** @return Copy of data that defines the spline */

};