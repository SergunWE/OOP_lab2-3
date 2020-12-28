#pragma once
#define M_PI 3.14159265358979323846

class ITriangle
{
public:
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
	virtual double GetSide(const int num) const = 0;
	virtual double GetAngle() const = 0;
	virtual ~ITriangle() = default;
};

