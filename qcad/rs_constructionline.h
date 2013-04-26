#ifndef RS_CONSTRUCTIONLINE_H
#define RS_CONSTRUCTIONLINE_H

#include "rs_atomicentity.h"
#include "rs_vector.h"


/**
* Holds the data that defined a construction line( a lien
* which is not limited to both directions).
*/
class RS_ConstructionLineData {
public:
	/** 
	* Default constructor. Leave the data obect uninitialized.
	*/
	RS_ConstructionLineData() {}

	RS_ConstructionLineData(const RS_Vector& point1,
		                    const RS_Vector& point2) {
								
								this->point1= point1;
								this->point2 = point2;
	}

	friend class RS_ConstructionLine;

	friend std::ostream& operator << (std::ostream& os, const RS_ConstructionLineData& ld) {

		os << "(" << ld.point1 <<
			"/" <<ld.point2 <<
			")";
			return os;
	}


private:
	RS_Vector point1;
	RS_Vector point2;
};

/** 
* Class for a construction lien entity.
*/

class RS_ConstructionLine : public RS_AtomicEntity {
public:
	RS_ConstructionLine(RS_EntityContainer* parent,
		                const RS_ConstructionLineData& d);

	virtual RS_Entity* clone();

	virtual ~RS_ConstructionLine();

	/** @return RS2::EntityConstructionLine */
	virtual RS2::EntityType rtti() const {
		return RS2::EntityConstructionLine;
	}

	/** 
	* @todo 
	* @return Start point of the entity.
	*/
	virtual RS_Vector getStartpoint() const {
		return RS_Vector(false);
	}

	/** 
	* @todo 
	* @return End point of the entity.
	*/
	virtual RS_Vector getEndpoint() const {
		return RS_Vector(false);
	}

	/** @ return Copy of data that defines the lien.*/
	RS_ConstructionLineData getData() const {
		return data;
	}

	/** @return First defination point. */
	RS_Vector getPoint1() const {
		return data.point1;
	}

	RS_Vector getPoint2() const {
		return data.point2;
	}

	virtual RS_Vector getNearestEndPoint(const RS_Vector& coord, 
		                                 double* dist = NULL);
	virtual RS_Vector getNearestPointOnEntity(const RS_Vector& coord, 
		bool onEntity = true, double* dist  = NULL, RS_Entity** entity  = NULL);
	virtual RS_Vector getNearestCenter(const RS_Vector& coord,
		                               double* dist = NULL);
	virtual RS_Vector getNearestMiddle(const RS_Vector& coord, 
		                               double* dist = NULL);
	virtual RS_Vector getNearestDist(double distance, 
		                             const RS_Vector& coord, 
		                             double* dist = NULL);

	virtual double getDistanceToPoint(const RS_Vector& coord, 
		RS_Entity** entity = NULL, 
		RS2::ResolveLevel level  = RS2::ResolveNone, 
		double solidDist = RS_MAXDOUBLE);

	virtual void move(RS_Vector offset);
	virtual void rotate(RS_Vector center, double angle);
	virtual void scale(RS_Vector center, RS_Vector factor);
	virtual void mirror(RS_Vector axisPoint1, RS_Vector axisPoint2);

	virtual void draw(RS_Painter* /*painter*/, RS_GraphicView* /*view*/, 
		double /*patternOffset */ );

	friend std::ostream& operator << (std::ostream& os,
		const RS_ConstructionLine& l);

	virtual void calculateBorders();


protected:
	RS_ConstructionLineData data;
};

#endif