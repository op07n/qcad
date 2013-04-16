#ifndef QG_ACTIONHANDLER_H
#define QG_ACTIONHANDLER_H

#include "qaction.h"
#include "qmainwindow.h"
#include "qobject.h"

#include "rs_document.h"
#include "rs_stringlist.h"

#include "qg_graphicview.h"

class QG_MainWindowInterface;
class QG_CadToolBarSnap;
class QG_CadToolBarSelect;


/** 
* this class can trigger actions
*/

class QG_ActionHandler : public QObject {
	Q_OBJECT
public:
	QG_ActionHandler(QG_MainWindowInterface* mw);
	virtual ~QG_ActionHandler();

	RS_ActionInterface* getCurrentAction();
	RS_ActionInterface* setCurrentAction(RS2::ActionType id);
	void killSelectActions();

	bool keycode(const QString& code);
	bool command(const QString& cmd);
	RS_StringList getAvailableCommands();

public slots:
    /*void slotFileNew(); */
	void slotFileOpen();
	void slotFileSaveAs();
	/*

	*/
	void slotZoomIn();
	void slotZoomOut();
	void slotZoomAuto();
	void slotZoomWindow();
	void slotZoomPan();
	void slotZoomPrevious();
	void slotZoomRedraw();

	void slotToolRegenerateDimesions();

	void slotEditUndo();
	void slotEditRedo();
	void slotEditCut();
	void slotEditCopy();
	void slotEditPaste();

	void slotSelectionSingle();
	void slotSelectContour();
	void slotSelectWindow();
	void slotDeselectWindow();
	void slotSelectAll();
	void slotDeselectAll();
	void slotSelectInvert();
	void slotSelectIntersected();
	void slotDeselectintersected();
	void slotSelectlayer();

	void slotDrawPoint();
	void slotDrawLine();
	void slotDrawLineAngle();
	void slotDrawLineHorizontal();
	void slotDrawLineVertical();
	void slotDrawLineFree();
	void slotDrawLineHorVert();
	void slotDrawLineParallel();
	void slotDrawLineParallelThrough();
	void slotDrawLineRectangle();
	void slotDrawLineBisector();
	void slotDrawLineTangent1();
	void slotDrawLineTangent2();
	void slotDrawLienRelAngle();
	void slotDrawLinePolygon();
	void slotDrawLinePolygon2();
	void slotDrawCircle();
	void slotDrawCircleCR();
	void slotDrawCircle2P();
	void slotDrawCircle3P();
	void slotDrawCircleParallel();
	void slotDrawArc();
	void slotDrawArc3P();
	void slotDrawArcParallel();
	void slotDrawArctangential();
	void slotDrawEllipseAxis();
	void slotDrawEllipseArcAxis();
	void slotDrawSpline();
	void slotDrawText();
	void slotDrawHatch();
	void slotDrawImage();
	void slotDrawPolyline();
	void slotPolylineAdd();
	void slotPolylineAppend();
	void slotPolylineDel();
	void slotPolylineDelBetween();
	void slotPolylineTrim();

	void slotDimAligned();
	void slotDimLinear();
	void slotDimLinearHor();
	void slotDimLinearVer();
	void slotDimRadial();
	void slotDimDiametric();
	void slotDimLeader();

	void slotModifyAtributes();
	void slotModifyDelete();
	void slotModifyDeleteQuick();
	void slotModifyDeleteFree();
	void slotModifyMove();
	void slotModifyScale();
	void slotModifyRotate();
	void slotModifyMirror();
	void slotModifyMoveRotate();
	void slotModifyRotate2();
	void slotModifyEntity();
	void slotModifyTrim();
	void slotModifyTrim2();
	void slotModifyTrimAmount();
	void slotModifyCut();
	void slotModifyStretch();
	void slotModifyBevel();
	void slotModifyRound();
	void slotModifyExplodeText();

	void slotSnapFree();
	void slotSnapGrid();
	void slotSnapEndpoint();
	void slotSnapOnEntity();
	void slotSnapCenter();
	void slotSnapMiddle();
	void slotSnapDist();
	void slotSnapIntersection();
	void slotSnapIntersectionManual();

	void slotRestrictNothing();
	void slotRestrictOrthogonal();
	void slotRestrictHorizontal();
	void slotRestrictVertical();

	void disableSnaps();
	void disableRestriction();
	void updateSnapMode();

	void slotSetRelativeZero();
	void slotLockRelativeZero(bool on);

	void slotInfoInside();
	void slotInfoDIst();
	void slotInfoDist2();
	void slotInfoAngle();
	void slotInfoTotalLength();
	void slotInfoArea();

	void slotLayersDefreezeAll();
	void slotLayersFreezeAll();
	void slotLayersAdd();
	void slotLayersRemove();
	void slotLayersEdit();
	void slotLayersInsert();
	void slotLayersToggleView();
	void slotLayersToggleLock();

    void slotBlocksDefreezeAll();
	void slotBlocksFreezeAll();
	void slotBlocksAdd();
	void slotBlocksRemove();
	void slotBlocksAttributes();
	void slotBlocksEdit();
	void slotBlocksInsert();
	void slotBlocksToggleView();
	void slotBlocksCreate();
	void slotBlocksExpole();

	void slotOptionsDrawing();
	
	void slotCamExportAuto();
	void slotCamRecorder();

	void slotFocusNormal();

	void setActionSnapFree(QAction* a) {
		snapFree = a;
	}
	void setActionSnapGrid(QAction* a) {
		snapFree = a;
	}
	void setActionSnapEndPoint(QAction* a) {
		snapEndPoint = a;
	}
	void setActionSnapOnEntity(QAction* a) {
		snapOnEntity = a;
	}
	void setActionSnapCenter(QAction* a) {
		snapCenter = a;
	}
	void setActionSnapMiddle(QAction* a) {
		snapMiddle = a;
	}
	void snapActionSnapDist(QAction* a) {
		snapDist = a;
	}
	void setActionSnapIntersection(QAction* a) {
		snapIntersectionManual = a;
	}
	void setActionRestricNothing(QAction* a) {
		restrictNothing = a;
	}
	void setActionRestrictOrthogonal(QAction* a) {
		restrictOrthogonal = a;
	}
	void setActionRestrictHorizontal(QAction* a) {
		restrictHorizontal = a;
	}
	void setActionRestrictVertical(QAction* a) {
		restrictVertical = a;
	}
	void setActionLockRelativeZero(QAction* a) {
		lockRelativeZero = a;
	}

	void setCadTooBarSnap(QG_CadToolBarSnap* tb);

	private:
		QG_MainWindowInterface* mainWindow;
		QG_CadToolBarSnap* cadToolBarSnap;

		QAction* snapFree;
		QAction* snapGrid;
		QAction* snapEndpoint;
		QAction* snapOnEntity;
		QAction* snapCenter;
		QAction* snapMiddle;
		QAction* snapDist;
		QAction* snapIntersection;
		QAction* snapIntersectionManual;

		QAction* restrictNothing;
		QAction* restrictOrthogonal;
		QAction* restrictHorizontal;
		QAction* restrictVertical;

		QAction* lockRelativeZero;

};