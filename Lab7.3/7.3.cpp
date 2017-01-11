#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>
#include <iomanip>

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
			cout << "Помилка! Неприпустимий символ." << endl;
			cout << "Спробуйте ще раз:";
			cin.clear();
			cin.sync();
		}
	}
	return number;
}

void sort(double mesh[5]);
void take_array(double inp_a[5], int n_a);
void make_array(double arr1[5], double arr2[5], double all[10]);
void output(double a[10]);
int main() {
	while (true){
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		double ar1[5], ar2[5], arNew[10];

		take_array(ar1, 1);
		take_array(ar2, 2);
		sort(ar1);
		sort(ar2);
		make_array(ar1, ar2, arNew);
		output(arNew);

		system("pause");
	}
	return 0;
}

void sort(double mesh[5]) {
	double tmp;
	int i, j;
	for (j = 0; j < 5; j++) {
		for (i = 0; i< 4; i++){
			if (*(mesh + i) >*(mesh + i + 1)){
				tmp = *(mesh + i + 1);
				*(mesh + i + 1) = *(mesh + i);
				*(mesh + i) = tmp;
			}
		}
	}
}
void take_array(double inp_a[5], int n_a) {
	int i;
	double number;
		for (i = 0; i <= 4; i++) {
			cout << "Введіть значення -" << i << "- (масив-" << n_a << ")(5ел):";
			*(inp_a + i) = inputCheck(number);
	}
}
void make_array(double arr1[5], double arr2[5], double all[10]) {
	int i;
	for (i = 0; i <= 9; i++) {
		if (i<5) *(all + i) = *(arr1 + i);
		if (i>=5) *(all + i) = *(arr2 + i - 5);
	}
}
void output(double a[10]){
	int i=0;
	cout << "\nНовий масив:" << endl;
	for (i; i < 10; i++) {
		cout << "array[" << i << "]\t" << a[i] << "\n";
	}
	cout << endl;
}
