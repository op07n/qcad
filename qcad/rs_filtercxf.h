#ifndef RS_FILTERCXF_H
#define RS_FILTERCXF_H

#include <fstream>

#include "rs_filterinterface.h"

/** 
* This format filter class can import and export CXF (CAM Expert font) files.

*/
class RS_FileterCXF : public RS_FilterInterface {
public:
	RS_FilterCXF();
	~RS_FileterCXF() {}

	/** 
	* @return RS2::FormatCXF.
	*/
	//
	//


	virtual bool fileImport(RS_Graphic& g, const RS_String& file, RS2::FormatType);
	
	virtual bool fileExport(RS_Graphic& g, const RS_String& file, RS2::FormatType);

	void stream(std::ofstream& fs, double value);
};
#endif