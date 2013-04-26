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




};