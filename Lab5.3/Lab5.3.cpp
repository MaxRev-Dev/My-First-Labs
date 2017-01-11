#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>
#include <iomanip>
using namespace std; 

void input_vars(float&, float&, float&, float&);
void count_xi(float&, float&,float&,float&,float&,float&);
void findSol(float&, float&, float&, float&, float&,float&);
void output_vars(float&);
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
	float firstX, dX, maxOfSum, minOfSum,prevX,cnt=1,newX,sol;
while (true) {
	input_vars(firstX, dX, maxOfSum, minOfSum);
	count_xi(firstX,dX,minOfSum,prevX,newX,cnt);
	findSol(prevX,newX,dX,maxOfSum,cnt,sol);
	system("pause"); 
	system("cls");
}	
	return 0;
}

void output_vars(float&q) {
	cout << " результат:"<< q;
}

void count_xi(float &Xtaken, float &deltaX, float &minimum, float &reservedX, float &X,float &i) 
{								//в цій функції ми шукаємо Х та Х-1
	for (i; i <= minimum; i++) {
		X = Xtaken/3+deltaX;	//формула знаходження нового Х
		if (i == minimum - 1){  // беремо Х-1 щоб потім не возитись з його пошуком
			reservedX = Xtaken;
		}	Xtaken = X;			// резервуємо Х щоб ще раз використати в формулі
	} 
}

void findSol(float& previousX, float& X, float &deltaX,float &maximum,float &count,float&s){
	float y=0,reserv;
	for (count; count <= maximum; count++) {
		y += pow(X + previousX, 3) / (X + previousX); // власне сама формула 
		reserv = previousX;								// резервуємо Х-1
		previousX = X;									// беремо новий знайдений Х в що середині формули
		X = reserv / 3 + deltaX;						// шукаємо новий Х
		if (count < maximum) {										
			cout << "\nПроміжний",output_vars(y);
		}
	}cout <<"\nОстаточний",output_vars(y);
	cout << endl;	
}


void input_vars(float &inpX, float &delta,float &maximum,float &minimum) {
	static float number;
	cout << "Введіть X:";
	inpX = inputCheck(number);
	cout << "Введіть крок зміни аргументу:";
	delta = inputCheck(number);
	cout << "Введіть максимум (max X):";
	maximum = inputCheck(number);
	cout << "Введіть номер змінної Х - (max " << maximum << "):";
	minimum = inputCheck(number);
}
