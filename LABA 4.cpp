#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
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
	char* book_name;
	char* avtor;
	int kol_str;
public:
	literature(char* avtor1, char* book_name1, int kol_str1)
	{
		kol_str = kol_str1;
		book_name = new char[strlen(book_name1) + 1];
		strcpy_s(book_name, strlen(book_name1) + 1, book_name1);
		avtor = new char[strlen(avtor1) + 1];
		strcpy_s(avtor, strlen(avtor1) + 1, avtor1);
	}
	~literature()
	{
		delete[]book_name;
		delete[]avtor;
	}
};

class pro_voinu :public literature
{
	char* nazvaine_voini;
	char* data_nachala;
	char* data_konca;
public:
	pro_voinu(char* avtor1, char* book_name1, int kol_str1, char* nazvanie_voini1, char* data_nachala1, char* data_konca1) :literature(avtor1, book_name1, kol_str1)
	{
		nazvaine_voini = new char[strlen(nazvanie_voini1) + 1];
		strcpy_s(nazvaine_voini, strlen(nazvanie_voini1) + 1, nazvanie_voini1);
		data_nachala = new char[strlen(data_nachala1) + 1];
		strcpy_s(data_nachala, strlen(data_nachala1) + 1, data_nachala1);
		data_konca = new char[strlen(data_konca1) + 1];
		strcpy_s(data_konca, strlen(data_konca1) + 1, data_konca1);
	}
	~pro_voinu()
	{
		delete[]nazvaine_voini;
		delete[]data_nachala;
		delete[]data_konca;
	}
	void display_pro_voinu()
	{
		cout << "\nНазвание книги:" << book_name << "\nИмя автора:" << avtor << "\nКоличестро страниц:" << kol_str << "\nНазвание войны:" << nazvaine_voini << "\nДата начала:" << data_nachala << "\nДата конца:" << data_konca << endl;
	}
};

class fantastika :public literature
{
	int kolichestvo_chastei;
	int rating;
public:
	fantastika(char* avtor1, char* book_name1, int kol_str1, int kolichestvo_chastei1, int rating1) :literature(avtor1, book_name1, kol_str1)
	{
		kolichestvo_chastei = kolichestvo_chastei1;
		rating = rating1;
	}
	void display_avtor()
	{
		cout << "\nНазвание книги:" << book_name << "\nИмя автора:" << avtor << "\nКоличестро страниц:" << kol_str << "\nКоличество частей:" << kolichestvo_chastei << "\nРейтинг(по 10-балльной шкале):" << rating;
	}
};

class uzhasi :public literature
{
	int kol_exemplyarov;
	char* ogranichenie_po_vozrastu;
public:
	uzhasi(char* avtor1, char* book_name1, int kol_str1, char* ogranichenie_po_vozrastu1, int kol_exemplyarov1) : literature(avtor1, book_name1, kol_str1)
	{
		kol_exemplyarov = kol_exemplyarov1;
		ogranichenie_po_vozrastu = new char[strlen(ogranichenie_po_vozrastu1) + 1];
		strcpy_s(ogranichenie_po_vozrastu, strlen(ogranichenie_po_vozrastu1) + 1, ogranichenie_po_vozrastu1);
	}
	~uzhasi()
	{
		delete[]ogranichenie_po_vozrastu;
	}
	void display_uzhasi()
	{
		cout << "\nНазвание книги:" << book_name << "\nИмя автора:" << avtor << "\nКоличестро страниц:" << kol_str << "\nОграничение по возрасту:" << ogranichenie_po_vozrastu << "\nКоличество экземляров:" << kol_exemplyarov;
	}
};
int main()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char BOOK_NAME[80];
	char AVTOR[80];
	string random;
	int KOL_STR, vibor;
	while (true)
	{
		cout << endl;
		cout << "\n1.Литературный жанр - про войну\n2.Литературный жанр - фантастика\n3.Литературный жанр - ужастик\n4.Выход\n->";
		vibor = fun_check();
		system("cls");
		switch (vibor)
		{
		case 1: {
			char nazvanie_voini[80];
			char data_nachala_voini[80];
			char data_konca_voini[80];
			cout << "-----ПРО ВОЙНУ-----";
			cout << "\nВведите название книги:";
			getline(cin, random);
			cin.getline(BOOK_NAME, 80);
			cout << "\nВведите имя автора:";
			cin.getline(AVTOR, 80);
			cout << "\nВведите количество страниц:";
			KOL_STR = getInt();
			cout << "\nВведите название войны:";
			cin.getline(nazvanie_voini, 80);
			cout << "\nВведите дату начала войны:";
			cin.getline(data_nachala_voini, 80);
			cout << "\nВведите дату конца войны:";
			cin.getline(data_konca_voini, 80);
			pro_voinu voina(AVTOR, BOOK_NAME, KOL_STR, nazvanie_voini, data_nachala_voini, data_konca_voini);
			voina.display_pro_voinu();
			break; }
		case 2:
		{
			int kol_chastei;
			int rating;
			cout << "-----ФАНТАСТИКА-----\n";
			cout << "\nВведите название книги:";
			getline(cin, random);
			cin.getline(BOOK_NAME, 80);
			cout << "\nВведите имя автора:";
			cin.getline(AVTOR, 80);
			cout << "\nВведите количество страниц:";
			KOL_STR = getInt();
			cout << "\nВведите количество частей:";
			kol_chastei = getInt();
			cout << "\nВвердите рейтинг книги(от 1 до 10):";
			rating = getInt();
			fantastika fant(AVTOR, BOOK_NAME, KOL_STR, kol_chastei, rating);
			fant.display_avtor();
			break;
		}
		case 3:
		{
			char ogranichenie[80];
			int kol_exp;
			cout << "-----УЖАСТИКИ-----\n";
			cout << "\nВведите название книги:";
			getline(cin, random);
			cin.getline(BOOK_NAME, 80);
			cout << "\nВведите имя автора:";
			cin.getline(AVTOR, 80);
			cout << "\nВведите количество страниц:";
			KOL_STR = getInt();
			cout << "\nВведите возрастное ограничение:";
			cin.getline(ogranichenie, 80);
			cout << "\nВведите количество экземляров книги:";
			kol_exp = getInt();
			uzhasi zhest(AVTOR, BOOK_NAME, KOL_STR, ogranichenie, kol_exp);
			zhest.display_uzhasi();
			break;
		}
		case 4:
		{
			return 0;
			break;
		}
		}
	}

	return 0;
}
