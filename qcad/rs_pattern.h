#ifndef RS_PATTERN
#define RS_PATTERN

#include "rs_entitycontainer.h"

class RS_PatternList;

/** 
* Pattern are used for hatches. They are stored in a RS_PatternList.
* Use RS_PatternList to access a pattern.
*/
class RS_Pattern : public RS_EntityContainer {
public:
	RS_Pattern(const RS_String& filename);
	virtual ~RS_Pattern();

	virtual bool loadPattern();

	/** @return the filename of this pattern */
	RS_String getFileName() const {
		return fileName;
	}

protected:
	// Pattern file name
	RS_String fileName;

	// Is this pattern currently loaded into memory?
	bool loaded;

};

#endif