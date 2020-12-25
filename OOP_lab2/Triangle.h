#pragma once
#include <algorithm>
#include <cmath>

class Triangle
{
public:
	double GetFirstSide() const { return _fSide; }
	double GetSecondSide() const { return _sSide; }
	double GetAngle() const { return _angle; }

	virtual double Perimeter() const; //��������
	virtual double Area() const; //�������

	Triangle() : _fSide(0), _sSide(0), _angle(0) {}
	Triangle(const double fSide, const double sSide, const double angle);
	virtual ~Triangle() = default;

protected:
	double _fSide; //������ �������
	double _sSide; //������ �������
	double _angle; //���� ����� ���������

	inline double GetRadian(const double degree) const; //������� � �������
	inline virtual double TSide() const; //���������� ������� �������
	
private:
	const double M_PI = 3.14159265358979323846;
};