#ifndef RS_DIMDIAMETRIC_H
#define RS_DIMDIAMETRIC_H

#include "rs_dimension.h"

/** 
* Holds the data that define a diametric dimension entity.
*/
class RS_DimDiametricData {
public:
	/** 
	* Default constructor. Leaves the data object uninitialized.
	*/
	RS_DimDiametricData() {}

	/** 
	* Constructor with initialisation.
	* @param definitionPoint Definition point of the diametric dimension
	* @param leader Leader length.
	*/
	RS_DimDiametricData(const RS_Vector& definitionPoint,
		                double leader) {
	    this->definitionPoint = definitionPoint;
		this->leader = leader;
	}

	friend std::ostream& operator << (std::ostream& os,
		                               const RS_DimDiametricData& dd) {
         os<<"("<< dd.definitionPoint << "/" << dd.leader << ")";
		 return os;
	}

public:
	/** Definition point */
	RS_Vector definitionPoint;
	/** Leader length */
	double leader;
};


/** 
* Class for diametric dimension entities.
*
*/
class RS_DimDiametric : public RS_Dimension {
public:
	RS_DimDiametric(RS_EntityContainer* parent,
		            const RS_DimensionData& d,
					const RS_DimDiametricData& ed);
	virtual ~RS_DimDiametric() {}

	virtual RS_Entity* clone() {
		RS_DimDiametric* d = new RS_DimDiametric(*this);
		d->entities.setAutoDelete(entities.autoDelete());
		d->initId();
		d->detach();
		return d;
	}

	/** #return RS2::EntityDimDiametric */
	virtual RS2::EntityType rtti() const {
		return RS2::EntityDimDiametric;
	}

	/** 
	* @return Copu of data that defines the diametric dimension.
	* @see getData()
	*/
	RS_DimDiametricData getEData() const {
		return edata;
	}

	virtual RS_VectorSolutions  getRefPoints();

	virtual RS_String getMeasuredLabel();

	virtual void update(bool autoText=false);

	RS_Vector getDefinitionPoint() {
		return edata.definitionPoint;
	}

	double getLeader() {
		return edata.leader;
	}

	virtual void move(RS_Vector offset);
	virtual void rotate(RS_Vector center, double angle);
	virtual void scale(RS_Vector center, RS_Vector factor);
	virtual void mirror(RS_Vector axisPoint1, RS_Vector axisPoint2);
	virtual void moveRef(const RS_Vector& ref, const RS_Vector& offset);

	friend std::ostream& operator << (std::ostream& os,
		                              const RS_DimDiametric& d);

protected:
	/** Extended data */
	RS_DimDiametricData edata;
};

#endif