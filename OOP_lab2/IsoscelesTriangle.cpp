#include "IsoscelesTriangle.h"

double IsoscelesTriangle::Perimeter() const
{
	return _side * 2 + GetSide(3);
}

double IsoscelesTriangle::Area() const
{
	return _side * _side * sin(M_PI * _angle / 180) / 2 ;
}

double IsoscelesTriangle::GetSide(const int num) const
{
	switch (num)
	{
	case 1:
	case 2:
		return _side;
	case 3:
		return _side / (2 * cos(M_PI * _angle / 180));
	default:
		throw std::exception("Incorrect side number");
	}
}

IsoscelesTriangle::IsoscelesTriangle(const double side, const double angle)
{
	if (side <= 0)
	{
		throw std::exception("Impermissible side length");
	}
	if (angle <= 0 || angle >= 180)
	{
		throw std::exception("Impermissible angle");
	}
	_side = side;
	_angle = angle;
}