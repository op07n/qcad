#ifndef RS_SELECTION_H
#define RS_SELECTION_H

#include "rs_entitycontainer.h"
#include "rs_graphicview.h"


/** 
* API class for selecting entities.
* there is no intersection handled in this class.
* This class si connected to an entity container and
* can be connected to a graphic view.
*/
class RS_Selection {
public:
	RS_Selection(RS_EntityContainer& entityContainer,
		         RS_GraphicView* graphicView=NULL);

	void selectSingle(RS_Entity* e);
	void selectAll(bool select=true);
	void deselectAll() {
		selectAll(false);
	}
	void invertSelection();
	void selectWindow(const RS_Vector& v1, const RS_Vector& v2,
		             bool select=true, bool cross=false);
	void deselectWindow(const RS_Vector& v1, const RS_Vector& v2) {
		selectWindow(v1,v2,false);
	}
	void selectIntersected(const RS_Vector& v1, const RS_Vector& v2,
		              bool select= true);
	void deselectIntersected(const RS_Vector& v1, const RS_Vector& v2) {
		selectIntersected(v1, v2, false);
	}
	void selectContour(RS_Entity* e);

	void selectLayer(RS_Entity* e);
	void selectLayer(const RS_String& layerName, bool select=true);
	void deselectLayer(const RS_String& layerName) {
		selectLayer(layerName,false);
	}

protected:
	RS_EntityContainer* container;
	RS_Graphic* graphic;
	RS_GraphicView* graphicView;
};

#endif