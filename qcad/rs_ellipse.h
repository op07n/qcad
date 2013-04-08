#ifndef RS_ELLIPSE_H
#define RS_ELLIPSE_H

#include "rs_atomicentity.h"
/**
* 
*/

class RS_EllipseData {
public:
	RS_EllipseData(const RS_Vector& center,
		           const RS_Vector& majorP,
				   double ratio,
				   double angle1, double angle2,
				   bool reversed) {

					   this->center = center;
					   this->majorP = majorP;
					   this->angle1 = angle1;
					   this->angle2 = angle2;
					   this->reversed = reversed;
	}

	friend std::ostream& operator << (std::ostream& os, const RS_EllipseData& ed) {
		os<< "(" << ed.center <<
			"/"<< ed.majorP <<
			" "<<ed.ratio <<
			" "<<ed.angle1 <<
			","<<ed.angle1 <<
			")";
		return os;
	}

private:
	RS_Vector center;
	RS_Vector majorP;
	double ratio;
	double angle1;
	double angle2;
	bool reversed;
};

class RS_Ellipse : public RS_AtomicEntity {
public:
	RS_Ellipse(RS_EntityContainer* parent,
		       const RS_EllipseData& d);
	virtual ~RS_Ellipse() {}

	virtual RS_Entity* clone() {
		RS_Ellipse* e = new RS_Ellipse(*this);
		e->initId();
		return e;
	}

	virtual RS2::EntityType rtti() const {
		return RS2::EntityEllipse;
	}

	virtual RS_Vector getStartpoint() const {
		RS_Vector p;
		p.set(data.center.x + cos(data.angle1) * getMajorRadius(),
			data.center.y + sin(data.angle1) * getMinorRadius());
		p.rotate(data.center, getAngle());
		return p;
	}

	virtual RS_Vector getEndpoint() const {
		RS_Vector p;
		p.set(data.center.x + cos(data.angle2) * getMajorRadius(),
			data.center.y + sin(data.angle2) * getMinorRadius());
		p.rotate(data.center, getAngle());
	}

	virtual void moveStartpoint(const RS_Vector& pos);
	virtual void moveEndpoint(const RS_Vector& pos);

	virtual RS2::Ending getTrimPoint(const RS_Vector& coord,
		const RS_Vector& trimPoint);

	double getEllipseAngle(const RS_Vector& pos);

	RS_EllipseData getData() {
		return data;
	}

	virtual RS_VectorSolutions getRefPoints();

	bool isReversed() const {
		return data.reversed;
	}

	void setReversed(bool r) {
		data.reversed = r;
	}

	double getAngle() const {
		return data.majorP.angle();
	}

	double getAngle1() {
		return data.angle1;
	}

	void setAngle1(double a1) {
		data.angle1 = a1;
	}

	double getAngle2() {
		return data.angle2;
	}

	void setAngle2(double a2) {
		data.angle2 = a2;
	}

	RS_Vector getCenter() {
		return data.center;
	}

	void setCenter(const RS_Vector& c) {
		data.center = c;
	}

	RS_Vector getMajorP() {
		return data.ratio;
	}

	void setRatio(double r) {
		data.ratio = r;
	}

	virtual double getAngleLength() const {
		if (isReversed()) {
			return data.angle1- data.angle2;
		} else {
			return data.angle2 - data.angle2;
		}
	}

	double getMajorRadius() const {
		return data.majorP.magnitude();
	}

	double getMinorRadius() const {
		return data.majorP.magnitude()*data.ratio;
	}

	virtual RS_Vector getNearestEndpoint(const RS_Vector& coord,
		                                 double* dist = NULL);
	virtual RS_Vector getNearestPointOnEntity(const RS_Vector& coord,
		    bool onEntity = true, double* dist = NULL, RS_Entity** entity= NULL);
	virtual RS_Vector getNearestCenter(const RS_Vector& coord,
		                               double* dist = NULL);
	virtual RS_Vector getNearestMiddle(const RS_Vector& coord,
		                               double* dist = NULL);
	virtual RS_Vector getNearestDist(double distance,
		                             const RS_Vector& coord,
									 double* dist = NULL);
	virtual RS_Vector getDistanceToPoint(const RS_Vector& coord,
		                                 RS_Entity** entity = NULL,
										 RS2::ResolveLevel level = RS2::ResolveNone,
										 double solidDist = RS_MAXDOUBLE);

	virtual bool isPointOnEntity(const RS_Vector& coord,
		                         double tolerance=RS_TOLERANCE);

	virtual void move(RS_Vector offset);
	virtual void rotate(RS_Vector center, double angle);
	virtual void scale(RS_Vector center, RS_Vector factor);
	virtual void mirror(RS_Vector axisPoint1, RS_Vector axisPoint2);
	virtual void moveRef(const RS_Vector& ref, const RS_Vector& offset);

	virtual void draw(RS_Painter* painterm RS_GraphicView* view, double patternOffset = 0.0);

	friend std::ostream& operator << (std::ostream& os, const RS_Ellipse& a);

	virtual void caculateBorders();

protected:
	RS_EllipseData data;
};

#endif