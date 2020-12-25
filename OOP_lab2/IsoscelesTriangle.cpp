#include "IsoscelesTriangle.h"

double IsoscelesTriangle::Perimeter() const
{
	return _fSide * 2 + TSide();
}

double IsoscelesTriangle::Area() const
{
	return TSide() * sqrt(_fSide * _fSide - TSide() * TSide() / 4) / 2;
}

IsoscelesTriangle::IsoscelesTriangle(const double fSide, const double sSide, const double angle) : Triangle(fSide, sSide, angle)
{
	if ((fSide != sSide))
	{
		throw std::exception("The triangle isn't isosceles");
	}

}