#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Factory.h"

using namespace std;

class Console
{
public:
	void Run(); //запуск консоли

	~Console()
	{
		for (int i = 0; i < _numberTrNow; i++)
		{
			delete _results[i];
		}
		delete[] _results;
	}
private:
	ITriangle** _results = nullptr; //массив треугольников
	int _menuItemNumber = -1; //номер пункта меню
	int _numberTr = 0; //размер массива
	int _numberTrNow = 0; //количество запис. в мас. треугольников
	static const int _numPointMenu = 8; //количество пунктов меню
	bool _warMes = true;
	const string _menu[_numPointMenu] = // основное меню
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
	void SetNumtTr(); //установка размера массива
	void Input(double& v); //ввод
	void Input(int& v);
	void CreateTriangle(); //создание треугольника
	bool PrintArrayTr(); //вывод массива
	void PrintTr(const ITriangle& tr); //вывод треугольника
	void CalculateValue(const int mode); //вычисление периметра и площади
	//0 - периметр
	//1 - площадь
	void CompareTriangle(const int mode); //сравнение треугольников по пер. и пло.
};