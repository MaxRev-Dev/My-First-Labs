#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <conio.h>
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

void user_out(float,float);
void user_inp(float &e1, float &e2, float &e3, float &e4, float &e5, float &e6);
void troubles_NOPE(float&, float&, float&, float&, float&, float&);
int prompt(int&);

int main()
{
	int on = 1;
	while (on==1) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		static float number, y1, y2, dy, x1, x2, dx;
		float &e1 = y1;
		float &e2 = y2;
		float &e3 = dy;
		float &e4 = x1;
		float &e5 = x2;
		float &e6 = dx;
		int &once = on;
		user_inp(e1, e2, e3, e4, e5, e6);
		troubles_NOPE(e1, e2, e3, e4, e5, e6);

		prompt(once);
	} 
	return 0;
}

int prompt(int &once){
	char xd[]="default";
	cout << "Перезапустити програму? ";
	cin >> xd;
	if (xd != "yes") {
		return 0;
	}
	else { return 1; };
}

void user_inp(float &e1, float &e2, float &e3, float &e4, float &e5, float &e6) {
	float number;
		std::cout << "Введіть Y1:";
		e1 = inputCheck(number);
		std::cout << "Введіть Y2:";
		e2 = inputCheck(number);
		std::cout << "Введіть dY:";
		e3 = inputCheck(number);

		std::cout << "Введіть X1:";
		e4 = inputCheck(number);
		std::cout << "Введіть X2:";
		e5 = inputCheck(number);
		std::cout << "Введіть dX:";
		e6 = inputCheck(number);
}

void user_out(float x, float y) {
			cout << "X=" << x << "\tY=" << y << "\t";
	}

void troubles_NOPE(float &e1, float &e2, float &e3, float &e4, float &e5, float &e6)
{
	float rsY, z;
	rsY = e1;
	for (e4; e4 <= e5; e4 += e6)	{
		for (e1; e1 <= e2; e1 += e3)	{
			user_out(e4, e1);
			z = pow(cos((e4 + 2) / (e1 + 1)), 2);
			cout << "Z=" << z << endl;
		}  e1 = rsY;
	}
}