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
	char id[10];
	char email[90];
	char phone[15];
	char passw[20];
	char trn[11]; //УНП
	
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
	void SetID(const char* a) {
		strcpy_s(id, a);
	}
	char* GetID() {
		return id;
	}
	void SetPassw(const char* p) {
		strcpy_s(passw, p);
	}
	char* GetPassw() {
		return passw;
	}
	Company() {
		strcpy_s(email, "-");
		strcpy_s(phone, "-");
		strcpy_s(trn, "-");
		strcpy_s(id, "-");
		strcpy_s(passw, "-");
	}
};

class InvestObject :public Company {
	char inv_obj[50];
	char owner[90];
	int profitability;
	int payback_period;
	char product[90];
public:
	InvestObject() {
		strcpy_s(inv_obj, "-");
		strcpy_s(owner, "-");
		strcpy_s(product, "-");
		profitability = 0;
		payback_period = 0;
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
	void SetProduct(const char* pr) {
		strcpy_s(product, pr);
	}
	char* GetProduct() {
		return product;
	}
	void SetProfitability(int pr) {
		profitability = pr;
	}
	int GetProfitability() {
		return profitability;
	}
	void SetPayback_period(int pp) {
		payback_period = pp;
	}
	int GetPayback_period() {
		return payback_period;
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
	char* GetSurname() {
		return surname;
	}
	char* GetName() {
		return name;
	}
	char* GetPatronymic() {
		return patronymic;
	}
	People() {
		strcpy_s(surname, "-");
		strcpy_s(name, "-");
		strcpy_s(patronymic, "-");
	}
};

class Client :public People {
	
	float account;
	char paym_acc[15];  //расчетный счет
public:
	list<InvestObject> inv_portfolio;
	Client() {
		account = 0;
		strcpy_s(paym_acc, "-");
	}
	void SetAccount(float a) {
		account = a;
	}
	float GetAccount() {
		return account;
	}
	void SetPaym_Acc(const char* pm) {
		strcpy_s(paym_acc, pm);
	}
	char* GetPaym_Acc() {
		return paym_acc;
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
	char position[40];
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
	char* GetPosition() {
		return position;
	}
	void SetPosition(const char* pos) {
		strcpy_s(position, pos);
	}
	char* GetBirthday() {
		return birthday;
	}
	void SetBirthday(const char* b) {
		strcpy_s(birthday, b);
	}
	double GetSalary() {
		return salary;
	}
	void SetSalary(double s) {
		salary = s;
	}
	int GetExperience() {
		return experience;
	}
	void SetExperience(int exp) {
		experience = exp;
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

template <class T>
class Mail {
private:
	T message;
	char FIO[50];
	char id[10];
	char details[10];
	char decision[10];
public:
	Mail() {
		//message = 0;
		strcpy_s(FIO, "-");
		strcpy_s(id, "-");
		strcpy_s(details, "-");
		strcpy_s(decision, "-");
	}
	void SetMessage(T m) {
		message=m;
	}
	void SetFIO(const char*f) {
		strcpy_s(FIO, f);
	}
	void SetID(const char* i) {
		strcpy_s(id, i);
	}
	T GetMessage() {
		return message;
	}
	char* GetFIO() {
		return FIO;
	}
	char* GetID() {
		return id;
	}
	void SetDetails(const char* d) {
		strcpy_s(details, d);
	}
	char* GetDetails() {
		return details;
	}
	void SetDecision(const char* d) {
		strcpy_s(decision, d);
	}
	char* GetDecision() {
		return decision;
	}
	template <class T>
	friend bool operator<(const Mail<T>& o1, const Mail<T>& o2);
	template <class T>
	friend bool operator>(const Mail<T>& o1, const Mail<T>& o2);
	template <class T>
	friend bool operator==(const Mail<T>& o1, const Mail<T>& o2);
	template <class T>
	friend bool operator!=(const Mail<T>& o1, const Mail<T>& o2);
};

template <class T>
bool operator<(const Mail<T>& o1, const Mail<T>& o2) {
	return strcmp(o1.FIO, o2.FIO) < 0;
}
template <class T>
bool operator>(const Mail<T>& o1, const Mail<T>& o2) {
	return strcmp(o1.FIO, o2.FIO) > 0;
}
template <class T>
bool operator==(const Mail<T>& o1, const Mail<T>& o2) {
	return strcmp(o1.FIO, o2.FIO) == 0;
}
template <class T>
bool operator!=(const Mail<T>& o1, const Mail<T>& o2) {
	return strcmp(o1.FIO, o2.FIO) != 0;
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
			if (str[i] == (32) || str[i] == (45))
			{
				flag++;
			}
			if (f==1&& str[i] == (46))
			{
				flag++;
			}
			if (flag == l)
			{
				i = k;
			}
		}
		if (flag !=k||k==0)
		{
			flag = 0;
			err = 1;
			k = 1;
			_itoa_s(err, er, 10);
			er[strlen(er) + 1] = '\0';
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	err = 0;
	_itoa_s(err, er, 10);
	er[strlen(er) + 1] = '\0';
	send((SOCKET)newS, er, sizeof(er), 0);
	return str;
}

char* СheckInvObj( void* newS) {   //проверка на название инвестиционного объекта или его владельца
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
			if (str[i] == (32)|| str[i] == (45) || str[i] == (38) || str[i] == (34)|| str[i] == (46))
			{
				flag++;
			}
			if ((str[i] >= (65)) && (str[i] <= (90)))
			{
				flag++;
			}
			if ((str[i] >= (97)) && (str[i] <= (122)))
			{
				flag++;
			}
			if (flag == l)
			{
				i = k;
			}
		}
		if (flag != k || k == 0)
		{
			flag = 0;
			k = 1;
			err = 1;
			_itoa_s(err, er, 10);
			er[strlen(er) + 1] = '\0';
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	err = 0;
	_itoa_s(err, er, 10);
	er[strlen(er) + 1] = '\0';
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
		if (flag != k || k == 0)
		{
			k = 0;
			flag = 0;
			err = 1;
			_itoa_s(err, er, 10);
			er[strlen(er) + 1] = '\0';
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	err = 0;
	_itoa_s(err, er, 10);
	er[strlen(er) + 1] = '\0';
	send((SOCKET)newS, er, sizeof(er), 0);
	return str;
}

int* CheckDecisionNum(int size, void* newS) {
	int* mass = new int[size];
	int num, flag = 0, k = 0, err = 0, q = 0;
	char str[500], er[500];
	for (int i = 0; i < size; i++) {
		while (1) {
			flag = 0; k = 0;
			str[0] = '\0';
			recv((SOCKET)newS, str, sizeof(str), 0);
			str[strlen(str) + 1] = '\0';
			k = strlen(str);
			for (int j = 0; j < k; j++) {
				if ((str[j] >= (49)) && (str[j] <= (57)))
				{
					flag++;
				}
			}
			if (flag != k || k == 0) {
				flag = 0; k = 0;
				err = 1;
				_itoa_s(err, er, 10);
				er[strlen(er) + 1] = '\0';
				send((SOCKET)newS, er, sizeof(er), 0);
				cin.clear();
				continue;
			}
			else {
				err = 0;
				_itoa_s(err, er, 10);
				er[strlen(er) + 1] = '\0';
				send((SOCKET)newS, er, sizeof(er), 0);
			}
			flag = 0;
			num = atoi(str);
			if (num > size) {
				err = 1;
				_itoa_s(err, er, 10);
				er[strlen(er) + 1] = '\0';
				send((SOCKET)newS, er, sizeof(er), 0);
				cin.clear();
				continue;
			}
			else {
				err = 0;
				_itoa_s(err, er, 10);
				er[strlen(er) + 1] = '\0';
				send((SOCKET)newS, er, sizeof(er), 0);
			}
			for (int p = 0; p < q; p++) {
				if (num == mass[p]) {
					flag++;
					p = q;
				}
			}
			if (flag != 0) {
				err = 1;
				_itoa_s(err, er, 10);
				er[strlen(er) + 1] = '\0';
				send((SOCKET)newS, er, sizeof(er), 0);
				cin.clear();
				continue;
			}
			else {
				err = 0;
				_itoa_s(err, er, 10);
				er[strlen(er) + 1] = '\0';
				send((SOCKET)newS, er, sizeof(er), 0);
				break;
			}
		}
		mass[i] = num;
		q++;
	}
	return mass;
}

char* Check_Date(int y1, int y2,void* newS) {   //проверка даты
	char str[500],er[500];
	int k = 1, flag = 0, i = 0, d = 0, m = 0, y = 0, t = 1,a;
	while (flag != k)
	{
		str[0] = '/0';
		recv((SOCKET)newS, str, sizeof(str), 0);
		str[strlen(str) + 1] = '\0';
		k = strlen(str);
		if (k == 10) {
			if ((str[2] == '.') && (str[5] == '.')) {
				flag = flag + 2;
			}
			m = atoi(&str[3]);
			if ((m > 0) && (m < 13)) {
				flag = flag + 2;
			}
			y = atoi(&str[6]);
			if (y >= y1 && y <= y2) {
				flag = flag + 4;
			}
			d = atoi(&str[0]);
			if (((y % 4 == 0) || ((y % 100 == 0) && (y % 400 == 0))) && m == 2) {
				if (d > 0 && d < 30) {
					flag = flag + 2;
				}
			}
			else if (m == 2) {
				if (d > 0 && d < 29) {
					flag = flag + 2;
				}
			}
			else {
				if ((m == 9) || (m == 4) || (m == 6) || (m == 11)) {
					if (d > 0 && d < 30) {
						flag = flag + 2;
					}
				}
				else
					if (d > 0 && d < 32) {
						flag = flag + 2;
					}
			}
		}
		if (flag != k || k != 10)
		{
			flag = 0;
			i = 0;
			a = 1;
			_itoa_s(a, er, 10);
			er[strlen(er) + 1] = '\0';
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	a = 0;
	_itoa_s(a, er, 10);
	er[strlen(er) + 1] = '\0';
	send((SOCKET)newS, er, sizeof(er), 0);
	return str;
}

float CheckFloat(void* newS) {
	float a;
	char m[500], er[225];
	int k = 1, flag = 0, dot,num;
	while (flag != k)
	{
		dot = 0;
		num = 0;
		m[0] = '/0';
		recv((SOCKET)newS, m, sizeof(m), 0);
		m[strlen(m) + 1] = '\0';
		k = strlen(m);
		for (int i = 0; i < k; i++)
		{
			int l = flag;
			if ((m[i] >= (48)) && (m[i] <= (57))&&dot==0)
			{
				flag++;
			}
			if ((m[i] >= (48)) && (m[i] <= (57)) && dot == 1&&num<2)
			{
				flag++;
				num++;
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
		if (flag != k ||k==0)
		{
			flag = 0;
			k = 1;
			a = 1;
			sprintf_s(er, "%.2f", a);
			er[strlen(er) + 1] = '\0';
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	a = 0;
	sprintf_s(er, "%.2f", a);
	er[strlen(er) + 1] = '\0';
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
		if (flag != k ||k==0)
		{
			flag = 0;
			k = 1;
			a = 1;
			_itoa_s(a, er, 10);
			er[strlen(er) + 1] = '\0';
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	a = 0;
	_itoa_s(a, er, 10);
	er[strlen(er) + 1] = '\0';
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
			er[strlen(er) + 1] = '\0';
			send((SOCKET)newS, er, sizeof(er), 0);
		}
		else {
			err = 0;
			_itoa_s(err, er, 10);
			er[strlen(er) + 1] = '\0';
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
		if (flag != k || k == 0)
		{
			k = 1;
			flag = 0;
			err = 1;
			_itoa_s(err, er, 10);
			er[strlen(er) + 1] = '\0';
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	err = 0;
	_itoa_s(err, er, 10);
	er[strlen(er) + 1] = '\0';
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
		if (flag != k || k == 0)
		{
			k = 1;
			flag = 0;
			err = 1;
			_itoa_s(err, er, 10);
			er[strlen(er) + 1] = '\0';
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	err = 0;
	_itoa_s(err, er, 10);
	er[strlen(er) + 1] = '\0';
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
		if (flag != k || k == 0)
		{
			k = 1;
			flag = 0;
			err = 1;
			_itoa_s(err, er, 10);
			er[strlen(er) + 1] = '\0';
			send((SOCKET)newS, er, sizeof(er), 0);
			cin.clear();
		}
	}
	err = 0;
	_itoa_s(err, er, 10);
	er[strlen(er) + 1] = '\0';
	send((SOCKET)newS, er, sizeof(er), 0);
	return str;
}

int Main_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Добро пожаловать в InvestLab!\nМеню:\n 1)Войти в качестве администратора;\n 2)Войти в качестве клиента;\n 3)Войти в качестве представителя инвестиционного объекта;\n 4)Войти в качестве эксперта;\n 5)Завершить работу программы.\n ");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 5, newS);
	return a;
}

int Admin_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню администратора:\n 1)Управление клиентами;\n 2)Принятие решения;\n 3)Управление экспертами;\n 4)Управление инвестиционными объектами;\n 5)Выйти в главное меню.\n ");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 5, newS);
	return a;
}

int ControlCl_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню управления клиентами:\n 1)Добавление нового клиента;\n 2)Вывод таблицы со всеми клиентами в алфавитном порядке;\n 3)Редактирование данных клиента;\n 4)Вывод договора клиента;\n 5)Фильтрация и сортировка данных;\n 6)Просмотр инвестиционного портфеля клиента;\n 7)Просмотр почты;\n 8)Выйти в меню администратора.\n");
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 8, newS);
	return a;
}

int MakeDecis_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню принятия решения:\n 1)Вывести результаты последнего принятого решения;\n 2)Создать проект;\n 3)Выйти в меню администратора.\n");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 3, newS);
	return a;
}

int ControlExp_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню управления экспертами:\n 1)Добавление эксперта;\n 2)Вывод таблицы со всеми экспертами в алфавитном порядке;\n 3)Редактирование данных эксперта;\n 4)Удаление эксперта;\n 5)Просмотр почты;\n 6)Выйти в меню администратора.\n");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 6, newS);
	return a;
}

int ControlInvObj_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню управления инвестиционными объектами:\n 1)Вывод таблицы со всеми свободными инвестиционными объектами в алфавитном порядке;\n 2)Редактирование данных инвестиционного объекта;\n 3)Удаление инвестиционного объекта;\n 4)Выйти в меню администратора.\n");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 4, newS);
	return a;
}

int Client_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню клиента:\n 1)Редактирование данных;\n 2)Внос денежных средств;\n 3)Просмотр инвестиционного портфеля;\n 4)Отправить запрос на расторжение договора;\n 5)Просмотр договора;\n 6)Просмотр почты;\n 7)Просмотр суммы на счету;\n 8)Выйти в главное меню.\n ");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 8, newS);
	return a;
}

int Expert_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню эксперта:\n 1)Редактирование данных;\n 2)Оценить перспективы всех инвестиционных объектов для выбранного в проекте клиента;\n 3)Отправить запрос;\n 4)Просмотреть почту;\n 5)Выйти в главное меню.\n ");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 5, newS);
	return a;
}

int WorkDataCl_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню работы с данными:\n 1)Фильтрация относительно ден.суммы вложения;\n 2)Сортировка относительно денежной суммы вложения(от max);\n 3)Выйти в главное меню.\n ");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 3, newS);
	return a;
}

int EditClientAdmin_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню редактирования:\n 1)Фамилия;\n 2)Имя;\n 3)Отчество;\n 4)Номер мобильного телефона;\n 5)Email;\n 6)Расчетный счет;\n 7)УНП;\n 8)Выйти в меню управления клиентами.\n ");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 8, newS);
	return a;
}

int EditExpertAdmin_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню редактирования:\n 1)Фамилия;\n 2)Имя;\n 3)Отчество;\n 4)Номер мобильного телефона;\n 5)Email;\n 6)Должность;\n 7)УНП;\n 8)Заработная плата;\n 9)Дата рождения;\n 10)Стаж;\n 11)Выйти в меню управления экспертами.\n ");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 11, newS);
	return a;
}

int EditClient_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню редактирования:\n 1)Фамилия;\n 2)Имя;\n 3)Отчество;\n 4)Номер мобильного телефона;\n 5)Email;\n 6)Расчетный счет;\n 7)УНП;\n 8)Пароль;\n 9)Выйти в меню управления клиентами.\n ");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 9, newS);
	return a;
}

int EditExpert_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню редактирования:\n 1)Фамилия;\n 2)Имя;\n 3)Отчество;\n 4)Номер мобильного телефона;\n 5)Email;\n 6)УНП;\n 7)Дата рождения;\n 8)Стаж;\n 9)Пароль;\n 10)Выйти в меню управления экспертами.\n ");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 10, newS);
	return a;
}

int EditInvObj_Menu(void* newS) {
	int a;
	char k[500];
	strcpy_s(k, "Меню редактирования:\n 1)Название;\n 2)Владелец;\n 3)Email;\n 4)Номер мобильного телефона;\n 5)УНП;\n 6)Сфера деятельности;\n 7)Период окупаемости;\n 8)Рентабельность;\n 9)Выйти в меню управления инвестиционными объектами.\n ");
	k[strlen(k) + 1] = '\0';
	send((SOCKET)newS, k, sizeof(k), 0);
	a = CheckInt(1, 9, newS);
	return a;
}

char* GetCompanyEmail(void* newS) {
	char str[500];
	ifstream f("CompanyInfo.txt", ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return 0;
	}
	else {
		strcpy_s(str, "FileGood1");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f.getline(str, 256, ';');
	f.getline(str, 256, ';');
	f.close();
	return str;
}

char* GetCompanyPassword(void* newS) {
	char str[500];
	ifstream f("CompanyInfo.txt", ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return 0;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f.getline(str, 256, ';');
	f.close();
	return str;
}

char* GetCompanyPhone(void* newS) {
	char str[500];
	ifstream f("CompanyInfo.txt", ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return 0;
	}
	else {
		strcpy_s(str, "FileGood3");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (int i = 0; i < 3; i++) {
		f.getline(str, 256, ';');
	}
	f.close();
	return str;
}

char* GetCompanyPaym_Acc(void* newS) {
	char str[500];
	ifstream f("CompanyInfo.txt", ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return 0;
	}
	else {
		strcpy_s(str, "FileGood4");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (int i = 0; i <4 ; i++) {
		f.getline(str, 256, ';');
	}
	f.close();
	return str;
}

char* GetCompanyTRN(void* newS) {
	char str[500];
	ifstream f("CompanyInfo.txt", ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return 0;
	}
	else {
		strcpy_s(str, "FileGood5");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (int i = 0; i < 5; i++) {
		f.getline(str, 256, ';');
	}
	f.close();
	return str;
}

void FileReadClients(list<Client>& clnts, void* newS) {
	Client c;
	char str[500];
	float a;
	ifstream f("Clients.txt", ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	if (f.peek() == EOF) {
		cout << "Файл пуст." << endl;
		strcpy_s(str, "FileEmpty");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileNOTEmpty");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	ifstream f1("ClientsPassw.txt", ios_base::in);
	if (!f1.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
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
		clnts.sort();
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
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (auto cl : clnts) {
		f << cl.GetSurname() << ";" << cl.GetName() << ";" << cl.GetPatronymic() << ";" << cl.GetID() << ";" << cl.GetEmail() << ";" << cl.GetPhone() << ";" << cl.GetAccount() << ";" << cl.GetPaym_Acc() << ";" << cl.GetTRN() << ";";
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
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
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

void FileReadTable(void* newS,const char* path) {
	char str[500];
	ifstream f(path, ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	if (f.peek() == EOF) {
		cout << "Файл пуст." << endl;
		strcpy_s(str, "FileEmpty");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	while (!f.eof()) //Будем читать информацию пока не дойдем до конца файла
	{
		str[0] = '/0';
		f.getline(str, 256, '\n'); //Построчное считывание информации в S 
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	strcpy_s(str, "EndOfFile");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
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
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
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
	f << "|  " << left << "Номер телефона: " << setw(29) << GetCompanyPhone(newS) << "    " << "Номер телефона: " << setw(29) << clnt.GetPhone() << "  |" << endl;
	f << "|  " << left << "Электр. почта: " << setw(30) << GetCompanyEmail(newS) << "    " << "Электр. почта: " << setw(30) << clnt.GetEmail() << "  |" << endl;
	f << "|  " << left << "Расчетный счет: " << setw(29) << GetCompanyPaym_Acc(newS) << "    " << "Расчетный счет: " << setw(29) << clnt.GetPaym_Acc() << "  |" << endl;
	f << "|  " << left << "УНП: " << setw(40) << GetCompanyTRN(newS) << "    " << "УНП: " << setw(40) << clnt.GetTRN() << "  |" << endl;
	f << "|" << right << setw(99) << setfill(' ') << "|" << endl;
	strcpy_s(FIO, clnt.GetSurname());
	strcat_s(FIO, " ");
	strcat_s(FIO, clnt.GetName());
	strcat_s(FIO, " ");
	strcat_s(FIO, clnt.GetPatronymic());
	f << "|  " << left << setw(45) << "Инвестиционная компания InvestLab" << "    " << setw(45) << FIO << "  |" << endl;
	f << "|" << right << setw(99) << setfill(' ') << "|" << endl;
	f << setw(100) << setfill('-') << "" << endl;
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
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		str[0] = '\0';
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (auto cl : clnts) {
		f << cl.GetEmail() << ";" << cl.GetPassw() << ";";
	}
	f << "***;";
	f.close();
}
 
list<Client>::iterator FindClient(list<Client>& clnts, void* newS) {
	char str[500], FIO[90];
	list<Client>::iterator cl,c1=clnts.end();
	strcpy_s(str, "Введите ФИО клиента: ");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	str[0] = '/0';
	strcpy_s(str, СheckRus(0, newS));
	int i = 0;
	for (cl = clnts.begin(); cl != clnts.end(); cl++) {
		FIO[0] = '/0';
		strcpy_s(FIO, cl->GetSurname());
		strcat_s(FIO, " ");
		strcat_s(FIO, cl->GetName());
		strcat_s(FIO, " ");
		strcat_s(FIO, cl->GetPatronymic());
		if (strcmp(str, FIO) == 0) {
			c1 = cl;
			i++;
		}
	}
	if (i > 1) {
		strcpy_s(str, "Есть несколько клиентов с таким ФИО.\nПожалуйста, введите id нужного Вам клиента: ");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		str[0] = '/0';
		strcpy_s(str, СheckNumb(6, newS));
		for (cl = clnts.begin(); cl != clnts.end(); cl++) {
			if (strcmp(str, cl->GetID()) == 0) {
				c1 = cl;
				break;
			}
		}
	}
	else {
		strcpy_s(str, "Клиент найден.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	return c1;
}

list<Expert>::iterator FindExpert(list<Expert>& exprt, void* newS) {
	char str[500], FIO[90];
	list<Expert>::iterator cl, c1 = exprt.end();
	strcpy_s(str, "Введите ФИО эксперта: ");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	str[0] = '/0';
	strcpy_s(str, СheckRus(0, newS));
	int i = 0;
	for (cl = exprt.begin(); cl != exprt.end(); cl++) {
		FIO[0] = '/0';
		strcpy_s(FIO, cl->GetSurname());
		strcat_s(FIO, " ");
		strcat_s(FIO, cl->GetName());
		strcat_s(FIO, " ");
		strcat_s(FIO, cl->GetPatronymic());
		if (strcmp(str, FIO) == 0) {
			c1 = cl;
			i++;
		}
	}
	if (i > 1) {
		strcpy_s(str, "Есть несколько экспертов с таким ФИО.\nПожалуйста, введите id нужного Вам эксперта: ");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		str[0] = '/0';
		strcpy_s(str, СheckNumb(6, newS));
		for (cl = exprt.begin(); cl != exprt.end(); cl++) {
			if (strcmp(str, cl->GetID()) == 0) {
				c1 = cl;
				break;
			}
		}
	}
	else {
		strcpy_s(str, "Эксперт найден.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	return c1;
}

list<InvestObject>::iterator FindInvObj(list<InvestObject>& invobj, void* newS) {
	char str[500], name[90];
	list<InvestObject>::iterator cl, c1 = invobj.end();
	strcpy_s(str, "Введите название инвестиционного объекта: ");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	str[0] = '/0';
	strcpy_s(str, СheckInvObj(newS));
	int i = 0;
	for (cl = invobj.begin(); cl != invobj.end(); cl++) {
		name[0] = '/0';
		strcpy_s(name, cl->GetInv_obj());
		if (strcmp(str, name) == 0) {
			c1 = cl;
			i++;
		}
	}
	if (i > 1) {
		strcpy_s(str, "Есть несколько инвестиционных объектов с таким названием.\nПожалуйста, введите id нужного Вам инвестиционного объекта: ");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		str[0] = '/0';
		strcpy_s(str, СheckNumb(6, newS));
		for (cl = invobj.begin(); cl != invobj.end(); cl++) {
			if (strcmp(str, cl->GetID()) == 0) {
				c1 = cl;
				break;
			}
		}
	}
	else {
		strcpy_s(str, "Инвестиционный объект найден.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	return c1;
}

void FileReadClientContract(list<Client>& clnts, void* newS) {   //почему только с амперсандом выполняется возвращение итератора?????
	list<Client>::iterator cl;
	char str[500];
	int a;
	while (1) {
		str[0] = '\0';
		cl = FindClient(clnts, newS);
		if (clnts.size() == 0) {
			strcpy_s(str, "В базе не зарегистрирован ни один клиент.");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			return;
		}
		if (cl == clnts.end()) {
			strcpy_s(str, "Данный клиент не зарегистрирован в базе. Желаете ли Вы повторить ввод ФИО? Да(1) или нет(2).");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			a = CheckInt(1, 2, newS);
			if (a == 1) {
				continue;
			}
			return;
		}
		else {
			str[0] = '\0';
			strcpy_s(str, "Данный клиент зарегистрирован в базе.");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
		}
		strcpy_s(str, cl->GetID());
		strcat_s(str, "_contract.txt");
		ifstream f(str, ios_base::in);
		if (!f.is_open() || f.bad()) {
			cout << "Файл не удалось открыть." << endl;
			strcpy_s(str, "FileError");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			return;
		}
		if (f.peek() == EOF) {
			cout << "Файл пуст." << endl;
			strcpy_s(str, "FileEmpty");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			return;
		}
		while (!f.eof()) //Будем читать информацию пока не дойдем до конца файла
		{
			str[0] = '/0';
			f.getline(str, 256, '\n'); //Построчное считывание информации в S 
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
		}
		strcpy_s(str, "EndOfFile");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		f.close();
		break;
	}
}

void FileReadExperts(list<Expert>& exp, void* newS) {
	Expert e;
	char str[500];
	int a;
	float b;
	ifstream f("Experts.txt", ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	if (f.peek() == EOF) {
		cout << "Файл пуст." << endl;
		strcpy_s(str, "FileEmpty");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileNOTEmpty");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	ifstream f1("ExpertsPassw.txt", ios_base::in);
	if (!f1.is_open() || f1.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
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
		e.SetSurname(str);
		f.getline(str, 100, ';');
		e.SetName(str);
		f.getline(str, 100, ';');
		e.SetPatronymic(str);
		f.getline(str, 100, ';');
		e.SetBirthday(str);
		f.getline(str, 100, ';');
		e.SetID(str);
		f.getline(str, 100, ';');
		e.SetPosition(str);
		f.getline(str, 100, ';');
		b = stof(str);
		e.SetSalary(b);
		f.getline(str, 100, ';');
		a = atoi(str);
		e.SetExperience(a);
		f.getline(str, 100, ';');
		e.SetEmail(str);
		f.getline(str, 100, ';');
		e.SetPhone(str);
		f.getline(str, 100, ';');
		e.SetTRN(str);
		f1.getline(str, 100, ';');
		f1.getline(str, 100, ';');
		e.SetPassw(str);
		exp.push_back(e);
		exp.sort();
	}
	f.close();
	f1.close();
}

void FileRecordExperts(list<Expert> exp, void* newS) {
	char str[500];
	ofstream f("Experts.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (auto e : exp) {
		f << e.GetSurname() << ";" << e.GetName() << ";" << e.GetPatronymic() << ";" << e.GetBirthday() << ";" << e.GetID()  << ";" << e.GetPosition() << ";" << e.GetSalary() << ";" << e.GetExperience() << ";" <<e.GetEmail() << ";" <<e.GetPhone() << ";" <<e.GetTRN() << ";";
	}
	f << "***;";
	f.close();
}

void FileRecordExpertsPassw(list<Expert> exp, void* newS) {
	char str[500];
	ofstream f("ExpertsPassw.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (auto e : exp) {
		f << e.GetEmail() << ";" << e.GetPassw() << ";";
	}
	f << "***;";
	f.close();
}

void FileRecordExpertsTable(list<Expert>exp, void* newS) {
	char str[500],FIO[80];
	int i = 1;
	ofstream f("ExpertsTable.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f << right << setw(208) << setfill('-') << "" << endl;
	f << left << setfill(' ') << "|" << setw(3) << "№" << "| " << setw(7) << "ID" << "| " << setw(45) << "ФИО" << "| "  << "Дата рождения" << " | " << setw(35) << "Email" << "| " << setw(15) << "Моб.телефон" << "| " << setw(9) << "УНП" << " | " << left << setw(40) << "Должность" << "| Зараб.плата |  Стаж  |" << endl;
	f << right << setw(208) << setfill('-') << "" << endl;
	for (auto e : exp) {
		strcpy_s(FIO, e.GetSurname());
		strcat_s(FIO, " ");
		strcat_s(FIO, e.GetName());
		strcat_s(FIO, " ");
		strcat_s(FIO, e.GetPatronymic());
		f << setfill(' ') << left << "|" << setw(3) << i << "| " << e.GetID() << " | " << setw(45) << FIO << "| " << setw(13) << e.GetBirthday() << " | " << setw(35) << e.GetEmail() << "| " << setw(15) << e.GetPhone() << "| " << e.GetTRN() << " | " << setw(40) << e.GetPosition()<< "| " << setw(8) << e.GetSalary() << "byn" << " | " << setw(4) << e.GetExperience() << "г. | "<<endl;
		i++;
		f << right << setw(208) << setfill('-') << "" << endl;
	}
	f.close();
}
//важно
void FileReadInvestObjects(list<InvestObject>& invobj, const char* path, void* newS) {
	InvestObject io;
	char str[500];
	int a;
	ifstream f(path, ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	if (f.peek() == EOF) {
		strcpy_s(str, "В базе данных не зарегистрирован ни один инвестиционный объект.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	while (1) {
		f.getline(str, 100, ';');
		if (strcmp(str, "***") == 0) {
			break;
		}
		io.SetInv_Obj(str);
		f.getline(str, 100, ';');
		io.SetOwner(str);
		f.getline(str, 100, ';');
		io.SetID(str);
		f.getline(str, 100, ';');
		io.SetEmail(str);
		f.getline(str, 100, ';');
		io.SetPhone(str);
		f.getline(str, 100, ';');
		io.SetTRN(str);
		f.getline(str, 100, ';');
		io.SetProduct(str);
		f.getline(str, 100, ';');
		a = atoi(str);
		io.SetPayback_period(a);
		f.getline(str, 100, ';');
		a = atoi(str);
		io.SetProfitability(a);
		invobj.push_back(io);
		invobj.sort();
	}
	f.close();
}

void FileRecordInvestObjects(list<InvestObject> invobj, const char* path, void* newS) {
	char str[500];
	ofstream f(path, ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (auto io : invobj) {
		f << io.GetInv_obj() << ";" << io.GetOwner() << ";" << io.GetID() << ";" << io.GetEmail() << ";" << io.GetPhone() << ";" << io.GetTRN() << ";" << io.GetProduct() << ";" << io.GetPayback_period() << ";" << io.GetProfitability() << ";";
	}
	f << "***;";
	f.close();
}

void FileRecordTableInvestObjects(list<InvestObject> invobj, const char* path, void* newS) {
	char str[500];
	int i = 1;
	ofstream f(path, ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f << right << setw(210) << setfill('-') << "" << endl;
	f << left << setfill(' ') << "|" << setw(3) << "№" << "| " << setw(7) << "ID" << "| " << setw(31) << "Инвестиционный объект" << "| " << setw(30) << "Владелец" << "| " << setw(27) << "Email" << "|" << setw(13) << "Моб.телефон" << "|" << setw(9) << "УНП" << "|" << left << setw(45) << "Сфера" << "|Срок окупаемости|Рентабельность|" << endl;
	f << right << setw(210) << setfill('-') << "" << endl;
	for (auto io : invobj) {
		f << setfill(' ') << left << "|" << setw(3) << i << "| " << io.GetID() << " | " << setw(31) << io.GetInv_obj() << "| " << setw(30) << io.GetOwner() << "| " << setw(27) << io.GetEmail() << "|" << setw(13) << io.GetPhone() << "|" << io.GetTRN() << "|" << setw(45) << io.GetProduct() << "| " << setw(13) << io.GetPayback_period() << "г." << "| " << setw(11) << io.GetProfitability() << "% |"<<endl;
		i++;
		f << right << setw(210) << setfill('-') << "" << endl;
	}
	f.close();
}

void AddNewClient(void* newS, list<Client>& clnts) {   //почему больше 12 символов не записывает??????
	Client obj;
	char p[500], flag[500];
	float f;
	int i;
	strcpy_s(p, "Введите данные для заключения договора с клиентом.\nВведите ФИО клиента.\nФамилия: ");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	strcpy_s(p, СheckRus(0, newS));
	obj.SetSurname(p);
	strcpy_s(p, "Имя: ");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	strcpy_s(p, СheckRus(0, newS));
	obj.SetName(p);
	strcpy_s(p, "Отчество: ");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	strcpy_s(p, СheckRus(0, newS));
	obj.SetPatronymic(p);
	srand(time(0));
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		i = 100000 + rand() % 999999;
		_itoa_s(i, p, 10);;
		if (clnts .size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetID(), p) == 0) {
					strcpy_s(flag, "Такой id уже существует. Повторите попытку.");
				}
			}
		}
	}
	obj.SetID(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Email: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, Check_Mail(newS));
		if (clnts.size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetEmail(), p) == 0) {
					strcpy_s(flag, "Такой email уже существует. Повторите попытку.");
				}
			}
		}
		flag[strlen(flag) + 1] = '\0';
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetEmail(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Номер мобильного телефона: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, Check_PhoneNum(newS));
		if (clnts.size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetPhone(), p) == 0) {
					strcpy_s(flag, "Такой номер мобильного телефона уже существует. Повторите попытку.");
				}
			}
		}
		flag[strlen(flag) + 1] = '\0';
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetPhone(p);
	strcpy_s(p, "Стартовая сумма вложения: ");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	f = CheckFloat(newS);
	obj.SetAccount(f);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Расчетный счет: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, СheckNumb(12, newS));
		if (clnts.size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetPaym_Acc(), p) == 0) {
					strcpy_s(flag, "Такой расчетный счет уже существует. Повторите попытку.");
				}
			}
		}
		flag[strlen(flag) + 1] = '\0';
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetPaym_Acc(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Учетный номер налогоплательщика: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, СheckNumb(9, newS));
		if (clnts.size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetTRN(), p) == 0) {
					strcpy_s(flag, "Такой УНП уже существует. Повторите попытку.");
				}
			}
		}
		flag[strlen(flag) + 1] = '\0';
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetTRN(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Новый пароль для клиента: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, Check_Password(newS, 15));
		if (clnts.size() != 0) {
			for (auto cl : clnts) {
				if (strcmp(cl.GetPassw(), p) == 0) {
					strcpy_s(flag, "Такой пароль уже существует. Повторите попытку.");
				}
			}
		}
		flag[strlen(flag) + 1] = '\0';
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetPassw(p);
	clnts.push_back(obj);
	clnts.sort();
	FileRecordClients(clnts, newS);
	FileRecordClientsTable(clnts, newS, "ClientsTable.txt");
	FileRecordClientContract(obj, newS);
	FileRecordClientsPassw(clnts, newS);
	strcpy_s(p, obj.GetID());
	strcat_s(p, "_clientmail.txt");
	ofstream fl(p, ios_base::out);
	fl.close();
	strcpy_s(p, obj.GetID());
	strcat_s(p, "_portfoliotable.txt");
	ofstream f2(p, ios_base::out);
	f2.close();
	strcpy_s(p, obj.GetID());
	strcat_s(p, "_portfolio.txt");
	ofstream f3(p, ios_base::out);
	f3.close();
}

void AddNewExpert(void* newS, list<Expert>& exprts) {   //почему больше 12 символов не записывает??????
	Expert obj;
	char p[500], flag[500],mass[10];
	float f;
	int i,y,y1;
	if (exprts.size() == 3) {
		strcpy_s(p, "Уже имеется три эксперта. Добавление нового эксперта невозможно.");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
	}
	else {
		strcpy_s(p, "Добавление возможно.");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, "Введите данные для добавления в команду нового эксперта.\nВведите ФИО эксперта.\nФамилия: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, СheckRus(0, newS));
		obj.SetSurname(p);
		strcpy_s(p, "Имя: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, СheckRus(0, newS));
		obj.SetName(p);
		strcpy_s(p, "Отчество: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, СheckRus(0, newS));
		obj.SetPatronymic(p);
		SYSTEMTIME tm;
		GetLocalTime(&tm);
		strcpy_s(p, "Дата рождения: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		sprintf_s(p, "%hu", tm.wYear);
		y = atoi(p);
		strcpy_s(p, Check_Date(y - 100, y - 18, newS));
		obj.SetBirthday(p);
		srand(time(0));
		strcpy_s(flag, "1");
		while (strcmp(flag, "0") != 0) {
			strcpy_s(flag, "0");
			i = 100000 + rand() % 999999;
			_itoa_s(i, p, 10);;
			if (exprts.size() != 0) {
				for (auto ex : exprts) {
					if (strcmp(ex.GetID(), p) == 0) {
						strcpy_s(flag, "Такой id уже существует. Повторите попытку.");
					}
				}
			}
		}
		obj.SetID(p);
		strcpy_s(p, "Позиция в компании: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, СheckRus(0, newS));
		obj.SetPosition(p);
		strcpy_s(p, "Заработная плата: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		f = CheckFloat(newS);
		obj.SetSalary(f);
		strcpy_s(flag, "1");
		i = 0;
		while (strcmp(flag, "0") != 0) {
			strcpy_s(flag, "0");
			strcpy_s(p, "Стаж работы(количество лет): ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			i = CheckInt(newS);
			y1 = strlen(obj.GetBirthday());
			strcpy_s(mass, &obj.GetBirthday()[y1 - 4]);
			y1 = atoi(mass);
			if (!(y1 + 18 <= y - i)) {
				strcpy_s(flag, "Введенный стаж несоответствует возрасту. Повторите попытку.");
			}
			send((SOCKET)newS, flag, sizeof(flag), 0);
		}
		obj.SetExperience(i);
		strcpy_s(flag, "1");
		while (strcmp(flag, "0") != 0) {
			strcpy_s(flag, "0");
			strcpy_s(p, "Email: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, Check_Mail(newS));
			if (exprts.size() != 0) {
				for (auto exp : exprts) {
					if (strcmp(exp.GetEmail(), p) == 0) {
						strcpy_s(flag, "Такой email уже существует. Повторите попытку.");
					}
				}
			}
			flag[strlen(flag) + 1] = '\0';
			send((SOCKET)newS, flag, sizeof(flag), 0);
		}
		obj.SetEmail(p);
		strcpy_s(flag, "1");
		while (strcmp(flag, "0") != 0) {
			strcpy_s(flag, "0");
			strcpy_s(p, "Номер мобильного телефона: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, Check_PhoneNum(newS));
			if (exprts.size() != 0) {
				for (auto exp : exprts) {
					if (strcmp(exp.GetPhone(), p) == 0) {
						strcpy_s(flag, "Такой номер мобильного телефона уже существует. Повторите попытку.");
					}
				}
			}
			flag[strlen(flag) + 1] = '\0';
			send((SOCKET)newS, flag, sizeof(flag), 0);
		}
		obj.SetPhone(p);
		strcpy_s(flag, "1");
		while (strcmp(flag, "0") != 0) {
			strcpy_s(flag, "0");
			strcpy_s(p, "Учетный номер налогоплательщика: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckNumb(9, newS));
			if (exprts.size() != 0) {
				for (auto exp : exprts) {
					if (strcmp(exp.GetTRN(), p) == 0) {
						strcpy_s(flag, "Такой УНП уже существует. Повторите попытку.");
					}
				}
			}
			flag[strlen(flag) + 1] = '\0';
			send((SOCKET)newS, flag, sizeof(flag), 0);
		}
		obj.SetTRN(p);
		strcpy_s(flag, "1");
		while (strcmp(flag, "0") != 0) {
			strcpy_s(flag, "0");
			strcpy_s(p, "Новый пароль для эксперта: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, Check_Password(newS, 15));
			if (exprts.size() != 0) {
				for (auto exp : exprts) {
					if (strcmp(exp.GetTRN(), p) == 0) {
						strcpy_s(flag, "Такой пароль уже существует. Повторите попытку.");
					}
				}
			}
			flag[strlen(flag) + 1] = '\0';
			send((SOCKET)newS, flag, sizeof(flag), 0);
		}
		obj.SetPassw(p);
		exprts.push_back(obj);
		exprts.sort();
		FileRecordExperts(exprts, newS);
		FileRecordExpertsTable(exprts, newS);
		FileRecordExpertsPassw(exprts, newS);
		strcpy_s(p, obj.GetID());
		strcat_s(p, "_expertmail.txt");
		ofstream fl(p, ios_base::out);
		fl.close();
	}
}

void AddNewInvObj(void* newS, list<InvestObject>& invobj) {   //почему больше 12 символов не записывает??????
	InvestObject obj;
	char p[500], flag[500];
	int i;
	strcpy_s(p, "Добро пожаловать в инвестиционную компанию InvestLab.\nВведите данные инвестиционного объекта.\nВведите название инвестиционного объекта: ");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	strcpy_s(p, СheckInvObj(newS));
	obj.SetInv_Obj(p);
	strcpy_s(p, "Владелец: ");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	strcpy_s(p, СheckInvObj(newS));
	obj.SetOwner(p);
	srand(time(0));
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		i = 100000 + rand() % 999999;
		_itoa_s(i, p, 10);;
		if (invobj.size() != 0) {
			for (auto io : invobj) {
				if (strcmp(io.GetID(), p) == 0) {
					strcpy_s(flag, "Такой id уже существует. Повторите попытку.");
				}
			}
		}
	}
	obj.SetID(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Email: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, Check_Mail(newS));
		if (invobj.size() != 0) {
			for (auto io: invobj) {
				if (strcmp(io.GetEmail(), p) == 0) {
					strcpy_s(flag, "Такой email уже существует. Повторите попытку.");
				}
			}
		}
		flag[strlen(flag) + 1] = '\0';
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetEmail(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Номер мобильного телефона: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, Check_PhoneNum(newS));
		if (invobj.size() != 0) {
			for (auto io : invobj) {
				if (strcmp(io.GetPhone(), p) == 0) {
					strcpy_s(flag, "Такой номер мобильного телефона уже существует. Повторите попытку.");
				}
			}
		}
		flag[strlen(flag) + 1] = '\0';
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetPhone(p);
	strcpy_s(flag, "1");
	while (strcmp(flag, "0") != 0) {
		strcpy_s(flag, "0");
		strcpy_s(p, "Учетный номер налогоплательщика: ");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(p, СheckNumb(9, newS));
		if (invobj.size() != 0) {
			for (auto io : invobj) {
				if (strcmp(io.GetTRN(), p) == 0) {
					strcpy_s(flag, "Такой УНП уже существует. Повторите попытку.");
				}
			}
		}
		flag[strlen(flag) + 1] = '\0';
		send((SOCKET)newS, flag, sizeof(flag), 0);
	}
	obj.SetTRN(p);
	strcpy_s(p, "Сфера деятельности: ");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	strcpy_s(p, СheckInvObj(newS));
	obj.SetProduct(p);
	strcpy_s(p, "Период окупаемости(в годах): ");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	i = CheckInt(newS);
	obj.SetPayback_period(i);
	strcpy_s(p, "Процент рентабельности: ");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	i = CheckInt(0,100,newS);
	obj.SetProfitability(i);
	invobj.push_back(obj);
	invobj.sort();
	FileRecordInvestObjects(invobj,"InvObjFree.txt",newS);
	FileRecordTableInvestObjects(invobj, "InvObjFreeTable.txt", newS);
}

void WorkDataClient(list<Client> clnts, void* newS) {
	int m;
	float a1, a2;
	char str[500];
	list<Client> c;
	list<Client>::iterator c1,c2,c3;
	Client obj;
	if (clnts.size() == 0) {
		strcpy_s(str, "Клиентская база пуста.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "Клиентская база не пуста.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	while (1) {
		m = WorkDataCl_Menu(newS);
		switch (m) {
		case 1: {
			strcpy_s(str, "1");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			c1 = c.begin();
			strcpy_s(str, "Введите нижную границу значения суммы вложения: ");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			a1=CheckFloat(newS);
			strcpy_s(str, "Введите верхнюю границу значения суммы вложения: ");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			a2 = CheckFloat(newS);
			for (auto cl : clnts) {
				if (cl.GetAccount() >= a1 && cl.GetAccount() <= a2) {
					c.insert(c1,cl);	
				}
			}
			if (c.size() == 0) {
				strcpy_s(str, "Клиентов с суммой вложения в таком диапазоне нет.");
				str[strlen(str) + 1] = '\0';
				send((SOCKET)newS, str, sizeof(str), 0);
				break;
			}
			else {
				strcpy_s(str, "Клиенты с суммой вложения в таком диапазоне есть.");
				str[strlen(str) + 1] = '\0';
				send((SOCKET)newS, str, sizeof(str), 0);
			}
			c.sort();
			FileRecordClientsTable(c, newS, "WorkDataCl.txt");
			FileReadTable(newS, "WorkDataCl.txt");
			c.clear();
			break;
		}
		case 2: {
			strcpy_s(str, "2");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			list<Client> c_copy(clnts);
			c3 = c.begin();
			int i = c_copy.size();
			while (i!=0) {
				c1 = c_copy.begin();
				for (c2 = c_copy.begin(); c2 != c_copy.end(); c2++) {
					if (c1->GetAccount() < c2->GetAccount()) {
						c1=c2;
					}
				}
				obj.SetSurname(c1->GetSurname());
				obj.SetName(c1->GetName());
				obj.SetPatronymic(c1->GetPatronymic());
				obj.SetID(c1->GetID());
				obj.SetEmail(c1->GetEmail());
				obj.SetPhone(c1->GetPhone());
				obj.SetPaym_Acc(c1->GetPaym_Acc());
				obj.SetTRN(c1->GetTRN());
				obj.SetAccount(c1->GetAccount());
				c.push_back(obj);
				c_copy.erase(c1);
				i--;
			}
			FileRecordClientsTable(c, newS, "WorkDataCl.txt");
			FileReadTable(newS, "WorkDataCl.txt");
			c.clear();
			break;
		}
		case 3: {
			strcpy_s(str, "3");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			
			return;
		}
		}
	}
	
} 

void EditClientAdmin(void* newS, list<Client>& clnts) {
	int a = 0,c=0;
	list<Client>::iterator cl;
	char p[500], m[500];
	while (1) {
		cl = FindClient(clnts, newS);
		if (clnts.size() == 0) {
			strcpy_s(p, "В базе не зарегистрирован ни один клиент.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = 2;
			break;
		}
		else if (cl == clnts.end()) {
			p[0] = '\0';
			strcpy_s(p, "Данный клиент не зарегистрирован в базе. Желаете ли Вы повторить ввод ФИО? Да(1) или нет(2).");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = CheckInt(1, 2, newS);
			if (a == 1) {
				continue;
			}
			break;
		}
		else {
			p[0] = '\0';
			strcpy_s(p, "Данный клиент зарегистрирован в базе.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			break;
		}
	}
	if (a == 2) {
		return;
	}
	while (c != 8) {
		clnts.sort();
		FileRecordClients(clnts, newS);
		FileRecordClientsTable(clnts, newS, "ClientsTable.txt");
		FileRecordClientsPassw(clnts, newS);
		c = EditClientAdmin_Menu(newS);
		switch (c) {
		case 1: {
			strcpy_s(p, "1");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленную фамилию: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			cl->SetSurname(p);
			break;
		}
		case 2: {
			strcpy_s(p, "2");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленное имя: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			cl->SetName(p);
			break;
		}
		case 3: {
			strcpy_s(p, "3");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленное отчество: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			cl->SetPatronymic(p);
			break;
		}
		case 4: {
			strcpy_s(p, "4");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				strcpy_s(p, "Введите обновленный номер мобильного телефона: ");
				p[strlen(p) + 1] = '\0';
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
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный email: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, Check_Mail(newS));
				if (clnts.size() != 0) {
					for (auto cl : clnts) {
						if (strcmp(cl.GetEmail(), p) == 0) {
							strcpy_s(m, "Такой email уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			cl->SetEmail(p);
			break;
		}
		case 6: {
			strcpy_s(p, "6");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный расчетный счет: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, СheckNumb(12, newS));
				if (clnts.size() != 0) {
					for (auto cl : clnts) {
						if (strcmp(cl.GetPaym_Acc(), p) == 0) {
							strcpy_s(m, "Такой расчетный счет уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			cl->SetPaym_Acc(p);
			break;
		}
		case 7: {
			strcpy_s(p, "7");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный учетный номер налогоплательщика: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, СheckNumb(9, newS));
				if (clnts.size() != 0) {
					for (auto cl : clnts) {
						if (strcmp(cl.GetTRN(), p) == 0) {
							strcpy_s(m, "Такой УНП уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			cl->SetTRN(p);
			break;
		}
		case 8: {
			strcpy_s(p, "8");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			return;
		}
		}
	}
}

void EditInvObjAdmin(void* newS, list<InvestObject>& invobj) {
	int a = 0, c = 0;
	list<InvestObject>::iterator inob;
	char p[500], m[500];
	while (1) {
		inob = FindInvObj(invobj, newS);
		if (invobj.size() == 0) {
			strcpy_s(p, "В базе не зарегистрирован ни один инвестиционный объект.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = 2;
			break;
		}
		else if (inob == invobj.end()) {
			p[0] = '\0';
			strcpy_s(p, "Данный инвестиционный объект не зарегистрирован в базе. Желаете ли Вы повторить ввод названия? Да(1) или нет(2).");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = CheckInt(1, 2, newS);
			if (a == 1) {
				continue;
			}
			break;
		}
		else {
			p[0] = '\0';
			strcpy_s(p, "Данный инвестиционный объект зарегистрирован в базе.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			break;
		}
	}
	if (a == 2) {
		return;
	}
	while (c != 9) {
		invobj.sort();
		FileRecordInvestObjects(invobj,"InvObjFree.txt", newS);
		FileRecordTableInvestObjects(invobj,"InvObjFreeTable.txt", newS);
		c = EditInvObj_Menu(newS);
		switch (c) {
		case 1: {
			strcpy_s(p, "1");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленное название инвестиционного объекта: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckInvObj(newS));
			inob->SetInv_Obj(p);
			break;
		}
		case 2: {
			strcpy_s(p, "2");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленного владельца: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckInvObj(newS));
			inob->SetOwner(p);
			break;
		}
		case 3: {
			strcpy_s(p, "3");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный email: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, Check_Mail(newS));
				if (invobj.size() != 0) {
					for (auto io : invobj) {
						if (strcmp(io.GetEmail(), p) == 0) {
							strcpy_s(m, "Такой email уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			inob->SetEmail(p);
			break;
		}
		case 4: {
			strcpy_s(p, "4");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				strcpy_s(p, "Введите обновленный номер мобильного телефона: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, Check_PhoneNum(newS));
				if (invobj.size() != 0) {
					for (auto io : invobj) {
						if (strcmp(io.GetPhone(), p) == 0) {
							strcpy_s(m, "Такой номер мобильного телефона уже существует.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			inob->SetPhone(p);
			break;
		}
		case 5: {
			strcpy_s(p, "5");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный учетный номер налогоплательщика: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, СheckNumb(9, newS));
				if (invobj.size() != 0) {
					for (auto io : invobj) {
						if (strcmp(io.GetTRN(), p) == 0) {
							strcpy_s(m, "Такой УНП уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			inob->SetTRN(p);
			break;
		}
		case 6: {
			strcpy_s(p, "6");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленную сферу деятельности: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckInvObj(newS));
			inob->SetOwner(p);
			break;
		}
		case 7: {
			strcpy_s(p, "7");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленный период окупаемости(в годах): ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = CheckInt(newS);
			inob->SetPayback_period(a);
			break;
		}
		case 8: {
			strcpy_s(p, "8");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленный процент рентабельности: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = CheckInt(0, 100, newS);
			inob->SetProfitability(a);
			break;
		}
		case 9: {
			strcpy_s(p, "9");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			return;
		}
		}
	}
}

void EditExpertAdmin(void* newS, list<Expert>& exprt) {
	int a = 0,c=0,y1,y2;
	float f;
	char p[500],m[500],year[500];
	list<Expert>::iterator exp;
	while (1) {
		exp = FindExpert(exprt, newS);
		if (exprt.size() == 0) {
			strcpy_s(p, "В базе не зарегистрирован ни один эксперт.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = 2;
			break;
		}
		else if (exp == exprt.end()) {
			p[0] = '\0';
			strcpy_s(p, "Данный эксперт не зарегистрирован в базе. Желаете ли Вы повторить ввод ФИО? Да(1) или нет(2).");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = CheckInt(1, 2, newS);
			if (a == 1) {
				continue;
			}
			break;
		}
		else {
			p[0] = '\0';
			strcpy_s(p, "Данный эксперт зарегистрирован в базе.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			break;
		}
	}
	if (a == 2) {
		return;
	}
	while (c != 11) {
		exprt.sort();
		FileRecordExperts(exprt, newS);
		FileRecordExpertsTable(exprt, newS);
		FileRecordExpertsPassw(exprt, newS);
		c = EditExpertAdmin_Menu(newS);
		switch (c) {
		case 1: {
			strcpy_s(p, "1");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленную фамилию: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			exp->SetSurname(p);
			break;
		}
		case 2: {
			strcpy_s(p, "2");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленное имя: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			exp->SetName(p);
			break;
		}
		case 3: {
			strcpy_s(p, "3");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленное отчество: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			exp->SetPatronymic(p);
			break;
		}
		case 4: {
			strcpy_s(p, "4");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				strcpy_s(p, "Введите обновленный номер мобильного телефона: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, Check_PhoneNum(newS));
				if (exprt.size() != 0) {
					for (auto ex : exprt) {
						if (strcmp(ex.GetPhone(), p) == 0) {
							strcpy_s(m, "Такой номер мобильного телефона уже существует.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			exp->SetPhone(p);
			break;
		}
		case 5: {
			strcpy_s(p, "5");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный email: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, Check_Mail(newS));
				if (exprt.size() != 0) {
					for (auto ex : exprt) {
						if (strcmp(ex.GetEmail(), p) == 0) {
							strcpy_s(m, "Такой email уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			exp->SetEmail(p);
			break;
		}
		case 6: {
			strcpy_s(p, "6");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленную позицию в компании: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			exp->SetPosition(p);
			break;
		}
		case 7: {
			strcpy_s(p, "7");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный учетный номер налогоплательщика: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, СheckNumb(9, newS));
				if (exprt.size() != 0) {
					for (auto ex : exprt) {
						if (strcmp(ex.GetTRN(), p) == 0) {
							strcpy_s(m, "Такой УНП уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			exp->SetTRN(p);
			break;
		}
		case 8: {
			strcpy_s(p, "8");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Заработная плата: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			f = CheckFloat(newS);
			exp->SetSalary(f);
			break;
		}
		case 9: {
			strcpy_s(p, "9");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				SYSTEMTIME tm;
				GetLocalTime(&tm);
				p[0] = '\0';
				strcpy_s(p, "Введите обновленную дату рождения: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				sprintf_s(p, "%hu", tm.wYear);
				y2 = atoi(p);
				strcpy_s(p, Check_Date(y2 - 100, y2 - 18, newS));
				y1 = strlen(p);
				strcpy_s(year, &p[y1 - 4]);
				y1 = atoi(year);
				if (!(y1 + 18 <= y2 - exp->GetExperience())) {
					strcpy_s(m, "Введенная дата рождения не соответствует возрасту. Повторите попытку.");
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			exp->SetBirthday(p);
			break;
		}
		case 10: {
			strcpy_s(p, "10");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			SYSTEMTIME tm;
			GetLocalTime(&tm);
			sprintf_s(p, "%hu", tm.wYear);
			y2 = atoi(p);
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				strcpy_s(p, "Стаж работы(количество лет): ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				a = CheckInt(newS);
				y1 = strlen(exp->GetBirthday());
				strcpy_s(p, &exp->GetBirthday()[y1 - 4]);
				y1 = atoi(p);
				strcpy_s(p, "0");
				if (!(y1 + 18 <= y2 - a)) {
					strcpy_s(m, "Введенный стаж несоответствует возрасту. Повторите попытку.");
				}
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			exp->SetExperience(a);
			break;
		}
		case 11: {
			strcpy_s(p, "11");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			return;
		}
		}
	}
}

void DeleteExpertAdmin(void* newS, list<Expert>& exprt) {
	list<Expert>::iterator exp;
	char p[500];
	int a=0;
	while (1) {
		exp = FindExpert(exprt, newS);
		if (exprt.size() == 0) {
			strcpy_s(p, "В базе не зарегистрирован ни один эксперт.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = 2;
			break;
		}
		else if (exp == exprt.end()) {
			p[0] = '\0';
			strcpy_s(p, "Данный эксперт не зарегистрирован в базе. Желаете ли Вы повторить ввод ФИО? Да(1) или нет(2).");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = CheckInt(1, 2, newS);
			if (a == 1) {
				continue;
			}
			break;
		}
		else {
			p[0] = '\0';
			strcpy_s(p, "Данный эксперт зарегистрирован в базе.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			break;
		}
	}
	if (a == 2) {
		return;
	}
	exprt.erase(exp);
	strcpy_s(p, "Данный эксперт был удален.");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	FileRecordExperts(exprt, newS);
	FileRecordExpertsTable(exprt, newS);
	FileRecordExpertsPassw(exprt, newS);
	return;
}

void DeleteInvObjAdmin(void* newS, list<InvestObject>& invobj) {
	list<InvestObject>::iterator inob;
	char p[500];
	int a=0;
	while (1) {
		inob = FindInvObj(invobj, newS);
		if (invobj.size() == 0) {
			strcpy_s(p, "В базе не зарегистрирован ни один инвестиционный объект.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = 2;
			break;
		}
		else if (inob == invobj.end()) {
			p[0] = '\0';
			strcpy_s(p, "Данный инвестиционный объект не зарегистрирован в базе. Желаете ли Вы повторить ввод названия? Да(1) или нет(2).");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = CheckInt(1, 2, newS);
			if (a == 1) {
				continue;
			}
			break;
		}
		else {
			p[0] = '\0';
			strcpy_s(p, "Данный инвестиционный объект зарегистрирован в базе.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			break;
		}
	}
	if (a == 2) {
		return;
	}
	invobj.erase(inob);
	strcpy_s(p, "Данный инвестиционный объект был удален.");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	FileRecordInvestObjects(invobj, "InvObjFree.txt", newS);
	FileRecordTableInvestObjects(invobj, "InvObjFreeTable.txt", newS);
	return;
}

list<Client>::iterator AuthorithationClient(list<Client>&clnts, void* newS) {
	char str[500], passw[500], login[500];
	list<Client>::iterator cl;
	strcpy_s(str, "Введите логин(email): ");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	str[0] = '/0';
	strcpy_s(login, Check_Mail(newS));
	strcpy_s(str, "Введите пароль: ");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	str[0] = '/0';
	strcpy_s(passw, Check_Password(newS, 15));
	for (cl = clnts.begin(); cl != clnts.end(); cl++) {
		if (strcmp(login, cl->GetEmail()) == 0 && strcmp(passw, cl->GetPassw()) == 0) {
			break;
		}
	}
	return cl;
}

list<Expert>::iterator AuthorithationExpert(list<Expert>& exprts, void* newS) {
	char str[500], passw[500], login[500];
	list<Expert>::iterator exp;
	strcpy_s(str, "Введите логин(email): ");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	str[0] = '/0';
	strcpy_s(login, Check_Mail(newS));
	strcpy_s(str, "Введите пароль: ");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	str[0] = '/0';
	strcpy_s(passw, Check_Password(newS, 15));
	for (exp = exprts.begin(); exp != exprts.end(); exp++) {
		if (strcmp(login, exp->GetEmail()) == 0 && strcmp(passw, exp->GetPassw()) == 0) {
			break;
		}
	}
	return exp;
}

int AuthorithationAdmin(void* newS) {
	char str[500], passw[500], login[500];
	int err1, err2;
	list<Expert>::iterator exp;
	strcpy_s(str, "Введите логин(email): ");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	str[0] = '/0';
	strcpy_s(login, Check_Mail(newS));
	strcpy_s(str, "Введите пароль: ");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	str[0] = '/0';
	strcpy_s(passw, Check_Password(newS, 15));
	err1 = strcmp(login, GetCompanyEmail(newS));
	err2 = strcmp(passw, GetCompanyPassword(newS));
	if ( err1== 0 || err2== 0) {
		return 0;
	}
	else return 1;
}

void EditClient(void* newS, list<Client>& clnts,list<Client>::iterator& cl) {
	int a = 0, c = 0;
	char p[500], m[500];
	while (c != 9) {
		clnts.sort();
		FileRecordClients(clnts, newS);
		FileRecordClientsTable(clnts, newS, "ClientsTable.txt");
		FileRecordClientsPassw(clnts, newS);
		c = EditClient_Menu(newS);
		switch (c) {
		case 1: {
			strcpy_s(p, "1");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленную фамилию: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			cl->SetSurname(p);
			break;
		}
		case 2: {
			strcpy_s(p, "2");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленное имя: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			cl->SetName(p);
			break;
		}
		case 3: {
			strcpy_s(p, "3");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленное отчество: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			cl->SetPatronymic(p);
			break;
		}
		case 4: {
			strcpy_s(p, "4");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				strcpy_s(p, "Введите обновленный номер мобильного телефона: ");
				p[strlen(p) + 1] = '\0';
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
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный email: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, Check_Mail(newS));
				if (clnts.size() != 0) {
					for (auto cl : clnts) {
						if (strcmp(cl.GetEmail(), p) == 0) {
							strcpy_s(m, "Такой email уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			cl->SetEmail(p);
			break;
		}
		case 6: {
			strcpy_s(p, "6");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный расчетный счет: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, СheckNumb(12, newS));
				if (clnts.size() != 0) {
					for (auto cl : clnts) {
						if (strcmp(cl.GetPaym_Acc(), p) == 0) {
							strcpy_s(m, "Такой расчетный счет уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			cl->SetPaym_Acc(p);
			break;
		}
		case 7: {
			strcpy_s(p, "7");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный учетный номер налогоплательщика: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, СheckNumb(9, newS));
				if (clnts.size() != 0) {
					for (auto cl : clnts) {
						if (strcmp(cl.GetTRN(), p) == 0) {
							strcpy_s(m, "Такой УНП уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			cl->SetTRN(p);
			break;
		}
		case 8: {
			strcpy_s(p, "8");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный пароль: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, Check_Password(newS,15));
				if (clnts.size() != 0) {
					for (auto cl : clnts) {
						if (strcmp(cl.GetPassw(), p) == 0) {
							strcpy_s(m, "Такой пароль уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			cl->SetPassw(p);
			break;
		}
		case 9: {
			strcpy_s(p, "9");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			return;
		}
		}
	}
}

void EditExpert(void* newS, list<Expert>& exprt,list<Expert>::iterator& exp) {
	int a = 0, c = 0, y1, y2;
	float f;
	char p[500], m[500],year[500];
	while (c != 10) {
		exprt.sort();
		FileRecordExperts(exprt, newS);
		FileRecordExpertsTable(exprt, newS);
		FileRecordExpertsPassw(exprt, newS);
		c = EditExpert_Menu(newS);
		switch (c) {
		case 1: {
			strcpy_s(p, "1");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленную фамилию: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			exp->SetSurname(p);
			break;
		}
		case 2: {
			strcpy_s(p, "2");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленное имя: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			exp->SetName(p);
			break;
		}
		case 3: {
			strcpy_s(p, "3");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "Введите обновленное отчество: ");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, СheckRus(0, newS));
			exp->SetPatronymic(p);
			break;
		}
		case 4: {
			strcpy_s(p, "4");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				strcpy_s(p, "Введите обновленный номер мобильного телефона: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, Check_PhoneNum(newS));
				if (exprt.size() != 0) {
					for (auto ex : exprt) {
						if (strcmp(ex.GetPhone(), p) == 0) {
							strcpy_s(m, "Такой номер мобильного телефона уже существует.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			exp->SetPhone(p);
			break;
		}
		case 5: {
			strcpy_s(p, "5");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный email: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, Check_Mail(newS));
				if (exprt.size() != 0) {
					for (auto ex : exprt) {
						if (strcmp(ex.GetEmail(), p) == 0) {
							strcpy_s(m, "Такой email уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			exp->SetEmail(p);
			break;
		}
		case 6: {
			strcpy_s(p, "6");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный учетный номер налогоплательщика: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, СheckNumb(9, newS));
				if (exprt.size() != 0) {
					for (auto ex : exprt) {
						if (strcmp(ex.GetTRN(), p) == 0) {
							strcpy_s(m, "Такой УНП уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			exp->SetTRN(p);
			break;
		}
		case 7: {
			strcpy_s(p, "7");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				SYSTEMTIME tm;
				GetLocalTime(&tm);
				p[0] = '\0';
				strcpy_s(p, "Введите обновленную дату рождения: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				sprintf_s(p, "%hu", tm.wYear);
				y2 = atoi(p);
				strcpy_s(p, Check_Date(y2 - 100, y2 - 18, newS));
				y1 = strlen(p);
				strcpy_s(year, &p[y1 - 4]);
				y1 = atoi(year);
				if (!(y1 + 18 <= y2 - exp->GetExperience())) {
					strcpy_s(m, "Введенная дата рождения не соответствует возрасту. Повторите попытку.");
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			exp->SetBirthday(p);
			break;
		}
		case 8: {
			strcpy_s(p, "8");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			SYSTEMTIME tm;
			GetLocalTime(&tm);
			sprintf_s(p, "%hu", tm.wYear);
			y2 = atoi(p);
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				strcpy_s(p, "Стаж работы(количество лет): ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				a = CheckInt(newS);
				y1 = strlen(exp->GetBirthday());
				strcpy_s(p, &exp->GetBirthday()[y1 - 4]);
				y1 = atoi(p);
				strcpy_s(p, "0");
				if (!(y1 + 18 <= y2 - a)) {
					strcpy_s(m, "Введенный стаж несоответствует возрасту. Повторите попытку.");
				}
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			exp->SetExperience(a);
			break;
		}
		case 9: {
			strcpy_s(p, "9");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(m, "1");
			while (strcmp(m, "0") != 0) {
				strcpy_s(m, "0");
				p[0] = '\0';
				strcpy_s(p, "Введите обновленный пароль: ");
				p[strlen(p) + 1] = '\0';
				send((SOCKET)newS, p, sizeof(p), 0);
				strcpy_s(p, Check_Password(newS, 15));
				if (exprt.size() != 0) {
					for (auto ex : exprt) {
						if (strcmp(ex.GetPassw(), p) == 0) {
							strcpy_s(m, "Такой пароль уже существует. Повторите попытку.");
						}
					}
				}
				m[strlen(m) + 1] = '\0';
				send((SOCKET)newS, m, sizeof(m), 0);
			}
			exp->SetPassw(p);
			break;
		}
		case 10: {
			strcpy_s(p, "10");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			return;
		}
		}
	}
}

void AddMoneyClient(void* newS, list<Client>& clnts, list<Client>::iterator& cl) {
	char p[500];
	float f1, f2;
	strcpy_s(p, "Введите сумму, которую вы хотите внести на свой счет: ");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	f1 = cl->GetAccount();
	f2 = CheckFloat(newS);
	cl->SetAccount(f1 + f2);
	strcpy_s(p, "Денежная сумма успешно внесена на счет.\n");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	FileRecordClients(clnts, newS);
	FileRecordClientsTable(clnts, newS, "ClientsTable.txt");
}

void RecordMailExpert(void* newS, list<Mail<int>> lst) {
	char str[500], FIO[80];
	int i = 1;
	ofstream f("ExpertMailAdmin.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (auto l : lst) {
		f << l.GetMessage() << ";" << l.GetFIO() << ";" << l.GetID() << ";"<<l.GetDetails()<<";" << l.GetDecision() << ";";
	}
	f << "***;";
	f.close();
}

void RecordTableMailExpert(void* newS, list<Mail<int>> lst) {
	char str[500], mess[80];
	int i = 1;
	ofstream f("ExpertMailAdminTable.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f << right << setw(161) << setfill('-') << "" << endl;
	f << left << setfill(' ') << "|" << setw(3) << "№" << "| "  << setw(45) << "Запрос" << "| "  << setw(50) << "ФИО" << "| " << setw(7) << "ID" << "| " << "Повышение зар.платы(в бел.р.)(29)" << " | " << left << setw(10) << "Решение" <<"|" << endl;
	f << right << setw(161) << setfill('-') << "" << endl;
	for (auto l : lst) {
		if (l.GetMessageW() == 1) {
			strcpy_s(mess, "Увеличение заработной оплаты");
		}
		else {
			strcpy_s(mess, "Увольнение");
		}
		f <<"|" << setfill(' ')<<left<<setw(3)<<i<<"| "<<setw(45)<< mess << "| " <<setw(50)<< l.GetFIO() << "| " <<setw(7)<< l.GetID() << "| " <<setw(33)<< l.GetDetails() << " | " <<setw(10)<< l.GetDecision() << "|"<<endl;
		f << right << setw(161) << setfill('-') << "" << endl;
		i++;
	}
	f.close();
}

void RecordMailClient(void* newS, list<Mail<string>> lst) {
	char str[500], FIO[80];
	int i = 1;
	ofstream f("ClientMailAdmin.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	for (auto l : lst) {
		f << l.GetMessage() << ";" << l.GetFIO() << ";" << l.GetID() << ";" << l.GetDetails() << ";" << l.GetDecision() << ";";
	}
	f << "***;";
	f.close();
}

void RecordTableMailClient(void* newS, list<Mail<string>> lst) {
	char str[500], FIO[80];
	int i = 1;
	ofstream f("ClientMailAdminTable.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f << right << setw(161) << setfill('-') << "" << endl;
	f << left << setfill(' ') << "|" << setw(3) << "№" << "| " << setw(45) << "Запрос" << "| " << setw(50) << "ФИО" << "| " << setw(7) << "ID" << "| " << "Повышение зар.платы(в бел.р.)(29)" << " | " << left << setw(10) << "Решение" << "|" << endl;
	f << right << setw(161) << setfill('-') << "" << endl;
	for (auto l : lst) {

		f << "|" << setfill(' ') << left << setw(3) << i << "| " << setw(45) << l.GetMessageW() << "| " << setw(50) << l.GetFIO() << "| " << setw(7) << l.GetID() << "| " << setw(33) << l.GetDetails() << " | " << setw(10) << l.GetDecision() << "|" << endl;
		f << right << setw(161) << setfill('-') << "" << endl;
		i++;
	}
	f.close();
}

void AddClientMailRequest(void* newS, list<Mail<string>>& lst, list<Client>::iterator& cl) {
	Mail<string> obj;
	char str[50];
	int flag = 0;
	obj.SetMessage("Разрыв договора");
	strcpy_s(str,cl->GetSurname());
	strcat_s(str," ");
	strcat_s(str, cl->GetName());
	strcat_s(str, " ");
	strcat_s(str, cl->GetPatronymic());
	obj.SetFIO(str);
	for (auto l : lst) {
		if(strcmp(l.GetID(), cl->GetID())==0) {
			strcpy_s(str, "Данный запрос уже был отправлен ранее.");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			return;
		}
	}
	obj.SetID(cl->GetID());
	lst.push_back(obj);
	lst.sort();
	strcpy_s(str, "Сообщение успешно отправлено.");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	RecordMailClient(newS, lst);
	RecordTableMailClient(newS, lst);
}

void AddExpertMailRequest(void* newS, list<Mail<int>>& lst, list<Expert>::iterator& exp) {
	Mail<int> obj;
	char str[500],str1[500],p[500];
	int a,flag=0;
	float m;
	str[0] = '\0';
	strcpy_s(str, "Вы хотите отправить запрос на увеличение зарплаты(1) или на увольнение(2)?");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	a = CheckInt(1, 2, newS);
	if (a == 2) {
		ifstream f1("Project.txt", ios_base::in);
		if (!f1.is_open() || f1.bad()) {
			cout << "Файл не удалось открыть." << endl;
			strcpy_s(p, "FileError");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			return;
		}
		else {
			strcpy_s(p, "FileGood");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
		}
		if (f1.peek() == EOF) {
			strcpy_s(p, "Good");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
		}
		else {
			strcpy_s(p, "Невозможно увольнение, так как на данный момент принимается решение насчет добавления инвестиционного объекта.\nПожалуйста, повторите попытку позже.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			f1.close();
			return;
		}
		f1.close();
	}
	_itoa_s(a, str, 10);
	obj.SetMessage(a);
	for (auto l : lst) {
		_itoa_s(l.GetMessage(), str1, 10);
		str1[strlen(str1) + 1] = '\0';
		if (strcmp(l.GetID(), exp->GetID()) == 0 && strcmp(str, str1) == 0) {
			str[0] = '\0';
			strcpy_s(str, "Данный запрос уже был отправлен ранее.");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			flag = 1;
			return;
		}
	}
	if (flag == 0) {
		str[0] = '\0';
		strcpy_s(str, "Все хорошо.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	if (a == 1) {
		str[0] = '\0';
		strcpy_s(str, "Введите сумму, на которую Вы хотите увеличить свою заработную плату.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		m = CheckFloat(newS);
		sprintf_s(str, "%.2f", m);
		str[strlen(str) + 1] = '\0';
		obj.SetDetails(str);
	}
	strcpy_s(str, exp->GetSurname());
	strcat_s(str, " ");
	strcat_s(str, exp->GetName());
	strcat_s(str, " ");
	strcat_s(str, exp->GetPatronymic());
	obj.SetFIO(str);
	obj.SetID(exp->GetID());
	lst.push_back(obj);
	lst.sort();
	RecordMailExpert(newS, lst);
	RecordTableMailExpert(newS, lst);
	strcpy_s(str, "Сообщение успешно отправлено.");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
}

void FileReadExpertMail(list<Mail<int>>& mexp, void* newS) {
	Mail<int> obj;
	char str[500];
	int a;
	ifstream f("ExpertMailAdmin.txt", ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	if (f.peek() == EOF) {
		cout << "Файл пуст." << endl;
		return;
	}
	while (1) {
		f.getline(str, 100, ';');
		if (strcmp(str, "***") == 0) {
			break;
		}
		a = atoi(str);
		obj.SetMessage(a);
		f.getline(str, 100, ';');
		obj.SetFIO(str);
		f.getline(str, 100, ';');
		obj.SetID(str);
		f.getline(str, 100, ';');
		obj.SetDetails(str);
		f.getline(str, 100, ';');
		obj.SetDecision(str);
		mexp.push_back(obj);
		mexp.sort();
	}
	f.close();
}

void FileReadClientMail(list<Mail<string>>& mcl, void* newS) {
	Mail<string> obj;
	char str[500];
	int a;
	ifstream f("ClientMailAdmin.txt", ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	if (f.peek() == EOF) {
		cout << "Файл пуст." << endl;
		return;
	}
	while (1) {
		f.getline(str, 100, ';');
		if (strcmp(str, "***") == 0) {
			break;
		}
		obj.SetMessage(str);
		f.getline(str, 100, ';');
		obj.SetFIO(str);
		f.getline(str, 100, ';');
		obj.SetID(str);
		f.getline(str, 100, ';');
		obj.SetDetails(str);
		f.getline(str, 100, ';');
		obj.SetDecision(str);
		mcl.push_back(obj);
		mcl.sort();
	}
	f.close();
}

void AnswerAdminRequestClient(list<Mail<string>>& mcl, void* newS, list<Client>& clnts) {
	char str[500];
	int i;
	list<Mail<string>>::iterator m = mcl.begin();
	list<Client>::iterator cl;
	if (mcl.size() == 0) {
		strcpy_s(str, "Почта пуста.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "Почта не пуста.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	FileReadTable(newS, "ClientMailAdminTable.txt");
	strcpy_s(str, "Введите номер запроса, на который Вы хотите ответить.");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	i = CheckInt(1, mcl.size(), newS);
	for (int k = 1; k <= mcl.size(); k++) {
		if (k == i) {
			break;
		}
		m++;
	}
	for (cl = clnts.begin(); cl != clnts.end(); cl++) {
		if (strcmp(cl->GetID(), m->GetID()) == 0) {
			break;
		}
	}
	strcpy_s(str, "Вы согласны(1) или нет(2)?");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	i = CheckInt(1, 2, newS);
	if (i == 1) {
		strcpy_s(str, cl->GetID());
		strcat_s(str, "_contract.txt");
		remove(str);
		strcpy_s(str, cl->GetID());
		strcat_s(str, "_clientmail.txt");
		remove(str);
		clnts.erase(cl);
		FileRecordClients(clnts, newS);
		FileRecordClientsTable(clnts, newS, "ClientsTable.txt");
		FileRecordClientsPassw(clnts, newS);

	}
	else {
		strcpy_s(str, cl->GetID());
		strcat_s(str, "_clientmail.txt");
		ofstream f(str, ios_base::out & ios_base::trunc);
		f << "Отказано в разрыве договора;" << endl;
		f.close();
	}
	mcl.erase(m);
	RecordMailClient(newS, mcl);
	RecordTableMailClient(newS, mcl);
}

void AnswerAdminRequestExpert(list<Mail<int>>& mexp, void* newS, list<Expert>& exprt) {
	char str[500];
	int i;
	float s1,s2;
	list<Mail<int>>::iterator m = mexp.begin();
	list<Expert>::iterator exp;
	if (mexp.size() == 0) {
		strcpy_s(str, "Почта пуста.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "Почта не пуста.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	FileReadTable(newS, "ExpertMailAdminTable.txt");
	strcpy_s(str, "Введите номер запроса, на который Вы хотите ответить.");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	i = CheckInt(1, mexp.size(), newS);
	for (int k = 1; k <= mexp.size(); k++) {
		if (k == i) {
			break;
		}
		m++;
	}
	for (exp = exprt.begin(); exp != exprt.end(); exp++) {
		if (strcmp(exp->GetID(), m->GetID()) == 0) {
			break;
		}
	}
	strcpy_s(str, "Вы согласны(1) или нет(2)?");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	i = CheckInt(1, 2, newS);
	if (i == 1) {
		if (m->GetMessage() == 1) {
			s1 = exp->GetSalary();
			s2 = stof(m->GetDetails());
			exp->SetSalary(s1+ s2);
		}
		if (m->GetMessage() == 2) {
			strcpy_s(str, exp->GetID());
			strcat_s(str, "_expertmail.txt");
			remove(str);
			exprt.erase(exp);
		}
		FileRecordExperts(exprt, newS);
		FileRecordExpertsTable(exprt, newS);
		FileRecordExpertsPassw(exprt, newS);
	}
	else {
		strcpy_s(str, exp->GetID());
		strcat_s(str, "_expertmail.txt");
		ofstream f(str, ios_base::out & ios_base::trunc);
		if (m->GetMessage() == 1) {
			strcpy_s(str, "в повышении;");
		}
		else {
			strcpy_s(str, "в увольнении;");
		}
		f << "Отказано "<<str << endl;
		f.close();
	}
	mexp.erase(m);
	RecordMailExpert(newS, mexp);
	RecordTableMailExpert(newS, mexp);
}

int CopyFileToFile(const char* path1, const char* path2, void* newS,const char k) {
	char str[500];
	ofstream f2(path2, ios_base::out & ios_base::trunc);
	if (!f2.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return 1;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	ifstream f1(path1, ios_base::in);
	if (!f1.is_open() || f1.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return 1;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	if (f1.peek() == EOF) {
		strcpy_s(str, "Невозможно формирование решения, так как отсутствуют инвестиционные объекты.");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return 1;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	while (!f1.eof()) //Будем читать информацию пока не дойдем до конца файла
	{
		str[0] = '/0';
		f1.getline(str, 500,k); //Построчное считывание информации в S 
		f2 << str<<k;
	}
	f1.close();
	f2.close();
	return 0;
}

void MakeDesicion(void* newS, list<Client> clnts) {
	char p[500], m[500];
	int a=0,size;
	list<Client>::iterator cl;
	ofstream f("Project.txt", ios_base::app);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(p, "FileError");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		return;
	}
	else {
		strcpy_s(p, "FileGood");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
	}
	f.seekp(0,ios::end);
	size = f.tellp();
	if (size != 0) {
		strcpy_s(p, "Решение уже сформировано для другого клиента. Пожалуйста, повторите попытку позже.");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
		return;
	}
	else {
		strcpy_s(p, "FileGood");
		p[strlen(p) + 1] = '\0';
		send((SOCKET)newS, p, sizeof(p), 0);
	}
	strcpy_s(p, "Выберите клиента, для которого будет выбираться инвестиционный объект экспертами.");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	while (1) {
		cl = FindClient(clnts, newS);
		if (clnts.size() == 0) {
			strcpy_s(p, "В базе не зарегистрирован ни один клиент.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = 2;
			break;
		}
		else if (cl == clnts.end()) {
			p[0] = '\0';
			strcpy_s(p, "Данный клиент не зарегистрирован в базе. Желаете ли Вы повторить ввод ФИО? Да(1) или нет(2).");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = CheckInt(1, 2, newS);
			if (a == 1) {
				continue;
			}
			break;
		}
		else {
			p[0] = '\0';
			strcpy_s(p, "Данный клиент зарегистрирован в базе.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			break;
		}
	}
	if (a == 2) {
		return;
	}
	f << cl->GetID() << ";0;*;0;*;0;***;";
	f.close();
	a=CopyFileToFile("InvObjFree.txt", "CopyInvObjFree.txt", newS,';');
	if (a == 1) {
		return;
	}
	a = CopyFileToFile("InvObjFreeTable.txt", "CopyInvObjFreeTable.txt", newS,'\n');
	if (a == 1) {
		return;
	}
	strcpy_s(p, "Решение сформировано.");
	p[strlen(p) + 1] = '\0';
	send((SOCKET)newS, p, sizeof(p), 0);
	
}

void RecordProjectFile(void* newS,int* mass,const char* id,int q) {
	char str[500];
	ofstream f("Project.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f << id << ";";
	cout << sizeof(mass) << endl;
	for (int i = 0; i < q; i++) {
		f << mass[i] << ";";
	}
	f << "*;0;*;0;***;";
	f.close();
}

void RecordProjectFile(void* newS, int* mass1, int* mass2, const char* id,int q) {
	char str[500];
	ofstream f("Project.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f << id << ";";
	for (int i = 0; i < q; i++) {
		f << mass1[i] << ";";
	}
	f << "*;";
	for (int i = 0; i < q; i++) {
		f << mass2[i] << ";";
	}
	f << "*;0;***;";
	f.close();
}

void RecordProjectFile(void* newS, int* mass1, int* mass2, int* mass3,  const char* id,int q) {
	char str[500];
	ofstream f("Project.txt", ios_base::out & ios_base::trunc);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f << id << ";";
	for (int i = 0; i < q; i++) {
		f << mass1[i] << ";";
	}
	f << "*;";
	for (int i = 0; i < q; i++) {
		f << mass2[i] << ";";
	}
	f << "*;";
	for (int i = 0; i < q; i++) {
		f << mass3[i] << ";";
	}
	f << "***;";
	f.close();
}

template <class T>
void RecordMethod(void* newS,T** E,T** m, T max, int q) {  
	char str[500];
	CopyFileToFile("CopyInvObjFreeTable.txt", "Method.txt", newS, '\n');
	ofstream f("Method.txt", ios_base::app);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f << "Оценки экспертов:\n";
	f <<left<<  setw(16) <<setfill('-') <<"" << endl;
	f << setfill(' ') << "| Э1 | Э2 | Э3 |"<< "\n";
	f << left << setw(16) << setfill('-') << "" << endl;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < 3; j++) {
			f <<left<<"|"<<setw(4) << setfill(' ') <<E[i][j];
		}
		f  <<"|" << "\n";
		f << left << setw(16) << setfill('-') << "" << endl;
	}
	f << "\n";
	int k = 6 + 5 * q;
	f << setfill(' ') << "Оценки, характеризующие предпочтение альтернатив в парных предпочтениях." << "\n";
	f << left << setw(k) << setfill('-') << "" << endl;
	f << setfill(' ') << "|    |";
	for (int i = 0; i < q; i++) {
		f << left << "a" << setw(3) << setfill(' ') << i + 1 << "|";
	}
	f<<"\n";
	f << left << setw(k) << setfill('-') << "" << endl;
	for (int i = 0; i < q; i++)
	{
		f <<left<< "|a" << setw(3) << setfill(' ') << i + 1<<"|";
		for (int j = 0; j < q; j++)
		{
			if (i != j) f << setw(4) << setfill(' ')<<left << m[i][j]<<"|";
			else f << setw(4) << setfill(' ') <<left<< "-" << "|";
		}
		f << "\n";
		f << left << setw(k) << setfill('-') << "" << endl;
	}
	f << "\n";
	f << setfill(' ') << "Наилучшей альтерантивой по методу Кондорсе является альтернатива по номером " << max<< "\n";
	f.close();
}

int Method(void* newS, int* mass1, int* mass2, int* mass3,int q ) {
	int k, i, j, n = 0, flag = 0;
	int** E = new int* [q];
	for (int i = 0; i < q; i++) {
		E[i] = new int[3];
	}
	int** p = new int* [q];
	for (int i = 0; i < q; i++) {
		p[i] = new int[3];
	}
	int num;
	j = 0;
	for (i = 0; i < q; i++) {
		E[i][j] = mass1[i];
	}
	j ++;
	for (i = 0; i < q; i++) {
		E[i][j] = mass2[i];
	}
	j ++;
	for (i = 0; i < q; i++) {
		E[i][j] = mass3[i];
	}
	for (i = 0; i < q; i++)
		for (j = 0; j < 3; j++)
			p[i][j] = 0;

	for (k = 0; k <q ; k++)
		for (i = 0; i < 3; i++)
			for (j = 0; j < q; j++)
				if (E[j][i] == (k + 1))
					p[k][i] = j + 1;

	int** m = new int* [q];
	for (int i = 0; i < q; i++) {
		m[i] = new int[q];
	}
	for (i = 0; i < q; i++)
		for (j = 0; j < q; j++)
			m[i][j] = 0;
	for (k = 0; k < q; k++)
	{
		for (i = 0; i < q; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (p[k][j] < p[i][j] && i != k)
					m[k][i]++;
			}
		}
	}
	// выбираем наилучшую альтернативу согласно принципу Кондерсе
	int max=0;
	for (i = 0; i < q; i++)
	{
		for (j = 0; j < q; j++)
		{
			if (m[i][j] >= m[j][i] && i != j)
				n++;
			if (j == q-1)
			{
				if (n == q-1)
					max=i + 1;
				else n = 0;
			}
		}
	}
	cout << max << endl;
	RecordMethod(newS, E, m, max, q);
	return max;
}

void RecordInvObjMethod(void* newS, list<InvestObject>::iterator io) {
	char str[500];
	ofstream f("Method.txt", ios_base::app);
	if (!f.is_open()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	f << right << setw(206) << setfill('-') << "" << endl;
	f << left << setfill(' ')<<  "| " << setw(7) << "ID" << "| " << setw(31) << "Инвестиционный объект" << "| " << setw(30) << "Владелец" << "| " << setw(27) << "Email" << "|" << setw(13) << "Моб.телефон" << "|" << setw(9) << "УНП" << "|" << left << setw(45) << "Сфера" << "|Срок окупаемости|Рентабельность|" << endl;
	f << right << setw(206) << setfill('-') << "" << endl;
	f << setfill(' ') << left << "| " << io->GetID() << " | " << setw(31) << io->GetInv_obj() << "| " << setw(30) << io->GetOwner() << "| " << setw(27) << io->GetEmail() << "|" << setw(13) << io->GetPhone() << "|" << io->GetTRN() << "|" << setw(45) << io->GetProduct() << "| " << setw(13) << io->GetPayback_period() << "г." << "| " << setw(11) << io->GetProfitability() << "% |" << endl;
	f << right << setw(206) << setfill('-') << "" << endl;
	f.close();
}

list<Client>::iterator FindClientID(list<Client>& clnts, const char* ID) {
	list<Client>::iterator cl = clnts.begin();
	for (cl; cl!= clnts.end(); cl++) {
		if (strcmp(cl->GetID(), ID) == 0) {
			break;
		}
	}
	return cl;
}

void AddInvObjClient(void* newS, const char* ID, list<Client> clnts, list<InvestObject>::iterator ino) {
	char str[500];
	list <Client>::iterator cl = FindClientID(clnts, ID);
	InvestObject io;
	int a;
	list<InvestObject> invobj;
	strcpy_s(str, ID);
	strcat_s(str, "_portfolio.txt");
	ifstream f(str, ios_base::in);
	if (!f.is_open() || f.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	if (f.peek() != EOF) {
		while (1) {
			f.getline(str, 100, ';');
			if (strcmp(str, "***") == 0) {
				break;
			}
			io.SetInv_Obj(str);
			f.getline(str, 100, ';');
			io.SetOwner(str);
			f.getline(str, 100, ';');
			io.SetID(str);
			f.getline(str, 100, ';');
			io.SetEmail(str);
			f.getline(str, 100, ';');
			io.SetPhone(str);
			f.getline(str, 100, ';');
			io.SetTRN(str);
			f.getline(str, 100, ';');
			io.SetProduct(str);
			f.getline(str, 100, ';');
			a = atoi(str);
			io.SetPayback_period(a);
			f.getline(str, 100, ';');
			a = atoi(str);
			io.SetProfitability(a);
			invobj.push_back(io);
			invobj.sort();
		}
	}
	f.close();
	io.SetInv_Obj(ino->GetInv_obj());
	io.SetOwner(ino->GetOwner());
	io.SetID(ino->GetID());
	io.SetEmail(ino->GetEmail());
	io.SetPhone(ino->GetPhone());
	io.SetTRN(ino->GetTRN());
	io.SetPayback_period(ino->GetPayback_period());
	io.SetProfitability(ino->GetProfitability());
	io.SetProduct(ino->GetProduct());
	invobj.push_back(io);
	invobj.sort();
	strcpy_s(str, ID);
	strcat_s(str, "_portfoliotable.txt");
	FileRecordTableInvestObjects(invobj, str, newS);
	strcpy_s(str, ID);
	strcat_s(str, "_portfolio.txt");
	FileRecordInvestObjects(invobj, str, newS);
}

void ExpertSetMarks(void* newS, list<Client>& clnts, list<InvestObject>& invobj, list<Expert>::iterator exp) {
	char str[500];
	list<InvestObject> prio;
	ifstream f1("Project.txt", ios_base::in);
	if (!f1.is_open() || f1.bad()) {
		cout << "Файл не удалось открыть." << endl;
		strcpy_s(str, "FileError");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		return;
	}
	else {
		strcpy_s(str, "FileGood");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
	}
	FileReadTable(newS, "CopyInvObjFreeTable.txt");
	FileReadInvestObjects(prio, "CopyInvObjFree.txt",newS);
	strcpy_s(str, "Введите, пожалуйста, все номера инвестиционных объектов от самого предпочтительного\nдо самого не предпочительного через клавишу Enter.");
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	_itoa_s(prio.size(), str, 10);
	str[strlen(str) + 1] = '\0';
	send((SOCKET)newS, str, sizeof(str), 0);
	int* mass = new int[prio.size()];
	mass = CheckDecisionNum(prio.size(), newS);
	for (int i = 0; i < prio.size(); i++) {
		cout << mass[i] << endl;
	}
	char ID[20];
	f1.getline(ID, 50, ';');
	f1.getline(str, 50, ';');
	if (strcmp(str, "0") == 0) {
		strcpy_s(str, "1");
		str[strlen(str) + 1] = '\0';
		send((SOCKET)newS, str, sizeof(str), 0);
		RecordProjectFile(newS, mass, ID, prio.size());
		ofstream f("ProjectExperts.txt", ios_base::app);
		if (!f.is_open()) {
			cout << "Файл не удалось открыть." << endl;
			strcpy_s(str, "FileError");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			return;
		}
		else {
			strcpy_s(str, "FileGood");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
		}
		f << exp->GetID() << ";";
		f.close();
	}
	else {
		int* mass2 = new int[prio.size()];
		
		mass2[0] = atoi(str);
		for (int i = 1; i < prio.size(); i++) {
			f1.getline(str, 50, ';');
			if (strcmp(str, "*") == 0) {
				break;
			}
			mass2[i] = atoi(str);
		}
		f1.getline(str, 50, ';');
		f1.getline(str, 50, ';');
		if (strcmp(str, "0") == 0) {
			strcpy_s(str, "1");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			RecordProjectFile(newS, mass2,mass, ID, prio.size());
			ofstream f("ProjectExperts.txt", ios_base::app);
			if (!f.is_open()) {
				cout << "Файл не удалось открыть." << endl;
				strcpy_s(str, "FileError");
				str[strlen(str) + 1] = '\0';
				send((SOCKET)newS, str, sizeof(str), 0);
				return;
			}
			else {
				strcpy_s(str, "FileGood");
				str[strlen(str) + 1] = '\0';
				send((SOCKET)newS, str, sizeof(str), 0);
			}
			f << exp->GetID() << ";";
			f.close();
		}
		else {
			strcpy_s(str, "2");
			str[strlen(str) + 1] = '\0';
			send((SOCKET)newS, str, sizeof(str), 0);
			int* mass3 = new int[prio.size()];
			mass3[0] = atoi(str);
			for (int i = 1; i < prio.size(); i++) {
				f1.getline(str, 50, ';');
				if (strcmp(str, "***") == 0) {
					break;
				}
				mass3[i] = atoi(str);
			}
			RecordProjectFile(newS, mass2, mass3,mass, ID, prio.size());
			int max = Method(newS, mass, mass2, mass3, prio.size());
			int k=1;
			list<InvestObject>::iterator pr=prio.begin();
			for (pr; pr != prio.end(); pr++) {
				if (k == max) {
					break;
				}
				k++;
			}
			list<InvestObject>::iterator pr1 = invobj.begin();
			RecordInvObjMethod(newS, pr);
			for (pr1; pr1 != invobj.end(); pr1++) {
				if (strcmp(pr1->GetID(),pr->GetID())==0) {
					break;
				}
			}
			invobj.erase(pr1);
			FileRecordInvestObjects(invobj, "InvObjFree.txt", newS);
			FileRecordTableInvestObjects(invobj, "InvObjFreeTable.txt", newS);
			AddInvObjClient(newS, ID, clnts, pr);
			ofstream f2("Project.txt", ios_base::out & ios_base::trunc);
			f2.close();
			ofstream f3("ProjectExperts.txt", ios_base::out & ios_base::trunc);
			f3.close();
		}
	}
	f1.close();
}

void PrintClInvObj(void* newS, list<Client>& clnts) {
	int a = 0, c = 0;
	list<Client>::iterator cl;
	char p[500], m[500];
	while (1) {
		cl = FindClient(clnts, newS);
		if (clnts.size() == 0) {
			strcpy_s(p, "В базе не зарегистрирован ни один клиент.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = 2;
			break;
		}
		else if (cl == clnts.end()) {
			p[0] = '\0';
			strcpy_s(p, "Данный клиент не зарегистрирован в базе. Желаете ли Вы повторить ввод ФИО? Да(1) или нет(2).");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			a = CheckInt(1, 2, newS);
			if (a == 1) {
				continue;
			}
			break;
		}
		else {
			p[0] = '\0';
			strcpy_s(p, "Данный клиент зарегистрирован в базе.");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			break;
		}
	}
	if (a == 2) {
		return;
	}
	strcpy_s(p, cl->GetID());
	strcat_s(p,"_portfoliotable.txt");
	FileReadTable(newS, p);
}

void main_working(void* newS) {
	list<Client> clnts;
	list<Client>::iterator cl;
	list<Expert> exprt;
	list<Expert>::iterator exp;
	list<InvestObject> invst_objct;
	list<InvestObject>::iterator inv_obj;
	list<Mail<string>> mcl;
	list<Mail<int>> mexp;
	int c, c1 = 0, c2 = 0, c3 = 0;
	int flag = 0,t;
	char p[500], k[500], m[500];
	p[0] = '\0'; k[0] = '\0'; m[0] = '\0';
	cout << "Сервер начал свою работу." << endl;
	FileReadClients(clnts, newS);
	FileReadExperts(exprt,newS);
	FileReadInvestObjects(invst_objct, "InvObjFree.txt",newS);
	FileReadExpertMail(mexp,newS);
	FileReadClientMail(mcl,newS);
	while (1) {
		c = Main_Menu(newS);
		switch (c) {
		case 1: {
			strcpy_s(p, "1");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			flag = 0;
			while (1) {
				t = AuthorithationAdmin(newS);
				if (t == 1) {
					strcpy_s(p, "Неверный логин и/или пароль.\nЖелаете повторить попытку? Да(1) или нет(2).");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					p[0] = '/0';
					flag = CheckInt(1, 2, newS);
					if (flag == 1) {
						continue;
					}
					else break;
				}
				else {
					strcpy_s(p, "Авторизация прошла успешно.");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
			}
			if (flag == 2) {
				break;
			}
			while (c1 != 5) {
				c1 = Admin_Menu(newS);
				switch (c1) {
				case 1: {
					strcpy_s(p, "1");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 8) {
						c2 = ControlCl_Menu(newS);
						switch (c2) {
						case 1: {  //добавление нового клиента
							strcpy_s(p, "1");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							AddNewClient(newS, clnts);
							break;
						}
						case 2: { //вывод на экран таблицы с клиентами
							strcpy_s(p, "2");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							FileReadTable(newS, "ClientsTable.txt");
							break;
						}
						case 3: { //редактирование данных
							strcpy_s(p, "3");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							EditClientAdmin(newS, clnts);
							break;
						}
						case 4: { //вывод на экран контркта с определенным клиентом
							strcpy_s(p, "4");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							FileReadClientContract(clnts, newS);
							break;
						}
						case 5: { //фильтрация и сортировка по денежной сумме вклада
							strcpy_s(p, "5");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							WorkDataClient(clnts, newS);
							break;
						}
						case 6: { //вывод инвест.объектов клиента
							strcpy_s(p, "6");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							PrintClInvObj(newS, clnts);
							break;
						}
						case 7: {
							strcpy_s(p, "7");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							AnswerAdminRequestClient(mcl, newS, clnts);
							break;
						}
						case 8: {
							strcpy_s(p, "8");
							p[strlen(p) + 1] = '\0';
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
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 3) {
						c2 = MakeDecis_Menu(newS);
						switch (c2) {
						case 1: {
							strcpy_s(p, "1");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							FileReadTable(newS, "Method.txt");
							break;
						}
						case 2: {
							strcpy_s(p, "2");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							if (exprt.size() != 3) {
								strcpy_s(p, "Недостаточно экспертов для формирования решения.");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
								break;
							}
							else {
								strcpy_s(p, "Good");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
							}
							if (invst_objct.size() < 3) {
								strcpy_s(p, "Недостаточно инвестиционных объектов для формирования решения.");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
								break;
							}
							else {
								strcpy_s(p, "Good");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
							}
							MakeDesicion(newS, clnts);
							break;
						}
						case 3: {
							strcpy_s(p, "3");
							p[strlen(p) + 1] = '\0';
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
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 6) {
						c2 = ControlExp_Menu(newS);
						switch (c2) {
						case 1: {
							strcpy_s(p, "1");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							AddNewExpert(newS, exprt);
							break;
						}
						case 2: {
							strcpy_s(p, "2");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							FileReadTable(newS, "ExpertsTable.txt");
							break;
						}
						case 3: {
							strcpy_s(p, "3");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							EditExpertAdmin(newS, exprt);
							break;
						}
						case 4: {
							strcpy_s(p, "4");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							ifstream f1("Project.txt", ios_base::in);
							if (!f1.is_open() || f1.bad()) {
								cout << "Файл не удалось открыть." << endl;
								strcpy_s(p, "FileError");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
								return;
							}
							else {
								strcpy_s(p, "FileGood");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
							}
							if (f1.peek() == EOF) {
								strcpy_s(p, "Good");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
							}
							else {
								strcpy_s(p, "Невозможно удаление сотрудников, так как на данный момент принимается решение насчет добавления инвестиционного объекта.\nПожалуйста, повторите попытку позже.");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
								f1.close();
								break;
							}
							f1.close();
							DeleteExpertAdmin(newS, exprt);
							break;
						}
						case 5: {
							strcpy_s(p, "5");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							AnswerAdminRequestExpert(mexp, newS, exprt);
							break;
						}
						case 6: {
							strcpy_s(p, "6");
							p[strlen(p) + 1] = '\0';
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
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 4) {
						c2 = ControlInvObj_Menu(newS);
						switch (c2) {
						case 1: {
							strcpy_s(p, "1");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							FileReadTable(newS, "InvObjFreeTable.txt");
							break;
						}
						case 2: {
							strcpy_s(p, "2");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							ifstream f1("Project.txt", ios_base::in);
							if (!f1.is_open() || f1.bad()) {
								cout << "Файл не удалось открыть." << endl;
								strcpy_s(p, "FileError");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
								return;
							}
							else {
								strcpy_s(p, "FileGood");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
							}
							if (f1.peek() == EOF) {
								strcpy_s(p, "Good");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
							}
							else {
								strcpy_s(p, "Невозможно редактирование инвестиционного объекта, так как на данный момент принимается решение\nнасчет добавления инвестиционного объекта.\nПожалуйста, повторите попытку позже.");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
								f1.close();
								break;
							}
							f1.close();
							EditInvObjAdmin(newS, invst_objct);
							break;
						}
						case 3: {
							strcpy_s(p, "3");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							ifstream f1("Project.txt", ios_base::in);
							if (!f1.is_open() || f1.bad()) {
								cout << "Файл не удалось открыть." << endl;
								strcpy_s(p, "FileError");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
								return;
							}
							else {
								strcpy_s(p, "FileGood");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
							}
							if (f1.peek() == EOF) {
								strcpy_s(p, "Good");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
							}
							else {
								strcpy_s(p, "Невозможно удаление инвестиционного объекта, так как на данный момент принимается решение\nнасчет добавления инвестиционного объекта.\nПожалуйста, повторите попытку позже.");
								p[strlen(p) + 1] = '\0';
								send((SOCKET)newS, p, sizeof(p), 0);
								f1.close();
								break;
							}
							f1.close();
							DeleteInvObjAdmin(newS, invst_objct);
							break;
						}
						case 4: {
							strcpy_s(p, "4");
							p[strlen(p) + 1] = '\0';
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
					p[strlen(p) + 1] = '\0';
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
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			flag = 0;
			while (1) {
				cl = AuthorithationClient(clnts, newS);
				if (cl == clnts.end()) {
					strcpy_s(p, "Неверный логин и/или пароль.\nЖелаете повторить попытку? Да(1) или нет(2).");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					p[0] = '/0';
					flag = CheckInt(1, 2, newS);
					if (flag==1) {
						continue;
					}
					else break;
				}

				else {
					strcpy_s(p, "Авторизация прошла успешно.");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
			}
			if (flag==2) {
				break;
			}
			while (c1 != 8) {
				c1 = Client_Menu(newS);
				switch (c1) {
				case 1: {
					strcpy_s(p, "1");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					EditClient(newS,clnts,cl);
					break;
				}
				case 2: { //внос ден.средств
					strcpy_s(p, "2");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					AddMoneyClient(newS, clnts, cl);
					break;
				}
				case 3: {
					strcpy_s(p, "3");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					strcpy_s(p, cl->GetID());
					strcat_s(p,"_portfoliotable.txt");
					FileReadTable(newS, p);
					break;
				}
				case 4: {
					strcpy_s(p, "4");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					ifstream f1("Project.txt", ios_base::in);
					if (!f1.is_open() || f1.bad()) {
						cout << "Файл не удалось открыть." << endl;
						strcpy_s(p, "FileError");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
						return;
					}
					else {
						strcpy_s(p, "FileGood");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
					}
					if (f1.peek() == EOF) {
						strcpy_s(p, "Good");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
					}
					else {
						strcpy_s(p, "NotGood");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
						f1.getline(p, 10, ';');
						if (strcmp(p, cl->GetID()) == 0) {
							strcpy_s(p, "Невозможен разрыв договора, так как на данный момент принимается решение насчет добавления инвестиционного объекта.\nПожалуйста, повторите попытку позже.");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
							f1.close();
							break;
						}
						else {
							strcpy_s(p, "Good");
							p[strlen(p) + 1] = '\0';
							send((SOCKET)newS, p, sizeof(p), 0);
						}
					}
					f1.close();
					AddClientMailRequest(newS,mcl,cl);
					break;
				}
				case 5: {
					strcpy_s(p, "5");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					strcpy_s(p, cl->GetID());
					strcat_s(p, "_contract.txt");
					FileReadTable(newS, p);
					break;
				}
				case 6: {
					strcpy_s(p, "6");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					strcpy_s(p, cl->GetID());
					strcat_s(p, "_clientmail.txt");
					ifstream fl(p, ios_base::in);
					if (fl.peek() == EOF) {
						strcpy_s(p, "Почта пуста.");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
						break;
					}
					else {
						strcpy_s(p, "Почта не пуста.");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
					}
					fl.getline(p, 100, ';');
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					fl.close();
					strcpy_s(p, cl->GetID());
					strcat_s(p, "_clientmail.txt");
					ofstream fl1(p, ios_base::out & ios_base::trunc);
					fl1.close();
					break;
				}
				case 7: {
					strcpy_s(p, "7");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					strcpy_s(p, "Ваша сумма на счету: ");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					_itoa_s(cl->GetAccount(), p, 10);
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					strcpy_s(p, " byn");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				case 8: {
					strcpy_s(p, "8");
					p[strlen(p) + 1] = '\0';
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
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			AddNewInvObj(newS, invst_objct);
			break;
		}
		case 4: {
			strcpy_s(p, "4");
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			flag = 0;
			while (1) {
				exp = AuthorithationExpert(exprt, newS);
				if (exp == exprt.end()) {
					strcpy_s(p, "Неверный логин и/или пароль.\nЖелаете повторить попытку? Да(1) или нет(2).");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					p[0] = '/0';
					flag = CheckInt(1, 2, newS);
					if (flag == 1) {
						continue;
					}
					else break;
				}

				else {
					strcpy_s(p, "Авторизация прошла успешно.");
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
			}
			if (flag == 2) {
				break;
			}
			while (c1 != 5) {
				c1 = Expert_Menu(newS);
				switch (c1) {
				case 1: {
					strcpy_s(p, "1");
					send((SOCKET)newS, p, sizeof(p), 0);
					EditExpert(newS,exprt,exp);
					break;
				}
				case 2: {
					strcpy_s(p, "2");
					send((SOCKET)newS, p, sizeof(p), 0);
					ifstream f1("Project.txt", ios_base::in);
					if (!f1.is_open() || f1.bad()) {
						cout << "Файл не удалось открыть." << endl;
						strcpy_s(p, "FileError");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
						return;
					}
					else {
						strcpy_s(p, "FileGood");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
					}
					if (f1.peek() == EOF) {
						strcpy_s(p, "Проект не создан.");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
						f1.close();
						break;;
					}
					else {
						strcpy_s(p, "FileGood");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
					}
					f1.close();
					ifstream f3("ProjectExperts.txt", ios_base::in);
					if (!f3.is_open() || f3.bad()) {
						cout << "Файл не удалось открыть." << endl;
						strcpy_s(p, "FileError");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
						break;
					}
					else {
						strcpy_s(p, "FileGood");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
					}
					flag = 0;
					if (f3.peek()!=EOF) {
						while (!f3.eof()) {
							p[0] = '/0';
							f3.getline(p, 256, ';'); //Построчное считывание информации в S 
							p[strlen(p) + 1] = '\0';
							if (strcmp(p, exp->GetID()) == 0) {
								flag++;
								break;
							}
						}
					}
					if (flag != 0) {
						strcpy_s(p, "Вы уже проранжировали инвестиционные объекты в данном решении, которое еще не было принято.\nПопробуйте, пожалуйста, позже.");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
						f3.close();
						break;
					}
					else {
						strcpy_s(p, "Good");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
					}
					f3.close();
					ExpertSetMarks(newS,clnts, invst_objct,exp);
					
					break;
				}
				case 3: {
					strcpy_s(p, "3");
					send((SOCKET)newS, p, sizeof(p), 0);
					AddExpertMailRequest(newS, mexp, exp);
					break;
				}
				case 4: {
					strcpy_s(p, "4");
					send((SOCKET)newS, p, sizeof(p), 0);
					strcpy_s(p, exp->GetID());
					strcat_s(p, "_expertmail.txt");
					ifstream fl(p, ios_base::in);
					if (fl.peek() == EOF) {
						strcpy_s(p, "Почта пуста.");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
						break;
					}
					else {
						strcpy_s(p, "Почта не пуста.");
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
					}
					fl.getline(p, 100, ';');
					p[strlen(p) + 1] = '\0';
					send((SOCKET)newS, p, sizeof(p), 0);
					fl.getline(p, 100, ';');
					if (strcmp(p, "Отказано в повышении") == 0 && strcmp(p,"Отказано в увольнении") == 0) {
						p[strlen(p) + 1] = '\0';
						send((SOCKET)newS, p, sizeof(p), 0);
					}
					else {
						strcpy_s(p, "Конец");
						send((SOCKET)newS, p, sizeof(p), 0);
					}
					fl.close();
					strcpy_s(p, exp->GetID());
					strcat_s(p, "_expertmail.txt");
					ofstream fl1(p, ios_base::out & ios_base::trunc);
					fl1.close();
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
		case 5: {
			strcpy_s(p, "5");
			p[strlen(p) + 1] = '\0';
			send((SOCKET)newS, p, sizeof(p), 0);
			closesocket((SOCKET)newS);
			exit(EXIT_SUCCESS);
			break;
		}
		}
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