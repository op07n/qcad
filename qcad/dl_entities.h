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


/** 
* generic Dimension data
*/
struct DL_DimensionData {
	/** 
	* Constructor
	* Param
	*/
	DL_DimensionData(double ddpx, double ddpy, double ddpz,
		             double dmpx, double dmpy, double dmpz,
					 int dType,
					 int dAttachmentPoint,
					 int dLineSpacingStyle,
					 double dLineSpacingFactor,
					 const string& dText,
					 const string& dStyle,
					 double dAngle) {
		  dpx = ddpx;
		  dpy = ddpy;
		  dpz = ddpz;

		  mpx = dmpx;
		  mpy = dmpy;
		  mpz = dmpz;

		  type = dType;

		  attachmentPoint = dAttachmentPoint;
		  lineSpacingStyle = dLineSpacingStyle;
		  lineSpacingFactor = dLineSpacingFactor;
		  text = dText;
		  style = dStyle;
		  angle = dAngle;
	}


	/* X Coordinate of definition point */
	double dpx;
	/* Y Coordinate of definition point */
	double dpy;
	/* Z Coordinate of definition point */
	double dpz;
	/* X Coordinate of middle point of the text */
	double mpx;
	/* Y Coordinate of middle point of the text */
	double mpy;
	/* Z Coordinate of middle point of the text */
	double mpz;
	/* 
	* Dimension type
	* 
	* 0   Rotated, horizontal, or vertical
	* 1   Aligned
	* 2   Angular
	* 3   Diametric
	* 4   Radius
	* 5   Angular 3-point
	* 6   Ordinate
	* 64  Ordinate type. This is a bit value (bit 7)
	*     used only with integer value 6. If set.
	*     ordinate is X-Type; if not set , ordinate is
	*     Y -Type
	* 128 This is a bit value (bit 8) added to the 
	*     other group 70 values if the dimension text
	*     has been positioned at a user-defined
	*     location rather than at the default location
	*/
	int type;
    /**
     * Attachment point.
     *
     * 1 = Top left, 2 = Top center, 3 = Top right,
     * 4 = Middle left, 5 = Middle center, 6 = Middle right,
     * 7 = Bottom left, 8 = Bottom center, 9 = Bottom right
     */
    int attachmentPoint;
	/** Line spacing style
	* 
	* 1 = at least, 2= exact
	*/
	int lineSpacingStyle;
	/** 
	* Line spacing factpr. 0.25 .. 0.40
	*/
	double lineSpacingFactor;
	/** 
	* text string
	* 
	* text string entered explicity by user or null
	* or "<>" for the actual measurement or " " (one blank space).
	* for supressing the text.
	*/
	string text;
	/** Dimension style (font name ) */
	string style;
	/** 
	* Rotation angle of dimension text away from
	* default orientation.
	*/
	double angle;
};


/** 
* Aligned Dimension Data.
*/
struct DL_DimAlignedData {
	/** 
	* Constructor
	* Parameters: see member variables
	*/
	DL_DimAlignedData(double depx1, double depy1, double depz1,
		              double depx2, double depy2, double depz2) {

		epx1 = depx1;
		epy1 = depy1;
		epz1 = depz1;

		epx2 = depx2;
		epy2 = depy2;
		epz2 = depz2;
	}

	/* X Coordinate of Extension point 1. */
	double epx1;
	/* Y of Ext point 1 */
	double epy1;
	/* Z of ext point 1 */
	double epz1;

	/* X of the ext p 2 */
	double epx2;
	/* Y of the ext p2  */
	double epy2;
	/* Z of the ext p2 */
	double epz2;
};


/** 
* Linear Dimension Data 
*/
struct DL_DimLinearData {
	DL_DimLinearData(double ddpx1, double ddpy1, double ddpz1,
		             double ddpx2, doouble ddpy2, double ddpz2,
					 double dAngle, double dOblique) {

	}

	/* X of ext p1 */
	double dpx1;
	/* Y 0f ext p1 */
	double dpy1;
	/* Z 0f ext p1 */
	double dpz1;

	/* X of ext p2 */
	double dpx2;
	/* Y 0f ext p2 */
	double dpy2;
	/* Z 0f ext p2 */
	double dpz2;

	/* Rotation angle (angle of dimension line) in degrees. */
	double angle;
	/* Oblique angle in degrees */
	double oblique;

};

/** 
* Radial Dimension data
*/
struct DL_DimRadialData {
	DL_DimRadialData(double ddpx, double ddpy, double ddpz, double dleader) {
		dpx = ddpx;
		dpy = ddpy;
		dpz = ddpz;


		leader = dleader;
	}

	/* X coordinate of definition point */
	double dpx;
	/* Y */
	double dpy;
	/* Z */
	double dpz;

	/* Leader length */
	double leader;
};


/** 
* Diametric  Dimension Data.
*/
struct DL_DimDiametricData {
	DL_DimDiametricData(double ddpx, double ddpy, double ddpz, double dleader) {
		dpx = ddpx;
		dpy = ddpy;
		dpz = ddpz;
		
		leader = dleader;
	}

	/* X Coor of definition point */
	double dpx;
	/* Y Coor of definnition point */
	double dpy;
	/* Z coor of definition point */
	double dpz;

	/* leader length */
};


/** 
* Angular Dimension Data 
*/
struct DL_DimAngularData {
	DL_DimAngularData(double ddpx1, double ddpy1, double ddpz1,
		              double ddpx2, double ddpy2, double ddpz2,
					  double ddpx3, double ddpy3, double ddpz3,
					  double ddpx4, double ddpy4, double ddpz4) {
		ddpx1 = dpx1;
		ddpy1 = dpy1;
		ddpz1 = dpz1;

		ddpx2 = dpx2;
		ddpy2 = dpy2;
		ddpz2 = dpz2;

		ddpx3 = dpx3;
		ddpy3 = dpy3;
		ddpz3 = dpz3;

		ddpx4 = dpx4;
		ddpy4 = dpy4;
		ddpz4 = dpz4;

	}

/* X Coordinate of deinition point 1 */
	double dpx1;
/* Y Coordinate of deinition point 1 */
	double dpy1;
/* Z Coordinate of deinition point 1 */
	double dpz1;

	/* X Coordinate of deinition point2 */
	double dpx2;
	/* Y Coordinate of deinition point 2 */
	double dpy2;
	/* Z Coordinate of deinition point 2 */
	double dpz2;

	/* X Coordinate of deinition point 3 */
	double dpx3;
	/* Y Coordinate of deinition point 3 */
	double dpy3;
	/* Z Coordinate of deinition point 3 */
	double dpz3;

	/* X Coordinate of deinition point4 */
	double dpx4;
	/* Y Coordinate of deinition point4 */
	double dpy4;
	/* Z Coordinate of deinition point4 */
	double dpz4;
};


/** 
* ( Angular Dimension Data (3 Point version )
*/
struct DL_Dimension3PData {
	DL_Dimension3PData(double ddpx1, double ddpy1, double ddpz1,
		double ddpx2, double ddpy2, double ddpz2,
		double ddpx3, double ddpy3, double ddpz3) {

			dpx1 = ddpx1;
			dpy1 = ddpy1;
			dpz1 = ddpz1;

			dpx2 = ddpx2;
			dpy2 = ddpy2;
			dpz2 = ddpz2;

			dpx3 = ddpx3;
			dpy3 = ddpy3;
			dpz3 = ddpz3;

	}
	
	/* X Coordinate of deinition point 1 */
	double dpx1;
	/* Y Coordinate of deinition point 1 */
	double dpy1;
	/* Z Coordinate of deinition point 1 */
	double dpz1;

	/* X Coordinate of deinition point2 */
	double dpx2;
	/* Y Coordinate of deinition point 2 */
	double dpy2;
	/* Z Coordinate of deinition point 2 */
	double dpz2;

	/* X Coordinate of deinition point 3 */
	double dpx3;
	/* Y Coordinate of deinition point 3 */
	double dpy3;
	/* Z Coordinate of deinition point 3 */
	double dpz3;
};

/** 
* Leader (arrow)
*/
struct DL_LeaderData {
	DL_LeaderData(int lArrowHeadFlag,
		          int lLeaderPathType,
				  int lLeaderCreationFlag,
				  int lHooklineDirectionFlag,
				  int lHooklineFlag,
				  double lTexAnnotationHeight,
				  double lTextAnnotationWidth,
				  int lNumber) {
		arrowHeadFlag = lArrowHeadFlag;
		leaderPathType = lLeaderPathType;
		leaderCreationFlag = lLeaderCreationFlag;
		hooklineDirectionFlag = lHooklineDirectionFlag;
		hooklineFlag = lHooklineFlag;
		textAnnotationHeight = lTexAnnotationHeight;
		textAnnotationWidth = lTextAnnotationWidth;
		number = lNumber;
	}

	/* Arrow head flag (71) */
	int arrowHeadFlag;
	/* Leader path type(72) */
	int leaderPathType;
	/* Leader creation flag(73) */
	int leaderCreationFlag;
	/* Hookline direction flag(74) */
	int hooklineDirectionFlag;
	/* Hookline flag */
	int hooklineFlag;
	/* Text annotation height (40) */
	double textAnnotationHeight;
	/* Text annnotation width(41) */
	double textAnnotationWidth;
	/* Number of vertices in leader (76) */
	int number;
};


/** 
* Leader Vertex data.
*/
struct DL_LeaderVertexData {
	DL_LeaderVertexData(double px= 0.0, double py = 0.0, double pz= 0.0) {
		x = px;
		y = py;
		z = pz;
	}

	/* X coor of the vertex */
	double x;
	/* Y of the vertex */
	double y;
	/* Z of the vertex */
	double z;
};


/* 
* hatch data
*/
struct DL_HatchData {
	DL_HatchData() {}

	DL_HatchData(int hNumLoops,
		         bool hSolid,
				 double hScale,
				 double hAngle,
				 const string& hPattern) {
	   numLoops = hNumLoops;
	   solid = hSolid;
	   scale = hScale;
	   angle = hAngle;
	   pattern = hPattern;
	}

    /* Number of boundary paths(loops) */
	int numLoops;
	/* Solid fill flag (tru = solid, false = pattern */
	bool solid;
	/* Pattern scale or spacing */
	double scale;
	/* Pattern angle */
	double angle;
    /* Pattern name */
	string pattern;
};

/** 
* Hatch boundary path (loop) data.
*/
struct DL_HatchLoopData {
	DL_HatchLoopData() {}
	
	DL_HatchLoopData(int hNumEdges) {
		numEdges = hNumEdges;
	}

	/* Number of edges in this loop */
	int numEdges;
};


/** 
* Hatch edge data
*/
struct DL_HatchEdgeData {
	DL_HatchEdgeData() {
		defined = false;
	}

	/** 
	* Constructor for an line edge 
	*/
	DL_HatchEdgeData(double lx1, double ly1,
		             double lx2, double ly2) {
         x1 = lx1;
		 y1 = ly1;
		 x2 = lx2;
		 y2 = ly2;
		 type = 1;
		 defined = true;
	}
	/** 
	* Constructor for an arc edge 
	*/
	DL_HatchEdgeData(double acx, double acy,
		             double aRadius,
					 double aAngle1, double aAngle2,
					 bool aCcw) {
	       cx = acx;
		   cy = acy;
		   radius = aRadius;
		   angle1 = aAngle1;
		   angle2 =aAngle2;
		   ccw = aCcw;
		   type = 2;
		   defined = true;
	}

	/** 
	* Edge type. 1 = line, 2 = arc.
	*/
	int type;

	/** 
	* Set to true if this edge is fully defined.
	*/
	bool defined;

	/* Start p(X) */
	double x1;
	/* Start p(Y) */
	double y1;
	/* End p(X) */
	double x2;
	/* End p(Y) */
	double y2;
	/* Center p of arc(X) */
	double cx;
	/* Center p of arc(Y) */
	double cy;
	/* Arc radius */
	double radius;
	/* Start angle */
	double angle1;
	/* End angle */
	double angle2;
	/* Counterclockwise flag */
	bool ccw;
};

/** 
* Image Data
*/
struct DL_ImageData {
	DL_ImageData(const string& iref,
		         double iipx, double iipy, double iipz,
				             double iux, double iuy, double iuz,
							 double ivx, double ivy, double ivz,
							 int iwidth, int iheight,
							 int ibrightness, int icontrast, int ifade) {
			ref = iref;
			ipx = iipx;
			ipy = iipy;
			ipz = iipz;
			       ux = iux;
			       uy = iuy;
			       uz = iuz;
			       vx = ivx;
			       vy = ivy;
			       vz = ivz;
				   width = iwidth;
				   height = iheight;
				   brightness = ibrightness;
				   constrast = icontrast;
				   fade = ifade;
	}
     
	/* Reference to the image file 
	      (unique, used to refer to the image def object). */
	string ref;
	/* X Coor of insertion p */
	double ipx;
	/* Y Coor of inseteion p */
	double ipy;
	/* Z Coor of insertion */
	double ipz;
	     /* X Co of u vector along bottom of image */
	     double ux;
		 /* Y Co of u vector along bottom of image */
		 double uy;
		 /* Z Co of u vector along bottom of image */
		 double uz;
		 /* X Co of v vector along bottom of image */
		 double vx;
		 /* Y Co of v vector along bottom of image */
		 double vy;
		 /* Z Co of v vector along bottom of image */
		 double vz;
		 /* width of image in pixel */
		 int width;
		 /* Height of image in pixel */
		 int height;
		 /* Brightness(0..100, degfualt = 50 ) */
		 int brightness;
		 /* Contrast (0..100, defualt = 50 ) */
		 int constrast;
		 /* Fade (0..100, defualt = 0) */
		 int fade;
};


/** 
* Image Definition Data
*/
struct DL_ImageDefData {

	DL_ImageDefData(const string& iref,
		                            const string& ifile) {
			ref = iref;
			   file = ifile;
	}

	/* Reference to the  image file 
	     (unique , used to refer to the iamge def object */
	string ref;

	     /* Image file */
	string file;
};

#endif
