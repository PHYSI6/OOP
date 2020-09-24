#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class employee
{
	int nomer_sotrudnika;
	float velichina_oklada;
	enum etype
	{
		Программист = 1,Тестировщик,Аналитик,Менеджер,Начальник
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
	void getempoly();
	void putempoly();
};
void employee::getempoly()
{
	int k;
	cout << "Введите номер сотрудника:";
	cin >> nomer_sotrudnika;
	cout << "Введите величину оклада (в рублях):";
	cin >> velichina_oklada;
	cout << "Введите день приема на работу:";
	cin >> dataprim.den_priema;
	cout << "Введите месяц приема на работу:";
	cin >> dataprim.mesyac_priema;
	cout << "Введите год приема на работу:";
	cin >> dataprim.god_priema;
	cout << "----Выберите профессию-----";
	cout << "\n1.Программист\n2.Тестировщик\n3.Аналитик\n4.Менеджер\n5.Начальник отдела\n";
	cin >> k;
	switch (k)
	{
	case(Программист):
		dolzhnost = "Программист";
		break;
	case(Тестировщик):
		dolzhnost = "Тестировщик";
		break;
	case(Аналитик):
		dolzhnost = "Аналитик";
		break;
	case(Менеджер):
		dolzhnost = "Менеджер";
			break;
	case(Начальник):
		dolzhnost = "Начальник отдела";
				break;
	}
}
void employee::putempoly()
{
	cout << endl;
	cout << "\nНомер сотрудника:" << nomer_sotrudnika << "\nВеличина оклада:" << velichina_oklada << "\nДолжность:" << dolzhnost<<"\nДата приёма на работу: "<<dataprim.den_priema<<" "<<dataprim.mesyac_priema<<" "<<dataprim.god_priema;
	cout << endl;
}
int main()
{
	setlocale(0, "rus");
	int size;
	employee *mas;
	cout << "Введите количество сотрудников:";
	cin >> size;
	mas = new employee[size];
	for (int i = 0; i < size; i++)
	{
		mas[i].getempoly();
	}
	for (int i = 0; i < size; i++)
	{
		mas[i].putempoly();
	}
	delete[]mas;
	system("pause");
	return 0;
}
