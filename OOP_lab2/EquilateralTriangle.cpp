#include "EquilateralTriangle.h"

double EquilateralTriangle::Perimeter() const
{
	return _fSide * 3;
}

double EquilateralTriangle::Area() const
{
	return _fSide * _fSide * sqrt(3) / 4;
}

EquilateralTriangle::EquilateralTriangle(const double fSide, const double sSide, const double angle = 60) : Triangle(fSide, sSide, angle)
{
	if ((fSide != sSide) || angle != 60)
	{
		throw std::exception("The triangle isn't equilateral");
	}
}