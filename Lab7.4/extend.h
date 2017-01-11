#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>
#include <iomanip>

using namespace std;

void _input(double*, int);
void _findPositiveNum(double*, int);
void _output(double ,int );

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
			cout << "�������! ������������� ������." << endl;
			cout << "��������� �� ���:";
			cin.clear();
			cin.sync();
		}
	}
	return number;
}

void _input(double *inp_a, int n_a) {
	int i;
	double number;
	for (i = 0; i < 9; i++) {
		cout << "������ �������� -" << i << "- (�����-" << n_a << ")(9��):";
		*(inp_a + i) = inputCheck(number);
	}
}

void _findPositiveNum(double *a, int i){
	double sv = *a;
	int inner, n;
	for (i = 0; i < 8; i++) {
		for (inner = 0; inner < 9; inner++) {
			if (*(a + i) < sv) {
				sv = *(a + i);
				n = i;
			}
		}
	} _output(sv, n);
}

void _output(double min, int num){
	cout << "�������� ����� ������: " << min << " �� ������� " << num << endl;
}
