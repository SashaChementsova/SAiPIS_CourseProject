#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WORD wVersionRequested;
	WSADATA wsaData;
	int err, err1 = 1, t, t1 = 0, t2 = 0, t3 = 0;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
		return -1;
	struct sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(1280);
	peer.sin_addr.s_addr = inet_addr("127.0.0.1");
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	connect(s, (struct sockaddr*)&peer, sizeof(peer));
	char b[500], buf[500], f[500], k[500];
	b[0] = '\0'; f[0] = '\0';
	recv(s, b, sizeof(b), 0);
	if (strcmp(b, "FileError") == 0) {
		cout << "Ошибка сервера." << endl;
		return 0;
	}
	recv(s, b, sizeof(b), 0);
	if (strcmp(b, "FileError") == 0) {
		cout << "Ошибка сервера." << endl;
		return 0;
	}
	while (1) {
		b[0] = '\0';
		recv(s, b, sizeof(b), 0);
		cout << b;
		err = 1; err1 = 1;
		while (err == 1 || err1 == 1) {
			b[0] = '\0';
			buf[0] = '\0';
			cin.getline(b, 50, '\n');
			b[strlen(b) + 1] = '\0';
			send(s, b, sizeof(b), 0);
			recv(s, buf, sizeof(buf), 0);
			err = atoi(buf);
			if (err == 1) {
				cout << "Ошибка ввода. Повторите попытку." << endl;
				cin.clear();
				continue;
			}
			buf[0] = '\0';
			recv(s, buf, sizeof(buf), 0);
			err1 = atoi(buf);
			if (err1 == 1) {
				cout << "Ошибка ввода. Повторите попытку." << endl;
				cin.clear();
				continue;
			}
		}
		k[0] = '\0';
		recv(s, k, sizeof(k), 0);
		t = atoi(k);
		switch (t) {
		case 1: {
			k[0] = '\0';
			recv(s, k, sizeof(k), 0);
			cout << k << endl;
			while (t1 != 5) {
				b[0] = '\0';
				err = 1; err1 = 1;
				recv(s, b, sizeof(b), 0);
				cout << b;
				while (err == 1 || err1 == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 50, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					err1 = atoi(buf);
					if (err1 == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
				}
				k[0] = '\0';
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					while (t2 != 9) {
						b[0] = '\0';
						err = 1; err1 = 1;
						recv(s, b, sizeof(b), 0);
						cout << b;
						while (err == 1 || err1 == 1) {
							b[0] = '\0';
							buf[0] = '\0';
							cin.getline(b, 500, '\n');
							b[strlen(b) + 1] = '\0';
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: { //добавление нового клиента
							b[0] = '\0';  //фамилия
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							b[0] = '\0'; //имя
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							b[0] = '\0';//отчество
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //email
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //моб.тел.
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							b[0] = '\0'; //сумма вложения
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //расчетный счет
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //унп
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //пароль
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}

							break;
						}
						case 2: { //вывод таблицы с клиентами на экран
							while (1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "EndOfFile") == 0) {
									break;
								}
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								if (strcmp(b, "FileEmpty") == 0) {
									cout << "Клиентская база пуста." << endl;
									break;
								}
								cout << b << endl;
							}
							break;
						}
						case 3: {
							break;
						}
						case 4: { //редактирование
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //получение ФИО для поиска
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "Есть несколько клиентов с таким ФИО.\nПожалуйста, введите id нужного Вам клиента: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //получение id для поиска
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "В базе не зарегистрирован ни один клиент.") == 0) {
									cout << b << endl;
									t3 = 1;
									continue;
								}
								else if (strcmp(b, "Данный клиент не зарегистрирован в базе. Желаете ли Вы повторить ввод ФИО? Да(1) или нет(2).") == 0) {
									cout << b << endl;
									b[0] = '\0';
									err = 1; err1 = 1;
									while (err == 1 || err1 == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										t3 = 1;
									}
									continue;
								}
								break;
							}
							if (t3 == 1) {
								t3 = 0;
								break;
							}
							if (strcmp(b, "В базе не зарегистрирован ни один клиент.") == 0) {
								t3 = 0;
								break;
							}
							while (t3 != 8) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								b[0] = '\0';
								err = 1; err1 = 1;
								recv(s, b, sizeof(b), 0);
								cout << b;
								while (err == 1 || err1 == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
										continue;
									}
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									err1 = atoi(buf);
									if (err1 == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
										continue;
									}
								}
								k[0] = '\0';
								recv(s, k, sizeof(k), 0);
								t3 = atoi(k);
								switch (t3) {
								case 1: { //редакт. фамилии
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 2: { //редакт.имени
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 3: { //редакт. отчества
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 4: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //редакт. моб.тел.
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											b[strlen(b) + 1] = '\0';
											send(s, b, sizeof(b), 0);
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										f[0] = '\0';
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									break;
								}
								case 5: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //редакт. email
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											b[strlen(b) + 1] = '\0';
											send(s, b, sizeof(b), 0);
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									break;
								}
								case 6: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //редактир. расчетный счет
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											b[strlen(b) + 1] = '\0';
											send(s, b, sizeof(b), 0);
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									break;
								}
								case 7: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //редакт. унп
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											send(s, b, sizeof(b), 0);
											b[strlen(b) + 1] = '\0';
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									break;
								}
								case 8: {
									break;
								}
								}
							}
							t3 = 0;
							break;
						}
						case 5: { //вывод контракта с опред.клиентом на экран
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //получение ФИО для поиска
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "Есть несколько клиентов с таким ФИО. Пожалуйста, введите id нужного Вам клиента: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //получение id для поиска
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
								}
								while (1) {
									b[0] = '\0';
									recv(s, b, sizeof(b), 0);
									if (strcmp(b, "В базе не зарегистрирован ни один клиент.") == 0) {
										cout << b << endl;
										t3 = 1;
										break;
									}
									if (strcmp(b, "Данный клиент не зарегистрирован в базе. Желаете ли Вы повторить ввод ФИО? Да(1) или нет(2).") == 0) {
										cout << b << endl;
										b[0] = '\0';
										err = 1; err1 = 1;
										while (err == 1 || err1 == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											b[strlen(b) + 1] = '\0';
											send(s, b, sizeof(b), 0);
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
												continue;
											}
											buf[0] = '\0';
											recv(s, buf, sizeof(buf), 0);
											err1 = atoi(buf);
											if (err1 == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
												continue;
											}
										}
										if (strcmp(b, "2") == 0) {
											t3 = 1;
										}
										break;
									}
									if (strcmp(b, "EndOfFile") == 0) {
										t3 = 1;
										break;
									}
									if (strcmp(b, "FileError") == 0) {
										cout << "Ошибка сервера." << endl;
										return 0;
									}
									if (strcmp(b, "FileEmpty") == 0) {
										cout << "Клиентская база пуста." << endl;
										t3 = 1;
										break;
									}
									cout << b << endl;
								}
							}
							t3 = 0;
							break;
						}
						case 6: {//фильтрация и сортировка по денежной сумме вклада
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "Клиентская база пуста.") == 0) {
								cout << b << endl;
								break;
							}
							while (t3 != 3) {
								err = 1; err1 = 1;
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								while (err == 1 || err1 == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
										continue;
									}
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									err1 = atoi(buf);
									if (err1 == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
										continue;
									}
								}
								k[0] = '\0';
								recv(s, k, sizeof(k), 0);
								t3 = atoi(k);
								switch (t3) {
								case 1: {
									b[0] = '\0'; //нижняя раница фильтрации
									recv(s, b, sizeof(b), 0);
									cout << b;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									b[0] = '\0'; //верхняя граница фильтрации
									recv(s, b, sizeof(b), 0);
									cout << b;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									b[0] = '\0';
									recv(s, b, sizeof(b), 0);
									if (strcmp(b, "Клиентов с суммой вложения в таком диапазоне нет.") == 0) {
										cout << b << endl;
										break;
									}
									b[0] = '\0';
									recv(s, b, sizeof(b), 0);
									if (strcmp(b, "FileError") == 0) {
										cout << "Ошибка сервера." << endl;
										return 0;
									}
									while (1) {
										b[0] = '\0';
										recv(s, b, sizeof(b), 0);
										if (strcmp(b, "EndOfFile") == 0) {
											break;
										}
										if (strcmp(b, "FileError") == 0) {
											cout << "Ошибка сервера." << endl;
											return 0;
										}
										if (strcmp(b, "FileEmpty") == 0) {
											cout << "Клиентская база пуста." << endl;
											break;
										}
										cout << b << endl;
									}
									break;
								}
								case 2: { //сортировка от максимально ден.вклада к минимальному
									b[0] = '\0';
									recv(s, b, sizeof(b), 0);
									if (strcmp(b, "FileError") == 0) {
										cout << "Ошибка сервера." << endl;
										return 0;
									}
									while (1) {
										b[0] = '\0';
										recv(s, b, sizeof(b), 0);
										if (strcmp(b, "EndOfFile") == 0) {
											break;
										}
										if (strcmp(b, "FileError") == 0) {
											cout << "Ошибка сервера." << endl;
											return 0;
										}
										if (strcmp(b, "FileEmpty") == 0) {
											cout << "Клиентская база пуста." << endl;
											break;
										}
										cout << b << endl;
									}
									break;
								}
								case 3: {
									break;
								}
								}
							}
							t3 = 0;
							break;
						}
						case 7: {
							break;
						}
						case 8: {
							break;
						}
						case 9: {
							break;
						}
						}
					}
					t2 = 0;
					break;
				}
				case 2: {
					while (t2 != 3) {
						b[0] = '\0';
						err = 1; err1 = 1;
						recv(s, b, sizeof(b), 0);
						cout << b;
						while (err == 1 || err1 == 1) {
							b[0] = '\0';
							buf[0] = '\0';
							cin.getline(b, 50, '\n');
							b[strlen(b) + 1] = '\0';
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: {
							break;
						}
						case 2: {
							break;
						}
						case 3: {
							break;
						}
						}
					}
					t2 = 0;
					break;
				}
				case 3: {
					while (t2 != 5) {
						b[0] = '\0';
						err = 1; err1 = 1;
						recv(s, b, sizeof(b), 0);
						cout << b;
						while (err == 1 || err1 == 1) {
							b[0] = '\0';
							buf[0] = '\0';
							cin.getline(b, 50, '\n');
							b[strlen(b) + 1] = '\0';
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: {  //добавление эксперта
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							if (strcmp(buf, "Уже имеется пять экспертов. Добавление нового эксперта невозможно.") == 0) {
								cout << buf << endl;
								break;
							}
							b[0] = '\0';  //фамилия
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							b[0] = '\0'; //имя
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							b[0] = '\0';//отчество
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							b[0] = '\0';//дата рождения
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							b[0] = '\0';//позиция в компании
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							b[0] = '\0';//зарплата
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //стаж
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //email
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //моб.тел.
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //унп
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //пароль
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							break;
						}
						case 2: {  //вывод таблицы с экспертами
							while (1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "EndOfFile") == 0) {
									break;
								}
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								if (strcmp(b, "FileEmpty") == 0) {
									cout << "Клиентская база пуста." << endl;
									break;
								}
								cout << b << endl;
							}
							break;
						}
						case 3: {
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //получение ФИО для поиска
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "Есть несколько экспертов с таким ФИО.\nПожалуйста, введите id нужного Вам эксперта: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //получение id для поиска
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "В базе не зарегистрирован ни один эксперт.") == 0) {
									cout << b << endl;
									t3 = 1;
									continue;
								}
								else if (strcmp(b, "Данный эксперт не зарегистрирован в базе. Желаете ли Вы повторить ввод ФИО? Да(1) или нет(2).") == 0) {
									cout << b << endl;
									b[0] = '\0';
									err = 1; err1 = 1;
									while (err == 1 || err1 == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										t3 = 1;
									}
									continue;
								}
								break;
							}
							if (t3 == 1) {
								t3 = 0;
								break;
							}
							if (strcmp(b, "В базе не зарегистрирован ни один эксперт.") == 0) {
								t3 = 0;
								break;
							}
							while (t3 != 11) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								b[0] = '\0';
								err = 1; err1 = 1;
								recv(s, b, sizeof(b), 0);
								cout << b;
								while (err == 1 || err1 == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
										continue;
									}
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									err1 = atoi(buf);
									if (err1 == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
										continue;
									}
								}
								k[0] = '\0';
								recv(s, k, sizeof(k), 0);
								t3 = atoi(k);
								switch (t3) {
								case 1: { //редакт. фамилии
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 2: { //редакт.имени
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 3: { //редакт. отчества
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 4: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //редакт. моб.тел.
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											b[strlen(b) + 1] = '\0';
											send(s, b, sizeof(b), 0);
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										f[0] = '\0';
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									break;
								}
								case 5: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //редакт. email
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											b[strlen(b) + 1] = '\0';
											send(s, b, sizeof(b), 0);
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									break;
								}
								case 6: { //позиция в компании
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 7: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //редакт. унп
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											send(s, b, sizeof(b), 0);
											b[strlen(b) + 1] = '\0';
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									break;
								}
								case 8: {  // редакт. зарплата
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 9: {//дата рождения
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0';
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											b[strlen(b) + 1] = '\0';
											send(s, b, sizeof(b), 0);
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									break;
								}
								case 10: {//редакт. стаж
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; 
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											b[strlen(b) + 1] = '\0';
											send(s, b, sizeof(b), 0);
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									break;
								}
								case 11: {
									break;
								}
								}
							}
							t3 = 0;
							break;
						}
						case 4: {
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //получение ФИО для поиска
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "Есть несколько экспертов с таким ФИО.\nПожалуйста, введите id нужного Вам эксперта: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //получение id для поиска
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "В базе не зарегистрирован ни один эксперт.") == 0) {
									cout << b << endl;
									t3 = 1;
									continue;
								}
								else if (strcmp(b, "Данный эксперт не зарегистрирован в базе. Желаете ли Вы повторить ввод ФИО? Да(1) или нет(2).") == 0) {
									cout << b << endl;
									b[0] = '\0';
									err = 1; err1 = 1;
									while (err == 1 || err1 == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										t3 = 1;
									}
									continue;
								}
								break;
							}
							if (t3 == 1) {
								t3 = 0;
								break;
							}
							if (strcmp(b, "В базе не зарегистрирован ни один эксперт.") == 0) {
								t3 = 0;
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							cout << b << endl;
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							break;
						}
						case 5: {
							break;
						}
						}
					}
					t2 = 0;
					break;
				}
				case 4: {
					while (t2 != 4) {
						b[0] = '\0';
						err = 1; err1 = 1;
						recv(s, b, sizeof(b), 0);
						cout << b;
						while (err == 1 || err1 == 1) {
							b[0] = '\0';
							buf[0] = '\0';
							cin.getline(b, 50, '\n');
							b[strlen(b) + 1] = '\0';
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: { //вывод таблицы с свободными инвест.объектами
							while (1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "EndOfFile") == 0) {
									break;
								}
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								if (strcmp(b, "FileEmpty") == 0) {
									cout << "Клиентская база пуста." << endl;
									break;
								}
								cout << b << endl;
							}
							break;
						}
						case 2: {
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //получение названия инв.об. для поиска
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "Есть несколько инвестиционных объектов с таким названием.\nПожалуйста, введите id нужного Вам инвестиционного объекта: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //получение id для поиска
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "В базе не зарегистрирован ни один инвестиционный объект.") == 0) {
									cout << b << endl;
									t3 = 1;
									continue;
								}
								else if (strcmp(b, "Данный инвестиционный объект не зарегистрирован в базе. Желаете ли Вы повторить ввод названия? Да(1) или нет(2).") == 0) {
									cout << b << endl;
									b[0] = '\0';
									err = 1; err1 = 1;
									while (err == 1 || err1 == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										t3 = 1;
									}
									continue;
								}
								break;
							}
							if (t3 == 1) {
								t3 = 0;
								break;
							}
							if (strcmp(b, "В базе не зарегистрирован ни один инвестиционный объект.") == 0) {
								t3 = 0;
								break;
							}
							while (t3 != 9) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								b[0] = '\0';
								err = 1; err1 = 1;
								recv(s, b, sizeof(b), 0);
								cout << b;
								while (err == 1 || err1 == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
										continue;
									}
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									err1 = atoi(buf);
									if (err1 == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
										continue;
									}
								}
								k[0] = '\0';
								recv(s, k, sizeof(k), 0);
								t3 = atoi(k);
								switch (t3) {
								case 1: { //редакт. названия
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 2: { //редакт.владельца
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 3: { 
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //редакт. email
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											b[strlen(b) + 1] = '\0';
											send(s, b, sizeof(b), 0);
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									break;
								}
								case 4: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //редакт. моб.тел.
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											b[strlen(b) + 1] = '\0';
											send(s, b, sizeof(b), 0);
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										f[0] = '\0';
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									break;
								}
								case 5: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //редакт. унп
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '\0';
											buf[0] = '\0';
											cin.getline(b, 50, '\n');
											send(s, b, sizeof(b), 0);
											b[strlen(b) + 1] = '\0';
											recv(s, buf, sizeof(buf), 0);
											err = atoi(buf);
											if (err == 1) {
												cout << "Ошибка ввода. Повторите попытку." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									
									break;
								}
								case 6: { //редакт.сферы
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 7: {//редакт.периода окупаемости
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 8: {  // редакт. рентабельности
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
									break;
								}
								case 9: {
									break;
								}
								}
							}
							t3 = 0;
							break;
						}
						case 3: {
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //получение названия инв.об. для поиска
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "Есть несколько инвестиционных объектов с таким названием.\nПожалуйста, введите id нужного Вам инвестиционного объекта: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //получение id для поиска
									err = 1;
									while (err == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "В базе не зарегистрирован ни один инвестиционный объект.") == 0) {
									cout << b << endl;
									t3 = 1;
									continue;
								}
								else if (strcmp(b, "Данный инвестиционный объект не зарегистрирован в базе. Желаете ли Вы повторить ввод названия? Да(1) или нет(2).") == 0) {
									cout << b << endl;
									b[0] = '\0';
									err = 1; err1 = 1;
									while (err == 1 || err1 == 1) {
										b[0] = '\0';
										buf[0] = '\0';
										cin.getline(b, 50, '\n');
										b[strlen(b) + 1] = '\0';
										send(s, b, sizeof(b), 0);
										recv(s, buf, sizeof(buf), 0);
										err = atoi(buf);
										if (err == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "Ошибка ввода. Повторите попытку." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										t3 = 1;
									}
									continue;
								}
								break;
							}
							if (t3 == 1) {
								t3 = 0;
								break;
							}
							if (strcmp(b, "В базе не зарегистрирован ни один инвестиционный объект.") == 0) {
								t3 = 0;
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							cout << b << endl;
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							break;
						}
						case 4: {
							break;
						}
						}
					}
					t2 = 0;
					break;
				}
				case 5: {
					break;
				}
				}
			}
			t1 = 0;
			break;
		}
		case 2: {
			while (1) {
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1; //получение логина
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 100, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
					}
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1; //получение пароля
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 100, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
					}
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				if (strcmp(b, "Неверный логин и/или пароль.\nЖелаете повторить попытку? Да(1) или нет(2).") == 0) {
					cout << b << endl;
					b[0] = '\0';
					err = 1; err1 = 1;
					while (err == 1 || err1 == 1) {
						b[0] = '\0';
						buf[0] = '\0';
						cin.getline(b, 50, '\n');
						b[strlen(b) + 1] = '\0';
						send(s, b, sizeof(b), 0);
						recv(s, buf, sizeof(buf), 0);
						err = atoi(buf);
						if (err == 1) {
							cout << "Ошибка ввода. Повторите попытку." << endl;
							cin.clear();
							continue;
						}
						buf[0] = '\0';
						recv(s, buf, sizeof(buf), 0);
						err1 = atoi(buf);
						if (err1 == 1) {
							cout << "Ошибка ввода. Повторите попытку." << endl;
							cin.clear();
							continue;
						}
					}
					if (strcmp(b, "2") == 0) {
						break;
					}
					else continue;
				}
				else break;
			}
			if (strcmp(b, "2") == 0) {
				break;
			}
			while (t1 != 8) {
				b[0] = '\0';
				err = 1; err1 = 1;
				recv(s, b, sizeof(b), 0);
				cout << b;
				while (err == 1 || err1 == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 50, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					err1 = atoi(buf);
					if (err1 == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
				}
				k[0] = '\0';
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					t3 = 0;
					while (t3 != 9) {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "Ошибка сервера." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "Ошибка сервера." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "Ошибка сервера." << endl;
							return 0;
						}
						b[0] = '\0';
						err = 1; err1 = 1;
						recv(s, b, sizeof(b), 0);
						cout << b;
						while (err == 1 || err1 == 1) {
							b[0] = '\0';
							buf[0] = '\0';
							cin.getline(b, 50, '\n');
							b[strlen(b) + 1] = '\0';
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						t3 = atoi(k);
						switch (t3) {
						case 1: { //редакт. фамилии
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							cout << buf;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							break;
						}
						case 2: { //редакт.имени
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							cout << buf;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							break;
						}
						case 3: { //редакт. отчества
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							cout << buf;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							break;
						}
						case 4: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //редакт. моб.тел.
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							break;
						}
						case 5: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //редакт. email
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							break;
						}
						case 6: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //редактир. расчетный счет
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							break;
						}
						case 7: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //редакт. унп
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									send(s, b, sizeof(b), 0);
									b[strlen(b) + 1] = '\0';
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							break;
						}
						case 8: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //редакт. пароля
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							break;
						}
						case 9: {
							break;
						}
						}
					}
					t3 = 0;
					break;
				}
				case 2: {
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					cout << b;
					err = 1;
					while (err == 1) {
						b[0] = '\0';
						buf[0] = '\0';
						cin.getline(b, 50, '\n');
						b[strlen(b) + 1] = '\0';
						send(s, b, sizeof(b), 0);
						recv(s, buf, sizeof(buf), 0);
						err = atoi(buf);
						if (err == 1) {
							cout << "Ошибка ввода. Повторите попытку." << endl;
							cin.clear();
						}
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					cout << b;
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "Ошибка сервера." << endl;
						return 0;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "Ошибка сервера." << endl;
						return 0;
					}
					break;
				}
				case 3: {
					break;
				}
				case 4: {
					
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					cout << b << endl;
					if (strcmp(b, "Данный запрос уже был отправлен ранее.") == 0) {
						break;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "Ошибка сервера." << endl;
						return 0;
					}
					break;
				}
				case 5: {
					while (1) {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "EndOfFile") == 0) {
							break;
						}
						if (strcmp(b, "FileError") == 0) {
							cout << "Ошибка сервера." << endl;
							return 0;
						}
						if (strcmp(b, "FileEmpty") == 0) {
							cout << "Клиентская база пуста." << endl;
							break;
						}
						cout << b << endl;
					}
					break;
				}
				case 6: {
					break;
				}
				case 7: {
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					cout << buf;
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					cout << buf;
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					cout << buf<<endl;
					break;
				}
				case 8: {
					break;
				}
				}
			}
			t1 = 0;
			break;
		}
		case 3: {  //добавление инвест.объекта
			b[0] = '\0';  //название инвест.объекта
			recv(s, b, sizeof(b), 0);
			cout << b;
			err = 1;
			while (err == 1) {
				b[0] = '\0';
				buf[0] = '\0';
				cin.getline(b, 50, '\n');
				b[strlen(b) + 1] = '\0';
				send(s, b, sizeof(b), 0);
				recv(s, buf, sizeof(buf), 0);
				err = atoi(buf);
				if (err == 1) {
					cout << "Ошибка ввода. Повторите попытку." << endl;
					cin.clear();
				}
			}
			b[0] = '\0';//владелец
			recv(s, b, sizeof(b), 0);
			cout << b;
			err = 1;
			while (err == 1) {
				b[0] = '\0';
				buf[0] = '\0';
				cin.getline(b, 50, '\n');
				b[strlen(b) + 1] = '\0';
				send(s, b, sizeof(b), 0);
				recv(s, buf, sizeof(buf), 0);
				err = atoi(buf);
				if (err == 1) {
					cout << "Ошибка ввода. Повторите попытку." << endl;
					cin.clear();
				}
			}
			f[0] = '\0';
			while (strcmp(f, "0") != 0) {
				b[0] = '\0'; //email
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1;
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 50, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
					}
				}
				recv(s, f, sizeof(f), 0);
				if (strcmp(f, "0") != 0) {
					cout << f << endl;
				}
			}
			f[0] = '\0';//моб.тел.
			while (strcmp(f, "0") != 0) {
				b[0] = '\0'; 
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1;
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 50, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
					}
				}
				recv(s, f, sizeof(f), 0);
				if (strcmp(f, "0") != 0) {
					cout << f << endl;
				}
			}
			f[0] = '\0';//унп
			while (strcmp(f, "0") != 0) {
				b[0] = '\0'; 
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1;
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 50, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
					}
				}
				recv(s, f, sizeof(f), 0);
				if (strcmp(f, "0") != 0) {
					cout << f << endl;
				}
			}
			b[0] = '\0';  //сфера деятельности
			recv(s, b, sizeof(b), 0);
			cout << b;
			err = 1;
			while (err == 1) {
				b[0] = '\0';
				buf[0] = '\0';
				cin.getline(b, 50, '\n');
				b[strlen(b) + 1] = '\0';
				send(s, b, sizeof(b), 0);
				recv(s, buf, sizeof(buf), 0);
				err = atoi(buf);
				if (err == 1) {
					cout << "Ошибка ввода. Повторите попытку." << endl;
					cin.clear();
				}
			}
			b[0] = '\0';  //период окупаемости
			recv(s, b, sizeof(b), 0);
			cout << b;
			err = 1;
			while (err == 1) {
				b[0] = '\0';
				buf[0] = '\0';
				cin.getline(b, 50, '\n');
				b[strlen(b) + 1] = '\0';
				send(s, b, sizeof(b), 0);
				recv(s, buf, sizeof(buf), 0);
				err = atoi(buf);
				if (err == 1) {
					cout << "Ошибка ввода. Повторите попытку." << endl;
					cin.clear();
				}
			}
			b[0] = '\0';//рентабельность
			recv(s, b, sizeof(b), 0);
			cout << b;
			err = 1; err1 = 1;
			while (err == 1 || err1 == 1) {
				b[0] = '\0';
				buf[0] = '\0';
				cin.getline(b, 50, '\n');
				b[strlen(b) + 1] = '\0';
				send(s, b, sizeof(b), 0);
				recv(s, buf, sizeof(buf), 0);
				err = atoi(buf);
				if (err == 1) {
					cout << "Ошибка ввода. Повторите попытку." << endl;
					cin.clear();
					continue;
				}
				buf[0] = '\0';
				recv(s, buf, sizeof(buf), 0);
				err1 = atoi(buf);
				if (err1 == 1) {
					cout << "Ошибка ввода. Повторите попытку." << endl;
					cin.clear();
					continue;
				}
			}
			b[0] = '\0';
			recv(s, b, sizeof(b), 0);
			if (strcmp(b, "FileError") == 0) {
				cout << "Ошибка сервера." << endl;
				return 0;
			}
			b[0] = '\0';
			recv(s, b, sizeof(b), 0);
			if (strcmp(b, "FileError") == 0) {
				cout << "Ошибка сервера." << endl;
				return 0;
			}
			break;
		}
		case 4: {
			k[0] = '\0';
			while (1) {
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1; //получение логина
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 100, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
					}
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1; //получение пароля
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 100, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
					}
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				if (strcmp(b, "Неверный логин и/или пароль.\nЖелаете повторить попытку? Да(1) или нет(2).") == 0) {
					cout << b << endl;
					b[0] = '\0';
					err = 1; err1 = 1;
					while (err == 1 || err1 == 1) {
						b[0] = '\0';
						buf[0] = '\0';
						cin.getline(b, 50, '\n');
						b[strlen(b) + 1] = '\0';
						send(s, b, sizeof(b), 0);
						recv(s, buf, sizeof(buf), 0);
						err = atoi(buf);
						if (err == 1) {
							cout << "Ошибка ввода. Повторите попытку." << endl;
							cin.clear();
							continue;
						}
						buf[0] = '\0';
						recv(s, buf, sizeof(buf), 0);
						err1 = atoi(buf);
						if (err1 == 1) {
							cout << "Ошибка ввода. Повторите попытку." << endl;
							cin.clear();
							continue;
						}
					}
					if (strcmp(b, "2") == 0) {
						break;
					}
					else continue;
				}
				else break;
			}
			if (strcmp(b, "2") == 0) {
				break;
			}
			while (t1 != 5) {
				err = 1; err1 = 1;
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				cout << b;
				while (err == 1 || err1 == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 50, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					err1 = atoi(buf);
					if (err1 == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
				}
				k[0] = '\0';
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					t3 = 0;
					while (t3 != 10) {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "Ошибка сервера." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "Ошибка сервера." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "Ошибка сервера." << endl;
							return 0;
						}
						b[0] = '\0';
						err = 1; err1 = 1;
						recv(s, b, sizeof(b), 0);
						cout << b;
						while (err == 1 || err1 == 1) {
							b[0] = '\0';
							buf[0] = '\0';
							cin.getline(b, 50, '\n');
							b[strlen(b) + 1] = '\0';
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						t3 = atoi(k);
						switch (t3) {
						case 1: { //редакт. фамилии
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							cout << buf;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							break;
						}
						case 2: { //редакт.имени
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							cout << buf;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							break;
						}
						case 3: { //редакт. отчества
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							cout << buf;
							err = 1;
							while (err == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							break;
						}
						case 4: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //редакт. моб.тел.
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							break;
						}
						case 5: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //редакт. email
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							break;
						}
						case 6: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //редакт. унп
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									send(s, b, sizeof(b), 0);
									b[strlen(b) + 1] = '\0';
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							break;
						}
						case 7: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //дата рождения
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							break;
						}
						case 8: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //стаж
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							break;
						}
						case 9: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //редакт. пароля
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							break;
						}
						case 10: {
							break;
						}
						}
					}
					t3 = 0;
					break;
				}
				case 2: {
					break;
				}
				case 3: {
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					cout << b << endl;
					err = 1; err1 = 1;
					while (err == 1 || err1 == 1) {
						b[0] = '\0';
						buf[0] = '\0';
						cin.getline(b, 50, '\n');
						b[strlen(b) + 1] = '\0';
						send(s, b, sizeof(b), 0);
						recv(s, buf, sizeof(buf), 0);
						err = atoi(buf);
						if (err == 1) {
							cout << "Ошибка ввода. Повторите попытку." << endl;
							cin.clear();
							continue;
						}
						buf[0] = '\0';
						recv(s, buf, sizeof(buf), 0);
						err1 = atoi(buf);
						if (err1 == 1) {
							cout << "Ошибка ввода. Повторите попытку." << endl;
							cin.clear();
							continue;
						}
					}
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					if (strcmp(buf, "Данный запрос уже был отправлен ранее.") == 0) {
						cout << buf << endl;
						break;
					}
					if (strcmp(b,"1")==0) {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						cout << b;
						err = 1;
						while (err == 1) {
							b[0] = '\0';
							buf[0] = '\0';
							cin.getline(b, 50, '\n');
							b[strlen(b) + 1] = '\0';
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
							}
						}
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "Ошибка сервера." << endl;
						return 0;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					cout << b << endl;
					break;
				}
				case 4: {
					break;
				}
				case 5: {
					break;
				}
				}
			}
			t1 = 0;
			break;
		}
		case 5: {
			system("cls");
			WSACleanup();
			return 0;
		}
		}
	}
}