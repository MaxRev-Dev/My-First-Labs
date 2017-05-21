#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	vector<int*>vec;
	string stmp;
	ifstream inp("D:\\MaxRev\\Desktop\\SHORTCUTS\\Labs\\nums[16.1.3].txt");
	cout << "Вектор: "<<endl;


	while (inp) {
		int *p_num = new int[1];
		getline(inp, stmp);
		if (stmp != "") {
			p_num[0] = atoi(stmp.c_str());
			vec.push_back(p_num);
			cout << p_num[0] << endl;
		}
	}
	cout << endl;

	for(size_t i = 0; i < vec.capacity(); ++i) {
		int current = vec[i][0];
		if (current< 0) {
			cout << "Перший від'ємний елемент: " << current<<endl;
			break;
		}
	}
	_getch();
	return 0;
}