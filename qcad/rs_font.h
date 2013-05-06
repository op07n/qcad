#ifndef RS_FONT_H
#define RS_FONT_H

#include <iostream>

#include "rs_blocklist.h"
#include "rs_string.h"
#include "rs_stringlist.h"

/** 
* Class for represnting a font, This is implemented as a RS_Graphic
* with a name (the font name) and several blocks, one for each letter
* in the font
*/
class RS_Font {
	RS_Font(const RS_String& name, bool owner=true);
	//

	/** @return the fileName of this font */
	RS_String getFileName() const {
		return fileName;
	}

	/** @return the encoding of this font */
	RS_String getEncoding() const {
		return encoding;
	}

	/** @return the alternative names of this font */
	const RS_StringList& getNames() const {
		return names;
	}

	/** @return the authors of this font */
	const RS_StringList& getAuthors() const {
		return authors;
	}

	/** return Default letter spacing for this font */
	double getLetterSpacing() {
		return letterSpacing;
	}

	/** return default word spacing for this font */
	double getWordSpacing() {
		return wordSpacing;
	}

	/** return defualt lien spacing factor for this font */
	double getLineSpacingFactor() {
		return lineSpacingFactor;
	}

	bool loadFont();

	// Wrappers for block list (letters) functions
	RS_BlockList* getLetterList() {
		return &letterList;
	}
	RS_Block* findLetter(const RS_String& name) {
		return letterList.find(name);
	}
	uint countLetters() {
		return letterList.count();
	}
	RS_Block* letterAt(uint i) {
		return letterList.at(i);
	}

	friend std::ostream& operator << (std::ostream& os, const RS_Font& l);

	friend class RS_FontList;
private:
	//! block list (letters);
	RS_BlockList letterList;

	// Font filename
	RS_String fileName;

	// Font encoding ( see docu for QTextCodec)
	RS_String encoding;

	// Font names
	RS_StringList names;

	// Authors
	RS_StringList authors;

	//Is this font currently loaded into memory?
	bool loaded;

	// Default leeter spacing fort this font
	double wordSpacing;

	//Default lien spacing factor for this font
	double lineSpacingFactor;
};
#endif