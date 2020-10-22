#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
int fun_check();
class String
{
	char* str;
public:
	String(const char*);
	String(const String&);
	~String();
	char* operator+=(char* s);
	char* operator=(char* s);
	friend ostream& operator<<(ostream& out, const String& obj);
	friend istream& operator>>(istream& in, String& obj);
};

ostream& operator <<(ostream& out, const String& obj)
{
	out << obj.str;
	return out;
}

istream& operator >>(istream& in, String& obj)
{
	in >> obj.str;
	return in;
}

void OutPutStr(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		cout << str[i];
	}
}
char* String::operator=(char* s)
{
	str = s;
	return str;
}
String::~String()
{
	delete[]str;
}

String::String(const char* s = "") {
	str = new char[strlen(s) + 1];
	strcpy_s(str, strlen(s) + 1, s);
}

String::String(const String& s) {
	str = new char[strlen(s.str) + 1];
	strcpy_s(str, strlen(s.str) + 1, s.str);
}

char* String::operator+=(char* s)
{
	strcat(str, s);
	return str;
}

int main()
{
	setlocale(0, "rus");
	char str1[80];
	int vibor;
	String obj;
	cout << "Введите 1 строку:";
	cin.getline(str1, 80);
	cout << "Введите 2 строку(объект):";
	cin >> obj;
	cout << "Выберите действие" << "\n1.объект=строка\n2.объект+=строка\n3.Выход\n";
	cout << "->";
	vibor = fun_check();
	cout << endl;
	switch (vibor)
	{
	case 1:
		cout << "Исходная строка 1:";
		OutPutStr(str1);
		cout << "\nИсходная строка 2(объект):";
		cout << obj << endl;
		cout << "\n------Результат после присваивания объекту строки-----\n";
		obj = str1;
		cout << "Первая строка:";
		cout << obj << endl;
		cout << "Вторая строка(объект):";
		OutPutStr(str1);
		break;
	case 2:
		cout << "Исходная строка 1:";
		OutPutStr(str1);
		cout << "\nИсходная строка 2(объект):";
		cout << obj << endl;
		obj += str1;
		cout << endl;
		cout << "\n-----Результат сложения объекта и строки-----\n";
		cout << obj;
		break;
	case 3:
		return 0;
		break;
	}
	cout << endl;
	system("pause");
	exit(1);
	return 0;
}

int fun_check()
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
