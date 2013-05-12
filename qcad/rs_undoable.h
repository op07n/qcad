#ifndef RS_UNDOABLE_H
#define RS_UNDOABLE_H

#include "rs_flags.h"

class RS_UndoCycle;


/**
* Base class for something that can be added and deleted and every
* addition and deletion can be undone.
*
* @see RS_Undo
*/

class RS_Undoable : public RS_Flags {
public:
	RS_Undoable();
	virtual ~RS_Undoable();

	/** 
	* Runtime type identification for undoables.
	* Note that this is voluntarily, The default implementation
	* return RS2::UndoableUnknow.
	*/
	virtual RS2::UndoableType undoRtti() {
		return RS2::UndoableUnknown;
	}

	virtual void setUndoCycle(RS_UndoCycle* cycle);
	virtual void changeUndoState();
	virtual void setUndoState(bool undone);
	virtual bool isUndone() const;


	/** 
	* Can be overwritten by the implementing class to be notified
	* when the uudo state changes (the undoable becomes visible /in visible)
	*/
	virtual void undoStateChanged(bool) {}

private:
	RS_UndoCycle* cycle;
};

#endif