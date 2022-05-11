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
	b[0] = '/0'; f[0] = '/0';
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
		b[0] = '/0';
		recv(s, b, sizeof(b), 0);
		cout << b;
		err = 1; err1 = 1;
		while (err == 1 || err1 == 1) {
			b[0] = '/0';
			buf[0] = '/0';
			cin.getline(b, 50, '\n');
			send(s, b, sizeof(b), 0);
			recv(s, buf, sizeof(buf), 0);
			err = atoi(buf);
			if (err == 1) {
				cout << "Ошибка ввода. Повторите попытку." << endl;
				cin.clear();
				continue;
			}
			buf[0] = '/0';
			recv(s, buf, sizeof(buf), 0);
			err1 = atoi(buf);
			if (err1 == 1) {
				cout << "Ошибка ввода. Повторите попытку." << endl;
				cin.clear();
				continue;
			}
		}
		k[0] = '/0';
		recv(s, k, sizeof(k), 0);
		t = atoi(k);
		switch (t) {
		case 1: {
			k[0] = '/0';
			recv(s, k, sizeof(k), 0);
			cout << k << endl;
			while (t1 != 5) {
				b[0] = '/0';
				err = 1; err1 = 1;
				recv(s, b, sizeof(b), 0);
				cout << b;
				while (err == 1 || err1 == 1) {
					b[0] = '/0';
					buf[0] = '/0';
					cin.getline(b, 50, '\n');
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
					buf[0] = '/0';
					recv(s, buf, sizeof(buf), 0);
					err1 = atoi(buf);
					if (err1 == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
				}
				k[0] = '/0';
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					while (t2 != 6) {
						b[0] = '/0';
						err = 1; err1 = 1;
						recv(s, b, sizeof(b), 0);
						cout << b;
						while (err == 1 || err1 == 1) {
							b[0] = '/0';
							buf[0] = '/0';
							cin.getline(b, 500, '\n');
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '/0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '/0';
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: { //добавление нового клиента
							b[0] = '/0';  //фамилия
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '/0';
								buf[0] = '/0';
								cin.getline(b, 50, '\n');
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							b[0] = '/0'; //имя
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '/0';
								buf[0] = '/0';
								cin.getline(b, 50, '\n');
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							b[0] = '/0';//отчество
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '/0';
								buf[0] = '/0';
								cin.getline(b, 50, '\n');
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
								b[0] = '/0'; //id
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '/0';
									buf[0] = '/0';
									cin.getline(b, 50, '\n');
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
								b[0] = '/0'; //email
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '/0';
									buf[0] = '/0';
									cin.getline(b, 50, '\n');
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
								b[0] = '/0'; //моб.тел.
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '/0';
									buf[0] = '/0';
									cin.getline(b, 50, '\n');
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
							b[0] = '/0'; //сумма вложения
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '/0';
								buf[0] = '/0';
								cin.getline(b, 50, '\n');
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
								b[0] = '/0'; //расчетный счет
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '/0';
									buf[0] = '/0';
									cin.getline(b, 50, '\n');
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
								b[0] = '/0'; //унп
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '/0';
									buf[0] = '/0';
									cin.getline(b, 50, '\n');
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
								b[0] = '/0'; //пароль
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '/0';
									buf[0] = '/0';
									cin.getline(b, 50, '\n');
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
							b[0] = '/0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '/0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '/0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							b[0] = '/0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "Ошибка сервера." << endl;
								return 0;
							}
							break;
						}
						case 2: { //вывод таблицы с клиентами на экран
							while (1) {
								b[0] = '/0';
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
							b[0] = '/0';
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '/0';
								buf[0] = '/0';
								cin.getline(b, 50, '\n');
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							b[0] = '/0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "Данный клиент не зарегистрирован в базе.") == 0) {
								cout << b << endl;
								break;
							}
							while (t3 != 8) {
								b[0] = '/0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								b[0] = '/0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								b[0] = '/0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "Ошибка сервера." << endl;
									return 0;
								}
								b[0] = '/0';
								err = 1; err1 = 1;
								recv(s, b, sizeof(b), 0);
								cout << b;
								while (err == 1 || err1 == 1) {
									b[0] = '/0';
									buf[0] = '/0';
									cin.getline(b, 50, '\n');
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
										continue;
									}
									buf[0] = '/0';
									recv(s, buf, sizeof(buf), 0);
									err1 = atoi(buf);
									if (err1 == 1) {
										cout << "Ошибка ввода. Повторите попытку." << endl;
										cin.clear();
										continue;
									}
								}
								k[0] = '/0';
								recv(s, k, sizeof(k), 0);
								t3 = atoi(k);
								switch (t3) {
								case 1: { //редакт. фамилии
									buf[0] = '/0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '/0';
										buf[0] = '/0';
										cin.getline(b, 50, '\n');
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
									buf[0] = '/0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '/0';
										buf[0] = '/0';
										cin.getline(b, 50, '\n');
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
									buf[0] = '/0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									err = 1;
									while (err == 1) {
										b[0] = '/0';
										buf[0] = '/0';
										cin.getline(b, 50, '\n');
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
										b[0] = '/0'; //моб.тел.
										recv(s, b, sizeof(b), 0);
										cout << b;
										err = 1;
										while (err == 1) {
											b[0] = '/0';
											buf[0] = '/0';
											cin.getline(b, 50, '\n');
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
									buf[0] = '/0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									break;
								}
								case 6: {
									buf[0] = '/0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
									break;
								}
								case 7: {
									buf[0] = '/0';
									recv(s, buf, sizeof(buf), 0);
									cout << buf;
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
							b[0] = '/0';
							recv(s, b, sizeof(b), 0);
							cout << b;
							err = 1;
							while (err == 1) {
								b[0] = '/0';
								buf[0] = '/0';
								cin.getline(b, 50, '\n');
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "Ошибка ввода. Повторите попытку." << endl;
									cin.clear();
								}
							}
							while (1) {
								b[0] = '/0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "Данный клиент не зарегистрирован в базе.") == 0) {
									cout << b << endl;
									break;
								}
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
							break;
						}
						}
					}
					t2 = 0;
					break;
				}
				case 2: {
					while (t2 != 3) {
						b[0] = '/0';
						err = 1; err1 = 1;
						recv(s, b, sizeof(b), 0);
						cout << b;
						while (err == 1 || err1 == 1) {
							b[0] = '/0';
							buf[0] = '/0';
							cin.getline(b, 50, '\n');
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '/0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '/0';
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
						b[0] = '/0';
						err = 1; err1 = 1;
						recv(s, b, sizeof(b), 0);
						cout << b;
						while (err == 1 || err1 == 1) {
							b[0] = '/0';
							buf[0] = '/0';
							cin.getline(b, 50, '\n');
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '/0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '/0';
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
						case 4: {
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
						b[0] = '/0';
						err = 1; err1 = 1;
						recv(s, b, sizeof(b), 0);
						cout << b;
						while (err == 1 || err1 == 1) {
							b[0] = '/0';
							buf[0] = '/0';
							cin.getline(b, 50, '\n');
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '/0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "Ошибка ввода. Повторите попытку." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '/0';
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
			k[0] = '/0';
			recv(s, k, sizeof(k), 0);
			cout << k << endl;
			while (t1 != 5) {
				b[0] = '/0';
				err = 1; err1 = 1;
				recv(s, b, sizeof(b), 0);
				cout << b;
				while (err == 1 || err1 == 1) {
					b[0] = '/0';
					buf[0] = '/0';
					cin.getline(b, 50, '\n');
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
					buf[0] = '/0';
					recv(s, buf, sizeof(buf), 0);
					err1 = atoi(buf);
					if (err1 == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
				}
				k[0] = '/0';
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					break;
				}
				case 2: {
					break;
				}
				case 3: {
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
		case 3: {
			k[0] = '/0';
			recv(s, k, sizeof(k), 0);
			cout << k << endl;
			break;
		}
		case 4: {
			k[0] = '/0';
			recv(s, k, sizeof(k), 0);
			cout << k << endl;
			while (t1 != 3) {
				err = 1; err1 = 1;
				b[0] = '/0';
				recv(s, b, sizeof(b), 0);
				cout << b;
				while (err == 1 || err1 == 1) {
					b[0] = '/0';
					buf[0] = '/0';
					cin.getline(b, 50, '\n');
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
					buf[0] = '/0';
					recv(s, buf, sizeof(buf), 0);
					err1 = atoi(buf);
					if (err1 == 1) {
						cout << "Ошибка ввода. Повторите попытку." << endl;
						cin.clear();
						continue;
					}
				}
				k[0] = '/0';
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
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