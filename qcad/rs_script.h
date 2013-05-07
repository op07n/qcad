#ifndef RS_SCRIPT_H
#define RS_SCRIPT_H

#include <iostream>

#include "rs_string.h"


/** 
* Class for representing a script .This is implemented as a RS_String
* containing the script name
* 
* OBSOLETE
*/
class RS_Script {
public:
	RS_Script(const RS_String& name, const RS_String& path);
	//

	/** @return the name of the script */
	RS_String getName() const {
		return name;
	}

	/** @return the full path and file name of the script */
	RS_String getPath() const {
		return	path;
	}


private:
	// Script name
	RS_String name;

	// Full path to script
	RS_String path;

};
#endif