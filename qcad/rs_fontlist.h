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
	int countFonts() {4`}

protected:
	static RS_FontList* uniqueInstance;
private:
	//! fonts in the graphic
	RS_PtrList<RS_Font> fonts;
};
#endif