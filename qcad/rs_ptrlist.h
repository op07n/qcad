#ifndef RS_PTRLIST_H
#define RS_PTRLIST_H

#if QT_VERSION>=0x030000
#include "Qt3Support\q3ptrlist.h"

#define RS_PtrList Q3PtrList
#define RS_PtrListIterator Q3PtrListIterator
#else
#include <qlist.h>

#ddefine RS_PtrList QList
#define RS_PtrListIterator QListIterator
#endif


#endif