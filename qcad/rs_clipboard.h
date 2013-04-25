#ifndef RS_CLIPBOARD_H
#define RS_CLIPBOARD_H

#include <iostream>
#include "rs_graphic.h"

#define RS_CLIPBOARD RS_Clipboard::instance()

class RS_Block;
class RS_Layer;
class RS_Entity;


/** 
* QCad internal clipboard. We do not use the system clipboard fro
* better portaility.
* Implemented as singleton.
*
*/
class RS_Clipboard {
protected:
	RS_Clipboard() {

	}

public:
	/** 
	* @return Instance to the unique clipboard object.
	*/
	static RS_Clipboard* instance() {
		if (uniqueInstance==NULL)
		{
			uniqueInstance = new RS_Clipboard()
		}
		return uniqueInstance;
	}

	void clear();

	void addBlock(RS_Block* b);
	bool hasBlock(const RS_String& name);
	int countBlocks() {
		return graphic.countBlocks();
	}
	RS_Block* blockAt(int i) {
		return graphic.blockAt(i);
	}
}; 


#endif