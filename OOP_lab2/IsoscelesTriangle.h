#pragma once
#include <algorithm>
#include <cmath>
#include "ITriangle.h"

class IsoscelesTriangle : public ITriangle //равнобедренный треугольник
{
public:
	double Perimeter() const override;
	double Area() const override;
	double GetAngle() const override { return _angle; }
	double GetSide(const int num) const override;

	IsoscelesTriangle() = default;
	IsoscelesTriangle(const double Side, const double angle);

private:
	double _side;
	double _angle;
};