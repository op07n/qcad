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


private:
	RS_LayerList layerList;
	RS_BlockList blockList;
	RS_VariableDict variableDict;
#ifdef RS_CAM
	RS_CamData camData;
#endif
};





#endif