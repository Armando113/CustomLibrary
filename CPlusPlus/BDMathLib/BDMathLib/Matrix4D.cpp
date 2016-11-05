#include "Matrix4D.h"

Matrix4D::Matrix4D()
	:pRow0(0), pRow1(0), pRow2(0), pRow3(0)
{
}

Matrix4D::Matrix4D(const Matrix4D &_source)
	: pRow0(_source.pRow0), pRow1(_source.pRow1), pRow2(_source.pRow2), pRow3(_source.pRow3)
{
}

Matrix4D Matrix4D::operator=(const Matrix4D &_source)
{
	return Matrix4D(_source);
}

Matrix4D::Matrix4D(Vector4D * const _row0, Vector4D * const _row1, Vector4D * const _row2, Vector4D * const _row3)
	:pRow0(_row0), pRow1(_row1), pRow2(_row2), pRow3(_row3)
{
}

Matrix4D::~Matrix4D()
{

}