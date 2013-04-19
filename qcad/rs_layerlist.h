#ifndef RS_LAYERLIST_H
#define RS_LAYERLIST_H

//#include <vector.h>

#include "rs_layer.h"
#include "rs_layerlistlistener.h"
#include "rs_entity.h"
#include "rs_ptrlist.h"

/** 
* A list of layers.
*
* @author Andrew Mustun
*/
class RS_LayerList {
public:
	RS_LayerList();
	virtual ~RS_LayerList() {}

	void clear();

	/** 
	* @return number of the layers in the list
	*/
	unit count() const {
		return layers.count();
	}

	/** 
	* @return Layer at given position or nULL if i is out of range.
	*/
	RS_Layer* at(uint i) {
		return layer.at(i);
	}

	void activate(const RS_String& name, bool notify = false);
	void activate(RS_Layer* layer, bool notify = false);
	//! @return The active layer of NULL if no layer is activated.
	RS_Layer* getActive() {
		return activateLayer;
	}
	virtual void add(RS_Layer* layer);
	virtual void remove(RS_Layer* layer);
	virtual void edit(RS_Layer* layer, const RS_Layer& source);
	RS_Layer* find(const RS_String& name);
	int getIndex(const RS_String& name);
	int getIndex(RS_Layer* layer);
	void toggle(const RS_String& name);
	void toggle(RS_Layer* layer);
	void toggleLock(RS_Layer* layer);
	void freezeAll(bool freeze);
	//
	//
	//
	//
	//
	//
	//

	void addListener(RS_LayerListListener* listener);
	void removeListener(RS_LayerListListener* listener);

	/** 
	* Sets the layer lists modified status to 'm'.
	*/

	void setModified(bool m) {
		modified = m;
	}

	/** 
	* @retval true the layer list has been modified.
	* @retval false the layer list has not been modified.
	*/
	virtual bool isModified() const {
		return modified;
	}

	friend std::ostream& operator << (std::ostream& os, RS_LayerList& l);

private:
	//
	RS_PtrList<RS_layer> layers;
	//
	RS_PtrList<RS_LayerListListener> layerListListeners;
	//
	RS_Layer* activeLayer;
	/** Flags set if the layer list was modified and not yet saved. */
	bool modified;
};

#endif