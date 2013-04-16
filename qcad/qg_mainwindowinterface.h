#define QG_MAINWINDOWINtErFACE_H
#define QG_MAINWINDOWINTERFACE_H

#include <qmainwindow.h>

#include "rs_document.h"
#include "rs_mainwindowinterface.h"

#include "qg_graphicview.h"
#include "qg_actionhandler.h"

/** 
* Interface for main application windows.
*/
class QG_MainWindowInterface : public RS_MainWindowInterface {
public:
	QG_MainWindowInterface() {}
	virtual ~QG_MainWindowInterface() {}

	virtual QGMainWindow* getMainWindow() = 0;
	virtual QG_ActionHandler* getActionHandler() = 0;
	virtual void setFocus2() = 0;

	//virtual QToolBar* createToolBar(const RS_String& name) = 0;
	//virtual void addToolBarButton(QToolBar* tb) = 0;
};

#endif
