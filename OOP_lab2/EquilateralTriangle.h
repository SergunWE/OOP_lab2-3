#pragma once
#include "Triangle.h"

class EquilateralTriangle : public Triangle //равностороний треугольник
{
public:
	double Perimeter() const override;
	double Area() const override;

	EquilateralTriangle() { _angle = 60; }
	EquilateralTriangle(const double fSide, const double sSide, const double angle);
};