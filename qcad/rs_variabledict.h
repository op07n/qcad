#ifndef RS_VARIABLEDICT_H
#define RS_VARIABLEDICT_H


//#include "rs_variabledict.h"
#include "rs_variable.h"
#include "rs_dict.h"
#include "rs_string.h"
#include "rs_debug.h"

/** 
* Dictionary of variables. The variables are stored as key / value
* pairs (string /string).
*/
class RS_VariableDict {
public:
	RS_VariableDict();
	virtual ~RS_VariableDict() {}

	void clear();
	/** 
	* @return Number of variables available.
	*/
	int count() {
		return variables.count();
	}

	void add(const RS_String& key, const RS_Vector& value, int code);
	void add(const RS_String& key, const RS_String& value, int code);
	void add(const RS_String& key, int value, int code);
	void add(const RS_String& key, double value, int code);

	RS_Vector getVector(const RS_String& key, const RS_Vector& def);
};


#endif