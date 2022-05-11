#define _AFXDLL 
#include <iostream>
#include <afx.h>  //для ускорения компиляции проектов
#include <winsock2.h>
#include <process.h> /* _beginthread, _endthread */  //содержит объявления функций и макросы, используемые при работе с потоками и процессами
#include <string>
#include <fstream>
#include <list>
#include <iomanip> 
#include <conio.h>
#include <time.h>

using namespace std;

class Company {
protected:
	char email[90];
	char phone[15];
	char trn[11]; //УНП
	char paym_acc[15];  //расчетный счет
public:
	void SetEmail(const char* em) {
		strcpy_s(email, em);
	}
	void SetPhone(const char* ph) {
		strcpy_s(phone, ph);
	}
	char* GetEmail() {
		return email;
	}
	char* GetPhone() {
		return phone;
	}
	void SetTRN(const char* t) {
		strcpy_s(trn, t);
	}
	char* GetTRN() {
		return trn;
	}
	void SetPaym_Acc(const char* pm) {
		strcpy_s(paym_acc, pm);
	}
	char* GetPaym_Acc() {
		return paym_acc;
	}
	Company() {
		strcpy_s(email, "-");
		strcpy_s(phone, "-");
		strcpy_s(paym_acc, "-");
		strcpy_s(trn, "-");
	}
};

class InvestObject :public Company {
	char inv_obj[50];
	char owner[90];
	/////////////////////
public:
	InvestObject() {
		strcpy_s(inv_obj, "-");
		strcpy_s(owner, "-");
	}
	void SetInv_Obj(const char* invo) {
		strcpy_s(inv_obj, invo);
	}
	void SetOwner(const char* own) {
		strcpy_s(owner, own);
	}
	char* GetInv_obj() {
		return inv_obj;
	}
	char* GetOwner() {
		return owner;
	}
	friend bool operator<(const InvestObject& o1, const InvestObject& o2);
	friend bool operator>(const InvestObject& o1, const InvestObject& o2);
	friend bool operator==(const InvestObject& o1, const InvestObject& o2);
	friend bool operator!=(const InvestObject& o1, const InvestObject& o2);
};

bool operator<(const InvestObject& o1, const InvestObject& o2) {
	return strcmp(o1.inv_obj, o2.inv_obj) < 0;
}
bool operator>(const InvestObject& o1, const InvestObject& o2) {
	return strcmp(o1.inv_obj, o2.inv_obj) > 0;
}
bool operator==(const InvestObject& o1, const InvestObject& o2) {
	return strcmp(o1.inv_obj, o2.inv_obj) == 0;
}
bool operator!=(const InvestObject& o1, const InvestObject& o2) {
	return strcmp(o1.inv_obj, o2.inv_obj) != 0;
}

class People :public Company {
protected:
	char surname[35];
	char name[20];
	char patronymic[20];
	char passw[12];
public:
	void SetSurname(const char* sn) {
		strcpy_s(surname, sn);
	}
	void SetName(const char* n) {
		strcpy_s(name, n);
	}
	void SetPatronymic(const char* p) {
		strcpy_s(patronymic, p);
	}
	void SetPassw(const char* p) {
		strcpy_s(passw, p);
	}
	char* GetSurname() {
		return surname;
	}
	char* GetName() {
		return name;
	}
	char* GetPatronymic() {
		return patronymic;
	}
	char* GetPassw() {
		return passw;
	}
	People() {
		strcpy_s(surname, "-");
		strcpy_s(name, "-");
		strcpy_s(patronymic, "-");
		strcpy_s(passw, "-");
	}
};

class Client :public People {
	char id[10];
	float account;
	list<InvestObject> inv_portfolio;
public:
	Client() {
		account = 0;
		strcpy_s(id, "-");
	}
	void SetAccount(float a) {
		account = a;
	}
	float GetAccount() {
		return account;
	}
	void SetID(const char* a) {
		strcpy_s(id, a);
	}
	char* GetID() {
		return id;
	}
	friend bool operator<(const Client& o1, const Client& o2);
	friend bool operator>(const Client& o1, const Client& o2);
	friend bool operator==(const Client& o1, const Client& o2);
	friend bool operator!=(const Client& o1, const Client& o2);
};

bool operator<(const Client& o1, const Client& o2) {
	return strcmp(o1.surname, o2.surname) < 0;
}
bool operator>(const Client& o1, const Client& o2) {
	return strcmp(o1.surname, o2.surname) > 0;
}
bool operator==(const Client& o1, const Client& o2) {
	return strcmp(o1.surname, o2.surname) == 0;
}
bool operator!=(const Client& o1, const Client& o2) {
	return strcmp(o1.surname, o2.surname) != 0;
}

class Expert :public People {
	char position[30];
	char birthday[13];
	double salary;
	int experience;
public:
	Expert() {
		strcpy_s(position, "-");
		strcpy_s(birthday, "-");
		salary = 0;
		experience = 0;
	}
	friend bool operator<(const Expert& o1, const Expert& o2);
	friend bool operator>(const Expert& o1, const Expert& o2);
	friend bool operator==(const Expert& o1, const Expert& o2);
	friend bool operator!=(const Expert& o1, const Expert& o2);
};

bool operator<(const Expert& o1, const Expert& o2) {
	return strcmp(o1.surname, o2.surname) < 0;
}
bool operator>(const Expert& o1, const Expert& o2) {
	return strcmp(o1.surname, o2.surname) > 0;
}
bool operator==(const Expert& o1, const Expert& o2) {
	return strcmp(o1.surname, o2.surname) == 0;
}
bool operator!=(const Expert& o1, const Expert& o2) {
	return strcmp(o1.surname, o2.surname) != 0;
}

char* СheckRus(int f, void* newS) {   //проверка слова на русс.буквы
	char str[500], er[225];
	int k = 1, flag = 0, err;
	while (flag != k)
	{
		str[0] = '/0';
		recv((SOCKET)newS, str, sizeof(str), 0);
		str[strlen(str) + 1] = '\0';
		k = strlen(str);
		for (int i = 0; i < k; i++)
		{
			int l = flag;
			if ((str[i] >= (-64)) && (str[i] <= (-1)))
			{
				flag++;
			}
			if (str[i] == (32) && f == 1)
			{
				flag++;
			}
			if (str[i] == (45))
			{
				flag++;
			}
			if (flag == l)
			{
				i = k;
			}
		}
		if (flag != k)
		{
			flag = 0;
			err = 1;
			_itoa_s(err, er, 10);
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	err = 0;
	_itoa_s(err, er, 10);
	send((SOCKET)newS, er, sizeof(er), 0);
	return str;
}

char* СheckNumb(int f, void* newS) {   //проверка расчетного счета на 12 цифр и УНП на 9
	char str[500], er[225];
	int k = 0, flag = 0, err;
	while (k == 0)
	{
		str[0] = '/0';
		recv((SOCKET)newS, str, sizeof(str), 0);
		str[strlen(str) + 1] = '\0';
		k = strlen(str);
		if (f != k) {
			flag = 1;
			k = 0;
		}
		for (int i = 0; i < k; i++)
		{
			if ((str[i] >= (48)) && (str[i] <= (57)))
			{
				flag++;
			}
		}
		if (flag != k)
		{
			k = 0;
			flag = 0;
			err = 1;
			_itoa_s(err, er, 10);
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	err = 0;
	_itoa_s(err, er, 10);
	send((SOCKET)newS, er, sizeof(er), 0);
	return str;
}

float CheckFloat(void* newS) {
	float a;
	char m[500], er[225];
	int k = 1, flag = 0, dot;
	while (flag != k)
	{
		dot = 0;
		m[0] = '/0';
		recv((SOCKET)newS, m, sizeof(m), 0);
		m[strlen(m) + 1] = '\0';
		k = strlen(m);
		for (int i = 0; i < k; i++)
		{
			int l = flag;
			if ((m[i] >= (48)) && (m[i] <= (57)))
			{
				flag++;
			}
			if (m[i] == (46) && dot == 0) {
				flag++;
				dot = 1;
			}
			if (flag == l)
			{
				i = k;
			}
		}
		if (flag != k)
		{
			flag = 0;
			a = 1;
			sprintf_s(er, "%.2f", a);
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	a = 0;
	sprintf_s(er, "%.2f", a);
	send((SOCKET)newS, er, sizeof(er), 0);
	a = stof(m);
	return a;
}

int CheckInt(void* newS) {
	int a;
	char m[500], er[225];
	int k = 1, flag = 0;
	while (flag != k)
	{
		m[0] = '/0';
		recv((SOCKET)newS, m, sizeof(m), 0);
		m[strlen(m) + 1] = '\0';
		k = strlen(m);
		for (int i = 0; i < k; i++)
		{
			int l = flag;
			if ((m[i] >= (48)) && (m[i] <= (57)))
			{
				flag++;
			}
			if (flag == l)
			{
				i = k;
			}
		}
		if (flag != k)
		{
			flag = 0;
			a = 1;
			_itoa_s(a, er, 10);
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	a = 0;
	_itoa_s(a, er, 10);
	send((SOCKET)newS, er, sizeof(er), 0);
	a = atoi(m);
	return a;
}

int CheckChoice(void* newS) {
	int a;
	char m[500], er[225];
	while (1)
	{
		m[0] = '/0';
		recv((SOCKET)newS, m, sizeof(m), 0);
		m[strlen(m) + 1] = '\0';
		if (strcmp(m, "0") != 0 && strcmp(m, "1") != 0)
		{
			a = 1;
			_itoa_s(a, er, 10);
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
		else break;
	}
	a = 0;
	_itoa_s(a, er, 10);
	send((SOCKET)newS, er, sizeof(er), 0);
	a = atoi(m);
	return a;
}

int CheckInt(int a1, int a2, void* newS) {
	int a, err;
	char er[500];
	while (1) {
		a = CheckInt(newS);
		if (a<a1 || a>a2) {
			err = 1;
			_itoa_s(err, er, 10);
			send((SOCKET)newS, er, sizeof(er), 0);
		}
		else {
			err = 0;
			_itoa_s(err, er, 10);
			send((SOCKET)newS, er, sizeof(er), 0);
			return a;
		}
	}
}

char* Check_PhoneNum(void* newS) {  //проверка номера телефона
	char str[500], er[225];
	int k = 1, flag = 0, err;
	while (flag != k)
	{
		str[0] = '/0';
		recv((SOCKET)newS, str, sizeof(str), 0);
		str[strlen(str) + 1] = '\0';
		k = strlen(str);
		if (k == 13) {
			if (str[0] == '+') {
				flag++;
			}
			if ((str[1] == '3') && (str[2] == '7') && (str[3] == '5')) {
				flag = flag + 3;
			}
			if (((str[4] == '2') && (str[5] == '5')) || ((str[4] == '2') && (str[5] == '9')) || ((str[4] == '4') && (str[5] == '4')) || ((str[4] == '3') && (str[5] == '3'))) {
				flag = flag + 2;
			}
			for (int i = 6; i < 13; i++) {
				if ((str[i] >= (48)) && (str[i] <= (57))) {
					flag++;
				}
			}
		}
		if (flag != k)
		{
			flag = 0;
			err = 1;
			_itoa_s(err, er, 10);
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	err = 0;
	_itoa_s(err, er, 10);
	send((SOCKET)newS, er, sizeof(er), 0);
	return str;
}

char* Check_Mail(void* newS) {  //проверка google почты
	char str[500], er[225];
	int k = 1, flag = 0, err;
	char mass[70];
	while (flag != k)
	{
		str[0] = '/0';
		recv((SOCKET)newS, str, sizeof(str), 0);
		str[strlen(str) + 1] = '\0';
		k = strlen(str);
		if (k >= 16) {
			strcpy_s(mass, &str[k - 10]);
			if (strcmp(mass, "@gmail.com") == 0) {
				flag = flag + 10;
			}
			for (int i = 0; i < k - 10; i++) {
				if ((str[i] > 64 && str[i] < 92) || (str[i] > 96 && str[i] < 123) || (str[i] == (46))) {
					flag++;
				}
				if ((str[i] >= (48)) && (str[i] <= (57))) {
					flag++;
				}
			}
		}
		if (flag != k)
		{
			flag = 0;
			err = 1;
			_itoa_s(err, er, 10);
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	err = 0;
	_itoa_s(err, er, 10);
	send((SOCKET)newS, er, sizeof(er), 0);
	return str;
}

char* Check_Password(void* newS, int r) {  //проверка пароля
	char str[500], er[225];
	int k = 1, flag = 0, err;
	while (flag != k)
	{
		str[0] = '\0';
		recv((SOCKET)newS, str, sizeof(str), 0);
		str[strlen(str) + 1] = '\0';
		k = strlen(str);
		for (int i = 0; i < k; i++)
		{
			int l = flag;
			if (((str[i] >= (65)) && (str[i] <= (90))) || ((str[i] >= (97)) && (str[i] <= (122))) || ((str[i] >= (48)) && (str[i] <= (57))))
			{
				flag++;
			}
			if (flag == l || k < 0 || k> r)
			{
				i = k;
			}
		}
		if (flag != k)
		{
			flag = 0;
			err = 1;
			_itoa_s(err, er, 10);
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	err = 0;
	_itoa_s(err, er, 10);
	send((SOCKET)newS, er, sizeof(er), 0);
	return str;
}

int Main_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Добро пожаловать в InvestLab!\nМеню:\n 1)Войти в качестве администратора;\n 2)Войти в качестве клиента;\n 3)Войти в качестве представителя инвестиционного объекта;\n 4)Войти в качестве эксперта;\n 5)Завершить работу программы.\n ");
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 5, newS);
	return a;
}

int Admin_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню администратора:\n 1)Управление клиентами;\n 2)Принятие решения;\n 3)Управление экспертами;\n 4)Управление инвестиционными объектами;\n 5)Выйти в главное меню.\n ");
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 5, newS);
	return a;
}

int ControlCl_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню управления клиентами:\n 1)Добавление нового клиента;\n 2)Вывод таблицы со всеми клиентами в алфавитном порядке;\n 3)Разрыв договора с клиентом;\n 4)Редактирование данных клиента;\n 5)Вывод договора клиента;\n 6)Фильтрация и сортировка данных;\n 7)Выйти в меню администратора.\n");
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 7, newS);
	return a;
}

int MakeDecis_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню принятия решения:\n 1)Вывод таблицы незавершенных проектов;\n 2)Вывод завершенных непросмотренных проектов;\n 3)Выйти в меню администратора.\n");
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 3, newS);
	return a;
}

int ControlExp_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню управления экспертами:\n 1)Добавление эксперта;\n 2)Вывод таблицы со всеми экспертами в алфавитном порядке;\n 3)Редактирование данных эксперта;\n 4)Удаление эксперта;\n 5)Выйти в меню администратора.\n");
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 5, newS);
	return a;
}

int ControlInvObj_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню управления инвестиционными объектами:\n 1)Вывод таблицы со всеми свободными инвестиционными объектами в алфавитном порядке;\n 2)Редактирование данных инвестиционного объекта;\n 3)Удаление инвестиционного объекта;\n 4)Выйти в меню администратора.\n");
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 4, newS);
	return a;
}

int Client_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню клиента:\n 1)Редактирование данных;\n 2)Внос денежных средств;\n 3)Просмотр инвестиционного портфеля;\n 4)Разрыв договора с инвестиционной компанией;\n 5)Выйти в главное меню.\n ");
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 5, newS);
	return a;
}

int Expert_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню эксперта:\n 1)Редактирование данных;\n 2)Выбор незавершенного проекта;\n 3)Выйти в главное меню.\n ");
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 3, newS);
	return a;
}

int WorkDataCl_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню работы с данными:\n 1)Фильтрация относительно ден.суммы вложения;\n 2)Сортировка относительно денежной суммы вложения(от max);\n 3)Выйти в главное меню.\n ");
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 3, newS);
	return a;
}

int EditClient_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню редактирования:\n 1)Фамилия;\n 2)Имя;\n 3)Отчество;\n 4)Номер мобильного телефона;\n 5)Email;\n 6)Расчетный счет;\n 7)УНП;\n 8)Выйти в меню управления клиентами.\n ");
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 8, newS);
	return a;
}

void FileReadClients(list<Client>& clnts, void* newS) {
	Client c;
	char str[500];
	float a;
	ifstream f("Clients.txt", ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	if (f.peek() == EOF) {
		cout << "Файл пуст." << endl;
		return;
	}
	ifstream f1("ClientsPassw.txt", ios_base::in);
	if (!f1.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	if (f1.peek() == EOF) {
		cout << "Файл пуст." << endl;
		return;
	}
	while (1) {
		f.getline(str, 100, ';');
		if (strcmp(str, "***") == 0) {
			break;
		}
		c.SetSurname(str);
		f.getline(str, 100, ';');
		c.SetName(str);
		f.getline(str, 100, ';');
		c.SetPatronymic(str);
		f.getline(str, 100, ';');
		c.SetID(str);
		f.getline(str, 100, ';');
		c.SetEmail(str);
		f.getline(str, 100, ';');
		c.SetPhone(str);
		f.getline(str, 100, ';');
		a = stof(str);
		c.SetAccount(a);
		f.getline(str, 100, ';');
		c.SetPaym_Acc(str);
		f.getline(str, 100, ';');
		c.SetTRN(str);
		f1.getline(str, 100, ';');
		f1.getline(str, 100, ';');
		c.SetPassw(str);
		clnts.push_back(c);
	}
	f.close();
	f1.close();
}

void FileRecordClients(list<Client> clnts, void* newS) {
	int i = 1;
	char str[500];
	//list<Client>::iterator cl=clnts.begin();
	ofstream f("Clients.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (auto cl : clnts) {
		f << cl.GetSurname() << ";" << cl.GetName() << ";" << cl.GetPatronymic() << ";" << cl.GetID() << ";" << cl.GetEmail() << ";" << cl.GetPhone() << ";" << cl.GetAccount() << ";" << cl.GetPaym_Acc() << ";" << cl.GetTRN() << ";";
	}
	f << "***;";
	f.close();
}

void FileRecordClientsPassw(list<Client> clnts, void* newS) {
	int i = 1;
	char str[500];
	//list<Client>::iterator cl=clnts.begin();
	ofstream f("ClientsPassw.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (auto cl : clnts) {
		f << cl.GetEmail() << ";" << cl.GetPassw() << ";";
	}
	f << "***;";
	f.close();
}

void FileRecordClientsTable(list<Client> clnts, void* newS,const char* path) {
	int i = 1;
	char FIO[90], str[500];
	ofstream f(path, ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f << right << setw(210) << setfill('-') << "" << endl;
	f << left << setfill(' ') << "|" << setw(3) << "№" << "| " << setw(8) << "ID" << "| " << setw(80) << "ФИО" << " | " << setw(40) << "Электронная почта" << " | " << setw(14) << "Моб.номер" << " | " << setw(20) << "Денежные средства" << " | " << "Расчетный счет" << " | " << left << setw(6) << "УНП" << "    |" << endl;
	f << right << setw(210) << setfill('-') << "" << endl;
	for (auto cl : clnts) {
		strcpy_s(FIO, cl.GetSurname());
		strcat_s(FIO, " ");
		strcat_s(FIO, cl.GetName());
		strcat_s(FIO, " ");
		strcat_s(FIO, cl.GetPatronymic());
		f << right << setfill(' ') << left << "|" << setw(3) << i << "| " << cl.GetID() << "  | " << setw(80) << FIO << " | " << setw(40) << cl.GetEmail() << " | " << setw(14) << cl.GetPhone() << " | " << setw(20) << cl.GetAccount() << " | " << setw(14) << cl.GetPaym_Acc() << " | " << setw(9) << cl.GetTRN() << " |" << endl;
		f << right << setw(210) << setfill('-') << "" << endl;
		i++;
	}
	f.close();
}

void FileRecordClientContract(Client clnt, void* newS) {
	char str[500], FIO[90], day[10], month[10];
	strcpy_s(FIO, clnt.GetID());
	strcat_s(FIO, "_contract.txt");
	ofstream f(FIO, ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	sprintf_s(str, "%hu", tm.wDay);
	if (strlen(str) == 1) {
		strcpy_s(day, "0");
		strcat_s(day, str);
	}
	else {
		strcpy_s(day, str);
	}
	sprintf_s(str, "%hu", tm.wMonth);
	if (strlen(str) == 1) {
		strcpy_s(month, "0");
		strcat_s(month, str);
	}
	else {
		strcpy_s(month, str);
	}
	f << setw(100) << setfill('-') << "" << endl;
	f << "|" << right << setw(63) << setfill(' ') << "ДОГОВОР ИНВЕСТИРОВАНИЯ" << setw(36) << setfill(' ') << "|" << endl;
	f << "|" << right << setw(99) << setfill(' ') << "|" << endl;
	f << "|" << right << setw(88) << setfill(' ') << day << "." << setw(2) << month << "." << tm.wYear << "  |" << endl;
	f << "|  " << left << setw(94) << "Инвестиционная компания InvestLab, именуемая в дальнейшем <Исполнитель>, с одной стороны, и" << "  |" << endl;
	f << "|  " << setw(96) << clnt.GetSurname() << "|" << endl;
	f << "|  " << setw(96) << clnt.GetName() << "|" << endl;
	strcpy_s(str, clnt.GetPatronymic());
	strcat_s(str, ",");
	f << "|  " << setw(96) << str << "|" << endl;
	f << "|  " << left << setw(94) << "именуемый в дальнейшем <Заказчик>, с другой стороны, именуемые в дальнейшем <Стороны>, заклю-" << "  |" << endl;
	f << "|  " << left << setw(94) << "чили настоящий Договор." << "  |" << endl;
	f << "|" << right << setw(99) << setfill(' ') << "|" << endl;
	f << "|  " << left << "Размер инвестиций по настоящему Договору составляет " << setw(22) << clnt.GetAccount() << " белорусских рублей." << "  |" << endl;
	f << "|  " << left << setw(94) << "Размер инвестиций может быть увеличен." << "  |" << endl;
	f << "|  " << left << setw(94) << "За выполнение Исполнителем работ по настоящему Договору Заказчик выплачивает Исполнителю воз-" << "  |" << endl;
	f << "|  " << left << setw(94) << "награждение в размере 15(пятнадцати) процентов от прибыли, получаемой Заказчиком от инвести-" << "  |" << endl;
	f << "|  " << left << setw(94) << "онного объекта." << "  |" << endl;
	f << "|" << right << setw(99) << setfill(' ') << "|" << endl;
	f << "|  " << left << setw(94) << "Исполнитель обязан:" << "  |" << endl;
	f << "|  " << left << setw(94) << "  Осуществить финансирование по настоящему Договору в полном объеме и в порядке, установленном" << "  |" << endl;
	f << "|  " << left << setw(94) << "настоящим Договором, а также выплачивать вознаграждение Заказчику в размере, порядке и на ус-" << "  |" << endl;
	f << "|  " << left << setw(94) << "ловиях, установленных настоящим Договором." << "  |" << endl;
	f << "|  " << left << setw(94) << "  Выполнить надлежащим образом иные свои обязательства, предусмотренные настоящим Договором." << "  |" << endl;
	f << "|  " << left << setw(94) << "Исполнитель имеет право:" << "  |" << endl;
	f << "|  " << left << setw(94) << "  Осуществлять контроль за соответствием объема и качества, выполняемых Подрядчиком работ по" << "  |" << endl;
	f << "|  " << left << setw(94) << "созданию результата инвестиционной деятельности." << "  |" << endl;
	f << "|  " << left << setw(94) << "  С согласия Заказчика передавать свои права и обязанности по настоящему Договору третьему ли-" << "  |" << endl;
	f << "|  " << left << setw(94) << "цу при условии принятия последним обязанностей, условий и обязательств по настоящему Договору." << "  |" << endl;
	f << "|  " << left << setw(94) << "Частичная и/или полная передача прав и обязанностей оформляется соответствующим договором." << "  |" << endl;
	f << "|" << right << setw(99) << setfill(' ') << "|" << endl;
	f << "|  " << left << setw(94) << "Заказчик обязан:" << "  |" << endl;
	f << "|  " << left << setw(94) << "  Передать Исполнителю необходимые документы (копии), имеющиеся у Заказчика, для государствен-" << "  |" << endl;
	f << "|  " << left << setw(94) << "ной регистрации права собственности на результат инвестиционной деятельности." << "  |" << endl;
	f << "|  " << left << setw(94) << "  Осуществить контроль за порядком и объемом направления инвестиций Исполнителем в соответст-" << "  |" << endl;
	f << "|  " << left << setw(94) << "вии с условиями настоящего Договора. Использовать средства, получаемые от Исполнителя, по це-" << "  |" << endl;
	f << "|  " << left << setw(94) << "левому назначению." << "  |" << endl;
	f << "|  " << left << setw(94) << "Заказчик имеет право:" << "  |" << endl;
	f << "|  " << left << setw(94) << "  Требовать от Исполнителя исполнения взятых на себя обязательств по настоящему Договору" << "  |" << endl;
	f << "|  " << left << setw(94) << "  С согласия Исполнителя передавать свои права и обязанности по настоящему Договору третьим" << "  |" << endl;
	f << "|  " << left << setw(94) << "лицам." << "  |" << endl;
	f << "|  " << left << setw(94) << "  Обеспечивать контроль за соответствием объема и качества выполняемых работ." << "  |" << endl;
	f << "|" << right << setw(99) << setfill(' ') << "|" << endl;
	f << "|" << right << setw(73) << setfill(' ') << "Юридические адреса и банковские реквизиты сторон" << setw(26) << setfill(' ') << "|" << endl;
	f << "|  " << left << setw(45) << "Исполнитель" << "    " << setw(45) << "Заказчик" << "  |" << endl;
	f << "|  " << left << "Номер телефона: " << setw(29) << "+375290009889" << "    " << "Номер телефона: " << setw(29) << clnt.GetPhone() << "  |" << endl;
	f << "|  " << left << "Электр. почта: " << setw(30) << "invest_lab01@gmail.com" << "    " << "Электр. почта: " << setw(30) << clnt.GetEmail() << "  |" << endl;
	f << "|  " << left << "Расчетный счет: " << setw(29) << "1258458145214521" << "    " << "Расчетный счет: " << setw(29) << clnt.GetPaym_Acc() << "  |" << endl;
	f << "|  " << left << "УНП: " << setw(40) << "258147369" << "    " << "УНП: " << setw(40) << clnt.GetTRN() << "  |" << endl;
	f << "|" << right << setw(99) << setfill(' ') << "|" << endl;
	strcpy_s(FIO, clnt.GetSurname());
	strcat_s(FIO, " ");
	strcpy_s(str, clnt.GetName());
	strcat_s(FIO, &str[0]);
	strcat_s(FIO, ".");
	strcpy_s(str, clnt.GetName());
	strcat_s(FIO, &str[0]);
	strcat_s(FIO, ".");
	f << "|  " << left << setw(45) << "Инвестиционная компания InvestLab" << "    " << setw(45) << FIO << "  |" << endl;
	f << "|" << right << setw(99) << setfill(' ') << "|" << endl;
	f << setw(100) << setfill('-') << "" << endl;
	f.close();
}

void FileReadTable(void* newS,const char* path) {
	char str[500];
	ifstream f(path, ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	if (f.peek() == EOF) {
		cout << "Файл пуст." << endl;
		strcpy_s(str, "FileEmpty");
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	while (!f.eof()) //Будем читать информацию пока не дойдем до конца файла
	{
		str[0] = '/0';
		f.getline(str, 256, '\n'); //Построчное считывание информации в S 
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	strcpy_s(str, "EndOfFile");
	send((SOCKET)newS, str, sizeof(str), 0);
	f.close();
}
 
list<Client>::iterator FindClient(list<Client>& clnts, void* newS) {
	char str[500], FIO[90];
	list<Client>::iterator cl;
	strcpy_s(str, "Введите ФИО клиента: ");
	send((SOCKET)newS, str, sizeof(str), 0);
	str[0] = '/0';
	strcpy_s(str, СheckRus(1, newS));
	for (cl = clnts.begin(); cl != clnts.end(); cl++) {
		FIO[0] = '/0';
		strcpy_s(FIO, cl->GetSurname());
		strcat_s(FIO, " ");
		strcat_s(FIO, cl->GetName());
		strcat_s(FIO, " ");
		strcat_s(FIO, cl->GetPatronymic());
		if (strcmp(str, FIO) == 0) {
			break;
		}
	}
	return cl;
}

void FileReadClientContract(list<Client>& clnts, void* newS) {   //почему только с амперсандом выполняется возвращение итератора?????
	list<Client>::iterator cl = FindClient(clnts, newS);
	char str[500];
	int a;
	if (cl == clnts.end()) {
		strcpy_s(str, "Данный клиент не зарегистрирован в базе.");
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		str[0] = '\0';
		strcpy_s(str, "Данный клиент зарегистрирован в базе.");
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	strcpy_s(str, cl->GetID());
	strcat_s(str, "_contract.txt");
	ifstream f(str, ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	if (f.peek() == EOF) {
		cout << "Файл пуст." << endl;
		strcpy_s(str, "FileEmpty");
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	while (!f.eof()) //Будем читать информацию пока не дойдем до конца файла
	{
		str[0] = '/0';
		f.getline(str, 256, '\n'); //Построчное считывание информации в S 
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	strcpy_s(str, "EndOfFile");
	send((SOCKET)newS, str, sizeof(str), 0);
	f.close();
}

void AddNewClient(void* newS, list<Client>& clnts) {   //почему больше 12 символов не записывает??????
	Client obj;
	char p[500], flag[500];
	float f;
	strcpy_s(p, "Введите данные для заключения договора с клиентом.\nВведите ФИО клиента.\nФамилия: ");
	send((SOCKET)newS, p, sizeof(p), 0);
	strcpy_s(p, СheckRus(1, newS));
	obj.SetSurname(p);
	strcpy_s(p, "Имя: ");
	send((SOCKET)newS, p, sizeof(p), 0);
	strcpy_s(p, СheckRus(1, newS));
	obj.SetName(p);
	strcpy_s(p, "Отчество: ");
	send((SOCKET)newS, p, sizeof(p), 0);
	strcpy_s(p, СheckRus(0, newS));
	obj.SetPatronymic(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Введите индивидульный номер клиента: ");
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, СheckNumb(6, newS));
		if (clnts.size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetID(), p) == 0) {
					strcpy_s(flag, "Такой id уже существует. Повторите попытку.");
				}
			}
		}
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetID(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Email: ");
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, Check_Mail(newS));
		if (clnts.size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetEmail(), p) == 0) {
					strcpy_s(flag, "Такой email уже существует. Повторите попытку.");
				}
			}
		}
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetEmail(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Номер мобильного телефона: ");
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, Check_PhoneNum(newS));
		if (clnts.size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetPhone(), p) == 0) {
					strcpy_s(flag, "Такой номер мобильного телефона уже существует. Повторите попытку.");
				}
			}
		}
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetPhone(p);
	strcpy_s(p, "Стартовая сумма вложения: ");
	send((SOCKET)newS, p, sizeof(p), 0);
	f = CheckFloat(newS);
	obj.SetAccount(f);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Расчетный счет: ");
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, СheckNumb(12, newS));
		if (clnts.size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetPaym_Acc(), p) == 0) {
					strcpy_s(flag, "Такой расчетный счет уже существует. Повторите попытку.");
				}
			}
		}
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetPaym_Acc(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Учетный номер налогоплательщика: ");
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, СheckNumb(9, newS));
		if (clnts.size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetTRN(), p) == 0) {
					strcpy_s(flag, "Такой УНП уже существует. Повторите попытку.");
				}
			}
		}
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetTRN(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Новый пароль для клиента: ");
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, Check_Password(newS, 15));
		if (clnts.size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetTRN(), p) == 0) {
					strcpy_s(flag, "Такой пароль уже существует. Повторите попытку.");
				}
			}
		}
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetPassw(p);
	clnts.push_back(obj);
	clnts.sort();
	FileRecordClients(clnts, newS);
	FileRecordClientsTable(clnts, newS, "ClientsTable.txt");
	FileRecordClientContract(obj, newS);
	FileRecordClientsPassw(clnts, newS);
}

void WorkDataClient(list<Client> clnts, void* newS) {
	int m;
	float a1, a2;
	char str[500];
	list<Client> c;
	list<Client>::iterator c1,c2;
	Client obj;
	while (1) {
		m = WorkDataCl_Menu(newS);
		switch (m) {
		case 1: {
			strcpy_s(str, "1");
			send((SOCKET)newS, str, sizeof(str), 0);
			c1 = c.begin();
			strcpy_s(str, "Введите нижную границу значения суммы вложения: ");
			send((SOCKET)newS, str, sizeof(str), 0);
			a1=CheckFloat(newS);
			strcpy_s(str, "Введите верхнюю границу значения суммы вложения: ");
			send((SOCKET)newS, str, sizeof(str), 0);
			a2 = CheckFloat(newS);
			for (auto cl : clnts) {
				if (cl.GetAccount() > a1 && cl.GetAccount() < a2) {
					c.insert(c1,cl);	
				}
			}
			c.sort();
			FileRecordClientsTable(c, newS, "WorkDataCl.txt");
			FileReadTable(newS, "WorkDataCl.txt");
			c.clear();
			break;
		}
		case 2: {
			strcpy_s(str, "2");
			send((SOCKET)newS, str, sizeof(str), 0);
			
			break;
		}
		case 3: {
			strcpy_s(str, "3");
			send((SOCKET)newS, str, sizeof(str), 0);
			
			return;
		}
		}
	}
	
} //доделать сортировку

void main_working(void* newS) {
	list<Client> clnts;
	list<Client>::iterator cl;
	list<Expert> exprt;
	list<Expert>::iterator exp;
	list<InvestObject> invst_objct;
	list<InvestObject>::iterator inv_obj;
	int c, c1 = 0, c2 = 0, c3 = 0;
	int flag = 0;
	char p[500], k[500], m[500];
	p[0] = '\0'; k[0] = '\0'; m[0] = '\0';
	cout << "Сервер начал свою работу." << endl;
	FileReadClients(clnts, newS);
	for (auto cl : clnts) {
		cout << "Passw   " << cl.GetPassw() << endl;
		cout << cl.GetSurname() << ";" << cl.GetName() << ";" << cl.GetPatronymic() << ";" << cl.GetEmail() << ";" << cl.GetPhone() << ";" << cl.GetAccount() << ";" << cl.GetPassw() << ";" << endl;
	}
	while (1) {
		c = Main_Menu(newS);
		switch (c) {
		case 1: {
			strcpy_s(p, "1");
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, "*ЗДЕСЬ БУДЕТ АВТОРИЗАЦИЯ*");
			send((SOCKET)newS, p, sizeof(p), 0);
			while (c1 != 5) {
				c1 = Admin_Menu(newS);
				switch (c1) {
				case 1: {
					strcpy_s(p, "1");
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 7) {
						c2 = ControlCl_Menu(newS);
						switch (c2) {
						case 1: {  //добавление нового клиента
							strcpy_s(p, "1");
							send((SOCKET)newS, p, sizeof(p), 0);
							AddNewClient(newS, clnts);
							break;
						}
						case 2: { //вывод на экран таблицы с клиентами
							strcpy_s(p, "2");
							send((SOCKET)newS, p, sizeof(p), 0);
							FileReadTable(newS, "ClientsTable.txt");
							break;
						}
						case 3: {
							strcpy_s(p, "3");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 4: { //редактирование данных
							strcpy_s(p, "4");
							send((SOCKET)newS, p, sizeof(p), 0);
							cl = FindClient(clnts, newS);
							if (cl == clnts.end()) {
								p[0] = '\0';
								strcpy_s(p, "Данный клиент не зарегистрирован в базе.");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
								break;
							}
							else {
								p[0] = '\0';
								strcpy_s(p, "Данный клиент зарегистрирован в базе.");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
							}
							while (c3 != 8) {
								clnts.sort();
								FileRecordClients(clnts, newS);
								FileRecordClientsTable(clnts, newS, "ClientsTable.txt");
								FileRecordClientsPassw(clnts, newS);
								c3 = EditClient_Menu(newS);
								switch (c3) {
								case 1: {
									strcpy_s(p, "1");
									send((SOCKET)newS, p, sizeof(p), 0);
									p[0] = '\0';
									strcpy_s(p, "Введите обновленную фамилию: ");
									send((SOCKET)newS, p, sizeof(p), 0);
									strcpy_s(p, СheckRus(1, newS));
									cl->SetSurname(p);
									break;
								}
								case 2: {
									strcpy_s(p, "2");
									send((SOCKET)newS, p, sizeof(p), 0);
									p[0] = '\0';
									strcpy_s(p, "Введите обновленное имя: ");
									send((SOCKET)newS, p, sizeof(p), 0);
									strcpy_s(p, СheckRus(1, newS));
									cl->SetSurname(p);
									break;
								}
								case 3: {
									strcpy_s(p, "3");
									send((SOCKET)newS, p, sizeof(p), 0);
									p[0] = '\0';
									strcpy_s(p, "Введите обновленное отчество: ");
									send((SOCKET)newS, p, sizeof(p), 0);
									strcpy_s(p, СheckRus(0, newS));
									cl->SetSurname(p);
									break;
								}
								case 4: {
									strcpy_s(p, "4");
									send((SOCKET)newS, p, sizeof(p), 0);
									p[0] = '\0';
									strcpy_s(m, "1");
									while (strcmp(m, "0") != 0) {
										strcpy_s(m, "0");
										strcpy_s(p, "Введите обновленный номер мобильного телефона: ");
										send((SOCKET)newS, p, sizeof(p), 0);
										strcpy_s(p, Check_PhoneNum(newS));
										if (clnts.size() != 0) {
											for (auto cl : clnts) {
												if (strcmp(cl.GetPhone(), p) == 0) {
													strcpy_s(m, "Такой номер мобильного телефона уже существует.");
												}
											}
										}
										m[strlen(m) + 1] = '\0';
										send((SOCKET)newS, m, sizeof(m), 0);
									}
									cl->SetPhone(p);
									break;
								}
								case 5: {
									strcpy_s(p, "5");
									send((SOCKET)newS, p, sizeof(p), 0);
									strcpy_s(m, "1");
									while (strcmp(m, "0") != 0) {
										strcpy_s(m, "0");
										p[0] = '\0';
										strcpy_s(p, "Введите обновленный email: ");
										send((SOCKET)newS, p, sizeof(p), 0);
										strcpy_s(p, Check_Mail(newS));
										if (clnts.size() != 0) {
											for (auto cl : clnts) {
												if (strcmp(cl.GetEmail(), p) == 0) {
													strcpy_s(m, "Такой email уже существует. Повторите попытку.");
												}
											}
										}
										send((SOCKET)newS, m, sizeof(m), 0);
									}
									cl->SetEmail(p);
									break;
								}
								case 6: {
									strcpy_s(p, "6");
									send((SOCKET)newS, p, sizeof(p), 0);
									strcpy_s(m, "1");
									while (strcmp(m, "0") != 0) {
										strcpy_s(m, "0");
										p[0] = '\0';
										strcpy_s(p, "Введите обновленный расчетный счет: ");
										send((SOCKET)newS, p, sizeof(p), 0);
										strcpy_s(p, СheckNumb(12, newS));
										if (clnts.size() != 0) {
											for (auto cl : clnts) {
												if (strcmp(cl.GetPaym_Acc(), p) == 0) {
													strcpy_s(m, "Такой расчетный счет уже существует. Повторите попытку.");
												}
											}
										}
										send((SOCKET)newS, m, sizeof(m), 0);
									}
									cl->SetPaym_Acc(p);
									break;
								}
								case 7: {
									strcpy_s(p, "7");
									send((SOCKET)newS, p, sizeof(p), 0);
									strcpy_s(m, "1");
									while (strcmp(m, "0") != 0) {
										strcpy_s(m, "0");
										p[0] = '\0';
										strcpy_s(p, "Введите обновленный учетный номер налогоплательщика: ");
										send((SOCKET)newS, p, sizeof(p), 0);
										strcpy_s(p, СheckNumb(9, newS));
										if (clnts.size() != 0) {
											for (auto cl : clnts) {
												if (strcmp(cl.GetTRN(), p) == 0) {
													strcpy_s(m, "Такой УНП уже существует. Повторите попытку.");
												}
											}
										}
										send((SOCKET)newS, m, sizeof(m), 0);
									}
									cl->SetTRN(p);
									break;
								}
								case 8: {
									strcpy_s(p, "8");
									send((SOCKET)newS, p, sizeof(p), 0);

									break;
								}
								}
							}
							c3 = 0;
							break;
						}
						case 5: { //вывод на экран контркта с определенным клиентом
							strcpy_s(p, "5");
							send((SOCKET)newS, p, sizeof(p), 0);
							FileReadClientContract(clnts, newS);
							break;
						}
						case 6: { //фильтрация и сортировка по денежной сумме вклада
							strcpy_s(p, "6");
							send((SOCKET)newS, p, sizeof(p), 0);
							WorkDataClient(clnts, newS);
							break;
						}
						case 7: {
							strcpy_s(p, "7");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						}
					}
					c2 = 0;
					break;
				}
				case 2: {
					strcpy_s(p, "2");
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 3) {
						c2 = MakeDecis_Menu(newS);
						switch (c2) {
						case 1: {
							strcpy_s(p, "1");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 2: {
							strcpy_s(p, "2");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 3: {
							strcpy_s(p, "3");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						}
					}
					c2 = 0;
					break;
				}
				case 3: {
					strcpy_s(p, "3");
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 5) {
						c2 = ControlExp_Menu(newS);
						switch (c2) {
						case 1: {
							strcpy_s(p, "1");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 2: {
							strcpy_s(p, "2");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 3: {
							strcpy_s(p, "3");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 4: {
							strcpy_s(p, "4");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 5: {
							strcpy_s(p, "5");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						}
					}
					c2 = 0;
					break;
				}
				case 4: {
					strcpy_s(p, "4");
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 4) {
						c2 = ControlInvObj_Menu(newS);
						switch (c2) {
						case 1: {
							strcpy_s(p, "1");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 2: {
							strcpy_s(p, "2");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 3: {
							strcpy_s(p, "3");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 4: {
							strcpy_s(p, "4");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						}
					}
					c2 = 0;
					break;
				}
				case 5: {
					strcpy_s(p, "5");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				}
			}
			c1 = 0;
			break;
		}
		case 2: {
			strcpy_s(p, "2");
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "*ЗДЕСЬ БУДЕТ АВТОРИЗАЦИЯ*");
			send((SOCKET)newS, p, sizeof(p), 0);
			while (c1 != 5) {
				c1 = Client_Menu(newS);
				switch (c1) {
				case 1: {
					strcpy_s(p, "1");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				case 2: {
					strcpy_s(p, "2");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				case 3: {
					strcpy_s(p, "3");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				case 4: {
					strcpy_s(p, "4");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				case 5: {
					strcpy_s(p, "5");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				}
			}
			c1 = 0;
			break;
		}
		case 3: {
			strcpy_s(p, "3");
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(k, "*Здесь будет регистрация инвестиционного объекта его представителем*\n ");
			send((SOCKET)newS, k, sizeof(k), 0);
			break;
		}
		case 4: {
			strcpy_s(p, "4");
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "*ЗДЕСЬ БУДЕТ АВТОРИЗАЦИЯ*");
			send((SOCKET)newS, p, sizeof(p), 0);
			while (c1 != 3) {
				c1 = Expert_Menu(newS);
				switch (c1) {
				case 1: {
					strcpy_s(p, "1");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				case 2: {
					strcpy_s(p, "2");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				case 3: {
					strcpy_s(p, "3");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				}
			}
			c1 = 0;
			break;
		}
		case 5: {
			strcpy_s(p, "5");
			send((SOCKET)newS, p, sizeof(p), 0);
			closesocket((SOCKET)newS);
			exit(EXIT_SUCCESS);
			break;
		}
		}

		///(c = recv((SOCKET)newS, p, sizeof(p), 0) != 0)
	}

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
		return -1;
	sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(1280);
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	int c = bind(s, (struct sockaddr*)&local, sizeof(local));
	int r = listen(s, 5);
	while (true) {
		sockaddr_in remote;
		int j = sizeof(remote);
		SOCKET newS = accept(s, (struct sockaddr*)&remote, &j);
		_beginthread(main_working, 0, (void*)newS);  //создание потока(Начальный адрес процедуры, который начинает выполнение нового потока; размер стека нового потока или 0; список аргументов, передаваемый в новый поток, или NULL)
	}
	WSACleanup();
	return 0;
}