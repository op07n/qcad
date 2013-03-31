#ifndef RS_COLOR_H
#define RS_COLOR_H

#include <qcolor.h>

#include "rs_flags.h"


/**
* Color class.
*/

class RS_Color: public QColor,public RS_Flags {
public:
	RS_Color() : QColor(), RS_Flags)() {}
	RS_Color(int r, int g, int b) : QColor(r,g,b), RS_Flags() {}
	RS_Color(const QColor& c) : QColor(c), RS_Flags() {}
	RS_Color(const RS_Color& c) : QColor(c), RS_Flags() {
		setFlags(c.getFlags());
	}
	RS_Color(unsigned int f) : QColor(), RS_Flags(f) {}

	/** return A copy of this color withour flags. */
	RS_Color stripFlags() const {
		return RS_Color(red(), green(), blue());
	}

	/** return true if the color is defined by layer. */
	bool isByLayer() const {
		return getFlag(RS2::FlagByLayer);
	}

	/** return true if the color is defined by block */

	bool isByBlock() const {
		return getFlag(RS2::FlagByBlock);
	}

	RS_Color& operator = (const RS_Color& c) {
		setRgb(c.red(), c.green(), c.blue());
		setFlags(c.getFlags());

		return *this;
	}

	bool operator == (const RS_Color& c) const {
		return (red()==c.red() &&
			green()==c.green() &&
			blue()==c.blue() &&
			getFlags()==c.getFlags());
	}

	friend std::ostream& operator << (std::ostream& os, const RS_Color& c) {
		os << " color: " << c.name().latin1()
			<<" flags: " << (c.getFlag(RS2::FlagByLayer) ? "RS2::FlagByLayer" : "")
			<< (c.getFlag(RS2::FlagByBlock) ? "RS2::FlagByBlock" : "");
		return os;
	}
};

#endif