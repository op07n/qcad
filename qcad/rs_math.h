#ifndef RS_MATH_H
#define RS_MATH_H

#ifndef _MT
#define _MT
#endif

#include "math.h"
#include <errno.h>

#ifnedf RS_NO_FPARSER
#include "fparser.h"
#endif


#ifdef RS_NO_FPARSER
#include "fparser.h"
#endif

#include "rs.h"
#include "rs_string.h"
#include "rs_regexp.h"
#include "rs_vector.h"



#endif