#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>

using namespace std;

struct ST {
	int ID;
	char name[20];
	double mark;
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ST x[20];
	int i = 0;

	while (true) {

		x[i].ID = i+1;
		cin.ignore();
		cout<< "Ім'я студента: ";
		cin.getline(x[i].name,20);
		cin.ignore();
		cout<< "Оцінка: ";
		cin >> x[i].mark;
		Sleep(500);
		_getch();
		if (GetKeyState(VK_RETURN) < 0) {
			break;
		}

		i++;
	}


		cout << "Студенти та їх оцінки:" << endl;
	for (int j = 0,rt=0; j <= i; ++j) {
		if (x[j].mark == 3) {


			cout << "[" << x[j].ID << "]" << "\t" << x[j].name << "\t" << x[j].mark << endl;
			rt++;
		}
		else if (j == i&& rt==0) {
			cout << "Немає таких студентів! "<<endl;
			exit(1);
		}
	}
	cout << endl << "Студентів: " << i + 1;
	_getch();

	return 0;
}