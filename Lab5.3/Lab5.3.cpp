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
			cout << "\n�������! ������������� ������." << endl;
			cout << "��������� �� ���:";
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
	cout << " ���������:"<< q;
}

void count_xi(float &Xtaken, float &deltaX, float &minimum, float &reservedX, float &X,float &i) 
{								//� ��� ������� �� ������ � �� �-1
	for (i; i <= minimum; i++) {
		X = Xtaken/3+deltaX;	//������� ����������� ������ �
		if (i == minimum - 1){  // ������ �-1 ��� ���� �� �������� � ���� �������
			reservedX = Xtaken;
		}	Xtaken = X;			// ��������� � ��� �� ��� ����������� � ������
	} 
}

void findSol(float& previousX, float& X, float &deltaX,float &maximum,float &count,float&s){
	float y=0,reserv;
	for (count; count <= maximum; count++) {
		y += pow(X + previousX, 3) / (X + previousX); // ������ ���� ������� 
		reserv = previousX;								// ��������� �-1
		previousX = X;									// ������ ����� ��������� � � �� ������� �������
		X = reserv / 3 + deltaX;						// ������ ����� �
		if (count < maximum) {										
			cout << "\n��������",output_vars(y);
		}
	}cout <<"\n����������",output_vars(y);
	cout << endl;	
}


void input_vars(float &inpX, float &delta,float &maximum,float &minimum) {
	static float number;
	cout << "������ X:";
	inpX = inputCheck(number);
	cout << "������ ���� ���� ���������:";
	delta = inputCheck(number);
	cout << "������ �������� (max X):";
	maximum = inputCheck(number);
	cout << "������ ����� ����� � - (max " << maximum << "):";
	minimum = inputCheck(number);
}
