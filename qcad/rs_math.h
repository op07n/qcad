#ifndef RS_MATH_H
#define RS_MATH_H

#ifndef _MT
#define _MT
#endif

#include "math.h"
#include <errno.h>

#ifndef RS_NO_FPARSER
#include "fparser.h"
#endif

#include "rs.h"
#include "rs_string.h"
#include "rs_regexp.h"
#include "rs_vector.h"

//#ifdef __GNUC__
//#define min(x,y) (x<y ? x : y)
//#define max(x,y) (x>y ? x : y)
//#endif

#define ARAD 57.29577951308232
#define RS_TOLERANCE 1.0e-10
#define RS_TOLERANCE_ANGLE 1.0e-8

typedef unsigned int uint;


class RS_Math {
public:
	static int round(double v);
	    static double pow(double x, double y);

	static double rad2deg(double a);
	static double deg2rad(double a);
	static double rad2gra(double a);
	static int findGCD(int a, int b);
	static bool isAngleBetween(double a,
		                       double a1, double a2,
							   bool reversed);
	static double correctAngle(double a);
	static double getAngleDifference(double a1, double a2);
	static double makeAngleReadable(double angle, bool readable=true,
		                            bool* corrected=NULL);
	static bool isAngleReadable(double angle);
	static bool isSameDirection(double dir1, double dir2, double tol);
	static double eval(const RS_String& expr, double def = 0.0);

	static bool cmpDouble(double v1, double v2, double tol=0.001);

	static double eval(const RS_String& expr, bool* ok ) {
#ifndef RS_NO_FPARSER
		if(expr.isEmpty()) {
			if(ok!=NULL) {
				*ok = false;
			}
			return 0.0;
		}

		FunctionParser fp;

		fp.AddConstant("pi", M_PI);

		        RS_String s = expr;
				bool done;
				do {
					    done = true;
						int i = s.indexOf(RS_RegExp("[0-9]* [0-9]*/[0-9]*"));
						if(i!=-1) {
							int i2 = s.indexOf(' ', i );
							if(i2!=-1) {
								s.replace(i2, 1, "+");
								done = false;
							}

						}
				}while (!done);
		int ret = fp.Parse( s.toLatin1().constData(), "", true);

		if(ret>=0) {
			if (ok!=NULL) {
				*ok = false;
			}
			return 0.0;
		}

		if ( ok!= NULL) {
			*ok = true;
		}

		return fp.Eval(NULL);
#else
	    //std::cerr << "RS_Math::eval: No FParser support compiled in.\n";
        return expr.toDouble();
#endif
}

	static RS_String doubleToString(double value, double prec);
	static RS_String doubleToString(double value, int prec);


	static void test();

};

#endif