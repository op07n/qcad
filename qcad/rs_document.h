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
public:
	RS_Document(RS_EntityContainer* parent=NULL);
	virtual ~RS_Document();

	virtual RS_LayerList* getlayerList() = 0;
	virtual RS_BlockList* getBlockList() = 0;

	virtual void newDoc();
	virtual void save() = 0;
	virtual bool saveas(const RS_String & filename, RS2::Formattype type) = 0;
	virtual bool open(const RS_String & filename, RS2::Formattype type) = 0;


     virtual bool isDocument() const {
		 return true;
	 }

	 virtual void removeUndoable(RS_Undoable* u) {
		 if ( u!=NULL && u->undoRtti() == RS2::UndoableEntity) {
			 removeEntity((RS_Entity*)u);
		 }
	 }

};



#endif