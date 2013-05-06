
#ifndef RS_FONTCHAR_H
#define RS_FONTCHAR_H

#include "rs_block.h"


/** 
* A character in a font is represneted by this special block class.
*/
class RS_FontChar : public RS_Block {
public:
	/** 
	* @param parent The font this block belongs to.
	* @param name The name of the letter (a unicode char) used as 
	*        an identifier
	* @param basepoint Base point (offset) of the letter (usually 0/0).
	*/
	RS_FontChar(RS_EntityContainer8 parent,
		        const RS_String& name,
				RS_Vector basePoint)
			: RS_Block(parent, RS_BlockData(name, basePoint, false)) {}

	virtual ~RS_FontChar() {}

	/** @return RS2::EntityFontChar */
	virtual RS2::EntityType rtti() const {
		return RS2::EntityFontChar;
	}

protected:
};

#endif