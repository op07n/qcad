#ifndef QG_SCROLLBAR_H
#define QG_SCROLLBAR_H

#include "qscrollbar.h"

/** 
* A small wrapper for the Qt scrollbar. this class offers a slot
* for scroll events.
*/

class QG_ScrollBar: public QScrollBar {
	Q_OBJECT
public:
	QG_ScrollBar(QWidget* parent=0, const char* name=0)
		: QScrollBar(parent, name) {}
	QG_ScrollBar(Orientation orientation, 
		         QWidget* parent=0, const char* name=0)
				 :QScrollBar(orientation, parent, name) {}

public slots:
	void slotWheelEvent(QWheelEvent* e) {
		wheelEvent(e);
	}

};

#endif