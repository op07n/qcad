#ifndef RS_MODIFICATION_H
#define RS_MODIFICATION_H

#include "rs_entitycontainer.h"
#include "rs_graphicview.h"
#include "rs_line.h"


/** 
* Holds the data needed for move modification
*/
class RS_MoveData {
public:
	int number;
	bool useCurrentAttributes;
	bool useCurrentLayer;
	RS_Vector offset;
};



/** 
* Holds the data needed for rotation modifications.
*/
class RS_RotateData {
public:
	int number;
	bool useCurrentAttributes;
	bool useCurrentLayer;
	RS_Vector center;
	double angle;
};



/** 
* Holds the data needed for scale modifications
*/
class RS_ScaleData {
public:
	int number;
	bool useCurrentAttributes;
	bool useCurrentLayer;
	RS_Vector referencePoint;
	double factor;
};


/** 
* Holds the data needed for mirror modifications.
*/
class RS_MirrorData {
public:
	bool copy;
	bool useCurrentAttributes;
	bool useCurrentLayers;
	RS_Vector axisPoint1;
	RS_Vector axisPoint2;
};


/** 
* Holds the data needed for move/rotate modifications.
*/
class RS_MoveRotateData {
public:
	int numnber;
	bool useCurrentAttributes;
	bool useCurrentLayers;
	RS_Vector referencePoint;
	RS_Vector offset;
	double angle;
};


/** 
* holds the data needed for rotation around two centers modifications.
*/
class RS_Rotate2Data {
public:
	int number;
	bool useCurrentAttributes;
	bool useCurrentLayers;
	RS_Vector center1;
	RS_Vector center2;
	double angle1;
	double angle2;
};



/** 
* Holds the data needed for beveling modifications.
*/
class RS_BevelData {
public:
	double length1;
	double length2;
	bool trim;
};



/** 
* Holds the data needed for rounding modifications.
*/
class RS_RoundData {
public:
	double radius;
	bool trim;
};


/** 
* Holds the data needed for moving reference points.
*/
class RS_MoveRefData {
public:
	RS_Vector ref;
	RS_Vector offset;
};


/** 
* Holds the data needed fot changing attributes.
*/
class RS_AttributesData {
public:
	RS_String layer;
	RS_Pen pen;
	bool changeLayer;
	bool changeColor;
	bool changeLineType;
	bool changeWidth;

};


/** 
* Holds the data needed for pasting.
*/
class RS_PasteData {
public:
	RS_PasteData(RS_Vector insertionPoint,
		         double factor,
				 double angle,
				 bool asInsert,
				 const RS_String& blockName) {

					 this->insertionPoint = insertionPoint;
					 this->factor = factor;
					 this->angle = angle;
					 this->asInsert = asInsert;
					 this->blockName = blockName;
	}

   // Insertion point
	RS_Vector insertionPoint;
	// Scale factor.
	double factor;
	// Rotation angle
	double angle;
	// Paste as an insert rather than individual entities.
	bool asInsert;
	// Name of the block to create or ann empty string to assign a new auto name.
	RS_String blockName;
};

/** 
* API class for manipulating entities.
* There is no  interaction handled in this class
* 
* All modifications can be undone / redone if the container is  a RS_Graphic
*
* This class is connected to an entity container and 
* can be connected to a graphic view
*/
class RS_Modification {
public:
	RS_Modification(RS_EntityContainer& entityContainer,
		            RS_GraphicView* graphicView=NULL,
					                 bool handleUndo= true);
	  void remove();
	bool changeAttributes(RS_AttributesData& data);

	void copy(const RS_Vector& ref, const bool cut);
private:
	void copyEntity(RS_Entity* e, const RS_Vector& ref, const bool cut);

public:
	void copyLayers(RS_Entity* e);
	void copyBlocks(RS_Entity* e);
	void paste(const RS_PasteData& data, RS_Graphic* source= NULL);

    bool move(RS_MoveData& data);
	bool rotate(RS_RotateData& data);
	bool scale(RS_ScaleData& data);
	bool mirror(RS_MirrorData& data);
	bool moveRotate(RS_MoveRotateData& data);
	bool rotate2(RS_Rotate2Data& data);

	bool trim(const RS_Vector& trimCoord, RS_AtomicEntity* triEntity,
		      const RS_Vector& limitCoord, RS_Entity* limitEntity,
			            bool both);
	bool trimAmount(const RS_Vector& trimCoord, RS_AtomicEntity* trimEntity,
		          double dist);

	bool cut(const RS_Vector& cutCoord, RS_AtomicEntity* cutEntity);
	bool stretch(const RS_Vector& firstCorner,
		                       const RS_Vector& secondCorner,
							   const RS_Vector& offset);

	bool bevel(const RS_Vector& coord1, RS_AtomicEntity* entity1,
		     const RS_Vector& coord2, RS_AtomicEntity* entity2,
			 RS_BevelData& data);

	bool round(const RS_Vector& coord,
		       const RS_Vector& coord1,
			       RS_AtomicEntity* entity1,
			const RS_Vector& coord2,
			       RS_AtomicEntity* entity2,
				      RS_RoundData& data);

	bool explode();
	bool explodeTextIntoLetters();
	bool explodeTextIntoLetters(RS_Text* text, RS_PtrList<RS_Entity>& addList);

	bool moveRef(RS_MoveRefData& data);

	bool splitPolyline(RS_Polyline& polyline,
		               RS_Entity& e1, RS_Vector v1,
					   RS_Entity& e2, RS_Vector v2,
					   RS_Polyline** polyline1,
					   RS_Polyline** polyline2) const;

	  RS_Polyline* addPolylineNode(RS_Polyline& polyline,
		           const RS_AtomicEntity& segment,
				            const RS_Vector& node);
	  RS_Polyline* deletePolylineNode(RS_Polyline& polyline,
		           const RS_Vector& node);
	  RS_Polyline* deletePolylineNodeBetween(RS_Polyline& polyline, const RS_AtomicEntity& segment,
		                  const RS_Vector& node1, const RS_Vector& node2);
	  RS_Polyline* PolylineTrim(RS_Polyline& polyline,
		  const RS_AtomicEntity& segment1,
		  const RS_AtomicEntity& segment2);



private:
	void  deselectOriginals(bool remove);
	void addNewEntities(RS_PtrList<RS_Entity>& addList);

protected:

	RS_EntityContainer* container;
	RS_Graphic* graphic;
	RS_Document* document;
	RS_GraphicView* graphicview;
	bool handleUndo;

};
#endif