#ifndef RS_ENTITYCONTAINER_H
#define RS_ENTITYCONTAINER_H

#include "rs_arc.h"
#include "rs_circle.h"
#include "rs_ellipse.h"
#include "rs_entity.h"
#include "rs_line.h"
#include "rs_point.h"
#include "rs_ptrlist.h"

/** 
* class representing a tree of entities.
* Typical entity container are graphics, polylines, groups, texts, ...)
*
*/
class RS_EntityContainer : public RS_Entity {

public:

	RS_EntityContainer(RS_EntityContainer* parent=NULL, bool owner=true);
	//
	virtual ~RS_EntityContainer();

	virtual RS_Entity* clone();
	virtual void detach();

	/** @return RS2::EntityContainer */
	virtual RS2::EntityType rtti() const {
		return RS2::EntityContainer;
	}

	void reparent(RS_EntityContainer* parent);

	/** 
	* @return true: becasue entities made from this class and subclasses 
	* are containers for other entities.
	*/

	virtual bool isContainer() const {
		return true;
	}

	/** 
	* return false
	*/
	virtual bool isAtomic() const {
		return false;
	}



};


#endif
