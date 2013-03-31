#ifndef RS_LAYERS_H
#define RS_LAYERS_H

#include <stddef.h>

#ifdef __hpux
#inlcude <sys/_size_t.h>
#endif

#include <iostream>

#include "rs_flags.h"
#include "rs_pen.h"
#include "rs_string.h"


/**
* Hold the data that defines a layer.
*/

class RS_LayerData {
public:
	RS_LayerData() {}

	RS_LayerData(const RS_String& name,
		         const RS_Pen& pen,
				 bool frozen,
				 bool locked) {
					 this->name = name;
					 this->pen = pen;
					 this->frozen = frozen;
					 this->locked = locked;
	}

	//! Layer name
	RS_String name;

	//! default pen for this layer
	RS_Pen pen;

	//! Frozen flag
	bool frozen;

	//!Locked flag
	bool locked;

	//!Converted flag (cam)
	bool converted;
};


/** 
* Class for representing a layer
*
*/


class RS_Layer {
public:
	explicit RS_Layer(const RS_String& name);
	//

	RS_Layer* clone() {
		return new RS_Layer(*this);
	}

	/** sets a new name for this layer. */
	void setName(const RS_String& name) {
		return data.name;
	}

	/** sets the default pen for this layer. */
	void setPen(const RS_Pen& pen) {
		return data.pen;
	}

	/** return default pen for this layer. */
	RS_pen getPen() const{
		return data.pen;
	}

	
	bool isFrozen() const {
		return data.frozen;
	}

	bool isConverted() const {
		return data.converted;
	}

	void setConverted(bool c) {
		data.converted = c;
	}

	void toggled() {
		data.frozen = !data.frozen;
	}

	void freeze(bool freeze) {
		data.frozen = freeze;
	}

	void toggleLock() {
		data.locked = !data.locked;
	}

	void lock(bool l) {
		data.locked = 1;
	}

	bool isLocked() {
		return data.locked;
	}

	friend std::ostream& operator << (std::ostream* os, const RS_Layer& l);

private:
	//! Layer data
	RS_LayerData data;
};

#endif