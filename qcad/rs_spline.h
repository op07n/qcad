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

	/** @return Copy of data that defines the spline */
	RS_SplineData  getData() const {
		return data;
	}

	/** Sets the splines degree (1-3) */
	void setDegree(int deg) {
		if(deg>=1 && deg<=3) {
			data.degree = deg;
		}

	}

	/** @return Degree of this spline curve (1-3) */
	int getDegree() {
		return data.degree;
	}

	/** @return 0. */
	int getNumberOfKnots() {
		return data.controlPoints.count();
	}

	/** 
	* @return true if the spline is closed.
	* @return false otherwise.
	*/
	bool isClosed() {
		return data.closed;
	}

	/** 
	* Sets the closed flag ot this spline
	*/
	void setClosed(bool c) {
		data.closed = c;
	}
	virtual RS_VectorSolutions getRefPoints();
	virtual RS_Vector getNearestRef(const RS_Vector& coord, 
		double* dist  = NULL );
	virtual RS_Vector getNearestSelectedRef(const RS_Vector& coord,
		                           double* dist = NULL);

	//
	//
	//
	//

	void update();


	virtual RS_Vector getNearestEndPoint(const RS_Vector& coord, 
		                                 double* dist = NULL );
	//
	virtual RS_Vector getNearestCenter(const RS_Vector& coord,
		double* dist  = NULL );
	virtual RS_Vector getNearestMiddle(const RS_Vector& coord,
		double* dist  = NULL);
	virtual RS_Vector getNearestDist(double distance, 
		const RS_Vector& coord, double* dist  = NULL);

	virtual void addControlPoint(const RS_Vector& v);
	virtual void removeLastControlPoint();

	virtual void move(RS_Vector offset);
	virtual void rotate(RS_Vector center, double angle);
	virtual void scale(RS_Vector center, RS_Vector factor);
	virtual void mirror(RS_Vector axisPoint1, RS_Vector axisPoint2);
	virtual void moveRef(const RS_Vector& ref, const RS_Vector& offset);

	virtual void draw(RS_Painter* painter, RS_GraphicView* view, double patternOffset = 0.0);
	RS_ValueList<RS_Vector> getControlPoints();

	friend std::ostream& operator << (std::ostream& os, const RS_Spline& l);

	virtual void calculateBorders();

	static void rbasis(int c, double t, int npts, int x[], double h[], double r[]);

	static void knot(int num, int order, int knotVector[]);
	static void rbsplinu(int npts, int k, int p1,
		double b[], double h[], double p[]);;

protected:
	RS_SplineData data;
};

#endif 