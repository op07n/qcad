#ifndef RS_MAINWINDOWINTERFACE_H
#define RS_MAINWINDOWINTERFACE_H

#include "rs_document.h"

#include "rs_graphicview.h"

/** 
* Interface for main application windows.
*/
class RS_MainWindowInterface {

public:
	RS_MainWindowInterface() {}
	virtual ~RS_MainWindowInterface() {}

	virtual RS_GraphicView* getGraphicView() = 0;
	virtual RS_Document* getDocument() = 0;

	virtual void createNewDocument(
		const RS_String& fileName = RS_String::null, RS_Document* doc=NULL) = 0;
	virtual void showSimulationControls() = 0;

};

#endif