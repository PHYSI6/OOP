#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(0, "rus");
	int n, m, N, M, kol = 0;
	cout << "Введите n:";
	cin >> n;
	cout << "Введите m:";
	cin >> m;
	N = n;
	M = m;
	int** array;
	double** array_double;
	array = new int* [m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
	}
	array_double = new double* [M];
	for (int i = 0; i < M; i++)
	{
		array_double[i] = new double[N];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> array[i][j];
		}
	}
	cout << "----------Исходный массив----------" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	cout << "----------Результирующий массив----------" << endl;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			if (array[i][j] < 0)
			{
				array_double[i][j] = -1;
			}
			else if (array[i][j] == 0)
			{
				array_double[i][j] = 0;
			}
			else
			{
				array_double[i][j] = array[i][j] * cos(array[i][j]);
			}
		}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << array_double[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (array_double[i][j] == -1)
			{
				kol++;
			}
		}
		cout << endl;
	}
	cout << "Количество -1 в результирующем массиве: " << kol << endl;
	for (int i = 0; i < n; i++)
	{
		delete[]array[i];
	}
	delete[]array;
	for (int i = 0; i < N; i++)
	{
		delete[] array_double[i];
	}
	delete[]array_double;
	system("pause");
	return 0;
}
