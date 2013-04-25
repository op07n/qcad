#ifndef RS_ACTIONINTERFACE_H
#define RS_ACTIONINTERFACE_H

#include <qobject.h>
#include <qaction.h>

#include "rs_entitycontainer.h"
#include "rs_commandevent.h"
#include "rs_event.h"
#include "rs_grahic.h"
#include "rs_graphicview.h"
#include "rs_mouseevent.h"
#include "rs_snapper.h"
#include "rs_string.h"
#include "rs_preview.h"
#include "rs_dialogfactory.h"

#ifndef RS_NO_QCADCMD
#include "rs_commands.h"
#endif

//
//

/** 
* This is the interface that must be implemented for all action
* classes. Action classes handle actions such
* as drawing lines, moving entities or zooming in.
*
* Inherited from QObject for Qt translation features.
*
*/

class RS_ActionInterface : public QObject, public RS_Snapper {
	Q_OBJECT
public:
	RS_ActionInterface(const char* name,
		               RS_EntityContainer& container,
					   RS_GraphicView& graphicView);
	virtual ~RS_Actioninterface();

	virtual RS2::ActionType rtti();

	RS_String getName();

	virtual void init(int status=0);
	virtual void mouseMoveEvent(RS_MouseEvent*);
};


#endif