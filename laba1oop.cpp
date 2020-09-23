#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	setlocale(0, "rus");
	int a, b, c;
	double x1, x2;
	cout << "Квадратное уравнение типа Ax^2 + Bx + C = 0" << endl;
	cout << "Введите A:";
	cin >> a;
	cout << "Введите B:";
	cin >> b;
	cout << "Введите C:";
	cin >> c;
	if (b * b - 4 * a * c > 0)
	{
		cout << "----Корни уравнения----" << endl;
		x1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		cout << "Первый корень = " << setw(10) << setfill('#') << setprecision(4) << x1 << endl;
		cout << "Второй корень = " << setw(10) << setfill('#') << setprecision(4) << x2 << endl;
	}
	else if (b * b - 4 * a * c == 0)
	{
		x1 = -b / (2 * a);
		cout << "Единственный корень = " << setw(10) << setfill('#') << setprecision(4) << x1 << endl;
	}
	else
	{
		cout << "Корней нет!";
	}
	system("pause");
	return 0;
}
