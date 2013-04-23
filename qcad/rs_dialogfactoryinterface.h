#ifndef RS_DIALOGFACTORYINTERFACE_H
#define RS_DIALOGFACTORYINTERFACE_H

#include "rs.h"
#include "rs_string.h"

class RS_ActionInterface;
class RS_ArcData;
class RS_AttributesData;
class RS_BevelData;
class RS_BlockData;
class RS_BlockList;
class RS_CircleData;
class RS_DimLinearData;
class RS_DimensionData;
class RS_Document;
class RS_Entity;
class RS_EventHandler;
class RS_Graphic;
class RS_GraphicView;
class RS_Grid;
class RS_Hatch;
class RS_Insert;
class RS_Layer;
class RS_LayerList;
class RS_MirrorData;
class RS_MoveData;
class RS_MoveRotateData;
class RS_Painter;
class RS_Rotate2Data;
class RS_RoundData;
class RS_ScaleData;
class RS_Solid;
class RS_Text;
class RS_Vector;


/** 
* Interface for objects that can create and show dialogs.
*/
class RS_DialogFactoryInterface {
public:
	RS_DialogFactoryInterface() {}

	virtual ~RS_DialogFactoryInterface() {}
	;

	/** 
	* This virtual method must be overwritten and must show the previously
	* shown menu in the cad toolbar.
	*/
	virtual void requestPreviousMenu() = 0;

	/** 
	* This virtual method must be overwritten and must create a new 
	* window for the given document or for a new document if no document
	* is given.
	*/
	virtual RS_GraphicView* requestNewDocument(const RS_String& filename = RS_String::null,
		    RS_Document* doc=NULL) = 0;


	/**
	* This virtual method must be overwritten and must create or show 
	* a simulation control widget.
	*/
	virtual void requestSimulationControls() = 0;

	/** 
	* This virtual method must be overwritten and must provide
	* a dialog for choosing the properties of a new layer to be
	* created, The method must create the new layer but not add
	* it to the layer list. The latter is uyp to the caller.
	* 
	* @retval The implementation is expected to return a pointer
	*         to the newly created layer or NULL if the user 
	*         cancel the dialog.
	*/
	virtual RS_Layer* requestNewLayerDialog(
		RS_LayerList* layerList = NULL) = 0;

	/** 
	* This virtual method must be overwritten and must provide
	* a dialog that asks for permission for removing the selected
	* layer from the layer list. The method must not actually
	* remove the layer. This is up to the caller.
	*
	* @return The implementation is expected to return a pointer
	*         to the layer which can be removed or NULL if the user
	*         cancels the dialog.
	*/
	virtual RS_Layer* requestLayerRemovalDialog(
		RS_LayerList* layerList = NULL) = 0;

	/** 
	* This virtual method must be overwritten and must provide
	* a dialog that asks for permission for removing the selected
	* layer from the layer list. The method must not actually
	* remove the layer, This is up to the caller.
	* @return The implemantation is expected to return a pointer
	*         to the layer which can be removed or NULL if the user
	*		  cancels the dialog.
	*/
	virtual RS_Layer* requestLayerRemovalDialog(
		RS_LayerList* layerList = NULL ) = 0;

	/** 
	* This virtual method must be overwritten and must provide
	* a dialog for choosing the properties of a new block to be
	* created. The method must create the new block but not added
	* it to the block list. The latter is up to the caller.
	*
	* @param block Pointer to the newly created block with default
	*              attributes.
	*
	* @return The implementation is expected to return a pointer
	*         to the newly created block or NULL if the user
	*         cancels the dialog.
	*/
	virtual RS_BlockData requestNewBlockDialog(RS_BlockList* blockList) = 0;

	/**
	*/

};
#endif 