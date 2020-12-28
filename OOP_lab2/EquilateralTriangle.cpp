#include "EquilateralTriangle.h"

double EquilateralTriangle::Perimeter() const
{
	return _side * 3;
}

double EquilateralTriangle::Area() const
{
	return _side * _side * sqrt(3) / 4;
}

double EquilateralTriangle::GetSide(const int num) const
{
	switch (num)
	{
	case 1:
	case 2:
	case 3:
		return _side;
	default:
		throw std::exception("Incorrect side number");
	}
}

EquilateralTriangle::EquilateralTriangle(const double side)
{
	if (side <= 0)
	{
		throw std::exception("The triangle isn't equilateral");
	}
	_side = side;
}