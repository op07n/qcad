#ifndef RS_UNDOABLE_H
#define RS_UNDOABLE_H

#include "rs_flags.h"

class RS_UndoCycle;


/**
* Base class for ..undo
*/

class RS_Undoable : public RS_Flags {
public:
	RS_Undoable();
	virtual ~RS_Undoable();


	virtual RS2::UndoableType undoRtti() {
		return RS2::UndoableUnknown;
	}

	virtual void setUndoCycle(RS_UndoCycle* cycle);
	virtual void changeUndoState();
	virtual void setUndoState(bool undone);
	virtual bool isUndone() const;

	virtual void undoStateChanged(bool) {}

private:
	RS_UndoCycle* cycle;
};

#endif