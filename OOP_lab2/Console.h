#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Factory.h"

using namespace std;

class Console
{
public:
	void Run(); //������ �������

	~Console()
	{
		for (int i = 0; i < _numberTrNow; i++)
		{
			delete _results[i];
		}
		delete[] _results;
	}
private:
	ITriangle** _results = nullptr; //������ �������������
	int _menuItemNumber = -1; //����� ������ ����
	int _numberTr = 0; //������ �������
	int _numberTrNow = 0; //���������� �����. � ���. �������������
	static const int _numPointMenu = 8; //���������� ������� ����
	bool _warMes = true;
	const string _menu[_numPointMenu] = // �������� ����
	{
		"Create a triangle",
		"Calculate the perimeter of the triangle",
		"Calculate the area of the triangle",
		"Compare two triangles by perimeter",
		"Compare two triangles by area",
		"View created triangles",
		"Expand an array of triangles",
		"Complete the program"
	};
	const string _errInput = "Incorrect input. Try again\n\n";
	void SetNumtTr(); //��������� ������� �������
	void Input(double& v); //����
	void Input(int& v);
	void CreateTriangle(); //�������� ������������
	bool PrintArrayTr(); //����� �������
	void PrintTr(const ITriangle& tr); //����� ������������
	void CalculateValue(const int mode); //���������� ��������� � �������
	//0 - ��������
	//1 - �������
	void CompareTriangle(const int mode); //��������� ������������� �� ���. � ���.
};