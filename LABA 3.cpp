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
	void OutPut();
	char* operator+=(char* s);
	char* operator=(char* s);
	friend void Input(String&);
	friend void Output(String&);
};

void Input(String& a)
{
	cout << "Введите строку 1:";
	cin.getline(a.str, 80, '\n');
}
void Output(String& a)
{
	for (int i = 0; a.str[i] != '\0'; i++) {
		cout << a.str[i];
	}
	cout << endl;
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

void String::OutPut()
{
	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i];
	}
	cout << endl;
}

int main()
{
	setlocale(0, "rus");
	char str1[80];
	int vibor;
	String obj;
	Input(obj);
	cout << "Введите 2 строку:";
	cin.getline(str1, 80, '\n');
	cout << "Выберите действие" << "\n1.объект=строка\n2.объект+=строка\n3.Выход\n";
	cout << "->";
	vibor = fun_check();
	cout << endl;
	switch (vibor)
	{
	case 1:
		cout << "Исходная строка 1(объект):";
		Output(obj);
		cout << "Исходная строка 2:";
		OutPutStr(str1);
		cout << "\n------Результат после присваивания объекту строки-----\n";
		obj = str1;
		cout << "Первая строка(объект):";
		Output(obj);
		cout << "Вторая строка:";
		OutPutStr(str1);
		break;
	case 2:
		cout << "Исходная строка 1(объект):";
		Output(obj);
		cout << "Исходная строка 2:";
		OutPutStr(str1);
		obj += str1;
		cout << endl;
		cout << "\n-----Результат сложения объекта и строки-----\n";
		Output(obj);
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
