#ifndef RS_PTRQUEUE_H
#define RS_PTRQUEUE_H

#if QT_VERSION>=0x030000
#include <qptrqueue.h>

#define RS_PtrQueue QPtrQueue
#else
#include <qqueue.h>

#define RS_PtrQueue QQueue
#endif


#endif