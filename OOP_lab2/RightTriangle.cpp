#include "RightTriangle.h"

double RightTriangle::Area() const
{
	return _fSide * _sSide / 2;
}

RightTriangle::RightTriangle(const double fSide, const double sSide, const double angle = 90) : Triangle(fSide, sSide, angle)
{
	if (angle != 90)
	{
		throw std::exception("The triangle isn't rectangular");
	}
}

inline double RightTriangle::TSide() const
{
	return sqrt(pow(std::max(_fSide, _sSide), 2) - pow(std::min(_fSide, _sSide), 2));
}