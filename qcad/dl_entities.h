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
