#include "Console.h"

void Console::Run()
{
	SetNumtTr();
	while (_menuItemNumber != _numPointMenu)
	{
		for (int i = 0; i < _numPointMenu; i++)
		{
			cout << i + 1 << ". " << _menu[i] << endl;
		}
		Input(_menuItemNumber);
		system("cls");
		switch (_menuItemNumber)
		{
		case 1:
			CreateTriangle();
			break;
		case 2:
			CalculateValue(0);
			break;
		case 3:
			CalculateValue(1);
			break;
		case 4:
			CompareTriangle(0);
			break;
		case 5:
			CompareTriangle(1);
			break;
		case 6:
			PrintArrayTr();
			break;
		case 7:
			SetNumtTr();
			break;
		case 8:
			break;
		default:
			cout << _errInput;
		}
	}
}

void Console::SetNumtTr()
{
	for (int i = 0; i < _numberTrNow; i++)
	{
		delete _results[i];
	}
	delete[] _results;
	_numberTr = 0;
	cout << "Enter the array's size to save triangles\n";
	while (_numberTr == 0)
	{
		Input(_numberTr);
		if (_numberTr != 0)
		{
			try
			{
				_results = new ITriangle*[_numberTr];
				/*for (int i = 0; i < _numberTr; i++)
				{
					_results[i] = nullptr;
				}*/
				system("cls");
				cout << "An array of size " << _numberTr << " is created\n\n";
				_numberTrNow = 0;
			}
			catch (bad_array_new_length)
			{
				if (_numberTr < 0)
				{
					cout << "Error. Enter a number greater than 0\n";
				}
				else
				{
					cout << "Error. Array size is too big. Please enter a smaller size\n";
				}
				_numberTr = 0;
				
			}
		}
		else
		{
			cout << "Enter a size greater than 0\n";
		}
	}
}

void Console::Input(double& v)
{
	cout << "> ";
	cin >> v;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void Console::Input(int& v)
{
	cout << "> ";
	cin >> v;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void Console::CreateTriangle()
{
	double fir;
	double sec;
	double angle;
	cout << "Enter the first side of the triangle\n";
	Input(fir);
	cout << "Enter the second side of the triangle\n";
	Input(sec);
	cout << "Enter the angle of the triangle\n";
	Input(angle);
	system("cls");
	if (_numberTrNow == _numberTr)
	{
		cout << "The array is full. A new array will be created\n";
		SetNumtTr();
	}
	try
	{
		_results[_numberTrNow] = Factory::CreateTriangle(fir, sec, angle);
		_numberTrNow++;
		cout << "The triangle was created\n\n";
	}
	catch (exception er)
	{
		cout << "Error. " << er.what() << "\n\n";
	}
	

}

bool Console::PrintArrayTr()
{
	if (_numberTrNow == 0)
	{
		cout << "The array is empty\n\n";
		return false;
	}
	cout.width(10);
	cout << left << "Number";
	cout.width(15);
	cout << left << "First Side";
	cout.width(15);
	cout << left << "Second Side";
	cout.width(6);
	cout << left << "Angle\n";
	for (int i = 0; i < _numberTrNow; i++)
	{
		cout.width(10);
		string n = to_string(i + 1) + ')';
		cout << left << n;
		PrintTr(*_results[i]);
		cout << '\n';
	}
	cout << '\n';
	return true;
}

void Console::PrintTr(const ITriangle& tr)
{
	cout.width(15);
	cout << left << tr.GetSide(1);
	cout.width(15);
	cout << left << tr.GetSide(2);
	cout.width(6);
	cout << left << tr.GetAngle();
}

void Console::CalculateValue(const int mode)
{
	if (!PrintArrayTr()) return;
	cout << "Enter the triangle number\n";
	int num = 0;
	while (num <= 0 || num > _numberTrNow)
	{
		Input(num);
		if (num <= 0 || num > _numberTrNow)
			cout << _errInput;
		else
		{
			system("cls");
			switch (mode)
			{
			case 0:
				cout << "Perimetr = ";
				cout << _results[num - 1]->Perimeter() << "\n\n";
				break;
			case 1:
				cout << "Area = ";
				cout << _results[num - 1]->Area() << "\n\n";
				break;
			default:
				cout << "Error. This mode doesn't exist\n\n";
			}
		}
	}
}

void Console::CompareTriangle(const int mode)
{
	if (!PrintArrayTr()) return;
	int num = 0;
	double value[2] = { 0, 0 };
	for (int i = 0; i < 2; i++)
	{
		num = 0;
		cout << "Enter the number of the " << i+1 << " triangle\n";
		while (num <= 0 || num > _numberTrNow)
		{
			Input(num);
			if (num <= 0 || num > _numberTrNow)
				cout << _errInput;
			else
			{
				switch (mode)
				{
				case 0:
					value[i] = _results[num-1]->Perimeter();
				break;
				case 1:
					value[i] = _results[num-1]->Area();
					break;
				default:
					cout << "Error. This mode doesn't exist\n\n";
				}
			}
		}
	}
	system("cls");
	cout << value[0] << ' ';
	if (value[0] == value[1]) cout << '=';
	else
		if (value[0] > value[1]) cout << '>';
		else cout << '<';
	cout << ' ' << value[1] << "\n\n";
}