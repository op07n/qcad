#ifndef RS_LINE_H
#define RS_LINE_H

#include "rs_atomicentity.h"

/** 
* Holds the data that defines a line 
*/
class RS_LineData {
public:
	/** 
	* Default constructor. Leaves the data object uninitialized
	*/
	RS_LineData() {}

	RS_LineData(const RS_Vector& startpoint,
		        const RS_Vector& endpoint) {
					this->startpoint = startpoint;
					this->endpoint = endpoint;
	}

	friend class RS_Line;
	friend class RS_ActionDrawLine;

	friend std::ostream& operator << (std::ostream& os, const RS_LineData& ld) {
		os << "(" << ld.startpoint <<
			"/" << ld.endpoint <<
			")";
		return os;
	}

public:
	RS_Vector startpoint;
	RS_Vector endpoint;
};

/** 
* class for a line entity
*
*/
class RS_Line : public RS_AtomicEntity {
public:
	//
	//
	RS_Line(RS_EntityContainer* parent,
		    const RS_LineData& d);

	virtual RS_Entity* clone();
	/*{
	   }
	   */

	virtual ~RS_Line();

	/** @return RS2::EntityLine */
	virtual RS2::EntityType rtti() const {
		return RS2::EntityLine;
	}
	/** @retrun true */
	virtual bool isEdge() const {
		return true;
	}

	/** @return Copy of data thate defines the line. */
	RS_LineData getData() const {
		return data;
	}
	virtual RS_VectorSolutions getRefPoints();

	/** @ return the startpoint of the entity */
	virtual RS_Vector getStartpoint() const {
		return data.startpoint;
	}
	/** @return the endpoint of the entiry */
	virtual RS_Vector getEndpoint() const {
		return data.endpoint;
	}
	/** Sets the startpoint */
	void setStartpoint(RS_Vector s) {
		data.startpoint = s;
		caculateBorders();
	}
	/** Sets the endpoint */
	void setEndpoint(RS_Vector e) {
		data.endpoint = e;
        calculateBorders();
	}
	/** 
	* @return Direction 1. The angle at which the line starts at
	* the startpoint.
	*/
	double getDirection1() const {
		return getAngle1();
	}
	/** 
	* @return Direction 2. The angle at which the line starts at
	* the endpoint.
	*/
	double getDirection2() const {
		return getAngle2();
	}
	virtual void moveStartpoint(const RS_Vector& pos);
	virtual void moveEndpoint(const RS_Vector& pos);
	virtual RS2::Ending getTrimPoint(const RS_Vector& coord, 
		const RS_Vector& trimPoint);
	virtual void reverse();
	RS_Vector getMiddlepoint() {
		return (data.startpoint + data.endpoint)/2.0;
	}
	/** Sets the y coordinate of the startpoint */
	void setStartpointY(double val) {
		data.startpoint.y = val;
		calculateBorders();
	}
	/** Sets the y coordinate of the endpoint */
	void setEndpointY(double val) {
		data.endpoint.y = val;
		calculateBorders();
	}
	virtual bool hasEndpointWithinWindow(RS_Vector v1, RS_Vector v2);

	/** 
	* @return The length of the line.
	*/
	virtual double getLength() {
		return data.startpoint.distanceTo(data.endpoint);
	}

	/** 
	* @return The angle of the line (from start to endpoint).
	*/
	virtual double getAngle1() const {
		return data.startpoint.angleTo(data.endpoint);
	}
	/** 
	* @return The angle of the line (from end to startpoint).
	*/
	virtual double getAngle2() const {
		return data.endpoint.angleTo(data.startpoint);
	}
protected:
	RS_LineData data;
};