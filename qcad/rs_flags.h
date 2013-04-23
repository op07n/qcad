#ifndef RS_FLAGS_H
#define RS_FLAGS_H

#include "rs.h"
#include "rs_debug.h"

/**
* Base class for objects which have flags.
*/

class RS_Flags {
public:
	/** Default constructor. Resets all flags to 0. */
	RS_Flags() {
		flags = 0;
	}

	/** Constructor with initialisation to the given flags. */
	RS_Flags(unsigned int f) {
		flags = f;
	}

	virtual ~RS_Flags() {}

	unsigned int getFlags() const {
		return flags;
	}

	void resetFlags() {
		flags = 0;
	}

	void setFlags(unsigned int f) {
		flags = f;
	}

	void setFlag(unsigned int f) {
		flags = flags|f;
	}

	void delFlag(unsigned int f) {
		flags = flags&(~f);
	}

	void toggleFlag(unsigned int f) {
		flags = flags^f;
	}


	bool getFlag(unsigned int f) const {
		if(flags&f) {
			return true;
		} else {
			return false;
		}
	}

private:
	unsigned int flags;

};


#endif
