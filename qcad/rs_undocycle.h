
#ifndef RS_UNDOLISTITEM_H
#define RS_UNDOLISTITEM_H

#include <iostream>

#include "rs.h"
#include "rs_entity.h"
#include "rs_ptrlist.h"
#include "rs_undoable.h"

/** 
* An Undo cycle represents an action that was triggered and can 
* be undone. It Stores all the pointers to the Undoables affected by
* the action. Undoables are entities in a container that can be 
* created and deleted.
*
* Undo Cycles are stored within classes derived from RS_Undo.
* @see RS_undoable
* @see RS_Undo
*
*/

class RS_UndoCycle {
public:
	/** 
	* @param type Type of undo item.
	*/
	RS_UndoCycle() {
		undoables.setAutoDelete(false);
	}

	/**
	* Add an Undoable to this Undo Cycle. every Cycle can contain one or
	* more Undoables.
	*/
	void addUndoable(const RS_Undoable* u) {
		undoables.append(u);
	}

	/**
	* Removes an undoable from the list.
	*/
	void removeUndoable(RS_Undoable* u) {
		undoables.remove(u);
	}

	/**
	* Iteration through undoable elements in this item.
	*/
	RS_Undoable* getFirstUndoable() {
		return undoables.first();
	}

	/**
	* Iteration through undoable elements in this item.
	*/

	RS_Undoable* getNextUndoable() {
		return undoables.next();
	}

	friend std::ostream& operator << (std::ostream& os,
		                              RS_UndoCycle& i) {
			os << " Undo item: " << "\n";
			os << " Undoable ids: ";
			for (RS_Undoable* u= i.getFirstUndoable();
				u!=NULL; u=i.getNextUndoable()) {

					if (u->undoRtti()==RS2::UndoableEntity) 
					{
						RS_Entity* e = (RS_Entity*)u;
						os<<e->getId() << (u->isUndone() ? "*" : "") << " ";
					} else {
						os << "|";
					}
			}
			return os;
	}
	friend class RS_Undo;


private:
	//
	//
	//
	RS_PtrList<RS_Undoable> undoables;
};
#endif