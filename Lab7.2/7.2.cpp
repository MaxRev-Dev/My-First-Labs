#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <graphics.h>

using namespace std;

template <class Type>
Type inputCheck(Type &number)
{
	while (true) {
		cin >> number;
		if (cin.peek() == '\n' || cin.peek() == ',' || cin.peek() == '.') {
			cin.get();
			break;
		}
		else {
			cout << "\n�������! ������������� ������." << endl;
			cout << "��������� �� ���:";
			cin.clear();
			cin.sync();
		}
	}
	return number;
}

int main()
{
s:
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double  number;
	double ar[6];
	int n = 0;
	for (n; n < 7; n++) {
		cout << "������ �������� N(����� ������ - 7):";
		ar[n] = inputCheck(number);

	}	cout << "������ ��'����� ����� � �����:";
	
	for (n=0; n < 7; n++) {
		if (fabs(ar[n]) == -ar[n]) {
			cout << n <<" ";
		} 
	}cout << endl;



	goto s;
	system("pause");
	return 0;
}