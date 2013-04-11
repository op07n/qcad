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
class RS_line : public RS_AtomicEntity {
public:
	//
	//
	RS_Line(RS_EntityContainer* parent,
		    const RS_LineData& d);
};