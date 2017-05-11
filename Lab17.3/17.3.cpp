#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
	HWND hwnd;
	char Title[1024];
	GetConsoleTitle(Title, 1024); // ������ ��� ����
	hwnd = FindWindow(NULL, Title); // ������ hwnd ����
	RECT rc;
	GetClientRect(hwnd, &rc);
	int iWidth = rc.right;
	int iHeight = rc.bottom;
	HDC hdc = GetDC(hwnd);    // �������� �������� ��� ���������
	HPEN p1, p2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // ������� ������� ����
	p1 = (HPEN)SelectObject(hdc, p2);  // ������� ������� ���� � �������� ���������
	int x = 0, y = 0, R = iWidth / 2;
	double fi = 0;
	do
	{
		x = R*cos(fi);
		y = R*sin(fi);
		MoveToEx(hdc, iWidth / 2, iHeight / 2, NULL);
		LineTo(hdc, x + iWidth / 2, iHeight / 2 - y);
		fi += 0.1;
	} while (fi<6.28);
	SelectObject(hdc, p1);   // ���������� ������ ����
	ReleaseDC(hwnd, hdc);    // ����������� �������� ���������
	DeleteObject(p2);       // ������� ��������� ����
	_getch();
	return 0;
}