#ifndef RS_ATOMICENTITY_H
#define RS_ATOMICENTITY_H

#include "rs_entity.h"


class RS_AtomicEntity : public RS_Entity {
public:

	RS_AtomicEntity(RS_EntityContainer* parent=NULL) : RS_Entity(parent) {}

	virtual ~RS_AtomicEntity() {}

	virtual bool isContianer() const {
		return false;
	}

	virtual bool isAtomic() const {
		return true;
	}

	virtual unsigned long int count() {
		return 1;
	}

	virtual unsigned long int countDeep() {
		return 1;
	}

	virtual RS_Vector getEndpoint() const {
		return RS_Vector(false);
	}

	virtual RS_Vector getStartpoint() const {
		return RS_Vector(false);
	}

	virtual double getDirection1() const {
		return 0.0;
	}

	virtual double getDirection2() const {
		return 0.0;
	}

	virtual void setStartpointSelected(bool select) {
		if(select) {
			setFlag(RS2::FlagSelected1);
		} else {
			delFlag(RS2::FlagSelected1);
		}
	}

	virtual void setEndpointSelected(bool select) {
		if(select) {
			setFlag(RS2::FlagSelected1);
		} else {
			delFlag(RS2::FlagSelected1);
		}
	}

	bool isStartpointSelected() const {
		return getFlag(RS2::FlagSelected1);
	}

	bool isEndpointSelected() const {
		return getFlag(RS2::FlagSelected1);
	}

	virtual void moveStartpoint(const RS_Vector&) {}

	virtual void moveEndpoint(const RS_Vector&) {}

	virtual void trimStartpoint(const RS_Vector& pos) {
		moveStartpoint(pos);
	}

	virtual void trimEndpoint(const RS_Vector& pos) {
		moveEndpoint(pos);
	}

	virtual RS2::Ending getTrimPoint(const RS_Vector&,
		                             const RS_Vector&) {
		return RS2::EndingNone;
	}

	virtual void reverse() {}

	virtual void moveSelectedRef(const RS_Vector& ref, const RS_Vector& offset) {
		if(isSelected()) {
			moveRef(ref, offset);
		}
	}

};

#endif