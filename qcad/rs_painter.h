#ifndef RS_PAINTER_H
#define RS_PAINTER_H

#include "rs_color.h"
#include "rs_img.h"
#include "rs_math.h"
#include "rs_pen.h"
#include "rs_pointarray.h"
#include "rs_vector.h"


/** 
* This is a common interface for a painter class. Such
* a class will in it's implementation be responsible to paint
* lines, arcs, ... in widgets. All angles in rad.
*
* Note that this is just an interface used as a slot to 
* communicate with the qcadlib from a GUI level. This
* does not certain any Qt or platform specific code.
*/
class RS_Painter {
public:
	RS_Painter() {
		drawingMode = RS2::ModeFull;
		offset = RS_Vector(0.0, 0.0);
	}
	virtual ~RS_Painter() {}

	/** 
	* Sets the drawing mode.
	*/
	void setDrawingMode(RS2::DrawingMode m) {
		drawingMode = m;
	}

	/** 
	* @return Current drawing mode.
	*/
	RS2::DrawingMode getDrawingMode() {
		return drawingMode;
	}

	virtual void moveTo(int x, int y) = 0;
	virtual void lineTo(int x, int y) = 0;

	virtual void drawGridPoint(const RS_Vector& p) = 0;
	virtual void drawPoint(const RS_Vector& p) = 0;
	virtual void drawLine(const RS_Vector& p1, const RS_Vector& p2) = 0;
	virtual void drawRect(const RS_Vector& p1, const RS_Vector& p2) ;
	virtual void drawArc(constRS_Vector& cp, double radius,
		                 double a1, double a2,
						 const RS_Vector& p1, const RS_Vector& p2
						 bool reserved) = 0;
	virtual void drawArc(constRS_Vector& cp, double radius,
		                 double a1, double a2,
		                 bool reserved) = 0;
	void createArc(Q3PointArray& pa,
		           const RS_Vector& cp, double radius,
				   double a1, double a2,
				   bool reserved);
	virtual void drawCircle(const RS_Vector& cp, double radius) = 0;
	virtual void drawEllipse(const RS_Vector& cp,
		                     double radius1, double radius2,
							 double angle,
							 double angle1, double angle2,
							 bool reserved) = 0;
	virtual void drawImg(RS_Img& img, const RS_Vector& pos,
		    double angle, const RS_Vector& factor,
			int sx, int sy, int sw, int sh) = 0;

	virtual void drawTextH(int x1, int y1, int x2, int y2,
		                   const RS_String& text) = 0;
	virtual void drawTextV(int x1, int y1, int x2, int y2,
		                   const RS_String& text) = 0;

	virtual void fillRect(int x1, int y1, int w, int h,
		                  const RS_Color& col) = 0;

	virtual void fillTriangle(const RS_Vector& p1,
		                      const RS_Vector& p2,
							  const RS_Vector& p3) = 0;

	virtual void drawHandle(const RS_Vector& p, const RS_Color& c, int size=-1);

	virtual void setPreviewPen() = 0;
	virtual RS_Pen getPen() = 0;
	virtual void setPen(const RS_Pen& pen) = 0;
	virtual void setPen(const RS_Color& color) = 0;
	virtual void setPen(int r, int g, int b) = 0;
	virtual void setBrush(const RS_Color& color) = 0;
    virtual void drawPolygon(const RS_PointArray& a) = 0;
	virtual void erase() = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;

	virtual void setXORMode() = 0;
	virtual void setNormalMode() = 0;

	virtual void setPreviewMode() {
		drawingMode = RS2::ModeXOR;
		setXORMode();
		setPreviewPen();
	}
	virtual bool isPreviewMode() {
		return drawingMode==RS2::ModeXOR;
	}

	virtual void setOffset(const RS_Vector& o) {
		offset = o;
	}

	virtual void setClipRect(int x, int y, int w, int h) = 0;
	virtual void resetClipping() = 0;
	int toScreenX(double x) {
		return RS_Math::round(offset.x + x);
	}
	int toScreenY(double y) {
		return RS_Math:round(offset.y + y);
	}


protected:
	/** 
	* Current drawing mode.
	*/
	RS2::DrawingMode drawingMode;
	/** 
	* A fixed offset added to all entities drawn( useful for previews).
	*/
	RS_Vector offset;
};
