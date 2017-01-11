#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>

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
			cout << "\nПомилка! Неприпустимий символ." << endl;
			cout << "Спробуйте ще раз:";
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
	double  number, t1, t2, Dt1, n, y, pt, nn = 0, Dt2;

	cout << "Введіть значення N:";
	n = inputCheck(number);
	cout << "Введіть значення T1:";
	t1 = inputCheck(number);
	cout << "Введіть значення T2:";
	t2 = inputCheck(number);
	cout << "Введіть значення Dt1:";
	Dt1 = inputCheck(number);
	cout << "Введіть значення Dt2:";
	Dt2 = inputCheck(number);
	cout << "Введіть значення pt:";
	pt = inputCheck(number);


	while (t1 <= t2) {
		y = (2 * t1 + 8) / (fabs(cos(3 * t1)) + 1);
		cout << "\nT=:" << t1 << "\tY=:" << y;
		t1 += Dt1;
	} cout << "\n------------";
	while (nn<n) {
		y = (2 * pt + 8) / (fabs(cos(3 * pt)) + 1);
		cout << "\nT=:" << pt << "\tY=:" << y;
		pt += Dt2;
		nn++;
	} cout << endl;


	goto s;
	system("pause");
	return 0;
}