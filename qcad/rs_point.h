#ifndef RS_POINT_H
#define RS_POINT_H

#include "rs_atomicentity.h"


/** 
* Holds the data that defines a point
*/

class RS_PointData {
public:
	RS_PointData(const RS_Vector& pos) {
		this->pos = pos;
	}

	friend std::ostream& operator << (std::ostream& os, const RS_PointData& pd) {
		os << "("<< pd.pos << ")";
		return os;
	}

	RS_Vector pos;
};

/** 
* Class for a point entry.
* 
*
*/
class RS_Point : public RS_AtomicEntity {
public:
	RS_Point(RS_EntityContainer* parent,
		     const RS_PointData& d);

	virtual RS_Entity* clone() {
		RS_Point* p = new RS_Point(*this);
		p->initId();
		return p;
	}

	/**  */
	virtual RS2::EntityType rtti() const {
		return RS2::EntityPoint;
	}

	/** 
	* start point
	*/
	virtual RS_Vector getStartpoint() const {
		return data.pos;
	}
	/** 
	* end point
	*/
	virtual RS_Vector getEndpoint() const {
		return data.pos;
	}

	virtual void moveStartpoint(const RS_Vector& pos);

	/** @return Copy of data that defines the point */
	RS_PointData getData() const {
		return data;
	}

	virtual RS_VectorSolutions getRefPoints();

	/** @return Position of the point */
	RS_Vector getPos() {
		return data.pos;
	}

	/** Sets a new position for this point. */
	void setPos(const RS_Vector& pos) {
		data.pos = pos;
	}

	virtual RS_Vector getNearestEndPoint(const RS_Vector& coord,
		                                 double* list = NULL);
	virtual RS_Vector getNeatestPointOnEntity(const RS_Vector& coord,
		    bool onEntity = true, double* dist = NULL, RS_Entity** entity = NULL);
	virtual RS_Vector getNearestCenter(const RS_Vector& coord,
		                               double* dist = NULL);
	virtual RS_Vector getNearestMiddle(const RS_Vector& coord, 
		                               double* dist = NULL);
	virtual RS_Vector getNearestDist(double distance, 
		                             const RS_Vector& coord, 
		                             double* dist /* = NULL */);
	virtual RS_Vector getDistanceToPoint(const RS_Vector& coord,
	                                     RS_Entity** entity=NULL,
										 RS2::ResolveLevel level=RS2::ResolveNone,
										 double solidDist = RS_MAXDOUBLE);

	virtual void move(RS_Vector offset);
	virtual void rotate(RS_Vector center, double angle);
	virtual void scale(RS_Vector center, RS_Vector factor);
	virtual void mirror(RS_Vector axisPoint1, RS_Vector axisPoint2);

	virtual void draw(RS_Painter* painter, RS_GraphicView* view, double patternOffset = 0.0);

	friend std::ostream& operator <<  (std::ostream& os, const RS_Point& p);

	/** Recaculation the borders of this entity */
	virtual void caculateBorders ();

protected:
	RS_PointData data;
}
;

#endif