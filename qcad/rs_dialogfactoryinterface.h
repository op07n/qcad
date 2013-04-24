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
class RS_RotateData;
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
	* remove the layer, This is up to the caller.
	* @return The implemantation is expected to return a pointer
	*         to the layer which can be removed or NULL if the user
	*		  cancels the dialog.
	*/
	virtual RS_Layer* requestLayerRemovalDialog(
		RS_LayerList* layerList = NULL ) = 0;

	/** 
	* This virtual method must be overwritten and must provide
	* a dialog to edit the layers attributes. The method must 
	* not actually edit the layer. This is up to the caller.
	*
	* @return The implementation is expected to return a pointer
	*         to the layer which can be removed or NULL if the user
	*         cancels the dialog.
	*/
	virtual RS_Layer* requestEditLayerDialog(
		RS_LayerList* layerList = NULL) = 0;

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
	* This virtual method must be overwritten and must provide 
	* a dialog that asks for permission for removing the selected
	* block from the block list. The method must not actually
	* remove the block. This is up to the caller.
	*
	* @return The implementation is expected to return a pointer
	*         to the block which can be removed or NULL if the user
    *         cancels the dialog.
	*/
	virtual RS_Block* requestBlockRemovalDialog(
		RS_BlockList* blockList) = 0;

	/** 
	* This virtual method must be overwritten and must provide 
	* a dialog that allows to change blocks attributes of the 
	* currently active block.
	* @return The implementation is expected to return a pointer
	*         to the block which was changed or NULL if the user
	*         cancel the dialog.
	*/
	virtual RS_BlockData requestBlockAtributesDialog(
		RS_BlockList* blockList) = 0;

	/** 
	* This virtual method must be overwritten and should provide 
	* a new way to edit a block.
	*/
	virtual void requestEditBlockWindow(
		RS_BlockList* blockList) = 0;

	virtual void closeEditBlockWindow(RS_Block* block) = 0;

	/** 
	* This virtual method must be overwritten and must provide
	* a dialog to get a filename for opening an image file, The method must 
	* not actually open the file. This is up tp the caller.
	*
	* @return The implementation is expected to return a string
	*         which contains the file name or an empty string if
	*         the user cancels the dialog.
	*/
	virtual RS_String requestImageOpenDialog() = 0;

	/** 
	* This virtual method must be overwritten and must present
	* a widget for options for the given action.
	*
	* @param action Pointer to the action which needs the option.
	* @param on true: switch widget on, false: off
	* @param update true: widget gets data from the action, false:
	*   widget gets data from the config file.
	*/
	virtual void requestOption(RS_ActionInterface* action,
		bool on, bool update = false) = 0;

	/** 
	* This virtual method must be overwrittten and must present
	* a widget for snap point with distance options.
	*
	* @param dist Distance which can be directly changed
	*             by the present widget.
	* @param on true: switch widget on, false: off
	*/
	virtual void requestSnapDistOptions(double& dist, bool on) = 0;

	/** 
	* This virtual method must be overwritten and must present
	* a widget for  entity attributes;
	* 
	* @param data Attributes data which can be directly changed
	*             by the present widget.
	*/
	virtual bool requestAttributesDialog(RS_AttributesData& data,
		RS_LayerList& layerList) = 0;

	/** 
	* This virtual method must be overwritten and must present
	* a widget for  move options (number of copies);
	* 
	* @param data Move data which can be directly changed
	*             by the present widget.
	*/
	virtual bool requestMoveDialog(RS_MoveData& data) = 0;

	/** 
	* This virtual method must be overwritten and must present
	* a widget for rotate options (number of copies, angle).
	* 
	* @param data Rotation data which can be directly changed
	*             by the presented widget.
	*/
	virtual bool requestRotateDialog(RS_RotateData& data) = 0;

	/** 
	* This virtual method must be overwritten and must present
	* a widget for rotate options (number of copies, angle).
	*
	* @param data Scaling data which can be directly changed
	*             by the presented widget.
	*/
	virtual bool requestScaleDialog(RS_ScaleData& data) = 0;

	/** 
	* This virtual method must be overwritten and must present
	* a widget for mirro options (number of copies);
	* 
	* @param data Mirror data which can be directly changed
	*             by the presented widget.
	*/
	virtual bool requestMirrorDialog(RS_MirrorData& data) = 0;

	/** 
	* This virtual method must be overwritten and must present
	* a widget for move/rotate options (number of copies,angle).
    * 
	* @param data Move/rotate data which can be directly changed
	*             by the presented widget.
	*/
	virtual bool requestMoveRotateDialog(RS_MoveRotateData& data) = 0;

	/** 
	* This virtual method must be overwritten and must present
	* a widget for rotate around two centers options (number of
	* copies, angles).
	* @param data Rotate data which can be directly changed
	*             by the presented widget.
	*/
	virtual bool requestRotate2Dialog(RS_Rotate2Data& data) = 0;

	/** 
	* This virtual method must be overwirtten and  must show 
	* the given toolbar.
	* @param id Tool bar ID.
	*/
	virtual void requestToolBar(RS2::ToolBarId id) = 0;

	/** 
	* This virtual method must be overwritten and must show
	* the tag toolbar with a button for launching the given
	* action.
	* @param nextAction ID of next action to create after selecting was done
	*/
	virtual void requestToolBarSelect(RS_ActionInterface* selectAction,
		                              RS2::ActionType nextAction) = 0;

	/** 
	* This virtual method must be overwritten and must present
	* a dialog to edit the given entity.
	* 
	* @param entity Pointer to the entity.
	*/
	virtual bool requestModifiedEntityDialog(RS_Entity* entity) = 0;

	/** 
	* This virtual method must be overwritten and must present
	* dialog to edit text entity attributes.
	*
	* @param entity Pointer to the text entity.
	*/
	virtual bool requestTextDialog(RS_Text* text) = 0;

	/** 
	* This virtual method must be overwritten and must presnet
	* a dialog to select pattern attributes.
	*
	* @param entity Pointer to the hatch entity.
	*/
	virtual bool requestHatchDialog(RS_Hatch* hatch) = 0;

	/** 
	* This virtual method must be overwritten and must present
	* a dialog for general application options.
	*/
	virtual void requestOptionsGeneralDialog() = 0;

	/** 
    * This virtual method must be overwritten and must present
	* a dialog for drawing options.
	* 
	* @param graphic Graphic document.
	*/
	virtual void requestOptionsDrawingDialog(RS_Graphic& graphic) = 0;

#ifdef RS_CAM
	virtual bool requestCamOptionsDialog(RS_Graphic& graphic) = 0;
#endif

	/** 
	* This virtual method must be overwritten if the graphic view has
	* a componet that is interested in the current mouse position.
	* The implementation will be called every time the mouse position
	* changed,
	*
	*  @param abs Aboslute coordinate of the mouse cursor or the 
	*                             

};
#endif 