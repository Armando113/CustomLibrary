#ifndef MATRIX4D_H
#define MATRIX4D_H

#include "VectorMatrixEnum.h"
#include "Vector4D.h"

//forward declare
class Vector4D;

class Matrix4D
{
private:

public:

	//Variables
	//First Row
	Vector4D *pRow0;
	Vector4D *pRow1;
	Vector4D *pRow2;
	Vector4D *pRow3;

	//Default Constructor
	Matrix4D();
	
	//Copy Constructor
	Matrix4D(const Matrix4D &_source);

	//Argument Constructor
	Matrix4D(Vector4D * const _row0, Vector4D * const _row1, Vector4D * const _row2, Vector4D * const _row3);

	//Equal Operator
	Matrix4D operator=(const Matrix4D &_source);

	//Destructor
	~Matrix4D();

};

#endif