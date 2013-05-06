#ifndef RS_FONTLIST_H
#define RS_FONTLIST_H

#include "rs_font.h"
#include "rs_entity.h"
#include "rs_ptrlist.h"

#define RS_FONTLIST RSFontList::instance()

/** 
* The global list of fonts, THis is implemented as a singleton.
* Use RS_FontList::instance() to get a pointer to the object.
*/
class RS_FontList {
protected:
	RS_FontList();

public:
	/** 
	* @return Instance to the unique font list.
	*/
	static RS_FontList* instance() {
		if( uniqueInstance==NULL) {
			uniqueInstance = new RS_FontList();
		}
		return uniqueInstance;
	}

	virtual ~RS_FontList() {}

	void init();

	void clearFonts();
	int countFonts() {
		return fonts.count();
	}
	virtual void removeFont(RS_Font* font);
	RS_Font* requestFont(const RS_String& name);
	// @return First font of the list
	RS_Font* firstFont() {
		return fonts.first();
	}
	/** 
	* @return Next font from the list after
	* calling firstFont() or nextFont();
	*/
	RS_Font* nextFont() {
		return fonts.next();
	}

	friend std::ostream& operator << (std::ostream& os, RS_FontList& l);

protected:
	static RS_FontList* uniqueInstance;
private:
	//! fonts in the graphic
	RS_PtrList<RS_Font> fonts;
};


#endif