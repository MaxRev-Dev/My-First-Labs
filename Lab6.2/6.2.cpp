#include <iostream>
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
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	static float A,B,eps,counter,x;
	while (true) {
		float &a = A;
		float &b = B;
		float &e = eps;
		float &i = counter;

		input_vars(A,B,eps);
		x=findRoot(A,B,eps,i);
		output(x,i);
		system("pause");
		system("cls");
	}
	return 0;
}

void output(float &x, float &i){

	cout << "\nКількість ітерацій --- " << i;
	cout << "\nРезультат --- " << x << endl;
}	

float findRoot(float &a, float &b, float &e, float &i)
{
	float  x1=0,x=0;
	
	x1 = fall(a, b);
	if ((f(a)*f(x1)) > 0) a = x1;
	else b = x1;
	x = fall(a, b);

		while (fabs(x - x1)>e){
				if ((f(a)*f(x)) > 0) a = x;
				else b = x;
				x = x1;
				x1 = fall(a, b);
				i++;
			}
		return x;
	}





float fall(float a, float b) {
	return (f(b)*a - f(a)*b) / (f(b) - f(a));
}

float f(float x)						
{
	return pow(x, 3) - 3 * pow(x, 2) + 1; 
}

void input_vars(float &a, float &b, float &e) {
	static float number;
	cout << "Введіть A:";
	a = inputCheck(number);
	cout << "Введіть B:";
	b = inputCheck(number);
	cout << "Введіть Епсилон:";
	e = inputCheck(number);
}

