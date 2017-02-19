#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

double** readFile();
void prompt();
double sum(double*);
double prod(double*);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double w,a,b,X,Y,p;
	int arr=0,i=0;
	double **x = readFile();

	a = prod(x[0]);
	b = prod(x[1]);

	X = sum(x[0]);
	Y = sum(x[1]);
	
	p = (a + b) / (X - Y);
	if (p > 0) {
		w = (a*X + Y) / (b*X - Y);
	}
	else {
		_getch(); 
		std::cout << std::endl << "ERROR! Р менше або = 0" << std::endl;
		prompt();
	}

	std::cout << "Processing";
	for (int i = 0; i < 5; i++) {
		Sleep(200);
		std::cout << ".";
	}
	std::cout << std::endl;
	std::cout << "Успіх! Вираз = " << std::setprecision(5) <<w;

	_getch();
	prompt();
	return 0;
}

void prompt() {
	std::cout << std::endl << "Ще раз?? " << "ESC - вихід" << std::endl;
	_getch();
	if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
	else main();
}
double** readFile() {

	std::ifstream ars("C:\\Users\\MaxRev\\Desktop\\MyArs2.txt");

	if (ars.is_open())
	{
		int i = 0, n = 0, non = 0, arr = 0, spacer;
		// DO YOU BELIEVE IN 3D ARRAY???
		// n -> char
		// non -> it's position in array
		// arr -> number of array

		char sym;

		char ***arrsOfNums = new char**[2];
		for (int i = 0; i < 2; i++) arrsOfNums[i] = new char*[50];

		for (int i = 0; i < 2; i++) {
			for (int ii = 0; ii < 50; ii++) {
				arrsOfNums[i][ii] = new char[10];
			}
		}

		while (!ars.eof()) {
			ars.get(sym);
			if (sym == '-' || sym == '.' || isdigit(sym)) {
				arrsOfNums[arr][non][n] = sym;
				n++;
				spacer = 0;
			}
			else if (sym == ' ') {
				if (spacer == 0) {
					non++; n = 0; spacer++;
				}
			}
			else if (sym == '\n') {
				arr++; non = 0; n = 0;
			}
		}

		//convert array... to double nums
		int k = 2, l = 6;
		double **x = new double*[2];
		for (int i = 0; i < k; i++) x[i] = new double[10];
		std::cout << std::endl << "Масиви з файлу..." << std::endl;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < l; j++) {
				x[i][j] = strtold(arrsOfNums[i][j], NULL);
			}
		}
		for (int j = 0; j < l; j++) {
			std::cout << "arr[" << i + 1 << "]" << "[" << j + 1 << "] = " << x[i][j] << std::setw(15) << "\tarr[" << i + 2 << "]" << "[" << j + 1 << "] = " << x[i + 1][j] << std::endl;
		}


		ars.close();
		return x;
	}
	else
	{
		std::cout << "Файл не знайдено.";
		return nullptr;
	}

}
double prod(double *x) {
	double s = 1;
	for (int i = 0; i < 6; i++) {
		s *= (1 / x[i]);
	}
	return s;
}
double sum(double *x){
	double p = 1;
	for (int i = 0; i < 6; i++) {
		p += fabs(x[i]);
	}
	return p;
}