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
			cout << "\n�������! ������������� ������." << endl;
			cout << "��������� �� ���:";
			cin.clear();
			cin.sync();
		}
	}
	return number;
}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
s: system("cls");
	double p1,p2, number,sum=0,hpr=0,res;

	cout << "����������� ���������� �������������";
	cout << "\n������ ��������� ����� ������:";
	p1 = inputCheck(number);
	cout << "������ ������ ����� ������:";
	p2 = inputCheck(number);

	cout << "���� ������:\t" << p1 << "-----" << p2 << endl;
	p1 = ceil(p1); // ���������� �� ������
	cout<<"��������� ����:"<<p1;

	while (p1 <= p2){
		sum += p1;
		p1++;
		hpr++;
	}

	res=sum / hpr;

	cout << "\n���� �����:" << sum;
	cout << "\nʳ������ �����:" << hpr;
	cout << "\n���������:" << res<<endl;
	
	system("pause");

	goto s;
	return 0;
}
