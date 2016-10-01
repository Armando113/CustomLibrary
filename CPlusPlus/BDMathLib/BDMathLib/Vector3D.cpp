#include "Vector3D.h"
#include <math.h>

//Default Constructor
Vector3D::Vector3D()
	:x(0.0f), y(0.0f), z(0.0f), w(1.0f)
{
}
//Float constructor
Vector3D::Vector3D(const float &_x, const float &_y, const float &_z)
	: x(_x), y(_y), z(_z), w(1.0f)
{
}
//Int constructor
Vector3D::Vector3D(const int &_x, const int &_y, const int &_z)
	: x(_x), y(_y), z(_z), w(1.0f)
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
Vector3D Vector3D::operator*(const int &_scalar)
{
	return Vector3D(this->x * _scalar, this->y * _scalar, this->z * _scalar);
}

Vector3D Vector3D::operator/(const float &_scalar)
{
	//make sure we don't get 0
	if (_scalar != 0.0f)
	{
		return Vector3D(this->x / _scalar, this->y / _scalar, this->z / _scalar);
	}

	//We got a 0, simply return this instance with no effect added
	return *this;
}
Vector3D Vector3D::operator/(const int &_scalar)
{
	//make sure we don't get 0
	if (_scalar != 0)
	{
		return Vector3D(this->x / _scalar, this->y / _scalar, this->z / _scalar);
	}

	//We got a 0, simply return this instance with no effect added
	return *this;
}

bool Vector3D::operator==(const Vector3D &_source)
{
	if (this->x == _source.x && this->y == _source.y && this->z == _source.z)
	{
		return true;
	}

	return false;
}

bool Vector3D::operator!=(const Vector3D &_source)
{
	if (this->x == _source.x && this->y == _source.y && this->z == _source.z)
	{
		return false;
	}

	return true;
}


//Static functions
float Vector3D::Dot(const Vector3D &_lhs, const Vector3D &_rhs)
{
	return ((_lhs.x * _rhs.x) + (_lhs.y * _rhs.y) + (_lhs.z * _rhs.z));
}

Vector3D& Vector3D::CrossProduct(const Vector3D &_lhs, const Vector3D &_rhs)
{
	return Vector3D(((_lhs.y * _rhs.z) - (_lhs.z * _rhs.y)), ((_lhs.z * _rhs.x) - (_lhs.x * _rhs.z)), ((_lhs.x * _rhs.y) - (_lhs.y * _rhs.x)));
}

float Vector3D::Magnitude(const Vector3D &_source)
{
	return sqrtf((_source.x * _source.x) + (_source.y * _source.y) + (_source.z * _source.z));
}

Vector3D& Vector3D::Normalize(const Vector3D &_source)
{
	float mag = Magnitude(_source);
	return Vector3D((_source.x / mag), (_source.y / mag), (_source.z / mag));
}