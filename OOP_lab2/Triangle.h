#pragma once
#include <algorithm>
#include <cmath>

class Triangle
{
public:
	double GetFirstSide() const { return _fSide; }
	double GetSecondSide() const { return _sSide; }
	double GetAngle() const { return _angle; }

	virtual double Perimeter() const; //периметр
	virtual double Area() const; //площадь

	Triangle() : _fSide(0), _sSide(0), _angle(0) {}
	Triangle(const double fSide, const double sSide, const double angle);
	virtual ~Triangle() = default;

protected:
	double _fSide; //первая сторона
	double _sSide; //вторая сторона
	double _angle; //угол между сторонами

	inline double GetRadian(const double degree) const; //градусы в радианы
	inline virtual double TSide() const; //вычисление третьей стороны
	
private:
	const double M_PI = 3.14159265358979323846;
};