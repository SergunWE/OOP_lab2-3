#pragma once
#define M_PI 3.14159265358979323846 //пи

class ITriangle
{
public:
	virtual double Perimeter() const = 0; //периметр
	virtual double Area() const = 0; //площадь
	virtual double GetSide(const int num) const = 0; //получение стороны
	virtual double GetAngle() const = 0; //получение угла
	virtual ~ITriangle() = default;
};