#define _AFXDLL  //�������� MFC � DLL
#include <iostream>
#include <afx.h>  //��� ��������� ���������� ��������
#include <winsock2.h>
#include <process.h> /* _beginthread, _endthread */  //�������� ���������� ������� � �������, ������������ ��� ������ � �������� � ����������
#include <string.h>
#include <fstream>

using namespace std;
  
void main_working(void* newS) {
	int c, c1 = 0, c2 = 0, c3;
	int flag = 0;
	char p[500], com[200], k[500], m[500];
	com[0] = '\0'; p[0] = '\0'; k[0] = '\0'; m[0] = '\0';
	cout << "������ ��������.\n";
	while (1) {
		strcpy_s(p, "����� ���������� � ��� ���������.\n");
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(k, "����:\n 1)����� � �������� ��������������;\n 2)����� � �������� �������;\n 3)����� � �������� ������������� ��������������� �������;\n 4)����� � �������� ��������;\n 5)��������� ������ ���������.\n ");
		send((SOCKET)newS, k, sizeof(k), 0);
		p[0] = '\0'; k[0] = '\0';
		recv((SOCKET)newS, m, sizeof(m), 0);
		c = atoi(m);
		switch (c) {
		case 1: {
			strcpy_s(p, "1");
			send((SOCKET)newS, p, sizeof(p), 0);
			strcpy_s(p, "*����� ����� �����������*");
			send((SOCKET)newS, p, sizeof(p), 0);
			while (c1 != 5) {
				strcpy_s(k, "���� ��������������:\n 1)���������� ���������;\n 2)�������� �������;\n 3)���������� ����������;\n 4)���������� ��������������� ���������;\n 5)����� � ������� ����.\n ");
				send((SOCKET)newS, k, sizeof(k), 0);
				recv((SOCKET)newS, m, sizeof(m), 0);
				c1 = atoi(m);
				switch (c1) {
				case 1: {
					strcpy_s(p, "1");
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 6) {
						strcpy_s(p, "���� ���������� ���������:\n 1)����� ������� �� ����� ��������� � ���������� �������;\n 2)������ �������� � ��������;\n 3)�������������� ������ �������;\n 4)����� �������� �������;\n 5)����������;\n 6)����� � ���� ��������������.\n");
						send((SOCKET)newS, p, sizeof(p), 0);
						recv((SOCKET)newS, m, sizeof(m), 0);
						c2 = atoi(m);
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
						case 6: {
							strcpy_s(p, "6");
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
						strcpy_s(p, "���� �������� �������:\n 1)����� ������� ������������� ��������;\n 2)����� ����������� ��������������� ��������;\n 3)����� � ���� ��������������.\n");
						send((SOCKET)newS, p, sizeof(p), 0);
						recv((SOCKET)newS, m, sizeof(m), 0);
						c2 = atoi(m);
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
						strcpy_s(p, "���� ���������� ����������:\n 1)���������� ��������;\n 2)����� ������� �� ����� ���������� � ���������� �������;\n 3)�������������� ������ ��������;\n 4)�������� ��������;\n 5)����� � ���� ��������������.\n");
						send((SOCKET)newS, p, sizeof(p), 0);
						recv((SOCKET)newS, m, sizeof(m), 0);
						c2 = atoi(m);
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
						strcpy_s(p, "���� ���������� ��������������� ���������:\n 1)����� ������� �� ����� ���������� ��������������� ��������� � ���������� �������;\n 2)�������������� ������ ��������������� �������;\n 3)�������� ��������������� �������;\n 4)����� � ���� ��������������.\n");
						send((SOCKET)newS, p, sizeof(p), 0);
						recv((SOCKET)newS, m, sizeof(m), 0);
						c2 = atoi(m);
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
			strcpy_s(p, "*����� ����� �����������*");
			send((SOCKET)newS, p, sizeof(p), 0);
			while (c1 != 5) {
				strcpy_s(k, "���� �������:\n 1)�������������� ������;\n 2)���� �������� �������;\n 3)�������� ��������������� ��������;\n 4)������ �������� � �������������� ���������;\n 5)����� � ������� ����.\n ");
				send((SOCKET)newS, k, sizeof(k), 0);
				recv((SOCKET)newS, m, sizeof(m), 0);
				c1 = atoi(m);
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
			strcpy_s(k, "*����� ����� ����������� ��������������� ������� ��� ��������������*\n ");
			send((SOCKET)newS, k, sizeof(k), 0);
			break;
		}
		case 4: {
			strcpy_s(p, "4");
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			strcpy_s(p, "*����� ����� �����������*");
			send((SOCKET)newS, p, sizeof(p), 0);
			while (c1 != 3) {
				strcpy_s(k, "���� ��������:\n 1)�������������� ������;\n 2)����� �������������� �������;\n 3)����� � ������� ����.\n ");
				send((SOCKET)newS, k, sizeof(k), 0);
				recv((SOCKET)newS, m, sizeof(m), 0);
				c1 = atoi(m);
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
		_beginthread(main_working, 0, (void*)newS);  //�������� ������(��������� ����� ���������, ������� �������� ���������� ������ ������; ������ ����� ������ ������ ��� 0; ������ ����������, ������������ � ����� �����, ��� NULL)
	}
	WSACleanup();
	return 0;
}