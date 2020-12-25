#pragma once
#include "Triangle.h"

class RightTriangle : public Triangle //прямоугольный треугольник
{
public:
	double Area() const override;

	RightTriangle() { _angle = 90; }
	RightTriangle(const double fSide, const double sSide, const double angle);

private:
	inline double TSide() const override;
};