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
		 ����������� = 1, ����������� , �������� , ���������� ,�������� , ���������
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
	cout << "������� ����� ����������:";
	cin >> nomer_sotrudnika;
	cout << "������� �������� ������(� ������):";
	cin >> velichina_oklada;
	cout << "������� ���� ������ �� ������:";
	cin >>dataprim.den_priema;
	cout << "������� ����� ������ �� ������:";
	cin >> dataprim.mesyac_priema;
	cout << "������� ��� ������ �� ������:";
	cin >> dataprim.god_priema;
	int fl;
	cout << "\n-----�������� ���������-----\n1.�����������\n2.�����������\n3.��������\n4.����������\n5.��������\n6.��������� ������\n";
	cin >> fl;
	switch (fl)
	{
	case (�����������):
		dolzhnost = "�����������";
		break;
	case (�����������):
		dolzhnost = "�����������";
		break;
	case (��������):
		dolzhnost = "��������";
		break;
	case (����������):
		dolzhnost = "����������";
		break;
	case (��������):
		dolzhnost = "��������";
		break;
	case (���������):
		dolzhnost = "��������� ������";
		break;
	}
}
void employee::putemploy()
{
	cout << endl;
	cout << "����� ����������:" << nomer_sotrudnika<<endl;
	cout << "��������� ����������:" << velichina_oklada << endl;
	cout << "��������� ����������:" << dolzhnost << endl;
	cout << "���� ������ �� ������: " <<dataprim.den_priema<<" "<<dataprim.mesyac_priema<<" "<<dataprim.god_priema;
	cout << endl;
}
int main()
{
	setlocale(0, "rus");
	employee *mas;
	int size;
	cout << "���������� �����������:";
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

