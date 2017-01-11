#include <iostream>
#include <windows.h>
#include "extend.h"

int main(){

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n=1;
	while (true)	{
		double *dyn_A = new double[9];
		_input(dyn_A, n);
		_findPositiveNum(dyn_A, n);
		delete[] dyn_A;
	}

	return 0;
}

