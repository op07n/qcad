#ifndef RS_DEBUG_H
#define RS_DEBUG_H

#ifdef __hpux
#include <sys/_size_t.h>
#endif

#include <iostream>
#include <stdio.h>

#include "rs_string.h"

#define RS_DEBUG RS_Debug::instance()

/**
* Debugging facilities.
*
*/

class RS_Debug {
public:
	/**
	* Enum for debug levels. Only messages of different level
	*/
	enum RS_DebugLevel { D_NOTHING,
		                 D_CRITICAL,
						 D_ERROR,
						 D_WARNING,
						 D_NOTICE,
						 D_INFORMATIONAL,
						 D_DEBUGGING };

private:
	RS_Debug();

public:
	static RS_Debug* instance();

	static void deleteInstance();
	void setLevel(RS_DebugLevel level);
	RS_DebugLevel getLevel();
	void print(RS_DebugLevel level, const char* format ...);
	void print(const char* format ...);
	void printUnicode(const RS_String& text);
	void timestamp();
	void setStream(FILES* s) {
		stream = s;
	}

private:
	static RS_Debug* uniqueInstance;

	RS_DebugLevel debuglevel;
	FILE* stream;

};

#endif

//EOF