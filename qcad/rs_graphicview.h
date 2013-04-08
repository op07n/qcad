#ifndef RS_GRAPHIC_VIEW_H
#define RS_GRAPHIC_VIEW_H

#include "rs_entitycontainer.h"

#include <stdarg.h>

#include "rs.h"
#include "rs_blocklist.h"
#include "rs_color.h"
#include "rs_keyevent.h"
#include "rs_linetypepattern.h"
#include "rs_commandevent.h"

class RS_ActionInterface;
//
//
class RS_EventHandler;
class RS_Grid;
class RS_Insert;
class RS_Painter;
class RS_Solid;
class RS_Text;
class RS_Hatch;
//class RS_MirrorData;
//class RS_MoveData;
//class RS_MoveRotateData;
//class RS_Rotate2Data;
//class RS_RotateData;
//class RS_ScaleData;
//class RS_BevelData;
//class RS_RoundData;



/**
 * This class is a common GUI interface for the graphic viewer 
 * widget which has to be implementet by real GUI classes such 
 * as the Qt graphical view.
 *
 * Note that this is just an interface used as a slot to 
 * communicate with the qcadlib from a GUI level. 
 */
class RS_GraphicView {
public:
	RS_GraphicView();
	virtual ~RS_GraphicView();

	void cleanUp();

    /**
     * @return Pointer to the graphic entity if the entity container
     * connected to this view is a graphic and valid.
     * NULL otherwise.
     */
	RS_Graphic* getGraphic() {
		if(container != NULL && container->rtti()==RS2::EntityGraphic ) {
			return (RS_Graphic*)container;
		} else {
			return NULL;
		}

	}

	/************************************************************************/
	/*  Sets the drawing mode                                                                     */
	/************************************************************************/
	void setDrawingMode(RS2::DrawingMode m) {
		drawingMode = m;
	}

    /************************************************************************/
    /* return Current drawing mode                                                                     */
    /************************************************************************/

	RS2::DrawingMode getDrawingMode() {
		return DrawingMode;
	}
	
	/** 
	* Activates or deactivates the delete mode.
	*/
	void setDeleteMode(bool m) {
		deleteMode = m;
	}

	/** 
	* @reval true Deleting instead of drawing.
	*        false Normal drawing mode.
	*/

	bool getDeleteMode() {
		return deleteMode;
	}

	/** this virtual method must be overwritten to return
	the width of the widget the graphic is shown in */
	virtual int getWidth() = 0;
	/** this virtual method must be overwritten to return
	the height of the widget the graphic is shown in */
	virtual int getHeight() = 0;
	/** this virtual method must be overwritten to redraw
	   the widget. */
	virtual void redraw() = 0;
	/** this virtual method must be overwritten and is then
	called whether the view changed */
	virtual void adjustOffsetControls() {}
	/** this virtual void method must be overwritten and is then
	called whether the view changed */
	virtual void adjustZoomControls() {}
	/**
	*  Sets an external painter device.                                                                 
	**/
	virtual void setPainter(RS_Painter* p) {
		painter = p;
	}
	/** this virtual void method must be overwritten and must return
	the painter device for the buffer of this widget */
	virtual RS_Painter* createPainter() = 0;

	/**
    * this virtual void method must be overwritten and must return
	* the direct painter device for this widget
	*/

	virtual RS_Painter* createDirectPainter() = 0;

	/**
    * this virtual void method must be overwritten and must destroy
	* the painter device and point 'painter' to NULL. If the painter
	* is static during the whole life of the application, it might
	* just do nothing.
	*/
	virtual void destroyPainter() = 0;

	/**
	* Sets the background color. Note that applying the background
	* color for the widget is up to the implementing class.
	*/
	virtual void setBackground(const RS_Color& bg) {
		background = bg;

		//bright background:
		if(bg.red() + bg.green() + bg.blue() > 380) {
			foreground = Qt::black;
		} else {
			foreground = Qt::white;
		}
	}

	/**
	* @ return Current background color.h
	*/
	RS_Color getBackground() {
		return background;
	}

	/** 
	* return Current foreground color
	*/
	RS_Color getForeground() {
		return foreground;
	}

	/**
	* Sets the grid color.
	*/
	void setGridColor(const RS_Color& c) {
		gridColor = c;
	}

	/** 
	* Sets the meta grid color
	*/
	void setMetaGridColor(const RS_Color& c) {
		metaGridColor = c;
	}

























protected:
	RS_EntityContainer* container;
	RS_EventHandler* eventHandler;

	int mx;   //!< Last known mouse cursor position
	int my;   //!< Last known mouse cursor position

	RS_Painter* painter;
	/** background color (any color) */
	RS_Color background;
	/** foreground color (black or white) */
	RS_Color foreground;
	/** grid color */
	RS_Color gridColor;
	/** meta grid color */
	RS_Color metaGridColor;
	/** selected color */
	RS_Color selectedColor;
	/** highlighted color */
	/** Grid */
	RS_Grid* grid;
    /**
	* Current default snap mode for this graphic view. Used for new 
	* actions
	*/
	RS2::SnapMode defaultSnapMode;

	RS2::DrawingMode drawingMode;

	/**
	* Delete mode. If true, all drawing actions will delete in background color
	* instead;
	*/
	bool deleteMode;
	//! If true, the simulation is currently running
	bool simulationRunning;

private:
	int updateEnabled;
	bool zoomFrozen;
	//bool gridVisible;
	bool draftMode;

	RS_Vector factor;
	int offsetX;
	int offsetY;

	RS_Vector previousFactor;
	int previousOffsetX;
	int previousOffsetY;

	int borderLeft;
	int borderTop;
	int borderRight;
	int borderBottom;

	RS_Vector relativeZero;
	bool relativeZeroLocked;
	//! Print preview flag
	bool printPreview;
	//! Active when printing only:
	bool printing;
	//int drawRecursion;

	//! Simulation speed in percentage
	int simulationSpeed;
	//! If true, the entity is drawn slowly (pixel by pixel).
	bool simulationSmooth;
	//! If true, the way between entities is also shown.
	bool simulationRapid
	//! Last position (for rapid move)
	RS_Vector simulationlast;

};

#endif