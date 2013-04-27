#ifndef RS_DIMALIGNED_H
#define RS_DIMALIGNED_H

#include "rs_dimension.h"

/** 
* Holds the data that defines an aligned dimension entity.
*/

class RS_DimAlignedData {
public:
	/** 
	* Default constructor. Leaves the data object uninitialized.
	*/
	RS_DimAlignedData() {}

	/** 
	* Constructor with initialisation.
	*
	   * @para extensionPoint1 definition point. Startpoint of the 
	*          first extension line.
	   * @para extensionPoint2 definition point. Startpoint of the
	*          second extension line.
	*/
	RS_DimAlignedData(const RS_Vector& extensionPoint1,
		              const RS_Vector& extensionPoint2) {
						  this->extensionPoint1 = extensionPoint1;
						  this->extensionPoint2 = extensionPoint2;
	}

	friend class RS_DimAligned;
	friend class RS_ActionDimAligned;

	friend std::ostream& operator << (std::ostream& os,
		                              const RS_DimAlignedData& dd)  {
	   os << "(" << dd.extensionPoint1 << "/"<< dd.extensionPoint2 <<")";
	   return os;
	}

private:
	/** definition point, Startpoint of the first extension line, */
	RS_Vector extensionPoint1;
	/** definition point, Startpoint of the second extension line, */
	RS_Vector extensionPoint2;
};


class RS_DimAligned : public RS_Dimension {
public:
	RS_DimAligned(RS_EntityContainer* parent,
		          const RS_DimensionData& d,
				  const RS_DimAlignedData& ed);
	virtual ~RS_DimAligned() {}

	virtual RS_Entity* clone() {
		RS_DimAligned* d = new RS_DimAligned(*this);
		d->entities.setAutoDelete(entities.autoDelete());
		d->initId();
		d->detach();
		return d;
	}

	/** 
	* @ return RS2::entityDimAligned */
	virtual RS2::EntityType rtti() const {
		return RS2::EntityDimAligned;
	}


	/** 
	* @return 
protected:
	/** Extended data. */
	RS_DimAlignedData edata;
};

#endif