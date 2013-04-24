#ifndef RS_DIALOGFACTORY_H
#define RS_DIALOGFACTORY_H

#include "rs_dialogfactoryinterface.h"
#include "rs_dialogfactoryadapter.h"
#include "rs_debug.h"

#define RS_DIALOGFACTORY RS_DialogFactory::instance()->getFactoryObject()

/** 
* Interface for objects that can create and show dialogs.
*/
class RS_DialogFactory {

private:
	RS_DialogFactory();

public:
	virtual ~RS_DialogFactory() {}

	static RS_DialogFactory* instance();

	void setFactoryObject(RS_DialogFactoryInterface* fo);
	RS_DialogFactoryInterface* getFactoryObject();

	void commandMessage(const RS_String& m);

private:
	RS_DialogFactoryInterface* factoryObject;
	RS_DialogFactoryAdapter factoryAdapter;
	static RS_DialogFactory* uniqueInstance;

};


#endif