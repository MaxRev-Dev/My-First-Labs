#include "HR.h"
#include <iostream>
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

HR::HR(int)
{
	createArray(n);
}

void HR::createArray(int n) 
{
	arr = new double[n];
}

void HR::outputArray()
{
	for (i=0; i < n-1; i++) {
		cout << "array[" << i << "] " << *(arr + i) << endl;
	}
}
	
double HR::addEl()
{
	double *temp = new double[n + 1];
	for (i = 0; i<n; i++) temp[i] = *(arr + i);
	delete[] arr;

	arr = new double[i+1];
	for (i=0; i < n; i++) *(arr + i) = temp[i];
	if (*(arr + i-1) != 0) {
		cout << "Введіть значення -"<< i << "- (ел-" << n+1 << "):";
		*(arr + i) = inputCheck(num);
		n++;
		delete[] temp;
	}
	return num;
}

HR::~HR()
{
	delete arr;
};
	