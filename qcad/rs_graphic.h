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

	// Wrappers for Layers function:
	void clearLayers() {
		layerList.clear();
	}
	uint countLayers() const {
		return layerList.count();
	}
	RS_Layer* layerAt(uint i) {
		return layerList.at(i);
	}
	void activateLayer(const RS_String& name) {
		layerList.activate(name);
	}
    void activateLayer(RS_Layer* layer) {
		layerList.activate(layer);
	}
	RS_Layer* getActiveLayer() {
		return layerList.getActive();
	}
	virtual void addLayer(RS_Layer* layer) {
		layerList.add(layer);
	}
	virtual void removeLayer(RS_Layer* layer);
	virtual void editLayer(RS_Layer* layer, const RS_Layer& source) {
		layerList.edit(layer, source);
	}
	RS_Layer* findLayer(const RS_String& name) {
		return layerList.find(name);
	}
	void toggleLayer(RS_Layer* layer) {
		layerList.toggle(layer);
	}
	void toggleLayer(const RS_String* name)
	{
		layerList.toggle(name);
	}
	void toggleLayerLock(RS_Layer* layer) {
		layerList.toggleLock(layer);
	}
    void freezeAllLayers(bool freeze) {
		layerList.freezeAll(freeze);
	}

	void addLayerListListener(RS_LayerListListener* listener) {
		layerList.addListener(listener);
	}
	void removeLayerListListener(RS_LayerListListener* listener) {
		layerList.removeListener(listener);
	}

	// Wrappers for variable function:
	void clearVariables() {
		variableDict.clear();
	}

	int countVariables() {
		return variableDict.count();
	}

	void addVariable(const RS_String& key,const RS_Vector& value, int code) {
		variableDict.add(key, value, code);
	}
    void addVariable(const RS_String& key,const RS_String& value, int code) {
		variableDict.add(key, value, code);
	}
	void addVariable(const RS_String& key,int value, int code) {
		variableDict.add(key, value, code);
	}
	void addVariable(const RS_String& key,double value, int code) {
		variableDict.add(key, value, code);
	}

	RS_Vector getVariableVector(const RS_String& key, const RS_Vector& def) {
		return variableDict.getVector(key, def);
	}
	RS_String getVariableString(const RS_String& key, const RS_String& def) {
		return variableDict.getString(key, def);
	}
	int getVariableInt(const RS_String& key, int def) {
		return variableDict.getInt(key, def);
	}
	double getVariableDouble(const RS_String& key, double def) {
		return variableDict.getDouble(key, def);
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