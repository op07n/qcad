#ifndef RS_VECTOR_H
#define RS_VECTOR_H

#include <iostream>

#include "rs.h"

/**
* represent a 3D vector(x/y/z)
*/

class RS_Vector {
public:
	RS_Vector();
	RS_Vector(double vx, double vy, double vz=0.0);
	//RS_Vector(double v[]);

	explicit RS_Vector(bool valid);
	~RS_Vector();

	void set(double vx, double vy, double vz=0.0);
	void setPolar(double radius, double angle);

	double distanceTo(const RS_Vector& v) const;
	double angle() const;
	double angleTo(const RS_Vector& v) const;
	double magnitude() const;
	RS_Vector lerp(const RS_Vector& v, double t) const;

	bool isInWindow(const RS_Vector& firstCorner, const RS_Vector& secondCorner);

	RS_Vector move(RS_Vector offset);
	RS_Vector rotate(double ang);
	RS_Vector rotate(RS_Vector center, double ang);
	RS_Vector scale(RS_Vector factor);
	RS_Vector scale(RS_Vector center, RS_Vector factor);
	RS_Vector mirror(RS_Vector axisPoint, RS_Vector axisPoint2);

	RS_Vector operator + (const RS_Vector& v) const;
	RS_Vector operator - (const RS_Vector& v) const; 
	RS_Vector operator * (double s) const;
	RS_Vector operator / (double s) const;

	void operator += (const RS_Vector& v);
	void operator -= (const RS_Vector& v);
	void operator *= (double s);

	bool operator == (const RS_Vector& v) const;
	bool operator != (const RS_Vector& v) const {
		return !operator==(v);
	}

	static RS_Vector minimum(const RS_Vector& v1, const RS_Vector& v2);
	static RS_Vector maximum(const RS_Vector& v1, const RS_Vector& v2);
	static RS_Vector crossP(const RS_Vector& v1, const RS_Vector& v2);
	static double dotP(const RS_Vector& v1, const RS_Vector& v2);

	friend std::ostream& operator << (std::ostream&, const RS_Vector& v);

#ifdef RS_TEST
	
	static bool test();
#endif

public:
	double x;
	double y;
	double z;
	bool valid;
};

/**
* 4 vectors
*/

class RS_VectorSolutions {
public:
	RS_VectorSolutions();
	RS_VectorSolutions(const RS_VectorSolutions& s);
	RS_VectorSolutions(int num);
	RS_VectorSolutions(const RS_Vector& v1);
	RS_VectorSolutions(const RS_Vector& v1, const RS_Vector& v2);
	RS_VectorSolutions(const RS_Vector& v1, const RS_Vector& v2,
		               const RS_Vector& v3);
	RS_VectorSolutions(const RS_Vector& v1, const RS_Vector& v2,
		               const RS_Vector& v3, const RS_Vector& v4);
	RS_VectorSolutions(const RS_Vector& v1, const RS_Vector& v2,
		               const RS_Vector& v3, const RS_Vector& v4,
					   const RS_Vector& v5);
	~RS_VectorSolutions();

	void alloc(int num);
	void clean();
	RS_Vector get(int i) const;
	int getNumber() const;
	bool hasValid() const;
	void set(int i, const RS_Vector& v);
	void setTangent() const;
	RS_Vector getClosest(const RS_Vector& coord,
		double* dist=NULL, int* index=NULL) const;
	void rotate(RS_Vector center, double ang);
	void scale(RS_Vector center, RS_Vector factor);

	RS_VectorSolutions operator = (const RS_VectorSolutions& s);

	friend std::ostream& operator << (std::ostream& os,
		                              const RS_VectorSolutions& s);

private:
	RS_Vector* vector;
	int num;
	bool tagent;
};

#endif
