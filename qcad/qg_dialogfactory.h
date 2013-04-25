#ifndef QG_DIALOGFACTORY_H
#define QG_DIALOGfACTORY_H

#include <qwidget.h>

#include "rs_dialogfactoryinterface.h"
#include "rs_vector.h"
#include "rs_debug.h"

class QG_CadToolBar;
class QG_CoordinateWidget;
class QG_SelectionWidget;
class QG_MouseWidget;
//class QG_PrintViewOptions;
class QG_CommandWidget;
class QG_MainWindowInterface;
class RS_Document;


#define QG_DIALOGFACTORY (RS_DialogFactory::instance()->getFactoryObject()->isAdapter()==false ? ((QG_DialogFactory*)RS_DialogFactory::instance()->getFactoryObject()) : NULL)


/** 
* This is the Qt implementation of a widget which can create and 
* show dialogs.
*/
class QG_DialogFactory: public RS_DialogFactoryInterface {
public:
	QG_DialogFactory(QWidget* parent, QWidget* ow);
	virtual ~QG_DialogFactory();

protected:
	/** 
	* Links factory to a widget that can host tool options.
	*/
	virtual void setOptionWidget(QWidget* ow) {
		RS_DEBUG->print("QG_DialogFactory::setOptionWidget");
		optionWidget = ow;
		RS_DEBUG->print("QG_DialogFactory::setOptionWidget: OK");
	}

public:
	/** 
	* Links this dialog factory to a coordinate widget.
	*/
	virtual void setCoordinateWidget(QG_CoordinateWidget* cw) {
		coordinateWidget = cw;
	}


protected:
	//! Pointer to the widget which can host dialogs
	QWidget* parent;
	//! Pointer to the widget which can host individual tool options
	QWidget* optionWidget;
	//! Pointer to the coordinate widget.
	QG_CoordinateWidget* coordinateWidget;
	//! Pointer to the mouse widget.
	QG_MouseWidget* mouseWidget;
	//! Poiinter to the selection widget.
	QG_SelectionWidget* selectionWidget;
	//! Pointer to the CAR tool bar
	QG_CadToolBar* cadToolBar;
	//!Pointer to the commmand line widget
	QG_CommandWidget* commandWidget;
	//!Pointer to the main app window
	QG_MainWindowInterface* mainWindow;

};


#endif