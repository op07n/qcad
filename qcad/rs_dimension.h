#ifndef RS_DIMENSION_H
#define RS_DIMENSION_H

#include "rs_entitycontainer.h"

/** 
* Holds the data taht is common to all dimension entities.
*/
class RS_DimensionData : public RS_Flags {
public:
	/** 
	* default constructor.
	*/
	RS_DimensionData() {}

	/** 
	* Constructor with initialisation.
	* 
	* @param dedinationPoint Definnition point
	* @param middleOfText Middle point of dimension text.
	* @param valign Vetical alignment.
	* @param halign Horizontal alignment.
	* @param lineSpacingStyle Line spacing style
	* @param text Text string entered explicity by user or null
	*           or "<>" for the actual measurement or " "(one black space).
	*           for supressing the text.
	* @param style Dimension style name.
	* @param angle ROtation angle of dimension text away from
	*            default orientation
	*/
};