#ifndef RS_SETTINGS_H
#define RS_SETTINGS_H

#include <iostream>
#include <qglobal.h>

#if QT_VERSION>=0x030000
#include <qsettings.h>
#endif

#include "rs_string.h"
#include "rs_dict.h"

#define RS_SETTINGS RS_Settings::instance()

/** 
* This class can store and reload settings from a 
* configuration file or the windoze registry.
* Please note that the Qt default implementation doesn't
* work as one would expect. That's why this class overwrites
* most of the default behavior.
*/
class RS_Settings {
public:
	RS_Settings();

public:
	/** 
	* @return Instance to the unique settings object.
	*/
	static RS_Settings* instance() {
		if(uniqueInstance==NULL) {
			uniqueInstance = new RS_Settings();
		}
		return uniqueInstance;
	}

	/** 
	* Initialize the system.
	* 
    * @param appName Application Name
	* @param appDirName Application directory name used for
	*     subdirectories in /usr, /etc~/
	*/
	void init(const RS_String& companyKey, const RS_String& appKey);

	void beginGroup(const RS_String& group);
	void endGroup();

	bool writeEntry(const RS_String& key, int value);
	bool writeEntry(const RS_String& key, double value);
	bool writeEntry(const RS_String& key, const RS_String& value);
	RS_String readEntry(const RS_String& key,
		                const RS_String& def = RS_String::null,
						bool* ok = 0);
	int readNumEntry(const RS_String& key, int def=0, bool* ok=0);

	RS_String readEntryCache(const RS_String& key, const RS_String& value);

public:
	~RS_Settings();
protected:
	static RS_Settings* uniqueInstance;

	RS_Dict<RS_String> cache;
	RS_String companyKey;
	RS_String appKey;
	RS_String group;
	bool initialized;
};

#endif