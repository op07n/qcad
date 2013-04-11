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
	virtual 


};