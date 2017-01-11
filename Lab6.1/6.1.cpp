#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;

void input_vars(float&, float&, float&);
void findSol(float&, float&, float&);

 
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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float X, N,epsilon;
	while (true) {
		input_vars(X, N, epsilon);
		float &x = X;
		float &n = N;
		float &e = epsilon;
		
		findSol(x, n, e);
		
		system("pause");
		system("cls");
	}
	return 0;
}


void findSol(float &x, float &n,float &e){
	double i=0,next_y,y;
	y = x;
	while(true) {
		 next_y = (x / pow(y, n - 1) + (n - 1)*y)/n;
		 if (fabs(next_y - y) <= e)	{
			 break;
		 }
		y = next_y; 
		i++;
	}
		cout << "\nКількість ітерацій " << i ;
	 	cout << "\nРезультат: Y=" << y << endl;
}

void input_vars(float &fX, float &N, float &e) {
	static float number;
	cout << "Введіть X:";
	fX = inputCheck(number);
	cout << "Введіть N:";
	N = inputCheck(number);
	cout << "Введіть Епсилон:";
	e = inputCheck(number);
}
