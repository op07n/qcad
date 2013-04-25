#ifndef RS_COORDINATEEVENT_H
#define RS_COORDINATEEVENT_H


/** 
* Coordinate Events.
*/
class RS_CoordinateEvent {
public:
	/** 
	* @param pos coordinate
	* @param pos abs true: absolute coordinate, false: relative coordinate
	*/
	RS_CoordinateEvent(const RS_Vector& pos) {
		this->pos = pos;
	}

	/** 
	* @return the position of the event in real graphic measures.
	*/
	RS_Vector getCoordinate() {
		return pos;
	}

protected:
	RS_Vector pos;
};
#endif