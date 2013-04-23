#ifndef RS_STRING_H
#define RS_STRING_H

#include <assert.h>

#include <qstring.h>

#define RS_String QString
#define RS_Char QChar

class RS_StringCompat {
public:
	static RS_String replace(const RS_String& str, RS_Char c1, RS_Char c2);
	static RS_String replace(const RS_String& str,
		const RS_String& s1, const RS_String& s2);
	static void test();
};

#endif