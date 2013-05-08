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
protected:
	static RS_System* unique
};
#endif