#pragma once
#include "Triangle.h"
#include "EquilateralTriangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"

class Factory
{
public:
	static Triangle* CreateTriangle(const double fSide, const double sSide, const double angle, char type = 'A')
	{
		switch (type)
		{
		case 'T': //просто треугольник
		case 't':
			return new Triangle(fSide, sSide, angle);
		case 'R': //прямоугольный
		case 'r':
			return new RightTriangle(fSide, sSide, angle);
		case 'E': //равносторонний
		case 'e':
			return new EquilateralTriangle(fSide, sSide, angle);
		case 'I': //равнобедренный
		case 'i':
			return new IsoscelesTriangle(fSide, sSide, angle);
		case 'A': //авто с возможностью конвертации
		case 'a':
		{
			if (angle == 90)
			{
				return new RightTriangle(fSide, sSide, angle);
			}
			if (fSide == sSide)
			{
				if (angle == 60)
				{
					return new EquilateralTriangle(fSide, sSide, angle);
				}
				return new IsoscelesTriangle(fSide, sSide, angle);
			}
			const double tSideU = sqrt(fSide * fSide + sSide * sSide - 2 * fSide * sSide * cos(3.14 * angle / 180));
			if (abs(tSideU - fSide) <= 0.1) //равнобедренный
			{
				return new IsoscelesTriangle(fSide, fSide, 180 - angle * 2);
			}
			if (abs(tSideU - sSide) <= 0.1)
			{
				return new IsoscelesTriangle(sSide, sSide, 180 - angle * 2);
			}
			double tSide = sqrt(pow(std::max(fSide, sSide), 2) - pow(std::min(fSide, sSide), 2));
			if (abs(tSide - tSideU) <= 0.1) //прямоугольный
			{
				return new RightTriangle(std::min(fSide, sSide), tSide, 90);
			}
			return new Triangle(fSide, sSide, angle);
		}
		default:
			throw std::exception("Incorrect triangle type entered");
		}
	}
};

