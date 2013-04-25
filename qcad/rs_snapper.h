#ifndef RS_SNAPPER_H
#define RS_SNAPPER_H

#include "rs_entitycontainer.h"

#include "rs.h"
#include "rs_mouseevent.h"
#include "rs_coordinateevent.h"

class RS_Entity;
class RS_GraphicView;
class RS_Vector;
class RS_Preview;

/** 
* This class is used fro snapping function in a graphic view.
* Actions are usually derived from this base class if they need 
* to catch entities or snap to coordinates. Use the methods to 
* receive a graphic coordinate from a mouse coordinate.
* 
* Possible snaping functions are described in RS_SnapMode.
* 
*/
class RS_Sanpper {
public:
	RS_Sanpper(RS_EntityContainer& container, RS_GraphicView& graphicView);
	virtual ~RS_Sanpper();

	void init();
	void finish();

	/** 
	* @return Pointer to the entity which was the key entity for the
	* last successful snapping action, If the snap mode is "end point"
	* the key entity is the entity whos end point was caught.
	* If the snap mode didn't require an entity (e.g. free, grid) this
	* method will return NULL.
	*/
	RS_Entity* getKeyEntity() {
		return keyEntity;
	}

	/** Sets a new snap mode. */
	void setSnapMode(RS2::SnapMode snapMode) {
		this->setSnapMode = snapMode;
	}
	/** Sets a new snap restriction. */
	void setSnapRestriction(RS2::SnapRestriction snapRes) {
		this->snapRes = snapRes;
	}

	/**
	* Sets the snap range in pixels for catchEntity().
	*
	* @see catchEntity()
	*/
	void setRange(int r) {
		snapRange = r;
	}

	RS_Vector snapPoint(RS_MouseEvent* e);

	RS_Vector snapFree(RS_Vector coord);
	RS_Vector snapEndpoint(RS_Vector coord);
	RS_Vector snapGrid(RS_Vector coord);
	RS_Vector snapOnEntity(RS_Vector coord);
	RS_Vector snapCenter(RS_Vector coord);
	RS_Vector snapMiddle(RS_Vector coord);
	RS_Vector snapDist(RS_Vector coord);
	RS_Vector snapIntersection(RS_Vector coord);
	//RS_Vector snapDirect(RS_Vector coord, bool abs);

	RS_Vector restrictOrthogonal(RS_Vector coord);
	RS_Vector restrictHorizontal(RS_Vector coord);
	RS_Vector restrictVertical(RS_Vector coord);

	//
	//
	RS_Entity* catchEntity(const RS_Vector& pos,
		                   RS2::ResolveLevel level=RS2::ResolveNone);
	RS_Entity* catchEntity(RS_MouseEvent* e,
		                   RS2::ResolveLevel level=RS2::ResolveNone);

	/** 
	* Suspends this snapper while another action takes place.
	*/
	virtual void suspend() {
		deleteSnapper();
		snapSpot = snapCoord = RS_Vector(false);
	}

	/** 
	* Resumes this snapper after it has been suspended.
	*/
	virtual void resume() {
		drawSnapper();
	}

	virtual void hideOptions();
	virtual void showOptions();

	void drawSnapper();
	void deleteSnapper();

private:
	void xorSnapper();

protected:
	RS_EntityContainer* container;
	RS_GraphicView* graphicView;
	RS_Entity* keyEntity;
	RS_Vector snapCoord;
	RS_Vector snapSpot;
	RS2::SnapMode snapMode;
	RS2::SnapRestriction snapRes;
	/** 
	* Snap distance for snaping to points with a
	* given distance form endpoints.
	*/
	double distance;
	/** 
	* Keeps tracks of the drawing in XOR mode.
	*/
	bool visible;
	/** 
	* Snap range for catching entities.
	*/
	int snapRange;
	/** 
	* Show large cross hairs.
	*/
	bool showCrosshairs;
	bool finished;
};



#endif