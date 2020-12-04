#include<iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;
int getInt() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}
int fun_check()
{
	int a;
	while (true)
	{
		cin >> a;
		if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 && cin.get() == '\n') break;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Данные введены некоректно, повторите ввод: ";
	}
	return a;
}
int fun_check1()
{
	int a;
	while (true)
	{
		cin >> a;
		if (a == 1 || a == 2 || a == 3 && cin.get() == '\n') break;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Данные введены некоректно, повторите ввод: ";
	}
	return a;
}
template<class T>
class List {
private:
	T info;
	List<T>* nachalo;
	List<T>* konec;
	List<T>* pred;
	List<T>* sled;
public:
	List();
	~List();
	List(const List<T>&);
	void display();
	void add(T);
	void del();
	template<class T> friend ostream& operator <<(ostream&, List<T>&);
	bool operator==(List<T>&);
};

template <class T> List<T>::List() {
	info = 0;
	nachalo = NULL;
	konec = NULL;
	pred = NULL;
	sled = NULL;
}

template<class T> List<T>::List(const List<T>& list) {
	info = list.info;
	nachalo = list.nachalo;
	konec = list.konec;
	pred = list.pred;
	sled = list.sled;
}

template <class T> void List<T>::add(T inf) {
	List<T>* list = new List<T>();
	list->sled = NULL;
	list->info = inf;
	if (!nachalo)
	{
		list->pred = NULL;
		nachalo = list;
		konec = list;
	}
	else {
		list->pred = konec;
		konec->sled = list;
		konec = list;
	}
}

template <class T> void List<T>::del() {
	if (nachalo != NULL) {
		if (nachalo == konec) {
			nachalo->sled = NULL;
			nachalo = NULL;
			delete nachalo;
		}
		else {
			List<T>* list = konec;
			konec = konec->pred;
			konec->sled = NULL;
			delete list;
		}
		cout << "Элемент удален!" << endl;
	}
}

template <class T> void List<T>::display() {
	List<T>* list = nachalo;
	if (list == NULL) {
		cout << "Список пуст!";
	}
	else {
		while (list) {
			cout << list->info << " ";
			list = list->sled;
		}
	}
	cout << endl;
}

template<class T> ostream& operator <<(ostream& out, List<T>& list) {
	if (list.nachalo == NULL) out << "Список пуст!";
	else {
		while (list.nachalo) {
			out << list.nachalo->info << " ";
			list.nachalo = list.nachalo->sled;
		}
	}
	out << endl;
	return out;
}

template<class T> bool List<T>::operator ==(List<T>& list) {
	List<T>* list1 = nachalo;
	List<T>* list2 = list.nachalo;
	int len1 = 0, len2 = 0;
	while (list1) {
		len1++;
		list1 = list1->sled;
	}
	while (list2) {
		len2++;
		list2 = list2->sled;
	}
	return len1 == len2;
}

template <class T> List<T>::~List() {
	while (nachalo) {
		konec = nachalo->sled;
		delete nachalo;
		nachalo = konec;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int add = 0;
	int	add1 = 0;
	bool r = true;
	char choice, choice2;
	List<int> list1;
	List<int> list2;
	while (r) {
		cout << "1.Добавление\n2.Просмотр\n3.Удаление\n4.Перегрузка вывода\n5.Перегрузка сравнения\n6.Выход\n->";
		choice2 = fun_check();
		system("cls");
		switch (choice2)
		{
		case 1:
			cout << "\n1.Добавление элемента в список 1 \n2.Добавление элемента в список 2\n3.Выход\n->";
			choice = fun_check1();

			if (choice == 1) {
				cout << "Введите элемент: ";
				add = getInt();
				list1.add(add);
			}
			else if (choice == 2) {
				cout << "Введите элемент: ";
				add1 = getInt();
				list2.add(add1);
			}
			else if (choice == 3)
			{
				system("cls");
				break;
			}
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "\n1.Вывод списка 1\n2.Вывод списка 2\n3.Выход\n->";
			choice = fun_check1();
			if (choice == 1)
			{
				list1.display();
			}
			else if (choice == 2)
			{
				list2.display();
			}
			else if (choice == 3)
			{
				system("cls");
				break;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "\n1.Удаление последнего элемента первого списка\n2.Удаление последнего элемента второго списка\n3.Выход\n->";
			choice = fun_check1();
			if (choice == 1)
			{
				list1.del();
			}
			else if (choice == 2)
			{
				list2.del();
			}
			else if (choice == 3)
			{
				system("cls");
				break;
			}
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "\n1.Перегрузка оператора вывода первого списка\n2.Перегрузка оператора вывода второго списка\n->";
			choice = fun_check1();
			if (choice == 1)
			{
				cout << list1;
			}
			else if (choice == 2)
			{
				cout << list2;
			}
			else if (choice == 3)
			{
				system("cls");
				break;
			}
			system("pause");
			system("cls");
			break;
		case 5:
			if (list1 == list2)
			{
				cout << "Списки равны!" << endl;
			}
			else
			{
				cout << "Списки не равны!" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 6:
			r = false;
			system("pause");
			break;
		}
	}
	return 0;
}
