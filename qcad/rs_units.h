#ifndef RS_UNITS_H
#define RS_UNITS_H

#include "rs.h"
#include "rs_string.h"
#include "rs_vector.h"

/** 
* Conversion methods for units
*/
class RS_Units {
	public:
		//static char* unit2sign(RS2::Unit unit);

		//static RS2::Units string2unit(const char* str, bool* ok=0);
		//static char* unit2string(RS2::Unit unit);

		static RS2::Unit dxfint2unit(int dxfint);

		static RS_String unitToString(RS2::Unit u, bool t = true);
		static RS2::Unit stringToUnit(const RS_String& u);

		static bool isMetric(RS2::Unit u);
		static double getFactorToMM(RS2::Unit u);
		static double convert(double val, RS2::Unit src, RS2::Unit dest);
		static RS_Vector convert(const RS_Vector val, RS2::Unit src, RS2::Unit dest);

		static RS_String unitToSign(RS2::Unit u);

		static RS_String formatLinear(double length, RS2::Unit unit,
			                          RS2::LinearFormat format,
									  int prec, bool showUnit=false);
		static RS_String formatScientific(double length, RS2::Unit unit,
			                              int prec, bool showUnit=false);
		static RS_String formatDecimal(double length, RS2::Unit unit,
			                           int prec, bool showUnit=false);
		static RS_String formatEngineering(double length, RS2::Unit unit,
			int prec, bool showUnit=false);
		static RS_String formatArchitectural(double length, RS2::Unit unit,
			int prec, bool showUnit=false);
		static RS_String formatFractional(double length, RS2::Unit unit,
			int prec, bool showUnit=false);

		static RS_String formatAngle(double angle, RS2::AngleFormat format,
			                          int prec);

		static RS_Vector paperFormatToSize(RS2::PaperFormat p);
		static RS2::PaperFormat paperSizeToFormat(const RS_Vector s);

		static RS_String paperFormatToString(RS2::PaperFormat p);
		static RS2::PaperFormat stringToPaperFormat(const RS_String& p);

		static void test();
};

#endif