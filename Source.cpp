#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
class employee
{
	int nomer_sotrudnika;
	float velichina_oklada;
	enum PROFESIYA
	{
		 Программист = 1, Тестировщик , Аналитик , Архитектор ,Менеджер , Начальник
	};
	string dolzhnost;
	class date
	{
	public:
		int den_priema;
		int mesyac_priema;
		int god_priema;
	}dataprim;
public:
	void getemploy();
	void putemploy();
};

void employee::getemploy()
{
	cout << "Введите номер сотрудника:";
	cin >> nomer_sotrudnika;
	cout << "Введите величину оклада(в рублях):";
	cin >> velichina_oklada;
	cout << "Введите день приема на работу:";
	cin >>dataprim.den_priema;
	cout << "Введите месяц приема на работу:";
	cin >> dataprim.mesyac_priema;
	cout << "Введите год приема на работу:";
	cin >> dataprim.god_priema;
	int fl;
	cout << "\n-----Выберите должность-----\n1.Программист\n2.Тестировщик\n3.Аналитик\n4.Архитектор\n5.Менеджер\n6.Начальник отдела\n";
	cin >> fl;
	switch (fl)
	{
	case (Программист):
		dolzhnost = "Программист";
		break;
	case (Тестировщик):
		dolzhnost = "Тестировщик";
		break;
	case (Аналитик):
		dolzhnost = "Аналитик";
		break;
	case (Архитектор):
		dolzhnost = "Архитектор";
		break;
	case (Менеджер):
		dolzhnost = "Менеджер";
		break;
	case (Начальник):
		dolzhnost = "Начальник отдела";
		break;
	}
}
void employee::putemploy()
{
	cout << endl;
	cout << "Номер сотрудника:" << nomer_sotrudnika<<endl;
	cout << "Должность сотрудника:" << velichina_oklada << endl;
	cout << "Должность сотрудника:" << dolzhnost << endl;
	cout << "Дата приема на работу: " <<dataprim.den_priema<<" "<<dataprim.mesyac_priema<<" "<<dataprim.god_priema;
	cout << endl;
}
int main()
{
	setlocale(0, "rus");
	employee *mas;
	int size;
	cout << "Количество сотрудников:";
	cin >> size;
	mas = new employee[size];
	for (int i = 0; i < size; i++)
	{
		mas[i].getemploy();
	}
	for (int i = 0; i < size; i++)
	{
		mas[i].putemploy();
	}
	delete[]mas;
	system("pause");
	return 0;
}

