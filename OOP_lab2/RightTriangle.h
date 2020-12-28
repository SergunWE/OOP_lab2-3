#pragma once
#include <algorithm>
#include <cmath>
#include "ITriangle.h"

class RightTriangle : public ITriangle //������������� �����������
{
public:
	virtual double Perimeter() const override; //��������
	virtual double Area() const override; //�������
	double GetAngle() const override { return 90; } //����
	double GetSide(const int num) const override; //������� ������������

	RightTriangle() : _fSide(0), _sSide(0) {}
	RightTriangle(const double fSide, const double sSide);

private:
	double _fSide; //������ �����
	double _sSide; //������ �����
};