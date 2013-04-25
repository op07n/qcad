#ifndef RS_PREVIEW_H
#define RS_PREVIEW_H

#include "rs_entitycontainer.h"

class RS_Entity;
class RS_GraphicView;
class RS_Vector;
class RS_MouseEvent;

/** 
* This class supports previewing. The RS_Snapper class uses
* an instance of RS_Preview to preview entities, ranges,
* lines, arcs, ... on the fly.
*
*/

class RS_Preview : public RS_EntityContainer {
public:
	RS_Preview(RS_EntityContainer* parent=NULL);
	~RS_Preview();

	virtual void addEntity(RS_Entity* entity);
	void addCloneOf(RS_Entity* entity);
	virtual void addSelectionFrom(RS_EntityContainer& container);
	virtual void addAllFrom(RS_EntityContainer& container);
	virtual void addStretchablesFrom(RS_EntityContainer& container,
		  const RS_Vector& v1, const RS_Vector& v2);

private:
	int maxEntities;
};

#endif