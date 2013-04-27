#ifndef RS_CREATION_H
#define RS_CREATION_H

#include "rs_entitycontainer.h
#include "rs_line.h"
#include "rs_polyline.h"
#include "rs_insert.h"
#include "rs_image.h"


/** 
* Data needed to insert library items.
*/
struct RS_LibraryInsertData {
	RS_String file;
	RS_Vector insertionPoint;
	double factor;
	double angle;
};


/** 
* class for the creation of new entities.
* This class is bound to an entity contianer in which the
* entity are stored.
*/

class RS_Creation {
public:
	RS_Creation(RS_EntityContainer* container,
		       RS_GraphicView* graphicView=NULL,
			   bool handleUndo=true);

	RS_Entity* createParallelThrough(const RS_Vector& coord,
		                      int number,
							  RS_Entity* e);

	RS_Entity* createParallel(const RS_Vector& coord,
		                      double distance,
							  int number,
							  RS_Entity* e);
	
	RS_Line* createParallelLine(const RS_Vector& coord,
		                          double distance, int number,
								  RS_Line* e);

	RS_Arc* createParallelArc(const RS_Vector& coord,
		                      double distance, int number,
							  RS_Line* e);

	RS_Circle* createParallelCircle(const RS_Vector& coord,
		                            double distance, int number,
									RS_Circle* e);

	RS_Line* createBisector(const RS_Vector& coord1,
		                    const RS_Vector& coord2,
							double length,
							int num,
							RS_Line& l1,
							RS_Line* l2);

	RS_Line* createTangent1(const RS_Vector& coord,
		                    const RS_Vector& point,
							RS_Entity* circle);

	RS_Line* createTangent2(const RS_Vector& coord,
		                    RS_Entity* circle1,
		                    RS_Entity* circle2);

	RS_Line* createLineRelAngle(const RS_Vector& coord,
		                        RS_Entity* entity,
								double angle,
								double length);

	RS_Line* createPolygon(const RS_Vector& center,
		                   const RS_Vector& corner,
						   int number);

	RS_Line* createPolygon2(const RS_Vector& corner1,
		                    const RS_Vector& corner2,
							int number);

	RS_Insert* createInsert(RS_InsertData& data);

	RS_Image* createImage(RS_ImageData& data);

	RS_Block* createBlock(const RS_BlockData& data,
		                  const RS_Vector& referencePoint,
						  const bool remove);

	RS_Insert* createLibraryInsert(RS_LibraryInsertData& data);

	//
	//
	//
	//

protected:
	RS_EntityContainer* container;
	RS_Graphic* graphic;
	RS_Document* document;
	RS_GraphicView* graphicView;
	bool handleUndo;

};