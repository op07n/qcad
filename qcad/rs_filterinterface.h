#ifndef RS_FILTERINTERFACE_H
#define RS_FILTERINTERFACE_H

#include "rs_graphic.h"

#include "rs_string.h"
#include "rs_valuelist.h"

#include "rs_debug.h"

/** 
* THis is the interface that must be implemented for all 
* format filter classes, THe RS_FileIO class
* use the methods defined in here to interact with the format
* filter classed.
*/

class RS_FilterInterface {
	/** 
	* Constructor 
	*/
	RS_FilterInterface() {

	}

	/** 
	* Destructor
	*/
	virtual~RS_FilterInterface() {}

	/** 
	* Checks if this filter can import the given file type.
	*/
	virtual bool canImport(RS2::FormatType t) {
		return !(importFormats.find(t)==importFormats.end());
	}

	/** 
	* Checks if this filter can export the given file type
	*/
	virtual bool canExport(RS2::FormatType t) {
		return !(exportFormats.find(t)==exportFormats.end());
	}

	/** 
	* The implementation
	*/


protected:
	//
	//

	//
	RS_ValueList<RS2::FormatType> importFormats;

	//
	RS_ValueList<RS2::FormatType> exportFormats;
};
#endif