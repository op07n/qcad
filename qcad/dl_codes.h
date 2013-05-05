#ifndef DXF_CODES_H
#define DXF_CODES_H

#if _MSC_VER >1000
#pragma once
#endif

#if defined(__OS2__)||defined(__EMX__)||defined(_WIN32)
#define  strcasecmp(s,t) stricmp(s,t)
#endif

#ifdef _WIN32
#undef M_PI
#define M_PI 3.14159265358979323846
#pragma warning(disable :4800)
#endif

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#define DL_DXF_MAXLINE 1024
#define DL_DXF_MAXGROUPCODE 1100

//used to mark invalid vectors:
//#define DL_DXF_MAXDOUBLE 1.0E+10

/** 
* Codes for color and DXF versions.\
*/
class DL_Codes {
public:
	/** 
	* Standard DXF colors.
	*/
	enum color {
		black = 250,
		green = 3,
		red = 1,
		brown = 15,
		yellow = 2,
		cyan = 4,
		magenta = 6,
		gray = 8,
		blue = 5,
		l_blue = 163,
		l_greeb = 121,
		l_cyan = 131,
		l_red = 23,
		l_magenta = 221,
		l_grey = 252,
		white = 7,
		bylayer = 256,
		byblock = 0
	};

/** 
* Version numbers for the DXF Format
*/
	enum version {
		AC1009, AC1012, AC1014, AC1015
	};
};

//Extended color palette:
// The first entry is only for direct indexing starting with [1]
// Color 1 is red(1,0,0)
const double dxfColors[][3] = {
	{0,0,0},                // unused
	{1,0,0},                // 1
	{1,1,0},
	{0,1,0},
	{0,1,1},
	{0,0,1},
	{1,0,1},
	{1,1,1},                // black or white
	{0.5,0.5,0.5},
	{0.75,0.75,0.75},
	{1,0,0},                // 10
	{1,0.5,0.5},
	{0.65,0,0},
	{0.65,0.325,0.325},
	{0.5,0,0},
	{0.5,0.25,0.25},
	{0.3,0,0},
	{0.3,0.15,0.15},
	{0.15,0,0},
	{0.15,0.075,0.075},
	{1,0.25,0},             // 20
	{1,0.625,0.5},
	{0.65,0.1625,0},
	{0.65,0.4063,0.325},
	{0.5,0.125,0},
	{0.5,0.3125,0.25},
	{0.3,0.075,0},
	{0.3,0.1875,0.15},
	{0.15,0.0375,0},
	{0.15,0.0938,0.075},
	{1,0.5,0},              // 30
	{1,0.75,0.5},
	{0.65,0.325,0},
	{0.65,0.4875,0.325},
	{0.5,0.25,0},
	{0.5,0.375,0.25},
	{0.3,0.15,0},
	{0.3,0.225,0.15},
	{0.15,0.075,0},
	{0.15,0.1125,0.075},
	{1,0.75,0},             // 40
	{1,0.875,0.5},
	{0.65,0.4875,0},
	{0.65,0.5688,0.325},
	{0.5,0.375,0},
	{0.5,0.4375,0.25},
	{0.3,0.225,0},
	{0.3,0.2625,0.15},
	{0.15,0.1125,0},
	{0.15,0.1313,0.075},
	{1,1,0},                // 50
	{1,1,0.5},
	{0.65,0.65,0},
	{0.65,0.65,0.325},
	{0.5,0.5,0},
	{0.5,0.5,0.25},
	{0.3,0.3,0},
	{0.3,0.3,0.15},
	{0.15,0.15,0},
	{0.15,0.15,0.075},
	{0.75,1,0},             // 60
	{0.875,1,0.5},
	{0.4875,0.65,0},
	{0.5688,0.65,0.325},
	{0.375,0.5,0},
	{0.4375,0.5,0.25},
	{0.225,0.3,0},
	{0.2625,0.3,0.15},
	{0.1125,0.15,0},
	{0.1313,0.15,0.075},
	{0.5,1,0},              // 70
	{0.75,1,0.5},
	{0.325,0.65,0},
	{0.4875,0.65,0.325},
	{0.25,0.5,0},
	{0.375,0.5,0.25},
	{0.15,0.3,0},
	{0.225,0.3,0.15},
	{0.075,0.15,0},
	{0.1125,0.15,0.075},
	{0.25,1,0},             // 80
	{0.625,1,0.5},
	{0.1625,0.65,0},
	{0.4063,0.65,0.325},
	{0.125,0.5,0},
	{0.3125,0.5,0.25},
	{0.075,0.3,0},
	{0.1875,0.3,0.15},
	{0.0375,0.15,0},
	{0.0938,0.15,0.075},
	{0,1,0},                // 90
	{0.5,1,0.5},
	{0,0.65,0},
	{0.325,0.65,0.325},
	{0,0.5,0},
	{0.25,0.5,0.25},
	{0,0.3,0},
	{0.15,0.3,0.15},
	{0,0.15,0},
	{0.075,0.15,0.075},
	{0,1,0.25},             // 100
	{0.5,1,0.625},
	{0,0.65,0.1625},
	{0.325,0.65,0.4063},
	{0,0.5,0.125},
	{0.25,0.5,0.3125},
	{0,0.3,0.075},
	{0.15,0.3,0.1875},
	{0,0.15,0.0375},
	{0.075,0.15,0.0938},
	{0,1,0.5},              // 110
	{0.5,1,0.75},
	{0,0.65,0.325},
	{0.325,0.65,0.4875},
	{0,0.5,0.25},
	{0.25,0.5,0.375},
	{0,0.3,0.15},
	{0.15,0.3,0.225},
	{0,0.15,0.075},
	{0.075,0.15,0.1125},
	{0,1,0.75},             // 120
	{0.5,1,0.875},
	{0,0.65,0.4875},
	{0.325,0.65,0.5688},
	{0,0.5,0.375},
	{0.25,0.5,0.4375},
	{0,0.3,0.225},
	{0.15,0.3,0.2625},
	{0,0.15,0.1125},
	{0.075,0.15,0.1313},
	{0,1,1},                // 130
	{0.5,1,1},
	{0,0.65,0.65},
	{0.325,0.65,0.65},
	{0,0.5,0.5},
	{0.25,0.5,0.5},
	{0,0.3,0.3},
	{0.15,0.3,0.3},
	{0,0.15,0.15},
	{0.075,0.15,0.15},
	{0,0.75,1},             // 140
	{0.5,0.875,1},
	{0,0.4875,0.65},
	{0.325,0.5688,0.65},
	{0,0.375,0.5},
	{0.25,0.4375,0.5},
	{0,0.225,0.3},
	{0.15,0.2625,0.3},
	{0,0.1125,0.15},
	{0.075,0.1313,0.15},
	{0,0.5,1},              // 150
	{0.5,0.75,1},
	{0,0.325,0.65},
	{0.325,0.4875,0.65},
	{0,0.25,0.5},
	{0.25,0.375,0.5},
	{0,0.15,0.3},
	{0.15,0.225,0.3},
	{0,0.075,0.15},
	{0.075,0.1125,0.15},
	{0,0.25,1},             // 160
	{0.5,0.625,1},
	{0,0.1625,0.65},
	{0.325,0.4063,0.65},
	{0,0.125,0.5},
	{0.25,0.3125,0.5},
	{0,0.075,0.3},
	{0.15,0.1875,0.3},
	{0,0.0375,0.15},
	{0.075,0.0938,0.15},
	{0,0,1},                // 170
	{0.5,0.5,1},
	{0,0,0.65},
	{0.325,0.325,0.65},
	{0,0,0.5},
	{0.25,0.25,0.5},
	{0,0,0.3},
	{0.15,0.15,0.3},
	{0,0,0.15},
	{0.075,0.075,0.15},
	{0.25,0,1},             // 180
	{0.625,0.5,1},
	{0.1625,0,0.65},
	{0.4063,0.325,0.65},
	{0.125,0,0.5},
	{0.3125,0.25,0.5},
	{0.075,0,0.3},
	{0.1875,0.15,0.3},
	{0.0375,0,0.15},
	{0.0938,0.075,0.15},
	{0.5,0,1},              // 190
	{0.75,0.5,1},
	{0.325,0,0.65},
	{0.4875,0.325,0.65},
	{0.25,0,0.5},
	{0.375,0.25,0.5},
	{0.15,0,0.3},
	{0.225,0.15,0.3},
	{0.075,0,0.15},
	{0.1125,0.075,0.15},
	{0.75,0,1},             // 200
	{0.875,0.5,1},
	{0.4875,0,0.65},
	{0.5688,0.325,0.65},
	{0.375,0,0.5},
	{0.4375,0.25,0.5},
	{0.225,0,0.3},
	{0.2625,0.15,0.3},
	{0.1125,0,0.15},
	{0.1313,0.075,0.15},
	{1,0,1},                // 210
	{1,0.5,1},
	{0.65,0,0.65},
	{0.65,0.325,0.65},
	{0.5,0,0.5},
	{0.5,0.25,0.5},
	{0.3,0,0.3},
	{0.3,0.15,0.3},
	{0.15,0,0.15},
	{0.15,0.075,0.15},
	{1,0,0.75},             // 220
	{1,0.5,0.875},
	{0.65,0,0.4875},
	{0.65,0.325,0.5688},
	{0.5,0,0.375},
	{0.5,0.25,0.4375},
	{0.3,0,0.225},
	{0.3,0.15,0.2625},
	{0.15,0,0.1125},
	{0.15,0.075,0.1313},
	{1,0,0.5},              // 230
	{1,0.5,0.75},
	{0.65,0,0.325},
	{0.65,0.325,0.4875},
	{0.5,0,0.25},
	{0.5,0.25,0.375},
	{0.3,0,0.15},
	{0.3,0.15,0.225},
	{0.15,0,0.075},
	{0.15,0.075,0.1125},
	{1,0,0.25},             // 240
	{1,0.5,0.625},
	{0.65,0,0.1625},
	{0.65,0.325,0.4063},
	{0.5,0,0.125},
	{0.5,0.25,0.3125},
	{0.3,0,0.075},
	{0.3,0.15,0.1875},
	{0.15,0,0.0375},
	{0.15,0.075,0.0938},
	{0.33,0.33,0.33},       // 250
	{0.464,0.464,0.464},
	{0.598,0.598,0.598},
	{0.732,0.732,0.732},
	{0.866,0.866,0.866},
	{1,1,1}                 // 255
}


// AutoCAD VERSION aliases
#define VER_R12    DL_Codes::AC1009
#define VER_LT2    DL_Codes::AC1009
#define VER_R13    DL_Codes::AC1012   // not supported yet
#define VER_LT95   DL_Codes::AC1012   // not supported yet
#define VER_R14    DL_Codes::AC1014   // not supported yet
#define VER_LT97   DL_Codes::AC1014   // not supported yet
#define VER_LT98   DL_Codes::AC1014   // not supported yet
#define VER_2000   DL_Codes::AC1015
#define VER_2002   DL_Codes::AC1015

//DXF  Group Codes:

//Strings
#define STRGRP_START         0
#define STRGRP_END           9

//Coordinates
#define CRDGRP_START         10
#define CRDGRP_END           19

//Real values
#define RLGRP_START          38
#define RSGRP_END            59

//short integer values
#define SHOGRP_START         60
#define SHOGRP_END           79

//New in Release 13, 
#define SUBCLASS             100

//More coordinates
#define CRD2GRP_START        210
#define CRD2GRP_END          239

//Extended Data strings
#define ESTRGRP_START        1000
#define ESTRGRP_END          1009

//Extended data reals
#define ERLGRP_START         1010
#define ERLGRP_END           1059


#define Y8_COORD_CODE           28
#define Z0_COORD_CODE           30
#define Z8_COORD_CODE           38

#define POINT_COORD_CODE        10
#define INSERT_COORD_CODE       10

#define THICKNESS               39
#define FIRST_REAL_CODE         THICKNESS
#define LAST_REAL_CODE          59
#define FIRST_INT_CODE          60
#define ATTFLAG_CODE            70
#define PLINE_FLAGS_CODE        70
#define LAYER_FLAGS_CODE        70
#define FLD_LEN_CODE            73  //Inside ATTRIB  resbuf
#define LAST_INT_CODE           79
#define X_EXTRU_CODE           210
#define Y_EXTRU_CODE           220
#define Z_EXTRU_CODE           230
#define COMMENT_CODE           999

//Start and endpoints of a line
#define LINE_START_CODE         10
#define LINE_END_CODE           11

//Some codes used by blocks
#define BLOCKS_FLAGS_CODE       70
#define BLOCKS_BASE_CODE        10
#define XREF_DEPENDENT          16
#define XREF_RESOLVED           32
#define REFERENCED              64

#define XSCALE_CODE             41
#define YSCALE_CODE             42
#define ANGLE_CODE              50
#define INS_POINT_CODE          10
#define NAME2_CODE               3

//some codes used by circle entities
#define CENTER_CODE             10
#define RADIUS_CODE             40

#define COND_OP_CODE            -4

//When using ads_buildlist you must use RTDXF0 instead of these
#define ENTITY_TYPE_CODE         0
#define SES_CODE                 0
#define FILE_SEP_CODE            0
#define SOT_CODE                 0
#define TEXTVAL_CODE             1
#define NAME_CODE                2
#define BLOCK_NAME_CODE          2
#define SECTION_NAME_CODE        2
#define ENT_HAND_CODE            5
#define TXT_STYLE_CODE           7
#define LAYER_NAME_CODE          8
#define FIRST_XCOORD_CODE       10
#define FIRST_YCOORD_CODE       20
#define FIRST_ZCOORD_CODE       30
#define L_START_CODE            10
#define L_END_CODE              11
#define TXTHI_CODE              40
#define SCALE_X_CODE            41
#define SCALE_Y_CODE            42
#define SCALE_Z_CODE            43
#define BUGLE_CODE              42
#define ROTATION_CODE           50
#define COLOUR_CODE             62
#define LTYPE_CODE               6


// Attribute flags
#define ATTS_FOLLOW_CODE        66
#define ATT_TAG_CODE             2
#define ATT_VAL_CODE             1
#define ATT_FLAGS_CODE          70
#define ATT_INVIS_FLAG           1
#define ATT_CONST_FLAG           2
#define ATT_VERRIFY_FLAG         4
#define ATT_RESET_FLAG           8

// PLINE defines
//FLags
#define OPEN_PLINE     0x00
#define CLOSED_PLINE   0x01
#define POLYLINE3D     0x80
#define PFACE_MESH     0x40
#define PGON_MESH      0x10
//Vertice follow entity, required in POLYLINES
#define VERTS_FOLLOW_CODE  66
#define VERTEX_COORD_CODE  10


//LAYER flags
#define FROZEN         1
#define FROZEN_BY_DEF  2
#define LOCKED         4
#define OBJECT_USED   64

#define BLOCK_EN_CODE   -2   //
#define E_NAME          -1   //

//  Extended data codes
#define EXTD_SENTINEL   (-3)
#define EXID_STR        1000
#define EXTD_APP_NAME   1001
#define EXTD_CTL_STR    1002
#define EXTD_LYR_STR    1003
#define EXTD_CHUNK      1004
#define EXTD_HANDLE     1005
#define EXTD_POINT      1010
#define EXTD_POS        1011
#define EXTD_DISP       1012
#define EXTD_DIR        1013
#define EXTD_FLOAT      1040
#define EXTD_DIST       1041
#define EXTD_SCALE      1042
#define EXTD_INT16      1072
#define EXTD_INT32      1071

//UCS codes for use in ads_trans
#define WCS_TRANS_CODE      0
#define UCS_TRANS_CODE      1
#define DCS_TRANS_CODE      2
#define PCS_TRANS_CODE      3

#endif


