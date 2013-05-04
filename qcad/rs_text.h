#ifndef RS_TEXT_H
#define RS_TEXT_H

#include "rs_entity.h"
#include "rs_entitycontainer.h"

/** 
* Holds the data that defines a text entity.
*/
class RS_TextData {
public:
	/** 
	* Default constructor. Leaves the data object uninitialized.
	*/
	RS_TextData() {}

	/** 
	* Constructor with initialisation.
	*
	* @param insertionPoint Insertion point
	@ @param height Nominal (initial) text height
	* @param width Reference rectangle width
	* @param valign Vertical alignment
	* @param halign Horizontal alignment
	* @param drawingDirection Drawing direction
	* @param lineSpacingStyle Line spacing style
	* @param lineSpacingFactor Line spacing factor
	* @param text Text string
	* @param style Text style name
	* @param angle Rotation angle
	* @param updateMode RS2::Update will update the text entity instantly
	*     RS2::NoUpdate will not update the entity. You can update
	*     it later manully using the update() method. This is 
	*     often the case since you might want to adjust attributes
	*     after creating a text entity.
	*/
	RS_TextData(const RS_Vector& insertionPoint,
		        double height,
				RS2::VAlign valign,
				RS2::HAlign halign,
				RS2::TextDrawingDirection drawingDirection,
				RS2::TextLineSpacingStyle lineSpacingStyle,
				double lineSpacingFactor,
				const RS_String& text,
				const RS_String& style,
				double angle,
				RS2::UpdateMode updateMode = RS2::Update) {
			this->insertionPoint = insertionPoint;
			this->height = height;
			this->width = width;
			this->valign = valign;
			this->halign = halign;
			this->drawingDirection = drawingDirection;
			this->lineSpacingStyle = lineSpacingStyle;
			this->lineSpacingFactor = lineSpacingFactor;
			this->style = style;
			this->angle = angle;
			this->text = text;
			this->updateMode = updateMode;
	}

	friend class RS_Text;

	friend std::ostream& operator << (std::ostream& os, const RS_TextData& td){
		os<< "("<<td.text.latin1()<<")";
		return os;
	}

public:
	/** insertion point */
	RS_Vector insertionPoint;
	/** Nominal (initial) text height */
	double height;
	/** Reference rectangle width */
	double width;
	/** Vertical alignment */
	RS2::VAlign valign;
	/** Horizontal alignment */
	RS2::HAlign halign;
	/** Drawing direction */
	RS2::TextDrawingDirection drawingDirection;
	/** Line Spacing style */
	RS2::TextLineSpacingStyle lineSpacingStyle;
	/** Line spacing factor */
	double lineSpacingFactor;
	/** Text string */
	RS_String text;
	/** Text style name */
	RS_String style;
	/** Rotation angle */
	double angle;
	/** Update mode */
	RS2::UpdateMode updateMode;
};