#ifndef RS_ENTITY_H
#define RS_ENTITY_H

#include "rs_dict.h" //liyang can not find

#include "rs.h"
#include "rs_layer.h"
#include "rs_math.h"
#include "rs_pen.h"
#include "rs_string.h"
#include "rs_stringlist.h"
#include "rs_undoable.h"
#include "rs_vector.h"

class RS_Arc;
class RS_Block;
class RS_Circle;
class RS_Document;
class RS_EntityContainer;
class Rs_Graphic;
class RS_GraphicView;
class RS_Insert;
class RS_Line;
class RS_Painter;
class RS_Point;
class RS_Polyline;
class RS_Text;


/**
* Base class for an entity
*/

class RS_Entity : public RS_Undoable {
public:


	RS_Entity(RS_EntityContainer* parent=NUL);
	virtual ~RS_Entity();

	void init()
	virtual void initId();

	virtual RS_Entity* clone() = 0;

	virtual void reparent(RS_EntityContainer* parent) {
		this->parent = parent;
	}

	void resetBorders();

	/**
	* rtti of this entity..?
	*/

	virtual RS2::EntityType rtti() const {
		return RS2::UndoableEntity;
	}

	unsigned long int getId() const {
		return id;
	}

	virtual unsigned long int count() = 0;

	virtual unsigned long int countDeep() = 0;

	virtual double getLength() {
		return -1.0;
	}

	RS_EntityContainer* getParent() const {
		return parent;
	}

	/**
	* Reparent this entity.
	*/

	void setParent(RS_EntityContainer* p) {
		parent = p;
	}

	RS_Graphic* getGraphic();
	RS_Block* getBlock();
	RS_Insert* getInsert();
	RS_Entity* getBlockOrInsert();
	RS_Document* getDocument();

	void setLayer(const RS_String& name);
	void setlayer(RS_Layer* l);
	void setLayerToActive();
	RS_Layer* getLayer(bool resolve = true) const;

	/**
	* Sets the explict pen for this entity or a pen with special
	* attributes such as BY_LAYER, ..
	*/

	void setPen(const RS_Pen& pen) {
		this->pen = pen;
	}

	void setPenToActive();
	RS_Pen getPen(bool resovle = true) const;

	/**
	* Must to be overwritten to return true if an entity type
	* is a container for other entities (e.g. polyline, group, ...)
	*/

	virtual bool isContainter() const = 0;

	/**
	* Must be overwritten to return true if an entity type
	* is an atomic entity.
	*/

	virtual bool isAtomic() const = 0;

	/**
	* Must be overwritten to return true if an entity type
	* is a potential edge entity of a contour. By default
	* this returns false.
	*/

	virtual bool isEdge() const {
		return false;
	}

	/**
	* return true for all document entities (e.g. graphics or blocks).
	* false otherwise
	*/

	virtual bool isDocument() const {
		return false;
	}

	virtual bool setSelected(bool select);
	virtual bool toggleSelected();
	virtual bool isSelected() const;
	virtual bool isParentSelected();
	virtual bool isProcessed() const;
	virtual void setProcessed(bool on);
	virtual bool isInWindow(RS_Vector v1, RS_Vector v2);
	virtual bool hasEndpointWithinWindow(RS_Vector , RS_Vector) {
		return false;
	}

	virtual bool isVisible();
	virtual void setVisible(bool v) {
		if (v) {
			setFlag(RS2::FlagVisible);
		} else {
			delFlag(RS2::FlagVisible);
		}
	}
	virtual void setHighlighted(bool on);
	virtual bool isHighlighted();

	virtual bool isLocked();

	virtual void undoStateChanged(bool undone);
	virtual bool isUndone() const;

	/**
	* Can be implemented by child classes to update the entities
	* temporary subentities. update() is called if the entity's
	* paramters or undo state changed.
	*/

	virtual void update() {}

	virtual void setUpdateEnabled(bool on) {
		updateEnabled = on;
	}

	/**
	* This method doesn't do any calculations. 
	* @return minimum coordinate of the entity.
	* @see calculateBorders()
	*/

	RS_Vector getMin() const {
		return minV;
	}

    /**
     * This method doesn't do any calculations. 
     * @return maximum coordinate of the entity.
     * @see calculateBorders()
     */

	RS_Vector getMax() const {
		return maxV;
	}

    /**
     * This method returns the difference of max and min returned 
     * by the above functions. 
     * @return size of the entity.
     * @see calculateBorders()
     * @see getMin()
     * @see getMax()
     */
	RS_Vector getSize() const {
		return maxV-minV;
	}

	void addGraphicVariable(const RS_String& key, double val, int code);
	void addGraphicVariable(const RS_String& key, int val, int code);
	void addGraphicVariable(const RS_String& key, const RS_String& val, int code);

	double getGraphicVariableDouble(const RS_String& key, double def);
	int getGraphicVariableInt(const RS_String& key, int def);
	RS_String getGraphicVariableString(const RS_String& key,
		                               const RS_String& def);

	RS2::Unit getGraphicUnit();

	 /**
     * Must be overwritten to get all reference points of the entity. 
     */
    virtual RS_VectorSolutions getRefPoints() {
		RS_VectorSolutions ret;
		return ret;
	}

	/**
	* Must be overwritten to get the closest endpoint to the 
	* given coordinate for this entity. 
	*
	* @param coord Coordinate (typically a mouse coordinate)
	* @param dist Pointer to a value which will contain the measured
	* distance between 'coord' and the closest endpoint. The passed
	* pointer can also be NULL in which case the distance will be
	* lost.
	*
	* @return The closest endpoint.
	*/

	virtual RS_Vector getNearestEndPoint(const RS_Vector& coord,
		                                 double* dist = NULL) = 0;

    /**
     * Must be overwritten to get the closest coordinate to the 
    * given coordinate which is on this entity.
     *
     * @param coord Coordinate (typically a mouse coordinate)
     * @param dist Pointer to a value which will contain the measured
     * distance between \p coord and the point. The passed pointer can 
     * also be \p NULL in which case the distance will be lost.
     *
     * @return The closest coordinate.
     */
	virtual RS_Vector getNearestPointOnEntity(const RS_Vector&,
		    bool onEntity = true, double* dist = NULL,
			RS_Entity** entity = NULL) = 0;

    /**
     * Must be overwritten to get the (nearest) center point to the 
     * given coordinate for this entity. 
     *
     * @param coord Coordinate (typically a mouse coordinate)
     * @param dist Pointer to a value which will contain the measured
     * distance between 'coord' and the closest center point. The passed
     * pointer can also be NULL in which case the distance will be
     * lost.
     *
     * @return The closest center point.
     */
	virtual RS_Vector getNearestCenter(const RS_Vector& coord,
		                               double* dist = NULL) = 0;

    /**
     * Must be overwritten to get the (nearest) middle point to the 
     * given coordinate for this entity. 
     *
     * @param coord Coordinate (typically a mouse coordinate)
     * @param dist Pointer to a value which will contain the measured
     * distance between 'coord' and the closest middle point. The passed
     * pointer can also be NULL in which case the distance will be
     * lost.
     *
     * @return The closest middle point.
     */
	virtual RS_Vector getNearestMiddle(const RS_Vector& coord,
		                               double* dist = NULL) = 0;

	/**
	* Must be overwritten to get the nearest point with a given
	* distance to the endpoint to the given coordinate for this entity. 
	*
	* @param distance Distance to endpoint.
	* @param coord Coordinate (typically a mouse coordinate)
	* @param dist Pointer to a value which will contain the measured
	* distance between 'coord' and the closest point. The passed
	* pointer can also be NULL in which case the distance will be
	* lost.
	*
	* @return The closest point with the given distance to the endpoint.
	*/
    virtual RS_Vector getNearestDist(double distance,
                                     const RS_Vector& coord,
                                     double* dist = NULL) = 0;

	/**
	* Must be overwritten to get the point with a given
	* distance to the start- or endpoint to the given coordinate for this entity. 
	*
	* @param distance Distance to endpoint.
	* @param startp true = measured from Startpoint, false = measured from Endpoint
	*
	* @return The point with the given distance to the start- or endpoint.
	*/
	virtual RS_Vector getNearestDist(double /*distance*/,
		bool /*startp*/) {
			return RS_Vector(false);
	}

	/**
	* Must be overwritten to get the nearest reference point for this entity. 
	*
	* @param coord Coordinate (typically a mouse coordinate)
	* @param dist Pointer to a value which will contain the measured
	* distance between 'coord' and the closest point. The passed
	* pointer can also be NULL in which case the distance will be
	* lost.
	*
	* @return The closest point with the given distance to the endpoint.
	*/
	virtual RS_Vector getNearestRef(const RS_Vector& coord,
		double* dist = NULL) { 
			RS_VectorSolutions s = getRefPoints();

			return s.getClosest(coord, dist); 
	}

	/**
	* Gets the nearest reference point of this entity if it is selected. 
	* Containers re-implement this method to return the nearest reference
	* point of a selected sub entity.
	*
	* @param coord Coordinate (typically a mouse coordinate)
	* @param dist Pointer to a value which will contain the measured
	* distance between 'coord' and the closest point. The passed
	* pointer can also be NULL in which case the distance will be
	* lost.
	*
	* @return The closest point with the given distance to the endpoint.
	*/
	virtual RS_Vector getNearestSelectedRef(const RS_Vector& coord,
		double* dist = NULL) { 
			if (isSelected()) {
				return getNearestRef(coord, dist);
			}
			else {
				return RS_Vector(false); 
			}
	}

	/**
	* Must be overwritten to get the shortest distance between this 
	* entity and a coordinate.
	*
	* @param coord Coordinate (typically a mouse coordinate)
	* @param entity Pointer which will contain the (sub-)entity which is 
	*               closest to the given point or NULL if the caller is not 
	*               interested in this information.
	* @param level The resolve level. 
	*
	* @sa RS2::ResolveLevel
	*
	* @return The measured distance between \p coord and the entity.
	*/

	virtual double  getDistanceToPoint(const RS_Vector& coord,
		                               RS_Entity** entity = NULL,
									   RS2::ResolveLevel level = RS2::ResolveNone, 
									   double solidDist = RS_MAXDOUBLE) = 0;

	virtual bool isPointOnEntity(const RS_Vector& coord, double tolerance=RS_TOLERANCE);

	virtual void move(RS_Vector offset) = 0;

	virtual void rotate(RS_Vector center, double angle) = 0;

	virtual void scale(RS_Vector center, RS_Vector factor) = 0;

	virtual void mirror(RS_Vector axisPoint1, RS_Vector axisPoint2) = 0;

	virtual void stretch(RS_Vector firstcorner,
		                 RS_Vector secondCorner,
						 RS_Vector offset);

	virtual void moveRef(const RS_Vector&,
		    const RS_Vector& )  {
				return;
	}

	virtual void draw(RS_Painter* painter, RS_GraphicView* view,
		double patternOffset = 0.0) = 0;

	double getStyleFactor(RS_String key);
	RS_StringList getAllKeys();
	void setUserDefVar(RS_String key, RS_String val);
	void delUserDefVar(RS_String key);

	friend std::ostream& operator << (std::ostream& os, RS_Entity& e);

	virtual void calculateBorders() = 0;

protected:

	RS_EntityContainer* parent;

	RS_Vector minV;
	RS_Vector maxV;

	RS_Layer* layer;

	unsigned long int id;

	RS_Pen pen;

	bool updateEnabled;

private:

	RS_Dict<RS_String> varlist;

};

#endif
