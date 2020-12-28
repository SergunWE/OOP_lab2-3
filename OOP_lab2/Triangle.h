#pragma once
#include <algorithm>
#include <cmath>
#include "ITriangle.h"

class Triangle : public ITriangle
{
public:
	double Perimeter() const override; //периметр
	double Area() const override; //площадь
	double GetAngle() const override { return _angle; } //угол
	double GetSide(const int num) const override; //стороны треугольника

	Triangle() : _fSide(0), _sSide(0), _angle(0) {}
	Triangle(const double fSide, const double sSide, const double angle);

private:
	double _fSide; //первая сторона
	double _sSide; //вторая сторона
	double _angle; //угол между сторонами
};