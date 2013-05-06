#ifndef DL_CREATIONINTERFACE_H
#define DL_CREATIONINTERFACE_H

#include <string.h>

#include "dl_attributes.h"
#include "dl_codes.h"
#include "dl_entities.h"
#include "dl_extrusion.h"


/** 
* Abstract class (interface) for the creation of new entities
* Inherit your class which takes care of the entities in the 
* processed DXF file from this interface.
*
* Double arrays passed to your implementation contains 3 double
* values for x, y, z coordinate unless started differently
*/
class DL_CreationInterface {
public:
	DL_CreationInterface() {
		extrusion = new DL_Extrusion;
	}
	virtual ~DL_CreationInterface() {
		delete extrusion;
	}

	/** 
	* called for every layer
	*/
	virtual void addLayer(const DL_LayerData& data) = 0;

	/** 
	* Called for every block. Note : all entities added after  this
	* commmand fo into this block until endBlock() is called.
	*/
	virtual void addBlock(const DL_BlockData& data) = 0;

	/** Called to end the current block */
	virtual void endBlock() = 0;

	/** Called for every point */
	virtual void addPoint(const DL_PointData& data) = 0;

	/** Called for every line */
	virtual void addLine(const DL_LineData& data) = 0;

	/** Called for every arc */
	virtual void addArc(const DL_ArcData& data) = 0;

	/** Called for every circle */
	virtual void addEllipse(const DL_EllipseData& data) = 0;

	/** Called for every polyline start */
	virtual void addPolyline(const DL_PolylineData& data) = 0;

	/** Called for every polyline vertex */
	virtual void addVertex(const DL_VertexData& data) = 0;

	/** Called for every spline */
	virtual void addSpline(const DL_SplineData& data) = 0;

	/** Called for every spline control point */
	virtual void addControlPoint(const DL_ControlPointData& data) = 0;

	/** Called for every spline knot value */
	virtual void addKnot(const DL_KnotData& data) = 0;

	/** Called for every insert */
	virtual void addInsert(const DL_InsertData& data) = 0;

	/** Called for every trace start */
	virtual void addTrace(const DL_TraceData& data) = 0;

	/** Called for every solid start */
	virtual void addSolid(const DL_SolidData& data) = 0;

	/** Called for every MultiText entity */
	virtual void addMText(const DL_MTextData& data) = 0;

	/** 
	* Called for additional text chunks for MText entitties,
	* The Chunks come at 25- character in size each. Not that those
	* chunks come before the actual MText entity.
	*/
	virtual void addMTextChunk(const char* text) = 0;

	/** Called for every Text enttity */
	virtual void addText(const DL_TextData& data) = 0;

	/** 
	* Called for every aligned dimension entitty.
	*/
	virtual void addDimAlign(const DL_DimensionData& data,
		                     const DL_DimAlignedData& edata) = 0;
	/** 
	* Called for every linear or rotated dimension entity.
	*/
	virtual void addDimLinear(const DL_DimensionData& data,
		                      const DL_DimLinearData& data) = 0;

	/** 
	* Called for every radial dimension entity.
	*/
	virtual void addDimRadial(const DL_DimensionData& data,
		                      const DL_DimLinearData& edata) = 0;

	/** 
	* Called for every Diametric dimension entity 
	*/
	virtual void addDimDiametric(const DL_DimensionData& data, 
		                      const DL_DimDiametricData& edata) = 0;

	/** 
	* Called for every angular dimension (2 lines version ) entity.
	*/
	virtual void addDimAngular(const DL_DimensionData& data,
		                       const DL_DimAngularData& edata) = 0;

	/** 
	* Called for every angular dimension (3 lines version ) entity.
	*/
	virtual void addDimAngular3P(const DL_DimensionData& data,
		                       const DL_DimAngular3PData& edata) = 0;

	/**
	* Called for every leader start
	*/
	virtual void addLeader(const DL_LeaderData& data) = 0;

	/** 
	* Called for every leader vertex 
	*/
	virtual void addLeaderVertex(const DL_LeaderVertexData& data) = 0;


	/** 
	* Called for every hatch entity
	*/
	virtual void addHatch(const DL_HatchData& data) = 0;

	/** 
	* Called for every image entity
	*/
	virtual void addImage(const DL_ImageData& data) = 0;

	/** 
	* Called for every iamge definition.
	*/
	virtual void LinkImage(const DL_ImageDefData& data) = 0;

	/** 
	* Called  for every hatch loop
	*/
	virtual void addHatchLoop(const DL_HatchLoopData& data) = 0;

	/** 
	* Called for every hatch edge entity
	*/
	virtual void addHatchEdge(const DL_HatchEdgeData& data) = 0;

	/** 
	* Called after ann entity has beeen completed.
	*/
	virtual void endEntity() = 0;

	/** 
	* Called for every vector variable in the DXF file (e.g. "$EXTMIN").
	*/
	virtual void setVariableVector(const char* key,
		                  double v1, double v2, double v3, int code) = 0;

	/** 
	* Called for every string variable in the DXF file (e.g. "$ACADVER").
	*/
	virtual void setVariableString(const char* key, const char* value, int code ) = 0;

	/** 
	* Called for every int variable in the DXF file (e.g. "$ACADMAINTVER").
	*/
	virtual void setVariableInt(const char* key,
		                 itn value, int code) = 0;

	/** 
	* Called for every double variable in the DXF file (e.g. "$DIMEXO").
	*/
	virtual void setVariableDouble(const char* key, double value, int code ) = 0;

	/** 
	* Called when a SEQEND occurs (when a POLYLINE or ATTRIB is done)
	*/
	virtual void endSequence() = 0;

	/** 
	* Sets the current attributes for entities */
	void setAttributes(const DL_Attributes& attrib) {
		attributes = attrib;
	}

	/** @return the current attributes used for new entities */
	DL_Attributes getAttributes() {
		return attributes;
	}

	/** Sets the current attributes for entities */
	void setExtrusion(double dx, double dy, double dz, double elevation) {
		extrusion->setDirection(dx, dy, dz);
		extrusion->setElevation(elevation);
	}

	/** @return the current attributes used for new entities */
	DL_Extrusion* getExtrusion() {
		return extrusion;
	}


protected:
	DL_Attributes attributes;
	DL_Extrusion *extrusion;
};
#endif