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
class literature
{
protected:
	string book_name;
	string avtor;
	int kol_str;
public:
	literature(string avtor1, string book_name1, int kol_str1)
	{
		kol_str = kol_str1;
		avtor = avtor1;
		book_name = book_name1;
	}
	virtual void show() = 0;
};

class pro_voinu :public literature
{
	string nazvaine_voini;
	string data_nachala;
	string data_konca;
public:
	pro_voinu(string avtor1, string book_name1, int kol_str1, string nazvanie_voini1, string data_nachala1, string data_konca1) :literature(avtor1, book_name1, kol_str1)
	{
		nazvaine_voini = nazvanie_voini1;
		data_nachala = data_nachala1;
		data_konca = data_konca1;
	}

	void show()
	{
		cout << "\nНазвание книги:" << book_name << "\nИмя автора:" << avtor << "\nКоличестро страниц:" << kol_str << "\nНазвание войны:" << nazvaine_voini << "\nДата начала:" << data_nachala << "\nДата конца:" << data_konca << endl;
	}
};

class fantastika :public literature
{
	int kolichestvo_chastei;
	int rating;
public:
	fantastika(string avtor1, string book_name1, int kol_str1, int kolichestvo_chastei1, int rating1) :literature(avtor1, book_name1, kol_str1)
	{
		kolichestvo_chastei = kolichestvo_chastei1;
		rating = rating1;
	}
	void show()
	{
		cout << "\nНазвание книги:" << book_name << "\nИмя автора:" << avtor << "\nКоличестро страниц:" << kol_str << "\nКоличество частей:" << kolichestvo_chastei << "\nРейтинг(по 10-балльной шкале):" << rating << endl;
	}
};

class uzhasi :public literature
{
	int kol_exemplyarov;
	string ogranichenie_po_vozrastu;
public:
	uzhasi(string  avtor1, string  book_name1, int kol_str1, string ogranichenie_po_vozrastu1, int kol_exemplyarov1) : literature(avtor1, book_name1, kol_str1)
	{
		kol_exemplyarov = kol_exemplyarov1;
		ogranichenie_po_vozrastu = ogranichenie_po_vozrastu1;
	}
	void show()
	{
		cout << "\nНазвание книги:" << book_name << "\nИмя автора:" << avtor << "\nКоличестро страниц:" << kol_str << "\nОграничение по возрасту:" << ogranichenie_po_vozrastu << "\nКоличество экземляров:" << kol_exemplyarov << endl;
	}
};
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
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 1;
	literature** mas = new literature * [n];
	n--;
	string AVTOR, book_name, random;
	string nazvanie_voini, data_nachala_voini, data_konca_voini, ogranichenie_po_vozrastu;
	int KOL_STR, vibor, vibor1, kol_chastei, rating, kol_exp;
	bool zikl1 = true;
	bool zikl2 = true;
	while (zikl1)
	{
		cout << "\n1.Ввод информации\n2.Просмотр информации\n3.Выход\n";
		vibor = fun_check1();
		system("cls");
		switch (vibor)
		{
		case 1:
		{
			while (zikl2)
			{
				cout << "-----Ввод данных----";
				cout << "\n1.Литературный жанр - про войну\n2.Литературный жанр - фантастика\n3.Литературный жанр - ужастик\n4.Выход\n->";
				vibor1 = fun_check();
				system("cls");
				switch (vibor1)
				{
				case 1:
				{
					cout << "-----ПРО ВОЙНУ-----";
					cout << "\nВведите название книги:";
					book_name = NAME_CORR();
					cout << "\nВведите имя автора:";
					AVTOR = NAME_CORR();
					cout << "\nВведите количество страниц:";
					KOL_STR = getInt();
					cout << "Введите название войны:";
					nazvanie_voini = NAME_CORR();
					cout << "\nВведите дату начала войны:";
					data_nachala_voini = INITIALS_CORR();
					cout << "\nВведите дату конца войны:";
					data_konca_voini = INITIALS_CORR();
					cout << endl;
					mas[n] = new pro_voinu(AVTOR, book_name, KOL_STR, nazvanie_voini, data_nachala_voini, data_konca_voini);
					mas[n]->show();
					n++;
					n++;
					literature** masPV = new literature * [n];
					n--;
					copy(mas, mas + n, masPV);
					mas = masPV;
					masPV = NULL;
					delete[]masPV;
					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					cout << "-----ФАНТАСТИКА-----";
					cout << "\nВведите название книги:";
					book_name = NAME_CORR();
					cout << "\nВведите имя автора:";
					AVTOR = NAME_CORR();
					cout << "\nВведите количество страниц:";
					KOL_STR = getInt();
					cout << "Введите количество частей:";
					kol_chastei = getInt();
					cout << "Введите рейтинг:";
					rating = getInt();
					mas[n] = new fantastika(AVTOR, book_name, KOL_STR, kol_chastei, rating);
					mas[n]->show();
					n++;
					n++;
					literature** masFAN = new literature * [n];
					n--;
					copy(mas, mas + n, masFAN);
					mas = masFAN;
					masFAN = NULL;
					delete[]masFAN;
					cout << endl;
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					cout << "-----УЖАСТИКИ-----";
					cout << "\nВведите название книги:";
					book_name = NAME_CORR();
					cout << "\nВведите имя автора:";
					AVTOR = NAME_CORR();
					cout << "\nВведите количество страниц:";
					KOL_STR = getInt();
					cout << "Введите количество экземляров:";
					kol_exp = getInt();
					cout << "Введите ограничение по возрасту:";
					cin >> ogranichenie_po_vozrastu;
					mas[n] = new uzhasi(AVTOR, book_name, KOL_STR, ogranichenie_po_vozrastu, kol_exp);
					mas[n]->show();
					n++;
					n++;
					literature** masUZH = new literature * [n];
					n--;
					copy(mas, mas + n, masUZH);
					mas = masUZH;
					masUZH = NULL;
					delete[]masUZH;
					system("pause");
					system("cls");
					break;
				}
				case 4:
				{
					zikl2 = false;
					break;
				}
				}
			}
			break; }
		case 2:
		{
			if (n != 0)
			{
				for (int i = 0; i < n; i++)
					mas[i]->show();
				cout << endl;
				system("pause");
			}
			else
			{
				cout << "Объект не найден!" << endl;
				system("pause");
				continue;
			}
			break;
		}
		case 3:
		{
			zikl1 = false;
			break;
		}
		}
	}
	return 0;
}
