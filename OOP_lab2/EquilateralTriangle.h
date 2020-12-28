#pragma once
#include <algorithm>
#include <cmath>
#include "ITriangle.h"

class EquilateralTriangle : public ITriangle //равностороний треугольник
{
public:
	double Perimeter() const override;
	double Area() const override;
	double GetAngle() const override { return 60; } 
	double GetSide(const int num) const override;

	EquilateralTriangle() : _side(0) {}
	EquilateralTriangle(const double side);

private:
	double _side; //сторона
};