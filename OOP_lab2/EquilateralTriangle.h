#pragma once
#include <algorithm>
#include <cmath>
#include "ITriangle.h"

class EquilateralTriangle : public ITriangle //равностороний треугольник
{
public:
	double Perimeter() const override;
	double Area() const override;
	double GetAngle() const override { return 60; } //угол
	double GetSide(const int num) const override; //стороны треугольника

	EquilateralTriangle() : _side(0) {}
	EquilateralTriangle(const double Side);
private:
	double _side; //сторона
};