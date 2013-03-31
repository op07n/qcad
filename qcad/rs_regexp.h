#ifndef RS_REGEXP_H
#define RS_REGEXP_H

#include <qregexp.h>

#if QT_VERSION>=0x030000

#define RS_RegExp QRegExp

#else

class RS_RegExp : public QRegExp {
public:
	RS_RegExp(const RS_String& pattern, bool caseSensitive = TRUE,
		bool wildcard = FALSE ):
	QRegExp(pattern, caseSensitive, wildcard) {
		thecap = "";
	}

	int RS_RegExp::search(const RS_String& str, int offset = 0) {
		int len = 0;
		int pos = 0;
		pos = match(str, offset, &len, true);
		if(pos!=-1) {
			thecap = str.mid(pos, len);
		}
		else {
			thecap = "";
		}
		return pos;
	}

	RS_String RS_RegExp::cap() {
		return thecap;
	}

private:
	RS_String thecap;
}

#endif

#endif