#ifndef RS_GRAPHIC_H
#define RS_GRAPHIC_H

#include "rs_blocklist.h"
#include "rs_layerlist.h"
#include "rs_variabledict.h"
#include "rs_document.h"
#include "rs_units.h"
#ifdef RS_CAM
#include "rs_camdata.h"
#endif

//class RS_CamData;



/** 
* A graphic document which can contain entities layers and blocks.
*/
class RS_Graphic : public RS_Document {
public:
	RS_Graphics(RS_EntityContainer* parent=NULL);
	virtual ~RS_Graphic();

	//

	/** */
	virtual RS2::EntityType rtti() const {
		return RS2::EntityGraphic;
	}

	virtual unsigned long int countLayerEntities(RS_Layer* layer);

	virtual RS_LayerList* getLayerList() {
		return &layerList;
	}
	virtual RS_BlockList* getBlockList() {
		return &blockList;
	}

	virtual void newDoc();
	virtual bool save();
	virtual bool saveAs(const RS_String& filename, RS2::FormatType type);
	virtual bool open(const RS_String& filename, RS2::FormatType type);

	/** 
	* @return true for all document entities (e.g. Graphics or Blocks).
	*/
	virtual bool isDocument() const {
		return true;
	}

	/** 
	* Removes an entity from the entity container. Implementation 
	* from RS_Undo
	*/
   virtual void removeUndoable(RS_Undoable* u) {
	   if (u!=NULL && u->undoRtti()==RS2::UndoableEntity) 
	   {
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
   * @return File name of the document currently loaded.
   * Note, that the default file name is empty.
   */
   RS_String getFilename() const {
	   return filename;
   }

   /**
   * Sets file name for the document currently loaded.
   */
   void setFilename(const RS_String& fn) {
	   filename = fn;
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

private:
	RS_LayerList layerList;
	RS_BlockList blockList;
	RS_VariableDict variableDict;
#ifdef RS_CAM
	RS_CamData camData;
#endif
};





#endif