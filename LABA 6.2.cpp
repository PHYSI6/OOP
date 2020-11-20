#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
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
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}

class literature
{
protected:
	string book_name;
	string avtor;
	int kol_str;
public:
	literature();
	literature(string book_name1, string avtor1, int kol_str1)
	{
		book_name = book_name1;
		avtor = avtor1;
		kol_str = kol_str1;
	}
	void show()
	{
		cout << "Название книги:" << book_name << endl;
		cout << "Автор книги:" << avtor << endl;
		cout << "Количество страниц:" << kol_str << endl;
	}
	void booktype()
	{
		cout << "Литература";
	}
	~literature();
};

literature::~literature()
{
}

literature::literature()
{
}
class comedy : virtual public literature
{
protected:
	string rating;
	string data_out;
public:
	comedy();
	comedy(string book_name1, string avtor1, int kol_str1, string rating1, string data_out1) : literature(book_name1, avtor1, kol_str1)
	{
		rating = rating1;
		data_out = data_out1;
	}
	void show()
	{
		cout << "Рейтинг:" << rating << endl;
		cout << "Дата выхода:" << data_out << endl;
	};
	void booktype()
	{
		cout << "-----Комедия-----\n";
	}
	~comedy();
};
comedy::comedy()
{
}
comedy::~comedy()
{}
class drama :virtual public literature
{
protected:
	string year_limit;
	string publishing;
public:
	drama();
	drama(string book_name1, string avtor1, int kol_str1, string year_limit1, string publishing1) : literature(book_name1, avtor1, kol_str1)
	{
		year_limit = year_limit1;
		publishing = publishing1;
	}
	void show()
	{
		cout << "Ограничение по возрасту:" << year_limit << endl;
		cout << "Издательство:" << publishing << endl;
	};
	void booktype()
	{
		cout << "-----Драма-----\n";
	}
	~drama();
};

drama::drama()
{
}
drama::~drama() {}
class drama_comedy : public drama, public comedy
{
protected:
	string book_quality;
	string type_of_jacket;
public:
	drama_comedy();
	drama_comedy(string book_name1, string avtor1, int kol_str1, string rating1, string data_out1, string year_limit1, string publishing1, string book_quality1, string type_of_jacket1) : drama(book_name1, avtor1, kol_str1, year_limit1, publishing1), comedy(book_name1, avtor1, kol_str1, rating1, data_out1), literature(book_name1, avtor1, kol_str1)
	{
		book_quality = book_quality1;
		type_of_jacket = type_of_jacket1;
	}
	void show()
	{
		literature::show();
		comedy::show();
		drama::show();
		cout << "Состояние книги:" << book_quality << endl;
		cout << "Тип обложки:" << type_of_jacket << endl;
	};
	void booktype()
	{
		drama::booktype();
		comedy::booktype();
		cout << "-----Драма-Комедия-----\n";
	}
	~drama_comedy();
};
drama_comedy::drama_comedy() {}
void ConsoleSetting()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 100, 50 };
	SetConsoleScreenBufferSize(hWnd, bufferSize);
}
drama_comedy::~drama_comedy() {}
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
int fun_check()
{
	int a;
	while (true)
	{
		cin >> a;
		if (a == 1 || a == 2 || a == 3 || a == 4 && cin.get() == '\n') break;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Данные введены некоректно, повторите ввод: ";
	}
	return a;
}
string NAME_CORR()
{
	string slovo;
	int button;
	char sumbol;
	while (true) {
		button = _getch();
		if (button == 8) { // - backspace
			if (slovo.length() != 0) {
				cout << '\b' << " " << '\b';
				slovo.erase(slovo.length() - 1); //erase - удаление
			}
		}
		else
			if (button == 13) break; // - enter
			else {
				sumbol = (char)button;
				if ((sumbol >= 'а' && sumbol <= 'я') || (sumbol >= 'А' && sumbol <= 'Я') || sumbol == ' ') {
					slovo = slovo + sumbol;
					cout << sumbol;
				}
			}
	}
	return slovo;
}
string INITIALS_CORR()
{
	string slovo;
	int button;
	char sumbol;
	while (true) {
		button = _getch();
		if (button == 8) { // - backspace
			if (slovo.length() != 0) {
				cout << '\b' << " " << '\b';
				slovo.erase(slovo.length() - 1); //erase - удаление
			}
		}
		else
			if (button == 13) break; // - enter
			else {
				sumbol = (char)button;
				if ((sumbol >= '1' && sumbol <= '9') || sumbol == '.' || sumbol == '0') {
					slovo = slovo + sumbol;
					cout << sumbol;
				}
			}
	}
	return slovo;
}
int main()
{
	ConsoleSetting();
	string bookname, avtor, rating, date_out, year_limit, publishing, book_quality, type_of_jacket;
	int kol_str;
	bool zikl1 = true;
	bool zikl2 = true;
	int n = 0;
	drama_comedy* mas = new drama_comedy[n];
	int vibor1, vibor2;
	while (zikl1)
	{
		cout << "\n1.Ввод информации\n2.Просмотр информации\n3.Выход\n";
		cout << "->";
		vibor1 = fun_check1();
		system("cls");
		switch (vibor1)
		{
		case 1:
		{
			cout << "\nВведите название книги:";
			bookname = NAME_CORR();
			cout << "\nВведите имя автора:";
			avtor = NAME_CORR();
			cout << "\nВведите количество страниц:";
			kol_str = getInt();
			cout << "Введите рейтинг:";
			cin >> rating;
			cout << "Введите дату издания:";
			date_out = INITIALS_CORR();
			cout << "\nВведите возврастное ограничение:";
			cin >> year_limit;
			cout << "Введите издательство:";
			publishing = NAME_CORR();
			cout << "\nВведите состояние книги:";
			book_quality = NAME_CORR();
			cout << "\nВведите тип обложки:";
			type_of_jacket = NAME_CORR();
			drama_comedy dc(bookname, avtor, kol_str, rating, date_out, year_limit, publishing, book_quality, type_of_jacket);
			drama_comedy* mas1 = new drama_comedy[n + 1];
			copy(mas, mas + n, mas1);
			mas1[n] = dc;
			n++;
			delete[]mas;
			mas = mas1;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			if (n == 0)
			{
				cout << "Объект не найден!" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				for (int i = 0; i < n; i++)
				{
					mas[i].booktype();
					mas[i].show();
					cout << endl;
				}
				system("pause");
				system("cls");
			}

			break;
		}
		case 3:
		{
			delete[]mas;
			zikl1 = false;
			break;
		}
		}
	}
	return 0;
}
