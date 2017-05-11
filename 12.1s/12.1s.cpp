#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <Windows.h>

using namespace std;

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream data("...FOLDER_OUT_PATH...",ios::trunc);
	string str[30];
	int iter = -1;
	double min,current;
	cout << "Введіть масив чисел. Після кожного числа натисніть [Enter]" << endl;
	while (true) {
		++iter;
		string strd;
		getline(cin, str[iter]);
		if (str[iter].empty()) break;
	}
	min = atoi(str[0].c_str());
	for (int i = 2; i < iter; i+=2) {
		current = atoi(str[i].c_str());
		if (min>current) min=current;
	} cout << "Найменше значення парних індексів [0,2,4...] = " << min<<endl;
	cout << "Різниця першого і останнього елемента: " << (atoi(str[0].c_str()) - atoi(str[--iter].c_str()))<<endl;

	for (int i = 0; i <= iter; ++i) data << str[i]<<endl;
	data.close();

	_getch();
}