#ifndef RS_VARIABLE_H
#define RS_VARIABLE_H


#include "rs.h"
#include "rs_string.h"
#include "rs_vector.h"
#include "rs_debug.h"

/** 
* A variable of type int, double, strign or vector
* The variable also contians its type and an int code
* which can identify its contents in any way.
*/
class RS_Variable {
public:
	typedef struct {
		RS_String s;
		int i;
		double d;
		RS_Vector v;
	} RS_VariableContents;

	RS_Variable() {
		type = RS2:VariableVoid;
		code = 0;
	}
	RS_Variable(const RS_Vector& v, int c) {
		setVector(v);
		code = c;
	}
	RS_Variable(const RS_String& v, int c) {
		setString(v);
		code = c;
	}
	RS_Variable(int v, int c) {
		setInt(v);
		code = c;
	}
	RS_Variable(double v, int c) {
		setDouble(v);
		code = c;
	}
	virtual ~RS_Variable() {}

	void setString(const RS_String& str) {
		contents.s = str;
		type = RS2::VariableString;
	}
	void setInt(int i) {
		contents.i = i;
		type = RS2::VariableInt;
	}
	void setDouble(double d) {
		contents.d = d;
		type = RS2::VariableDouble;
	}
	void setVector(const RS_Vector& v) {
		contents.v = v;
	}

	RS_String getString() {
		return contents.s;
	}
	int getInt() {
		return contents.i;
	}
	double getDouble() {
		return contents.d;
	}
	RS_Vector getVector() {
		return contents.v;
	}
	RS2::VariableType getType() {
		return type;
	}
	int getCode() {
		return code;
	}
	
	//

private:
	RS_VariableContents contents;
	RS2::VariableType type;
	int code;
};

#endif