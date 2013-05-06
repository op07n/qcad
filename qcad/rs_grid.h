#ifndef  RS_GRID_H
#define RS_GRID_H

#include "rs_graphicview.h"
#include "rs_vector.h"

/** 
* This class represents a grid. Grids can be drawn on graphic
* views and snappers can snap to the grid points.
*/
class RS_Grid {
public:
	RS_Grid(RS_GraphicView* graphicView);
	~RS_Grid();

	void update();

	/** 
	* @return Array of all visible grid points.
	*/
	RS_Vector* getPoints() {
		return pt;
	}

	/** 
	* @return Number of visible grid points
	*/
	int count() {
		return number;
	}

	/** 
	* @return Current grid spacing.
	*/
	//
	//
	//
	RS_String getInfo() {
		return RS_String("%1 / %2").arg(spacing).arg(metaSpacing);
	}


	/** 
	* @return Meta grid position in X.
	*/
	double* getMetaX() {
		return metaX;
	}

	/** 
	* @return Number of visible meta grid lines in X.
	*/
	int countMetaX() {
		return numMetaX();
	}

	/** 
	* @return Meta grid position in Y
	*/
	double* getMetaY() {
		return metaY;
	}

	/** 
	* @return Number of visible meta grid lines in Y
	*/
	int countMetaY() {
		return numMetaY;
	}
protected:
	// Graphic view this grid is connected to.
	RS_GraphicView* graphicView;

	// Current grid spacing
	double spacing;
	// Current meta grid spacing
	double metaSpacing;

	// Pointer to array of grid points
	RS_Vector* pt;
	// Number of points in the array
	int number;
	// Meta grid of position in X
	double* metaX;
	// Number of meta grid lines in X
	int numMetaX;
	// Meta grid position in Y
	double* metaY;
	// Number of meta grid lines in Y
	int numMetaY;
};

#endif