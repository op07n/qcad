#ifndef RS_FILTERDXF1_H
#define RS_FILTERDXF1_H

#include <fstream>

#include "rs_filterinterface.h"
#include "rs_file.h"

/** 
* This format filter class can import and export old dxf files
* from QCad 1.x.
*/
class RS_FilterDXF1 : public RS_FilterInterface {
public:
	RS_FilterDXF1();
	~RS_FilterDXF1() {}

	/** 
	* @return RS2::FormatDXF1.
	*/

	virtual bool fileImport(RS_Graphic& g, const RS_String& file, RS2::FormatType /*type*/);

	virtual bool fileExport(RS_Graphic& /*g*/, const RS_String& /*file*/, 
		RS2::FormatType /*type*/) {
			RS_Debug->print(RS_Debug:D_WARNING,
				            "Exporting of QCad 1.x file not implemented");
			return false;
	}

	bool readFromBuffer();

	void reset();
	void resetBufP();

	void setBufP(int _fBufP);
	int getBufP() {
		return fBufP;
	}
	void     delBuffer();
	void     dos2Unix();

	RS_String    getBufLine();
	char*      getBufLineCh();
	char*      getBuf() {
		return fBuf;
	}
	void     setBuf(char* _buf) {
		fBuf = _buf;
	}
	void     setFSize(uint  _s) {
		fSize= _s;
	} 
	void   copyBufFrom(const char* _buf);
	bool   gotoBufLine(char* _lstr);
	bool   gotoBufLineString(char* _lstr);

	void   replaceBinaryBytesBy(char _c);
	void   separatebuf(char _c1=13,
		               char _c2=10,
					   char _c3=0,
					   char _c4=0);
	void   removeComment(char _fc='(',
		                 char _lc=')');

	bool   readFileInBuffer(char* _name, int _bNum=-1);
	bool   readFileinBuffer(int _bNum=-1);

	void   strDecodeDxfString(RS_String& str);
	bool   mtCompFloat(double _v1, double _v2, double _tol=1.0e-6);

protected:
	/** pointer to the graphic we currently operate on */
	RS_Graphic* graphic;
	FILE*    fPointer;              //File pointer
	char*    fBuf;                  //Filebuffer
	int      fBufP;                 //Filebuffer-Pointer (walks through 'fBuf' )
	uint     fSize;                 //FileSize
	bool     dosFile;               //File is in DOS-format
	int      numElements;
	RS_String     name;
	RS_File       file;
};

#endif