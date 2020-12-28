#include "RightTriangle.h"

double RightTriangle::Perimeter() const
{
	return _fSide + _sSide + GetSide(3);
}

double RightTriangle::Area() const
{
	return _fSide * _sSide / 2;
}

double RightTriangle::GetSide(const int num) const
{
	switch (num)
	{
	case 1:
		return _fSide;
	case 2:
		return _sSide;
	case 3:
		return sqrt(pow(std::max(_fSide, _sSide), 2) - pow(std::min(_fSide, _sSide), 2));
	default:
		throw std::exception("Incorrect side number");
	}
}

RightTriangle::RightTriangle(const double fSide, const double sSide)
{
	if (fSide <= 0 || sSide <= 0)
	{
		throw std::exception("Impermissible side length");
	}
	_fSide = fSide;
	_sSide = sSide;
}