#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	setlocale(0, "rus");
	double a, b, c, x1, x2, D;
	cout << "Квадратное уравнение типа Ax^2 + Bx + C = 0" << endl;
	cout << "Введите A:";
	cin >> a;
	cout << "Введите B:";
	cin >> b;
	cout << "Введите C:";
	cin >> c;
	D = b * b - 4 * a * c;
	if (D > 0)
	{
		cout << "----Корни уравнения----" << endl;
		x1 = (-b - sqrt(D)) / (2 * a);
		x2 = (-b + sqrt(D)) / (2 * a);
		cout << "Первый корень = " << setw(10) << setfill('#') << setprecision(4) << x1 << endl;
		cout << "Второй корень = " << setw(10) << setfill('#') << setprecision(4) << x2 << endl;
	}
	else if (D == 0)
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
