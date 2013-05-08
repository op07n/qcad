#ifndef RS_STATICGRAPHICVIEW_H
#define RS_STATICGRAPHICVIEW_H

#include "rs_graphicview.h"
#include "rs_layerlistlistener.h"

/** 
* THis is an implementation of a viewer with a fixed size
* for drawing onto fixed devices (such as bitmaps).
*/
class RS_StaticGraphicView: public RS_GraphicView {
public:
	RS_StaticGraphicView(int w, int h, RS_Painter* p);
	virtual ~RS_StaticGraphicView();

	virtual int getWidth();
	virtual int getHeight();
	virtual void redraw() {}
	virtual void adjustOffsetControls() {}
	virtual void adjustZoomControls() {}
	virtual RS_Painter* createPainter();
	virtual RS_Painter* createDirectPainter();
	virtual void setMouseCursor(RS2::CursorType ) {}

	virtual void emulateMouseMoveEvent() {}
	    virtual void updateGridStatusWidget(const RS_String& ) {}

	void paint();

private:
	// Width
	int width;

	// Height
	int height;
};