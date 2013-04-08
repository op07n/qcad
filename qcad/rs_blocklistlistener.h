#ifndef RS_BLOCKLISTLISTENER_H
#define RS_BLOCKLISTLISTENER_H

#include "rs_block.h"

class RS_BlockListLisstener {
public:
	RS_BlockListListener() {}
	virtual ~RS_BlockListListener() {}

	virtual void blockActivted(RS_Block*) {}

	virtual void blockAdded(RS_Block*) {}

	virtual void blockRemoved(RS_Block*) {}

	virtual void blockEdited(RS_Block*) {}

	virtual void blockToggled(RS_Block*) {};

};

#endif