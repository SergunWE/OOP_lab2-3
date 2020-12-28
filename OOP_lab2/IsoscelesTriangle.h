#pragma once
#include <algorithm>
#include <cmath>
#include "ITriangle.h"

class IsoscelesTriangle : public ITriangle //равнобедренный треугольник
{
public:
	double Perimeter() const override;
	double Area() const override;
	double GetAngle() const override { return _angle; } //угол
	double GetSide(const int num) const override; //стороны треугольника

	IsoscelesTriangle() = default;
	IsoscelesTriangle(const double Side, const double angle);
private:
	double _side;
	double _angle;
};