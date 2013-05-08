#ifndef RS_SYSTEM_H
#define RS_SYSTEM_H

#include <iostream>

#include "rs_debug.h"
#include "rs_dir.h"
#include "rs_string.h"
#include "rs_stringlist.h"

/** 
* Class for some system methods such as file system operations.
* IMplemented as singleton
*/
class RS_System {
protected:
	RS_System() {
		initialized = false;
	}

public:
	/** 
	* @return Instance to the unique system object.
	*/
	static RS_System* instance() {
		if (uniqueInstance==NULL) {
			uniqueInstance = new RS_System();
		}
		return uniqueInstance;
	}
protected:
	static RS_System* uniqueInstance;

	RS_String appName;
	RS_String appVersion;
	RS_String appDirName;
	RS_String appDir;

	//
	RS_StringList languageList;

	bool initialized;
};
#endif