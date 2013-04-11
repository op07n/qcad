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

	virtual void moveTo(int x, int y);
	virtual void lienTo(int x, int y);
	virtual void drawGridPoint(const RS_Vector& p) ;
	virtual void drawPoint(const RS_Vector& p) ;
	virtual void drawLine(const RS_Vector& p1, const RS_Vector& p2) ;
	//virtual void drawRect(const RS_Vector& p1, const RS_Vector& p2) ;
	virtual void drawArc(constRS_Vector& cp, double radius,
		double a1, double a2,
		const RS_Vector& p1, const RS_Vector& p2
		bool reserved) ;

	virtual void drawArc(constRS_Vector& cp, double radius,
		double a1, double a2,
		bool reserved) ;
	virtual void drawArcMac(const RS_Vector& cp, double radius,
		                    double a1, double a2,
							bool reserved);

	virtual void drawCircle(const RS_Vector& cp, double radius) ;
	virtual void drawEllipse(const RS_Vector& cp,
		double radius1, double radius2,
		double angle,
		double angle1, double angle2,
		bool reserved) ;
	virtual void drawImg(RS_Img& img, const RS_Vector& pos,
		double angle, const RS_Vector& factor,
		int sx, int sy, int sw, int sh) ;

	virtual void drawTextH(int x1, int y1, int x2, int y2,
		const RS_String& text) ;
	virtual void drawTextV(int x1, int y1, int x2, int y2,
		const RS_String& text) ;

	virtual void fillRect(int x1, int y1, int w, int h,
		const RS_Color& col) ;

	virtual void fillTriangle(const RS_Vector& p1,
		const RS_Vector& p2,
		const RS_Vector& p3) ;

	virtual void drawPolygon(const RS_PointArray& a) ;
	virtual void erase();
	virtual int getWidth();
	virtual int getHeight();


	//
	virtual void setPreviewPen() ;
	virtual RS_Pen getPen() ;
	virtual void setPen(const RS_Pen& pen) ;
	virtual void setPen(const RS_Color& color) ;
	virtual void setPen(int r, int g, int b) ;
	virtual void disablePen();

	virtual void setBrush(const RS_Color& color) ;


	virtual void setXORMode() ;
	virtual void setNormalMode() ;

	virtual void setClipRect(int x, int y, int w, int h) ;
	virtual void resetClipping() ;

protected:
	RS_Pen lpen;
};

#endif