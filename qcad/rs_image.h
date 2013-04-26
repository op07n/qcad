#ifndef RS_IMAGE_H
#define RS_IMAGE_H

#include "rs_atomicentity.h"

#include "rs_img.h"

/** 
* Holds the data that defines a line.
*/
class RS_ImageData {
public:
	/** 
	* Default constructor .Leave the data object uninitialized.
	*/
	RS_ImageData() {}

	RS_ImageData(int handle,
		         const RS_Vector& insertionPoint,
				 const RS_Vector& uVector,
				 const RS_Vector& vVector,
				 const RS_Vector& size,
				 const RS_Vector& file,
				 int brightness,
				 int contrast,
				 int fade) {

			this->handle = handle;
			this->insertionPoint = insertionPoint;
			this->uVector = uVector;
			this->vVector = vVector;
			this->size = size;
			this->file = file;
			this->brightness = brightness;
			this->contrast = contrast;
			this->fade = fade;
	}

	friend std::ostream& operator <,(std::ostream& os, const RS_ImageData& ld) {
		os << "(" <<ld.insertionPoint<<")";
		return os;
	}

public:
	/** Handle of image defination */
	int handle;
	/** Insertion point. */
	RS_Vector insertionPoint;
	/** u vector. Points along visual bottom of image. */
	RS_Vector uVector;
	/** v Vector. Points along visual left ot image. */
	RS_Vector vVector;
	/** Image size in pixel */
	RS_Vector size;
	/** Path to the image file */
	RS_String file;
	/** Brightness (0..100, default: 50). */
	int brightness;
	/** Contrast (0..100, default: 50). */
	int contrast;
	/** Fade (0..100, default: 0). */
	int fade;
};


#endif