#ifndef RS_PAINTERQT_H
#define RS_PAINTERQT_H

#include "qpainter.h"

#include "rs_color.h"
#include "rs_graphicview.h"
#include "rs_painter.h"

/** 
* The Qt implementation of a painter. It can draw objects such as
* lines or arcs in a widget, All coordinates are screen coordinates
* and have nothing t do with the graphic view
*/
class RS_PainterQt: public QPainter, public RS_Painter {
public:
	RS_PainterQt(const QPaintDevice* pd);
	virtual ~RS_PainterQt();
};