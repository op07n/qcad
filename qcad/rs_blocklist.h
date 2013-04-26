#ifndef RS_BLOCKLIST_H
#define RS_BLOCKLIST_H

#include "rs_block.h"
#include "rs_blocklistlistener.h"
#include "rs_entity.h"
#include "rs_ptrlist.h"



class RS_BlockList {
public:
	RS_BlockList(bool owner= false);
	virtual ~RS_BlockList() {}

	void clear();
	/*
	*
	*/

	uint count() {
		return blocks.count();
	}

	/*
	* block at given position
	*/

	RS_Block* at(unit i) {
		return blocks.at(i);
	}

	void activate(const RS_String& name);
	void activate(RS_Block* block);
	// @return the active block of NULL if no block is activated
	RS_Block* getActive() {
		return activeBlock;
	}

	virtual bool add(RS_Block* block, bool notify=true);
	virtual void addNotification();
	virtual void remove(RS_Block* block);
	virtual bool rename(RS_Block* block, const RS_String& name);
	//
	RS_Block* find(const RS_String& name);
	RS_String newName(const RS_String& suggestion = "");
	void toggle(const RS_string& name);
	void toggle(RS_Block* block);
	void freezeAll(bool freeze);

	/**
	*
	*/

	void addListener(RS_BlockListListener* listener);
	void removeListener(RS_BlockListListener* listener);

	/**
	*
	*/

	void setModified(bool m) {
		modified = m;
	}

	/*
	*
	*/
	virtual bool isModified() const {
		return modified;
	}

	friend std::ostream& operator << (std::ostream& os, RS_BlockList& b);

private:

	bool owner;

	RS_PtrList<RS_Block> blocks;

	RS_PtrList<RS_BlockListListener> blockListeners;

	RS_Block* activeBlock;

	bool modified;

};

#endif