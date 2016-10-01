#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
private:

public:

	//The 3 dimensions
	float x;
	float y;
	float z;
	//The extra to make it 16 byte-aligned
	float w;


	//Constructors
	//Default Constructor
	Vector3D();

	//Custom constructor
	Vector3D(const float &_x, const float &_y, const float &_z);
	Vector3D(const int &_x, const int &_y, const int &_z);

	//Copy constructor
	Vector3D(const Vector3D &_source);

	//Equal operator
	Vector3D operator=(const Vector3D &_source);

	//Destructor
	~Vector3D();

	//Operators
	//Sum
	Vector3D operator+(const Vector3D &_source);
	//Subtraction
	Vector3D operator-(const Vector3D &_source);
	//Multiplication (Scalar)
	Vector3D operator*(const float &_scalar);
	Vector3D operator*(const int &_scalar);
	//Division
	Vector3D operator/(const float &_scalar);
	Vector3D operator/(const int &_scalar);
	//Equals operator
	bool operator==(const Vector3D &_source);
	//Not equals operator
	bool operator!=(const Vector3D &_source);


	//Static functions
	static float Dot(const Vector3D &_lhs, const Vector3D &_rhs);
	static Vector3D& CrossProduct(const Vector3D &_lhs, const Vector3D &_rhs);
	static float Magnitude(const Vector3D &_source);
	static Vector3D& Normalize(const Vector3D &_source);

};

#endif