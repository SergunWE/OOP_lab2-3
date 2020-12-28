#pragma once
#include <algorithm>
#include <cmath>
#include "ITriangle.h"

class Triangle : public ITriangle
{
public:
	double Perimeter() const override; //��������
	double Area() const override; //�������
	double GetAngle() const override { return _angle; } //����
	double GetSide(const int num) const override; //������� ������������

	Triangle() : _fSide(0), _sSide(0), _angle(0) {}
	Triangle(const double fSide, const double sSide, const double angle);

private:
	double _fSide; //������ �������
	double _sSide; //������ �������
	double _angle; //���� ����� ���������
};