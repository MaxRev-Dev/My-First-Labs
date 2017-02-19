#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <exception>
using namespace std;

int main() { 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int *arr = new int[1];
	try {
		short srr[1][2][3][4][5][6][7][8][9][2];
		cout << sizeof(srr);
	}
	catch (int srr){
		cout << sizeof(srr);
	}
	_getch();
	return 0;
}

