#ifndef RS_SCRIPTLIST_H
#define RS_SCRIPTLIST_H

#include "rs_script.h"
#include "rs_ptrlist.h"

#define RS_SCRIPTLIST_H RS_ScriptList::instance()

/** 
* The global list of scripts. This is implemented as a singleton.
* Use RS_SCriptList::instance() to get a pointer to the object.
*/

class RS_ScriptList {
protected:
	RS_ScriptList();

public:
	/** 
	* @return instance to the unique script list.
	*/
	static RS_ScriptList* instance() {
		if(uniqueInstance==NULL) {
			uniqueInstance = new RS_ScriptList();
		}
		return uniqueInstance;
	}

	virtual ~RS_ScriptList() {}

	void init();

	void clearScripts();
	int countScripts() {
		return scripts.count();
	}
	//void activateScript(const RS_String& name);
	//void activateScript(RS_Script* script);
	//
	//
	//
	RS_Script* firstScript() {
		return scripts.first;
	}
	/** @return Next Script from the list after
	* calling firstScript() or nextScript();
	*/
	RS_Script* nextScript() {
		return scripts.next();
	}

	//void addScriptListListener(RS_ScriptListListener* listener);

	static bool test();

protected:
	static RS_ScriptList* uniqueInstance;
private:
	// all scripts avaiable
	RS_PtrList<RS_Script> scripts;
	// List of required ScriptListListeners
	//
	//

};
#endif