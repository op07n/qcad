#ifndef RS_LAYERLISTLISTENER_H
#define RS_LAYERLISTLISTENER_H

#include "rs_layer.h"

/**
* This class is an interface for classes that are intersted in 
* knowing about the changes in the layer list.
*/

class RS_LayerListListener {
public:
	RS_LayerListListener() {}
	virtual ~RS_LayerListListener() {}

	/**
	* Called when the active layer changes.
	*/
	virtual void layerActivated(RS_Layer*) {}

	/**
	* Called when a new layer is added to the list.
	*/
	virtual void layerAdded(RS_Layer*) {}

	/**
	* Called when a  layer is removed from the list.
	*/
	virtual void layerRemoved(RS_Layer*) {}

	/**
	* Called when a  layer's attributes are modified.
	*/
	virtual void layerEdited(RS_Layer*) {}

	/**
	* Called when a  layer's visibility is toggled.
	*/
	virtual void layerToggled(RS_Layer*) {}

}
;






#endif