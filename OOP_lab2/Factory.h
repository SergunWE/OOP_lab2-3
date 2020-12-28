#pragma once
#include "Triangle.h"
#include "EquilateralTriangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"

class Factory
{
public:
	static ITriangle* CreateTriangle(const double fSide, const double sSide, const double angle)
	{
		if (angle == 90)
		{
			return new RightTriangle(fSide, sSide);
		}
		if (fSide == sSide)
		{
			if (angle == 60)
			{
				return new EquilateralTriangle(fSide);
			}
			return new IsoscelesTriangle(fSide, angle);
		}
		return new Triangle(fSide, sSide, angle);
	}
};