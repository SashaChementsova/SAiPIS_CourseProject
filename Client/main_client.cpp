#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <conio.h>
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
	recv(s, b, sizeof(b), 0);  //������
	if (strcmp(b, "FileError") == 0) {
		cout << "������ �������." << endl;
		return 0;
	}
	b[0] = '\0';
	recv(s, b, sizeof(b), 0);
	if (strcmp(b, "FileEmpty") != 0) {
		b[0] = '\0';
		recv(s, b, sizeof(b), 0);
		if (strcmp(b, "FileError") == 0) {
			cout << "������ �������." << endl;
			return 0;
		}
	}
	b[0] = '\0';
	recv(s, b, sizeof(b), 0);
	if (strcmp(b, "FileError") == 0) { //�������
		cout << "������ �������." << endl;
		return 0;
	}
	b[0] = '\0';
	recv(s, b, sizeof(b), 0);
	if (strcmp(b, "FileEmpty") != 0) {
		b[0] = '\0';
		recv(s, b, sizeof(b), 0); //�������
		if (strcmp(b, "FileError") == 0) {
			cout << "������ �������." << endl;
			return 0;
		}
	}
	b[0] = '\0';
	recv(s, b, sizeof(b), 0); //���.������
	if (strcmp(b, "FileError") == 0) {
		cout << "������ �������." << endl;
		return 0;
	}
	b[0] = '\0';
	recv(s, b, sizeof(b), 0);
	b[0] = '\0';
	recv(s, b, sizeof(b), 0);
	if (strcmp(b, "FileError") == 0) {
		cout << "������ �������." << endl;
		return 0;
	}
	b[0] = '\0';
	recv(s, b, sizeof(b), 0);
	if (strcmp(b, "FileError") == 0) {
		cout << "������ �������." << endl;
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
				cout << "������ �����. ��������� �������." << endl;
				cin.clear();
				continue;
			}
			buf[0] = '\0';
			recv(s, buf, sizeof(buf), 0);
			err1 = atoi(buf);
			if (err1 == 1) {
				cout << "������ �����. ��������� �������." << endl;
				cin.clear();
				continue;
			}
		}
		k[0] = '\0';
		recv(s, k, sizeof(k), 0);
		system("cls");
		t = atoi(k);
		switch (t) {
		case 1: {
			while (1) {
				b[0] = '\0';
				cout << "�������������" << endl;
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1; //��������� ������
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 100, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
					}
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1; //��������� ������
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					int j = 0;
					b[0] = '\0';
					for (;;) {
						b[j] = _getch();
						if (b[j] == '\r')
							break;
						if (b[j] == '\b') {
							cout << "\b \b";
							j--;
						}
						else if (b[j] != '\0') {
							cout << "*";
							j++;
						}
					}
					b[j] = '\0';
					cout << "\n";
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
					}
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				if (strcmp(b, "FileError") == 0) {
					cout << "������ �������." << endl;
					return 0;
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				if (strcmp(b, "FileError") == 0) {
					cout << "������ �������." << endl;
					return 0;
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				system("cls");
				if (strcmp(b, "�������� ����� �/��� ������.\n������� ��������� �������? ��(1) ��� ���(2).") == 0) {
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
							cout << "������ �����. ��������� �������." << endl;
							cin.clear();
							continue;
						}
						buf[0] = '\0';
						recv(s, buf, sizeof(buf), 0);
						err1 = atoi(buf);
						if (err1 == 1) {
							cout << "������ �����. ��������� �������." << endl;
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
			system("cls");
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
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
						continue;
					}
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					err1 = atoi(buf);
					if (err1 == 1) {
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
						continue;
					}
				}
				k[0] = '\0';
				recv(s, k, sizeof(k), 0);
				system("cls");
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					while (t2 != 8) {
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
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						system("cls");
						t2 = atoi(k);
						switch (t2) {
						case 1: { //���������� ������ �������
							b[0] = '\0';  //�������
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							b[0] = '\0'; //���
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							b[0] = '\0';//��������
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
									cout << "������ �����. ��������� �������." << endl;
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
										cout << "������ �����. ��������� �������." << endl;
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
								b[0] = '\0'; //���.���.
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							b[0] = '\0'; //����� ��������
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //��������� ����
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
										cout << "������ �����. ��������� �������." << endl;
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
								b[0] = '\0'; //���
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
										cout << "������ �����. ��������� �������." << endl;
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
								b[0] = '\0'; //������
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							b[0] = '\0';  //������ � �������
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}

							b[0] = '\0';  //� �������
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}

							b[0] = '\0';//��������
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0'; //������
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							system("cls");
							break;
						}
						case 2: { //����� ������� � ��������� �� �����
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "Good") != 0) {
								cout << b << endl;
								system("pause");
								system("cls");
								break;
							}
							while (1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "EndOfFile") == 0) {
									break;
								}
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								if (strcmp(b, "FileEmpty") == 0) {
									cout << "���������� ���� �����." << endl;
									break;
								}
								cout << b << endl;
							}
							system("pause");
							system("cls");
							break;
						}
						case 3: { //��������������
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //��������� ��� ��� ������
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "���� ��������� �������� � ����� ���.\n����������, ������� id ������� ��� �������: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //��������� id ��� ������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "� ���� �� ��������������� �� ���� ������.") == 0) {
									cout << b << endl;
									t3 = 1;
									system("pause");
									system("cls");
									continue;
								}
								else if (strcmp(b, "������ ������ �� ��������������� � ����. ������� �� �� ��������� ���� ���? ��(1) ��� ���(2).") == 0) {
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										t3 = 1;
									}
									system("cls");
									continue;
								}
								system("cls");
								break;
							}
							if (t3 == 1) {
								t3 = 0;
								system("cls");
								break;
							}
							if (strcmp(b, "� ���� �� ��������������� �� ���� ������.") == 0) {
								t3 = 0;
								system("cls");
								break;
							}
							while (t3 != 8) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
										continue;
									}
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									err1 = atoi(buf);
									if (err1 == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
										continue;
									}
								}
								k[0] = '\0';
								recv(s, k, sizeof(k), 0);
								system("cls");
								t3 = atoi(k);
								switch (t3) {
								case 1: { //������. �������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 2: { //������.�����
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 3: { //������. ��������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 4: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //������. ���.���.
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										f[0] = '\0';
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
									break;
								}
								case 5: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //������. email
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
									break;
								}
								case 6: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //��������. ��������� ����
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
									break;
								}
								case 7: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //������. ���
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
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
						case 4: { //����� ��������� � �����.�������� �� �����
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //��������� ��� ��� ������
									buf[0] = '\0';
									cin.getline(b, 50, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "���� ��������� �������� � ����� ���. ����������, ������� id ������� ��� �������: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //��������� id ��� ������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "� ���� �� ��������������� �� ���� ������.") == 0) {
									cout << b << endl;
									t3 = 1;
									system("pause");
									system("cls");
									break;
								}
								if (strcmp(b, "������ ������ �� ��������������� � ����. ������� �� �� ��������� ���� ���? ��(1) ��� ���(2).") == 0) {
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										t3 = 1;
										system("cls");
										continue;
									}
									system("cls");
									break;
								}
								while (1) {
									t3 = 1;
									b[0] = '\0';
									recv(s, b, sizeof(b), 0);
									if (strcmp(b, "EndOfFile") == 0) {
										t3 = 1;
										break;
									}
									if (strcmp(b, "FileError") == 0) {
										cout << "������ �������." << endl;
										return 0;
									}
									if (strcmp(b, "FileEmpty") == 0) {
										cout << "���������� ���� �����." << endl;
										t3 = 1;
										break;
									}
									cout << b << endl;

								}

								system("pause");
								system("cls");
							}
							t3 = 0;
							break;
						}
						case 5: {//���������� � ���������� �� �������� ����� ������
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "���������� ���� �����.") == 0) {
								cout << b << endl;
								system("pause");
								system("cls");
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
										continue;
									}
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									err1 = atoi(buf);
									if (err1 == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
										continue;
									}
								}
								k[0] = '\0';
								recv(s, k, sizeof(k), 0);
								t3 = atoi(k);
								system("cls");
								switch (t3) {
								case 1: {
									b[0] = '\0'; //������ ������ ����������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									b[0] = '\0'; //������� ������� ����������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									b[0] = '\0';
									recv(s, b, sizeof(b), 0);
									if (strcmp(b, "�������� � ������ �������� � ����� ��������� ���.") == 0) {
										cout << b << endl;
										system("pause");
										system("cls");
										break;
									}
									b[0] = '\0';
									recv(s, b, sizeof(b), 0);
									if (strcmp(b, "FileError") == 0) {
										cout << "������ �������." << endl;
										return 0;
									}
									system("cls");
									while (1) {
										b[0] = '\0';
										recv(s, b, sizeof(b), 0);
										if (strcmp(b, "EndOfFile") == 0) {
											break;
										}
										if (strcmp(b, "FileError") == 0) {
											cout << "������ �������." << endl;
											return 0;
										}
										if (strcmp(b, "FileEmpty") == 0) {
											cout << "���������� ���� �����." << endl;
											break;
										}
										cout << b << endl;
									}
									system("pause");
									system("cls");
									break;
								}
								case 2: { //���������� �� ����������� ���.������ � ������������
									b[0] = '\0';
									recv(s, b, sizeof(b), 0);
									if (strcmp(b, "FileError") == 0) {
										cout << "������ �������." << endl;
										return 0;
									}
									while (1) {
										b[0] = '\0';
										recv(s, b, sizeof(b), 0);
										if (strcmp(b, "EndOfFile") == 0) {
											break;
										}
										if (strcmp(b, "FileError") == 0) {
											cout << "������ �������." << endl;
											return 0;
										}
										if (strcmp(b, "FileEmpty") == 0) {
											cout << "���������� ���� �����." << endl;
											break;
										}
										cout << b << endl;
									}
									system("pause");
									system("cls");
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
						case 6: {
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //��������� ��� ��� ������
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "���� ��������� �������� � ����� ���.\n����������, ������� id ������� ��� �������: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //��������� id ��� ������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "� ���� �� ��������������� �� ���� ������.") == 0) {
									cout << b << endl;
									t3 = 1;
									system("pause");
									system("cls");
									continue;
								}
								else if (strcmp(b, "������ ������ �� ��������������� � ����. ������� �� �� ��������� ���� ���? ��(1) ��� ���(2).") == 0) {
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										system("cls");
										t3 = 1;
									}
									system("cls");
									continue;
								}
								system("cls");
								break;
							}
							if (t3 == 1) {
								system("cls");
								t3 = 0;
								break;
							}
							if (strcmp(b, "� ���� �� ��������������� �� ���� ������.") == 0) {
								t3 = 0;
								system("cls");
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							cout << b << endl;
							while (1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "EndOfFile") == 0) {
									break;
								}
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								if (strcmp(b, "FileEmpty") == 0) {
									cout << "� ������� ������� ��� �� ������ ��������������� �������." << endl;
									break;
								}
								cout << b << endl;
							}
							system("pause");
							system("cls");
							break;
						}
						case 7: {
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							if (strcmp("����� �����.", buf) == 0) {
								cout << buf << endl;
								system("cls");
								break;
							}
							while (1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "EndOfFile") == 0) {
									break;
								}
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								if (strcmp(b, "FileEmpty") == 0) {
									cout << "���������� ���� �����." << endl;
									break;
								}
								cout << b << endl;
							}
							b[0] = '\0';
							err = 1; err1 = 1;
							recv(s, b, sizeof(b), 0);
							cout << b << endl;
							while (err == 1 || err1 == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
									continue;
								}
								buf[0] = '\0';
								recv(s, buf, sizeof(buf), 0);
								err1 = atoi(buf);
								if (err1 == 1) {
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
									continue;
								}
							}
							b[0] = '\0';
							err = 1; err1 = 1;
							recv(s, b, sizeof(b), 0);
							cout << b << endl;
							while (err == 1 || err1 == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
									continue;
								}
								buf[0] = '\0';
								recv(s, buf, sizeof(buf), 0);
								err1 = atoi(buf);
								if (err1 == 1) {
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
									continue;
								}
							}
							if (strcmp(b, "1") == 0) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							system("pause");
							system("cls");
							break;
						}
						case 8: {
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
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						system("cls");
						t2 = atoi(k);
						switch (t2) {
						case 1: {
							while (1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "EndOfFile") == 0) {
									break;
								}
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								if (strcmp(b, "FileEmpty") == 0) {
									cout << "�� ������ ������� ��� �� ���� �������. ����������, ��������� ������� �����." << endl;
									break;
								}
								cout << b << endl;
							}
							system("pause");
							system("cls");
							break;
						}
						case 2: { //������������ �������
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "Good") != 0) {
								cout << b << endl;
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "Good") != 0) {
								cout << b << endl;
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileGood") != 0) {
								cout << b << endl;
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							cout << b << endl;
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //��������� ��� ��� ������
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "���� ��������� �������� � ����� ���.\n����������, ������� id ������� ��� �������: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //��������� id ��� ������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "� ���� �� ��������������� �� ���� ������.") == 0) {
									cout << b << endl;
									t3 = 1;
									system("pause");
									system("cls");
									continue;
								}
								else if (strcmp(b, "������ ������ �� ��������������� � ����. ������� �� �� ��������� ���� ���? ��(1) ��� ���(2).") == 0) {
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										system("pause");
										system("cls");
										t3 = 1;
									}
									system("cls");
									continue;
								}
								break;
							}
							if (t3 == 1) {
								t3 = 0;
								break;
							}
							if (strcmp(b, "� ���� �� ��������������� �� ���� ������.") == 0) {
								t3 = 0;
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "Good") != 0) {
								cout << b << endl;
								system("pause");
								system("cls");
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileGood") != 0) {
								cout << b << endl;
								system("pause");
								system("cls");
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileGood") != 0) {
								cout << b << endl;
								system("pause");
								system("cls");
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							cout << b << endl;
							system("pause");
							system("cls");
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
					while (t2 != 6) {
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
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						system("cls");
						t2 = atoi(k);
						switch (t2) {
						case 1: {  //���������� ��������
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							if (strcmp(buf, "��� ������� ��� ��������. ���������� ������ �������� ����������.") == 0) {
								cout << buf << endl;
								system("pause");
								system("cls");
								break;
							}
							b[0] = '\0';  //�������
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							b[0] = '\0'; //���
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							b[0] = '\0';//��������
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							b[0] = '\0';//���� ��������
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							b[0] = '\0';//������� � ��������
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							b[0] = '\0';//��������
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //����
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
										cout << "������ �����. ��������� �������." << endl;
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
										cout << "������ �����. ��������� �������." << endl;
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
								b[0] = '\0'; //���.���.
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
										cout << "������ �����. ��������� �������." << endl;
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
								b[0] = '\0'; //���
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
										cout << "������ �����. ��������� �������." << endl;
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
								b[0] = '\0'; //������
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
										cout << "������ �����. ��������� �������." << endl;
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
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							system("cls");
							break;
						}
						case 2: {  //����� ������� � ����������
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "Good") != 0) {
								cout << b << endl;
								system("pause");
								system("cls");
								break;
							}
							while (1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "EndOfFile") == 0) {
									break;
								}
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								if (strcmp(b, "FileEmpty") == 0) {
									cout << "���������� ���� �����." << endl;
									break;
								}
								cout << b << endl;
							}
							system("pause");
							system("cls");
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
									b[0] = '\0';  //��������� ��� ��� ������
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "���� ��������� ��������� � ����� ���.\n����������, ������� id ������� ��� ��������: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //��������� id ��� ������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "� ���� �� ��������������� �� ���� �������.") == 0) {
									cout << b << endl;
									t3 = 1;
									continue;
								}
								else if (strcmp(b, "������ ������� �� ��������������� � ����. ������� �� �� ��������� ���� ���? ��(1) ��� ���(2).") == 0) {
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										t3 = 1;
									}
									continue;
								}
								system("cls");
								break;
							}
							if (t3 == 1) {
								t3 = 0;
								system("pause");
								system("cls");
								break;
							}
							if (strcmp(b, "� ���� �� ��������������� �� ���� �������.") == 0) {
								t3 = 0;
								system("pause");
								system("cls");
								break;
							}
							while (t3 != 11) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
										continue;
									}
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									err1 = atoi(buf);
									if (err1 == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
										continue;
									}
								}
								k[0] = '\0';
								recv(s, k, sizeof(k), 0);
								system("cls");
								t3 = atoi(k);
								switch (t3) {
								case 1: { //������. �������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 2: { //������.�����
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 3: { //������. ��������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 4: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //������. ���.���.
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										f[0] = '\0';
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
									break;
								}
								case 5: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //������. email
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
									break;
								}
								case 6: { //������� � ��������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 7: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //������. ���
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
									break;
								}
								case 8: {  // ������. ��������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 9: {//���� ��������
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
									break;
								}
								case 10: {//������. ����
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
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
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "Good") != 0) {
								cout << b << endl;
								break;
							}
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //��������� ��� ��� ������
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "���� ��������� ��������� � ����� ���.\n����������, ������� id ������� ��� ��������: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //��������� id ��� ������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "� ���� �� ��������������� �� ���� �������.") == 0) {
									cout << b << endl;
									t3 = 1;
									system("pause");
									system("cls");
									continue;
								}
								else if (strcmp(b, "������ ������� �� ��������������� � ����. ������� �� �� ��������� ���� ���? ��(1) ��� ���(2).") == 0) {
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										t3 = 1;
									}
									system("cls");
									continue;
								}
								break;
							}
							if (t3 == 1) {
								t3 = 0;
								system("cls");
								break;
							}
							if (strcmp(b, "� ���� �� ��������������� �� ���� �������.") == 0) {
								t3 = 0;
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							cout << b << endl;
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							system("pause");
							system("cls");
							break;
						}
						case 5: {
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							if (strcmp("����� �����.", buf) == 0) {
								cout << buf << endl;
								system("pause");
								system("cls");
								break;
							}
							while (1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "EndOfFile") == 0) {
									break;
								}
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								if (strcmp(b, "FileEmpty") == 0) {
									cout << "���������� ���� �����." << endl;
									break;
								}
								cout << b << endl;
							}
							b[0] = '\0';
							err = 1; err1 = 1;
							recv(s, b, sizeof(b), 0);
							cout << b << endl;
							while (err == 1 || err1 == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
									continue;
								}
								buf[0] = '\0';
								recv(s, buf, sizeof(buf), 0);
								err1 = atoi(buf);
								if (err1 == 1) {
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
									continue;
								}
							}
							b[0] = '\0';
							err = 1; err1 = 1;
							recv(s, b, sizeof(b), 0);
							cout << b << endl;
							while (err == 1 || err1 == 1) {
								b[0] = '\0';
								buf[0] = '\0';
								cin.getline(b, 50, '\n');
								b[strlen(b) + 1] = '\0';
								send(s, b, sizeof(b), 0);
								recv(s, buf, sizeof(buf), 0);
								err = atoi(buf);
								if (err == 1) {
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
									continue;
								}
								buf[0] = '\0';
								recv(s, buf, sizeof(buf), 0);
								err1 = atoi(buf);
								if (err1 == 1) {
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
									continue;
								}
							}
							if (strcmp(b, "1") == 0) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}

							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							system("pause");
							system("cls");
							break;
						}
						case 6: {
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
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						system("cls");
						t2 = atoi(k);
						switch (t2) {
						case 1: { //����� ������� � ���������� ������.���������
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "Good") != 0) {
								cout << b << endl;
								system("pause");
								system("cls");
								break;
							}
							while (1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "EndOfFile") == 0) {
									break;
								}
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								if (strcmp(b, "FileEmpty") == 0) {
									cout << "���� � ��������������� ��������� �����." << endl;
									break;
								}
								cout << b << endl;
							}
							system("pause");
							system("cls");
							break;
						}
						case 2: {
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "Good") != 0) {
								cout << b << endl;
								system("pause");
								system("cls");
								break;
							}
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //��������� �������� ���.��. ��� ������
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "���� ��������� �������������� �������� � ����� ���������.\n����������, ������� id ������� ��� ��������������� �������: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //��������� id ��� ������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "� ���� �� ��������������� �� ���� �������������� ������.") == 0) {
									system("pause");
									system("cls");
									cout << b << endl;
									t3 = 1;
									system("pause");
									system("cls");
									continue;
								}
								else if (strcmp(b, "������ �������������� ������ �� ��������������� � ����. ������� �� �� ��������� ���� ��������? ��(1) ��� ���(2).") == 0) {
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										t3 = 1;
										system("pause");
										system("cls");
									}
									system("cls");
									continue;
								}
								system("cls");
								break;
							}
							if (t3 == 1) {
								t3 = 0;
								break;
							}
							if (strcmp(b, "� ���� �� ��������������� �� ���� �������������� ������.") == 0) {
								t3 = 0;
								break;
							}
							while (t3 != 9) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
									return 0;
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "FileError") == 0) {
									cout << "������ �������." << endl;
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
										continue;
									}
									buf[0] = '\0';
									recv(s, buf, sizeof(buf), 0);
									err1 = atoi(buf);
									if (err1 == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
										continue;
									}
								}
								k[0] = '\0';
								recv(s, k, sizeof(k), 0);
								system("cls");
								t3 = atoi(k);
								switch (t3) {
								case 1: { //������. ��������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 2: { //������.���������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 3: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //������. email
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
									break;
								}
								case 4: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //������. ���.���.
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										f[0] = '\0';
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
									break;
								}
								case 5: {
									f[0] = '\0';
									while (strcmp(f, "0") != 0) {
										b[0] = '\0'; //������. ���
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
												cout << "������ �����. ��������� �������." << endl;
												cin.clear();
											}
										}
										recv(s, f, sizeof(f), 0);
										if (strcmp(f, "0") != 0) {
											cout << f << endl;
										}
									}
									system("cls");
									break;
								}
								case 6: { //������.�����
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 7: {//������.������� �����������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
									break;
								}
								case 8: {  // ������. ��������������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
									system("cls");
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
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "Good") != 0) {
								cout << b << endl;
								system("pause");
								system("cls");
								break;
							}
							t3 = 0;
							while (t3 != 1) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								cout << b;
								err = 1;
								while (err == 1) {
									b[0] = '\0';  //��������� �������� ���.��. ��� ������
									buf[0] = '\0';
									cin.getline(b, 100, '\n');
									b[strlen(b) + 1] = '\0';
									send(s, b, sizeof(b), 0);
									recv(s, buf, sizeof(buf), 0);
									err = atoi(buf);
									if (err == 1) {
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "���� ��������� �������������� �������� � ����� ���������.\n����������, ������� id ������� ��� ��������������� �������: ") == 0) {
									cout << b << endl;
									b[0] = '\0'; //��������� id ��� ������
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
										}
									}
								}
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "� ���� �� ��������������� �� ���� �������������� ������.") == 0) {
									cout << b << endl;
									t3 = 1;
									system("pause");
									system("cls");
									continue;
								}
								else if (strcmp(b, "������ �������������� ������ �� ��������������� � ����. ������� �� �� ��������� ���� ��������? ��(1) ��� ���(2).") == 0) {
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
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
										buf[0] = '\0';
										recv(s, buf, sizeof(buf), 0);
										err1 = atoi(buf);
										if (err1 == 1) {
											cout << "������ �����. ��������� �������." << endl;
											cin.clear();
											continue;
										}
									}
									if (strcmp(b, "2") == 0) {
										t3 = 1;
										system("cls");
									}
									continue;
								}
								break;
							}
							system("cls");
							if (t3 == 1) {
								t3 = 0;
								break;
							}
							if (strcmp(b, "� ���� �� ��������������� �� ���� �������������� ������.") == 0) {
								t3 = 0;
								break;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							cout << b << endl;
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							b[0] = '\0';
							recv(s, b, sizeof(b), 0);
							if (strcmp(b, "FileError") == 0) {
								cout << "������ �������." << endl;
								return 0;
							}
							system("pause");
							system("cls");
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
				cout << "������" << endl;
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1; //��������� ������
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 100, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
					}
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1; //��������� ������
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					int j = 0;
					b[0] = '\0';
					for (;;) {
						b[j] = _getch();
						if (b[j] == '\r')
							break;
						if (b[j] == '\b') {
							cout << "\b \b";
							j--;
						}
						else if (b[j] != '\0') {
							cout << "*";
							j++;
						}
					}
					b[j] = '\0';
					cout << "\n";
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
					}
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				if (strcmp(b, "�������� ����� �/��� ������.\n������� ��������� �������? ��(1) ��� ���(2).") == 0) {
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
							cout << "������ �����. ��������� �������." << endl;
							cin.clear();
							continue;
						}
						buf[0] = '\0';
						recv(s, buf, sizeof(buf), 0);
						err1 = atoi(buf);
						if (err1 == 1) {
							cout << "������ �����. ��������� �������." << endl;
							cin.clear();
							continue;
						}
					}
					if (strcmp(b, "2") == 0) {
						break;
					}
					else continue;
					system("cls");
				}
				else break;
			}
			system("cls");
			if (strcmp(b, "2") == 0) {
				break;
			}
			b[0] = '\0';
			recv(s, b, sizeof(b), 0);
			cout << b << endl;
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
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
						continue;
					}
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					err1 = atoi(buf);
					if (err1 == 1) {
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
						continue;
					}
				}
				k[0] = '\0';
				recv(s, k, sizeof(k), 0);
				system("cls");
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					t3 = 0;
					while (t3 != 9) {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
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
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						system("cls");
						t3 = atoi(k);
						switch (t3) {
						case 1: { //������. �������
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							system("cls");
							break;
						}
						case 2: { //������.�����
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							system("cls");
							break;
						}
						case 3: { //������. ��������
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							system("cls");
							break;
						}
						case 4: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //������. ���.���.
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							system("cls");
							break;
						}
						case 5: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //������. email
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							system("cls");
							break;
						}
						case 6: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //��������. ��������� ����
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							system("cls");
							break;
						}
						case 7: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //������. ���
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							system("cls");
							break;
						}
						case 8: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //������. ������
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							system("cls");
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
							cout << "������ �����. ��������� �������." << endl;
							cin.clear();
						}
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					cout << b;
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "������ �������." << endl;
						return 0;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "������ �������." << endl;
						return 0;
					}
					system("pause");
					system("cls");
					break;
				}
				case 3: {
					while (1) {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "EndOfFile") == 0) {
							break;
						}
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						if (strcmp(b, "FileEmpty") == 0) {
							cout << "�������������� �������� ����." << endl;
							break;
						}
						cout << b << endl;
					}
					system("pause");
					system("cls");
					break;
				}
				case 4: {
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "������ �������." << endl;
						return 0;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "Good") != 0) {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "Good") != 0) {
							cout << b << endl;
							system("pause");
							system("cls");
							break;
						}
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					cout << b << endl;
					if (strcmp(b, "������ ������ ��� ��� ��������� �����.") == 0) {
						system("pause");
						system("cls");
						break;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "������ �������." << endl;
						return 0;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "������ �������." << endl;
						return 0;
					}
					system("pause");
					system("cls");
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
							cout << "������ �������." << endl;
							return 0;
						}
						if (strcmp(b, "FileEmpty") == 0) {
							cout << "���������� ���� �����." << endl;
							break;
						}
						cout << b << endl;
					}
					system("pause");
					system("cls");
					break;
				}
				case 6: {
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					if (strcmp("����� �����.", buf) == 0) {
						cout << buf << endl;
						system("pause");
						system("cls");
						break;
					}
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					cout << buf << endl;
					system("pause");
					system("cls");
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
					cout << buf << endl;
					system("pause");
					system("cls");
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
		case 3: {  //���������� ������.�������
			b[0] = '\0';  //�������� ������.�������
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
					cout << "������ �����. ��������� �������." << endl;
					cin.clear();
				}
			}
			b[0] = '\0';//��������
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
					cout << "������ �����. ��������� �������." << endl;
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
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
					}
				}
				recv(s, f, sizeof(f), 0);
				if (strcmp(f, "0") != 0) {
					cout << f << endl;
				}
			}
			f[0] = '\0';//���.���.
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
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
					}
				}
				recv(s, f, sizeof(f), 0);
				if (strcmp(f, "0") != 0) {
					cout << f << endl;
				}
			}
			f[0] = '\0';//���
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
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
					}
				}
				recv(s, f, sizeof(f), 0);
				if (strcmp(f, "0") != 0) {
					cout << f << endl;
				}
			}
			b[0] = '\0';  //����� ������������
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
					cout << "������ �����. ��������� �������." << endl;
					cin.clear();
				}
			}
			b[0] = '\0';  //������ �����������
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
					cout << "������ �����. ��������� �������." << endl;
					cin.clear();
				}
			}
			b[0] = '\0';//��������������
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
					cout << "������ �����. ��������� �������." << endl;
					cin.clear();
					continue;
				}
				buf[0] = '\0';
				recv(s, buf, sizeof(buf), 0);
				err1 = atoi(buf);
				if (err1 == 1) {
					cout << "������ �����. ��������� �������." << endl;
					cin.clear();
					continue;
				}
			}
			b[0] = '\0';
			recv(s, b, sizeof(b), 0);
			if (strcmp(b, "FileError") == 0) {
				cout << "������ �������." << endl;
				return 0;
			}
			b[0] = '\0';
			recv(s, b, sizeof(b), 0);
			if (strcmp(b, "FileError") == 0) {
				cout << "������ �������." << endl;
				return 0;
			}
			system("cls");
			break;
		}
		case 4: {
			k[0] = '\0';
			while (1) {
				b[0] = '\0';
				cout << "�������" << endl;
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1; //��������� ������
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					cin.getline(b, 100, '\n');
					b[strlen(b) + 1] = '\0';
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
					}
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				cout << b;
				err = 1; //��������� ������
				while (err == 1) {
					b[0] = '\0';
					buf[0] = '\0';
					int j = 0;
					b[0] = '\0';
					for (;;) {
						b[j] = _getch();
						if (b[j] == '\r')
							break;
						if (b[j] == '\b') {
							cout << "\b \b";
							j--;
						}
						else if (b[j] != '\0') {
							cout << "*";
							j++;
						}
					}
					b[j] = '\0';
					cout << "\n";
					send(s, b, sizeof(b), 0);
					recv(s, buf, sizeof(buf), 0);
					err = atoi(buf);
					if (err == 1) {
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
					}
				}
				b[0] = '\0';
				recv(s, b, sizeof(b), 0);
				if (strcmp(b, "�������� ����� �/��� ������.\n������� ��������� �������? ��(1) ��� ���(2).") == 0) {
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
							cout << "������ �����. ��������� �������." << endl;
							cin.clear();
							continue;
						}
						buf[0] = '\0';
						recv(s, buf, sizeof(buf), 0);
						err1 = atoi(buf);
						if (err1 == 1) {
							cout << "������ �����. ��������� �������." << endl;
							cin.clear();
							continue;
						}
					}
					if (strcmp(b, "2") == 0) {
						system("cls");
						break;
					}
					else {
						system("cls");
						continue;
					}
				}
				else {
					system("cls");
					break;
				}
			}
			if (strcmp(b, "2") == 0) {
				break;
			}
			system("cls");
			b[0] = '\0';
			recv(s, b, sizeof(b), 0);
			cout << b << endl;
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
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
						continue;
					}
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					err1 = atoi(buf);
					if (err1 == 1) {
						cout << "������ �����. ��������� �������." << endl;
						cin.clear();
						continue;
					}
				}
				k[0] = '\0';
				recv(s, k, sizeof(k), 0);
				system("cls");
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					t3 = 0;
					while (t3 != 10) {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
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
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err1 = atoi(buf);
							if (err1 == 1) {
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
								continue;
							}
						}
						k[0] = '\0';
						recv(s, k, sizeof(k), 0);
						system("cls");
						t3 = atoi(k);
						switch (t3) {
						case 1: { //������. �������
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							system("cls");
							break;
						}
						case 2: { //������.�����
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							system("cls");
							break;
						}
						case 3: { //������. ��������
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
									cout << "������ �����. ��������� �������." << endl;
									cin.clear();
								}
							}
							system("cls");
							break;
						}
						case 4: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //������. ���.���.
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							system("cls");
							break;
						}
						case 5: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //������. email
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							system("cls");
							break;
						}
						case 6: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //������. ���
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							system("cls");
							break;
						}
						case 7: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //���� ��������
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							system("cls");
							break;
						}
						case 8: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //����
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							system("cls");
							break;
						}
						case 9: {
							f[0] = '\0';
							while (strcmp(f, "0") != 0) {
								b[0] = '\0'; //������. ������
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
										cout << "������ �����. ��������� �������." << endl;
										cin.clear();
									}
								}
								f[0] = '\0';
								recv(s, f, sizeof(f), 0);
								if (strcmp(f, "0") != 0) {
									cout << f << endl;
								}
							}
							system("cls");
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
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "������ �������." << endl;
						return 0;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileGood") != 0) {
						cout << b << endl;
						system("pause");
						system("cls");
						break;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "������ �������." << endl;
						return 0;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "Good") != 0) {
						cout << b << endl;
						system("pause");
						system("cls");
						break;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "������ �������." << endl;
						return 0;
					}
					while (1) {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "EndOfFile") == 0) {
							break;
						}
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						if (strcmp(b, "FileEmpty") == 0) {
							cout << "���� �������������� �������� �����." << endl;
							system("pause");
							system("cls");
							break;
						}
						cout << b << endl;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "������ �������." << endl;
						return 0;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileGood") != 0) {
						cout << b << endl;
						system("pause");
						system("cls");
						break;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					cout << b << endl;
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					err1 = atoi(b);
					for (int l = 0; l < err1; l++) {
						err = 1;
						while (err != 0) {
							b[0] = '\0';
							buf[0] = '\0';
							cin.getline(b, 50, '\n');
							b[strlen(b) + 1] = '\0';
							send(s, b, sizeof(b), 0);
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "������������ �������.��������� �������." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "����� �� �������� ��������. ��������� �������." << endl;
								cin.clear();
								continue;
							}
							buf[0] = '\0';
							recv(s, buf, sizeof(buf), 0);
							err = atoi(buf);
							if (err == 1) {
								cout << "������ ��������. ��������� �������." << endl;
								cin.clear();
								continue;
							}
							else break;
						}
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "1") == 0) {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
					}
					else {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						if (strcmp(b, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}


					}
					system("cls");
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
							cout << "������ �����. ��������� �������." << endl;
							cin.clear();
							continue;
						}
						buf[0] = '\0';
						recv(s, buf, sizeof(buf), 0);
						err1 = atoi(buf);
						if (err1 == 1) {
							cout << "������ �����. ��������� �������." << endl;
							cin.clear();
							continue;
						}
					}
					if (strcmp(b, "2") == 0) {
						buf[0] = '\0';
						recv(s, buf, sizeof(buf), 0);
						if (strcmp(buf, "FileError") == 0) {
							cout << "������ �������." << endl;
							return 0;
						}
						buf[0] = '\0';
						recv(s, buf, sizeof(buf), 0);
						if (strcmp(buf, "Good") != 0) {
							cout << buf << endl;
							system("pause");
							system("cls");
							break;
						}
					}
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					if (strcmp(buf, "������ ������ ��� ��� ��������� �����.") == 0) {
						cout << buf << endl;
						system("pause");
						system("cls");
						break;
					}
					if (strcmp(b, "1") == 0) {
						b[0] = '\0';
						recv(s, b, sizeof(b), 0);
						cout << b << endl;
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
								cout << "������ �����. ��������� �������." << endl;
								cin.clear();
							}
						}
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "������ �������." << endl;
						return 0;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					if (strcmp(b, "FileError") == 0) {
						cout << "������ �������." << endl;
						return 0;
					}
					b[0] = '\0';
					recv(s, b, sizeof(b), 0);
					cout << b << endl;
					system("pause");
					system("cls");
					break;
				}
				case 4: {
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					if (strcmp("����� �����.", buf) == 0) {
						cout << buf << endl;
						system("pause");
						system("cls");
						break;
					}
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					cout << buf << endl;
					buf[0] = '\0';
					recv(s, buf, sizeof(buf), 0);
					if (strcmp(buf, "�����") != 0) {
						cout << buf << endl;
					}
					system("pause");
					system("cls");
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