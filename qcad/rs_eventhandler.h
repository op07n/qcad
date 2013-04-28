#ifndef RS_EVENTHANDLER_H
#define RS_EVENTHANDLER_H

#include "rs_actioninterface.h"
//#include "rs_actiondrawpoint.h"

#include "rs_event.h"
#include "rs_keyevent.h"
#include "rs_mouseevent.h"

#define RS_MAXACTIONS 16

class RS_ActionInterface;

/** 
* The event handler owns and manages all actions that are currently
* active . All events going from the view to the actions come over
* this class.
*/
class RS_EventHandler {
public:
	RS_EventHandler(RS_Graphic* graphicView);
	~RS_EventHandler();

	void back();
	void enter();

	void mousePressEvent(RS_MouseEvent *e);
	void mouseReleaseEvent(RS_MouseEvent *e);
	void mouseMoveEvent(RS_MouseEvent *e);
	void mouseLeaveEvent();
	void mouseEnterEvent();

	void keyPressEvent(RS_KeyEvent* e);
	void keyPressEvent(RS_KeyEvent* e);

	void commandEvent(RS_CommandEvent* e);
	void enableCorrdinateInput();
	void disableCoordinateInput();

	void setDefaultAction(RS_ActionInterface* action);
	RS_ActionInterface* getDefaultAction();

	void setCurrentAction(RS_ActionInterface* action);
	RS_ActionInterface* getCurrentAction();

	void killSelectActions();
	void killAllActions();

	bool hasAction();
	void cleanUp();
	void debugActions();
	void setSnapMode(RS2::SnapMode sm);
	void setSnapRestriction(RS2::SnapRestriction sr);


protected:
	RS_GraphicView* graphicView;
	RS_ActionInterface* defaultAction;
	RS_ActionInterface* currentActions[RS_MAXACTIONS];
	int actionIndex;
	bool coordinateInputEnabled;

};


#endif