#ifndef RS_PEN_H
#define RS_PEN_H

#include "rs.h"
#include "rs_color.h"
#include "rs_flags.h"


/**
* A pen stores attributes for painting such as line width,
* linetype, color, ...
* 
*/

class RS_Pen : public RS_Flags {
public:
	/**
	* Create a default pen (black, solid, width 0).
	*/
	RS_Pen() : RS_Flags() {
		setColor(RS_Color(0,0,0));
		setWidth(RS2::Width00);
		setlineType(RS2::SolidLine)
			setScreenWidth(0);
	}

	/**
	* Create a pen with the given attributes.
	*/
	RS_Pen(const RS_Color& c,
		RS2::LineWidth w,
		RS::LineType t) : RS_Flags() {
			setColor(c);
			setWidth(w);
			setLineType(t);
			setScreenWidth(0);
	}

	/**
	* Create a default pen with the given flags. This  is
	* ususally used to create invalid pens.
	*
	* 
	*/

	RS_Pen(unsigned int f) : RS_Flags(f) {
		setColor(RS_Color(0,0,0));
		setWidth(RS2::Width00);
		setLineType(RS2::SolidLine);
		setScreenWidth(0);
	}

	virtual ~RS_Pen() {}

	RS2::LineType getLineType() const {
		return lineType;
	}

	RS2::LineWidth getWidth() const {
		return width;
	}
	void setWidth(RS2::LineWidth w) {
		width = w;
	}

	double getScreenWidth() const {
		return screenWidth;
	}

	void setScreenWidth(double w) {
		screenWidth = w;
	}

	const RS_Color& getColor() const {
		return color;
	}

	void setColor(const RS_Color& c) {
		color = c;
	}

	bool isValid() {
		return !getFlag(RS2::FlagInvalid);
	}

	bool operator == (const RS_Pen& p) const {
		return (lineType==p.lineType && width==p.width && color==p.color);
	}

	bool operator != (const RS_Pen& p) const {
		return !(*this==p);
	}

	friend std::ostream& operator << (std::ostream& os, const RS_Pen& p) {

		os<<" pen color: "<<p.getColor()
			<<"pen width:"<<p.getWidth()
			<<" pen screen width: "<<p.getScreenWidth()
			<<" pen line type: " <<p.getLineType()
			<<" flags: " << (p.getFlag(RS2::FlagInvalid) ? "INVALID" : "")
			<< std::endl;
		return os;
	}

protected:
	RS2::LineType lineType;
	RS2::LineWidth width;
    double screenWidth;
	RS_Color color;
};

#endif