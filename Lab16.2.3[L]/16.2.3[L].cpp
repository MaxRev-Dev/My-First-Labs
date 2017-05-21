#include <iostream>
#include <string>
#include "D:\\important!labs_path\filecfg.h"
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <fstream>

using namespace std;
ifstream inp( glpath+ "Labs\\nums[16.2.3].txt");

int main() {
	SetConsoleOutputCP(1251);
	string stmp;
	int *nums = new int[20], iter = 0, x;
	double sum = 0;
	
	while (inp) {
		getline(inp, stmp);
		if (stmp != "") nums[iter++] = atoi(stmp.c_str());
	}
	cout << endl;
	cout << "Ââåä³òü Õ: ";
	cin >> x;
	for (int n = iter, i = 0; n != 0, i < iter; ++i, n--) {
		cout << " " << nums[i] <<" * "<< x <<"^"<<n<< (((i+1)!=iter) ? " + " : " = ");
		sum += nums[i] * pow(x, n);
	}
	cout << sum << endl;
	_getch();
	return 0;
}