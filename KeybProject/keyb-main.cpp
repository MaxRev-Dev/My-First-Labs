#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <string>
#include "ext.h"

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector<string>vecGrab;
	string buffer = "";
	cout << "String: "
		<< "По окончание ввода введите пустую строку" << endl;

	do {
		getline(cin, buffer);
		if (buffer.size() > 0) {
			vecGrab.push_back(buffer);
		}
	} while (buffer != "");

	unsigned int vector_size = vecGrab.size();

	cout << "Ваш вектор." << endl;
	for (size_t i = 0; i < vector_size; i++) {
		cout << vecGrab[i] << endl;
	}

	system("pause");
	return 0;
}