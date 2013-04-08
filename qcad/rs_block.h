#ifndef RS_BLOCK_H
#define RS_BLOCK_H

#include "rs_document.h"

class RS_BlockData {
public:
	RS_BlockData() {}
		RS_BlockData(const RS_String& name,
			       const RS_Vector& basePoint,
				   bool frozen) {
					   this->name = name;
					   this->basePoint = basePoint;
					   this->frozen = frozen;
		}

		bool isValid() {
			return (!name.isEmpty() && basePoint.valid);
		}

public:
	RS_String name;

	RS_Vector basePoint;

	bool frozen;
};

class RS_Block : public RS_Document {
	
	friend class RS_BlockList;
public:

	RS_Block(RS_EntityContainer* parent, const RS_BlockData& d);

	virtual ~RS_Block();

	virtual RS_Entity* clone();

	virtual RS2::EntityType rtti() const {
		return RS2::EntityBlock;
	}

	RS_String getName() const {
		return data.name;
	}

	RS_Vector getBasePoint() const {
		return data.basePoint;
	}

	virtual RS_LayerList* getLayerList();
	virtual Rs_BlockList* getBlockList();

	virtual bool save();

	virtual bool saveAs(const RS_String& filename, RS2::FormaType type);

	virtual bool open(const RS_String&, RS2::FormatType) {
		return false;
	}


	friend std::ostream& operator << (std::ostream& os, const RS_Block& b) {
		os << "name:" << b.getName().tolatin1() << "\n";
		os << " entities: " << (Rs_EntityContainer&)b << "\n";
		return os;
	}

	void setName(const RS_String& n) {
		data.name = n;
	}

	bool isFrozen() const {
		return data.frozen;
	}

	void toggle() {
		data.frozen = !data.frozen;
	}

	void freeze(bool freeze) {
		data.frozen = freeze;
	}

	virtual void setModified(bool m);

protected:

	RS_BlockData data;
};

#endif