#include "rs_arc.h"

#include "rs_constuctionline.h"
#include "rs_linetypepattern.h"
#include "rs_information.h"
#include "rs_math.h"
#include "rs_graphicview.h"
#include "rs_painter.h"


/**
* Default constructor
*/
RS_Arc::RS_Arc(RS_EntityContainer* parent,
               const RS_ArcData& d)
			   : RS_AtomicEntity(parent), data(d) {
       calculateEndpoint();
	   calculateBorders();
}


/** 
* Create this arc from 3 given points which defines the arc line.
*
* @param p1 1st point.
* @param p2 2nd point.
* @param p3 3rd point.
*/RLERANCE &&
		    p2.distanceTo(p3)>RS_TOLERANCE && 
		    p3.distanceTo(p1)>RS_TOLERANCE) {

		//middle points between 3 points:
		RS_Vector mp1, mp2;
		RS_Vector dir1, dir2;
		double a1, a2;

		// intersection of two middle lines
		mp1 = (p1 + p2) / 2.0 ;
		a1 = p1.angleTo(p2) + M_PI/2.0;
		dir1.setPolar(100.0, a1);
		mp2 = (p2 + p3)/2.0;
		a2 = p2.angleTo(p3) + M_PI/2.0;
		dir2.setPolar(100.0, a2);

		RS_VectorSolutions sol = 
			RS_Information::getIntersection(&midLine1, &midLine2);

		data.center = sol.get(0);
		data.radius = data.center.distanceTo(p3);
		data.angle1 = data.center.angleTo(p1);
		data.angle2 = data.center.angleTo(p3);
		data.reversed = RS_Match::isAngleBetween(data.center.angleTo(p2),
			                                     data.angle1, data.angle2, true);

		if(sol.get(0).valid && data.radius<1.0e14) &&
			   data.radius>RS_TOLERANCE) {
			caculateEndpoints();
			caculateBorders();
			return true;
		}   else {
			  RS_DEUBG->print("RS_Arc::createFrom3P:"
			                   "Cannot create an arc with radius 0.0. ");
			 return false;
		}
		
}



/** 
* Creates an arc from its startpoints, endpoint, start direction (angle)
* and radius.
*
* @retval  true Successfullu created arc
* @retval false Cannot creates arc (radius too small or endpoint too far away)
*/
bool RS_Arc::createFrom2PDirectionRadius(const RS_Vector& startPoint,
        const RS_Vector& endPoint,
		double direction1, double radius) {

}