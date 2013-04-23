#ifndef QG_GRAPHICVIEW_H
#define QG_GRAPHICVIEW_H

#include "qwidget.h"
#include "qlabel.h"
#include "qscrollbar.h"
#include "qpixmap.h"
#include "qlayout.h"
#include "qurl.h"
#include "qfiledialog.h"

#include "rs_graphicview.h"
#include "rs_layerlistlistener.h"
#include "rs_blocklistlistener.h"
#include "rs_painterqt.h"
 
#include "qg_scrollbar.h"
#include "Qt3Support/q3filedialog.h"



/** 
* this is the qt impletation of a widget whichi can view a
* graphic.
* 
* Instance of this class can be linked to layer lists using
* addLayerListener();
*
*/
class QG_GraphicView: public QWidget,
	        public RS_GraphicView,
			public Q3FilePreview,
			public RS_LayerListListener,
	public RS_BlockListLisstener {
		Q_OBJECT
public:
	QG_GraphicView(QWidget* parent=0, const char* name=0, WFlags f=0);
	virtual ~QG_GraphicView();

	virtual int getWidth();
	virtual int getHeight();
	virtual void redraw();
	virtual void adjustOffsetControls();
	virtual void adjustZoomControls();
	virtual RS_Painter* createPainter();
	virtual RS_Painter* createDirectPainter();
	virtual void destroyPainter();
	virtual void setBackground(const RS_Color& bg);
	virtual void setMouseCursor(RS2::CursorType c);
	virtual void updateGridStatusWidget(const RS_String& text);

	//Methods from RS_LayerListListener Interface:
	virtual void layerEdited(RS_Layer*) {
		redraw();
	}
	virtual void layerRemoved(RS_Layer*) {
		redraw();
	}
	virtual void layerToggled(RS_Layer*) {
		redraw();
	}

protected:
	virtual void emulateMouseMoveEvent();
	virtual void mousePressEvent(QMouseEvent* e);
	virtual void mouseReleaseEvent(QMouseEvent* e);
	virtual void mouseMoveEvent(QMouseEvent* e);
#if QT_VERSION>=0x030000
	virtual void tabletEvent(QTableEvent* e);
#endif
	virtual void leaveEvent(QEvent*);
	virtual void enterEvent(QEvent*);
	virtual void focusInEvent(QFocusEvent*);
	virtual void focusOutEvent(QFocusEvent*);
	virtual void wheelEvent(QWheelEvent*);
	virtual void keyPressEvent(QKeyEvent* e);
	virtual void keyReleaseEvent(QKeyEvent* e);

	void paintEvent(QPaintEvent *);
	virtual void resizeEvent(QResizeEvent* e);

	void previewUrl(const QUrl &u);

private slots:
		void slotHScrolled(int value);
		void slotVscrolled(int value);
private:
	//
	QPixmap* buffer;

protected:
	int lastWidth;
	int lastHeight;
	//!
	QG_ScrollBar* hScrollBar;
	//
	QG_ScrollBar* vScrollBar;
	//
	QGridLayout* layout;
	//
	QLabel* gridStatus;
	//
	QCursor* curCad;
	//
	QCursor* curDel;
	//
	QCursor* curSelect;
	//
	QCursor* curMagnifier;
	//
	QCursor* curHand;

};

#endif