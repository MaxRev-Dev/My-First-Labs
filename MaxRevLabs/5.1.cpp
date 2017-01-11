#include <math.h>
#include <windows.h>
#include <iostream>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float x0, x, y, e, n;
	cout << "Ввведіть початкове значення x=";
	cin >> x0;
	cout << "Введіть точність e=";
	cin >> e;
	x = x0;
	y = x - (exp(x) + x) / (exp(x) + 1);
	n = 0;
	while (fabs(y - x) > e) {
		x = y;
		y = x - (exp(x) + x) / (exp(x) + 1);
		n++;
	}
	cout << "Значення кореня " << y << endl;
	cout << "Кількість ітерацій " << n << endl;
	system("pause");
	return 0;
}
