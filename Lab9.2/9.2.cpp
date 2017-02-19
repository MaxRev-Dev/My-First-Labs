#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

#include <math.h>

double cust_log(double, double);
double prod(double[], double[], double, double, int, int);
double getExr(double **);
double** readFile();
double inpVars();
double constructFraction(double **);
double rc = 0;
void prompt();
const double X = -6.13;
const double Y = 25.4*pow(10, -4);

template <class Type>
Type inputCheck(Type &number)
{
	using namespace std;
	while (true) {
		cin >> number;
		if (cin.peek() == '\n' || cin.peek() == ',' || cin.peek() == '.') {
			cin.get();
			break;
		}
		else {
			cout << endl << "Помилка! Неприпустимий символ." << endl;
			cin.clear();
			cin.sync();
			inputCheck(number);
		}
	}
	return number;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N=0;
	double sum = 0;
	std::cout << "Введіть кількість дробів: ";
	rc = inputCheck(N);
	if (rc == -10999) { std::cout << "Ой! Щось пішло не так...\a"; _getch(); return -1; };
	double **x = readFile();

	double *frac = new double[N];
	for (int i = 0; i < N; i++) {
		frac[i] = constructFraction(x);
		if (frac[i] == -10999) { _getch();  break; };
		sum += frac[i];
	}
	std::cout<<"Processing";
	for (int i = 0; i < 5; i++) {
		Sleep(200);
		std::cout<<".";
	}
	std::cout << std::endl;
	std::cout << "Успіх! Вираз = " << std::setprecision(5) << sum;
	
	_getch();
	prompt();
	return 0;
}

double cust_log(double x, double coef) {
	log(fabs(1 + coef*tan(x)));
	return x;
}
double prod(double a[], double b[],double ca,double cb, int i, int max) {
	double prod =1;
	for (i--; i < max--; i++) {
		prod *= (ca*a[i] + cb*b[i]);
	}
	return prod;
}
double getExr(double **x) {
	int sw;
	
	if (x == nullptr) return -10999;
		double *a = x[0];
		double *b = x[1];
	std::cout << "Введіть вид виразу:"<<std::endl;
	std::cout << " 1 для логарифму  типу ln | 1 + C*tg x |" << std::endl;
	std::cout << " 2 для добутку типу i = min\\П\\max ( Ai + Bi  ) " << std::endl;
	std::cout << "-----> ";
	rc = inputCheck(sw);
	if (rc == -10999) return -10999;
	switch (sw)
	{
	case 1: {
		char coefBeforeTan = 1;
		double x, coefDbl;
		std::cout << "Введіть коефіціент перед тангенсом (x або y для константи):";
		coefDbl = inpVars();
		std::cout << "Введіть Х (x або y для константи):";
		x = inpVars();
		if (coefDbl == -10999 || x == -10999) return -10999;
		if (coefDbl == 0) {
			coefDbl= 1;
		}
		return cust_log(x, coefDbl);
	} break;
	case 2: {
		int i, maxi;
		double ca, cb;

		std::cout << "Введіть \"і\":";
		rc = inputCheck(i);
		std::cout << "Введіть MAX \"і\":";
		rc = inputCheck(maxi);
		std::cout << "Коефіцієнт А (deft 1):";
		ca = inpVars();
		if (ca == 0) ca = 1;
		std::cout << "Коефіцієнт B (deft 1):";
		cb = inpVars();
		if (cb == 0) cb = 1;
		if (rc == -10999) return -10999;
		return prod(a, b,ca,cb, i, maxi);
	} break;

	default:
		std::cout << "Ой! Щось пішло не так...";
		return -10999;
		break;
	}

}
double inpVars() {
	char var;
	double x;
	std::cin >> var;
	if (std::cin.fail()) return -10999;
	if (var == 'x' || var == 'X' || var == 'Y' || var == 'y') {
		if (var == 'x' || var == 'X') x = ::X;
		else if (var == 'y' || var == 'Y') x = ::Y;
	} else x = (double)var;
	return x;
}
double constructFraction(double **x) {
	double numeri, denomi;
	std::cout << std::endl;
	std::cout << "<Чисельник>"<<std::endl;
	numeri = getExr(x);
	if (numeri == -10999) return -10999;
	std::cout << std::endl;
	std::cout << "<А тепер знаменник>" << std::endl;
	denomi = getExr(x);
	if (denomi == -10999) return -10999;
	return numeri / denomi;
}
void prompt() {
	std::cout << std::endl << "Ще раз?? " << "ESC - вихід" << std::endl;
	_getch();
	if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
	else main();
}
double** readFile() {

	std::ifstream ars("C:\\Users\\MaxRev\\Desktop\\MyArs.txt");

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
			if (sym == '-' || sym == '.'|| isdigit(sym)) {
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
		int k =  2, l = 10;
		double **x = new double*[2];
		for (int i = 0; i < k; i++) x[i] = new double[10];
		std::cout << std::endl << "Масиви з файлу..." << std::endl;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < l; j++) {
				x[i][j] = strtold(arrsOfNums[i][j], NULL);
			}
		}
			for (int j = 0; j < l; j++) {
				 std::cout << "arr[" << i + 1 << "]" << " [" << j + 1 << "] = " << x[i][j] << std::setw(15)<< "\tarr[" << i + 2 << "]" << " [" << j + 1 << "] = " << x[i + 1][j] << std::endl;
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

