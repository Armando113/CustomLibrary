#include "Vector4D.h"
#include <math.h>

//Default Constructor
Vector4D::Vector4D()
	:x(0.0f), y(0.0f), z(0.0f), w(1.0f)
{
}
//Float constructor
Vector4D::Vector4D(const float &_x, const float &_y, const float &_z, const float &_w = 1.0f)
	: x(_x), y(_y), z(_z), w(_w)
{
}
//Instrinsic Constructor
Vector4D::Vector4D(const __m128 &_m)
	: mVect(_m)
{
}
//Copy Constructor
Vector4D::Vector4D(const Vector4D &_source)
	: x(_source.x), y(_source.y), z(_source.z), w(_source.w)
{
}

Vector4D::~Vector4D()
{
	//Nothing to delete for now
}

Vector4D Vector4D::operator+(const Vector4D &_source)
{
	return Vector4D(_mm_add_ps(this->mVect, _source.mVect));
}

Vector4D Vector4D::operator-(const Vector4D &_source)
{
	return Vector4D(_mm_sub_ps(this->mVect, _source.mVect));
}

Vector4D Vector4D::operator*(const float &_scalar)
{
	return Vector4D(this->x * _scalar, this->y * _scalar, this->z * _scalar, this->w);
}
Vector4D Vector4D::operator*(const Vector4D &_mVect)
{
	return Vector4D(_mm_mul_ps(this->mVect, _mVect.mVect));
}

bool Vector4D::operator==(const Vector4D &_source)
{
	if (this->x == _source.x && this->y == _source.y && this->z == _source.z)
	{
		return true;
	}

	return false;
}

bool Vector4D::operator!=(const Vector4D &_source)
{
	if (this->x == _source.x && this->y == _source.y && this->z == _source.z)
	{
		return false;
	}

	return true;
}


//Static functions
float Vector4D::Dot(const Vector4D &_lhs, const Vector4D &_rhs)
{
	return ((_lhs.x * _rhs.x) + (_lhs.y * _rhs.y) + (_lhs.z * _rhs.z));
}

Vector4D Vector4D::CrossProduct(const Vector4D &_lhs, const Vector4D &_rhs)
{
	return Vector4D(((_lhs.y * _rhs.z) - (_lhs.z * _rhs.y)), ((_lhs.z * _rhs.x) - (_lhs.x * _rhs.z)), ((_lhs.x * _rhs.y) - (_lhs.y * _rhs.x)));
}

float Vector4D::Magnitude(const Vector4D &_source)
{
	return sqrtf((_source.x * _source.x) + (_source.y * _source.y) + (_source.z * _source.z));
}

Vector4D Vector4D::Normalize(const Vector4D &_source)
{
	float mag = Magnitude(_source);
	return Vector4D((_source.x / mag), (_source.y / mag), (_source.z / mag));
}