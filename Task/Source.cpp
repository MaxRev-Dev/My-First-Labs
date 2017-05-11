#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

double Newton(double n,int args_qnt, int* x, int* y) {
	double result = y[0], current_Monominal, den;
	int i, j, k;
	for (i = 1; i<args_qnt; i++) {
		current_Monominal = 0;
		for (j = 0; j <= i; j++) {
			den = 1;
			for (k = 0; k <= i; k++) {
				if (k != j) den *= (x[j] - x[k]);
			}
			current_Monominal += y[j] / den;
		}
		for (k = 0; k<i; k++) current_Monominal *= (n - x[k]);
		result += current_Monominal;
	}
	return result;
}
void showArgs(int* cur) {
	for (int i = 0; i < 5; ++i) {
		cout << " " << cur[i];
	} cout << endl;
}
int main() {
	SetConsoleOutputCP(1251);
	int args_X[] = { 0,1,2,3,4 };
	int args_Y[] = { 1,4,15,40,80 };
	double X;
	cout << "Введіть Х: ";
	cin >> X;
	cout << "Значення масиву Х (вузлові точки): ", showArgs(args_X);
	cout << "Значення масиву Y (значення функції):", showArgs(args_Y);

	cout << "При заданому Х="<<X<<" значення многочлена дорівнює: "<< Newton(X, 5, args_X, args_Y)<<endl;
	_getch();
	return 0;
}