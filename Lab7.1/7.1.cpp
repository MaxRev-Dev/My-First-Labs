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
			cout << "\nПомилка! Неприпустимий символ." << endl;
			cout << "Спробуйте ще раз:";
			cin.clear();
			cin.sync();
		}
	}
	return number;
}
void i_v(double m[6]);

int main()
{
	while (true) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double  number, t1, t2, Dt1, n, y, pt, nn = 0, Dt2;
	int i = 0, m = 0;
	double T[20], Y[20], apt[20], ay[20], ai[6];

	i_v(ai);
	n = ai[0];
	t1 = ai[1];
	t2 = ai[2];
	Dt1 = ai[3];
	Dt2 = ai[4];
	pt = ai[5];

	for (t1, i; t1 <= t2; t1 += Dt1, i++) {
		y = (2 * t1 + 8) / (fabs(cos(3 * t1)) + 1);
		T[i] = t1;
		Y[i] = y;
		cout << "\nT=(array1[" << i << "]):" << left << setw(10) << T[i] << "Y=(array2[" << i << "]):" << Y[i];

	} cout << "\n";  for (int d = 0; d < getmaxx() / 6; d++) cout << ".";

	for (nn, m; nn < n; nn++, pt += Dt2, m++) {
		y = (2 * pt + 8) / (fabs(cos(3 * pt)) + 1);
		apt[m] = pt;
		ay[m] = y;
		cout << "\nT=(array3[" << m << "]):" << left << setw(10) << apt[m] << "Y=(array4[" << m << "]):" << ay[m];
	} cout << endl;
	system("pause");
}
	return 0;
}

void i_v(double m[6]) {
	double number;
	cout << "Введіть значення N(Розмір масиву - 20):";
	*m = inputCheck(number);
	cout << "Введіть значення T1:";
	*(m + 1) = inputCheck(number);
	cout << "Введіть значення T2(Розмір масиву - 20):";
	*(m + 2) = inputCheck(number);
	cout << "Введіть значення Dt1:";
	*(m + 3) = inputCheck(number);
	cout << "Введіть значення Dt2:";
	*(m + 4) = inputCheck(number);
	cout << "Введіть значення pt:";
	*(m + 5) = inputCheck(number);
}