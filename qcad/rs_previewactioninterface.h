#ifndef RS_PREVIEWACTIONONINTERFACE_H
#define RS_PREVIEWACTIONONINTERFACE_H

#include "rs_actioninterface.h"
#include "rs_painter.h"
#include "rs_preview.h"

/** 
* This is the interface that must be implemented for all
* action classed which need a preview.
*/
class RS_PreviewActionInterface : public RS_ActionInterface {
public:
	RS_PreviewActionInterface(const char* name, 
		                      RS_EntityContainer& container,
							  RS_GraphicView& graphicView);
	virtual ~RS_PreviewActionInterface();

	virtual void init(int status=0);
	virtual void finish();
	virtual void suspend();
	virtual void resume();
	virtual void trigger();
	void clearPreview();
	void drawPreview();
	void deletePreview();

private:
	void xorPreview();

protected:
	/** 
	* Preview that holds the entities to be preview .
	*/
	RS_Preview* preview;
	/** 
	* Keep track of the drawing in XOR mode
	*/
	bool visible;
	/** 
	* Current offset of the preview
	*/
	RS_Vector offset;
};

#endif