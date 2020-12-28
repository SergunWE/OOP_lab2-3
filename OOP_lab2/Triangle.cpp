#include "Triangle.h"

double Triangle::Perimeter() const
{
	return _fSide + _sSide + GetSide(3);
}

double Triangle::Area() const
{
	return _fSide * _sSide * sin(M_PI * _angle / 180) / 2 ;
}

double Triangle::GetSide(const int num) const
{
	switch (num)
	{
	case 1:
		return _fSide;
	case 2:
		return _sSide;
	case 3:
		return sqrt(_fSide * _fSide + _sSide * _sSide - 2 * _fSide * _sSide * cos(M_PI * _angle / 180));
	default:
		throw std::exception("Incorrect side number");
	}
}

Triangle::Triangle(const double fSide, const double sSide, const double angle)
{
	if (fSide <= 0 || sSide <= 0)
	{
		throw std::exception("Impermissible side length");
	}
	if (angle <= 0 || angle >= 180)
	{
		throw std::exception("Impermissible angle");
	}
	_fSide = fSide;
	_sSide = sSide;
	_angle = angle;
}