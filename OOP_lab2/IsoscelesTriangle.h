#pragma once
#include "Triangle.h"

class IsoscelesTriangle : public Triangle //равнобедренный треугольник
{
public:
	double Perimeter() const override;
	double Area() const override;

	IsoscelesTriangle() = default;
	IsoscelesTriangle(const double fSide, const double sSide, const double angle);
};