#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <math.h>
double cust_log(double, double);
double prod(double[], double[], double, double, int, int);
double getExr(double **);
double** readFile();
double constructFraction(double **);
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
			cout << "\n�������! ������������� ������." << endl;
			cout << "��������� �� ���:";
			cin.clear();
			cin.sync();
			cout << endl;
		}
	}
	return number;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	double sum = 0;
	std::cout << "������ ������� �����: ";
	inputCheck(N);

	double **x = readFile();
	double *frac = new double[N];
	for (int i = 0; i < N; i++) {
		frac[i] = constructFraction(x);
		if (frac[i] == -10999) return -1;
		sum += frac[i];
	}

	std::cout << "����! C��� = " << sum;
	_getch();
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
	std::cout << "������ ��� ������:"<<std::endl;
	std::cout << " 1 ��� ��������" << std::endl;
	std::cout << " 2 ��� �������" << std::endl;
	std::cout << "-----> ";
	inputCheck(sw);
	switch (sw)
	{
	case 1: {
		double coefBeforeTan = 1, x;
		std::cout << "������ ���������� ����� ��������� (Enter ��� 1):";
		inputCheck(coefBeforeTan);
		std::cout << "������ �:";
		inputCheck(x);
		if (coefBeforeTan == 0) {
			coefBeforeTan = 1;
		}
		return cust_log(x, coefBeforeTan);
	} break;
	case 2: {
		std::cout << "������ \"�\":";
		int i, maxi;
		double ca, cb;
		inputCheck(i);
		std::cout << "������ MAX \"�\":";
		inputCheck(maxi);
		std::cout << "���������� � (deft 1):";
		inputCheck(ca);
		if (ca == 0) ca = 1;
		std::cout << "���������� B (deft 1):";
		inputCheck(cb);
		if (cb == 0) cb = 1;

		return prod(a, b,ca,cb, i, maxi);
	} break;

	default:
		std::cout << "��! ���� ���� �� ���...";
		return -10999;
		break;
	}

}
double constructFraction(double **x) {
	double numeri, denomi;
	std::cout << "<���������>"<<std::endl;
	numeri = getExr(x);
	std::cout << "<� ����� ���������>" << std::endl;
	denomi = getExr(x);
	if (numeri == -10999 || denomi == -10999) return -10999;
	return numeri / denomi;
}

double** readFile() {

	std::ifstream ars("C:\\Users\\MaxRev\\Desktop\\MyArs.txt");

	if (ars.is_open())
	{
		int count = 0;
		int temp;

		while (!ars.eof()) {
			ars >> temp;
			count++;
		}

		ars.seekg(0, std::ios::beg);
		ars.clear();

		int count_space = 0;
		char symbol;
		while (!ars.eof())
		{
			ars.get(symbol);
			if (symbol == ' ') count_space++;
			if (symbol == '\n') break;
		}
		ars.seekg(0, std::ios::beg);
		ars.clear();


		int n = count / (count_space + 1);
		int m = count_space + 1;
		double **x = new double*[n];
		for (int i = 0; i<n; i++) x[i] = new double[m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ars >> x[i][j];
			}
		}
		ars.close();
		return x;
	}
	else
	{
		std::cout << "���� �� ��������.";
		return nullptr;
	}

}

