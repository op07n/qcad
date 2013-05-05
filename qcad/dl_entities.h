#ifndef DL_ENTITIES_H
#define DL_ENTITIES_H


#include <string>
using std::string;

/** 
* Layer Data
*/
struct DL_LayerData {
	/** 
	* Parameters: see member variables.
	*/
	DL_LayerData(const string& lName,
		         int bFlags) {
					 NAME = lName;
					 flags = lFlags;
	}

	/** Layer name.   */
	string name;
	/** layer flags.  (1 = frozen, 2= frozen by default, 4 = locked) */
	int flags;
};




/** 
* Block Data.
*/
struct DL_BlockData {
	/** 
	* Constructor.
	* Parameters:  see member variables.
	*/
	DL_BlockData(const string& bName,
		         int bFlags,
				 double bbpx, double bbpy, double bbpz) {
					 name = bName;
					 flags = bFlags;
					 bpx = bbpx;
					 bpy = bbpy;
					 bpz = bbpz;		
	}

/** Block name */
string name;
/** Block flags. (not used currently) */
int flags;
/** X Coordinate of base point */
double bpx;
/** Y Coordinate of base point */
double bpy;
/** Z Coordinate of base point */
double bpz;
};



/** 
* Line type Data
*/
struct DL_LineTypeData {
	/** 
	* Constructor
	* Parameter: see member variables
	*/
	DL_LineTypeData(const string& lName,
		            int lFlags) {
						
	}

/** Line type name. */
string name;
/** Line type flags. */
int flags;
};



/** 
* point Data
*/
struct DL_PointData {
	/** 
	* Constructor
	* Parameters: see member variables
	*/
	DL_PointData(double px=0.0, double py=0.0, double pz=0.0) {
		x = px;
		y = py;
		z = pz;
	}

	/* X Coordinate of the point  */
	double x;
	/* Y Coordinate of the point  */
	double y;
	/* Z Coordinate of the point */
	double z;
};



/** 
* Line Data
*/
struct DL_LineData {
	/** 
	* Constructor.
	* Parameters: see the member variables.
	*/
	DL_LineData(double lx1, double ly1, double lz1,
		        double lx2, double ly2, double lz2) {
					x1 = lx1;
					y1 = ly1;
					z1 = lz1;

					x2 = lx2;
					y2 = ly2;
					z2 = lz2;
	}

	/* X Start coordinate of the point */
	double x1;
	/* Y Start coordinate of the point */
	double y1;
	/* Z Start coordinate of the point */
	double z1;

	/* X End coordinate of the point */
	double x2;
	/* Y End coordinate of the point */
	double y2;
	/* Z End coordinate of the point */
	double z2;
};



/** 
* Arc Data
*/
struct DL_ArcData {
	/** 
	* Constructor
	* Parameters: see member variables
	*/
	DL_ArcData(double acx, double acy, double acz,
		       double aRadius,
			   double aAngle1, double aAngle2) {
				   cx = acx;
				   cy = acy;
				   cz = acz;
				   radius = aRadius;
				   angle1 = aAngle1;
				   angle2 = aAngle2;
	}

/* X Coordinate of center point */
double cx;
/* Y Coordinate of center point */
double cy;
/* Z Coordinate of center point */
double xz;


/* Radius of arc */
double radius;
/* Startangle of arc in degrees. */
double angle1;
/* Endangle of arc in degrees. */
double angle2
};


/** 
* Circle Data
*/
struct DL_CircleData {
	/** 
	* Constructor
	* Parameters: see member variables
	*/
	DL_CircleData(double acx, double acy, double acz,
		          double aRadius) {

					  cx = acx;
					  cy = acy;
					  cz = acz;
					  radius = aRadius;

	}

	/*! X Coordinate of center point. */
	double cx;
	/*! Y Coordinate of center point. */
	double cy;
	/*! Z Coordinate of center point. */
	double cz;

	/* Radius of arc */
	double radius;
};


/** 
* PolyLine Data
*/
struct DL_PolyLineData {
	/** 
	* Constructor
	* Parameters : see member variables
	*/
	DL_PolyLineData(int pNumber, int pMVerteces, int pNVerteces, int pFlags) {
		number = pNumber;
		m = pMVerteces;
		n = pNVerteces;
		flags = pFlags;
	}

	/* Number of vertices in this polyline */
	unsigned int number;

	/* Number of vertices in m direction if polyLine is a polygon mesh */
	unsigned int m;

	/* Number of vertices in n direction if polyline is a polygon mesh */
	unsigned int n;

	/* Flags */
	int flags;
};



/** 
* Vertex Data.
*/
struct DL_VertexData {

	/** 
	* Constructor.
	* Parameters: see member variables
	*/
	DL_VertexData(double px=0.0, double py=0.0, double pz=0.0,
		          double pBulge=0.0) {



	}

/* X Coordinate of the vertex */
double x;
/* Y Coordinate of the vertex */
double y;
/* Z */
double z;
/* Bugle 
* The tangent of 1/4 of the arc angle or 0 for lines */
double bulge;
};


/** 
* Trace Data
*/
struct DL_TraceData {
	double x[4];
	double y[4];
	double z[4];
};

/** 
* Solid Data.
*/
typedef DL_TraceData DL_SolidData;

/** 
* Spline Data
*/
struct DL_SplineData {
	/** 
	* Constructor
	* Parameters: see member variables
	*/
	DL_SplineData(int pDegree, int pNKnots, int pNControl, int pFlags) {
		degree = pDegree;
		nKnots = pNKnots;
		nControl = pNControl;
		flags = pFlags;
	}


	// Degree of the spline curve */
	unsigned int degree;

	/* Number of knots; */ 
	unsigned int nKnots;

	/* Number of control points. */
	unsigned int nControl;

	/* Flags */
	int flags;
};


/** 
* Spline knot data.
*/
struct DL_KnotData {
	DL_KnotData() {}
	/** 
	* Constructor.
	* Parameters: see m,ember variables
	*/
	DL_KnotData(double pk) {
		k = pk;
	}

	/* Knot value */
	double k;
};


/** 
* Spline Control point data
*/
struct DL_ControlPointData {
	/** 
	* Constructor.
	* Parameters: see member variables.
	*/
	DL_ControlPointData(double px, double py, double pz) {
		x = px;
		y = py;
		z = pz;

	}

	/*! X coordinate of the control point. */
	double x;
	/*! Y coordinate of the control point. */
	double y;
	/*! Z coordinate of the control point. */
	double z;
};


/** 
* Ellipse Data
*/
struct DL_EllipseData {
	/** 
	* Constructor
	* Parameters: see member variables
	*/
	DL_EllipseData(double ecx, double ecy, double ecz,
		           double emx, double emy, double emz,
				   double eRatio,
				   double eAngle1, double eAngle2) {

		 cx = ecx;
		 cy = ecy;
		 cz = ecz;
		 mx = emx;
		 my = emy;
		 mz = emz;
		 ratio = eRatio;
		 angle1 = eAngle1;
		 angle2 = eAngle2;
		 
	}


/* X Coordinate of center point */
double cx;
/* Y of the center point */
double cy;
/* Z of the center point */
double cz;


/* X of the endpoint of the major axis */
double mx;
/* Y of the endpoint of the major axis */
double my;
/* Z of the endpoint of the major axis */
double mz;

/* Ratio of the minor axis to the major  axis */
double ratio;
/* Startangle of the ellipse in rad */
double angle1;
/* endangle of the ellipse in rad */
double angle2;
};


/** 
* Insert Data.
*/
struct DL_InsertData {
	/** 
	* Constructor
	* Parameters: see member variables
	*/
	DL_InsertData(const string& iName,
		double iipx, double iipy, double iipz,
		double isx, double isy, double isz,
		double iAngle,
		int iCols, int iRows, 
		double iColSp, double iRowSp) {
			name = iName;
			ipx = iipx;
			ipy = iipy;
			ipz = iipz;
			sx = isx;
			sy = isy;
			sz = isz;
			angle = iAngle;
			cols = iCols;
			rows = iRows;
			colSp = iColSp;
			rowSp = iRowSp;
	}


	/* Name of the referred block */
	string name;
	/* X of the insertion point */
	double ipx;
	/* Y of insertion point */
	double ipy;
	/* Z of insertion point */
	double ipz;
	/* X Scale factor */
	double sx;
	/* Y Scale factor */
	double sy;
	/* Z Scale factor */
	double sz;
	/* Rotation angle in rad */
	double angle;
	/* Number of colums if we insert an array of the block or 1. */
	int cols;
	/* Num of row if we insert an array of the block or 1 */
	int rows;
	/* Values for the spacing between cols. */
	double colSp;
	/* Values for the spacing between rows. */
	double rowSp;
};


/** 
* MText Data
*/
struct DL_MTextData {
	/** 
	* Constructor
	* Parameters: see member variables.
	*/
	DL_MTextData(double tipsx, double tipy, double tipz,
		         double tHeight, double tWidth,
				 int tAttachmentPoint,
				 int tDrawingDirection,
				 int tLineSpacingStyle,
				 double tLineSpacingFactor,
				 const string& tText,
				 const string& tStyle,
				 double tAngle) {
    ipx = tipx;
	}


	/*! X Coordinate of insertion point. */
	double ipx;
	/*! Y Coordinate of insertion point. */
	double ipy;
	/*! Z Coordinate of insertion point. */
	double ipz;
	/* Text height */
	double height;
	/* Width of the text box */
	double width;
	/** 
	* Atachment point 
	* 1 = top Left, 2 = Top center, 3 = Top Right
	* 4 = Middle left, 5 = Middle center, 6 = Middle right,
	* 7 = Boottom left , 8 = Bottom center, 9 = Bottom right
	*/
	int attachmentPoint;
	/** 
	* Drawing direction
	* 
	* 1 = left to right, 3 = top to bottom, 5 = by style
	*/
	int drawingDirection;
	/** 
	* Line spacing style.
	* 
	* 1 = at least, 2= exact
	*/
	int lineSpacingStyle;
	/* Text string */
	string text;
	/* Style string */
	string style;
	/* Rotation angle */
	double angle;
};


/** 
* Text Data
*/
struct DL_TextData {
	/** 
	* Constructor
	* Param
	*/
	DL_TextData(double tipx, double tipy, double tipz,
		        double tapx, double tapy, double tapz,
				double tHeight, double tXScaleFactor,
				int tTextGenerationFlags,
				int tHJustification,
				int tVjustification,
				const string& tText,
				const string& tStyle,
				double tAngle) {
		 ipx = tipx;
		 ipy = tipy;
		 ipz = tipz;

		 apx = tapx;
		 apy = tapy;
		 apz = tapz;

		 height = tHeight;
		 xScaleFactor = tXScaleFactor;
		 textGenerationFlags = tTextGenerationFlags;
		 hJustification = tHJustification;
		 vJustification = tVjustification;
		 text = tText;
		 style = tStyle;
		 angle = tAngle;
	}


	/*! X Coordinate of insertion point. */
	double ipx;
	/*! Y Coordinate of insertion point. */
	double ipy;
	/*! Z Coordinate of insertion point. */
	double ipz;

	/* X of alignment point */
	double apx;
	/* Y of alignment point */
	double apy;
	/* Z of alignment point */
	double apz;

	/* Text height */
	double height;
	/* Relative X Scale factor */
	double xScaleFactor;
	/* 0 = default, 2= Backwards, 4 = Upside down */
	int textGenerationFlags;
	/** 
	* Horizontal justfication
	*
	* 0 = left (default) , 1 = Center, 2= Right,
	* 3 = aligned,  4 = Middle, 5 = Fit
	* FOr 3, 4,4 the vertical alignment has to be 0.
	*/
	int hJustification;
	/** 
	* Vertical justification
	*
	* 0 = Baseline (default) , 1 = Bottom, 2 = Middle, 3 = Top
	*/
	int vJustification;
	/* Text string */
	string text;
	/* Style (font) */
	string style;
	/* Rotation angle of dimension text away from default orientation */
	double angle;
};