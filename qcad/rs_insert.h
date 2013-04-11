#ifndef RS_INSERT_H
#define RS_INSERT_H

#include "rs_entitycontainer.h"

#include "rs_block.h"
#include "rs_grahic.h"

/** 
* Holds the data that defines an insert.
*/
class RS_InsertData {
public:
	/** 
	* Default constructor.
	*/
	RS_InsertData() {}

	/** 
	* @param name the name of the block used as an identifier
	* @param insertionPoint Insertion point of the block
	* @param scaleFactor scale factor in x/ y;
	* @param angle Rotation angle.
	* @param cols Number of cols if we insert a whole array
	* @param rows Number of rows if we insert a whole array.
	* @param spacing Spacing between rows and cols
	* @param blockSouce source for the block to insert if other than parent.
	*     
	*/
	RS_InsertData(const RS_String& name,
		RS_Vector  insertionPoint,
		RS_Vector scaleFactor,
		double angle,
		int cols, int rows, RS_Vector spacing,
		RS_BlockList* blockSource = NULL,
		RS2::UpdateMode updateMode = RS2::Update) {
			this->name = name;
			this->insertionPoint = insertionPoint;
			this->angle =angle;
			this->cols = cols;
			this->rows = rows;
			this->spacing = spacing;
			this->blockSource = blockSource;
			this->updateMode = updateMode;
	}

	friend class RS_Insert;
	friend std::ostream& operator << (std::ostream& os,
		                              const RS_InsertData& d) {
	     os << "(" << d.name.latin1() << ")";
	}


    RS_String name;
	RS_Vector insertionPoint;
	RS_Vector scaleFactor;
	double angle;
	int cols, rows;
	RS_Vector spacing;
	RS_BlockList* blockSource;
	RS2::UpdateMode updateMode;

};


/** 
* An insert inserts a block into the drawing at a certain location
* with certain attributes (angle, scale, ..).
* Inserts don't really contain other entities internally. They just refer
* to a block. However, to the outside world they act exactly
* like EntityContainer
*/
class RS_Insert : public RS_EntityContainer {
public:
	RS_Insert(RS_EntityContainer* parent,
		const RS_InsertData& d);
	virtual ~RS_Insert();

	virtual RS_Entity* clone() {
		RS_Insert* i = new RS_Insert(*this);
		i->entities.
	}

protected:
	RS_InsertData data;
	RS_Block* block;
};