#ifndef VECTOR4D_H
#define VECTOR4D_H

#include "VectorMatrixEnum.h"
#include <xmmintrin.h>
#include <smmintrin.h>  

class Matrix4D;

class Vector4D
{
private:
	//No one should access this constructor (Floats only!!)
	template<typename T>
	Vector4D(const T &_x, const T &_y, const T &_z);



public:
	//Let Matrix4D access us
	friend class Matrix4D;

#pragma warning( disable : 4201)
	union
	{
		__m128 mVect;
		struct
		{
			//The 3 dimensions
			float x;
			float y;
			float z;
			//The extra to make it 16 byte-aligned
			float w;
		};
	};

	//Constructors
	//Default Constructor
	Vector4D();

	//Custom constructor
	Vector4D(const float &_x, const float &_y, const float &_z, const float &_w = 1.0f);

	//Intrinsic Constructor
	Vector4D(const __m128 &_m);


	//Copy constructor
	Vector4D(const Vector4D &_source);

	//Equal operator
	Vector4D operator=(const Vector4D &_source);

	//Destructor
	~Vector4D();

	//Operators
	//Sum
	Vector4D operator+(const Vector4D &_source);
	//Subtraction
	Vector4D operator-(const Vector4D &_source);
	//Multiplication (Scalar)
	Vector4D operator*(const float &_scalar);
	Vector4D operator*(const Vector4D &_mVect);//This is to use SIMD
	//Equals operator
	bool operator==(const Vector4D &_source);
	//Not equals operator
	bool operator!=(const Vector4D &_source);


	//Static functions
	static float Dot(const Vector4D &_lhs, const Vector4D &_rhs);
	static Vector4D CrossProduct(const Vector4D &_lhs, const Vector4D &_rhs);
	static float Magnitude(const Vector4D &_source);
	static Vector4D Normalize(const Vector4D &_source);

};

#endif