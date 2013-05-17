#include "rs_entity.h"

#include <iostream>

#include "rs_arc.h"
#include "rs_circle.h"
#include "rs_debug.h"
#include "rs_document.h"
#include "rs_ellipse.h"
#include "rs_graphic.h"
#include "rs_graphicview.h"
#include "rs_insert.h"
#include "rs_layer.h"
#include "rs_line.h"
#include "rs_painter.h"
#include "rs_point.h"
#include "rs_polyline.h"
#include "rs_text.h"
#include "rs_stringlist.h"

/** 
* Default constructor.
* @param parent The parent entity of this entity
*               E.g. a line might have a graphic entity or
*               a polyline entity as parent.
*/
RS_Entity::RS_Entity(RS_EntityContainer* parent) {

	this->parent = parent;
	init();
}

/**
* Copy constructor.
*/

/** 
* Destructor.
*/
RS_Entity::~RS_Entity() {}



/** 
* Initialisation. Called from all constructors.
*/
void RS_Entity::init() {
    resetBorders();

	setFlags(RS2::FlagVisible);
	//
	//
	updateEnabled = true;
	setLayerToActive();
	initId();
}

/** 
* Give this entity a new unique id.
*/
void RS_Entity::initId() {
	static unsigned long int idCounter=0;
	id = idCounter++;
}

/** 
* Reset the borders of this element.
*/
void RS_Entity::resetBorders() {
	//
	double maxd = RS_MAXDOUBLE;
	double mind = RS_MINDOUBLE;

	minV.set(maxd, maxd, maxd);
	maxV.set(mind, mind, mind);
}



/** 
* Selects or deselects this entity.
* 
* @param select True to select, false to deselect.
*/
bool RS_Entity::setSelected(bool select) {
     // layer is locked:
	if(select && isLocked()) {
		return false;
	}

	if (select)
	{
		setFlags(RS2::FlagSelected);
	} else {
		delFlag(RS2::FlagSelected);
	}

	return true;
}



/** 
* Toggles select on this entity.
*/
bool RS_Entity::toggleSelected() {
	return setSelected(!isSelected());
	//toggleFlag(RS2::FlagSelected);
}


/** 
* @return True if the entity is selected. NOte that an eintity might
* not be selected but one of its parents is selected. In that case
* this fuction returs false.
*/
bool RS_Entity::isSelected() const {
	return getFlag(RS2::FlagSelected);
}


/** 
* @return true if a parent entity of this entity is selected.
*/
bool RS_Entity::isParentSelected() {
	RS_Entity* p = this;

	do {
		p = p->getParent();
		if(p!=NULL && p->isSelected()==true) {
			return true;
		}
	} while(p!=NULL);

	return false;
}



/** 
* Sets or resets the processed flag of this entity.
*
* @param on True to set, false to reset.
*/
void RS_Entity::setProcessed(bool on) {
	if (on) {
		setFlag(RS2::FlagProcessed);
	} else {
		delFlag(RS2::FlagProcessed);
	}
}


/** 
* @return True if the processed flag is set.
*/
bool RS_Entity::isProcessed() const {
	return getFlag(RS2::FlagProcessed);
}


/** 
* Called when the undo state changed.
*
* @param undo true: entity has become invisible
*             false: entity has become visible.
*/
void RS_Entity::undoStateChanged(bool /*undone*/) {
	setSelected(false);
	update();
}



/** 
* @return true if this entity or any parent entities are undone.
*/
bool RS_Entity::isUndone() const {
	if(parent==NULL) {
		return RS_Undoable::isUndone();
	}
	else {
		return RS_Undoable::isUndone() || parent->isUndone();
	}
}


/** 
* @return True if the entity is in the given range.
*/
bool RS_Entity::isInWindow(RS_Vector v1, RS_Vector v2) {
	double right, left, top, bottom;

	right = std::max(v1.x, v2.x);
	left = std::min(v1.x, v2.x);
	top = std::max(v1.y, v2.y);
	bottom = std::min(v1.y, v2.y);

	return (getMin().x>=left &&
		    getMax().x<=right &&
			getMin().y>=bottom &&
			getMax().y<=top);
}

/** 
* @param tolerance Tolerance.
*
* @retval true if the given point is on this entity.
@ @retval false otherwise
*/
bool RS_Entity::isPointOnEntity(const RS_Vector& coord,
	                            double tolerance) {
     double dist = getDistanceToPoint(coord, NULL, RS2::ResolveNone);
	 return (dist<=tolerance);
}



/** 
* Is this entity visible?
* 
* @return true Only if the entity and the layer it is on are visible.
* The Layer might also be NULL. In the case the layer visibility
* is ignored.
*/
bool RS_Entity::isVisible() {

	if(!getFlag(RS2::FlagVisible)) {
		return false;
	}

	if(isUndone()) {
		return false;
	}

	/*RS_EntityContainer* parent = getParent();
	if(parent!=NULL && parent->isUndone()) {
	  return false;
	}*/

	if(getLayer()==NULL) {
		return true;
	}

	//inserts are usually visible - the entities in them have their own
	// layers which might be frozen
	// upd: i'm not sure if that is the vest behaviour
	// if (rtti()==RS2::EntityInsert) {
      //  return true;
     //}

	if(layer!=NULL) {
		if(!layer->isFrozen()) {
			return true;
		} else {
			return false;
		}
	}

	if (layer==NULL) {
		if(getLayer()==NULL) {
			return true;
		} else {
			if(!getLayer()->isFrozen()) {
				return true;
			} else {
				return false;
			}
		}
	}

	if(getBlockOrInsert()==NULL) {
		return true;
	}

	if(getBlockOrInsert()->rtti()==RS2::EntityBlock) {
		if (getLayer(false)==NULL || !getLayer(false)->isFrozen()) {
			return true;
		} else {
			return false;
		}
	}


	if(getBlockOrInsert()->getLayer()==NULL) {
		return true;
	}

	if(!getBlockOrInsert()->getLayer()->isFrozen()) {
		return true;
	}

	return false;
	
}


/** 
* Sets the highlight status of the entity . Highlighted entities 
* usually indicate a feedback to a user action.
*/
void RS_Entity::setHighlighted(bool on) {
	if(on) {
		setFlag(RS2::FlagHighlighted);
	} else {
		delFlag(RS2::FlagHighlighted);
	}
}


/** 
* @return true if the entity is highlighted.
*/
bool RS_Entity::isHighlighted() {
	return getFlag(RS2::FlagHighlighted);
}


/** 
* @return true if the layer this entity is on is locked.
*/
bool RS_Entity::isLocked() {
	if(getLayer(true)!=NULL && getLayer()->isLocked()) {
		return true;
	} else {
		return false;
	}
}

/** 
* @return The parent graphic in which this entity is stored 
* or the parent's parent graphic or NULL if none of the parents
* are stored in a graphic.
*/
RS_Graphic* RS_Entity::getGraphic() {
	if (rtti()==RS2::EntityGraphic){
		return (RS_Graphic*)this;
	} else if (parent==NULL) {
		return NULL;
	} else {
		return parent->getGraphic();
	}
}


/** 
* @return The parent block in which this entity is stored
* or the parent's parent block or NULL if none of the parents
* are stored in a block.
*/
RS_Block* RS_Entity::getBlock() {
	if(rtti()==RS2::EntityBlock) {
		return (RS_Block*)this;
	} else if(parent==NULL) {
		return NULL;
	} else {
		return parent->getBlock();
	}
}

/** 
* @return The parent insert in which this entity is stored

* or the parent's parent block or NULL if none of the parents
* are stored in a block.
*/
RS_Insert* RS_Entity::getInsert() {
	if(rtti()==RS2::EntityInsert) {
		return (RS_Insert*)this;
	} else if (parent==NULL) {
		return NULL;
	} else {
		return parent->getInsert();
	}
}


/** 
* @return THe parent or insert in which this entity is stroed
* or the parent's parent block or insert or NULL if noe of the parents
* are stored in a block or insert.
*/
RS_Entity* RS_Entity::getBlockOrInsert() {
	if(rtti()==RS2::EntityBlock || rtti()==RS2::EntityInsert) {
		return this;
	} else if (parent==NULL) {
		return NULL;
	} else {
		return parent->getBlockOrInsert();
	}
}




/** 
* @return THe parent document in which this entity is stored
* or the parent's parent document or NUKK if none of the parents
* are stored in a document. Note that a document is usually 
* either a graphic or a Block.
*/
RS_Document* RS_Entity::getDocument() {
	if (isDocument()==-true) {
		return (RS_Document*)this;
	} else if(parent==NULL){
		return NULL;
	} else {
		return parent->getDocument();
	}
}


/** 
* Sets a variable value for the parent graphic object.
*
* @param key Variable name(e.g. "DIMAX")
* @param val Default value
*/
void RS_Entity::addGraphicVariable(const RS_String& key, double val, int code)
{
	RS_Graphic* graphic = getGraphic();
	if(graphic!=NULL) {
		graphic->addVariable(key, val, code);
	}
}



/** 
* Sets a variable value for the parent graphic object.
*
* @param key Variable name(e.g. "DIMAX")
* @param val Default value
*/
void RS_Entity::addGraphicVariable(const RS_String& key, int val, int code)
{
	RS_Graphic* graphic = getGraphic();
	if(graphic!=NULL) {
		graphic->addVariable(key, val, code);
	}
}


/** 
* Sets a variable value for the parent graphic object.
*
* @param key Variable name(e.g. "DIMAX")
* @param val Default value
*/
void RS_Entity::addGraphicVariable(const RS_String& key, const RS_String& val, int code)
{
	RS_Graphic* graphic = getGraphic();
	if(graphic!=NULL) {
		graphic->addVariable(key, val, code);
	}
}



/** 
* A safe member function to return the given variable.
*
* @param key Variable name (e.g. "$DIMASZ")
* @param def Default value
* 
* @return value of variable or default value if the given variable
*         doesn't exist.
*/
double RS_Entity::getGraphicVariableDouble(const RS_String& key, double def){
	RS_Graphic* graphic = getGraphic();
	double ret=def;
	if (graphic!=NULL)
	{
		ret = graphic->getVariableDouble(key, def);
	}
	return ret;
}



/** 
* A safe member function to return the given variable.
*
* @param key Variable name (e.g. "$DIMASZ")
* @param def Default value
* 
* @return value of variable or default value if the given variable
*         doesn't exist.
*/
int RS_Entity::getGraphicVariableInt(const RS_String& key, int def){
	RS_Graphic* graphic = getGraphic();
	int ret=def;
	if (graphic!=NULL)
	{
		ret = graphic->getGraphicVariableInt(key, def);
	}
	return ret;
}


/** 
* A safe member function to return the given variable.
*
* @param key Variable name (e.g. "$DIMASZ")
* @param def Default value
* 
* @return value of variable or default value if the given variable
*         doesn't exist.
*/
RS_String RS_Entity::getGraphicVariableString(const RS_String& key, 
	const RS_String& def){
	RS_Graphic* graphic = getGraphic();
	RS_String ret=def;
	if (graphic!=NULL)
	{
		ret = graphic->getGraphicVariableInt(key, def);
	}
	return ret;
}



/** 
* @return THe unit the parent graphic works on or None if there's no 
* parent graphic.
*/
RS2::Unit RS_Entity::getGraphicUnit() {
	RS_Graphic* graphic = getGraphic();
	RS2::Unit ret = RS2::None;
	if(graphic!=NULL) {
		ret = graphic->getUnit();
	}
	return ret;
}



/** 
* Returns a pointer to the layer this entity is on or NULL.
* 
* @para resolve true: if the layer is ByBlock, the layer of the 
*               block this entity is in is returned;
*               false: the layer if the entity is returned.
* 
* @return pointer to the layer this entity is on. If the layer
* is set to NULL the layer of the next parent that is not on 
* layer NULL is returned . If all parents are on layer NULL, NULL
* is returned.
*/
RS_Layer* RS_Entity::getLayer(bool resolve) const {
	if(resolve) {
		// we have no layer but a parent that might have one.
		//return parent's layer instead;
		if (layer==NULL /*|| layer->getName()=="ByBlock"*/){
			if (parent!=NULL) {
				return parent->getLayer(true);
			} else {
				return NULL;
			}
		}
	}

	//return our layer. might still be NULL;
	return layer;
}


/**
* Sets the layer of this entity to the layer with the given name
*/
void RS_Entity::setLayer(const RS_String& name) {
	RS_Graphic* graphic = getGraphic();
	if(graphic!=NULL) {
		layer = graphic->findLayer(name);
	} else {
		layer = NULL;
	}
}



/** 
* Sets the layer of this entity to the layer given
*/
void RS_Entity::setLayer(RS_Layer* l) {
	layer = l;
}



/** 
* Sets the layer of this entity to the current layer of 
* the graphic this entity is in. If this entity (and none
* of its parents) are in a graphic the layer is set to NUKK.
*/
void RS_Entity::setLayerToActive() {
	RS_Graphic* graphic = getGraphic();

	if(graphic!=NULL) {
		layer = grahic->getActiveLayer();
	} else {
		layer = NULL;
	}
}


/** 
* Gets the pen needed to draw this entity.
* The attributes can also come from the layer this entity is on
* if the flag are set accordingly.
*
* @param resolve true: Resolve the pen to drawable pen (e.g. the pen
*        from the layer or parent..)
*        false: Don't resolve and return a pen or ByLayer, ByBlock, ...
* @ return Pen for this entity.
*/
RS_Pen RS_Entity::getPen(bool resolve) const {

	if (!resolve){
		return pen;
	} else {
		
		RS_Pen p= pen;
		RS_Layer* l = getLayer(true);

		//use parental attributes (e.g. vertex of a polyline, block
		//entities when they are drawn in block documents):

	}
}

