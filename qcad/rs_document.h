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
	virtual bool save() = 0;
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

	 /** 
	 * @return Currently active drawing pen.
	 */
	 RS_Pen getActivePen() const {
		 return activePen;
	 }

	 /** 
	 * Sets the currently active drawing pen to p.
	 */
	 void setActivePen(RS_Pen p) {
		 activePen = p;
	 }

	 /** 
	 * @ return File name of the document currently loaded.
	 * Note that the default file name is empty.
	 */
	 RS_String getFilename() const {
		 return filename;
	 }

	 /** 
	 * @sets File name for the document curretly loaded.
	 */
	 virtual void setModified(bool m) {
		 modified = m;
	 }

	 /** 
	 * @retval true The document has been modified since it was last saved.
	 * @retval false The document has not been modified since it was last saved.
	 */
	 virtual bool isModified() const {
		 return modified;
	 }

	 /** 
	 * Overwritten to set modified flag before starting an undo cycle.
	 */
	 virtual void startUndoCycle() {
		 setModified(true);
		 RS_Undo::startUndoCycle();
	 }


protected:
	/** Flags set if the document was modified and not yet saved */
	bool modified;
    /** Active Pen */
	RS_Pen activePen;
	/** File name of the document or empty for a new document */
	RS_String filename;
    /** Format type */
	RS2::FormatType formatType;
};



#endif