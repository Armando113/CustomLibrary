#include "Vector3D.h"

//Default Constructor
Vector3D::Vector3D()
	:x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
}
//Float constructor
Vector3D::Vector3D(const float &_x, const float &_y, const float &_z)
	: x(_x), y(_y), z(_z), w(0.0f)
{
}
//Int constructor
Vector3D::Vector3D(const int &_x, const int &_y, const int &_z)
	: x(_x), y(_y), z(_z), w(0.0f)
{
}
//Copy Constructor
Vector3D::Vector3D(const Vector3D &_source)
	: x(_source.x), y(_source.y), z(_source.z), w(_source.w)
{
}

Vector3D::~Vector3D()
{
	//Nothing to delete for now
}

Vector3D Vector3D::operator+(const Vector3D &_source)
{
	return Vector3D(this->x + _source.x, this->y + _source.y, this->z + _source.z);
}

Vector3D Vector3D::operator-(const Vector3D &_source)
{
	return Vector3D(this->z - _source.x, this->y - _source.y, this->z - _source.z);
}

Vector3D Vector3D::operator*(const float &_scalar)
{
	return Vector3D(this->x * _scalar, this->y * _scalar, this->z * _scalar);
}