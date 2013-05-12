#ifndef RS_H
#define RS_H

#include <qnamespace.h>
#include <qprinter.h>

#define RS_TEST

#ifdef RS_TEST
#include <assert.h>
#endif

//Windows XP can't handle the original MAX/MINDOUBLE's
#define RS_MAXDOUBLE 1.0E+10
#define RS_MINDOUBLE -1.0E+10



/**
* Class namespace for various enum along with some simple.
* wrapper methods for converting the enums to the Qt
* counterparts.
*
* @author Andrew Mustun
*/

class RS2 {
public:

	/**
	* Flags.
	*/
	enum Flags {
		/** Flags for Undoable. */
		FlagUndone      = 1<<0,
		/** Entity Visibility. */
		FlagVisible     = 1<<1,
		/** Entity attribute (e.g. color) is definde by layer. */
		FlagByLayer     = 1<<2,
		/** Entity attribute (e.g. color) defined by block. */
		FlagByBlock     = 1<<3,
		/** Layer frozen. */
		FlagFrozen      = 1<<4,
		/** Layer frozen by default. */
		FlagDefFrozen   = 1<<5,
		/** Layer locked. */
		FlagLocked      = 1<<6,
		/** Used for invalid pens.  */
		FlagInvalid    = 1<<7,
		/** Entity in current selection */
		FlagSelected    = 1<<8,
		/** Polyline closed? */
		FlagClosed      = 1<<9,
		/** Flag for temporary entities (e.g. hatch) */
		FlagTemp        = 1<<10,
		/** Flag for processed entities (optcontour) */
		FlagProcessed   = 1<<11,
		/** Startpoint selected */
		FlagSelected1   = 1<<12,
		/** Endpoint selected */
		FlagSelected2   = 1<<13,
		/** Entity is highlighted temporaly (as a user action feedback) */
		FlagHighlighted = 1<<14
	};


	/** 
	* Variable types used by RS_VariableDict and RS_Variable.
	*/

	enum VariableType {
		VariableString,
		VariableInt,
		VariableDouble,
		VariableVector,
		VariableVoid
	};

	/**
	* File types. Used by file dialogs. Note: the extension might not
	* be enough to distinguish file types.
	*/

	enum FormatType {
		FormatUnknown,          /**< Unknow */
		FormatDXF1,            /**< QCad 1 compatibility DXF fromat. */
		FormatDXF,             /**< DXF format. 2000. */
		FormatDXF12,           /**< DXF format. R12.  */
		FormatCXF,             /**< CAM Expert Font format.  */
		FormatCAM              /**< CAM Expert CAM format (NC, CNC, D, ..) */
	};

	/**
	* Entity types returned by the rtti() method 
	*/
	enum EntityType {
		EntityUnknown,
		EntityContainer,
		EntityBlock,
		EntityFontChar,
		EntityInsert,
		EntityGraphic,
		EntityPoint,
		EntityLine,
		EntityPolyline,
		EntityVertex,
		EntityArc,
		EntityCircle,
		EntityEllipse,
		EntitySolid,
		EntityConstructionLine,
		EntityText,
		EntityDimAligned,
		EntityDimLinear,
		EntityDimRadial,
		EntityDimDiametric,
		EntityDimAngular,
		EntityDimLeader,
		EntityHatch,
		EntityImage,
		EntitySpline
	};

	enum ActionType {
		ActionNone,

		ActionDefault,

		ActionFileNew,
		ActionFileOpen,
		ActionFileSave,
		ActionFileSaveAs,
		ActionFileExport,
		ActionFileClose,
		ActionFilePrint,
		ActionFilePrintPreview,
		ActionFileQuit,

		ActionPrintPreview,

		ActionEditUndo,
		ActionEditRedo,
		ActionEditCut,
		ActionEditCutNoSelect,
		ActionEditCopy,
		ActionEditCopyNoSelect,
		ActionEditPaste,

		ActionViewStatusBar,
		ActionViewLayerList,
		ActionViewBlockList,
		ActionViewCommandLine,
		ActionViewOptionToolbar,
		ActionViewGrid,
		ActionViewDraft,

		ActionZoomIn,
		ActionZoomOut,
		ActionZoomAuto,
		ActionZoomWindow,
		ActionZoomPan,
		ActionZoomRedraw,
		ActionZoomPrevious,

		ActionSelectSingle,
		ActionSelectContour,
		ActionSelectWindow,
		ActionDeselectWindow,
		ActionSelectAll,
		ActionDeselectAll,
		ActionSelectIntersected,
		ActionDeselectIntersected,
		ActionSelectInvert,
		ActionSelectLayer,
		ActionSelectDouble,

		ActionDrawArc,
		ActionDrawArc3P,
		ActionDrawArcParallel,
		ActionDrawArcTangential,
		ActionDrawCircle,
		ActionDrawCircle2P,
		ActionDrawCircle3P,
		ActionDrawCircleCR,
		ActionDrawCircleParallel,
		ActionDrawEllipseArcAxis,
		ActionDrawEllipseAxis,
		ActionDrawHatch,
		ActionDrawHatchNoSelect,
		ActionDrawImage,
		ActionDrawLine,
		ActionDrawLineAngle,
		ActionDrawLineBisector,
		ActionDrawLineFree,
		ActionDrawLineHorVert,
		ActionDrawLineHorizontal,
		ActionDrawLineOrthogonal,
		ActionDrawLineParallel,
		ActionDrawLineParallelThrough,
		ActionDrawLinePolygon,
		ActionDrawLinePolygon2,
		ActionDrawLineRectangle,
		ActionDrawLineRelAngle,
		ActionDrawLineTangent1,
		ActionDrawLineTangent2,
		ActionDrawLineVertical,
		ActionDrawPoint,
		ActionDrawSpline,
		ActionDrawPolyline,
		ActionDrawText,

		ActionPolylineAdd,
		ActionPolylineAppend,
		ActionPolylineDel,
		ActionPolylineDelBetween,
		ActionPolylineTrim,

		ActionDimAligned,
		ActionDimLinear,
		ActionDimLinearVer,
		ActionDimLinearHor,
		ActionDimRadial,
		ActionDimDiametric,
		ActionDimAngular,
		ActionDimLeader,

		ActionModifyAttributes,
		ActionModifyAttributesNoSelect,
		ActionModifyDelete,
		ActionModifyDeleteNoSelect,
		ActionModifyDeleteQuick,
		ActionModifyDeleteFree,
		ActionModifyMove,
		ActionModifyMoveNoSelect,
		ActionModifyRotate,
		ActionModifyRotateNoSelect,
		ActionModifyScale,
		ActionModifyScaleNoSelect,
		ActionModifyMirror,
		ActionModifyMirrorNoSelect,
		ActionModifyMoveRotate,
		ActionModifyMoveRotateNoSelect,
		ActionModifyRotate2,
		ActionModifyRotate2NoSelect,
		ActionModifyEntity,
		ActionModifyTrim,
		ActionModifyTrim2,
		ActionModifyTrimAmount,
		ActionModifyCut,
		ActionModifyStretch,
		ActionModifyBevel,
		ActionModifyRound,

		ActionSnapFree,
		ActionSnapGrid,
		ActionSnapEndpoint,
		ActionSnapOnEntity,
		ActionSnapCenter,
		ActionSnapMiddle,
		ActionSnapDist,
		ActionSnapIntersection,
		ActionSnapIntersectionManual,

		ActionRestrictNothing,
		ActionRestrictOrthogonal,
		ActionRestrictHorizontal,
		ActionRestrictVertical,

		ActionSetRelativeZero,
		ActionLockRelativeZero,
		ActionUnlockRelativeZero,

		ActionInfoInside,
		ActionInfoDist,
		ActionInfoDist2,
		ActionInfoAngle,
		ActionInfoTotalLength,
		ActionInfoTotalLengthNoSelect,
		ActionInfoArea,

		ActionLayersDefreezeAll,
		ActionLayersFreezeAll,
		ActionLayersAdd,
		ActionLayersRemove,
		ActionLayersEdit,
		ActionLayersToggleView,
		ActionLayersToggleLock,

		ActionBlocksDefreezeAll,
		ActionBlocksFreezeAll,
		ActionBlocksAdd,
		ActionBlocksRemove,
		ActionBlocksAttributes,
		ActionBlocksEdit,
		ActionBlocksInsert,
		ActionBlocksToggleView,
		ActionBlocksCreate,
		ActionBlocksCreateNoSelect,
		ActionBlocksExplode,
		ActionBlocksExplodeNoSelect,

		ActionModifyExplodeText,
		ActionModifyExplodeTextNoSelect,

		ActionLibraryInsert,

		ActionOptionsGeneral,
		ActionOptionsDrawing,

		ActionToolRegenerateDimensions,

		ActionScriptOpenIDE,
		ActionScriptRun,

#ifndef RS_NO_COMPLEX_ENTITIES
		ActionPARISDebugCreateContainer,
#endif

#ifdef RS_CAM
		ActionCamExportAuto,
		ActionCamReorder,

#endif

		/** Needed to loop through all actions */
		ActionLast
	};

	/**
	* Entity ending. Used for returning which end of an entity  is met
	*/

	enum Ending {
		EndingStart,    /**<Start point. > */
		EndingEnd,      /**<End point.> */
		EndingNone      /**< Neither.  */
	};

	/**
	* Update mode for non-atomic entities that need to be updated ehen 
	* they change. e.g. texts, inserts, ...
	*/

	enum UpdateMode {
		NoUpdate,    
		Update,
		PreviewUpdate
	};

	/**
	* Drawing mode.
	*/
	enum DrawingMode {
		ModeFull,
		ModeAuto,  
		ModePreview,
		ModeXOR,
		ModeBW
	};

	/**
	* Undoable rtti
	*/

	enum UndoableType {
		UndoableUnknown,
		UndoableEntity,
		UndoableLayer
	};

	/**
	* Toolbar ID's.
	*/

	enum ToolBarId {
		ToolBarMain,
		ToolBarPoints,
		ToolBarLines,
		ToolBarArcs,
		ToolBarCircles,
		ToolBarEllipses,
		ToolBarSplines,
		ToolBarPolylines,
		ToolBarText,
		ToolBarDim,
		ToolBarSnap,
		ToolBarModify,
		ToolBarSelect,
		ToolBarInfo
	};


	/**
	* Units.
	*/

	enum Unit {
		None = 0,
		Inch = 1,
		Foot = 2,
		Mile = 3,
		Millimeter = 4,
		Centimeter = 5,
		Meter  = 6,
		Kilometer = 7,
		Microinch = 8,
		Mil = 9,
		Yard = 10,
		Angstrom = 11,
		Nanometer = 12,
		Micron = 13,
		Decimeter = 14,
		Decameter = 15,
		Hectometer = 16,
		Gigameter = 17,
		Astro = 18,
		Lightyear = 19,
		Parsec = 20,

		LastUnit = 21

	};

	/**
	* Format for length values.
	*/

	enum LinearFormat {
		/** Scientific (e.g. 2.5E+05)*/
		Scientific,
		/** Decimal (e.g. 9.5)*/
		Decimal,
		/** Engineering (e.g. 7' 11.5 ")*/
		Engineering,
		/** Architectural (e.g. 7'-9 1/8")*/
		Architectural,
		/** Fractional (e.g. 7 9 1/8) */
		Fractional
	};

	/**
	* Angle Units.
	*/

	enum AngleUnit {
		Deg,
		Rad,
		Gra
	};

	/**
	* Display formats for angles.
	*/

	enum AngleFormat {
		DegreesDecimal,
		DegreesMinutesSeconds,
		Gradians,
		Radians,
		Surveyors
	};

	/**
	* Enum of levels of resolving when iterating trough an entity tree.
	*/

	enum ResolveLevel {
		ResolveNone,
		/**
		* Resolve all but not Inserts.
		*/
		ResolveAllButInserts,
		/**
		* all Entity Containers are resolved
		* (including Texts, Polylines, ...)
		*/
		ResolveAll
	};

	enum Direction {
		Up, Left, Right, Down
	};

	/**
	* Vertical alignments.
	*/

	/**
	* Vertical alignments.
	*/

	enum VAlign {
		VAlignTop,    /**< Top. */
		VAlignMiddle, /**< Middle */
		VAlignBottom  /**< Bottom  */
	};

	/**
	* Horizontal alignments.
	*/

	enum HAlign {
		HAlignLeft,
		HAlignCenter,
		HAlignRight
	};
	/**
	* Text drawing direction.
	*/
	enum TextDrawingDirection 
	{
		LeftToRight,
		TopToBottom,
		ByStyle
	};

	enum TextLineSpacingStyle {
		AtLeast,
		Exact
	};
	/**
	* Leader path type.
	*/
	enum LeaderPathType {
		Straight,
		Spline
	};

	/**
	* Direction for zooming actions.
	*/

	enum ZoomDirection {
		In, Out
	};

	/**
	* Axis specification for zooming actions.
	*/
	enum Axis {
		OnlyX, OnlyY, Both
	};

	/**
	* Snap Mode
	*/

	enum SnapMode {
		SnapFree,
		SnapGrid,
		SnapEndpoint,
		SnapMiddle,
		SnapCenter,
		SnapOnEntity,
		SnapDist,
		SnapIntersection,
		SnapIntersectionManual
	};

	/** 
	* Snap restrictions
	*/
	enum SnapRestriction {
		RestrictNothing,
		RestrictOrthogonal,
		RestrictHorizontal,
		RestrictVertical
	};

	/**
	* Mouse button and keyboard state for mouse events.
	*/

	enum ButtonState {
		NoButton        = Qt::NoButton,
		LeftButton      = Qt::LeftButton,
		RightButton     = Qt::RightButton,
		MidButton       = Qt::MidButton,
		MouseButtonMask = Qt::MouseButtonMask,
		ShiftButton     = Qt::ShiftButton,
		ControlButton   = Qt::ControlButton,
		AltButton       = Qt::AltButton,
#if QT_VERSION >= 0x030000
		MetaButton      = Qt::MetaButton,
#endif
		KeyButtonMask   = Qt::KeyButtonMask,
		Keypad          = Qt::Keypad

	};

	/**
	* Wrapper for QT
	*/
	static Qt::ButtonState rsToQtButtonState(RS2::ButtonState t) {
		return (Qt::ButtonState)t;
	}

	static RS2::ButtonState qtToRsButtonState(Qt::ButtonState t) {
		return (RS2::ButtonState)t;
	}
	/**
	* Enum of line styles:
	*/
	enum LineType {
		NoPen = 0,
		SolidLine =1,

		DotLine = 2,
		DotLine2 = 3,
		DotLineX2 = 4,

		DashLine = 5,
		DashLine2 = 6,
		DashLineX2 = 7,

        DashDotLine = 8, 
        DashDotLine2 = 9,    
        DashDotLineX2 = 10, 

		DivideLine = 11,
		DivideLine2 = 12,
		DivideLineX2 = 13,

		CenterLine = 14,
		CenterLine2 = 15,
		CenterLineX2 = 16,

		BorderLine = 17,
		BorderLine2 = 18,
		BorderLineX2 = 19,

		LineByLayer = -1,
		LineByBlock = -2

	};

	/**
	* Wrapper for Qt
	*/

	static Qt::PenStyle rsToQtLineType(RS2::LineType t) {
		switch (t) {
		case NoPen:
			return Qt::NoPen;
			break;
		case SolidLine:
			return Qt::SolidLine;
			break;
		case DotLine:
		case DotLine2:
		case DotLineX2:
			return Qt::DotLine;
			break;
		case DashLine:
		case DashLine2:
		case DashLineX2:
			return Qt::DashLine;
			break;
		case DashDotLine:
		case DashDotLine2:
		case DashDotLineX2:
			return Qt::DashDotLine;
			break;
		case DivideLine:
		case DivideLine2:
		case DivideLineX2:
			return Qt::DashDotDotLine;
			break;
		case CenterLine:
		case CenterLine2:
		case CenterLineX2:
			return Qt::DashDotLine;
			break;
		case BorderLine:
		case BorderLine2:
		case BorderLineX2:
			return Qt::DashDotLine;
			break;
		case LineByLayer:
		case LineByBlock:
		default:
			return Qt::SolidLine;
			break;
		}
		return Qt::SolidLine;
	}


	/**
	* Wrapper for Qt.
	*/

	static RS2::LineType qtToRsPenStyle(Qt::PenStyle s) {
		switch (s) {
		case Qt::NoPen:
			return NoPen;
		case Qt::SolidLine:
			return SolidLine;
			break;
		case Qt::DashLine:
			return DashLine;
			break;
		case Qt::DotLine:
			return DotLine;
			break;
		case Qt::DashDotLine:
			return DashDotLine;
			break;
		case Qt::DashDotDotLine:
			return DivideLine;
			break;
		default:
			return SolidLine;
			break;
		}
		return SolidLine;
	}



	/**
	* \brief Struct that stores a line type pattern (e.g. dash dot dot).
	*/

	struct LineTypePatternStruct {
		double* pattern;
		int num;
	}
	LineTypePattern;

	/**
	* Enum of Line widths:
	*/

	enum LineWidth {
		Width00 = 0,
		Width01 = 5,
		Width02 = 9,
		Width03 = 13,
		Width04 = 15,
		Width05 = 18,
		Width06 = 20,
		Width07 = 25,
		Width08 = 30,
		Width09 = 35,
		Width10 = 40,
		Width11 = 50,
		Width12 = 53,
		Width13 = 60,
		Width14 = 70,
		Width15 = 80,
		Width16 = 90,
		Width17 = 100,
		Width18 = 106,
		Width19 = 120,
		Width20 = 140,
		Width21 = 158,
		Width22 = 200,
		Width23 = 211,
		WidthByLayer = -1,
		WidthByBlock = -2,
		WidthDefault = -3
	};

	/**
	* Wrapper for Qt
	*/
	static LineWidth intToLineWidth(int w) {
		if ( w == -3) {
			return WidthDefault;
		} else if (w == -2) {
			return WidthByBlock;
		} else if (w == -1) {
			return WidthByLayer;
		} else if (w<3) {
			return Width00;
		} else if (w<8) {
			return Width01;
		} else if (w<12) {
			return Width02;
		} else if (w<14) {
			return Width03;
		} else if (w<17) {
			return Width04;
		} else if (w<19) {
			return Width05;
		} else if (w<23) {
			return Width06;
		} else if (w<28) {
			return Width07;
		} else if (w<33) {
			return Width08;
		} else if (w<38) {
			return Width09;
		} else if (w<46) {
			return Width10;
		} else if (w<52) {
			return Width11;
		} else if (w<57) {
			return Width12;
		} else if (w<66) {
			return Width13;
		} else if (w<76) {
			return Width14;
		} else if (w<86) {
			return Width15;
		} else if (w<96) {
			return Width16;
		} else if (w<104) {
			return Width17;
		} else if (w<114) {
			return Width18;
		} else if (w<131) {
			return Width19;
		} else if (w<150) {
			return Width20;
		} else if (w<180) {
			return Width21;
		} else if (w<206) {
			return Width22;
		}  else {
			return Width23;
		}

	}


	/**
	* Enum of cursor types.
	*/
	enum CursorType {
		ArrowCursor,
		UpArrowCursor,
		CrossCursor,
		WaitCursor,
		IbeamCursor,
		SizeVerCursor,
		SizeHorCursor,
		SizeBDiagCursor,
		SizeFDiagCursor,
		SizeAllCursor,
		BlankCursor,
		SplitVCursor,
		SplitHCursor,
		PointingHandCursor,
		ForbiddenCursor,
		WhatsThisCursor,
		CadCursor,
		DelCursor,
		SelectCursor,
		MagnifierCursor,
		MovingHandCursor
	};

	/**
	* Wrapper for Qt.
	*/
#if QT_VERSION>=0x030000
	static Qt::CursorShape rsToQtCursorType(RS2::CursorType t) {
		switch (t) {
		case ArrowCursor:
			return Qt::ArrowCursor;
			break;
		case UpArrowCursor:
			return Qt::UpArrowCursor;
			break;
		case CrossCursor:
			return Qt::CrossCursor;
			break;
		case WaitCursor:
			return Qt::WaitCursor;
			break;
		case IbeamCursor:
			return Qt::IBeamCursor;
			break;
		case SizeVerCursor:
			return Qt::SizeVerCursor;
			break;
		case SizeHorCursor:
			return Qt::SizeHorCursor;
			break;
		case SizeBDiagCursor:
			return Qt::SizeBDiagCursor;
			break;
		case SizeFDiagCursor:
			return Qt::SizeFDiagCursor;
			break;
		case SizeAllCursor:
			return Qt::SizeAllCursor;
			break;
		case BlankCursor:
			return Qt::BlankCursor;
            break;
        case SplitVCursor:
            return Qt::SplitVCursor;
            break;
        case SplitHCursor:
            return Qt::SplitHCursor;
            break;
        case PointingHandCursor:
            return Qt::PointingHandCursor;
            break;
        case ForbiddenCursor:
            return Qt::ForbiddenCursor;
            break;
        case WhatsThisCursor:
            return Qt::WhatsThisCursor;
			break;
		default:
			return Qt::ArrowCursor;
			break;
		}
		return Qt::ArrowCursor;
	}
#endif

	/**
	* Paper formats.
	*/
	enum PaperFormat {
		Custom,
		Letter,
		Legal,
		Executive,
		A0,
		A1,
		A2,
		A3,
		A4,
		A5,
		A6,
		A7,
		A8,
		A9,
		B0,
		B1,
		B2,
		B3,
		B4,
		B5,
		B6,
		B7,
		B8,
		B9,
		B10,
		C5E,
		Comm10E,
		DLE,
		Folio,
		//Ledger,
		Tabloid,
		NPageSize
	};

	/**
	* Wrapper for Qt.
	*/
#if QT_VERSION>=0x030000
	static QPrinter::PageSize rsToQtPaperFormat(RS2::PaperFormat f) {
		QPrinter::PageSize ret;
		switch (f) {
		case Custom:
			ret = QPrinter::Custom;
			break;
		case Letter:
			ret = QPrinter::Letter;
			break;
		case Legal:
			ret = QPrinter::Legal;
			break;
		case Executive:
			ret = QPrinter::Executive;
			break;
		case A0:
			ret = QPrinter::A0;
			break;
		case A1:
			ret = QPrinter::A1;
			break;
		case A2:
			ret = QPrinter::A2;
			break;
		case A3:
			ret = QPrinter::A3;
			break;
		default:
		case A4:
			ret = QPrinter::A4;
			break;
		case A5:
			ret = QPrinter::A5;
			break;
		case A6:
			ret = QPrinter::A6;
			break;
		case A7:
			ret = QPrinter::A7;
			break;
		case A8:
			ret = QPrinter::A8;
			break;
		case A9:
			ret = QPrinter::A9;
			break;
		case B0:
			ret = QPrinter::B0;
			break;
		case B1:
			ret = QPrinter::B1;
			break;
		case B2:
			ret = QPrinter::B2;
			break;
		case B3:
			ret = QPrinter::B3;
			break;
		case B4:
			ret = QPrinter::B4;
			break;
		case B5:
			ret = QPrinter::B5;
			break;
		case B6:
			ret = QPrinter::B6;
			break;
		case B7:
			ret = QPrinter::B7;
			break;
		case B8:
			ret = QPrinter::B8;
			break;
		case B9:
			ret = QPrinter::B9;
			break;
		case B10:
			ret = QPrinter::B10;
			break;
		case C5E:
			ret = QPrinter::C5E;
			break;
		case Comm10E:
			ret = QPrinter::Comm10E;
			break;
		case DLE:
			ret = QPrinter::DLE;
			break;
		case Folio:
			ret = QPrinter::Folio;
			break;
			//Ledger,
		case Tabloid:
			ret = QPrinter::Tabloid;
			break;
		case NPageSize:
			ret = QPrinter::NPageSize;
			break;		
		}
		return ret;
	}
#endif

};
#endif