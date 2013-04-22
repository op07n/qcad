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

	virtual double getLength();

	virtual void undoStateChanged(bool undone);
	virtual void setVisible(bool v);

	virtual bool selectWindow(RS_Vector v1, RS_Vector v2,
		bool select=true, bool cross=false);

	virtual void addEntity(RS_Entity* entity);
	virtual void insertEntity(int index, RS_Entity* entity);
	virtual void replaceEntity(int index, RS_Entity* entity);
	virtual bool removeEntity(RS_Entity* entity);
	virtual RS_Entity* firstEntity(RS2::ResolveLevel level=RS2::ResolveNone);
	virtual RS_Entity* lastEntity(RS2::ResolveLevel level=RS2::ResolveNone);
	virtual RS_Entity* nextEntity(RS2::ResolveLevel level=RS2::ResolveNone);
	virtual RS_Entity* prevEntity(RS2::ResolveLevel level=RS2::ResolveNone);
	virtual RS_Entity* EntityAt(uint index);
	virtual RS_Entity* currentEntity();
	virtual int entityAt();
	virtual int findEntity(RS_Entity* entity);
	virtual void clear();

	RS_PtrListIterator<RS_Entity> createIterator();

	//virtual unsigned long int count() {
    //	return count(false);
    //}
	virtual bool IsEmpty() {
		return count()==0;
	}
	virtual unsigned long int count();
	virtual unsigned long int countDeep();
	//virtual unsigned long int countLayerEntities(RS_Layer* layer);
	virtual unsigned long int countSelected();

	/** 
	* Enable / Disable automatic update of borders on entity removals
	* and additions. By default this is turened on.
	*/
	virtual void setAutoUpdateBorders(bool enable) {
		autoUpdateBorders = enable;
	}
	virtual void adjustBorders(RS_Entity* entity);
	virtual void calculateBorders();
	virtual void forcedCalculateBorders();
	virtual void updateDimensions();
	virtual void updateInserts();
	virtual void updateSplines();
	virtual void update();
	virtual void renameInserts(const RS_String& oldName,
		const RS_String& newName);

	virtual RS_Vector getNearestEndPoint(const RS_Vector& coord, 
		                                 double* dist  = NULL);

	RS_Entity* getNearestEntity(const RS_Vector& point,
		                        double* dist = NULL,
								RS2::ResolveLevel level=RS2::ResolveAll);

	virtual RS_Vector getNearestPointOnEntity(const RS_Vector&, 
		bool onEntity = true, 
		double* dist = NULL, 
		RS_Entity** entity = NULL);

	virtual RS_Vector getNearestCenter(const RS_Vector& coord, 
		                               double* dist = NULL);
	virtual RS_Vector getNearestMiddle(const RS_Vector& coord, 
		                               double* dist = NULL);
	virtual RS_Vector getNearestDist(double distance, 
		                             const RS_Vector& coord, 
		                             double* dist  = NULL);
	virtual RS_Vector getNearestIntersection(const RS_Vector& coord,
		    double* dist = NULL);
	virtual RS_Vector getNearestRef(const RS_Vector& coord, 
		                            double* dist = NULL);
	virtual RS_Vector getNearestSelectedRef(const RS_Vector& coord, 
		                                    double* dist = NULL);

	virtual double getDistanceToPoint(const RS_Vector& coord, 
		RS_Entity** entity  = NULL , 
		RS2::ResolveLevel level  = RS2::ResolveNone , 
		double solidDist = RS_MAXDOUBLE );

	virtual bool optimizeContours();

	virtual bool hasEndPointsWithinWindow(RS_Vector v1, RS_Vector v2);

	virtual void move(RS_Vector offset);
	virtual void rotate(RS_Vector center, double angle);
	virtual void scale(RS_Vector center, RS_Vector factor);
	virtual void mirror(RS_Vector axisPoint1, RS_Vector axisPoint2);

	virtual void stretch(RS_Vector firstcorner, 
		RS_Vector secondCorner, 
		RS_Vector offset);
	virtual void moveRef(const RS_Vector& ref, const RS_Vector& offset);
	virtual void moveSelectedRef(const RS_Vector& ref, const RS_Vector& offset);

	virtual void draw(RS_Painter* painter, 
		RS_GraphicView* view, 
		double patternOffset  = 0.0 );

	friend std::ostream& operator << (std::ostream& os, RS_EntityContainer& ec);

protected:

	/** entities in the container */
	RS_PtrList<RS_Entity> entities;

	/** sub container used only temporarly for iteration. */
	RS_EntityContainer* subContainer;

	/** 
	* Automatically update the borders of the container when entities
	* are added or removed.
	*/
	static bool autoUpdateBorders;
};


#endif
