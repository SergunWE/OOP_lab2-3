#include "Triangle.h"

double Triangle::Perimeter() const
{
	return _fSide + _sSide + TSide();
}

double Triangle::Area() const
{
	return _fSide * _sSide / 2 * sin(GetRadian(_angle));
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

inline double Triangle::GetRadian(const double degree) const
{
	return M_PI * degree / 180;
}

inline double Triangle::TSide() const
{
	return sqrt(_fSide * _fSide + _sSide * _sSide - 2 * _fSide * _sSide * cos(GetRadian(_angle)));
}