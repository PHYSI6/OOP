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

template <typename T>
class List {
private:
	T* a = new T;
	int n = 0;
public:
	List() {};
	void add(T k) {
		T* ptr = new T[n + 1];
		for (int i = 0; i < n; i++) {
			ptr[i] = a[i];
		}
		a = ptr;
		ptr = NULL;
		delete[]ptr;
		a[n] = k;
		n++;
	}
	void checkEmpty() {
		if (n == 0) cout << "Список пуст!!!";
		else
		{
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
		}
	}
	void del() {
		n--;
	}
};

template <typename T>
class Tranzktion {
public:
	List<T>* that;
	List<T>* previos;
public:
	Tranzktion() :previos(NULL), that(new List<T>) {};
	Tranzktion(const Tranzktion <T>& _st) :that(new List<T>(*(_st.that))), previos(NULL) {};
	~Tranzktion() {
		delete that;
		delete previos;
	};
	Tranzktion<T>& operator=(const Tranzktion<T>& _st) {
		if (this != &_st)
		{
			delete that;
			that = new List<T>(*(_st.that));
		}
		return *this;
	};
	void BeginTrans()
	{
		delete previos;
		previos = that;
		that = new List<T>(*previos);
	};
	void Commit()
	{
		delete previos;
		previos = NULL;
	};
	void Rollback()
	{
		if (previos != NULL)
		{
			delete that;
			that = previos;
			previos = NULL;
		}
	};
	List<T>* operator->() { return that; };
};

int main()
{
	setlocale(LC_ALL, "rus");
	int add = 0;
	int	add1 = 0;
	bool r = true;
	char choice2;
	Tranzktion<int> list1;
	while (r) {
		cout << "1.Добавление\n2.Просмотр\n3.Удаление\n4.Откат\n5.Выход\n->";
		choice2 = fun_check();
		system("cls");
		switch (choice2)
		{
		case 1:
			list1.BeginTrans();
			cout << "Введите элемент: ";
			add = getInt();
			list1->add(add);
			system("pause");
			system("cls");
			break;
		case 2:
			list1->checkEmpty();
			system("pause");
			system("cls");
			break;
		case 3:
			list1.BeginTrans();
			list1->del();
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "Список до отката:";
			list1->checkEmpty();
			cout << endl;
			list1.Rollback();
			cout << "Список после отката:";
			list1->checkEmpty();
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			r = false;
			system("pause");
			break;
		}
	}
	return 0;
}
