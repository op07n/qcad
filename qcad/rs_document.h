#ifndef RS_DOCUMENT_H
#define RS_DOCUMENT_H

#include "rs_layerlist.h"
#include "rs_entitycontainer.h"
#include "rs_undo.h"
#include "rs_string.h"

class RS_BlockList;
/**
* Base class for documents. Documents can be either graphics or 
* blocks and are typically shown in graphic views. Documents hold
* an active pen for drawing in the document, a file name and they
* know whether they have been modified or not.
*/


class RS_Document : public RS_EntityContainer,
	public RS_Undo {
};



#endif