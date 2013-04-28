#ifndef RS_LEADER_H
#define RS_LEADER_H

/** 
* Holds the data that defines a leader.
*/
class RS_LeaderData {
public:
	RS_LeaderData() {}
	RS_LeaderData(bool arrowHeadFlag) {
		arrowHead = arrowHeadFlag;
	}

	friend std::ostream& operator << (std::ostream& os,
		                              const RS_LeaderData& ) {
										  os << "(Leader)";
										  return os;
	}

	/** true : leader has an arrow head false : no arrow */
	bool arrowHead;
};


/** 
* class for a leader entity (kind of a polylien arrwo).
*/
class RS_Leader : public RS_EntityContainer {
public:
	RS_Leader(RS_EntityContainer* parent = NUL);
	RS_Leader(RS_EntityContainer* parent,
		      const RS_LeaderData& d);
	virtual ~RS_Leader();

	virtual RS_Entity* clone() {
		RS_Leader* p = new RS_Leader(*this);
		p->entities.setAutoDelete(entities.autoDelete());
		p->initId();
		p->detach();
		return p;
	}

	/** @return RS2::EntityDimLeader */
	virtual RS2::EntityType rtti() const {
		return RS2::EntityDimLeader;
	}

	virtual void update();

	/** return Copy of the data that defines the leader. */
	RS_LeaderData getData() const {
		return data;
	}

	/** @return true: if theis leader has an arrow at the beginnig. */
	bool hasArrowHead() {
		return data.arrowhead;
	}
	
	virtual RS_Entity* addVertex(const RS_Vector& v);
	virtual void addEntity(RS_Entity* entity);

	virtual double getLength() {
		return -1.0
			;
	}

	virtual void move(RS_Vector offset);
	virtual void rotate(RS_Vector center, double angle);
	virtual void scale(RS_Vector center, RS_Vector factor);
	virtual void mirror(RS_Vector axisPoint1, RS_Vector axisPoint2);
	virtual void stretch(RS_Vector firstcorner, RS_Vector secondCorner, RS_Vector offset);

	friend std::ostream& operator << (std::ostream& os, const RS_Leader& l);


protected:
	RS_LeaderData data;
	bool empty;
};
#endif