#ifndef RS_HATCH_H
#define RS_HATCH_H


#include "rs_entity.h"
#include "rs_entitycontainer.h"

/** 
* Holds the data that defines a hatch entity.
*/
class RS_HatchData {
public:
	/** 
	* Default constructor. Leaves the data object uninitialized.
	*/
	RS_Hatch() {}

	/** 
	* @param solid true: solid fill, false: pattern.
	* @param scale Pattern scale or spacing.
	* @param pattern Pattern name.
	*/
	RS_HatchData(bool solid,
		         double scale,
				 double angle,
				 const RS_String& pattern) {

	}

public:
	bool solid;
	double scale;
	double angle;
	RS_String pattern;
};

/** 
* Class for a hatch entity.
*/
class RS_Hatch : public RS_EntityContainer {
public:
	RS_Hatch(RS_EntityContainer* parent,
		     const RS_HatchData& d);
	virtual ~RS_Hatch() {}

	virtual RS_Entity* clone();

	/** RS2::EntityHatch */
	virtual RS2::EntityType rtti() const {
		return RS2::EntityHatch;
	}

	/** 
	@return true: if this is a hatch with ines (hatch pattern,
	*       false : if this is fillled with a solid color.
	*/
	virtual bool isContainer() const {
		if(isSolid()) {
			return false;
		}
		else {
			return true;
		}
	}

	/** @return Copy of data that defines the hatch. */
	RS_HatchData getData() const {
		return data;
	}

	bool validate();

	int countLoops();

	/** @return true if this a solid fill. false if it is a pattern hatch. */
	bool isSolid() const {
		return data.solid = solid;
	}

	RS_String getPattern() {
		return data.pattern;
	}
	void setPattern(const RS_String& pattern) {
		data.pattern = pattern;
	}

	double getScale() {
		return data.scale;
	}

	void setScale(double scale) {
		data.scale = scale;
	}
	
	double getAngle() {
		data.angle = angle;
	}

	virtual void calculateBorders();
	void update();
	void activateContour(bool on);

	virtual void draw(RS_Painter* painter, RS_GraphicView* view, double patternOffset  = 0.0  );

	virtual double getLength() {
		return -1.0;
	}

	virtual double getDistanceToPoint(const RS_Vector& coord, RS_Entity** entity = NULL  , 
		RS2::ResolveLevel level = RS2::ResolveNone  , 
		double solidDist  = RS_MAXDOUBLE  );

	virtual void move(RS_Vector offset);
	virtual void rotate(RS_Vector center, double angle);
	virtual void scale(RS_Vector center, RS_Vector factor);
	virtual void mirror(RS_Vector axisPoint1, RS_Vector axisPoint2);
	virtual void stretch(RS_Vector firstcorner, RS_Vector secondCorner, RS_Vector offset);

	friend std::ostream& operator << (std::ostream& os, const RS_Hatch& p);

protected:
	RS_HatchData data;
	RS_EntityContainer* hatch;
	bool updateRunning;
	bool needOptimization;
};


#endif