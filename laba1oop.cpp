#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	setlocale(0, "rus");
	int a, b, c;
	double x1, x2;
	cout << "���������� ��������� ���� Ax^2 + Bx + C = 0" << endl;
	cout << "������� A:";
	cin >> a;
	cout << "������� B:";
	cin >> b;
	cout << "������� C:";
	cin >> c;
	if (b * b - 4 * a * c > 0)
	{
		cout << "----����� ���������----" << endl;
		x1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		cout << "������ ������ = " << setw(10) << setfill('#') << setprecision(4) << x1 << endl;
		cout << "������ ������ = " << setw(10) << setfill('#') << setprecision(4) << x2 << endl;
	}
	else if (b * b - 4 * a * c == 0)
	{
		x1 = -b / (2 * a);
		cout << "������������ ������ = " << setw(10) << setfill('#') << setprecision(4) << x1 << endl;
	}
	else
	{
		cout << "������ ���!";
	}
	system("pause");
	return 0;
}
