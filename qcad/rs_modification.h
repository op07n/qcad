#ifndef RS_MODIFICATION_H
#define RS_MODIFICATION_H

#include "rs_entitycontainer.h"
#include "rs_graphicview.h"
#include "rs_line.h"


/** 
* Holds the data needed for move modification
*/
class RS_MoveData {
public:
	int number;
	bool useCurrentAttributes;
	bool useCurrentLayer;
	RS_Vector offset;
};



/** 
* Holds the data needed for rotation modifications.
*/
class RS_RotateData {
public:
	int number;
	bool useCurrentAttributes;
	bool useCurrentLayer;
	RS_Vector center;
	double angle;
};



/** 
* Holds the data needed for scale modifications
*/
class RS_ScaleData {
public:
	int number;
	bool useCurrentAttributes;
	bool useCurrentLayer;
	RS_Vector referencePoint;
	double factor;
};


/** 
* Holds the data needed for mirror modifications.
*/
class RS_MirrorData {
public:
	bool copy;
	bool useCurrentAttributes;
	bool useCurrentLayers;
	RS_Vector axisPoint1;
	RS_Vector axisPoint2;
};


/** 
* Holds the data needed for move/rotate modifications.
*/
class RS_MoveRotateData {
public:
	int numnber;
	bool useCurrentAttributes;
	bool useCurrentLayers;
	RS_Vector referencePoint;
	RS_Vector offset;
	double angle;
};


/** 
* holds the data needed for rotation around two centers modifications.
*/



#endif