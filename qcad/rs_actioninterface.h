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
	virtual void mousePressedEvent(RS_MouseEvent*);
	
	virtual void mouseReleaseEvent(RS_MouseEvent*);
	virtual void keyPressedEvent(RS_KeyEvent* e);
	virtual void keyReleasedEvent(RS_KeyEvent* e);
	virtual void coordinateEvent(RS_CoordinateEvent*);
	virtual void commandEvent(RS_CommandEvent*);
	virtual RS_StringList getAvalilableCommands();
	virtual void setStatus(int status);
	virtual int getStatus();
	virtual void trigger();
	virtual void updateMouseButtonHints();
	virtual void updateMouseCursor();
	virtual void updateToolBar();
	virtual bool isFinished();
	virtual void setFinished();
	virtual void finish();
	virtual void setPredecessor(RS_ActionInterface* pre);
	virtual void suspend();
	virtual void resume();
	virtual void hideOptions();
	virtual void showOptions();
	bool checkCommand(const RS_String& cmd, const RS_String& str,
		                     RS2::ActionType action=RS2::ActionNone);
	RS_String command(const RS_String& cmd);
	RS_String msgAvailableCommands();

private:
	/** 
	* Current status of the action. After an action has been
	* created the action status is set to 0. Actions
	* that are terminated have a status of -1. Other status
	* number can be used to describe the stage this action 
	* is in E.G. a window zoom consists of selecting the 
	* first corner (status 0), and selcting the second
	* corner (status 1).
	*/
	int status;

protected:
	/** Action name, Used internally for debugging */
	RS_String name;

	/** 
	* This flag is set when the action has terminated and 
	* can be deleted.
	*/
	bool finished;

	/** 
	* Pointer to the graphic is this contianer is a graphic.
	* NULL otherwise
	*/
	RS_Graphic* graphic;

    /** 
	* Pointer to the document (graphic or block) or NULL
	*/
	RS_Document* document;

	/** 
	* Pointer to the default mouse cursor for this action or NULL.
	*/
	//RS2::CursorType cursor;

	/** 
	* Predecessor of this action or NULL.
	*/
	RS_ActionInterface* predecessor;

	//

	//

	//

	//

	//

};


#endif