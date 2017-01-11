#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <limits.h>
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
			cout << endl;
		}
	}
	return number;
}
void formula(double&, double&, double&, double&);
void i_v(double &, double &);
void o_v(double &, double &);
double f(double,double);

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		double x, eps,n=1,i=0;
		i_v(x, eps);
		formula(x, eps, n,i);
		
	system("pause");
	system("cls");
	}
	return 0;
}

void formula( double& x, double& eps, double &n,double&i) {
	while(fabs(f(x,n)) > eps && fabs(x)<INT_MAX)
		{
			x += f(x, n);
			i++;
			n++;
			o_v(x, i);
		}
	
}

double f(const double x, const double n){
	return (pow(-1,n) * pow(x,2*n)/(2*n+1));
}

void o_v(double &var, double &iter){
	double dy=0;
	if (var != dy){
		cout << "|\tЗмінна - " << var << " \t\t|\tІтерація - " << iter << "\t\t|\n";
	} dy = var;
}

void i_v(double &zz, double &ee) {
		static double number;
		cout << "Введіть X:";
		zz = inputCheck(number);
		cout << "Введіть Епсилон:";
		ee = inputCheck(number);
	}